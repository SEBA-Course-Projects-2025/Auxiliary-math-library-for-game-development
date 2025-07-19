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

FetchContent_Declare(
        benchmark
        URL https://github.com/google/benchmark/archive/v1.7.1.zip
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest benchmark)

enable_testing()

add_executable(Test
        tests/vector2.cpp
        tests/vector3.cpp
        tests/vector4.cpp
        tests/matrix4x4.cpp
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

add_executable(Benchmarks
        benchmarks/vector2.cpp
        benchmarks/vector3.cpp
        benchmarks/vector4.cpp
        benchmarks/matrix4x4.cpp
)
target_include_directories(Benchmarks PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(Benchmarks PRIVATE
        benchmark::benchmark
        Auxiliary_math_library_for_game_development
)