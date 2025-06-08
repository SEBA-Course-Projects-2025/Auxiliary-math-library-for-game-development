#pragma once
#include <cmath>

namespace math
{
class Vector2
{
   public:
    Vector2(float x, float y) : x_(x), y_(y) {}

    float x() const { return x_; }
    float y() const { return y_; }
    void setX(float x) { x_ = x; }
    void setY(float y) { y_ = y; }

    Vector2 &add(const Vector2 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(other.y()));
        return *this;
    }

    Vector2 &add(float x, float y)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        return *this;
    }

    Vector2 &sub(const Vector2 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(other.y()));
        return *this;
    }

    Vector2 &sub(float x, float y)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        return *this;
    }

    Vector2 &mul(const Vector2 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(other.y()));
        return *this;
    }

    Vector2 &mul(float x, float y)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        return *this;
    }

    Vector2 &div(const Vector2 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(other.y()));
        return *this;
    }

    Vector2 &div(float x, float y)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        return *this;
    }

    Vector2 scale(float scalar) const
    {
        return Vector2(static_cast<float>(static_cast<double>(x_) * scalar),
                       static_cast<float>(static_cast<double>(y_) * scalar));
    }

    Vector2 normalize() const
    {
        double length = std::sqrt(static_cast<double>(x_) * x_ + static_cast<double>(y_) * y_);
        if (length == 0.0)
            return Vector2(0.0f, 0.0f);
        return Vector2(static_cast<float>(x_ / length), static_cast<float>(y_ / length));
    }

    Vector2 negate() const { return Vector2(-x_, -y_); }

    float magnitude_sqr() const
    {
        return static_cast<float>(static_cast<double>(x_) * x_ + static_cast<double>(y_) * y_);
    }

    float magnitude() const { return std::sqrt(magnitude_sqr()); }

    float area(const Vector2 &other) const
    {
        return static_cast<float>(
            std::abs(static_cast<double>(x_) * other.y() - static_cast<double>(y_) * other.x()));
    }

    float dot(const Vector2 &other) const { return x_ * other.x_ + y_ * other.y_; }

    float angle(const Vector2 &other) const
    {
        float mag1 = magnitude();
        float mag2 = other.magnitude();

        if (mag1 == 0.0f || mag2 == 0.0f)
        {
            return 0.0f;
        }

        float cos_angle = dot(other) / (mag1 * mag2);

        if (cos_angle > 1.0f)
            cos_angle = 1.0f;
        if (cos_angle < -1.0f)
            cos_angle = -1.0f;

        return std::acos(cos_angle);
    }

    Vector2 mad(const Vector2 &other, float scalar) const
    {
        return Vector2(
            static_cast<float>(static_cast<double>(x_) + static_cast<double>(other.x_) * scalar),
            static_cast<float>(static_cast<double>(y_) + static_cast<double>(other.y_) * scalar));
    }

    bool equal(const Vector2 &other) const
    {
        constexpr float epsilon = 1e-5f;
        return (std::abs(static_cast<double>(x_) - other.x_) < epsilon) &&
               (std::abs(static_cast<double>(y_) - other.y_) < epsilon);
    }

    bool operator==(const Vector2 &other) const { return equal(other); }

    Vector2 &operator=(const Vector2 &other)
    {
        if (this != &other)
        {
            x_ = other.x_;
            y_ = other.y_;
        }
        return *this;
    }

   private:
    float x_;
    float y_;
};
}  // namespace math
