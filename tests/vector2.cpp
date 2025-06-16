#include "include/vector2.hpp"

#include <gtest/gtest.h>

using ksemath::Vector2;

TEST(Vector2ConstructorTest, ConstructFromTwoScalars)
{
    Vector2<float> v(1.0f, 2.5f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.5f);
}

TEST(Vector2ConstructorTest, ConstructFromVector2)
{
    Vector2<float> v1(1.0f, 2.0f);
    Vector2<float> v(v1);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2ConstructorTest, ConstructWithZeroes)
{
    Vector2<float> v(0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
}

TEST(Vector2ConstructorTest, ConstructWithLargeValues)
{
    Vector2<float> v(1e10f, -1e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e10f);
    EXPECT_FLOAT_EQ(v.y(), -1e10f);
}

TEST(Vector2AddTest, AddVector2)
{
    Vector2<float> v(1.0f, 2.0f);
    Vector2<float> other(5.0f, 6.0f);
    v.add(other);
    EXPECT_FLOAT_EQ(v.x(), 6.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
}

TEST(Vector2SubTest, SubVector2)
{
    Vector2<float> v(10.0f, 10.0f);
    Vector2<float> other(1.0f, 2.0f);
    v.sub(other);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
}

TEST(Vector2MulTest, MulVector2)
{
    Vector2<float> v(2.0f, 3.0f);
    Vector2<float> other(2.0f, 3.0f);
    v.mul(other);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 9.0f);
}

TEST(Vector2DivTest, DivVector2)
{
    Vector2<float> v(20.0f, 30.0f);
    Vector2<float> other(2.0f, 3.0f);
    v.div(other);
    EXPECT_FLOAT_EQ(v.x(), 10.0f);
    EXPECT_FLOAT_EQ(v.y(), 10.0f);
}

TEST(Vector2EdgeCasesTest, AddWithZero)
{
    Vector2<float> v(1.0f, 2.0f);
    v.add(0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2EdgeCasesTest, SubWithZero)
{
    Vector2<float> v(1.0f, 2.0f);
    v.sub(0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2EdgeCasesTest, MulWithOne)
{
    Vector2<float> v(1.0f, 2.0f);
    v.mul(1.0f, 1.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2EdgeCasesTest, DivByOne)
{
    Vector2<float> v(1.0f, 2.0f);
    v.div(1.0f, 1.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2EdgeCasesTest, AddWithLargeNumbers)
{
    Vector2<float> v(1.0f, 2.0f);
    v.add(1e10f, 2e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f + 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f + 2e10f);
}

TEST(Vector2EdgeCasesTest, SubWithLargeNumbers)
{
    Vector2<float> v(1e20f, 2e20f);
    v.sub(1e10f, 2e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e20f - 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f - 2e10f);
}

TEST(Vector2EdgeCasesTest, MulWithLargeNumbers)
{
    Vector2<float> v(1.0f, 2.0f);
    v.mul(1e10f, 2e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 2e10f);
}

TEST(Vector2EdgeCasesTest, DivWithLargeNumbers)
{
    Vector2<float> v(1e20f, 2e20f);
    v.div(1e10f, 2e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e20f / 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f / 2e10f);
}

TEST(Vector2ScaleTest, ScaleWithPositiveFloat)
{
    Vector2<float> v(1.0f, 2.0f);
    v.scale(2.5f);
    EXPECT_FLOAT_EQ(v.x(), 2.5f);
    EXPECT_FLOAT_EQ(v.y(), 5.0f);
}

TEST(Vector2ScaleTest, ScaleWithZero)
{
    Vector2<float> v(1.0f, 2.0f);
    v.scale(0);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
}

TEST(Vector2MagnitudeSqrTest, MagnitudeSqrPositiveVector)
{
    Vector2<float> v(1.0f, 2.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1.0f + 4.0f);
}

TEST(Vector2MagnitudeSqrTest, MagnitudeSqrZeroVector)
{
    Vector2<float> v(0.0f, 0.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vector2MagnitudeSqrTest, MagnitudeSqrLargeVector)
{
    Vector2<float> v(1e10f, 2e10f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1e20f + 4e20f);
}

TEST(Vector2MagnitudeTest, MagnitudePositiveVector)
{
    Vector2<float> v(1.0f, 2.0f);
    float result = v.magnitude();
    float expected = std::sqrt(1.0f + 4.0f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector2MagnitudeTest, MagnitudeZeroVector)
{
    Vector2<float> v(0.0f, 0.0f);
    float result = v.magnitude();
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vector2NormalizeEdgeCase, NormalizeAfterScaling)
{
    Vector2<float> v(1.0f, 2.0f);
    v.scale(100.0f);
    v.normalize();
    EXPECT_NEAR(v.magnitude(), 1.0f, 1e-6f);
}

TEST(Vector2DotTest, BasicDotProduct)
{
    Vector2<float> v1(1.0f, 2.0f);
    Vector2<float> v2(2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v1.dot(v2), 1.0f * 2.0f + 2.0f * 3.0f);
}

TEST(Vector2CosTest, CosBetweenSameVectors)
{
    Vector2<float> v(1.0f, 2.0f);
    EXPECT_FLOAT_EQ(v.cos(v), 1.0f);
}

TEST(Vector2CosTest, CosBetweenOrthogonalVectors)
{
    Vector2<float> v1(1.0f, 0.0f);
    Vector2<float> v2(0.0f, 1.0f);
    EXPECT_FLOAT_EQ(v1.cos(v2), 0.0f);
}

TEST(Vector2AngleTest, AngleBetweenOrthogonalVectors)
{
    Vector2<float> v1(1.0f, 0.0f);
    Vector2<float> v2(0.0f, 1.0f);
    EXPECT_FLOAT_EQ(v1.angle(v2), M_PI_2);
}

TEST(Vector2MadTest, MadWithFloatScalar)
{
    Vector2<float> v1(1.0f, 2.0f);
    Vector2<float> v2(0.1f, 0.2f);
    v1.mad(v2, 2.0f);
    EXPECT_FLOAT_EQ(v1.x(), 1.2f);
    EXPECT_FLOAT_EQ(v1.y(), 2.4f);
}

TEST(Vector2EqualTest, EqualVectors)
{
    Vector2<float> v1(1.0f, 2.0f);
    Vector2<float> v2(1.0f + 1e-6f, 2.0f + 1e-6f);
    EXPECT_TRUE(v1.equal(v2));
}

TEST(Vector2EqualTest, NotEqualVectors)
{
    Vector2<float> v1(1.0f, 2.0f);
    Vector2<float> v2(1.01f, 2.01f);
    EXPECT_FALSE(v1.equal(v2));
}

TEST(Vector2AliasTest, Vec2fConstructsCorrectly)
{
    ksemath::vec2f v(1.0f, 2.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
}

TEST(Vector2AliasTest, Vec2dConstructsCorrectly)
{
    ksemath::vec2d v(1.0, 2.0);
    EXPECT_DOUBLE_EQ(v.x(), 1.0);
    EXPECT_DOUBLE_EQ(v.y(), 2.0);
}

TEST(Vector2AliasTest, Vec2lConstructsCorrectly)
{
    ksemath::vec2l v(1.0L, 2.0L);
    EXPECT_EQ(v.x(), 1.0L);
    EXPECT_EQ(v.y(), 2.0L);
}

TEST(Vector2MixedParamTest, AddIntAndFloatParams)
{
    Vector2<float> v(1, 2.5f);
    v.add(3.5, 4);
    EXPECT_FLOAT_EQ(v.x(), 4.5f);
    EXPECT_FLOAT_EQ(v.y(), 6.5f);
}

TEST(Vector2MixedParamTest, SubFloatAndDoubleParams)
{
    Vector2<double> v(10.0f, 20.0);
    v.sub(2, 5.0f);
    EXPECT_DOUBLE_EQ(v.x(), 8.0);
    EXPECT_DOUBLE_EQ(v.y(), 15.0);
}

TEST(Vector2MixedParamTest, MulFloatAndIntParams)
{
    Vector2<float> v(2.0f, 3.0f);
    v.mul(2, 0.5);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 1.5f);
}

TEST(Vector2MixedParamTest, DivDoubleAndFloatParams)
{
    Vector2<double> v(9.0, 12.0);
    v.div(3.0f, 2);
    EXPECT_DOUBLE_EQ(v.x(), 3.0);
    EXPECT_DOUBLE_EQ(v.y(), 6.0);
}

TEST(Vector2MixedTemplateTest, AddDifferentTemplateTypes)
{
    Vector2<float> v1(1.0f, 2.0f);
    Vector2<double> v2(3.0, 4.0);
    v1.add(v2.x(), v2.y());
    EXPECT_FLOAT_EQ(v1.x(), 4.0f);
    EXPECT_FLOAT_EQ(v1.y(), 6.0f);
}

TEST(Vector2MixedTemplateTest, SubDifferentTemplateTypes)
{
    Vector2<double> v1(5.5, 7.5);
    Vector2<float> v2(1.5f, 2.5f);
    v1.sub(v2.x(), v2.y());
    EXPECT_DOUBLE_EQ(v1.x(), 4.0);
    EXPECT_DOUBLE_EQ(v1.y(), 5.0);
}

TEST(Vector2MixedTemplateTest, MulDifferentTemplateTypes)
{
    Vector2<long double> v1(2.0L, 4.0L);
    Vector2<float> v2(1.5f, 0.5f);
    v1.mul(v2.x(), v2.y());
    EXPECT_EQ(v1.x(), 3.0L);
    EXPECT_EQ(v1.y(), 2.0L);
}

TEST(Vector2MixedTemplateTest, DivDifferentTemplateTypes)
{
    Vector2<float> v1(10.0f, 20.0f);
    Vector2<double> v2(2.0, 4.0);
    v1.div(v2.x(), v2.y());
    EXPECT_FLOAT_EQ(v1.x(), 5.0f);
    EXPECT_FLOAT_EQ(v1.y(), 5.0f);
}
