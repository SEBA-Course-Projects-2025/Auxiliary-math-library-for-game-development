#include "include/vector3.hpp"

#include <gtest/gtest.h>

#include "include/vector2.hpp"

using ksemath::Vector2;
using ksemath::Vector3;

TEST(Vector3ConstructorTest, ConstructFromThreeScalars)
{
    Vector3<float> v(1, 2, 3);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vector3ConstructorTest, ConstructFromVector2AndScalar)
{
    Vector2<float> v2(1.0f, 2.0f);
    Vector3<float> v(v2, 3);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vector3ConstructorTest, ConstructFromScalarAndVector2)
{
    Vector2<float> v2(2.0f, 3.0f);
    Vector3<float> v(1, v2);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vector3ConstructorTest, ConstructWithNegativeValues)
{
    Vector3<float> v(-1, -2, -3);
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
}

TEST(Vector3ConstructorTest, ConstructWithZeroes)
{
    Vector3<float> v(0, 0, 0);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
    EXPECT_FLOAT_EQ(v.z(), 0.0f);
}

TEST(Vector3ConstructorTest, ConstructWithLargeValues)
{
    Vector3<float> v(1e10f, -1e10f, 3.4e+38f);
    EXPECT_FLOAT_EQ(v.x(), 1e10f);
    EXPECT_FLOAT_EQ(v.y(), -1e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.4e+38f);
}

TEST(Vector3AddTest, AddThreeNumericValues)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.add(4, 5, 6);
    EXPECT_FLOAT_EQ(v.x(), 5.0f);
    EXPECT_FLOAT_EQ(v.y(), 7.0f);
    EXPECT_FLOAT_EQ(v.z(), 9.0f);
}

TEST(Vector3AddTest, AddVector2AndScalar)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    Vector2<float> v2(4.0f, 5.0f);
    v.add(v2, 6);
    EXPECT_FLOAT_EQ(v.x(), 5.0f);
    EXPECT_FLOAT_EQ(v.y(), 7.0f);
    EXPECT_FLOAT_EQ(v.z(), 9.0f);
}

TEST(Vector3AddTest, AddScalarAndVector2)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    Vector2<float> v2(5.0f, 6.0f);
    v.add(4, v2);
    EXPECT_FLOAT_EQ(v.x(), 5.0f);
    EXPECT_FLOAT_EQ(v.y(), 7.0f);
    EXPECT_FLOAT_EQ(v.z(), 9.0f);
}

TEST(Vector3AddTest, AddVector3)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    Vector3<float> other(4.0f, 5.0f, 6.0f);
    v.add(other);
    EXPECT_FLOAT_EQ(v.x(), 5.0f);
    EXPECT_FLOAT_EQ(v.y(), 7.0f);
    EXPECT_FLOAT_EQ(v.z(), 9.0f);
}

TEST(Vector3SubTest, SubThreeNumericValues)
{
    Vector3<float> v(10.0f, 10.0f, 10.0f);
    v.sub(1, 2, 3);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
}

TEST(Vector3SubTest, SubVector2AndScalar)
{
    Vector3<float> v(10.0f, 10.0f, 10.0f);
    Vector2<float> v2(1.0f, 2.0f);
    v.sub(v2, 3);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
}

TEST(Vector3SubTest, SubScalarAndVector2)
{
    Vector3<float> v(10.0f, 10.0f, 10.0f);
    Vector2<float> v2(2.0f, 3.0f);
    v.sub(1, v2);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
}

TEST(Vector3SubTest, SubVector3)
{
    Vector3<float> v(10.0f, 10.0f, 10.0f);
    Vector3<float> other(1.0f, 2.0f, 3.0f);
    v.sub(other);
    EXPECT_FLOAT_EQ(v.x(), 9.0f);
    EXPECT_FLOAT_EQ(v.y(), 8.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.0f);
}

TEST(Vector3EdgeCasesTest, AddWithLargeNumbers)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.add(1e10f, 2e10f, 3e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f + 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f + 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f + 3e10f);
}

TEST(Vector3EdgeCasesTest, SubWithLargeNumbers)
{
    Vector3<float> v(1e20f, 2e20f, 3e20f);
    v.sub(1e10f, 2e10f, 3e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e20f - 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f - 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3e20f - 3e10f);
}

TEST(Vector3EdgeCasesTest, MulWithLargeNumbers)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.mul(1e10f, 2e10f, 3e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f * 3e10f);
}

