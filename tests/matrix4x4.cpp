#include "matrix4x4.hpp"

#include <gtest/gtest.h>

#include <cmath>

#include "vector4.hpp"

using namespace ksemath;

const double EPSILON = 1e-6;

TEST(Matrix4x4Test, DefaultConstructorCreatesIdentityMatrix)
{
    mat4d m;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (i == j)
            {
                EXPECT_DOUBLE_EQ(m.at(i, j), 1.0);
            }
            else
            {
                EXPECT_DOUBLE_EQ(m.at(i, j), 0.0);
            }
        }
    }
}

TEST(Matrix4x4Test, ElementConstructorInitializesCorrectly)
{
    mat4d m(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    EXPECT_DOUBLE_EQ(m.at(0, 0), 1);
    EXPECT_DOUBLE_EQ(m.at(0, 1), 2);
    EXPECT_DOUBLE_EQ(m.at(0, 2), 3);
    EXPECT_DOUBLE_EQ(m.at(0, 3), 4);

    EXPECT_DOUBLE_EQ(m.at(1, 0), 5);
    EXPECT_DOUBLE_EQ(m.at(1, 1), 6);
    EXPECT_DOUBLE_EQ(m.at(1, 2), 7);
    EXPECT_DOUBLE_EQ(m.at(1, 3), 8);

    EXPECT_DOUBLE_EQ(m.at(2, 0), 9);
    EXPECT_DOUBLE_EQ(m.at(2, 1), 10);
    EXPECT_DOUBLE_EQ(m.at(2, 2), 11);
    EXPECT_DOUBLE_EQ(m.at(2, 3), 12);

    EXPECT_DOUBLE_EQ(m.at(3, 0), 13);
    EXPECT_DOUBLE_EQ(m.at(3, 1), 14);
    EXPECT_DOUBLE_EQ(m.at(3, 2), 15);
    EXPECT_DOUBLE_EQ(m.at(3, 3), 16);
}

TEST(Matrix4x4Test, VectorConstructorInitializesCorrectly)
{
    vec4d col0(1, 5, 9, 13);
    vec4d col1(2, 6, 10, 14);
    vec4d col2(3, 7, 11, 15);
    vec4d col3(4, 8, 12, 16);

    mat4d m(col0, col1, col2, col3);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            EXPECT_DOUBLE_EQ(m.at(i, j), i + 1 + j * 4);
        }
    }
}

