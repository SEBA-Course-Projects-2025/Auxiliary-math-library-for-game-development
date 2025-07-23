#pragma once
#include <cmath>
#include <stdexcept>

#include "vector2.hpp"
#include "vector3.hpp"
#define USE_SSE
// #define USE_NEON

#ifdef USE_SSE
#include <immintrin.h>
#elif defined(USE_NEON)
#include <arm_neon.h>
#endif

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

    // Add these to the public section of the Vector4<V> class
    V &operator[](size_t index)
    {
        switch (index)
        {
            case 0:
                return x_;
            case 1:
                return y_;
            case 2:
                return z_;
            case 3:
                return w_;
            default:
                throw std::out_of_range("Vector4 index out of range");
        }
    }

    const V &operator[](size_t index) const
    {
        switch (index)
        {
            case 0:
                return x_;
            case 1:
                return y_;
            case 2:
                return z_;
            case 3:
                return w_;
            default:
                throw std::out_of_range("Vector4 index out of range");
        }
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

template <>
class Vector4<float>
{
   public:
    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4(A x, B y, C z, D w)
#ifdef USE_SSE
        : data_(_mm_set_ps(static_cast<float>(w), static_cast<float>(z), static_cast<float>(y),
                           static_cast<float>(x)))
#elif defined(USE_NEON)
        : data_(load_neon_vec(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z),
                              static_cast<float>(w)))
#else
        : x_(static_cast<float>(x)),
          y_(static_cast<float>(y)),
          z_(static_cast<float>(z)),
          w_(static_cast<float>(w))
#endif
    {
    }

    template <arithmetic C, arithmetic D, arithmetic V2>
    Vector4(Vector2<V2> const &v, C z, D w) noexcept
#ifdef USE_SSE
        : data_(_mm_set_ps(static_cast<float>(w), static_cast<float>(z), static_cast<float>(v.y()),
                           static_cast<float>(v.x())))
#elif defined(USE_NEON)
        : data_(load_neon_vec(static_cast<float>(v.x()), static_cast<float>(v.y()),
                              static_cast<float>(z), static_cast<float>(w)))
#else
        : x_(static_cast<float>(v.x())),
          y_(static_cast<float>(v.y())),
          z_(static_cast<float>(z)),
          w_(static_cast<float>(w))
#endif
    {
    }

    template <arithmetic A, arithmetic D, arithmetic V2>
    Vector4(A x, Vector2<V2> const &v, D w)
#ifdef USE_SSE
        : data_(_mm_set_ps(static_cast<float>(w), static_cast<float>(v.y()),
                           static_cast<float>(v.x()), static_cast<float>(x)))
#elif defined(USE_NEON)
        : data_(load_neon_vec(static_cast<float>(x), static_cast<float>(v.x()),
                              static_cast<float>(v.y()), static_cast<float>(w)))
#else
        : x_(static_cast<float>(x)),
          y_(static_cast<float>(v.x())),
          z_(static_cast<float>(v.y())),
          w_(static_cast<float>(w))
#endif
    {
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4(A x, B y, Vector2<V2> const &v)
#ifdef USE_SSE
        : data_(_mm_set_ps(static_cast<float>(v.y()), static_cast<float>(v.x()),
                           static_cast<float>(y), static_cast<float>(x)))
#elif defined(USE_NEON)
        : data_(load_neon_vec(static_cast<float>(x), static_cast<float>(y),
                              static_cast<float>(v.x()), static_cast<float>(v.y())))
#else
        : x_(static_cast<float>(x)),
          y_(static_cast<float>(y)),
          z_(static_cast<float>(v.x())),
          w_(static_cast<float>(v.y()))
#endif
    {
    }

    template <arithmetic V21, arithmetic V22>
    Vector4(Vector2<V21> const &v1, Vector2<V22> const &v2)
#ifdef USE_SSE
        : data_(_mm_set_ps(static_cast<float>(v2.y()), static_cast<float>(v2.x()),
                           static_cast<float>(v1.y()), static_cast<float>(v1.x())))
#elif defined(USE_NEON)
        : data_(load_neon_vec(static_cast<float>(v1.x()), static_cast<float>(v1.y()),
                              static_cast<float>(v2.x()), static_cast<float>(v2.y())))
#else
        : x_(static_cast<float>(v1.x())),
          y_(static_cast<float>(v1.y())),
          z_(static_cast<float>(v2.x())),
          w_(static_cast<float>(v2.y()))
#endif
    {
    }

    template <arithmetic D, arithmetic V3>
    Vector4(Vector3<V3> const &v, D w)
#ifdef USE_SSE
        : data_(_mm_set_ps(static_cast<float>(w), static_cast<float>(v.z()),
                           static_cast<float>(v.y()), static_cast<float>(v.x())))
#elif defined(USE_NEON)
        : data_(load_neon_vec(static_cast<float>(v.x()), static_cast<float>(v.y()),
                              static_cast<float>(v.z()), static_cast<float>(w)))
#else
        : x_(static_cast<float>(v.x())),
          y_(static_cast<float>(v.y())),
          z_(static_cast<float>(v.z())),
          w_(static_cast<float>(w))
#endif
    {
    }

    template <arithmetic A, arithmetic V3>
    Vector4(A x, Vector3<V3> const &v)
#ifdef USE_SSE
        : data_(_mm_set_ps(static_cast<float>(v.z()), static_cast<float>(v.y()),
                           static_cast<float>(v.x()), static_cast<float>(x)))
#elif defined(USE_NEON)
        : data_(load_neon_vec(static_cast<float>(x), static_cast<float>(v.x()),
                              static_cast<float>(v.y()), static_cast<float>(v.z())))
#else
        : x_(static_cast<float>(x)),
          y_(static_cast<float>(v.x())),
          z_(static_cast<float>(v.y())),
          w_(static_cast<float>(v.z()))
#endif
    {
    }

    float x() const
    {
#ifdef USE_SSE
        return _mm_cvtss_f32(data_);
#elif defined(USE_NEON)
        return vgetq_lane_f32(data_, 0);
#else
        return x_;
#endif
    }

    float y() const
    {
#ifdef USE_SSE
        __m128 y_vec = _mm_shuffle_ps(data_, data_, _MM_SHUFFLE(1, 1, 1, 1));
        return _mm_cvtss_f32(y_vec);
#elif defined(USE_NEON)
        return vgetq_lane_f32(data_, 1);
#else
        return y_;
#endif
    }

    float z() const
    {
#ifdef USE_SSE
        __m128 z_vec = _mm_shuffle_ps(data_, data_, _MM_SHUFFLE(2, 2, 2, 2));
        return _mm_cvtss_f32(z_vec);
#elif defined(USE_NEON)
        return vgetq_lane_f32(data_, 2);
#else
        return z_;
#endif
    }

    float w() const
    {
#ifdef USE_SSE
        __m128 w_vec = _mm_shuffle_ps(data_, data_, _MM_SHUFFLE(3, 3, 3, 3));
        return _mm_cvtss_f32(w_vec);
#elif defined(USE_NEON)
        return vgetq_lane_f32(data_, 3);
#else
        return w_;
#endif
    }

    template <arithmetic T>
    void setX(T x)
    {
#ifdef USE_SSE
        __m128 new_x = _mm_set_ss(static_cast<float>(x));
        data_ = _mm_move_ss(data_, new_x);
#elif defined(USE_NEON)
        data_ = vsetq_lane_f32(static_cast<float>(x), data_, 0);
#else
        x_ = static_cast<float>(x);
#endif
    }

    template <arithmetic T>
    void setY(T y)
    {
#ifdef USE_SSE
        __m128 new_y = _mm_set1_ps(static_cast<float>(y));
        __m128 mask = _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0xFFFFFFFF, 0, 0xFFFFFFFF));
        data_ = _mm_or_ps(_mm_and_ps(mask, data_), _mm_andnot_ps(mask, new_y));
#elif defined(USE_NEON)
        data_ = vsetq_lane_f32(static_cast<float>(y), data_, 1);
#else
        y_ = static_cast<float>(y);
#endif
    }

    template <arithmetic T>
    void setZ(T z)
    {
#ifdef USE_SSE
        __m128 new_z = _mm_set1_ps(static_cast<float>(z));
        __m128 mask = _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0, 0xFFFFFFFF, 0xFFFFFFFF));
        data_ = _mm_or_ps(_mm_and_ps(mask, data_), _mm_andnot_ps(mask, new_z));
