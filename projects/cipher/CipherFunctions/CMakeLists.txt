add_library(CipherFunctions STATIC cipher.cpp)

target_include_directories(CipherFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )