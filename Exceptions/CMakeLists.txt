cmake_minimum_required(VERSION 3.17)
project(Exceptions)

set(CMAKE_CXX_STANDARD 17)

add_executable(Exceptions main.cpp TQueue.h Excep.cpp Excep.h dofile.h dofile.cpp)