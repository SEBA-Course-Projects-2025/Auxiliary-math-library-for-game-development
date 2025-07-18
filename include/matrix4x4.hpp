#pragma once

#include "vector4.hpp"

namespace ksemath
{
template <typename T>
class Matrix4x4
{
   public:
    // Constructors
    Matrix4x4()
        : columns{Vector4<T>(1, 0, 0, 0), Vector4<T>(0, 1, 0, 0), Vector4<T>(0, 0, 1, 0),
                  Vector4<T>(0, 0, 0, 1)}
    {
    }

    Matrix4x4(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23,
              T m30, T m31, T m32, T m33)
        : columns{Vector4<T>(m00, m10, m20, m30), Vector4<T>(m01, m11, m21, m31),
                  Vector4<T>(m02, m12, m22, m32), Vector4<T>(m03, m13, m23, m33)}
    {
    }

    Matrix4x4(const Vector4<T>& col0, const Vector4<T>& col1, const Vector4<T>& col2,
              const Vector4<T>& col3)
        : columns{Vector4<T>(col0.x(), col1.x(), col2.x(), col3.x()),
                  Vector4<T>(col0.y(), col1.y(), col2.y(), col3.y()),
                  Vector4<T>(col0.z(), col1.z(), col2.z(), col3.z()),
                  Vector4<T>(col0.w(), col1.w(), col2.w(), col3.w())}
    {
    }

    // Accessors
    Vector4<T>& operator[](size_t index) { return columns[index]; }
    const Vector4<T>& operator[](size_t index) const { return columns[index]; }

    T& at(size_t row, size_t col) { return columns[col][row]; }
    const T& at(size_t row, size_t col) const { return columns[col][row]; }

    // // Matrix operations
    // Matrix4x4 operator+(const Matrix4x4& other) const
    // {
    //     return Matrix4x4(
    //         columns[0] + other.columns[0],
    //         columns[1] + other.columns[1],
    //         columns[2] + other.columns[2],
    //         columns[3] + other.columns[3]
    //     );
    // }
    //
    // Matrix4x4 operator-(const Matrix4x4& other) const
    // {
    //     return Matrix4x4(
    //         columns[0] - other.columns[0],
    //         columns[1] - other.columns[1],
    //         columns[2] - other.columns[2],
    //         columns[3] - other.columns[3]
    //     );
    // }
    //
    // Matrix4x4 operator*(T scalar) const
    // {
    //     return Matrix4x4(
    //         columns[0] * scalar,
    //         columns[1] * scalar,
    //         columns[2] * scalar,
    //         columns[3] * scalar
    //     );
    // }
    //
    // Matrix4x4 operator/(T scalar) const
    // {
    //     return Matrix4x4(
    //         columns[0] / scalar,
    //         columns[1] / scalar,
    //         columns[2] / scalar,
    //         columns[3] / scalar
    //     );
    // }
    //
    // Vector4<T> operator*(const Vector4<T>& vec) const
    // {
    //     return columns[0] * vec.x() +
    //            columns[1] * vec.y() +
    //            columns[2] * vec.z() +
    //            columns[3] * vec.w();
    // }
    //
    // Matrix4x4 operator*(const Matrix4x4& other) const
    // {
    //     Matrix4x4 result;
    //     for (size_t i = 0; i < 4; ++i) {
    //         for (size_t j = 0; j < 4; ++j) {
    //             T sum = 0;
    //             for (size_t k = 0; k < 4; ++k) {
    //                 sum += at(i, k) * other.at(k, j);
    //             }
    //             result.at(i, j) = sum;
    //         }
    //     }
    //     return result;
    // }
    //
    // Matrix4x4& operator+=(const Matrix4x4& other)
    // {
    //     columns[0] += other.columns[0];
    //     columns[1] += other.columns[1];
    //     columns[2] += other.columns[2];
    //     columns[3] += other.columns[3];
    //     return *this;
    // }
    //
    // Matrix4x4& operator-=(const Matrix4x4& other)
    // {
    //     columns[0] -= other.columns[0];
    //     columns[1] -= other.columns[1];
    //     columns[2] -= other.columns[2];
    //     columns[3] -= other.columns[3];
    //     return *this;
    // }
    //
    // Matrix4x4& operator*=(T scalar)
    // {
    //     columns[0] *= scalar;
    //     columns[1] *= scalar;
    //     columns[2] *= scalar;
    //     columns[3] *= scalar;
    //     return *this;
    // }
    //
    // Matrix4x4& operator/=(T scalar)
    // {
    //     columns[0] /= scalar;
    //     columns[1] /= scalar;
    //     columns[2] /= scalar;
    //     columns[3] /= scalar;
    //     return *this;
    // }
    //
    // Matrix4x4& operator*=(const Matrix4x4& other)
    // {
    //     *this = *this * other;
    //     return *this;
    // }

    // Special matrix operations
    Matrix4x4 transposed() const
    {
        Matrix4x4 result;
        for (size_t i = 0; i < 4; ++i)
        {
            for (size_t j = 0; j < 4; ++j)
            {
                result.at(i, j) = at(j, i);
            }
        }
        return result;
    }

