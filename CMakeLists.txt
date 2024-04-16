cmake_minimum_required(VERSION 3.24)
project(CameraCapture)

add_subdirectory(${CMAKE_SOURCE_DIR}/CameraCapture/)
add_subdirectory(${CMAKE_SOURCE_DIR}/MohsenKit/)

set(QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/MohsenKit" CACHE STRING "QML Import Path for QtCreator")
