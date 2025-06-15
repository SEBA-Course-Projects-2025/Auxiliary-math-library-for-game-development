#include "../include/vector2.hpp"

#include <gtest/gtest.h>

using math::Vector2;

TEST(Vector2ConstructorTest, ConstructFromTwoScalars)
{
    Vector2 v(1, 2.5f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.5f);
}

TEST(Vector2ConstructorTest, ConstructFromVector2)
{
    Vector2 v1(1.0f, 2.0f);
    Vector2 v(v1);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2ConstructorTest, ConstructWithNegativeValues)
{
    Vector2 v(-1, -2.5f);
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.5f);
}

TEST(Vector2ConstructorTest, ConstructWithZeroes)
{
    Vector2 v(0, 0.0f);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
}

TEST(Vector2ConstructorTest, ConstructWithLargeValues)
{
    Vector2 v(1e10, -1e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e10f);
    EXPECT_FLOAT_EQ(v.y(), -1e10f);
}

TEST(Vector2AddTest, AddTwoNumericValues)
{
    Vector2 v(1.0f, 2.0f);
    v.add(5, 6.0f);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
}

TEST(Vector2AddTest, AddVector2)
{
    Vector2 v(1.0f, 2.0f);
    Vector2 other(5.0f, 6.0f);
    v.add(other);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
}

TEST(Vector2SubTest, SubTwoNumericValues)
{
    Vector2 v(10.0f, 10.0f);
    v.sub(1, 2.0f);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
}

TEST(Vector2SubTest, SubVector2)
{
    Vector2 v(10.0f, 10.0f);
    Vector2 other(1.0f, 2.0f);
    v.sub(other);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
}

