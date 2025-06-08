#pragma once
#include <cassert>
#include <cmath>

#include "vector2.hpp"

namespace math
{
class Vector3
{
   public:
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3(T x, T y, T z) : x_(static_cast<float>(x)), y_(static_cast<float>(y)), z_(static_cast<float>(z)) {}
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3(Vector2 const &v, T z) : x_(static_cast<float>(v.x())), y_(static_cast<float>(v.y())), z_(static_cast<float>(z)) {}
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3(T x, Vector2 const &v) : x_(static_cast<float>(x)), y_(static_cast<float>(v.x())), z_(static_cast<float>(v.y())) {}

    float x() const { return x_; }
    float y() const { return y_; }
    float z() const { return z_; }
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

    template <typename T>
        requires std::is_arithmetic_v<T>
    void setZ(T z)
    {
        z_ = static_cast<float>(z);
    }

    Vector3 &add(const Vector3 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(other.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(other.z()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &add(T x, T y, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &add(Vector2 const &v, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &add(T x, Vector2 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.y()));
        return *this;
    }

    Vector3 &sub(const Vector3 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(other.y()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(other.z()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &sub(T x, T y, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &sub(Vector2 const &v, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &sub(T x, Vector2 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.y()));
        return *this;
    }

    Vector3 &mul(const Vector3 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(other.y()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(other.z()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &mul(T x, T y, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &mul(Vector2 const &v, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &mul(T x, Vector2 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.y()));
        return *this;
    }

    Vector3 &div(const Vector3 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(other.y()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(other.z()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &div(T x, T y, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &div(Vector2 const &v, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &div(T x, Vector2 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.y()));
        return *this;
    }

   private:
    float x_;
    float y_;
    float z_;
};
}  // namespace math
