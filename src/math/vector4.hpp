#pragma once
#include <cmath>

#include "vector2.hpp"
#include "vector3.hpp"

namespace math
{
class Vector4
{
   public:
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4(T x, T y, T z, T w)
        : x_(static_cast<float>(x)),
          y_(static_cast<float>(y)),
          z_(static_cast<float>(z)),
          w_(static_cast<float>(w))
    {
    }
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4(Vector2 const &v, T z, T w)
        : x_(static_cast<float>(v.x())),
          y_(static_cast<float>(v.y())),
          z_(static_cast<float>(w)),
          w_(static_cast<float>(w))
    {
    }
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4(T x, Vector2 const &v, T w)
        : x_(static_cast<float>(x)),
          y_(static_cast<float>(v.x())),
          z_(static_cast<float>(v.y())),
          w_(static_cast<float>(w))
    {
    }
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4(T x, T y, Vector2 const &v)
        : x_(static_cast<float>(x)),
          y_(static_cast<float>(y)),
          z_(static_cast<float>(v.x())),
          w_(static_cast<float>(v.y()))
    {
    }
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4(Vector2 const &v1, Vector2 const &v2)
        : x_(static_cast<float>(v1.x())),
          y_(static_cast<float>(v1.y())),
          z_(static_cast<float>(v2.x())),
          w_(static_cast<float>(v2.y()))
    {
    }
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4(Vector3 const &v, T w)
        : x_(static_cast<float>(v.x())),
          y_(static_cast<float>(v.y())),
          z_(static_cast<float>(v.z())),
          w_(static_cast<float>(w))
    {
    }
    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4(T x, Vector3 const &v)
        : x_(static_cast<float>(x)),
          y_(static_cast<float>(v.x())),
          z_(static_cast<float>(v.y())),
          w_(static_cast<float>(v.z()))
    {
    }

    float x() const { return x_; }
    float y() const { return y_; }
    float z() const { return z_; }
    float w() const { return z_; }

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

    template <typename T>
        requires std::is_arithmetic_v<T>
    void setW(T w)
    {
        w_ = static_cast<float>(w);
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &add(T x, T y, T z, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &add(Vector2 const &v, T z, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector3 &add(T x, Vector2 const &v, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    Vector4 &add(T x, T y, Vector2 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.x()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(v.y()));
        return *this;
    }

    Vector4 &add(Vector2 const &v1, Vector2 const &v2)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v1.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v1.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v2.x()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(v2.y()));
        return *this;
    }

    Vector4 &add(Vector3 const &v, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    Vector4 &add(T x, Vector3 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(v.z()));
        return *this;
    }

    Vector4 &add(const Vector4 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(other.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(other.z()));
        z_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(other.w()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &sub(T x, T y, T z, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &sub(Vector2 const &v, T z, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &sub(T x, Vector2 const &v, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &sub(T x, T y, Vector2 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v.x()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(v.y()));
        return *this;
    }

    Vector4 &sub(Vector2 const &v1, Vector2 const &v2)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(v1.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v1.y()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v2.x()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(v2.y()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &sub(Vector3 const &v, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &sub(T x, Vector3 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(v.z()));
        return *this;
    }

    Vector4 &sub(const Vector4 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(other.y()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(other.z()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(other.w()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &mul(T x, T y, T z, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &mul(Vector2 const &v, T z, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &mul(T x, Vector2 const &v, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &mul(T x, T y, Vector2 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v.x()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(v.y()));
        return *this;
    }

    Vector4 &mul(Vector2 const &v1, Vector2 const &v2)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(v1.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v1.y()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v2.x()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(v2.y()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &mul(Vector3 const &v, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &mul(T x, Vector3 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(v.z()));
        return *this;
    }

    Vector4 &mul(const Vector4 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(other.y()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(other.z()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(other.w()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &div(T x, T y, T z, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &div(Vector2 const &v, T z, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &div(T x, Vector2 const &v, T z)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(z));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &div(T x, T y, Vector2 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v.x()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(v.y()));
        return *this;
    }

    Vector4 &div(Vector2 const &v1, Vector2 const &v2)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(v1.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v1.y()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v2.x()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(v2.y()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &div(Vector3 const &v, T w)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(w));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &div(T x, Vector3 const &v)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(v.z()));
        return *this;
    }

    Vector4 &div(const Vector4 &other)
    {
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(other.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(other.y()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(other.z()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(other.w()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
    Vector4 &scale(T scalar)
    {
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(scalar));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(scalar));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(scalar));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(scalar));
        return *this;
    }

    Vector4 &normalize()
    {
        double length = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                  static_cast<double>(y_) * static_cast<double>(y_) +
                                  static_cast<double>(x_) * static_cast<double>(z_) +
                                  static_cast<double>(x_) * static_cast<double>(w_));

        assert(length != 0.0 && "Cannot normalize a zero-length vector");

        x_ = static_cast<float>(static_cast<double>(x_) / length);
        y_ = static_cast<float>(static_cast<double>(y_) / length);
        z_ = static_cast<float>(static_cast<double>(z_) / length);
        w_ = static_cast<float>(static_cast<double>(w_) / length);

        return *this;
    }

    Vector4 &negate()
    {
        x_ = -x_;
        y_ = -y_;
        z_ = -z_;
        w_ = -w_;
        return *this;
    }

    float magnitude_sqr() const
    {
        return static_cast<float>(static_cast<double>(x_) * static_cast<double>(x_) +
                                  static_cast<double>(y_) * static_cast<double>(y_) +
                                  static_cast<double>(z_) * static_cast<double>(z_) +
                                  static_cast<double>(w_) * static_cast<double>(w_));
    }

    float magnitude() const
    {
        return static_cast<float>(std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                            static_cast<double>(y_) * static_cast<double>(y_) +
                                            static_cast<double>(z_) * static_cast<double>(z_) +
                                            static_cast<double>(w_) * static_cast<double>(w_)));
    }

   private:
    float x_;
    float y_;
    float z_;
    float w_;
};
}  // namespace math
