#! /bin/sh

home_libs=~/libs

if test -d /llj/libs ; then
   home_libs=/llj/libs
fi

home_kick=${home_libs}/kick

./configure --prefix=${home_kick}

if test -d ${home_kick}; then
    rm -rf ${home_kick}
fi

make install

make distclean