#elif defined(USE_NEON)
        data_ = vsetq_lane_f32(static_cast<float>(z), data_, 2);
#else
        z_ = static_cast<float>(z);
#endif
    }

    template <arithmetic T>
    void setW(T w)
    {
#ifdef USE_SSE
        __m128 new_w = _mm_set1_ps(static_cast<float>(w));
        __m128 mask = _mm_castsi128_ps(_mm_set_epi32(0, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF));
        data_ = _mm_or_ps(_mm_and_ps(mask, data_), _mm_andnot_ps(mask, new_w));
#elif defined(USE_NEON)
        data_ = vsetq_lane_f32(static_cast<float>(w), data_, 3);
#else
        w_ = static_cast<float>(w);
#endif
    }

    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4 &add(A x, B y, C z, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(z), static_cast<float>(y),
                                static_cast<float>(x));
        data_ = _mm_add_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(z),
                           static_cast<float>(w)};
        data_ = vaddq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic C, arithmetic D, arithmetic V2>
    Vector4 &add(Vector2<V2> const &v, C z, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(z),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_add_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(z), static_cast<float>(w)};
        data_ = vaddq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic D, arithmetic V2>
    Vector4 &add(A x, Vector2<V2> const &v, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(v.y()),
                                static_cast<float>(v.x()), static_cast<float>(x));
        data_ = _mm_add_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(v.x()),
                           static_cast<float>(v.y()), static_cast<float>(w)};
        data_ = vaddq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &add(A x, B y, Vector2<V2> const &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.y()), static_cast<float>(v.x()),
                                static_cast<float>(y), static_cast<float>(x));
        data_ = _mm_add_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(v.x()),
                           static_cast<float>(v.y())};
        data_ = vaddq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.x()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(v.y()));