TEST(Vector3EdgeCasesTest, DivWithLargeNumbers)
{
    Vector3<float> v(1e20f, 2e20f, 3e20f);
    v.div(1e10f, 2e10f, 3e10f);
    EXPECT_FLOAT_EQ(v.x(), 1e20f / 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2e20f / 2e10f);
    EXPECT_FLOAT_EQ(v.z(), 3e20f / 3e10f);
}

TEST(Vector3ScaleTest, ScaleWithPositiveInteger)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.scale(2);
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
    EXPECT_FLOAT_EQ(v.z(), 6.0f);
}

TEST(Vector3ScaleTest, ScaleWithPositiveFloat)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.scale(2.5f);
    EXPECT_FLOAT_EQ(v.x(), 2.5f);
    EXPECT_FLOAT_EQ(v.y(), 5.0f);
    EXPECT_FLOAT_EQ(v.z(), 7.5f);
}

TEST(Vector3ScaleTest, ScaleWithNegativeValue)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.scale(-1);
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
}

TEST(Vector3ScaleTest, ScaleWithZero)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.scale(0);
    EXPECT_FLOAT_EQ(v.x(), 0.0f);
    EXPECT_FLOAT_EQ(v.y(), 0.0f);
    EXPECT_FLOAT_EQ(v.z(), 0.0f);
}

TEST(Vector3ScaleTest, ScaleWithLargeNumber)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.scale(1e10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 1e10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f * 1e10f);
}

TEST(Vector3ScaleTest, ScaleWithSmallNumber)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.scale(1e-10f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f * 1e-10f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f * 1e-10f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f * 1e-10f);
}

TEST(Vector3NormalizeTest, NormalizeNonZeroVector)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.normalize();
    float mag = v.magnitude();
    EXPECT_NEAR(mag, 1.0f, 1e-6f);
}

TEST(Vector3NormalizeTest, NormalizeAlreadyUnitVector)
{
    Vector3<float> v(1.0f, 0.0f, 0.0f);
    v.normalize();
    EXPECT_NEAR(v.x(), 1.0f, 1e-6f);
    EXPECT_NEAR(v.y(), 0.0f, 1e-6f);
    EXPECT_NEAR(v.z(), 0.0f, 1e-6f);
}

TEST(Vector3NormalizeTest, NormalizeNegativeVector)
{
    Vector3<float> v(-1.0f, -2.0f, -3.0f);
    v.normalize();
    float mag = v.magnitude();
    EXPECT_NEAR(mag, 1.0f, 1e-6f);
}

TEST(Vector3NormalizeDeathTest, NormalizeZeroVector)
{
    Vector3<float> v(0.0f, 0.0f, 0.0f);
    EXPECT_DEATH(v.normalize(), "Cannot normalize a zero-length vector");
}

TEST(Vector3NegateTest, NegatePositiveVector)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), -2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
}

TEST(Vector3NegateTest, NegateNegativeVector)
{
    Vector3<float> v(-1.0f, -2.0f, -3.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vector3NegateTest, NegateMixedVector)
{
    Vector3<float> v(1.0f, -2.0f, 3.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), -1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), -3.0f);
}

TEST(Vector3MagnitudeSqrTest, MagnitudeSqrPositiveVector)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1.0f + 4.0f + 9.0f);
}

TEST(Vector3MagnitudeSqrTest, MagnitudeSqrNegativeVector)
{
    Vector3<float> v(-1.0f, -2.0f, -3.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1.0f + 4.0f + 9.0f);
}

TEST(Vector3MagnitudeSqrTest, MagnitudeSqrZeroVector)
{
    Vector3<float> v(0.0f, 0.0f, 0.0f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vector3MagnitudeSqrTest, MagnitudeSqrLargeVector)
{
    Vector3<float> v(1e10f, 2e10f, 3e10f);
    float result = v.magnitude_sqr();
    EXPECT_FLOAT_EQ(result, 1e20f + 4e20f + 9e20f);
}

TEST(Vector3MagnitudeTest, MagnitudePositiveVector)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    float result = v.magnitude();
    float expected = std::sqrt(1.0f + 4.0f + 9.0f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector3MagnitudeTest, MagnitudeNegativeVector)
{
    Vector3<float> v(-1.0f, -2.0f, -3.0f);
    float result = v.magnitude();
    float expected = std::sqrt(1.0f + 4.0f + 9.0f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector3MagnitudeTest, MagnitudeZeroVector)
{
    Vector3<float> v(0.0f, 0.0f, 0.0f);
    float result = v.magnitude();
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vector3MagnitudeTest, MagnitudeLargeVector)
{
    Vector3<float> v(1e10f, 2e10f, 3e10f);
    float result = v.magnitude();
    float expected = std::sqrt(1e20f + 4e20f + 9e20f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector3MagnitudeTest, MagnitudeSmallVector)
{
    Vector3<float> v(1e-10f, 2e-10f, 3e-10f);
    float result = v.magnitude();
    float expected = std::sqrt(1e-20f + 4e-20f + 9e-20f);
    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Vector3NormalizeEdgeCase, NormalizeAfterScaling)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.scale(100.0f);
    v.normalize();
    EXPECT_NEAR(v.magnitude(), 1.0f, 1e-6f);
}

TEST(Vector3EdgeCase, ScaleThenNegate)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v.scale(-2.0f);
    v.negate();
    EXPECT_FLOAT_EQ(v.x(), 2.0f);
    EXPECT_FLOAT_EQ(v.y(), 4.0f);
    EXPECT_FLOAT_EQ(v.z(), 6.0f);
}

TEST(Vector3EdgeCase, MagnitudeAfterNormalize)
{
    Vector3<float> v(5.0f, 0.0f, 0.0f);
    v.normalize();
    EXPECT_FLOAT_EQ(v.magnitude(), 1.0f);
    EXPECT_FLOAT_EQ(v.magnitude_sqr(), 1.0f);
}

TEST(Vector3CosTest, CosBetweenSameVectors)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v.cos(v), 1.0f);
}

