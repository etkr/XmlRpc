set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

cmake_minimum_required(VERSION 3.10)

# set the project name
project(XmlRpcTest)

find_package(XMLRPC REQUIRED c++2 client)
include_directories(${XMLRPC_INCLUDE_DIRS})

# add the executable
add_executable(XmlRpcTest main.cpp)
target_link_libraries(XmlRpcTest ${XMLRPC_LIBRARIES})