    T determinant() const
    {
        // This is a simplified implementation - for better performance consider
        // using SSE/NEON optimized determinant calculation
        T a = at(0, 0), b = at(0, 1), c = at(0, 2), d = at(0, 3);
        T e = at(1, 0), f = at(1, 1), g = at(1, 2), h = at(1, 3);
        T i = at(2, 0), j = at(2, 1), k = at(2, 2), l = at(2, 3);
        T m = at(3, 0), n = at(3, 1), o = at(3, 2), p = at(3, 3);

        T det = a * (f * (k * p - l * o) - g * (j * p - l * n) + h * (j * o - k * n)) -
                b * (e * (k * p - l * o) - g * (i * p - l * m) + h * (i * o - k * m)) +
                c * (e * (j * p - l * n) - f * (i * p - l * m) + h * (i * n - j * m)) -
                d * (e * (j * o - k * n) - f * (i * o - k * m) + g * (i * n - j * m));

        return det;
    }

    Matrix4x4 inverted() const
    {
        T det = determinant();
        assert(det != 0 && "Matrix is not invertible");

        Matrix4x4 inv;
        T a = at(0, 0), b = at(0, 1), c = at(0, 2), d = at(0, 3);
        T e = at(1, 0), f = at(1, 1), g = at(1, 2), h = at(1, 3);
        T i = at(2, 0), j = at(2, 1), k = at(2, 2), l = at(2, 3);
        T m = at(3, 0), n = at(3, 1), o = at(3, 2), p = at(3, 3);

        inv.at(0, 0) = (f * (k * p - l * o) - g * (j * p - l * n) + h * (j * o - k * n)) / det;
        inv.at(0, 1) = (-b * (k * p - l * o) + c * (j * p - l * n) - d * (j * o - k * n)) / det;
        inv.at(0, 2) = (b * (g * p - h * o) - c * (f * p - h * n) + d * (f * o - g * n)) / det;
        inv.at(0, 3) = (-b * (g * l - h * k) + c * (f * l - h * j) - d * (f * k - g * j)) / det;

        inv.at(1, 0) = (-e * (k * p - l * o) + g * (i * p - l * m) - h * (i * o - k * m)) / det;
        inv.at(1, 1) = (a * (k * p - l * o) - c * (i * p - l * m) + d * (i * o - k * m)) / det;
        inv.at(1, 2) = (-a * (g * p - h * o) + c * (e * p - h * m) - d * (e * o - g * m)) / det;
        inv.at(1, 3) = (a * (g * l - h * k) - c * (e * l - h * i) + d * (e * k - g * i)) / det;

        inv.at(2, 0) = (e * (j * p - l * n) - f * (i * p - l * m) + h * (i * n - j * m)) / det;
        inv.at(2, 1) = (-a * (j * p - l * n) + b * (i * p - l * m) - d * (i * n - j * m)) / det;
        inv.at(2, 2) = (a * (f * p - h * n) - b * (e * p - h * m) + d * (e * n - f * m)) / det;
        inv.at(2, 3) = (-a * (f * l - h * j) + b * (e * l - h * i) - d * (e * j - f * i)) / det;

        inv.at(3, 0) = (-e * (j * o - k * n) + f * (i * o - k * m) - g * (i * n - j * m)) / det;
        inv.at(3, 1) = (a * (j * o - k * n) - b * (i * o - k * m) + c * (i * n - j * m)) / det;
        inv.at(3, 2) = (-a * (f * o - g * n) + b * (e * o - g * m) - c * (e * n - f * m)) / det;
        inv.at(3, 3) = (a * (f * k - g * j) - b * (e * k - g * i) + c * (e * j - f * i)) / det;

        return inv;
    }

    // Static factory methods for common matrices
    static Matrix4x4 identity() { return Matrix4x4(); }

    static Matrix4x4 translation(T x, T y, T z)
    {
        return Matrix4x4(1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z, 0, 0, 0, 1);
    }

    static Matrix4x4 scale(T x, T y, T z)
    {
        return Matrix4x4(x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1);
    }

    static Matrix4x4 rotationX(T angle)
    {
        T c = std::cos(angle);
        T s = std::sin(angle);
        return Matrix4x4(1, 0, 0, 0, 0, c, -s, 0, 0, s, c, 0, 0, 0, 0, 1);
    }

    static Matrix4x4 rotationY(T angle)
    {
        T c = std::cos(angle);
        T s = std::sin(angle);
        return Matrix4x4(c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1);
    }

    static Matrix4x4 rotationZ(T angle)
    {
        T c = std::cos(angle);
        T s = std::sin(angle);
        return Matrix4x4(c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    }

    static Matrix4x4 perspective(T fov, T aspect, T near, T far)
    {
        T tanHalfFov = std::tan(fov / 2);
        T range = near - far;

        return Matrix4x4(1 / (aspect * tanHalfFov), 0, 0, 0, 0, 1 / tanHalfFov, 0, 0, 0, 0,
                         (-near - far) / range, 2 * far * near / range, 0, 0, 1, 0);
    }

    static Matrix4x4 orthographic(T left, T right, T bottom, T top, T near, T far)
    {
        return Matrix4x4(2 / (right - left), 0, 0, -(right + left) / (right - left), 0,
                         2 / (top - bottom), 0, -(top + bottom) / (top - bottom), 0, 0,
                         -2 / (far - near), -(far + near) / (far - near), 0, 0, 0, 1);
    }

   private:
    Vector4<T> columns[4];
};

using mat4f = Matrix4x4<float>;
using mat4d = Matrix4x4<double>;
}  // namespace ksemath