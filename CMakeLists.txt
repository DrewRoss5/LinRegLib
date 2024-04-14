cmake_minimum_required(VERSION 3.28)
project(Linreg VERSION 0.1.0 DESCRIPTION "A library for simple linear regressions")

# set the source directory
set(CMAKE_SOURCE_DIR "src/")
set(TEST_DIR "test/")

# include vcpkg
include(${VCPKG_CMAKE})

# Find and include Google Test
find_package(GTest)
include(GoogleTest)

# add the library
add_library(linreglib ${CMAKE_SOURCE_DIR}linreg.cpp ${CMAKE_SOURCE_DIR}linreg.h)

# add the unit test
if (CMAKE_BUILD_TYPE MATCHES DEBUG)
add_executable(linreg_test ${TEST_DIR}linreg_test.cpp ${CMAKE_SOURCE_DIR}linreg.h ${CMAKE_SOURCE_DIR}linreg.cpp)
target_link_libraries(linreg_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
endif (CMAKE_BUILD_TYPE MATCHES DEBUG)

install(TARGETS linreglib 
            ARCHIVE DESTINATION lib 
            LIBRARY DESTINATION lib 
            RUNTIME DESTINATION bin)


