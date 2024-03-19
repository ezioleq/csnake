cmake_minimum_required(VERSION 3.20)
project(csnake C)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)

add_executable(
        csnake
        src/main.c
        src/snake.c
        src/snake.h
        src/game.c
        src/game.h
        src/direction.h
        src/constants.h
        src/food.c
        src/food.h
        src/mathf.c
        src/mathf.h
)

target_link_libraries(csnake SDL2)
