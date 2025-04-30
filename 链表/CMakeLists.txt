cmake_minimum_required(VERSION 3.2)

project(algorithm)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(.)
add_executable(lru main.cc lru.cc)