TEST(Matrix4x4Test, AccessorsWorkCorrectly)
{
    mat4d m(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    // Test const and non-const versions
    EXPECT_DOUBLE_EQ(m[0][0], 1);
    EXPECT_DOUBLE_EQ(m[1][1], 6);
    EXPECT_DOUBLE_EQ(m[2][2], 11);
    EXPECT_DOUBLE_EQ(m[3][3], 16);

    // Test at() function
    m.at(0, 0) = 100;
    EXPECT_DOUBLE_EQ(m.at(0, 0), 100);

    const mat4d& cm = m;
    EXPECT_DOUBLE_EQ(cm.at(0, 0), 100);
}

// TEST(Matrix4x4Test, TransposeWorksCorrectly) {
//     mat4d m(1, 2, 3, 4,
//             5, 6, 7, 8,
//             9, 10, 11, 12,
//             13, 14, 15, 16);
//
//     mat4d transposed = m.transposed();
//
//     for (int i = 0; i < 4; ++i) {
//         for (int j = 0; j < 4; ++j) {
//             EXPECT_DOUBLE_EQ(transposed.at(i, j), m.at(j, i));
//         }
//     }
//
//     // Verify identity matrix is unchanged by transpose
//     mat4d identity = mat4d::identity();
//     EXPECT_TRUE(identity.transposed() == identity);
// }

TEST(Matrix4x4Test, DeterminantCalculation)
{
    // Test identity matrix determinant
    mat4d identity = mat4d::identity();
    EXPECT_DOUBLE_EQ(identity.determinant(), 1.0);

    // Test simple diagonal matrix
    mat4d diagonal(2, 0, 0, 0, 0, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 5);
    EXPECT_DOUBLE_EQ(diagonal.determinant(), 2 * 3 * 4 * 5);

    // Test more complex matrix
    mat4d m(1, 0, 2, -1, 3, 0, 0, 5, 2, 1, 4, -3, 1, 0, 5, 0);
    EXPECT_DOUBLE_EQ(m.determinant(), 30);
}

// TEST(Matrix4x4Test, InversionWorksCorrectly) {
//     // Test identity matrix inversion
//     mat4d identity = mat4d::identity();
//     mat4d invIdentity = identity.inverted();
//     for (int i = 0; i < 4; ++i) {
//         for (int j = 0; j < 4; ++j) {
//             EXPECT_DOUBLE_EQ(invIdentity.at(i, j), identity.at(i, j));
//         }
//     }
//
//     // Test simple diagonal matrix inversion
//     mat4d diagonal(2, 0, 0, 0,
//                    0, 4, 0, 0,
//                    0, 0, 8, 0,
//                    0, 0, 0, 16);
//     mat4d invDiagonal = diagonal.inverted();
//     EXPECT_DOUBLE_EQ(invDiagonal.at(0, 0), 0.5);
//     EXPECT_DOUBLE_EQ(invDiagonal.at(1, 1), 0.25);
//     EXPECT_DOUBLE_EQ(invDiagonal.at(2, 2), 0.125);
//     EXPECT_DOUBLE_EQ(invDiagonal.at(3, 3), 0.0625);
//
//     // Test that product of matrix and its inverse is identity
//     mat4d m(1, 0, 2, -1,
//             3, 0, 0, 5,
//             2, 1, 4, -3,
//             1, 0, 5, 0);
//     mat4d invM = m.inverted();
//     mat4d product = m * invM;
//
//     for (int i = 0; i < 4; ++i) {
//         for (int j = 0; j < 4; ++j) {
//             if (i == j) {
//                 EXPECT_NEAR(product.at(i, j), 1.0, EPSILON);
//             } else {
//                 EXPECT_NEAR(product.at(i, j), 0.0, EPSILON);
//             }
//         }
//     }
// }

TEST(Matrix4x4Test, StaticFactoryMethods)
{
    // Test translation matrix
    mat4d translation = mat4d::translation(2, 3, 4);
    EXPECT_DOUBLE_EQ(translation.at(0, 3), 2);
    EXPECT_DOUBLE_EQ(translation.at(1, 3), 3);
    EXPECT_DOUBLE_EQ(translation.at(2, 3), 4);

    // Test scale matrix
    mat4d scale = mat4d::scale(2, 3, 4);
    EXPECT_DOUBLE_EQ(scale.at(0, 0), 2);
    EXPECT_DOUBLE_EQ(scale.at(1, 1), 3);
    EXPECT_DOUBLE_EQ(scale.at(2, 2), 4);

    // Test rotation matrices (basic verification)
    double angle = M_PI / 4;  // 45 degrees
    mat4d rotX = mat4d::rotationX(angle);
    EXPECT_DOUBLE_EQ(rotX.at(0, 0), 1);
    EXPECT_NEAR(rotX.at(1, 1), cos(angle), EPSILON);
    EXPECT_NEAR(rotX.at(1, 2), -sin(angle), EPSILON);
    EXPECT_NEAR(rotX.at(2, 1), sin(angle), EPSILON);
    EXPECT_NEAR(rotX.at(2, 2), cos(angle), EPSILON);

    mat4d rotY = mat4d::rotationY(angle);
    EXPECT_NEAR(rotY.at(0, 0), cos(angle), EPSILON);
    EXPECT_DOUBLE_EQ(rotY.at(1, 1), 1);
    EXPECT_NEAR(rotY.at(0, 2), sin(angle), EPSILON);
    EXPECT_NEAR(rotY.at(2, 0), -sin(angle), EPSILON);
    EXPECT_NEAR(rotY.at(2, 2), cos(angle), EPSILON);

    mat4d rotZ = mat4d::rotationZ(angle);
    EXPECT_NEAR(rotZ.at(0, 0), cos(angle), EPSILON);
    EXPECT_NEAR(rotZ.at(0, 1), -sin(angle), EPSILON);
    EXPECT_NEAR(rotZ.at(1, 0), sin(angle), EPSILON);
    EXPECT_NEAR(rotZ.at(1, 1), cos(angle), EPSILON);
    EXPECT_DOUBLE_EQ(rotZ.at(2, 2), 1);
}

TEST(Matrix4x4Test, ProjectionMatrices)
{
    // Test perspective projection
    double fov = M_PI / 2;  // 90 degrees
    double aspect = 16.0 / 9.0;
    double near = 0.1;
    double far = 100.0;

    mat4d persp = mat4d::perspective(fov, aspect, near, far);
    EXPECT_NEAR(persp.at(0, 0), 1.0 / (aspect * tan(fov / 2)), EPSILON);
    EXPECT_NEAR(persp.at(1, 1), 1.0 / tan(fov / 2), EPSILON);
    EXPECT_NEAR(persp.at(2, 2), (-near - far) / (near - far), EPSILON);
    EXPECT_NEAR(persp.at(2, 3), 2 * far * near / (near - far), EPSILON);
    EXPECT_DOUBLE_EQ(persp.at(3, 2), 1.0);

    // Test orthographic projection
    double left = -10, right = 10;
    double bottom = -5, top = 5;
    near = 0.1, far = 100.0;

    mat4d ortho = mat4d::orthographic(left, right, bottom, top, near, far);
    EXPECT_DOUBLE_EQ(ortho.at(0, 0), 2.0 / (right - left));
    EXPECT_DOUBLE_EQ(ortho.at(1, 1), 2.0 / (top - bottom));
    EXPECT_DOUBLE_EQ(ortho.at(2, 2), -2.0 / (far - near));
    EXPECT_DOUBLE_EQ(ortho.at(0, 3), -(right + left) / (right - left));
    EXPECT_DOUBLE_EQ(ortho.at(1, 3), -(top + bottom) / (top - bottom));
    EXPECT_DOUBLE_EQ(ortho.at(2, 3), -(far + near) / (far - near));
}