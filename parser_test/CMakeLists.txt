cmake_minimum_required(VERSION 3.16)
project(TimeParserTest CXX)
set(CMAKE_CXX_STANDARD 17)

# Lisää Googletest
add_subdirectory(googletest)
include_directories(googletest/googletest/include)

# Lähdekoodit
add_executable(runTests
    TimeParser.cpp
    test_cases/TimeParserTest.cpp
)
# lisää projektijuuri include-poluksi
target_include_directories(runTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(runTests gtest gtest_main)