#endif
        return *this;
    }

    template <arithmetic V21, arithmetic V22>
    Vector4 &add(Vector2<V21> const &v1, Vector2<V22> const &v2)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v2.y()), static_cast<float>(v2.x()),
                                static_cast<float>(v1.y()), static_cast<float>(v1.x()));
        data_ = _mm_add_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v1.x()), static_cast<float>(v1.y()),
                           static_cast<float>(v2.x()), static_cast<float>(v2.y())};
        data_ = vaddq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v1.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v1.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v2.x()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(v2.y()));
#endif
        return *this;
    }

    template <arithmetic D, arithmetic V3>
    Vector4 &add(Vector3<V3> const &v, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(v.z()),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_add_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(v.z()), static_cast<float>(w)};
        data_ = vaddq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &add(A x, Vector3<V3> const &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.z()), static_cast<float>(v.y()),
                                static_cast<float>(v.x()), static_cast<float>(x));
        data_ = _mm_add_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(v.x()),
                           static_cast<float>(v.y()), static_cast<float>(v.z())};
        data_ = vaddq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(v.z()));
#endif
        return *this;
    }

    template <arithmetic V4>
    Vector4 &add(const Vector4<V4> &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.w()), static_cast<float>(v.z()),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_add_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(v.z()), static_cast<float>(v.w())};
        data_ = vaddq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) + static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) + static_cast<double>(v.w()));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4 &sub(A x, B y, C z, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(z), static_cast<float>(y),
                                static_cast<float>(x));
        data_ = _mm_sub_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(z),
                           static_cast<float>(w)};
        data_ = vsubq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic C, arithmetic D, arithmetic V2>
    Vector4 &sub(Vector2<V2> const &v, C z, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(z),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_sub_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(z), static_cast<float>(w)};
        data_ = vsubq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic D, arithmetic V2>
    Vector4 &sub(A x, Vector2<V2> const &v, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(v.y()),
                                static_cast<float>(v.x()), static_cast<float>(x));
        data_ = _mm_sub_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(v.x()),
                           static_cast<float>(v.y()), static_cast<float>(w)};
        data_ = vsubq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &sub(A x, B y, Vector2<V2> const &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.y()), static_cast<float>(v.x()),
                                static_cast<float>(y), static_cast<float>(x));
        data_ = _mm_sub_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(v.x()),
                           static_cast<float>(v.y())};
        data_ = vsubq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v.x()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(v.y()));
#endif
        return *this;
    }

    template <arithmetic V21, arithmetic V22>
    Vector4 &sub(Vector2<V21> const &v1, Vector2<V22> const &v2)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v2.y()), static_cast<float>(v2.x()),
                                static_cast<float>(v1.y()), static_cast<float>(v1.x()));
        data_ = _mm_sub_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v1.x()), static_cast<float>(v1.y()),
                           static_cast<float>(v2.x()), static_cast<float>(v2.y())};
        data_ = vsubq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(v1.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v1.y()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v2.x()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(v2.y()));
