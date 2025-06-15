#pragma once
#include <cassert>
#include <cmath>
#include <type_traits>

namespace math
{
template <typename Ar>
concept arithmetic = std::is_arithmetic_v<Ar>;

template <typename V>
class Vector2
{
   public:
    template <arithmetic A, arithmetic B>
    Vector2(A x, B y) noexcept : x_(static_cast<V>(x)), y_(static_cast<V>(y))
    {
    }

    float x() const { return x_; }
    float y() const { return y_; }

    template <arithmetic T>
    void setX(T x)
    {
        x_ = static_cast<V>(x);
    }

    template <arithmetic T>
    void setY(T y)
    {
        y_ = static_cast<V>(y);
    }

    bool isValid() const { return std::isfinite(x_) && std::isfinite(y_); }

    Vector2& add(const Vector2& other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(other.y()));
        return *this;
    }

    template <arithmetic A, arithmetic B>
    Vector2& add(A x, B y)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(y));
        return *this;
    }

    Vector2& sub(const Vector2& other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(other.y()));
        return *this;
    }

    template <arithmetic A, arithmetic B>
    Vector2& sub(A x, B y)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(y));
        return *this;
    }

    Vector2& mul(const Vector2& other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(other.y()));
        return *this;
    }

    template <arithmetic A, arithmetic B>
    Vector2& mul(A x, B y)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(y));
        return *this;
    }

    Vector2& div(const Vector2& other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(other.y()));
        return *this;
    }

    template <arithmetic A, arithmetic B>
    Vector2& div(A x, B y)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(y));
        return *this;
    }

    template <arithmetic T>
    Vector2& scale(T scalar)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(scalar));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(scalar));
        return *this;
    }

    Vector2& normalize()
    {
        const double length = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                  static_cast<double>(y_) * static_cast<double>(y_));

        assert(length > 0.0 && "Cannot normalize a zero-length vector");

        x_ = static_cast<V>(static_cast<double>(x_) / length);
        y_ = static_cast<V>(static_cast<double>(y_) / length);

        return *this;
    }

    Vector2& negate()
    {
        x_ = -x_;
        y_ = -y_;
        return *this;
    }

    float magnitude_sqr() const
    {
        return static_cast<V>(static_cast<double>(x_) * static_cast<double>(x_) +
                                  static_cast<double>(y_) * static_cast<double>(y_));
    }

    float magnitude() const
    {
        return static_cast<V>(std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                            static_cast<double>(y_) * static_cast<double>(y_)));
    }

    float area(const Vector2& other) const
    {
        return static_cast<V>(
            std::abs(static_cast<double>(x_) * static_cast<double>(other.y()) -
                     static_cast<double>(y_) * static_cast<double>(other.x())));
    }

    float dot(const Vector2& other) const
    {
        return static_cast<V>(static_cast<double>(x_) * static_cast<double>(other.x()) +
                                  static_cast<double>(y_) * static_cast<double>(other.y()));
    }

    float cos(const Vector2& other) const
    {
        const double dot = static_cast<double>(x_) * static_cast<double>(other.x()) +
                     static_cast<double>(y_) * static_cast<double>(other.y());
        const double mag1 = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                static_cast<double>(y_) * static_cast<double>(y_));
        const double mag2 = std::sqrt(static_cast<double>(other.x()) * static_cast<double>(other.x()) +
                                static_cast<double>(other.y()) * static_cast<double>(other.y()));

        assert(mag1 > 0.0 && mag2 > 0.0 && "Cannot compute angle with a zero-magnitude vector");

        return static_cast<V>(dot / (mag1 * mag2));
    }

    float angle(const Vector2& other) const
    {
        const double dot = static_cast<double>(x_) * static_cast<double>(other.x()) +
                     static_cast<double>(y_) * static_cast<double>(other.y());
        const double mag1 = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                static_cast<double>(y_) * static_cast<double>(y_));
        const double mag2 = std::sqrt(static_cast<double>(other.x()) * static_cast<double>(other.x()) +
                                static_cast<double>(other.y()) * static_cast<double>(other.y()));

        assert(mag1 > 0.0 && mag2 > 0.0 && "Cannot compute angle with a zero-magnitude vector");

        return static_cast<V>(std::acos(dot / (mag1 * mag2)));
    }

    template <arithmetic T>
    Vector2& mad(const Vector2& other, T scalar)
    {
        x_ = static_cast<V>(static_cast<double>(x_) +
                                static_cast<double>(other.x()) * static_cast<double>(scalar));
        y_ = static_cast<V>(static_cast<double>(y_) +
                                static_cast<double>(other.y()) * static_cast<double>(scalar));
        return *this;
    }

    bool equal(const Vector2& other) const
    {
        constexpr double epsilon = 1e-5f;
        return std::abs(static_cast<double>(x_) - static_cast<double>(other.x_)) < epsilon &&
               std::abs(static_cast<double>(y_) - static_cast<double>(other.y_)) < epsilon;
    }

    bool operator==(const Vector2& other) const noexcept { return equal(other); }

    Vector2& operator=(const Vector2& other) noexcept
    {
        x_ = other.x_;
        y_ = other.y_;
        return *this;
    }

   private:
    float x_;
    float y_;
};

using vec2f = Vector2<float>;
using vec2d = Vector2<double>;
using vec2l = Vector2<long double>;
}  // namespace math
