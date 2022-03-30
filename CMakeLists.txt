cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_STANDARD 11)

project(c-training)

add_subdirectory(A)
add_subdirectory(B)

add_executable(main main.c)
add_executable(udp udp.c)


