#pragma once
#include <cmath>

#include "vector2.hpp"
#include "vector3.hpp"

namespace math
{
template <typename V>
class Vector4
{
   public:
    template <typename A, typename B, typename C, typename D>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C> &&
                 std::is_arithmetic_v<D>)
    Vector4(A x, B y, C z, D w)
        : x_(static_cast<V>(x)),
          y_(static_cast<V>(y)),
          z_(static_cast<V>(z)),
          w_(static_cast<V>(w))
    {
    }

    template <typename C, typename D>
        requires(std::is_arithmetic_v<C> && std::is_arithmetic_v<D>)
    Vector4(Vector2 const &v, C z, D w)
        : x_(static_cast<V>(v.x())),
          y_(static_cast<V>(v.y())),
          z_(static_cast<V>(z)),
          w_(static_cast<V>(w))
    {
    }

    template <typename A, typename D>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<D>)
    Vector4(A x, Vector2 const &v, D w)
        : x_(static_cast<V>(x)),
          y_(static_cast<V>(v.x())),
          z_(static_cast<V>(v.y())),
          w_(static_cast<V>(w))
    {
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4(A x, B y, Vector2 const &v)
        : x_(static_cast<V>(x)),
          y_(static_cast<V>(y)),
          z_(static_cast<V>(v.x())),
          w_(static_cast<V>(v.y()))
    {
    }

    Vector4(Vector2 const &v1, Vector2 const &v2)
        : x_(static_cast<V>(v1.x())),
          y_(static_cast<V>(v1.y())),
          z_(static_cast<V>(v2.x())),
          w_(static_cast<V>(v2.y()))
    {
    }

    template <typename D>
        requires std::is_arithmetic_v<D>
    Vector4(Vector3 const &v, D w)
        : x_(static_cast<V>(v.x())),
          y_(static_cast<V>(v.y())),
          z_(static_cast<V>(v.z())),
          w_(static_cast<V>(w))
    {
    }

    template <typename A>
        requires std::is_arithmetic_v<A>
    Vector4(A x, Vector3 const &v)
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

    template <typename T>
        requires std::is_arithmetic_v<T>
    void setW(T w)
    {
        w_ = static_cast<V>(w);
    }

    template <typename A, typename B, typename C, typename D>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C> &&
                 std::is_arithmetic_v<D>)
    Vector4 &add(A x, B y, C z, D w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &add(Vector2 const &v, A z, B w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &add(A x, Vector2 const &v, B w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &add(A x, B y, Vector2 const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v.x()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(v.y()));
        return *this;
    }

    Vector4 &add(Vector2 const &v1, Vector2 const &v2)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(v1.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v1.y()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v2.x()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(v2.y()));
        return *this;
    }

    template <typename A>
        requires std::is_arithmetic_v<A>
    Vector4 &add(Vector3 const &v, A w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) + static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) + static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) + static_cast<double>(v.z()));
        w_ = static_cast<V>(static_cast<double>(w_) + static_cast<double>(w));
        return *this;
    }

    template <typename A>
        requires std::is_arithmetic_v<A>
    Vector4 &add(A x, Vector3 const &v)
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

    template <typename A, typename B, typename C, typename D>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C> &&
                 std::is_arithmetic_v<D>)
    Vector4 &sub(A x, B y, C z, D w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(w));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &sub(Vector2 const &v, A z, B w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(w));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &sub(A x, Vector2 const &v, B z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(z));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &sub(A x, B y, Vector2 const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v.x()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(v.y()));
        return *this;
    }

    Vector4 &sub(Vector2 const &v1, Vector2 const &v2)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(v1.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v1.y()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v2.x()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(v2.y()));
        return *this;
    }

    template <typename A>
        requires std::is_arithmetic_v<A>
    Vector4 &sub(Vector3 const &v, A w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) - static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) - static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) - static_cast<double>(v.z()));
        w_ = static_cast<V>(static_cast<double>(w_) - static_cast<double>(w));
        return *this;
    }

    template <typename A>
        requires std::is_arithmetic_v<A>
    Vector4 &sub(A x, Vector3 const &v)
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

    template <typename A, typename B, typename C, typename D>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C> &&
                 std::is_arithmetic_v<D>)
    Vector4 &mul(A x, B y, C z, D w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(w));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &mul(Vector2 const &v, A z, B w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(w));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &mul(A x, Vector2 const &v, B z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(z));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &mul(A x, B y, Vector2 const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v.x()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(v.y()));
        return *this;
    }

    Vector4 &mul(Vector2 const &v1, Vector2 const &v2)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(v1.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v1.y()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v2.x()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(v2.y()));
        return *this;
    }

    template <typename A>
        requires std::is_arithmetic_v<A>
    Vector4 &mul(Vector3 const &v, A w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) * static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) * static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) * static_cast<double>(v.z()));
        w_ = static_cast<V>(static_cast<double>(w_) * static_cast<double>(w));
        return *this;
    }

    template <typename A>
        requires std::is_arithmetic_v<A>
    Vector4 &mul(A x, Vector3 const &v)
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

    template <typename A, typename B, typename C, typename D>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B> && std::is_arithmetic_v<C> &&
                 std::is_arithmetic_v<D>)
    Vector4 &div(A x, B y, C z, D w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(w));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &div(Vector2 const &v, A z, B w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(z));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(w));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &div(A x, Vector2 const &v, B z)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(z));
        return *this;
    }

    template <typename A, typename B>
        requires(std::is_arithmetic_v<A> && std::is_arithmetic_v<B>)
    Vector4 &div(A x, B y, Vector2 const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(y));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v.x()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(v.y()));
        return *this;
    }

    Vector4 &div(Vector2 const &v1, Vector2 const &v2)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(v1.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v1.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v2.x()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(v2.y()));
        return *this;
    }

    template <typename A>
        requires std::is_arithmetic_v<A>
    Vector4 &div(Vector3 const &v, A w)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(v.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v.z()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(w));
        return *this;
    }

    template <typename A>
        requires std::is_arithmetic_v<A>
    Vector4 &div(A x, Vector3 const &v)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(x));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(v.x()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(v.y()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(v.z()));
        return *this;
    }

    Vector4 &div(const Vector4 &other)
    {
        x_ = static_cast<V>(static_cast<double>(x_) / static_cast<double>(other.x()));
        y_ = static_cast<V>(static_cast<double>(y_) / static_cast<double>(other.y()));
        z_ = static_cast<V>(static_cast<double>(z_) / static_cast<double>(other.z()));
        w_ = static_cast<V>(static_cast<double>(w_) / static_cast<double>(other.w()));
        return *this;
    }

    template <typename T>
        requires std::is_arithmetic_v<T>
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

    template <typename T>
        requires std::is_arithmetic_v<T>
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

    bool operator==(const Vector4 &other) const
    {
        constexpr double epsilon = 1e-5f;
        return std::abs(static_cast<double>(x_) - static_cast<double>(other.x_)) < epsilon &&
               std::abs(static_cast<double>(y_) - static_cast<double>(other.y_)) < epsilon &&
               std::abs(static_cast<double>(z_) - static_cast<double>(other.z_)) < epsilon &&
               std::abs(static_cast<double>(w_) - static_cast<double>(other.w_)) < epsilon;
    }

    Vector4 &operator=(const Vector4 &other)
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
}  // namespace math
