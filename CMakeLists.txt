cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(design)

add_executable(design src/abstract_factory.cpp)

install(TARGETS design DESTINATION bin)

if(BUILD_TESTS)
    enable_testing()
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)
    add_executable(testing tests/test.cpp)
    target_link_libraries(testing PRIVATE gtest gtest_main)
    add_test(NAME tester COMMAND testing)
endif()

set(DESIGN_VERSION 1.0.0)
include(CPackConfig.cmake)
