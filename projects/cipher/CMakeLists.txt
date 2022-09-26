cmake_minimum_required(VERSION 3.10)

project(Cipher)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(CipherFunctions)

set (SRC_LIST main.cpp)

add_executable(Cipher ${SRC_LIST})

target_link_libraries(Cipher PUBLIC CipherFunctions)

target_include_directories(Cipher PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

