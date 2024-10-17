# Definimos la versión mínima de CMake
cmake_minimum_required(VERSION 3.29)
# Definimos el nombre del proyecto
project(black-jack)
# Definimos la versión de C++ que vamos a utilizar
set(CMAKE_CXX_STANDARD 20)
add_executable(black-jack src/main.cpp
        src/modules/enums.cpp
        src/modules/enums.h
        src/modules/card.cpp
        src/modules/card.h)