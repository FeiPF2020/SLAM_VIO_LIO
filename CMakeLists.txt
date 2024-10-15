cmake_minimum_required(VERSION 3.16)
project(SLAM_VIO_LIO)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")

find_package(OpenMP REQUIRED)

if(OPENMP_FOUND)
    message("**OPENMP_FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif ()

find_package(Eigen3 REQUIRED)
message(Eigen: ${EIGEN3_INCLUDE_DIR})

find_package(PCL 1.10 QUIET)
if(PCL_FOUND)
#    message(STATUS "Found PCL: ${PCL_LIBRARIES}")
    message(STATUS "Found PCL")
else()
    message(STATUS "PCL not found")
endif()


include_directories(
        ${EIGEN3_INCLUDE_DIR}
        ${PCL_INCLUDE_DIRS}
        include
)

add_executable(SLAM_VIO_LIO main.cpp)
#target_link_libraries(MyPCLProject ${PCL_LIBRARIES})
