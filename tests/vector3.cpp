#include "src/math/vector3.hpp"

#include <gtest/gtest.h>

#include "src/math/vector2.hpp"

using math::Vector2;
using math::Vector3;

TEST(Vector3ConstructorTest, ConstructFromThreeScalars)
{
    Vector3 v(1, 2.5f, 3.0);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.5f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vector3ConstructorTest, ConstructFromVector2AndScalar)
{
    Vector2 v2(1.0f, 2.0f);
    Vector3 v(v2, 3);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vector3ConstructorTest, ConstructFromScalarAndVector2)
{
    Vector2 v2(2.0f, 3.0f);
    Vector3 v(1, v2);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vector3ConstructorTest, ConstructWithNegativeValues)
{
    Vector3 v(-1, -2.5f, -3.0);
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.5f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
}

TEST(Vector3ConstructorTest, ConstructWithZeroes)
{
    Vector3 v(0, 0.0f, 0.0);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
    EXPECT_FLOAT_EQ(v.z(), 0.0f);
}

TEST(Vector3ConstructorTest, ConstructWithLargeValues)
{
    Vector3 v(1e10, -1e10f, 3.4e+38);
    EXPECT_FLOAT_EQ(v.x(), 1e10f);
    EXPECT_FLOAT_EQ(v.y(), -1e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.4e+38f);
}

TEST(Vector3AddTest, AddThreeNumericValues)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.add(4, 5.0f, 6.0);
    EXPECT_FLOAT_EQ(v.x(), 5.0f);
    EXPECT_FLOAT_EQ(v.y(), 7.0f);
    EXPECT_FLOAT_EQ(v.z(), 9.0f);
}

TEST(Vector3AddTest, AddVector2AndScalar)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    Vector2 v2(4.0f, 5.0f);
    v.add(v2, 6);
    EXPECT_FLOAT_EQ(v.x(), 5.0f);
    EXPECT_FLOAT_EQ(v.y(), 7.0f);
    EXPECT_FLOAT_EQ(v.z(), 9.0f);
}

TEST(Vector3AddTest, AddScalarAndVector2)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    Vector2 v2(5.0f, 6.0f);
    v.add(4, v2);
    EXPECT_FLOAT_EQ(v.x(), 5.0f);
    EXPECT_FLOAT_EQ(v.y(), 7.0f);
    EXPECT_FLOAT_EQ(v.z(), 9.0f);
}

TEST(Vector3AddTest, AddVector3)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    Vector3 other(4.0f, 5.0f, 6.0f);
    v.add(other);
    EXPECT_FLOAT_EQ(v.x(), 5.0f);
    EXPECT_FLOAT_EQ(v.y(), 7.0f);
    EXPECT_FLOAT_EQ(v.z(), 9.0f);
}

TEST(Vector3SubTest, SubThreeNumericValues)
{
    Vector3 v(10.0f, 10.0f, 10.0f);
    v.sub(1, 2.0f, 3.0);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
}

TEST(Vector3SubTest, SubVector2AndScalar)
{
    Vector3 v(10.0f, 10.0f, 10.0f);
    Vector2 v2(1.0f, 2.0f);
    v.sub(v2, 3);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
}

TEST(Vector3SubTest, SubScalarAndVector2)
{
    Vector3 v(10.0f, 10.0f, 10.0f);
    Vector2 v2(2.0f, 3.0f);
    v.sub(1, v2);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
}

TEST(Vector3SubTest, SubVector3)
{
    Vector3 v(10.0f, 10.0f, 10.0f);
    Vector3 other(1.0f, 2.0f, 3.0f);
    v.sub(other);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
}

TEST(Vector3EdgeCasesTest, AddWithLargeNumbers)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.add(1e10, 2e10f, 3e10);
    EXPECT_FLOAT_EQ(v.x(), 1.0f + 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f + 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f + 3e10f);
}

TEST(Vector3EdgeCasesTest, SubWithLargeNumbers)
{
    Vector3 v(1e20f, 2e20f, 3e20f);
    v.sub(1e10, 2e10f, 3e10);
    EXPECT_FLOAT_EQ(v.x(), 1e20f - 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f - 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3e20f - 3e10f);
}