TEST(Vector2MulTest, MulTwoNumericValues)
{
    Vector2 v(2.0f, 3.0f);
    v.mul(2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
}

TEST(Vector2MulTest, MulVector2)
{
    Vector2 v(2.0f, 3.0f);
    Vector2 other(2.0f, 3.0f);
    v.mul(other);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
}

TEST(Vector2DivTest, DivTwoNumericValues)
{
    Vector2 v(20.0f, 30.0f);
    v.div(2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
}

TEST(Vector2DivTest, DivVector2)
{
    Vector2 v(20.0f, 30.0f);
    Vector2 other(2.0f, 3.0f);
    v.div(other);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
}

TEST(Vector2DivTest, DivTwoVector2s)
{
    Vector2 v(20.0f, 30.0f);
    Vector2 v1(2.0f, 3.0f);
    v.div(v1);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
}

TEST(Vector2EdgeCasesTest, AddWithZero)
{
    Vector2 v(1.0f, 2.0f);
    v.add(0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2EdgeCasesTest, SubWithZero)
{
    Vector2 v(1.0f, 2.0f);
    v.sub(0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2EdgeCasesTest, MulWithOne)
{
    Vector2 v(1.0f, 2.0f);
    v.mul(1.0f, 1.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2EdgeCasesTest, DivByOne)
{
    Vector2 v(1.0f, 2.0f);
    v.div(1.0f, 1.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2EdgeCasesTest, AddWithLargeNumbers)
{
    Vector2 v(1.0f, 2.0f);
    v.add(1e10f, 2e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f + 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f + 2e10f);
}

TEST(Vector2EdgeCasesTest, SubWithLargeNumbers)
{
    Vector2 v(1e20f, 2e20f);
    v.sub(1e10f, 2e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e20f - 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f - 2e10f);
}

TEST(Vector2EdgeCasesTest, MulWithLargeNumbers)
{
    Vector2 v(1.0f, 2.0f);
    v.mul(1e10f, 2e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 2e10f);
}

TEST(Vector2EdgeCasesTest, DivWithLargeNumbers)
{
    Vector2 v(1e20f, 2e20f);
    v.div(1e10f, 2e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e20f / 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f / 2e10f);
}

TEST(Vector2EdgeCasesTest, AddWithMixedTypes)
{
    Vector2 v(1.0f, 2.0f);
    v.add(1, 2.0);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
}

TEST(Vector2EdgeCasesTest, SubWithMixedTypes)
{
    Vector2 v(10.0f, 10.0f);
    v.sub(1, 2.0);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
}

TEST(Vector2EdgeCasesTest, MulWithMixedTypes)
{
    Vector2 v(2.0f, 2.0f);
    v.mul(1, 2.0);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
}

TEST(Vector2EdgeCasesTest, DivWithMixedTypes)
{
    Vector2 v(20.0f, 20.0f);
    v.div(1, 2.0);
    EXPECT_FLOAT_EQ(v.x(), 20.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
}

TEST(Vector2ScaleTest, ScaleWithPositiveInteger)
{
    Vector2 v(1.0f, 2.0f);
    v.scale(2);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
}

TEST(Vector2ScaleTest, ScaleWithPositiveFloat)
{
    Vector2 v(1.0f, 2.0f);
    v.scale(2.5f);
    EXPECT_FLOAT_EQ(v.x(), 2.5f);
    EXPECT_FLOAT_EQ(v.y(), 5.0f);
}

TEST(Vector2ScaleTest, ScaleWithNegativeValue)
{
    Vector2 v(1.0f, 2.0f);
    v.scale(-1);
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.0f);
}

TEST(Vector2ScaleTest, ScaleWithZero)
{
    Vector2 v(1.0f, 2.0f);
    v.scale(0);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
}

TEST(Vector2MagnitudeSqrTest, MagnitudeSqrPositiveVector)
{
    Vector2 v(1.0f, 2.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1.0f + 4.0f);
}

TEST(Vector2MagnitudeSqrTest, MagnitudeSqrNegativeVector)
{
    Vector2 v(-1.0f, -2.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1.0f + 4.0f);
}

TEST(Vector2MagnitudeSqrTest, MagnitudeSqrZeroVector)
{
    Vector2 v(0.0f, 0.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vector2MagnitudeSqrTest, MagnitudeSqrLargeVector)
{
    Vector2 v(1e10f, 2e10f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1e20f + 4e20f);
}

TEST(Vector2MagnitudeTest, MagnitudePositiveVector)
{
    Vector2 v(1.0f, 2.0f);
    float result = v.magnitude();
    float expected = std::sqrt(1.0f + 4.0f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector2MagnitudeTest, MagnitudeNegativeVector)
{
    Vector2 v(-1.0f, -2.0f);
    float result = v.magnitude();
    float expected = std::sqrt(1.0f + 4.0f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector2MagnitudeTest, MagnitudeZeroVector)
{
    Vector2 v(0.0f, 0.0f);
    float result = v.magnitude();
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vector2MagnitudeTest, MagnitudeLargeVector)
{
    Vector2 v(1e10f, 2e10f);
    float result = v.magnitude();
    float expected = std::sqrt(1e20f + 4e20f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector2MagnitudeTest, MagnitudeSmallVector)
{
    Vector2 v(1e-10f, 2e-10f);
    float result = v.magnitude();
    float expected = std::sqrt(1e-20f + 4e-20f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector2NormalizeEdgeCase, NormalizeAfterScaling)
{
    Vector2 v(1.0f, 2.0f);
    v.scale(100.0f);
    v.normalize();
    EXPECT_NEAR(v.magnitude(), 1.0f, 1e-6f);
}

TEST(Vector2EdgeCase, ScaleThenNegate)
{
    Vector2 v(1.0f, 2.0f);
    v.scale(-2.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
}

TEST(Vector2EdgeCase, MagnitudeAfterNormalize)
{
    Vector2 v(5.0f, 0.0f);
    v.normalize();
    EXPECT_FLOAT_EQ(v.magnitude(), 1.0f);
    EXPECT_FLOAT_EQ(v.magnitude_sqr(), 1.0f);
}

TEST(Vector2DotTest, BasicDotProduct)
{
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v1.dot(v2), 1.0f * 2.0f + 2.0f * 3.0f);
}

TEST(Vector2DotTest, DotProductWithSelf)
{
    Vector2 v(1.0f, 2.0f);
    EXPECT_FLOAT_EQ(v.dot(v), 1.0f * 1.0f + 2.0f * 2.0f);
}

TEST(Vector2DotTest, DotProductWithNegativeValues)
{
    Vector2 v1(1.0f, -2.0f);
    Vector2 v2(-2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v1.dot(v2), 1.0f * -2.0f + -2.0f * 3.0f);
}

TEST(Vector2DotTest, DotProductWithLargeValues)
{
    Vector2 v1(1e10f, 2e10f);
    Vector2 v2(2e10f, 3e10f);
    EXPECT_FLOAT_EQ(v1.dot(v2), 2e20f + 6e20f);
}

TEST(Vector2CosTest, CosBetweenSameVectors)
{
    Vector2 v(1.0f, 2.0f);
    EXPECT_FLOAT_EQ(v.cos(v), 1.0f);
}

TEST(Vector2CosTest, CosBetweenOrthogonalVectors)
{
    Vector2 v1(1.0f, 0.0f);
    Vector2 v2(0.0f, 1.0f);
    EXPECT_FLOAT_EQ(v1.cos(v2), 0.0f);
}

TEST(Vector2CosTest, CosBetweenOppositeVectors)
{
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(-1.0f, -2.0f);
    EXPECT_FLOAT_EQ(v1.cos(v2), -1.0f);
}

TEST(Vector2AngleTest, AngleBetweenOrthogonalVectors)
{
    Vector2 v1(1.0f, 0.0f);
    Vector2 v2(0.0f, 1.0f);
    EXPECT_FLOAT_EQ(v1.angle(v2), M_PI_2);
}

TEST(Vector2AngleTest, AngleBetweenOppositeVectors)
{
    Vector2 v1(1.0f, 0.0f);
    Vector2 v2(-1.0f, 0.0f);
    EXPECT_FLOAT_EQ(v1.angle(v2), M_PI);
}

TEST(Vector2MadTest, MadWithFloatScalar)
{
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(0.1f, 0.2f);
    v1.mad(v2, 2.0f);
    EXPECT_FLOAT_EQ(v1.x(), 1.2f);
    EXPECT_FLOAT_EQ(v1.y(), 2.4f);
}

TEST(Vector2MadTest, MadWithIntScalar)
{
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(0.1f, 0.2f);
    v1.mad(v2, 2);
    EXPECT_FLOAT_EQ(v1.x(), 1.2f);
    EXPECT_FLOAT_EQ(v1.y(), 2.4f);
}

TEST(Vector2MadTest, MadWithLargeScalar)
{
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(1e10f, 2e10f);
    v1.mad(v2, 1e-10f);
    EXPECT_FLOAT_EQ(v1.x(), 2.0f);
    EXPECT_FLOAT_EQ(v1.y(), 4.0f);
}

TEST(Vector2EqualTest, EqualVectors)
{
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(1.0f + 1e-6f, 2.0f + 1e-6f);
    EXPECT_TRUE(v1.equal(v2));
}

TEST(Vector2EqualTest, NotEqualVectors)
{
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(1.01f, 2.01f);
    EXPECT_FALSE(v1.equal(v2));
}
