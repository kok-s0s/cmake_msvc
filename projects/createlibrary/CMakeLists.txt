cmake_minimum_required(VERSION 3.0.0)
project(cipher VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(hello STATIC hello.cpp)
add_library(cipher STATIC cipher.cpp)
# add_library(hello SHARED hello.cpp)
# add_library(cipher SHARED cipher.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