#endif
        return *this;
    }

    template <arithmetic D, arithmetic V3>
    Vector4 &sub(Vector3<V3> const &v, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(v.z()),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_sub_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(v.z()), static_cast<float>(w)};
        data_ = vsubq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &sub(A x, Vector3<V3> const &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.z()), static_cast<float>(v.y()),
                                static_cast<float>(v.x()), static_cast<float>(x));
        data_ = _mm_sub_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(v.x()),
                           static_cast<float>(v.y()), static_cast<float>(v.z())};
        data_ = vsubq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(v.z()));
#endif
        return *this;
    }

    template <arithmetic V4>
    Vector4 &sub(const Vector4<V4> &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.w()), static_cast<float>(v.z()),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_sub_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(v.z()), static_cast<float>(v.w())};
        data_ = vsubq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) - static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) - static_cast<double>(v.w()));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4 &mul(A x, B y, C z, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(z), static_cast<float>(y),
                                static_cast<float>(x));
        data_ = _mm_mul_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(z),
                           static_cast<float>(w)};
        data_ = vmulq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic C, arithmetic D, arithmetic V2>
    Vector4 &mul(Vector2<V2> const &v, C z, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(z),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_mul_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(z), static_cast<float>(w)};
        data_ = vmulq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic D, arithmetic V2>
    Vector4 &mul(A x, Vector2<V2> const &v, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(v.y()),
                                static_cast<float>(v.x()), static_cast<float>(x));
        data_ = _mm_mul_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(v.x()),
                           static_cast<float>(v.y()), static_cast<float>(w)};
        data_ = vmulq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &mul(A x, B y, Vector2<V2> const &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.y()), static_cast<float>(v.x()),
                                static_cast<float>(y), static_cast<float>(x));
        data_ = _mm_mul_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(v.x()),
                           static_cast<float>(v.y())};
        data_ = vmulq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v.x()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(v.y()));
#endif
        return *this;
    }

    template <arithmetic V21, arithmetic V22>
    Vector4 &mul(Vector2<V21> const &v1, Vector2<V22> const &v2)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v2.y()), static_cast<float>(v2.x()),
                                static_cast<float>(v1.y()), static_cast<float>(v1.x()));
        data_ = _mm_mul_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v1.x()), static_cast<float>(v1.y()),
                           static_cast<float>(v2.x()), static_cast<float>(v2.y())};
        data_ = vmulq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(v1.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v1.y()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v2.x()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(v2.y()));
#endif
        return *this;
    }

    template <arithmetic D, arithmetic V3>
    Vector4 &mul(Vector3<V3> const &v, D w)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(v.z()),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_mul_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(v.z()), static_cast<float>(w)};
        data_ = vmulq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &mul(A x, Vector3<V3> const &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.z()), static_cast<float>(v.y()),
                                static_cast<float>(v.x()), static_cast<float>(x));
        data_ = _mm_mul_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(v.x()),
                           static_cast<float>(v.y()), static_cast<float>(v.z())};
        data_ = vmulq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(v.z()));
#endif
        return *this;
    }

    template <arithmetic V4>
    Vector4 &mul(const Vector4<V4> &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.w()), static_cast<float>(v.z()),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_mul_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(v.z()), static_cast<float>(v.w())};
        data_ = vmulq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(v.w()));
#endif
        return *this;
    }

    // === div === //

    template <arithmetic A, arithmetic B, arithmetic C, arithmetic D>
    Vector4 &div(A x, B y, C z, D w)
    {
        assert(x != 0 && y != 0 && z != 0 && w != 0);
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(z), static_cast<float>(y),
                                static_cast<float>(x));
        data_ = _mm_div_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(z),
                           static_cast<float>(w)};
        data_ = vdivq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic C, arithmetic D, arithmetic V2>
    Vector4 &div(Vector2<V2> const &v, C z, D w)
    {
        assert(v.x() != 0 && v.y() != 0 && z != 0 && w != 0);
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(z),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_div_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(z), static_cast<float>(w)};
        data_ = vdivq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(z));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic D, arithmetic V2>
    Vector4 &div(A x, Vector2<V2> const &v, D w)
    {
        assert(x != 0 && v.x() != 0 && v.y() != 0 && w != 0);
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(v.y()),
                                static_cast<float>(v.x()), static_cast<float>(x));
        data_ = _mm_div_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(v.x()),
                           static_cast<float>(v.y()), static_cast<float>(w)};
        data_ = vdivq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic B, arithmetic V2>
    Vector4 &div(A x, B y, Vector2<V2> const &v)
    {
        assert(x != 0 && y != 0 && v.x() != 0 && v.y() != 0);
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.y()), static_cast<float>(v.x()),
                                static_cast<float>(y), static_cast<float>(x));
        data_ = _mm_div_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(v.x()),
                           static_cast<float>(v.y())};
        data_ = vdivq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(y));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v.x()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(v.y()));
