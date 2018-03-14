cmake_minimum_required(VERSION 3.9)
project(ESI-SHARE)

set(CMAKE_CXX_STANDARD 11)

add_executable(ESI-SHARE main.c types.h carga.cpp carga.h administrador.c administrador.h)