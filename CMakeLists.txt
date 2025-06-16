cmake_minimum_required(VERSION 3.19)
project(Auxiliary_math_library_for_game_development)

set(CMAKE_CXX_STANDARD 20)

add_library(Auxiliary_math_library_for_game_development
        INTERFACE
)

target_include_directories(Auxiliary_math_library_for_game_development INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Test
        tests/vector2.cpp
        tests/vector3.cpp
        tests/vector4.cpp
)
target_include_directories(Test PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(Test PRIVATE
        gtest_main
        Auxiliary_math_library_for_game_development
)

include(GoogleTest)
gtest_discover_tests(Test)
