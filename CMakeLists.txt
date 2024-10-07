# Definimos la versión mínima de CMake
cmake_minimum_required(VERSION 3.29)
# Definimos el nombre del proyecto
project(black-jack)
# Definimos la versión de C++ que vamos a utilizar
set(CMAKE_CXX_STANDARD 26)
# Definimos el nombre del ejecutable y los archivos que lo componen
add_executable(black-jack src/main.cpp)