#! /usr/bin/env python

import glob
import re
import sys

enable_wsf = 0

if '-wsf' in sys.argv:
    enable_wsf = 1

if len(sys.argv) == 2+enable_wsf:
    srcdir = sys.argv[1]
else:
    srcdir = '.'

wsf = ['lasso_disco_', 'lasso_dst_', 'lasso_is_', 'lasso_profile_service',
        'lasso_discovery', 'lasso_wsf', 'lasso_interaction', 'lasso_utility',
        'lasso_sa_', 'lasso_soap_', 'lasso_authentication', 'lasso_wsse' ]
if enable_wsf:
    wsf = []

fd = open('types.c', 'w')

print >> fd, "/* This file has been autogenerated; changes will be lost */"
print >> fd, ""
print >> fd, "typedef GType (*type_function) (void);"
print >> fd, ""

header_files = []
for header_file in glob.glob('%s/*/*.h' % srcdir):
    if not enable_wsf and 'id-wsf' in header_file:
        continue
    header_files.append(header_file)
    try:
        type = re.findall('lasso_.*get_type', open(header_file).read())[0]
    except IndexError:
        continue
    for t in wsf:
        if type.startswith(t):
            break
    else:
        print >> fd, "extern GType %s();" % type

print >> fd, ""
print >> fd, "type_function functions[] = {"
for header_file in header_files:
    try:
        type = re.findall('lasso_.*get_type', open(header_file).read())[0]
    except IndexError:
        continue
    for t in wsf:
        if type.startswith(t):
            break
    else:
        print >> fd, "\t%s," % type
print >> fd, "\tNULL"
print >> fd, "};"