#endif
        return *this;
    }

    template <arithmetic V21, arithmetic V22>
    Vector4 &div(Vector2<V21> const &v1, Vector2<V22> const &v2)
    {
        assert(v1.x() != 0 && v1.y() != 0 && v2.x() != 0 && v2.y() != 0);
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v2.y()), static_cast<float>(v2.x()),
                                static_cast<float>(v1.y()), static_cast<float>(v1.x()));
        data_ = _mm_div_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v1.x()), static_cast<float>(v1.y()),
                           static_cast<float>(v2.x()), static_cast<float>(v2.y())};
        data_ = vdivq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(v1.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v1.y()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v2.x()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(v2.y()));
#endif
        return *this;
    }

    template <arithmetic D, arithmetic V3>
    Vector4 &div(Vector3<V3> const &v, D w)
    {
        assert(v.x() != 0 && v.y() != 0 && v.z() != 0 && w != 0);
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(w), static_cast<float>(v.z()),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_div_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(v.z()), static_cast<float>(w)};
        data_ = vdivq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(w));
#endif
        return *this;
    }

    template <arithmetic A, arithmetic V3>
    Vector4 &div(A x, Vector3<V3> const &v)
    {
        assert(x != 0 && v.x() != 0 && v.y() != 0 && v.z() != 0);
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.z()), static_cast<float>(v.y()),
                                static_cast<float>(v.x()), static_cast<float>(x));
        data_ = _mm_div_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(x), static_cast<float>(v.x()),
                           static_cast<float>(v.y()), static_cast<float>(v.z())};
        data_ = vdivq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v.x()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v.y()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(v.z()));
