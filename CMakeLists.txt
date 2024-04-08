cmake_minimum_required(VERSION 3.28)
project(Linreg VERSION 0.1.0 DESCRIPTION "A library for simple linear regressions")
# set the source directory
set(CMAKE_SOURCE_DIR "src/")
# create and install the library
add_library(linreglib ${CMAKE_SOURCE_DIR}linreg.cpp ${CMAKE_SOURCE_DIR}linreg.h)
install(TARGETS linreglib 
            ARCHIVE DESTINATION lib 
            LIBRARY DESTINATION lib 
            RUNTIME DESTINATION bin)
