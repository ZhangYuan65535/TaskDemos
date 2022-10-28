cmake_minimum_required(VERSION 3.7)

set(VERSION 4.0)

project(CalculateServer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "-g -Wall")

set(BIN_NAME server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")


# Sources files
file(GLOB_RECURSE SRCS "src/*.h" "src/*.cpp")

# Find the library
find_package(PkgConfig REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Concurrent REQUIRED)
find_package(Qt5X11Extras REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(DtkWidget REQUIRED)
find_package(Qt5Svg REQUIRED)
find_package(DtkCore REQUIRED)

pkg_check_modules(XCB_EWMH REQUIRED xcb-ewmh)
pkg_check_modules(DFrameworkDBus REQUIRED dframeworkdbus)
pkg_check_modules(QGSettings REQUIRED gsettings-qt)

include_directories(
    src
    src/dbusinterface
    src/dbusservices
    src/model
    src/view
    src/widgets
    src/global_util
    src/worker
    src/interface
)

aux_source_directory(src SRC)
aux_source_directory(src/dbusinterface DBUSINTERFACE)
aux_source_directory(src/model MODEL)
aux_source_directory(src/view VIEW)
aux_source_directory(src/widgets WIDGETS)
aux_source_directory(src/global_util GLOBAL_UTIL)
aux_source_directory(src/worker WORKER)
aux_source_directory(src/interface INTERFACE)
aux_source_directory(src/dbusservices DBUSSERVICES)

file(GLOB SRC_PATH
    ${SRC}
    ${DBUSINTERFACE}
    ${MODEL}
    ${VIEW}
    ${WIDGETS}
    ${GLOBAL_UTIL}
    ${WORKER}
    ${INTERFACE}
    ${DBUSSERVICES}
)

add_executable(${BIN_NAME}  ${SRCS} ${SRC_PATH} ${INTERFACES})

target_include_directories(${BIN_NAME} PUBLIC
    ${DtkWidget_INCLUDE_DIRS}
    ${DtkCore_INCLUDE_DIRS}
    ${XCB_EWMH_INCLUDE_DIRS}
    ${DFrameworkDBus_INCLUDE_DIRS}
    ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
    ${QGSettings_INCLUDE_DIRS}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(${BIN_NAME} PRIVATE
    ${XCB_EWMH_LIBRARIES}
    ${DFrameworkDBus_LIBRARIES}
    ${DtkWidget_LIBRARIES}
    ${DtkCore_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Concurrent_LIBRARIES}
    ${Qt5X11Extras_LIBRARIES}
    ${Qt5DBus_LIBRARIES}
    ${QGSettings_LIBRARIES}
    ${Qt5Svg_LIBRARIES}
)
