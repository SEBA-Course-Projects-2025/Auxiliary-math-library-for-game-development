#include "include/vector4.hpp"

#include <gtest/gtest.h>

#include "include/vector2.hpp"
#include "include/vector3.hpp"

using ksemath::Vector2;
using ksemath::Vector3;
using ksemath::Vector4;

TEST(Vector4ConstructorTest, ConstructFromFourScalars)
{
    Vector4<float> v(1, 2.5f, 3.0f, 4u);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.5f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4ConstructorTest, ConstructFromVector2AndTwoScalars)
{
    Vector2<float> v2(1.0f, 2.0f);
    Vector4<float> v(v2, 3, 4.5f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.5f);
}

TEST(Vector4ConstructorTest, ConstructFromScalarVector2Scalar)
{
    Vector2<float> v2(2.0f, 3.0f);
    Vector4<float> v(1, v2, 4.5f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.5f);
}

TEST(Vector4ConstructorTest, ConstructFromTwoScalarsAndVector2)
{
    Vector2<float> v2(3.0f, 4.0f);
    Vector4<float> v(1.0f, 2u, v2);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4ConstructorTest, ConstructFromTwoVector2s)
{
    Vector2<float> v1(1.0f, 2.0f);
    Vector2<float> v2(3.0f, 4.0f);
    Vector4<float> v(v1, v2);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4ConstructorTest, ConstructFromVector3AndScalar)
{
    Vector3<float> v3(1.0f, 2.0f, 3.0f);
    Vector4<float> v(v3, 4.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4ConstructorTest, ConstructFromScalarAndVector3)
{
    Vector3<float> v3(2.0f, 3.0f, 4.0f);
    Vector4<float> v(1, v3);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

// Edge Cases
TEST(Vector4ConstructorTest, ConstructWithNegativeValues)
{
    Vector4<float> v(-1, -2.5f, -3.0f, -4);
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.5f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
    EXPECT_FLOAT_EQ(v.w(), -4.0f);
}

TEST(Vector4ConstructorTest, ConstructWithZeroes)
{
    Vector4<float> v(0, 0.0f, 0.0f, 0u);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
    EXPECT_FLOAT_EQ(v.z(), 0.0f);
    EXPECT_FLOAT_EQ(v.w(), 0.0f);
}

TEST(Vector4ConstructorTest, ConstructWithLargeValues)
{
    Vector4<float> v(1e10f, -1e10f, 3.4e+38f, -3.4e+38f);
    EXPECT_FLOAT_EQ(v.x(), 1e10f);
    EXPECT_FLOAT_EQ(v.y(), -1e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.4e+38f);
    EXPECT_FLOAT_EQ(v.w(), -3.4e+38f);
}

TEST(Vector4AddTest, AddFourNumericValues)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.add(5, 6.0f, 7.0f, 8u);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 12.0f);
}

TEST(Vector4AddTest, AddVector2AndTwoNumericValues)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    Vector2<float> v2(5.0f, 6.0f);
    v.add(v2, 7, 8.0f);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 12.0f);
}

TEST(Vector4AddTest, AddNumericValueVector2AndNumericValue)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    Vector2<float> v2(6.0f, 7.0f);
    v.add(5, v2, 8.0f);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 12.0f);
}

TEST(Vector4AddTest, AddTwoNumericValuesAndVector2)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    Vector2<float> v2(7.0f, 8.0f);
    v.add(5, 6.0f, v2);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 12.0f);
}

TEST(Vector4AddTest, AddTwoVector2s)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    Vector2<float> v1(5.0f, 6.0f);
    Vector2<float> v2(7.0f, 8.0f);
    v.add(v1, v2);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 12.0f);
}

TEST(Vector4AddTest, AddVector3AndNumericValue)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    Vector3<float> v3(5.0f, 6.0f, 7.0f);
    v.add(v3, 8.0f);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 12.0f);
}

TEST(Vector4AddTest, AddNumericValueAndVector3)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    Vector3<float> v3(6.0f, 7.0f, 8.0f);
    v.add(5, v3);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 12.0f);
}