#endif
        return *this;
    }

    template <arithmetic V4>
    Vector4 &div(const Vector4<V4> &v)
    {
#ifdef USE_SSE
        __m128 rhs = _mm_set_ps(static_cast<float>(v.w()), static_cast<float>(v.z()),
                                static_cast<float>(v.y()), static_cast<float>(v.x()));
        data_ = _mm_div_ps(data_, rhs);
#elif defined(USE_NEON)
        float32x4_t rhs = {static_cast<float>(v.x()), static_cast<float>(v.y()),
                           static_cast<float>(v.z()), static_cast<float>(v.w())};
        data_ = vdivq_f32(data_, rhs);
#else
        x_ = static_cast<float>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<float>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<float>(static_cast<double>(z_) / static_cast<double>(v.z()));
        w_ = static_cast<float>(static_cast<double>(w_) / static_cast<double>(v.w()));
#endif
        return *this;
    }

    template <arithmetic T>
    Vector4 &scale(T scalar)
    {
#ifdef USE_SSE
        __m128 scale = _mm_set1_ps(static_cast<float>(scalar));
        data_ = _mm_mul_ps(data_, scale);
#elif defined(USE_NEON)
        float32x4_t scale = vdupq_n_f32(static_cast<float>(scalar));
        data_ = vmulq_f32(data_, scale);
#else
        x_ = static_cast<float>(static_cast<double>(x_) * static_cast<double>(scalar));
        y_ = static_cast<float>(static_cast<double>(y_) * static_cast<double>(scalar));
        z_ = static_cast<float>(static_cast<double>(z_) * static_cast<double>(scalar));
        w_ = static_cast<float>(static_cast<double>(w_) * static_cast<double>(scalar));
#endif
        return *this;
    }

    Vector4 &normalize()
    {
#ifdef USE_SSE
        __m128 squared = _mm_mul_ps(data_, data_);
        __m128 temp = _mm_hadd_ps(squared, squared);
        temp = _mm_hadd_ps(temp, temp);
        float length = _mm_cvtss_f32(_mm_sqrt_ss(temp));
        assert(length > 0.0f && "Cannot normalize a zero-length vector");
        __m128 len_vec = _mm_set1_ps(length);
        data_ = _mm_div_ps(data_, len_vec);
#elif defined(USE_NEON)
        // Square each component
        float32x4_t squared = vmulq_f32(data_, data_);
        // Horizontal add: sum all 4 floats in squared vector
        float32x2_t low = vget_low_f32(squared);
        float32x2_t high = vget_high_f32(squared);
        float32x2_t sum = vpadd_f32(low, high);
        float length = std::sqrt(vget_lane_f32(sum, 0) + vget_lane_f32(sum, 1));
        assert(length > 0.0f && "Cannot normalize a zero-length vector");
        float32x4_t len_vec = vdupq_n_f32(length);
        data_ = vdivq_f32(data_, len_vec);
#else
        const double length =
            std::sqrt(static_cast<double>(x_) * x_ + static_cast<double>(y_) * y_ +
                      static_cast<double>(z_) * z_ + static_cast<double>(w_) * w_);
        assert(length > 0.0 && "Cannot normalize a zero-length vector");
        x_ = static_cast<float>(static_cast<double>(x_) / length);
        y_ = static_cast<float>(static_cast<double>(y_) / length);
        z_ = static_cast<float>(static_cast<double>(z_) / length);
        w_ = static_cast<float>(static_cast<double>(w_) / length);
#endif
        return *this;
    }

    Vector4 &negate()
    {
#ifdef USE_SSE
        __m128 sign_mask = _mm_set1_ps(-0.0f);
        data_ = _mm_xor_ps(data_, sign_mask);
#elif defined(USE_NEON)
        data_ =
            vreinterpretq_f32_u32(veorq_u32(vreinterpretq_u32_f32(data_), vdupq_n_u32(0x80000000)));
#else
        x_ = -x_;
        y_ = -y_;
        z_ = -z_;
        w_ = -w_;
#endif
        return *this;
    }

    float magnitude_sqr() const
    {
#ifdef USE_SSE
        __m128 mul = _mm_mul_ps(data_, data_);
        __m128 sum = _mm_hadd_ps(mul, mul);
        sum = _mm_hadd_ps(sum, sum);
        return _mm_cvtss_f32(sum);
#elif defined(USE_NEON)
        float32x4_t mul = vmulq_f32(data_, data_);
        float32x2_t low = vget_low_f32(mul);
        float32x2_t high = vget_high_f32(mul);
        float32x2_t sum = vpadd_f32(low, high);
        return vget_lane_f32(sum, 0) + vget_lane_f32(sum, 1);
#else
        return static_cast<float>(static_cast<double>(x_) * x_ + static_cast<double>(y_) * y_ +
                                  static_cast<double>(z_) * z_ + static_cast<double>(w_) * w_);
#endif
    }

    float magnitude() const
    {
#ifdef USE_SSE
        __m128 mul = _mm_mul_ps(data_, data_);
        __m128 sum = _mm_hadd_ps(mul, mul);
        sum = _mm_hadd_ps(sum, sum);
        return _mm_cvtss_f32(_mm_sqrt_ss(sum));
#elif defined(USE_NEON)
        float32x4_t mul = vmulq_f32(data_, data_);
        float32x2_t low = vget_low_f32(mul);
        float32x2_t high = vget_high_f32(mul);
        float32x2_t sum = vpadd_f32(low, high);
        float total = vget_lane_f32(sum, 0) + vget_lane_f32(sum, 1);
        return std::sqrt(total);
#else
        return static_cast<float>(
            std::sqrt(static_cast<double>(x_) * x_ + static_cast<double>(y_) * y_ +
                      static_cast<double>(z_) * z_ + static_cast<double>(w_) * w_));
#endif
    }

    float dot(const Vector4 &other) const
    {
#ifdef USE_SSE
        __m128 mul = _mm_mul_ps(data_, other.data_);
        __m128 sum = _mm_hadd_ps(mul, mul);
        sum = _mm_hadd_ps(sum, sum);
        return _mm_cvtss_f32(sum);
#elif defined(USE_NEON)
        float32x4_t mul = vmulq_f32(data_, other.data_);
        float32x2_t low = vget_low_f32(mul);
        float32x2_t high = vget_high_f32(mul);
        float32x2_t sum = vpadd_f32(low, high);
        return vget_lane_f32(sum, 0) + vget_lane_f32(sum, 1);
#else
        return static_cast<float>(
            static_cast<double>(x_) * other.x_ + static_cast<double>(y_) * other.y_ +
            static_cast<double>(z_) * other.z_ + static_cast<double>(w_) * other.w_);
#endif
    }

    float cos(const Vector4 &other) const
    {
#ifdef USE_SSE
        __m128 mul = _mm_mul_ps(data_, other.data_);
        __m128 dot = _mm_hadd_ps(mul, mul);
        dot = _mm_hadd_ps(dot, dot);

        __m128 mag1 = _mm_mul_ps(data_, data_);
        mag1 = _mm_hadd_ps(mag1, mag1);
        mag1 = _mm_hadd_ps(mag1, mag1);
        mag1 = _mm_sqrt_ps(mag1);

        __m128 mag2 = _mm_mul_ps(other.data_, other.data_);
        mag2 = _mm_hadd_ps(mag2, mag2);
        mag2 = _mm_hadd_ps(mag2, mag2);
        mag2 = _mm_sqrt_ps(mag2);

        float m1 = _mm_cvtss_f32(mag1);
        float m2 = _mm_cvtss_f32(mag2);

        assert(m1 > 0.0f && m2 > 0.0f && "Cannot compute angle with a zero-magnitude vector");

        __m128 mag_product = _mm_mul_ps(mag1, mag2);
        __m128 cos_theta = _mm_div_ps(dot, mag_product);

        return _mm_cvtss_f32(cos_theta);
#elif defined(USE_NEON)
        float32x4_t mul = vmulq_f32(data_, other.data_);
        float32x2_t low = vget_low_f32(mul);
        float32x2_t high = vget_high_f32(mul);
        float32x2_t sum = vpadd_f32(low, high);
        float dot_product = vget_lane_f32(sum, 0) + vget_lane_f32(sum, 1);

        // magnitude 1
        float32x4_t mag1 = vmulq_f32(data_, data_);
        float32x2_t low1 = vget_low_f32(mag1);
        float32x2_t high1 = vget_high_f32(mag1);
        float32x2_t sum1 = vpadd_f32(low1, high1);
        float mag1_val = std::sqrt(vget_lane_f32(sum1, 0) + vget_lane_f32(sum1, 1));

        // magnitude 2
        float32x4_t mag2 = vmulq_f32(other.data_, other.data_);
        float32x2_t low2 = vget_low_f32(mag2);
        float32x2_t high2 = vget_high_f32(mag2);
        float32x2_t sum2 = vpadd_f32(low2, high2);
        float mag2_val = std::sqrt(vget_lane_f32(sum2, 0) + vget_lane_f32(sum2, 1));

        assert(mag1_val > 0.0f && mag2_val > 0.0f &&
               "Cannot compute angle with a zero-magnitude vector");

        return dot_product / (mag1_val * mag2_val);
#else
        const double dotProduct =
            static_cast<double>(x_) * other.x_ + static_cast<double>(y_) * other.y_ +
            static_cast<double>(z_) * other.z_ + static_cast<double>(w_) * other.w_;

        const double mag1 = std::sqrt(static_cast<double>(x_) * x_ + static_cast<double>(y_) * y_ +
                                      static_cast<double>(z_) * z_ + static_cast<double>(w_) * w_);

        const double mag2 = std::sqrt(
            static_cast<double>(other.x_) * other.x_ + static_cast<double>(other.y_) * other.y_ +
            static_cast<double>(other.z_) * other.z_ + static_cast<double>(other.w_) * other.w_);

        assert(mag1 > 0.0f && mag2 > 0.0f && "Cannot compute angle with a zero-magnitude vector");

        const double cosTheta = dotProduct / (mag1 * mag2);
        return static_cast<float>(cosTheta);
#endif
    }

    float angle(const Vector4 &other) const
    {
#ifdef USE_SSE
        float cos_scalar = cos(other);
        return std::acos(cos_scalar);
#elif defined(USE_NEON)
        float cos_scalar = cos(other);
        return std::acos(cos_scalar);
#else
        const double dotProduct =
            static_cast<double>(x_) * other.x_ + static_cast<double>(y_) * other.y_ +
            static_cast<double>(z_) * other.z_ + static_cast<double>(w_) * other.w_;

        const double mag1 = std::sqrt(static_cast<double>(x_) * x_ + static_cast<double>(y_) * y_ +
                                      static_cast<double>(z_) * z_ + static_cast<double>(w_) * w_);

        const double mag2 = std::sqrt(
            static_cast<double>(other.x_) * other.x_ + static_cast<double>(other.y_) * other.y_ +
            static_cast<double>(other.z_) * other.z_ + static_cast<double>(other.w_) * other.w_);

        assert(mag1 > 0.0f && mag2 > 0.0f && "Cannot compute angle with a zero-magnitude vector");

        const double cosTheta = dotProduct / (mag1 * mag2);
        return static_cast<float>(std::acos(cosTheta));
#endif
    }

    template <arithmetic T>
    Vector4 &mad(const Vector4 &other, T scalar)
    {
#ifdef USE_SSE
        __m128 scale = _mm_set1_ps(static_cast<float>(scalar));
        __m128 scaled = _mm_mul_ps(other.data_, scale);
        data_ = _mm_add_ps(data_, scaled);
#elif defined(USE_NEON)
        float32x4_t scale = vdupq_n_f32(static_cast<float>(scalar));
        float32x4_t scaled = vmulq_f32(other.data_, scale);
        data_ = vaddq_f32(data_, scaled);
#else
        x_ = static_cast<float>(static_cast<double>(x_) +
                                static_cast<double>(other.x_) * static_cast<double>(scalar));
        y_ = static_cast<float>(static_cast<double>(y_) +
                                static_cast<double>(other.y_) * static_cast<double>(scalar));
        z_ = static_cast<float>(static_cast<double>(z_) +
                                static_cast<double>(other.z_) * static_cast<double>(scalar));
        w_ = static_cast<float>(static_cast<double>(w_) +
                                static_cast<double>(other.w_) * static_cast<double>(scalar));
#endif
        return *this;
    }

    bool equal(const Vector4 &other) const
    {
        constexpr float epsilon = 1e-5f;
#ifdef USE_SSE
        __m128 diff = _mm_sub_ps(data_, other.data_);
        __m128 abs_diff = _mm_andnot_ps(_mm_set1_ps(-0.0f), diff);
        __m128 cmp = _mm_cmplt_ps(abs_diff, _mm_set1_ps(epsilon));
        return _mm_movemask_ps(cmp) == 0xF;
#elif defined(USE_NEON)
        float32x4_t diff = vabdq_f32(data_, other.data_);
        uint32x4_t cmp = vcltq_f32(diff, vdupq_n_f32(epsilon));
        // check if all lanes are true
        return (vminvq_u32(cmp) != 0);
#else
        return std::abs(static_cast<double>(x_) - static_cast<double>(other.x_)) < epsilon &&
               std::abs(static_cast<double>(y_) - static_cast<double>(other.y_)) < epsilon &&
               std::abs(static_cast<double>(z_) - static_cast<double>(other.z_)) < epsilon &&
               std::abs(static_cast<double>(w_) - static_cast<double>(other.w_)) < epsilon;
#endif
    }

    bool operator==(const Vector4 &other) const noexcept { return equal(other); }

    Vector4 &operator=(const Vector4 &other) noexcept
    {
#ifdef USE_SSE
        data_ = other.data_;
#elif defined(USE_NEON)
        data_ = other.data_;
#else
        x_ = other.x_;
        y_ = other.y_;
        z_ = other.z_;
        w_ = other.w_;
#endif
        return *this;
    }

    float operator[](size_t index)
    {
#ifdef USE_SSE
        __m128 vec;
        switch (index)
        {
            case 0:
                return _mm_cvtss_f32(data_);
            case 1:
                vec = _mm_shuffle_ps(data_, data_, _MM_SHUFFLE(1, 1, 1, 1));
                return _mm_cvtss_f32(vec);
            case 2:
                vec = _mm_shuffle_ps(data_, data_, _MM_SHUFFLE(2, 2, 2, 2));
                return _mm_cvtss_f32(vec);
            case 3:
                vec = _mm_shuffle_ps(data_, data_, _MM_SHUFFLE(3, 3, 3, 3));
                return _mm_cvtss_f32(vec);
            default:
                throw std::out_of_range("Vector4 index out of range");
        }
#elif defined(USE_NEON)
        switch (index)
        {
            case 0:
                return vgetq_lane_f32(data_, 0);
            case 1:
                return vgetq_lane_f32(data_, 1);
            case 2:
                return vgetq_lane_f32(data_, 2);
            case 3:
                return vgetq_lane_f32(data_, 3);
            default:
                throw std::out_of_range("Vector4 index out of range");
        }
#else
        switch (index)
        {
            case 0:
                return x_;
            case 1:
                return y_;
            case 2:
                return z_;
            case 3:
                return w_;
            default:
                throw std::out_of_range("Vector4 index out of range");
        }
#endif
    }

    const float operator[](size_t index) const
    {
        return const_cast<Vector4<float> *>(this)->operator[](index);
    }

   private:
#if defined(USE_NEON)
    static float32x4_t load_neon_vec(float a, float b, float c, float d)
    {
        float vals[4] = {a, b, c, d};
        return vld1q_f32(vals);
    }
#endif
#ifdef USE_SSE
    __m128 data_;
#elif defined(USE_NEON)
    float32x4_t data_;
#else
    float x_, y_, z_, w_;
#endif
};

}  // namespace ksemath