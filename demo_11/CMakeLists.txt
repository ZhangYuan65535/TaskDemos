cmake_minimum_required(VERSION 3.13)

project(UnitTest)

find_package(Qt5Widgets)

include_directories(src)
include_directories(include)


set(CMAKE_CXX_FLAGS "-g -Wall")

file(GLOB SRCS "src/*.h" "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRCS} "main.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${Qt5Widgets_LIBRARIES}
)