TEST(Vector4AddTest, AddVector4)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> other(5.0f, 6.0f, 7.0f, 8.0f);
    v.add(other);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 12.0f);
}

TEST(Vector4SubTest, SubFourNumericValues)
{
    Vector4<float> v(10.0f, 10.0f, 10.0f, 10.0f);
    v.sub(1, 2.0f, 3.0f, 4u);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
    EXPECT_FLOAT_EQ(v.w(), 6.0f);
}

TEST(Vector4SubTest, SubVector2AndTwoNumericValues)
{
    Vector4<float> v(10.0f, 10.0f, 10.0f, 10.0f);
    Vector2<float> v2(1.0f, 2.0f);
    v.sub(v2, 3, 4.0f);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
    EXPECT_FLOAT_EQ(v.w(), 6.0f);
}

TEST(Vector4SubTest, SubNumericValueVector2AndNumericValue)
{
    Vector4<float> v(10.0f, 10.0f, 10.0f, 10.0f);
    Vector2<float> v2(2.0f, 3.0f);
    v.sub(1, v2, 4.0f);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
    EXPECT_FLOAT_EQ(v.w(), 6.0f);
}

TEST(Vector4SubTest, SubTwoNumericValuesAndVector2)
{
    Vector4<float> v(10.0f, 10.0f, 10.0f, 10.0f);
    Vector2<float> v2(3.0f, 4.0f);
    v.sub(1, 2.0f, v2);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
    EXPECT_FLOAT_EQ(v.w(), 6.0f);
}

TEST(Vector4SubTest, SubTwoVector2s)
{
    Vector4<float> v(10.0f, 10.0f, 10.0f, 10.0f);
    Vector2<float> v1(1.0f, 2.0f);
    Vector2<float> v2(3.0f, 4.0f);
    v.sub(v1, v2);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
    EXPECT_FLOAT_EQ(v.w(), 6.0f);
}

TEST(Vector4SubTest, SubVector3AndNumericValue)
{
    Vector4<float> v(10.0f, 10.0f, 10.0f, 10.0f);
    Vector3<float> v3(1.0f, 2.0f, 3.0f);
    v.sub(v3, 4.0f);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
    EXPECT_FLOAT_EQ(v.w(), 6.0f);
}

TEST(Vector4SubTest, SubNumericValueAndVector3)
{
    Vector4<float> v(10.0f, 10.0f, 10.0f, 10.0f);
    Vector3<float> v3(2.0f, 3.0f, 4.0f);
    v.sub(1, v3);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
    EXPECT_FLOAT_EQ(v.w(), 6.0f);
}

TEST(Vector4SubTest, SubVector4)
{
    Vector4<float> v(10.0f, 10.0f, 10.0f, 10.0f);
    Vector4<float> other(1.0f, 2.0f, 3.0f, 4.0f);
    v.sub(other);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
    EXPECT_FLOAT_EQ(v.w(), 6.0f);
}

TEST(Vector4MulTest, MulFourNumericValues)
{
    Vector4<float> v(2.0f, 3.0f, 4.0f, 5.0f);
    v.mul(2, 3.0f, 4.0f, 5u);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
    EXPECT_FLOAT_EQ(v.z(), 16.0f);
    EXPECT_FLOAT_EQ(v.w(), 25.0f);
}

TEST(Vector4MulTest, MulVector2AndTwoNumericValues)
{
    Vector4<float> v(2.0f, 3.0f, 4.0f, 5.0f);
    Vector2<float> v2(2.0f, 3.0f);
    v.mul(v2, 4, 5.0f);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
    EXPECT_FLOAT_EQ(v.z(), 16.0f);
    EXPECT_FLOAT_EQ(v.w(), 25.0f);
}

TEST(Vector4MulTest, MulNumericValueVector2AndNumericValue)
{
    Vector4<float> v(2.0f, 3.0f, 4.0f, 5.0f);
    Vector2<float> v2(3.0f, 4.0f);
    v.mul(2, v2, 5.0f);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
    EXPECT_FLOAT_EQ(v.z(), 16.0f);
    EXPECT_FLOAT_EQ(v.w(), 25.0f);
}

