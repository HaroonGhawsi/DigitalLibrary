# build using:
#   BOOST_ROOT=../boost_1_55_0 cmake .
# later verbose output from make:
#   make VERBOSE=1
# /usr/bin/c++ -I.../boost_1_55_0 -std=gnu++11 -o CMakeFiles/udpechoserver.dir/udpechoserver.cpp.o -c udpechoserver.cpp
# /usr/bin/c++ CMakeFiles/udpechoserver.dir/udpechoserver.cpp.o -o udpechoserver -rdynamic .../boost_1_55_0/stage/lib/libboost_system.so -Wl,-rpath,.../boost_1_55_0/stage/lib

# the property CXX_STANDARD is first mentioned in cmake 3.1.3

cmake_minimum_required (VERSION 3.0.2)



project (digiLibServer)

SET(CMAKE_CXX_FLAGS "-std=c++11")

# tcpserver
set(EXEC_NAME "digiLibServer")

add_executable(${EXEC_NAME} digiLibServer/src/digiLibServer.cpp)
#set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD 11)
#set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD_REQUIRED true)

# internal list of mandatory boost components
SET(BOOST_MANDATORY_COMPONENTS system)

find_package(Boost "1.52.0" COMPONENTS ${BOOST_MANDATORY_COMPONENTS} REQUIRED)

# add include path for boost to the compiler
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(${EXEC_NAME} ${Boost_SYSTEM_LIBRARY})



