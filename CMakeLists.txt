cmake_minimum_required(VERSION 3.30)
project(Auxiliary_math_library_for_game_development)

set(CMAKE_CXX_STANDARD 20)

add_library(Auxiliary_math_library_for_game_development STATIC library.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Main main.cpp)
target_link_libraries(Main PRIVATE Auxiliary_math_library_for_game_development)

add_executable(Test Test.cpp)
target_link_libraries(Test gtest_main Auxiliary_math_library_for_game_development)

include(GoogleTest)
gtest_discover_tests(Test)