TEST(Vector4MulTest, MulTwoNumericValuesAndVector2)
{
    Vector4<float> v(2.0f, 3.0f, 4.0f, 5.0f);
    Vector2<float> v2(4.0f, 5.0f);
    v.mul(2, 3.0f, v2);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
    EXPECT_FLOAT_EQ(v.z(), 16.0f);
    EXPECT_FLOAT_EQ(v.w(), 25.0f);
}

TEST(Vector4MulTest, MulTwoVector2s)
{
    Vector4<float> v(2.0f, 3.0f, 4.0f, 5.0f);
    Vector2<float> v1(2.0f, 3.0f);
    Vector2<float> v2(4.0f, 5.0f);
    v.mul(v1, v2);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
    EXPECT_FLOAT_EQ(v.z(), 16.0f);
    EXPECT_FLOAT_EQ(v.w(), 25.0f);
}

TEST(Vector4MulTest, MulVector3AndNumericValue)
{
    Vector4<float> v(2.0f, 3.0f, 4.0f, 5.0f);
    Vector3<float> v3(2.0f, 3.0f, 4.0f);
    v.mul(v3, 5.0f);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
    EXPECT_FLOAT_EQ(v.z(), 16.0f);
    EXPECT_FLOAT_EQ(v.w(), 25.0f);
}

TEST(Vector4MulTest, MulNumericValueAndVector3)
{
    Vector4<float> v(2.0f, 3.0f, 4.0f, 5.0f);
    Vector3<float> v3(3.0f, 4.0f, 5.0f);
    v.mul(2, v3);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
    EXPECT_FLOAT_EQ(v.z(), 16.0f);
    EXPECT_FLOAT_EQ(v.w(), 25.0f);
}

TEST(Vector4MulTest, MulVector4)
{
    Vector4<float> v(2.0f, 3.0f, 4.0f, 5.0f);
    Vector4<float> other(2.0f, 3.0f, 4.0f, 5.0f);
    v.mul(other);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
    EXPECT_FLOAT_EQ(v.z(), 16.0f);
    EXPECT_FLOAT_EQ(v.w(), 25.0f);
}

TEST(Vector4DivTest, DivFourNumericValues)
{
    Vector4<float> v(20.0f, 30.0f, 40.0f, 50.0f);
    v.div(2.0f, 3.0f, 4.0f, 5.0f);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 10.0f);
}

TEST(Vector4DivTest, DivVector2AndTwoNumericValues)
{
    Vector4<float> v(20.0f, 30.0f, 40.0f, 50.0f);
    Vector2<float> v2(2.0f, 3.0f);
    v.div(v2, 4.0f, 5.0f);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 10.0f);
}

TEST(Vector4DivTest, DivNumericValueVector2AndNumericValue)
{
    Vector4<float> v(20.0f, 30.0f, 40.0f, 50.0f);
    Vector2<float> v2(3.0f, 4.0f);
    v.div(2.0f, v2, 5.0f);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 10.0f);
}

TEST(Vector4DivTest, DivTwoNumericValuesAndVector2)
{
    Vector4<float> v(20.0f, 30.0f, 40.0f, 50.0f);
    Vector2<float> v2(4.0f, 5.0f);
    v.div(2.0f, 3.0f, v2);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 10.0f);
}

TEST(Vector4DivTest, DivTwoVector2s)
{
    Vector4<float> v(20.0f, 30.0f, 40.0f, 50.0f);
    Vector2<float> v1(2.0f, 3.0f);
    Vector2<float> v2(4.0f, 5.0f);
    v.div(v1, v2);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 10.0f);
}

TEST(Vector4DivTest, DivVector3AndNumericValue)
{
    Vector4<float> v(20.0f, 30.0f, 40.0f, 50.0f);
    Vector3<float> v3(2.0f, 3.0f, 4.0f);
    v.div(v3, 5.0f);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 10.0f);
}

TEST(Vector4DivTest, DivNumericValueAndVector3)
{
    Vector4<float> v(20.0f, 30.0f, 40.0f, 50.0f);
    Vector3<float> v3(3.0f, 4.0f, 5.0f);
    v.div(2.0f, v3);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 10.0f);
}

