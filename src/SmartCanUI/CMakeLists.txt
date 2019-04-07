cmake_minimum_required (VERSION 2.8.8)
project (EXAMPLE_QT)

if(NOT DEFINED USE_QT)
    set(USE_QT 5)
endif(NOT DEFINED USE_QT)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable (task main.cpp mainwindow.cpp)
set(HEADERS common.h mainwindow.h)

if(${USE_QT} GREATER 4)
    find_package(Qt5Widgets REQUIRED)
    target_link_libraries(task Qt5::Widgets)
else()
    find_package(Qt4 REQUIRED)
    target_link_libraries(task Qt4::QtGui)
endif()
