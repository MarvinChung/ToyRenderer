cmake_minimum_required(VERSION 3.1)
project(toyrenderer)
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable( main main.cpp Vec3.h Ray.h Sphere.h)