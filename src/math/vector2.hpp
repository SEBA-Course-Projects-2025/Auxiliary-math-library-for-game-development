#pragma once

namespace math {
class Vector2 {
public:
    Vector2() : x_(0.0f), y_(0.0f) {}
    Vector2(float x, float y) : x_(x), y_(y) {}

    float x() const;
    float y() const;
    void setX(float x);
    void setY(float y);

    Vector2 add(const Vector2 &other) const;
    Vector2 sub(const Vector2 &other) const;
    Vector2 mul(const Vector2 &other) const;
    Vector2 div(const Vector2 &other) const;

    Vector2 scale(float scalar) const;
    Vector2 normalize() const;

    float magnitude() const;
    float magnitude_sqr() const;
    float area(const Vector2 &other) const;
    float angle(const Vector2 &other) const;
    float dot(const Vector2 &other) const;

    Vector2 mad(const Vector2 &other, float scalar) const;

    bool equal(const Vector2 &other) const;
    bool operator==(const Vector2& other) const;

private:
    float x_;
    float y_;
};
}
