cmake_minimum_required(VERSION 3.17)
project(pacman_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(pacman_game main.cpp Game.cpp MainCharacter.cpp Component.cpp Pacman.cpp Pacman.h Score.cpp Score.h Ghost.cpp Ghost.h Movable.cpp Movable.h Map.cpp Map.h Wall.cpp Wall.h GameState.cpp GameState.h)
target_link_libraries(pacman_game -lglut -lSOIL -lGL -lGLU)