TEST(Vector4DivTest, DivVector4)
{
    Vector4<float> v(20.0f, 30.0f, 40.0f, 50.0f);
    Vector4<float> other(2.0f, 3.0f, 4.0f, 5.0f);
    v.div(other);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 10.0f);
    EXPECT_FLOAT_EQ(v.w(), 10.0f);
}

TEST(Vector4EdgeCasesTest, AddWithZero)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.add(0.0f, 0.0f, 0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4EdgeCasesTest, SubWithZero)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.sub(0, 0.0f, 0.0f, 0u);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4EdgeCasesTest, MulWithOne)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.mul(1, 1.0f, 1.0f, 1u);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4EdgeCasesTest, DivByOne)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.div(1, 1.0f, 1.0f, 1u);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4EdgeCasesTest, AddWithLargeNumbers)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.add(1e10f, 2e10f, 3e10f, 4e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f + 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f + 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f + 3e10f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f + 4e10f);
}

TEST(Vector4EdgeCasesTest, SubWithLargeNumbers)
{
    Vector4<float> v(1e20f, 2e20f, 3e20f, 4e20f);
    v.sub(1e10f, 2e10f, 3e10f, 4e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e20f - 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f - 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3e20f - 3e10f);
    EXPECT_FLOAT_EQ(v.w(), 4e20f - 4e10f);
}

TEST(Vector4EdgeCasesTest, MulWithLargeNumbers)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.mul(1e10f, 2e10f, 3e10f, 4e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f * 3e10f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f * 4e10f);
}

TEST(Vector4EdgeCasesTest, DivWithLargeNumbers)
{
    Vector4<float> v(1e20f, 2e20f, 3e20f, 4e20f);
    v.div(1e10f, 2e10f, 3e10f, 4e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e20f / 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f / 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3e20f / 3e10f);
    EXPECT_FLOAT_EQ(v.w(), 4e20f / 4e10f);
}

TEST(Vector4EdgeCasesTest, AddWithMixedTypes)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.add(1, 2.0f, 3u, 4.0f);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
    EXPECT_FLOAT_EQ(v.z(), 6.0f);
    EXPECT_FLOAT_EQ(v.w(), 8.0f);
}

TEST(Vector4EdgeCasesTest, SubWithMixedTypes)
{
    Vector4<float> v(10.0f, 10.0f, 10.0f, 10.0f);
    v.sub(1, 2.0f, 3u, 4.0f);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
    EXPECT_FLOAT_EQ(v.w(), 6.0f);
}

TEST(Vector4EdgeCasesTest, MulWithMixedTypes)
{
    Vector4<float> v(2.0f, 2.0f, 2.0f, 2.0f);
    v.mul(1, 2.0f, 3u, 4.0f);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
    EXPECT_FLOAT_EQ(v.z(), 6.0f);
    EXPECT_FLOAT_EQ(v.w(), 8.0f);
}

TEST(Vector4EdgeCasesTest, DivWithMixedTypes)
{
    Vector4<float> v(20.0f, 20.0f, 20.0f, 20.0f);
    v.div(1, 2.0f, 4u, 5.0f);
    EXPECT_FLOAT_EQ(v.x(), 20.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 5.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4ScaleTest, ScaleWithPositiveInteger)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.scale(2);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
    EXPECT_FLOAT_EQ(v.z(), 6.0f);
    EXPECT_FLOAT_EQ(v.w(), 8.0f);
}

TEST(Vector4ScaleTest, ScaleWithPositiveFloat)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.scale(2.5f);
    EXPECT_FLOAT_EQ(v.x(), 2.5f);
    EXPECT_FLOAT_EQ(v.y(), 5.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.5f);
    EXPECT_FLOAT_EQ(v.w(), 10.0f);
}

TEST(Vector4ScaleTest, ScaleWithNegativeValue)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.scale(-1);
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
    EXPECT_FLOAT_EQ(v.w(), -4.0f);
}

TEST(Vector4ScaleTest, ScaleWithZero)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.scale(0);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
    EXPECT_FLOAT_EQ(v.z(), 0.0f);
    EXPECT_FLOAT_EQ(v.w(), 0.0f);
}

