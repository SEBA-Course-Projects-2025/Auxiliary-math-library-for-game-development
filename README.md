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
## Full list and implemented methods and features
### Vectors
- Vector constructors for 2, 3, and 4 elements support initialization from a smaller vector and additional values.
  Example: `ksemath::Vector3<double> vec2(vec1, 2);` where `vec1` is a 2D vector.
- Access coordinates via `x()`, `y()`, `z()`, and `w()` methods.
- Modify coordinates using `setX()`, `setY()`, `setZ()`, and `setW()` methods.
- Vector arithmetic:
  - `add()`, `sub()`, `mul()`, `div()` methods accept both vectors and coordinate values.
- Additional operations:
  - `scale()` — multiply vector by scalar
  - `normalize()` — convert vector to unit vector
  - `isValid()` — check if coordinates are finite
  - `negate()` — reverse vector direction
- Geometry and utility:
  - `magnitude()` and `magnitude_sqr()` — get length and squared length
  - `cos()` and `angle()` — compute cosine and angle between vectors
  - `mad()` — multiply-and-add operation
  - `equal()` — check for approximate equality
  - Operators: `==`, `=` implemented
- Type aliases:
  - `vec2f`, `vec2d`, `vec2l` — for `Vector2<float>`, `Vector2<double>`, `Vector2<long double>`
### Matrices
- Matrix4x4 class template works with any arithmetic type (float, double, etc.)
- Three constructors available:
  - Default constructor creates identity matrix
  - Constructor with 16 individual elements (column-major order)
  - Constructor with four Vector4 columns
- Access elements using:
  - `operator[]` for column access
  - `at(row, col)` for direct element access
- Matrix operations (currently commented out but available for implementation):
  - Addition, subtraction with other matrices
  - Multiplication and division by scalar
  - Matrix-vector multiplication
  - Matrix-matrix multiplication
  - Compound assignment operators (+=, -=, *=, /=)
- Special matrix operations:
  - `transposed()` - returns transposed matrix
  - `determinant()` - calculates matrix determinant
  - `inverted()` - returns inverse matrix (throws assert if not invertible)
- Static factory methods for common transformations:
  - `identity()` - creates identity matrix
  - `translation(x, y, z)` - creates translation matrix
  - `scale(x, y, z)` - creates scaling matrix
  - `rotationX(angle)`, `rotationY(angle)`, `rotationZ(angle)` - create rotation matrices
  - `perspective(fov, aspect, near, far)` - creates perspective projection matrix
  - `orthographic(left, right, bottom, top, near, far)` - creates orthographic projection matrix
- Type aliases for convenience:
  - `mat4f` for Matrix4x4<float>
  - `mat4d` for Matrix4x4<double>
