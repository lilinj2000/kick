
home_3rd=~/3rd

if test -d /llj/3rd ; then
   home_3rd=/llj/3rd
fi

home_boost=$home_3rd/boost
home_kmds=$home_3rd/kmds_api/devpack_c_cplusplus_5.4

export LD_LIBRARY_PATH=$home_boost/lib:$home_kmds/lib_linux64


