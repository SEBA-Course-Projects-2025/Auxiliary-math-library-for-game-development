#pragma once
#include <cassert>
#include <cmath>

namespace math
{
class Vector2
{
   public:
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector2(T x, T y) : x_(static_cast<float>(x)), y_(static_cast<float>(y))
    {
    }

    float x() const { return x_; }
    float y() const { return y_; }

    template <typename T>
        requires std::is_arithmetic_v<T>
    void setX(T x)
    {
        x_ = static_cast<float>(x);
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    void setY(T y)
    {
        y_ = static_cast<float>(y);
    }

    bool isValid() const { return std::isfinite(x_) && std::isfinite(y_); }

    Vector2 &add(const Vector2 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(other.y()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector2 &add(T x, T y)
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

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector2 &sub(T x, T y)
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

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector2 &mul(T x, T y)
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

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector2 &div(T x, T y)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector2 &scale(T scalar)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(scalar));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(scalar));
        return *this;
    }

    Vector2 &normalize()
    {
        double length = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                  static_cast<double>(y_) * static_cast<double>(y_));

        assert(length != 0.0 && "Cannot normalize a zero-length vector");

        x_ = static_cast<float>(static_cast<double>(x_) / length);
        y_ = static_cast<float>(static_cast<double>(y_) / length);

        return *this;
    }

    Vector2 &negate()
    {
        x_ = -x_;
        y_ = -y_;
        return *this;
    }

    float magnitude_sqr() const
    {
        return static_cast<float>(static_cast<double>(x_) * static_cast<double>(x_) +
                                  static_cast<double>(y_) * static_cast<double>(y_));
    }

    float magnitude() const
    {
        return static_cast<float>(std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                            static_cast<double>(y_) * static_cast<double>(y_)));
    }

    float area(const Vector2 &other) const
    {
        return static_cast<float>(
            std::abs(static_cast<double>(x_) * static_cast<double>(other.y()) -
                     static_cast<double>(y_) * static_cast<double>(other.x())));
    }

    float dot(const Vector2 &other) const
    {
        return static_cast<float>(static_cast<double>(x_) * static_cast<double>(other.x()) +
                                  static_cast<double>(y_) * static_cast<double>(other.y()));
    }

    float cos(const Vector2 &other) const
    {
        double dot = static_cast<double>(x_) * static_cast<double>(other.x()) +
                     static_cast<double>(y_) * static_cast<double>(other.y());
        double mag1 = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                static_cast<double>(y_) * static_cast<double>(y_));
        double mag2 = std::sqrt(static_cast<double>(other.x()) * static_cast<double>(other.x()) +
                                static_cast<double>(other.y()) * static_cast<double>(other.y()));

        assert(mag1 != 0.0 && mag2 != 0.0 && "Cannot compute angle with a zero-magnitude vector");

        double cosTheta = dot / (mag1 * mag2);

        return static_cast<float>(cosTheta);
    }

    float angle(const Vector2 &other) const
    {
        double dot = static_cast<double>(x_) * static_cast<double>(other.x()) +
                     static_cast<double>(y_) * static_cast<double>(other.y());
        double mag1 = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                static_cast<double>(y_) * static_cast<double>(y_));
        double mag2 = std::sqrt(static_cast<double>(other.x()) * static_cast<double>(other.x()) +
                                static_cast<double>(other.y()) * static_cast<double>(other.y()));

        assert(mag1 != 0.0 && mag2 != 0.0 && "Cannot compute angle with a zero-magnitude vector");

        double cosTheta = dot / (mag1 * mag2);

        return static_cast<float>(std::acos(cosTheta));
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector2 &mad(const Vector2 &other, T scalar)
    {
        x_ = static_cast<float>(static_cast<double>(x_) +
                                static_cast<double>(other.x()) * static_cast<double>(scalar));
        y_ = static_cast<float>(static_cast<double>(y_) +
                                static_cast<double>(other.y()) * static_cast<double>(scalar));
        return *this;
    }

    bool equal(const Vector2 &other) const
    {
        constexpr double epsilon = 1e-5f;
        return std::abs(static_cast<double>(x_) - static_cast<double>(other.x_)) < epsilon &&
               std::abs(static_cast<double>(y_) - static_cast<double>(other.y_)) < epsilon;
    }

    bool operator==(const Vector2 &other) const
    {
        constexpr double epsilon = 1e-5f;
        return std::abs(static_cast<double>(x_) - static_cast<double>(other.x_)) < epsilon &&
               std::abs(static_cast<double>(y_) - static_cast<double>(other.y_)) < epsilon;
    }

    Vector2 &operator=(const Vector2 &other)
    {
        x_ = other.x_;
        y_ = other.y_;

        return *this;
    }

   private:
    float x_;
    float y_;
};
}  // namespace math
