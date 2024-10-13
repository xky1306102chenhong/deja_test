AUTOMAKE_OPTIONS= dejagnu
bin_PROGRAMS = sorttest
sorttest_SOURCES = sorttest.c libsort.c
INCLUDES =
LDADD =
CLEANFILES = *~
DISTCLEANFILES = .deps/*.P
EXTRA_DIST= testsuite
RUNTESTDEFAULTFLAGS = --tool sorttest SORTTEST=`pwd`/sorttest \
--srcdir $$srcdir/testsuite
