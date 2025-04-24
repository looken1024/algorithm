cmake_minimum_required(VERSION 3.2)

project(algorithm)

add_library(base64 STATIC base64.cc)
add_library(md5 STATIC md5.cc)
include_directories(.)


