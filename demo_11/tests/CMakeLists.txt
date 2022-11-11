set(BIN_NAME ut-unittest)

file(GLOB_RECURSE SRCS "../src/*.h" "../src/*.cpp")
file(GLOB_RECURSE TEST_FILES "./*.h" "./*.cpp")

add_executable(${BIN_NAME}
    ${SRCS}
    ${TEST_FILES}
)

target_link_libraries(${BIN_NAME} PRIVATE
    ${Qt5Widgets_LIBRARIES}
    -lpthread
    -lgcov
    -lgtest
)

enable_testing()
add_test(NAME ${BIN_NAME} COMMAND ${BIN_NAME})
