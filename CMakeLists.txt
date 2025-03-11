cmake_minimum_required(VERSION 3.10)

project(LifeSimulator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/grid.cpp
    src/life_simulator.cpp
)

add_executable(life_simulator ${SOURCES})

find_package(Curses REQUIRED)
target_link_libraries(life_simulator ${CURSES_LIBRARIES})
