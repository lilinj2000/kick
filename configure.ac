#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(kick, 0.1, lilinj2000@gmail.com)
AC_CONFIG_SRCDIR([])
#AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
LT_INIT
AC_PROG_RANLIB
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
#AC_CHECK_HEADER_STDBOOL

AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

# Checks for library functions.
LT_RELEASE=0.1
LT_CURRENT=0
LT_REVISION=1
LT_AGE=0
AC_SUBST(LT_RELEASE)
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)

home_3rd=~/3rd
home_libs=~/libs

if test -d /llj/3rd ; then
   home_3rd=/llj/3rd
fi

if test -d /llj/libs ; then
   home_libs=/llj/libs
fi

dnl rapidjson lib
RAPIDJSON_HOME=$home_3rd/rapidjson
AC_ARG_WITH([rapidjson], 
    [AS_HELP_STRING([--with-rapidjson],
        [home path of the rapidjson, defaults to $RAPIDJSON_HOME])],
    [RAPIDJSON_HOME="$withval"],
    [RAPIDJSON_HOME="$RAPIDJSON_HOME"])
AC_SUBST([RAPIDJSON_HOME])

RAPIDJSON_CPPFLAGS="-I$RAPIDJSON_HOME/include"
AC_SUBST(RAPIDJSON_CPPFLAGS)

dnl boost lib
AC_ARG_WITH([boost],
    [AS_HELP_STRING([--with-boost],
        [home path of the boost, defaults to $home_3rd/boost])],
    [BOOST_HOME="$withval"],
    [BOOST_HOME="$home_3rd/boost"])
AC_SUBST([BOOST_HOME])

BOOST_CPPFLAGS="-I$BOOST_HOME/include -DBOOST_ALL_DYN_LINK"
BOOST_LIBADD="$BOOST_HOME/lib/libboost_log_setup.so \
              $BOOST_HOME/lib/libboost_log.so \
	      $BOOST_HOME/lib/libboost_filesystem.so \
  	      $BOOST_HOME/lib/libboost_program_options.so \
	      $BOOST_HOME/lib/libboost_regex.so \
	      $BOOST_HOME/lib/libboost_thread.so \
	      $BOOST_HOME/lib/libboost_chrono.so \
	      $BOOST_HOME/lib/libboost_date_time.so \
	      $BOOST_HOME/lib/libboost_system.so"
AC_SUBST(BOOST_CPPFLAGS)
AC_SUBST(BOOST_LIBADD)

dnl kmds api lib
KMDS_HOME=$home_3rd/kmds_api/devpack_c_cplusplus_5.4
AC_ARG_WITH([kmds],
    [AS_HELP_STRING([--with-kmds],
        [path of the kmds api, defaults to $KMDS_HOME])],
    [KMDS_HOME="$withval"],
    [KMDS_HOME="$KMDS_HOME"])
AC_SUBST([KMDS_HOME])

KMDS_CPPFLAGS=-I$KMDS_HOME/include
KMDS_LIBADD="-L$KMDS_HOME/lib_linux64 -lkmdsapi  -lkmdsapi -ltibrvft64 -ltibrvcm64 -ltibrv64 -lkcbpcli -lkcbpcrypt -lkcxpmq -llcomm"
AC_SUBST(KMDS_CPPFLAGS)
AC_SUBST(KMDS_LIBADD)

dnl gtest lib
AC_ARG_WITH([gtest],
    [AS_HELP_STRING([--with-gtest],
        [home path of the gtest, defaults to $home_3rd/gtest])],
    [GTEST_HOME="$withval"],
    [GTEST_HOME="$home_3rd/gtest"])
AC_SUBST([GTEST_HOME])

GTEST_CPPFLAGS=-I$GTEST_HOME/include
GTEST_LIBADD="$GTEST_HOME/lib/libgtest.a $GTEST_HOME/lib/libgtest_main.a"
AC_SUBST(GTEST_CPPFLAGS)
AC_SUBST(GTEST_LIBADD)

dnl soil lib
AC_ARG_WITH([soil],
    [AS_HELP_STRING([--with-soil],
        [home path of the soil, defaults to $home_libs/soil])],
    [SOIL_HOME="$withval"],
    [SOIL_HOME="$home_libs/soil"])
AC_SUBST([SOIL_HOME])

SOIL_CPPFLAGS="-I$SOIL_HOME/include"
SOIL_LIBADD="$SOIL_HOME/lib/libsoil.la"
AC_SUBST(SOIL_CPPFLAGS)
AC_SUBST(SOIL_LIBADD)

dnl json lib
AC_ARG_WITH([json],
    [AS_HELP_STRING([--with-json],
        [home path of the json, defaults to $home_libs/json])],
    [JSON_HOME="$withval"],
    [JSON_HOME="$home_libs/json"])
AC_SUBST([JSON_HOME])

JSON_CPPFLAGS="-I$JSON_HOME/include"
JSON_LIBADD="$JSON_HOME/lib/libjson.la"
AC_SUBST(JSON_CPPFLAGS)
AC_SUBST(JSON_LIBADD)


AC_OUTPUT([
	Makefile
	kick/Makefile
	service/Makefile
	utest/Makefile])



