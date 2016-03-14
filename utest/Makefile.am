AUTOMAKE_OPTIONS = foreign

SUBDIRS = 

noinst_PROGRAMS = unittest

unittest_SOURCES = \
	MDServiceTest.cc


unittest_CPPFLAGS = -I$(top_srcdir) -I.. -I..\
		$(BOOST_CPPFLAGS) \
		$(KMDS_CPPFLAGS) \
		$(RAPIDJSON_CPPFLAGS) \
		$(GTEST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(JSON_CPPFLAGS)


unittest_LDADD = \
	$(GTEST_LIBADD) \
	../service/libkick.la \
	$(BOOST_LIBADD) \
	$(KMDS_LIBADD) \
	$(SOIL_LIBADD)



unittest_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = 

EXTRA_DIST = env.sh log.cfg md.cfg


