cmake_minimum_required (VERSION 2.8.8)
project (SmartCanUI)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable (task main.cpp mainwindow.cpp smartcanview.cpp resources.qrc)
set(HEADERS common.h mainwindow.h smartcanview.h)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Svg REQUIRED)
target_link_libraries(task Qt5::Widgets Qt5::Svg)
