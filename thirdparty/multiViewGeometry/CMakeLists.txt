cmake_minimum_required(VERSION 3.10)
project(multiViewGeometry)

set(CMAKE_CXX_STANDARD 17)

find_package(gflags REQUIRED)
find_package(Eigen3 REQUIRED)
#find_package(glog REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(multiViewGeometry SHARED src/base2D.cpp)
target_link_libraries(multiViewGeometry gflags)

find_package(GTest REQUIRED)
enable_testing()

add_executable(test_base2D test/test_base2D.cpp)
target_link_libraries(test_base2D gtest gtest_main gflags multiViewGeometry)

add_test(NAME multiViewGeometry_test COMMAND test_base2D)