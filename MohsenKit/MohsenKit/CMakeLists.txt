cmake_minimum_required(VERSION 3.23.0)
project(MohsenKit VERSION 0.1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Qml)

set(QT_LIBS Qt::Core Qt::Quick Qt::Qml)

qt_add_resources(resource_file ${CMAKE_CURRENT_SOURCE_DIR}/MohsenKit.qrc)

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(${PROJECT_NAME} OBJECT ${resource_file} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} ${QT_LIBS})
