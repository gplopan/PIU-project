cmake_minimum_required(VERSION 3.18)
project(classes)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "usr/lib/qt")

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(classes main.cpp Enemy.cpp headers/Enemy.h Tower.cpp headers/Tower.h Level.cpp headers/Level.h Player.cpp headers/Player.h Game.cpp headers/Game.h Board.cpp headers/Board.h)
target_link_libraries(classes Qt5::Widgets)