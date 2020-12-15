cmake_minimum_required(VERSION 3.17)
project(TesteHED)

set(CMAKE_CXX_STANDARD 14)

add_executable(TesteHED main.cpp Mesh.cpp Mesh.h hed.h Point.h)