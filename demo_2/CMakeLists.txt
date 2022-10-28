cmake_minimum_required(VERSION 3.13)
project(demo_2 VERSION 1.0)


add_subdirectory(GuiPlugin)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "-g")
set(BIN_NAME "Calculator")

find_package(PkgConfig)
find_package(Qt5Widgets)
find_package(Qt5DBus)
pkg_check_modules(QGSettings REQUIRED gsettings-qt)

file(GLOB_RECURSE SRCS "src/*.h" "src/*.cpp")

add_executable(${BIN_NAME} ${SRCS})

target_include_directories(${BIN_NAME} PUBLIC
    ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
    )
target_link_libraries(${BIN_NAME} PRIVATE
    ${Qt5Widgets_LIBRARIES}
    ${Qt5DBus_LIBRARIES}
    )
#target_link_libraries(${BIN_NAME} PUBLIC
#    "${PROJECT_BINARY_DIR}/GuiPlugin/Guicalc"
#    )
