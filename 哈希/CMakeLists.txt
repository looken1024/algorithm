cmake_minimum_required(VERSION 3.2)

project(algorithm)

add_library(murmurhash2 STATIC murmurhash2.cc)
add_library(murmurhash3 STATIC murmurhash3.cc)
include_directories(.)


