#!/bin/sh
# Run this to generate all the initial makefiles, etc.

PROJECT=lasso
TEST_TYPE=-f
FILE=lasso.pc.in

# a silly hack that generates autoregen.sh but it's handy
echo "#!/bin/sh" > autoregen.sh
echo "./autogen.sh $@ \$@" >> autoregen.sh
chmod +x autoregen.sh

DIE=0

srcdir=`dirname $0`
test -z "$srcdir" && srcdir=.

THEDIR="`pwd`"

cd "$srcdir"

(autoconf --version) < /dev/null > /dev/null 2>&1 || {
	echo
	echo "You must have autoconf installed to compile $PROJECT."
	echo "Download the appropriate package for your distribution,"
	echo "or get the source tarball at ftp://ftp.gnu.org/gnu/autoconf/"
	DIE=1
}

if automake-1.15 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.15
    ACLOCAL=aclocal-1.15
elif automake-1.14 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.14
    ACLOCAL=aclocal-1.14
elif automake-1.13 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.13
    ACLOCAL=aclocal-1.13
elif automake-1.12 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.12
    ACLOCAL=aclocal-1.12
elif automake-1.11 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.11
    ACLOCAL=aclocal-1.11
elif automake-1.10 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.10
    ACLOCAL=aclocal-1.10
elif automake-1.9 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.9
    ACLOCAL=aclocal-1.9
elif automake-1.8 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.8
    ACLOCAL=aclocal-1.8
elif automake-1.7 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.7
    ACLOCAL=aclocal-1.7
elif automake-1.6 --version < /dev/null > /dev/null 2>&1; then
    AUTOMAKE=automake-1.6
    ACLOCAL=aclocal-1.6
else
	echo
	echo "You must have automake installed to compile $PROJECT."
	echo "Download the appropriate package for your distribution,"
	echo "or get the source tarball at ftp://ftp.gnu.org/gnu/automake/"
	DIE=1
fi

if test "$DIE" -eq 1; then
	exit 1
fi

test $TEST_TYPE $FILE || {
	echo "You must run this script in the top-level $PROJECT directory"
	exit 1
}

if test "$#" = 0; then
	echo "I am going to run ./configure with no arguments - if you wish "
        echo "to pass any to it, please specify them on the $0 command line."
fi

# to support timj aclocal setup we are shipping gnome-doc-utils.m4
# and making sure automake picks it up ;)
# this is bad as -I prepends to the search path
echo "* Running libtoolize"
libtoolize --copy --force

GTKDOCIZE=`which gtkdocize`
if test -z $GTKDOCIZE; then
        echo "You don't have gtk-doc installed, and thus"
        echo "won't be able to generate the documentation."
        touch gtk-doc.make
else
        echo "* Running gtkdocize"
        $GTKDOCIZE --flavour no-tmpl || exit $?
fi

echo "* Running $ACLOCAL"
$ACLOCAL $ACLOCAL_FLAGS -I m4 || exit $?

echo "* Running autoconf"
autoconf || exit $?
(autoheader --version)  < /dev/null > /dev/null 2>&1 && autoheader

echo "* Running $AUTOMAKE"
$AUTOMAKE --add-missing -Wno-portability $am_opt || exit $?

cd "$THEDIR"

if [ "$1" != "noconfig" ]; then
	$srcdir/configure --enable-gtk-doc --enable-maintainer-mode "$@" || exit $?
fi

echo
echo "Now type 'make install' to install $PROJECT."