TEST(Vector3CosTest, CosBetweenOrthogonalVectors)
{
    Vector3<float> v1(1.0f, 0.0f, 0.0f);
    Vector3<float> v2(0.0f, 1.0f, 0.0f);
    EXPECT_FLOAT_EQ(v1.cos(v2), 0.0f);
}

TEST(Vector3CosTest, CosBetweenOppositeVectors)
{
    Vector3<float> v1(1.0f, 2.0f, 3.0f);
    Vector3<float> v2(-1.0f, -2.0f, -3.0f);
    EXPECT_FLOAT_EQ(v1.cos(v2), -1.0f);
}

TEST(Vector3AngleTest, AngleBetweenSameVectors)
{
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v.angle(v), 0.0f);
}

TEST(Vector3AngleTest, AngleBetweenOrthogonalVectors)
{
    Vector3<float> v1(1.0f, 0.0f, 0.0f);
    Vector3<float> v2(0.0f, 1.0f, 0.0f);
    EXPECT_FLOAT_EQ(v1.angle(v2), M_PI_2);
}

TEST(Vector3AngleTest, AngleBetweenOppositeVectors)
{
    Vector3<float> v1(1.0f, 0.0f, 0.0f);
    Vector3<float> v2(-1.0f, 0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v1.angle(v2), M_PI);
}

TEST(Vector3MadTest, MadWithFloatScalar)
{
    Vector3<float> v1(1.0f, 2.0f, 3.0f);
    Vector3<float> v2(0.1f, 0.2f, 0.3f);
    v1.mad(v2, 2.0f);
    EXPECT_FLOAT_EQ(v1.x(), 1.2f);
    EXPECT_FLOAT_EQ(v1.y(), 2.4f);
    EXPECT_FLOAT_EQ(v1.z(), 3.6f);
}

TEST(Vector3MadTest, MadWithIntScalar)
{
    Vector3<float> v1(1.0f, 2.0f, 3.0f);
    Vector3<float> v2(0.1f, 0.2f, 0.3f);
    v1.mad(v2, 2);
    EXPECT_FLOAT_EQ(v1.x(), 1.2f);
    EXPECT_FLOAT_EQ(v1.y(), 2.4f);
    EXPECT_FLOAT_EQ(v1.z(), 3.6f);
}

TEST(Vector3MadTest, MadWithLargeScalar)
{
    Vector3<float> v1(1.0f, 2.0f, 3.0f);
    Vector3<float> v2(1e10f, 2e10f, 3e10f);
    v1.mad(v2, 1e-10f);
    EXPECT_FLOAT_EQ(v1.x(), 2.0f);
    EXPECT_FLOAT_EQ(v1.y(), 4.0f);
    EXPECT_FLOAT_EQ(v1.z(), 6.0f);
}

TEST(Vector3EqualTest, EqualVectors)
{
    Vector3<float> v1(1.0f, 2.0f, 3.0f);
    Vector3<float> v2(1.0f + 1e-6f, 2.0f + 1e-6f, 3.0f + 1e-6f);
    EXPECT_TRUE(v1.equal(v2));
}

TEST(Vector3EqualTest, NotEqualVectors)
{
    Vector3<float> v1(1.0f, 2.0f, 3.0f);
    Vector3<float> v2(1.1f, 2.1f, 3.1f);
    EXPECT_FALSE(v1.equal(v2));
}

