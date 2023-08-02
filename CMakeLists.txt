cmake_minimum_required(VERSION 3.23)
project(Lab1_grafica)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1_grafica main.cpp color.cpp color.h Vertex2.cpp Vertex2.h bitmap.cpp bitmap.h framebuffer.cpp framebuffer.h)
