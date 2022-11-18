cmake_minimum_required(VERSION 3.13)

project(Service)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "-g")

file(GLOB INCLUDE_FILES "./include/*.h")
file(GLOB_RECURSE SRCS "./src/*.h" "./src/*.cpp")

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core DBus)

add_executable(${PROJECT_NAME} ${INCLUDE_FILES} ${SRCS} "main.cpp")

target_include_directories(${PROJECT_NAME} PUBLIC
    "./include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::DBus
)
