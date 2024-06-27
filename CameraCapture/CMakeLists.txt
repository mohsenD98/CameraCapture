cmake_minimum_required(VERSION 3.24)

project(CameraCapture)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOGEN_PARALLEL AUTO)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt6 REQUIRED COMPONENTS Core Quick)
set(QT_LIBS Qt::Core Qt::Quick)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.h)

qt_add_resources(rcc_file qml/qml.qrc)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${rcc_file}
)

target_link_libraries(${PROJECT_NAME} ${QT_LIBS} MohsenKit MohsenIcons)
