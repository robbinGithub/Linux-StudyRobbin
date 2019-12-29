cmake_minimum_required(VERSION 3.0.0)
 
project(C++_EXAMPLE)
 
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -pthread")
 
 
 
file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp )
 
foreach( sourcefile IN LISTS APP_SOURCES )
    string( REPLACE ".c" "" program ${sourcefile} )
    add_executable( ${program} ${sourcefile} )
endforeach( sourcefile )