TEST(Vector4ScaleTest, ScaleWithLargeNumber)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.scale(1e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f * 1e10f);
}

TEST(Vector4ScaleTest, ScaleWithSmallNumber)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.scale(1e-10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e-10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 1e-10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f * 1e-10f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f * 1e-10f);
}
/*
TEST(Vector4NormalizeTest, NormalizeNonZeroVector)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.normalize();
    float mag = v.magnitude();
    EXPECT_NEAR(mag, 1.0f, 1e-6f);
}

TEST(Vector4NormalizeTest, NormalizeAlreadyUnitVector)
{
    Vector4<float> v(1.0f, 0.0f, 0.0f, 0.0f);
    v.normalize();
    EXPECT_NEAR(v.x(), 1.0f, 1e-6f);
    EXPECT_NEAR(v.y(), 0.0f, 1e-6f);
    EXPECT_NEAR(v.z(), 0.0f, 1e-6f);
    EXPECT_NEAR(v.w(), 0.0f, 1e-6f);
}

TEST(Vector4NormalizeTest, NormalizeNegativeVector)
{
    Vector4<float> v(-1.0f, -2.0f, -3.0f, -4.0f);
    v.normalize();
    float mag = v.magnitude();
    EXPECT_NEAR(mag, 1.0f, 1e-6f);
}

TEST(Vector4NormalizeDeathTest, NormalizeZeroVector)
{
    Vector4<float> v(0.0f, 0.0f, 0.0f, 0.0f);
    EXPECT_DEATH(v.normalize(), "Cannot normalize a zero-length vector");
}

TEST(Vector4NegateTest, NegatePositiveVector)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
    EXPECT_FLOAT_EQ(v.w(), -4.0f);
}

TEST(Vector4NegateTest, NegateNegativeVector)
{
    Vector4<float> v(-1.0f, -2.0f, -3.0f, -4.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4NegateTest, NegateMixedVector)
{
    Vector4<float> v(1.0f, -2.0f, 3.0f, -4.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4MagnitudeSqrTest, MagnitudeSqrPositiveVector)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1.0f + 4.0f + 9.0f + 16.0f);
}

TEST(Vector4MagnitudeSqrTest, MagnitudeSqrNegativeVector)
{
    Vector4<float> v(-1.0f, -2.0f, -3.0f, -4.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1.0f + 4.0f + 9.0f + 16.0f);
}

TEST(Vector4MagnitudeSqrTest, MagnitudeSqrZeroVector)
{
    Vector4<float> v(0.0f, 0.0f, 0.0f, 0.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vector4MagnitudeSqrTest, MagnitudeSqrLargeVector)
{
    Vector4<float> v(1e10f, 2e10f, 3e10f, 4e10f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1e20f + 4e20f + 9e20f + 16e20f);
}

TEST(Vector4MagnitudeTest, MagnitudePositiveVector)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    float result = v.magnitude();
    float expected = std::sqrt(1.0f + 4.0f + 9.0f + 16.0f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector4MagnitudeTest, MagnitudeNegativeVector)
{
    Vector4<float> v(-1.0f, -2.0f, -3.0f, -4.0f);
    float result = v.magnitude();
    float expected = std::sqrt(1.0f + 4.0f + 9.0f + 16.0f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector4MagnitudeTest, MagnitudeZeroVector)
{
    Vector4<float> v(0.0f, 0.0f, 0.0f, 0.0f);
    float result = v.magnitude();
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vector4MagnitudeTest, MagnitudeLargeVector)
{
    Vector4<float> v(1e10f, 2e10f, 3e10f, 4e10f);
    float result = v.magnitude();
    float expected = std::sqrt(1e20f + 4e20f + 9e20f + 16e20f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector4MagnitudeTest, MagnitudeSmallVector)
{
    Vector4<float> v(1e-10f, 2e-10f, 3e-10f, 4e-10f);
    float result = v.magnitude();
    float expected = std::sqrt(1e-20f + 4e-20f + 9e-20f + 16e-20f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector4NormalizeEdgeCase, NormalizeAfterScaling)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.scale(100.0f);
    v.normalize();
    EXPECT_NEAR(v.magnitude(), 1.0f, 1e-6f);
}

TEST(Vector4EdgeCase, ScaleThenNegate)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    v.scale(-2.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
    EXPECT_FLOAT_EQ(v.z(), 6.0f);
    EXPECT_FLOAT_EQ(v.w(), 8.0f);
}

TEST(Vector4EdgeCase, MagnitudeAfterNormalize)
{
    Vector4<float> v(5.0f, 0.0f, 0.0f, 0.0f);
    v.normalize();
    EXPECT_FLOAT_EQ(v.magnitude(), 1.0f);
    EXPECT_FLOAT_EQ(v.magnitude_sqr(), 1.0f);
}

TEST(Vector4DotTest, BasicDotProduct)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(2.0f, 3.0f, 4.0f, 5.0f);
    EXPECT_FLOAT_EQ(v1.dot(v2), 40.0f);
}

TEST(Vector4DotTest, DotProductWithSelf)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.dot(v), 30.0f);
}

TEST(Vector4DotTest, DotProductWithNegativeValues)
{
    Vector4<float> v1(1.0f, -2.0f, 3.0f, -4.0f);
    Vector4<float> v2(-2.0f, 3.0f, -4.0f, 5.0f);
    EXPECT_FLOAT_EQ(v1.dot(v2), -40.0f);
}

TEST(Vector4DotTest, DotProductWithLargeValues)
{
    Vector4<float> v1(1e10f, 2e10f, 3e10f, 4e10f);
    Vector4<float> v2(2e10f, 3e10f, 4e10f, 5e10f);
    EXPECT_FLOAT_EQ(v1.dot(v2), 4e21f);
}

TEST(Vector4CosTest, CosBetweenSameVectors)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.cos(v), 1.0f);
}

TEST(Vector4CosTest, CosBetweenOrthogonalVectors)
{
    Vector4<float> v1(1.0f, 0.0f, 0.0f, 0.0f);
    Vector4<float> v2(0.0f, 1.0f, 0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v1.cos(v2), 0.0f);
}

TEST(Vector4CosTest, CosBetweenOppositeVectors)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(-1.0f, -2.0f, -3.0f, -4.0f);
    EXPECT_FLOAT_EQ(v1.cos(v2), -1.0f);
}

TEST(Vector4AngleTest, AngleBetweenSameVectors)
{
    Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.angle(v), 0.0f);
}

TEST(Vector4AngleTest, AngleBetweenOrthogonalVectors)
{
    Vector4<float> v1(1.0f, 0.0f, 0.0f, 0.0f);
    Vector4<float> v2(0.0f, 1.0f, 0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v1.angle(v2), M_PI_2);
}

TEST(Vector4AngleTest, AngleBetweenOppositeVectors)
{
    Vector4<float> v1(1.0f, 0.0f, 0.0f, 0.0f);
    Vector4<float> v2(-1.0f, 0.0f, 0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v1.angle(v2), M_PI);
}

TEST(Vector4MadTest, MadWithFloatScalar)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(0.1f, 0.2f, 0.3f, 0.4f);
    v1.mad(v2, 2.0f);
    EXPECT_FLOAT_EQ(v1.x(), 1.2f);
    EXPECT_FLOAT_EQ(v1.y(), 2.4f);
    EXPECT_FLOAT_EQ(v1.z(), 3.6f);
    EXPECT_FLOAT_EQ(v1.w(), 4.8f);
}

TEST(Vector4MadTest, MadWithIntScalar)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(0.1f, 0.2f, 0.3f, 0.4f);
    v1.mad(v2, 2);
    EXPECT_FLOAT_EQ(v1.x(), 1.2f);
    EXPECT_FLOAT_EQ(v1.y(), 2.4f);
    EXPECT_FLOAT_EQ(v1.z(), 3.6f);
    EXPECT_FLOAT_EQ(v1.w(), 4.8f);
}

TEST(Vector4MadTest, MadWithLargeScalar)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(1e10f, 2e10f, 3e10f, 4e10f);
    v1.mad(v2, 1e-10f);
    EXPECT_FLOAT_EQ(v1.x(), 2.0f);
    EXPECT_FLOAT_EQ(v1.y(), 4.0f);
    EXPECT_FLOAT_EQ(v1.z(), 6.0f);
    EXPECT_FLOAT_EQ(v1.w(), 8.0f);
}

TEST(Vector4EqualTest, EqualVectors)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(1.0f + 1e-6f, 2.0f + 1e-6f, 3.0f + 1e-6f, 4.0f + 1e-6f);
    EXPECT_TRUE(v1.equal(v2));
}

TEST(Vector4EqualTest, NotEqualVectors)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(1.1f, 2.1f, 3.1f, 4.1f);
    EXPECT_FALSE(v1.equal(v2));
}

TEST(Vector4OperatorEqualTest, EqualVectors)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(1.0f + 1e-6f, 2.0f + 1e-6f, 3.0f + 1e-6f, 4.0f + 1e-6f);
    EXPECT_TRUE(v1 == v2);
}

TEST(Vector4OperatorEqualTest, NotEqualVectors)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(1.1f, 2.1f, 3.1f, 4.1f);
    EXPECT_FALSE(v1 == v2);
}

TEST(Vector4OperatorAssignmentTest, BasicAssignment)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4<float> v2(0, 0, 0, 0);
    v2 = v1;
    EXPECT_FLOAT_EQ(v2.x(), 1.0f);
    EXPECT_FLOAT_EQ(v2.y(), 2.0f);
    EXPECT_FLOAT_EQ(v2.z(), 3.0f);
    EXPECT_FLOAT_EQ(v2.w(), 4.0f);
}

TEST(Vector4OperatorAssignmentTest, SelfAssignment)
{
    Vector4<float> v1(1.0f, 2.0f, 3.0f, 4.0f);
    v1 = v1;
    EXPECT_FLOAT_EQ(v1.x(), 1.0f);
    EXPECT_FLOAT_EQ(v1.y(), 2.0f);
    EXPECT_FLOAT_EQ(v1.z(), 3.0f);
    EXPECT_FLOAT_EQ(v1.w(), 4.0f);
}

TEST(Vector4CosTest, ZeroMagnitudeVectors)
{
    Vector4<float> v1(0.0f, 0.0f, 0.0f, 0.0f);
    Vector4<float> v2(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_DEATH(v1.cos(v2), "Cannot compute angle with a zero-magnitude vector");
}

TEST(Vector4AngleTest, ZeroMagnitudeVectors)
{
    Vector4<float> v1(0.0f, 0.0f, 0.0f, 0.0f);
    Vector4<float> v2(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_DEATH(v1.angle(v2), "Cannot compute angle with a zero-magnitude vector");
}

TEST(Vector4AliasTest, Vec4fConstructsCorrectly)
{
    ksemath::vec4f v(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
    EXPECT_FLOAT_EQ(v.w(), 4.0f);
}

TEST(Vector4AliasTest, Vec4dConstructsCorrectly)
{
    ksemath::vec4d v(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(v.x(), 1.0);
    EXPECT_DOUBLE_EQ(v.y(), 2.0);
    EXPECT_DOUBLE_EQ(v.z(), 3.0);
    EXPECT_DOUBLE_EQ(v.w(), 4.0);
}

TEST(Vector4AliasTest, Vec4lConstructsCorrectly)
{
    ksemath::vec4l v(1.0L, 2.0L, 3.0L, 4.0L);
    EXPECT_EQ(v.x(), 1.0L);
    EXPECT_EQ(v.y(), 2.0L);
    EXPECT_EQ(v.z(), 3.0L);
    EXPECT_EQ(v.w(), 4.0L);
}

TEST(Vector4MixedParamTest, AddIntAndFloatParams)
{
    ksemath::vec4f v(1, 2.5f, 3, 4.0f);
    v.add(1.5, 2, 3.5f, 0.5f);
    EXPECT_FLOAT_EQ(v.x(), 2.5f);
    EXPECT_FLOAT_EQ(v.y(), 4.5f);
    EXPECT_FLOAT_EQ(v.z(), 6.5f);
    EXPECT_FLOAT_EQ(v.w(), 4.5f);
}

TEST(Vector4MixedParamTest, SubFloatAndDoubleParams)
{
    ksemath::vec4d v(10.0f, 20.0, 30.0, 40.0);
    v.sub(2, 5.0f, 10.0, 15.0f);
    EXPECT_DOUBLE_EQ(v.x(), 8.0);
    EXPECT_DOUBLE_EQ(v.y(), 15.0);
    EXPECT_DOUBLE_EQ(v.z(), 20.0);
    EXPECT_DOUBLE_EQ(v.w(), 25.0);
}

TEST(Vector4MixedParamTest, MulFloatAndIntParams)
{
    ksemath::vec4f v(2.0f, 3.0f, 4.0f, 5.0f);
    v.mul(2, 0.5, 3, 4.0f);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 1.5f);
    EXPECT_FLOAT_EQ(v.z(), 12.0f);
    EXPECT_FLOAT_EQ(v.w(), 20.0f);
}

TEST(Vector4MixedParamTest, DivDoubleAndFloatParams)
{
    ksemath::vec4d v(9.0, 12.0, 18.0, 24.0);
    v.div(3.0f, 2, 6.0, 8.0f);
    EXPECT_DOUBLE_EQ(v.x(), 3.0);
    EXPECT_DOUBLE_EQ(v.y(), 6.0);
    EXPECT_DOUBLE_EQ(v.z(), 3.0);
    EXPECT_DOUBLE_EQ(v.w(), 3.0);
}

TEST(Vector4MixedTemplateTest, AddDifferentTemplateTypes)
{
    ksemath::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    ksemath::vec4d v2(3.0, 4.0, 5.0, 6.0);
    v1.add(v2.x(), v2.y(), v2.z(), v2.w());
    EXPECT_FLOAT_EQ(v1.x(), 4.0f);
    EXPECT_FLOAT_EQ(v1.y(), 6.0f);
    EXPECT_FLOAT_EQ(v1.z(), 8.0f);
    EXPECT_FLOAT_EQ(v1.w(), 10.0f);
}

TEST(Vector4MixedTemplateTest, SubDifferentTemplateTypes)
{
    ksemath::vec4d v1(5.5, 7.5, 9.5, 11.5);
    ksemath::vec4f v2(1.5f, 2.5f, 3.5f, 4.5f);
    v1.sub(v2.x(), v2.y(), v2.z(), v2.w());
    EXPECT_DOUBLE_EQ(v1.x(), 4.0);
    EXPECT_DOUBLE_EQ(v1.y(), 5.0);
    EXPECT_DOUBLE_EQ(v1.z(), 6.0);
    EXPECT_DOUBLE_EQ(v1.w(), 7.0);
}

TEST(Vector4MixedTemplateTest, MulDifferentTemplateTypes)
{
    ksemath::vec4l v1(2.0L, 4.0L, 5.0L, 6.0L);
    ksemath::vec4f v2(1.5f, 0.5f, 2.0f, 0.5f);
    v1.mul(v2.x(), v2.y(), v2.z(), v2.w());
    EXPECT_EQ(v1.x(), 3.0L);
    EXPECT_EQ(v1.y(), 2.0L);
    EXPECT_EQ(v1.z(), 10.0L);
    EXPECT_EQ(v1.w(), 3.0L);
}

TEST(Vector4MixedTemplateTest, DivDifferentTemplateTypes)
{
    ksemath::vec4f v1(10.0f, 20.0f, 40.0f, 80.0f);
    ksemath::vec4d v2(2.0, 4.0, 5.0, 10.0);
    v1.div(v2.x(), v2.y(), v2.z(), v2.w());
    EXPECT_FLOAT_EQ(v1.x(), 5.0f);
    EXPECT_FLOAT_EQ(v1.y(), 5.0f);
    EXPECT_FLOAT_EQ(v1.z(), 8.0f);
    EXPECT_FLOAT_EQ(v1.w(), 8.0f);
}
*/