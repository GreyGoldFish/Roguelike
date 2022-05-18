cmake_minimum_required(VERSION 3.5)

project(Roguelike LANGUAGES C)

find_package(libtcod CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

add_executable(Roguelike main.c event.c)

target_link_libraries(Roguelike PRIVATE libtcod::libtcod)
target_link_libraries(Roguelike PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static)
