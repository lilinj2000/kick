AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libkick.la
libkick_la_SOURCES = \
		    MDOptions.cc MDServiceImpl.cc

libkick_la_CPPFLAGS = -I$(top_srcdir) \
			$(BOOST_CPPFLAGS) \
			$(KMDS_CPPFLAGS) \
			$(SOIL_CPPFLAGS) \
			$(RAPIDJSON_CPPFLAGS) \
			$(JSON_CPPFLAGS)

libkick_la_LIBADD = $(KMDS_LIBADD) \
		$(BOOST_LIBADD) \
		$(SOIL_LIBADD) \
		$(SSL_LIBADD) \
		$(JSON_LIBADD)

libkick_la_LDFLAGS = \
	-no-undefined -version-info \
	$(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	-release $(LT_RELEASE)

# header files
noinst_HEADERS = KickLog.hh Message.hh \
		MDOptions.hh MDServiceImpl.cc



