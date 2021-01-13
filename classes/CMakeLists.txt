cmake_minimum_required(VERSION 3.18)
project(classes)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "usr/lib/qt")

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(classes main.cpp
        Enemy.cpp headers/Enemy.h
        Tower.cpp headers/Tower.h
        Level.cpp headers/Level.h
        Player.cpp headers/Player.h
        StartGame.cpp headers/StartGame.h
        Board.cpp headers/Board.h
        Bullet.cpp headers/Bullet.h
        MainWindow.cpp headers/MainWindow.h
        Menu.cpp headers/Menu.h)
target_link_libraries(classes Qt5::Widgets)