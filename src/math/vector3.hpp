#pragma once
#include <cassert>
#include <cmath>
#include <type_traits>

#include "vector2.hpp"

namespace math
{
template <typename V>
class Vector3
{
   public:
    template <typename A, typename B, typename C>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C>)
    Vector3(A x, B y, C z)
        : x_(static_cast<V>(x)), y_(static_cast<V>(y)), z_(static_cast<V>(z))
    {
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3(Vector2 const &v, T z)
        : x_(static_cast<V>(v.x())), y_(static_cast<V>(v.y())), z_(static_cast<V>(z))
    {
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3(T x, Vector2 const &v)
        : x_(static_cast<V>(x)), y_(static_cast<V>(v.x())), z_(static_cast<V>(v.y()))
    {
    }

    float x() const { return x_; }
    float y() const { return y_; }
    float z() const { return z_; }

    template <typename T>
        requires std::is_arithmetic_v<T>
    void setX(T x)
    {
        x_ = static_cast<V>(x);
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    void setY(T y)
    {
        y_ = static_cast<V>(y);
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    void setZ(T z)
    {
        z_ = static_cast<V>(z);
    }

    Vector3 &add(const Vector3 &other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(other.y()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(other.z()));
        return *this;
    }

    template <typename A, typename B, typename C>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C>)
    Vector3 &add(A x, B y, C z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &add(Vector2 const &v, T z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &add(T x, Vector2 const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v.y()));
        return *this;
    }

    Vector3 &sub(const Vector3 &other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(other.y()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(other.z()));
        return *this;
    }

    template <typename A, typename B, typename C>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C>)
    Vector3 &sub(A x, B y, C z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &sub(Vector2 const &v, T z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &sub(T x, Vector2 const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v.y()));
        return *this;
    }

    Vector3 &mul(const Vector3 &other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(other.y()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(other.z()));
        return *this;
    }

    template <typename A, typename B, typename C>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C>)
    Vector3 &mul(A x, B y, C z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &mul(Vector2 const &v, T z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &mul(T x, Vector2 const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v.y()));
        return *this;
    }

    Vector3 &div(const Vector3 &other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(other.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(other.z()));
        return *this;
    }

    template <typename A, typename B, typename C>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C>)
    Vector3 &div(A x, B y, C z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &div(Vector2 const &v, T z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &div(T x, Vector2 const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v.y()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &scale(T scalar)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(scalar));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(scalar));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(scalar));
        return *this;
    }

    bool isValid() const { return std::isfinite(x_) && std::isfinite(y_) && std::isfinite(z_); }

    Vector3 &normalize()
    {
        const double length = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                  static_cast<double>(y_) * static_cast<double>(y_) +
                                  static_cast<double>(z_) * static_cast<double>(z_));
        assert(length > 0.0 && "Cannot normalize a zero-length vector");
        x_ = static_cast<V>(static_cast<double>(x_) / length);
        y_ = static_cast<V>(static_cast<double>(y_) / length);
        z_ = static_cast<V>(static_cast<double>(z_) / length);
        return *this;
    }

    Vector3 &negate()
    {
        x_ = -x_;
        y_ = -y_;
        z_ = -z_;
        return *this;
    }

    float magnitude_sqr() const
    {
        return static_cast<V>(static_cast<double>(x_) * static_cast<double>(x_) +
                                  static_cast<double>(y_) * static_cast<double>(y_) +
                                  static_cast<double>(z_) * static_cast<double>(z_));
    }

    float magnitude() const
    {
        return static_cast<V>(std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                            static_cast<double>(y_) * static_cast<double>(y_) +
                                            static_cast<double>(z_) * static_cast<double>(z_)));
    }

    float cos(const Vector3 &other) const
    {
        const double dot = static_cast<double>(x_) * static_cast<double>(other.x()) +
                     static_cast<double>(y_) * static_cast<double>(other.y()) +
                     static_cast<double>(z_) * static_cast<double>(other.z());

        const double mag1 = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                static_cast<double>(y_) * static_cast<double>(y_) +
                                static_cast<double>(z_) * static_cast<double>(z_));

        const double mag2 = std::sqrt(static_cast<double>(other.x()) * static_cast<double>(other.x()) +
                                static_cast<double>(other.y()) * static_cast<double>(other.y()) +
                                static_cast<double>(other.z()) * static_cast<double>(other.z()));

        assert(mag1 > 0.0 && mag2 > 0.0 && "Cannot compute angle with a zero-magnitude vector");

        double cosTheta = dot / (mag1 * mag2);

        return static_cast<V>(cosTheta);
    }

    float angle(const Vector3 &other) const
    {
        const double dot = static_cast<double>(x_) * static_cast<double>(other.x()) +
                     static_cast<double>(y_) * static_cast<double>(other.y()) +
                     static_cast<double>(z_) * static_cast<double>(other.z());

        const double mag1 = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                static_cast<double>(y_) * static_cast<double>(y_) +
                                static_cast<double>(z_) * static_cast<double>(z_));

        const double mag2 = std::sqrt(static_cast<double>(other.x()) * static_cast<double>(other.x()) +
                                static_cast<double>(other.y()) * static_cast<double>(other.y()) +
                                static_cast<double>(other.z()) * static_cast<double>(other.z()));

        assert(mag1 > 0.0 && mag2 > 0.0 && "Cannot compute angle with a zero-magnitude vector");

        const double cosTheta = dot / (mag1 * mag2);

        return static_cast<V>(std::acos(cosTheta));
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &mad(const Vector3 &other, T scalar)
    {
        x_ = static_cast<V>(static_cast<double>(x_) +
                                static_cast<double>(other.x()) * static_cast<double>(scalar));
        y_ = static_cast<V>(static_cast<double>(y_) +
                                static_cast<double>(other.y()) * static_cast<double>(scalar));
        z_ = static_cast<V>(static_cast<double>(z_) +
                                static_cast<double>(other.z()) * static_cast<double>(scalar));
        return *this;
    }

    bool equal(const Vector3 &other) const
    {
        constexpr double epsilon = 1e-5;
        return std::abs(static_cast<double>(x_) - static_cast<double>(other.x_)) < epsilon &&
               std::abs(static_cast<double>(y_) - static_cast<double>(other.y_)) < epsilon &&
               std::abs(static_cast<double>(z_) - static_cast<double>(other.z_)) < epsilon;
    }

    bool operator==(const Vector3 &other) const
    {
        constexpr double epsilon = 1e-5;
        return std::abs(static_cast<double>(x_) - static_cast<double>(other.x_)) < epsilon &&
               std::abs(static_cast<double>(y_) - static_cast<double>(other.y_)) < epsilon &&
               std::abs(static_cast<double>(z_) - static_cast<double>(other.z_)) < epsilon;
    }

    Vector3 &operator=(const Vector3 &other)
    {
        x_ = other.x_;
        y_ = other.y_;
        z_ = other.z_;
        return *this;
    }

   private:
    V x_, y_, z_;
};

using vec3f = Vector3<float>;
using vec3d = Vector3<double>;
using vec3l = Vector3<long double>;
}  // namespace math
