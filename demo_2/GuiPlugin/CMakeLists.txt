find_package(Qt5Widgets)
find_package(Qt5DBus)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(LIB_NAME "Guicalc")

file(GLOB_RECURSE SRC_FILES "*.h" "*.cpp")

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/plugins)

add_library(${LIB_NAME} SHARED
    ${SRC_FILES}
 )


target_include_directories(${LIB_NAME} PUBLIC
    ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
    ../src
    )
target_link_libraries(${LIB_NAME} PRIVATE
    ${Qt5Widgets_LIBRARIES}
    ${Qt5DBus_LIBRARIES}
    )
