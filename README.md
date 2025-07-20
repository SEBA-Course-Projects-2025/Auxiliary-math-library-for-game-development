# Auxiliary math library for game development
## Short description:
**This library was made to be used for creation of game engines and in graphics rendering.**  
**The core functional of this library consists of:**
- Vectors for 2, 3 and 4 elements implemented;
- Implemented methods for vectors which are: addition, subtraction, multiplication, division, dot product, angle and cosine, magnitude, normalize, scale etc.
- Matrix 4x4 with basic matrix methods implemented;
- All implemented methods are covered with unit tests and proved working;
- Vector for 4 elements is optimised with SSE for Intel and AMD processors and with NEON for ARM processors, increasing computation speed for the methods.
## Instructions on how to deploy a library:
- In CMakeLists.txt file in your project add lines:
  ```
  include(FetchContent)
  FetchContent_Declare(
        vectorlib
        GIT_REPOSITORY https://github.com/SEBA-Course-Projects-2025/Auxiliary-math-library-for-game-development.git
        GIT_TAG main
  )
  FetchContent_MakeAvailable(vectorlib)
  target_link_libraries(<project name> PRIVATE Auxiliary_math_library_for_game_development)
  ```
- Reload CMake project and build the project
- Include required headers, like #include <vector2.hpp> etc.
- Now you can use the functional of the library.
