#pragma once
#include <cmath>

#include "vector2.hpp"
#include "vector3.hpp"

namespace ksemath
{
template <typename V>
class Vector4
{
   public:
    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4(A x, B y, C z, D w)
        : x_(static_cast<V>(x)), y_(static_cast<V>(y)), z_(static_cast<V>(z)), w_(static_cast<V>(w))
    {
    }

    template <arithmetic C, arithmetic D, arithmetic V2>
    Vector4(Vector2<V2> const &v, C z, D w) noexcept
        : x_(static_cast<V>(v.x())),
          y_(static_cast<V>(v.y())),
          z_(static_cast<V>(z)),
          w_(static_cast<V>(w))
    {
    }

    template <arithmetic A, arithmetic D, arithmetic V2>
    Vector4(A x, Vector2<V2> const &v, D w)
        : x_(static_cast<V>(x)),
          y_(static_cast<V>(v.x())),
          z_(static_cast<V>(v.y())),
          w_(static_cast<V>(w))
    {
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4(A x, B y, Vector2<V2> const &v)
        : x_(static_cast<V>(x)),
          y_(static_cast<V>(y)),
          z_(static_cast<V>(v.x())),
          w_(static_cast<V>(v.y()))
    {
    }

    template <arithmetic V21, arithmetic V22>
    Vector4(Vector2<V21> const &v1, Vector2<V22> const &v2)
        : x_(static_cast<V>(v1.x())),
          y_(static_cast<V>(v1.y())),
          z_(static_cast<V>(v2.x())),
          w_(static_cast<V>(v2.y()))
    {
    }

    template <arithmetic D, arithmetic V3>
    Vector4(Vector3<V3> const &v, D w)
        : x_(static_cast<V>(v.x())),
          y_(static_cast<V>(v.y())),
          z_(static_cast<V>(v.z())),
          w_(static_cast<V>(w))
    {
    }

    template <arithmetic A, arithmetic V3>
    Vector4(A x, Vector3<V3> const &v)
        : x_(static_cast<V>(x)),
          y_(static_cast<V>(v.x())),
          z_(static_cast<V>(v.y())),
          w_(static_cast<V>(v.z()))
    {
    }

    float x() const { return x_; }
    float y() const { return y_; }
    float z() const { return z_; }
    float w() const { return w_; }

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

    template <arithmetic T>
    void setZ(T z)
    {
        z_ = static_cast<V>(z);
    }

    template <arithmetic T>
    void setW(T w)
    {
        w_ = static_cast<V>(w);
    }

    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4 &add(A x, B y, C z, D w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &add(Vector2<V2> const &v, A z, B w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &add(A x, Vector2<V2> const &v, B w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &add(A x, B y, Vector2<V2> const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v.x()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(v.y()));
        return *this;
    }

    template <arithmetic V21, arithmetic V22>
    Vector4 &add(Vector2<V21> const &v1, Vector2<V22> const &v2)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(v1.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v1.y()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v2.x()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(v2.y()));
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &add(Vector3<V3> const &v, A w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v.z()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &add(A x, Vector3<V3> const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(v.z()));
        return *this;
    }

    Vector4 &add(const Vector4 &other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(other.y()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(other.z()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(other.w()));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4 &sub(A x, B y, C z, D w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &sub(Vector2<V2> const &v, A z, B w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &sub(A x, Vector2<V2> const &v, B z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(z));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &sub(A x, B y, Vector2<V2> const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v.x()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(v.y()));
        return *this;
    }

    template <arithmetic V21, arithmetic V22>
    Vector4 &sub(Vector2<V21> const &v1, Vector2<V22> const &v2)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(v1.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v1.y()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v2.x()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(v2.y()));
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &sub(Vector3<V3> const &v, A w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v.z()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &sub(A x, Vector3<V3> const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(v.z()));
        return *this;
    }

    Vector4 &sub(const Vector4 &other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(other.y()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(other.z()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(other.w()));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4 &mul(A x, B y, C z, D w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &mul(Vector2<V2> const &v, A z, B w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &mul(A x, Vector2<V2> const &v, B z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(z));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &mul(A x, B y, Vector2<V2> const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v.x()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(v.y()));
        return *this;
    }

    template <arithmetic V21, arithmetic V22>
    Vector4 &mul(Vector2<V21> const &v1, Vector2<V22> const &v2)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(v1.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v1.y()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v2.x()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(v2.y()));
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &mul(Vector3<V3> const &v, A w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v.z()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &mul(A x, Vector3<V3> const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(v.z()));
        return *this;
    }

    Vector4 &mul(const Vector4 &other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(other.y()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(other.z()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(other.w()));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4 &div(A x, B y, C z, D w)
    {
        assert(x != 0 && "Division by zero in x");
        assert(y != 0 && "Division by zero in y");
        assert(z != 0 && "Division by zero in z");
        assert(w != 0 && "Division by zero in w");

        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &div(Vector2<V2> const &v, A z, B w)
    {
        assert(v.x() != 0 && "Division by zero in x (Vector2)");
        assert(v.y() != 0 && "Division by zero in y (Vector2)");
        assert(z != 0 && "Division by zero in z");
        assert(w != 0 && "Division by zero in w");

        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &div(A x, Vector2<V2> const &v, B z)
    {
        assert(x != 0 && "Division by zero in x");
        assert(v.x() != 0 && "Division by zero in y (Vector2)");
        assert(v.y() != 0 && "Division by zero in z (Vector2)");
        assert(z != 0 && "Division by zero in w");

        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(z));
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &div(A x, B y, Vector2<V2> const &v)
    {
        assert(x != 0 && "Division by zero in x");
        assert(y != 0 && "Division by zero in y");
        assert(v.x() != 0 && "Division by zero in z (Vector2)");
        assert(v.y() != 0 && "Division by zero in w (Vector2)");

        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v.x()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(v.y()));
        return *this;
    }

    template <arithmetic V21, arithmetic V22>
    Vector4 &div(Vector2<V21> const &v1, Vector2<V22> const &v2)
    {
        assert(v1.x() != 0 && "Division by zero in x (Vector2 v1)");
        assert(v1.y() != 0 && "Division by zero in y (Vector2 v1)");
        assert(v2.x() != 0 && "Division by zero in z (Vector2 v2)");
        assert(v2.y() != 0 && "Division by zero in w (Vector2 v2)");

        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(v1.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v1.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v2.x()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(v2.y()));
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &div(Vector3<V3> const &v, A w)
    {
        assert(v.x() != 0 && "Division by zero in x (Vector3)");
        assert(v.y() != 0 && "Division by zero in y (Vector3)");
        assert(v.z() != 0 && "Division by zero in z (Vector3)");
        assert(w != 0 && "Division by zero in w");

        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v.z()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(w));
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &div(A x, Vector3<V3> const &v)
    {
        assert(x != 0 && "Division by zero in x");
        assert(v.x() != 0 && "Division by zero in y (Vector3)");
        assert(v.y() != 0 && "Division by zero in z (Vector3)");
        assert(v.z() != 0 && "Division by zero in w (Vector3)");

        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(v.z()));
        return *this;
    }

    Vector4 &div(const Vector4 &other)
    {
        assert(other.x() != 0 && "Division by zero in x");
        assert(other.y() != 0 && "Division by zero in y");
        assert(other.z() != 0 && "Division by zero in z");
        assert(other.w() != 0 && "Division by zero in w");

        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(other.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(other.z()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(other.w()));
        return *this;
    }

    template <arithmetic T>
    Vector4 &scale(T scalar)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(scalar));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(scalar));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(scalar));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(scalar));
        return *this;
    }

    Vector4 &normalize()
    {
        const double length = std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                        static_cast<double>(y_) * static_cast<double>(y_) +
                                        static_cast<double>(z_) * static_cast<double>(z_) +
                                        static_cast<double>(w_) * static_cast<double>(w_));

        assert(length > 0.0 && "Cannot normalize a zero-length vector");

        x_ = static_cast<V>(static_cast<double>(x_) / length);
        y_ = static_cast<V>(static_cast<double>(y_) / length);
        z_ = static_cast<V>(static_cast<double>(z_) / length);
        w_ = static_cast<V>(static_cast<double>(w_) / length);

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
        return static_cast<V>(static_cast<double>(x_) * static_cast<double>(x_) +
                              static_cast<double>(y_) * static_cast<double>(y_) +
                              static_cast<double>(z_) * static_cast<double>(z_) +
                              static_cast<double>(w_) * static_cast<double>(w_));
    }

    float magnitude() const
    {
        return static_cast<V>(std::sqrt(static_cast<double>(x_) * static_cast<double>(x_) +
                                        static_cast<double>(y_) * static_cast<double>(y_) +
                                        static_cast<double>(z_) * static_cast<double>(z_) +
                                        static_cast<double>(w_) * static_cast<double>(w_)));
    }

    float dot(const Vector4 &other) const
    {
        return static_cast<V>(static_cast<double>(x_) * static_cast<double>(other.x()) +
                              static_cast<double>(y_) * static_cast<double>(other.y()) +
                              static_cast<double>(z_) * static_cast<double>(other.z()) +
                              static_cast<double>(w_) * static_cast<double>(other.w()));
    }

    float cos(const Vector4 &other) const
    {
        const double dotProduct = static_cast<double>(x_) * static_cast<double>(other.x()) +
                                  static_cast<double>(y_) * static_cast<double>(other.y()) +
                                  static_cast<double>(z_) * static_cast<double>(other.z()) +
                                  static_cast<double>(w_) * static_cast<double>(other.w());

        const double mag1 = std::sqrt(static_cast<double>(x_) * x_ + static_cast<double>(y_) * y_ +
                                      static_cast<double>(z_) * z_ + static_cast<double>(w_) * w_);

        const double mag2 = std::sqrt(static_cast<double>(other.x()) * other.x() +
                                      static_cast<double>(other.y()) * other.y() +
                                      static_cast<double>(other.z()) * other.z() +
                                      static_cast<double>(other.w()) * other.w());

        assert(mag1 > 0.0 && mag2 > 0.0 && "Cannot compute angle with a zero-magnitude vector");

        const double cosTheta = dotProduct / (mag1 * mag2);
        return static_cast<V>(cosTheta);
    }

    float angle(const Vector4 &other) const
    {
        const double dotProduct = static_cast<double>(x_) * static_cast<double>(other.x()) +
                                  static_cast<double>(y_) * static_cast<double>(other.y()) +
                                  static_cast<double>(z_) * static_cast<double>(other.z()) +
                                  static_cast<double>(w_) * static_cast<double>(other.w());

        const double mag1 = std::sqrt(static_cast<double>(x_) * x_ + static_cast<double>(y_) * y_ +
                                      static_cast<double>(z_) * z_ + static_cast<double>(w_) * w_);

        const double mag2 = std::sqrt(static_cast<double>(other.x()) * other.x() +
                                      static_cast<double>(other.y()) * other.y() +
                                      static_cast<double>(other.z()) * other.z() +
                                      static_cast<double>(other.w()) * other.w());

        assert(mag1 > 0.0 && mag2 > 0.0 && "Cannot compute angle with a zero-magnitude vector");

        const double cosTheta = dotProduct / (mag1 * mag2);
        return static_cast<V>(std::acos(cosTheta));
    }

    template <arithmetic T>
    Vector4 &mad(const Vector4 &other, T scalar)
    {
        x_ = static_cast<V>(static_cast<double>(x_) +
                            static_cast<double>(other.x()) * static_cast<double>(scalar));
        y_ = static_cast<V>(static_cast<double>(y_) +
                            static_cast<double>(other.y()) * static_cast<double>(scalar));
        z_ = static_cast<V>(static_cast<double>(z_) +
                            static_cast<double>(other.z()) * static_cast<double>(scalar));
        w_ = static_cast<V>(static_cast<double>(w_) +
                            static_cast<double>(other.w()) * static_cast<double>(scalar));
        return *this;
    }

    bool equal(const Vector4 &other) const
    {
        constexpr double epsilon = 1e-5f;
        return std::abs(static_cast<double>(x_) - static_cast<double>(other.x_)) < epsilon &&
               std::abs(static_cast<double>(y_) - static_cast<double>(other.y_)) < epsilon &&
               std::abs(static_cast<double>(z_) - static_cast<double>(other.z_)) < epsilon &&
               std::abs(static_cast<double>(w_) - static_cast<double>(other.w_)) < epsilon;
    }

    bool operator==(const Vector4 &other) const noexcept
    {
        constexpr double epsilon = 1e-5f;
        return std::abs(static_cast<double>(x_) - static_cast<double>(other.x_)) < epsilon &&
               std::abs(static_cast<double>(y_) - static_cast<double>(other.y_)) < epsilon &&
               std::abs(static_cast<double>(z_) - static_cast<double>(other.z_)) < epsilon &&
               std::abs(static_cast<double>(w_) - static_cast<double>(other.w_)) < epsilon;
    }

    Vector4 &operator=(const Vector4 &other) noexcept
    {
        x_ = other.x_;
        y_ = other.y_;
        z_ = other.z_;
        w_ = other.w_;

        return *this;
    }

   private:
    V x_;
    V y_;
    V z_;
    V w_;
};

using vec4f = Vector4<float>;
using vec4d = Vector4<double>;
using vec4l = Vector4<long double>;
}  // namespace ksemath
