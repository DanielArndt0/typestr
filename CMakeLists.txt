cmake_minimum_required(VERSION 3.16)

project(typestr VERSION 1.0.0 LANGUAGES CXX)

add_library(typestr INTERFACE)
add_library(typestr::typestr ALIAS typestr)

target_compile_features(typestr INTERFACE cxx_std_11)

target_include_directories(typestr INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    add_executable(typestr_basic examples/basic.cpp)
    target_link_libraries(typestr_basic PRIVATE typestr::typestr)
endif()
