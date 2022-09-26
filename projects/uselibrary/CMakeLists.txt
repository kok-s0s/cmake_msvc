cmake_minimum_required(VERSION 3.0.0)
project(cipher_test VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories("lib")

link_directories("lib")

add_executable(cipher_test main.cpp)

target_link_libraries(cipher_test hello cipher)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
