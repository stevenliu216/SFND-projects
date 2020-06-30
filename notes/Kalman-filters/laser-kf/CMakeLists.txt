cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# set project name
project(KalmanFilterLidar)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIRS})

# add the executable
add_executable(main src/main.cpp src/kalman_filter.cpp src/tracking.cpp)
