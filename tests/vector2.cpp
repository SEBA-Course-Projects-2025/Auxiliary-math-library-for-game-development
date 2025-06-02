#include <gtest/gtest.h>
#include "src/math/vector2.hpp"

using math::Vector2;

TEST(Vector2Test, Add) {
    Vector2 v1(1.5f, 2.5f);
    Vector2 v2(3.0f, 4.0f);
    Vector2 result = v1.add(v2);
    EXPECT_FLOAT_EQ(result.x(), 4.5f);
    EXPECT_FLOAT_EQ(result.y(), 6.5f);
}

TEST(Vector2Test, Sub) {
    Vector2 v1(5.0f, 7.0f);
    Vector2 v2(2.0f, 3.0f);
    Vector2 result = v1.sub(v2);
    EXPECT_FLOAT_EQ(result.x(), 3.0f);
    EXPECT_FLOAT_EQ(result.y(), 4.0f);
}

TEST(Vector2Test, Mul) {
    Vector2 v1(2.0f, 3.0f);
    Vector2 v2(4.0f, 5.0f);
    Vector2 result = v1.mul(v2);
    EXPECT_FLOAT_EQ(result.x(), 8.0f);
    EXPECT_FLOAT_EQ(result.y(), 15.0f);
}

TEST(Vector2Test, Div) {
    Vector2 v1(8.0f, 9.0f);
    Vector2 v2(2.0f, 3.0f);
    Vector2 result = v1.div(v2);
    EXPECT_FLOAT_EQ(result.x(), 4.0f);
    EXPECT_FLOAT_EQ(result.y(), 3.0f);
}

TEST(Vector2Test, DivByZero) {
    Vector2 v1(1.0f, 1.0f);
    Vector2 v2(0.0f, 1.0f);
    Vector2 result = v1.div(v2);
    EXPECT_TRUE(std::isinf(result.x()) || std::isnan(result.x()));
    EXPECT_FLOAT_EQ(result.y(), 1.0f);
}