TEST(Vector3EdgeCasesTest, MulWithLargeNumbers)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.mul(1e10, 2e10f, 3e10);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f * 3e10f);
}

TEST(Vector3EdgeCasesTest, DivWithLargeNumbers)
{
    Vector3 v(1e20f, 2e20f, 3e20f);
    v.div(1e10, 2e10f, 3e10);
    EXPECT_FLOAT_EQ(v.x(), 1e20f / 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f / 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3e20f / 3e10f);
}

TEST(Vector3EdgeCasesTest, AddWithMixedTypes)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.add(1, 2.0f, 3u);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
    EXPECT_FLOAT_EQ(v.z(), 6.0f);
}

TEST(Vector3EdgeCasesTest, SubWithMixedTypes)
{
    Vector3 v(10.0f, 10.0f, 10.0f);
    v.sub(1, 2.0f, 3u);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
}

TEST(Vector3EdgeCasesTest, MulWithMixedTypes)
{
    Vector3 v(2.0f, 2.0f, 2.0f);
    v.mul(1, 2.0f, 3u);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
    EXPECT_FLOAT_EQ(v.z(), 6.0f);
}

TEST(Vector3EdgeCasesTest, DivWithMixedTypes)
{
    Vector3 v(20.0f, 20.0f, 20.0f);
    v.div(1, 2.0f, 4u);
    EXPECT_FLOAT_EQ(v.x(), 20.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
    EXPECT_FLOAT_EQ(v.z(), 5.0f);
}

TEST(Vector3ScaleTest, ScaleWithPositiveInteger)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.scale(2);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
    EXPECT_FLOAT_EQ(v.z(), 6.0f);
}

TEST(Vector3ScaleTest, ScaleWithPositiveFloat)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.scale(2.5f);
    EXPECT_FLOAT_EQ(v.x(), 2.5f);
    EXPECT_FLOAT_EQ(v.y(), 5.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.5f);
}

TEST(Vector3ScaleTest, ScaleWithNegativeValue)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.scale(-1);
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
}

TEST(Vector3ScaleTest, ScaleWithZero)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.scale(0);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
    EXPECT_FLOAT_EQ(v.z(), 0.0f);
}

TEST(Vector3ScaleTest, ScaleWithLargeNumber)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.scale(1e10);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f * 1e10f);
}

TEST(Vector3ScaleTest, ScaleWithSmallNumber)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.scale(1e-10);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e-10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 1e-10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f * 1e-10f);
}

TEST(Vector3NormalizeTest, NormalizeNonZeroVector)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.normalize();
    float mag = v.magnitude();
    EXPECT_NEAR(mag, 1.0f, 1e-6f);
}

TEST(Vector3NormalizeTest, NormalizeAlreadyUnitVector)
{
    Vector3 v(1.0f, 0.0f, 0.0f);
    v.normalize();
    EXPECT_NEAR(v.x(), 1.0f, 1e-6f);
    EXPECT_NEAR(v.y(), 0.0f, 1e-6f);
    EXPECT_NEAR(v.z(), 0.0f, 1e-6f);
}

TEST(Vector3NormalizeTest, NormalizeNegativeVector)
{
    Vector3 v(-1.0f, -2.0f, -3.0f);
    v.normalize();
    float mag = v.magnitude();
    EXPECT_NEAR(mag, 1.0f, 1e-6f);
}

TEST(Vector3NormalizeDeathTest, NormalizeZeroVector)
{
    Vector3 v(0.0f, 0.0f, 0.0f);
    EXPECT_DEATH(v.normalize(), "Cannot normalize a zero-length vector");
}

TEST(Vector3NegateTest, NegatePositiveVector)
{
    Vector3 v(1.0f, 2.0f, 3.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
}

TEST(Vector3NegateTest, NegateNegativeVector)
{
    Vector3 v(-1.0f, -2.0f, -3.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vector3NegateTest, NegateMixedVector)
{
    Vector3 v(1.0f, -2.0f, 3.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
}
