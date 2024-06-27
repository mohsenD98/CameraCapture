cmake_minimum_required(VERSION 3.24)
project(CameraCapture)

add_subdirectory(${CMAKE_SOURCE_DIR}/CameraCapture/)
add_subdirectory(${CMAKE_SOURCE_DIR}/MohsenKit/)
add_subdirectory(${CMAKE_SOURCE_DIR}/MohsenIcons/)

list(APPEND QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/MohsenKit")
list(APPEND QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/MohsenIcons")
list(REMOVE_DUPLICATES QML_IMPORT_PATH)

set(QML_IMPORT_PATH  ${QML_IMPORT_PATH} CACHE STRING "QML Import Path for QtCreator")

message("->" ${QML_IMPORT_PATH})
