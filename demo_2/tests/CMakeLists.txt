

set(BIN_NAME demo2_unit_test)

# 自动生成moc文件
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 用于测试覆盖率的编译条件
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-D SANITIZER_CHECK)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address -O2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address -O2")
endif()

file(GLOB_RECURSE SRCS "*.h" "*.cpp" "../src/*.cpp" "/view_unit_test/*.cpp" "/worker_unit_test/*.cpp" "/global_util_unit_test/*cpp" "/boxfram_unit_test/*.cpp" "/dbusinterface_unit_test/*.cpp" test_res.qrc ${CMAKE_CURRENT_SOURCE_DIR}/../src/skin.qrc)
# 查找依赖库
find_package(PkgConfig REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Concurrent REQUIRED)
find_package(Qt5X11Extras REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(DtkWidget REQUIRED)
find_package(Qt5Svg REQUIRED)
#QTest 依赖库
find_package(Qt5 COMPONENTS Test REQUIRED)
find_package(GTest REQUIRED)
find_package(DtkCore REQUIRED)

pkg_check_modules(QGSettings REQUIRED gsettings-qt)
pkg_check_modules(DFrameworkDBus REQUIRED dframeworkdbus)
pkg_check_modules(XCB_EWMH REQUIRED xcb-ewmh)
