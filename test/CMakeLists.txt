add_executable(dastest
    test.cpp
)

add_test(NAME dastest COMMAND dastest)
target_link_libraries(dastest PUBLIC das68k gtest)