TEST(Vector3AliasTest, Vec3fConstructsCorrectly)
{
    ksemath::vec3f v(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v.x(), 1.0f);
    EXPECT_FLOAT_EQ(v.y(), 2.0f);
    EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vector3AliasTest, Vec3dConstructsCorrectly)
{
    ksemath::vec3d v(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(v.x(), 1.0);
    EXPECT_DOUBLE_EQ(v.y(), 2.0);
    EXPECT_DOUBLE_EQ(v.z(), 3.0);
}

TEST(Vector3AliasTest, Vec3lConstructsCorrectly)
{
    ksemath::vec3l v(1.0L, 2.0L, 3.0L);
    EXPECT_EQ(v.x(), 1.0L);
    EXPECT_EQ(v.y(), 2.0L);
    EXPECT_EQ(v.z(), 3.0L);
}

TEST(Vector3MixedParamTest, AddIntAndFloatParams)
{
    ksemath::vec3f v(1, 2.5f, 3);
    v.add(3.5, 4, 0.5f);
    EXPECT_FLOAT_EQ(v.x(), 4.5f);
    EXPECT_FLOAT_EQ(v.y(), 6.5f);
    EXPECT_FLOAT_EQ(v.z(), 3.5f);
}

TEST(Vector3MixedParamTest, SubFloatAndDoubleParams)
{
    ksemath::vec3d v(10.0f, 20.0, 30.0);
    v.sub(2, 5.0f, 10.0);
    EXPECT_DOUBLE_EQ(v.x(), 8.0);
    EXPECT_DOUBLE_EQ(v.y(), 15.0);
    EXPECT_DOUBLE_EQ(v.z(), 20.0);
}

TEST(Vector3MixedParamTest, MulFloatAndIntParams)
{
    ksemath::vec3f v(2.0f, 3.0f, 4.0f);
    v.mul(2, 0.5, 3);
    EXPECT_FLOAT_EQ(v.x(), 4.0f);
    EXPECT_FLOAT_EQ(v.y(), 1.5f);
    EXPECT_FLOAT_EQ(v.z(), 12.0f);
}

TEST(Vector3MixedParamTest, DivDoubleAndFloatParams)
{
    ksemath::vec3d v(9.0, 12.0, 18.0);
    v.div(3.0f, 2, 6.0);
    EXPECT_DOUBLE_EQ(v.x(), 3.0);
    EXPECT_DOUBLE_EQ(v.y(), 6.0);
    EXPECT_DOUBLE_EQ(v.z(), 3.0);
}

TEST(Vector3MixedTemplateTest, AddDifferentTemplateTypes)
{
    ksemath::vec3f v1(1.0f, 2.0f, 3.0f);
    ksemath::vec3d v2(3.0, 4.0, 5.0);
    v1.add(v2.x(), v2.y(), v2.z());
    EXPECT_FLOAT_EQ(v1.x(), 4.0f);
    EXPECT_FLOAT_EQ(v1.y(), 6.0f);
    EXPECT_FLOAT_EQ(v1.z(), 8.0f);
}

TEST(Vector3MixedTemplateTest, SubDifferentTemplateTypes)
{
    ksemath::vec3d v1(5.5, 7.5, 9.5);
    ksemath::vec3f v2(1.5f, 2.5f, 3.5f);
    v1.sub(v2.x(), v2.y(), v2.z());
    EXPECT_DOUBLE_EQ(v1.x(), 4.0);
    EXPECT_DOUBLE_EQ(v1.y(), 5.0);
    EXPECT_DOUBLE_EQ(v1.z(), 6.0);
}

TEST(Vector3MixedTemplateTest, MulDifferentTemplateTypes)
{
    ksemath::vec3l v1(2.0L, 4.0L, 5.0L);
    ksemath::vec3f v2(1.5f, 0.5f, 2.0f);
    v1.mul(v2.x(), v2.y(), v2.z());
    EXPECT_EQ(v1.x(), 3.0L);
    EXPECT_EQ(v1.y(), 2.0L);
    EXPECT_EQ(v1.z(), 10.0L);
}

TEST(Vector3MixedTemplateTest, DivDifferentTemplateTypes)
{
    ksemath::vec3f v1(10.0f, 20.0f, 40.0f);
    ksemath::vec3d v2(2.0, 4.0, 5.0);
    v1.div(v2.x(), v2.y(), v2.z());
    EXPECT_FLOAT_EQ(v1.x(), 5.0f);
    EXPECT_FLOAT_EQ(v1.y(), 5.0f);
    EXPECT_FLOAT_EQ(v1.z(), 8.0f);
}
