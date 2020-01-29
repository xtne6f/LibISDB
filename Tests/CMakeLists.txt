cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_language(CXX)
find_package(Threads REQUIRED)

if(MINGW)
  add_definitions(-D_FILE_OFFSET_BITS=64 -D_UNICODE -DUNICODE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-s,--dynamicbase,--nxcompat -municode -static")
endif(MINGW)

project(libisdbtest CXX)
add_executable(libisdbtest ${CMAKE_CURRENT_SOURCE_DIR}/libisdbtest.cpp)
target_link_libraries(libisdbtest LibISDB ${CMAKE_THREAD_LIBS_INIT})
