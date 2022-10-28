project(mymath)

set(CMAKE_AUTOMOC ON)
set(LIBRARY_OUTPUT_PATH /home/yuan/Desktop/lib)

find_package(Qt5Core)
file(GLOB SRCS "*.cpp" "*.h")

add_library(${PROJECT_NAME} SHARED ${SRCS})

target_link_libraries(${PROJECT_NAME}
    Qt5::Core)
