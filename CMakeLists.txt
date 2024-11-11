# Definimos la versión mínima de CMake
cmake_minimum_required(VERSION 3.29)
# Definimos el nombre del proyecto
project(black-jack)
# Definimos la versión de C++ que vamos a utilizar
set(CMAKE_CXX_STANDARD 20)
add_executable(black-jack src/main.cpp
        src/card.cpp
        src/player.cpp
        src/deck.cpp
        src/blackjack.cpp
        src/enums.h
        src/card.h
        src/suite.h
        src/figure.h
        src/winner.h
        src/deck.h
        src/player.h
        src/blackjack.h
)