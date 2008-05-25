# Lasso - A free implementation of the Liberty Alliance specifications.
# 
# Copyright (C) 2004-2007 Entr'ouvert
# http://lasso.entrouvert.org
#
# Authors: See AUTHORS file in top-level directory.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

import re
import sys

import utils

class PhpCode:
    def __init__(self, binding_data, fd):
        self.binding_data = binding_data
        self.fd = fd

    def is_object(self, t):
        return t not in ['char*', 'const char*', 'gchar*', 'const gchar*', 'GList*', 'GHashTable*',
                'xmlNode*', 'int', 'gint', 'gboolean', 'const gboolean'] + self.binding_data.enums

    def generate(self):
        self.generate_header()
        for klass in self.binding_data.structs:
            self.generate_class(klass)
        self.generate_exceptions()
        self.generate_footer()

    def generate_header(self):
        print >> self.fd, '''\
<?php

/* this file has been generated automatically; do not edit */

/**
 * @package Lasso
 */

// Try to load Lasso extension if it's not already loaded.
if (!extension_loaded('lasso')) {
    die("Lasso extension is not loaded");
}

/*
 * Convert a C object to a PHP object
 */
function cptrToPhp ($cptr) {
    if (is_null($cptr) || !$cptr) return null;
    $typename = lasso_get_object_typename($cptr);
    $class_name = $typename . "NoInit";
    $obj = new $class_name(); 
    if (! is_null($obj)) {
        $obj->_cptr = $cptr;
        return $obj;
    }
    return null;
}

function lassoGetRequestTypeFromSoapMsg($mesg) {
    return lasso_get_request_type_from_soap_msg($mesg);
}

function lassoRegisterIdWsf2DstService($prefix, $href) {
    lasso_register_idwsf2_dst_service($prefix, $href);
}
'''

    def generate_class(self, klass):
        class_name = klass.name

        if klass.parent != 'GObject':
            inheritence = ' extends %s' % klass.parent
        else:
            inheritence = ''

        print >> self.fd, '/**'
        print >> self.fd, ' * @package Lasso'
        print >> self.fd, ' */'
        print >> self.fd, 'class %(class_name)s%(inheritence)s {' % locals()

        if klass.members or klass.methods:
            self.generate_constructors(klass)
            self.generate_getters_and_setters(klass)
            self.generate_methods(klass)

        print >> self.fd, '}'
        print >> self.fd, ''

        # Add a special class to get an object instance without initialising
        print >> self.fd, '/**'
        print >> self.fd, ' * @package Lasso'
        print >> self.fd, ' */'
        print >> self.fd, 'class %(class_name)sNoInit extends %(class_name)s {' % locals()
        print >> self.fd, '    public function __construct() {}'
        print >> self.fd, '}'
        print >> self.fd, ''

    def generate_constructors(self, klass):
        method_prefix = utils.format_as_underscored(klass.name) + '_'
        for m in self.binding_data.functions:
            if m.name == method_prefix + 'new':
                php_args = []
                c_args = []
                for arg in m.args:
                    arg_type, arg_name, arg_options = arg
                    if arg_options.get('optional'):
                        php_args.append('$%s = null' % arg_name)
                    else:
                        php_args.append('$%s' % arg_name)

                    if self.is_object(arg_type):
                        c_args.append('$%s->_cptr' % arg_name)
                    else:
                        c_args.append('$%s' % arg_name)

                php_args = ', '.join(php_args)
                c_args = ', '.join(c_args)
                # XXX: could check $this->_cptr->typename to see if it got the
                # right class type
                print >> self.fd, '    public $_cptr = null;'
                print >> self.fd, ''
                print >> self.fd, '    public function __construct(%s) {' % php_args
                print >> self.fd, '        $this->_cptr = %s(%s);' % (m.name, c_args)
                print >> self.fd, '        if (is_null($this->_cptr)) { throw new Exception("Constructor for ', klass.name, ' failed "); }'
                print >> self.fd, '    }'
                print >> self.fd, ''

            if m.name == method_prefix + 'new_from_dump':
                if len(m.args) == 1:
                    print >> self.fd, '    public static function newFromDump($dump) {'
                    print >> self.fd, '        return cptrToPhp(%s($dump));' % m.name
                else:
                    print >> self.fd, '    public static function newFromDump($server, $dump) {'
                    print >> self.fd, '        return cptrToPhp(%s($server->_cptr, $dump));' % m.name
                # XXX: Else throw an exception
                print >> self.fd, '    }'
                print >> self.fd, ''
            elif m.name == method_prefix + 'new_full':
                pass

    def generate_getters_and_setters(self, klass):

        # FIXME: handle objects and GLists

        # Generic getter
        print >> self.fd, '    /**'
        print >> self.fd, '     * @return mixed'
        print >> self.fd, '     */'
        print >> self.fd, '    public function __get($attr) {'
        print >> self.fd, '        $func = "get_" . $attr;'
        print >> self.fd, '        if (method_exists($this, $func)) {'
        print >> self.fd, '            return call_user_func(array($this, $func));'
        print >> self.fd, '        }'
        print >> self.fd, '        return null;'
        print >> self.fd, '    }'
        print >> self.fd, ''

        # Generic setter
        print >> self.fd, '    public function __set($attr, $value) {'
        print >> self.fd, '        $func = "set_" . $attr;'
        print >> self.fd, '        if (method_exists($this, $func)) {'
        print >> self.fd, '            call_user_func(array($this, $func), $value);'
        print >> self.fd, '        }'
        print >> self.fd, '    }'
        print >> self.fd, ''

        for m in klass.members:
            mtype = m[0]
            mname = utils.format_as_camelcase(m[1])
            options = m[2]
            
            # Getters
            print >> self.fd, '    /**'
            print >> self.fd, '     * @return %s' % self.get_docstring_return_type(mtype)
            print >> self.fd, '     */'
            print >> self.fd, '    protected function get_%s() {' % mname
            if self.is_object(mtype):
                print >> self.fd, '        return cptrToPhp(%s_%s_get($this->_cptr));' % (
                        klass.name, mname)
            elif mtype in ('GList*', 'GHashTable*'):
                print >> self.fd, '        $array = %s_%s_get($this->_cptr);' % (klass.name, mname)
                if self.is_object(options.get('elem_type')):
                    print >> self.fd, '        $obj_array = array();'
                    if mtype == 'GList*':
                        print >> self.fd, '        foreach ($array as $item) {'
                        print >> self.fd, '            $obj_array[] = cptrToPhp($item);'
                    else:
                        print >> self.fd, '        foreach ($array as $key => $item) {'
                        print >> self.fd, '            $obj_array[$key] = cptrToPhp($item);'
                    print >> self.fd, '        }'
                    print >> self.fd, '        $array = $obj_array;'
                print >> self.fd, '        return $array;'
            else:
                print >> self.fd, '        return %s_%s_get($this->_cptr);' % (klass.name, mname)
            print >> self.fd, '    }'

            # Setters
            print >> self.fd, '    protected function set_%s($value) {' % mname
            if self.is_object(mtype):
                print >> self.fd, '        %s_%s_set($this->_cptr, $value->_cptr);' % (klass.name, mname)
            elif mtype in ('GList*', 'GHashTable*') and self.is_object(options.get('elem_type')):
                print >> self.fd, '        $array = array();'
                # FIXME: setting an array to NULL should really set it to NULL and not to an empty array
                print >> self.fd, '        if (!is_null($value)) {'
                if mtype == 'GList*':
                    print >> self.fd, '            foreach ($value as $item) {'
                    print >> self.fd, '                $array[] = $item->_cptr;'
                else:
                    print >> self.fd, '            foreach ($value as $key => $item) {'
                    print >> self.fd, '                $array[$key] = $item->_cptr;'
                print >> self.fd, '            }'
                print >> self.fd, '        }'
                print >> self.fd, '        %s_%s_set($this->_cptr, $array);' % (klass.name, mname)
            else:
                print >> self.fd, '        %s_%s_set($this->_cptr, $value);' % (klass.name, mname)
            print >> self.fd, '    }'
            print >> self.fd, ''


    def generate_methods(self, klass):
        methods = klass.methods[:]

        # first pass on methods, removing accessors
        for m in klass.methods:
            if m.rename:
                meth_name = m.rename
            else:
                meth_name = m.name
            if not ('_get_' in meth_name and len(m.args) == 1):
                continue
            methods.remove(m)
            try:
                setter_name = meth_name.replace('_get_', '_set_')
                setter = [x for x in methods if x.name == setter_name][0]
                methods.remove(setter)
            except IndexError:
                setter = None
            mname = re.match(r'lasso_.*_get_(\w+)', meth_name).group(1)
            mname =utils.format_as_camelcase(mname)

            print >> self.fd, '    /**'
            print >> self.fd, '     * @return %s' % self.get_docstring_return_type(m.return_type)
            print >> self.fd, '     */'
            print >> self.fd, '    protected function get_%s() {' % mname
            if self.is_object(m.return_type):
                print >> self.fd, '        $cptr = %s($this->_cptr);' % meth_name
                print >> self.fd, '        if (! is_null($cptr)) {'
                print >> self.fd, '            return cptrToPhp($cptr);'
                print >> self.fd, '        }'
                print >> self.fd, '        return null;'
            else:
                print >> self.fd, '        return %s($this->_cptr);' % meth_name
            print >> self.fd, '    }'
            if setter:
                print >> self.fd, '    protected function set_%s($value) {' % mname
                if self.is_object(m.return_type):
                    print >> self.fd, '        %s($this->_cptr, $value->_cptr);' % setter.name
                else:
                    print >> self.fd, '        %s($this->_cptr, $value);' % setter.name
                print >> self.fd, '    }'
            print >> self.fd, ''

        # second pass on methods, real methods
        method_prefix = utils.format_as_underscored(klass.name) + '_'
        for m in methods:
            if m.name.endswith('_new') or m.name.endswith('_new_from_dump') or \
                    m.name.endswith('_new_full'):
                continue
            if not m.name.startswith(method_prefix):
                print >> sys.stderr, 'W:', m.name, 'vs', method_prefix
                continue

            if m.rename:
                mname = m.rename
            else:
                mname = m.name
            cname = mname
            mname = mname[len(method_prefix):]
            php_args = []
            c_args = []
            for arg in m.args[1:]:
                arg_type, arg_name, arg_options = arg
                arg_name = '$' + arg_name
                if arg_options.get('optional'):
                    if arg_options.get('default'):
                        defval = arg_options.get('default')
                        if defval.startswith('c:'): # constant
                            php_args.append('%s = %s' % (arg_name, defval[2:]))
                        elif defval.startswith('b:'): # boolean
                            php_args.append('%s = %s' % (arg_name, defval[2:]))
                        else:
                            print >> sys.stderr, "E: don't know what to do with %s" % defval
                            sys.exit(1)
                    else:
                        php_args.append('%s = null' % arg_name)
                else:
                    php_args.append(arg_name)
                if arg_type in ('char*', 'const char*', 'gchar*', 'const gchar*') or \
                        arg_type in ['int', 'gint', 'gboolean', 'const gboolean'] or \
                        arg_type in self.binding_data.enums:
                    c_args.append(arg_name)
                else:
                    c_args.append('%s._cptr' % arg_name)

            if php_args:
                php_args = ', '.join(php_args)
            else:
                php_args = ''
            if c_args:
                c_args = ', ' + ', '.join(c_args)
            else:
                c_args = ''

            if m.docstring:
                print >> self.fd, self.generate_docstring(m, mname, 4)
            print >> self.fd, '    public function %s(%s) {' % (
                    utils.format_underscore_as_camelcase(mname), php_args)
            if m.return_type == 'void':
                print >> self.fd, '        %s($this->_cptr%s);' % (cname, c_args)
            elif m.return_type in ('gint', 'int'):
                print >> self.fd, '        $rc = %s($this->_cptr%s);' % (cname, c_args)
                print >> self.fd, '        if ($rc == 0) {'
                print >> self.fd, '            return 0;'
                print >> self.fd, '        } else if ($rc > 0) {' # recoverable error
                print >> self.fd, '            return $rc;'
                print >> self.fd, '        } else if ($rc < 0) {' # unrecoverable error
                print >> self.fd, '            LassoError::throw_on_rc($rc);'
                print >> self.fd, '        }'
            else:
                print >> self.fd, '        return %s($this->_cptr%s);' % (cname, c_args)
            print >> self.fd, '    }'
            print >> self.fd, ''

        print >> self.fd, ''

    def generate_docstring(self, func, method_name, indent):
        docstring = func.docstring.orig_docstring
        if func.args:
            first_arg_name = func.args[0][1]
        else:
            first_arg_name = None

        def rep(s):
            type = s.group(1)[0]
            var = s.group(1)[1:]
            if type == '#': # struct
                return var
            elif type == '%': # %TRUE, %FALSE
                if var in ('TRUE', 'FALSE'):
                    return var
                print >> sys.stderr, 'W: unknown docstring thingie: %s' % s.group(1)
            elif type == '@':
                if var == first_arg_name:
                    return '$this'
                else:
                    return '$' + var
            return s.group(1)

        lines = []
        for l in docstring.splitlines():
            if l.strip() and not lines:
                continue
            lines.append(l)
        s = indent * ' ' + '/**\n'
        s += '\n'.join([indent * ' ' + ' * ' + x for x in lines[1:]])
        s += '\n' + indent * ' ' + ' */'
        regex = re.compile(r'([\#%@]\w+)', re.DOTALL)
        s = regex.sub(rep, s)
        s = s.replace('Return value: ', '@return %s ' % self.get_docstring_return_type(func.return_type))
        return s

    def get_docstring_return_type(self, return_type):
        if return_type == None:
            return ''
        elif return_type == 'gboolean':
            return 'boolean'
        elif return_type in ['int', 'gint'] + self.binding_data.enums:
            return 'int'
        elif return_type in ('char*', 'gchar*', 'const char*', 'const gchar*', 'xmlNode*'):
            return 'string'
        elif return_type in ('GList*', 'GHashTable*'):
            return 'array'
        else:
            # Objects
            return return_type.replace('*', '')

    def generate_exceptions(self):
        done_cats = []

        for exc_cat in self.binding_data.overrides.findall('exception/category'):
            cat = exc_cat.attrib.get('name')
            done_cats.append(cat)
            parent_cat = exc_cat.attrib.get('parent', '')
            print >> self.fd, '''\
/**
 * @package Lasso
 */
class Lasso%sError extends Lasso%sError {}
''' % (cat, parent_cat)

        exceptions_dict = {}

        for c in self.binding_data.constants:
            m = re.match(r'LASSO_(\w+)_ERROR_(.*)', c[1])
            if not m:
                continue
            cat, detail = m.groups()
            cat = cat.title().replace('_', '')
            detail = (cat + '_' + detail).title().replace('_', '')
            if not cat in done_cats:
                done_cats.append(cat)
                for exc_cat in self.binding_data.overrides.findall('exception/category'):
                    if exc_cat.attrib.get('name') == cat:
                        parent_cat = exc_cat.attrib.get('parent')
                        break
                else:
                    parent_cat = ''

                print >> self.fd, '''\
/**
 * @package Lasso
 */
class Lasso%sError extends Lasso%sError {}
''' % (cat, parent_cat)

            if detail not in exceptions_dict:
                print >> self.fd, '''\
/**
 * @package Lasso
 */
class Lasso%sError extends Lasso%sError {
    protected $code = %s;
}
''' % (detail, cat, c[1])
                exceptions_dict[detail] = c[1]

        print >> self.fd, '''\
/**
 * @package Lasso
 */
class LassoError extends Exception {
    private static $exceptions_dict = array('''

        for k, v in exceptions_dict.items():
            print >> self.fd, '        %s => "Lasso%sError",' % (v, k)

        print >> self.fd, '''\
    );

    public static function throw_on_rc($rc) {
        $exception = self::$exceptions_dict[$rc];
        if (! class_exists($exception)) {
            $exception = "LassoError";
        }
        throw new $exception(strError($rc), $rc);
    }
}
'''

    def generate_footer(self):
        print >> self.fd, '''\
?>'''

