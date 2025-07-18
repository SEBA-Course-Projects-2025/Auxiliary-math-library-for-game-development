#include "include/vector4.hpp"

#include <benchmark/benchmark.h>

namespace ksemath
{

// Helper function to generate random vectors
template <typename V>
Vector4<V> random_vec4(V min, V max)
{
    V range = max - min;
    return Vector4<V>(min + static_cast<V>(rand()) / (static_cast<V>(RAND_MAX / range)),
                      min + static_cast<V>(rand()) / (static_cast<V>(RAND_MAX / range)),
                      min + static_cast<V>(rand()) / (static_cast<V>(RAND_MAX / range)),
                      min + static_cast<V>(rand()) / (static_cast<V>(RAND_MAX / range)));
}

// Construction benchmarks
static void BM_Vector4f_Construction(benchmark::State& state)
{
    for (auto _ : state)
    {
        Vector4<float> v(1.0f, 2.0f, 3.0f, 4.0f);
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_Vector4f_Construction);

static void BM_Vector4d_Construction(benchmark::State& state)
{
    for (auto _ : state)
    {
        Vector4<double> v(1.0, 2.0, 3.0, 4.0);
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_Vector4d_Construction);

// Addition benchmarks
static void BM_Vector4f_Addition(benchmark::State& state)
{
    Vector4<float> v1 = random_vec4<float>(-100.0f, 100.0f);
    Vector4<float> v2 = random_vec4<float>(-100.0f, 100.0f);

    for (auto _ : state)
    {
        Vector4<float> result = v1;
        result.add(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_Addition);

static void BM_Vector4d_Addition(benchmark::State& state)
{
    Vector4<double> v1 = random_vec4<double>(-100.0, 100.0);
    Vector4<double> v2 = random_vec4<double>(-100.0, 100.0);

    for (auto _ : state)
    {
        Vector4<double> result = v1;
        result.add(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_Addition);

// Subtraction benchmarks
static void BM_Vector4f_Subtraction(benchmark::State& state)
{
    Vector4<float> v1 = random_vec4<float>(-100.0f, 100.0f);
    Vector4<float> v2 = random_vec4<float>(-100.0f, 100.0f);

    for (auto _ : state)
    {
        Vector4<float> result = v1;
        result.sub(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_Subtraction);

static void BM_Vector4d_Subtraction(benchmark::State& state)
{
    Vector4<double> v1 = random_vec4<double>(-100.0, 100.0);
    Vector4<double> v2 = random_vec4<double>(-100.0, 100.0);

    for (auto _ : state)
    {
        Vector4<double> result = v1;
        result.sub(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_Subtraction);

// Multiplication benchmarks
static void BM_Vector4f_Multiplication(benchmark::State& state)
{
    Vector4<float> v1 = random_vec4<float>(-100.0f, 100.0f);
    Vector4<float> v2 = random_vec4<float>(-100.0f, 100.0f);

    for (auto _ : state)
    {
        Vector4<float> result = v1;
        result.mul(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_Multiplication);

static void BM_Vector4d_Multiplication(benchmark::State& state)
{
    Vector4<double> v1 = random_vec4<double>(-100.0, 100.0);
    Vector4<double> v2 = random_vec4<double>(-100.0, 100.0);

    for (auto _ : state)
    {
        Vector4<double> result = v1;
        result.mul(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_Multiplication);

// Division benchmarks
static void BM_Vector4f_Division(benchmark::State& state)
{
    Vector4<float> v1 = random_vec4<float>(1.0f, 100.0f);  // Avoid division by zero
    Vector4<float> v2 = random_vec4<float>(1.0f, 100.0f);

    for (auto _ : state)
    {
        Vector4<float> result = v1;
        result.div(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_Division);

static void BM_Vector4d_Division(benchmark::State& state)
{
    Vector4<double> v1 = random_vec4<double>(1.0, 100.0);
    Vector4<double> v2 = random_vec4<double>(1.0, 100.0);

    for (auto _ : state)
    {
        Vector4<double> result = v1;
        result.div(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_Division);

// Scaling benchmarks
static void BM_Vector4f_Scaling(benchmark::State& state)
{
    Vector4<float> v = random_vec4<float>(-100.0f, 100.0f);
    float scalar = 2.5f;

    for (auto _ : state)
    {
        Vector4<float> result = v;
        result.scale(scalar);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_Scaling);

static void BM_Vector4d_Scaling(benchmark::State& state)
{
    Vector4<double> v = random_vec4<double>(-100.0, 100.0);
    double scalar = 2.5;

    for (auto _ : state)
    {
        Vector4<double> result = v;
        result.scale(scalar);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_Scaling);

// Normalization benchmarks
static void BM_Vector4f_Normalization(benchmark::State& state)
{
    Vector4<float> v = random_vec4<float>(-100.0f, 100.0f);

    for (auto _ : state)
    {
        Vector4<float> result = v;
        result.normalize();
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_Normalization);

static void BM_Vector4d_Normalization(benchmark::State& state)
{
    Vector4<double> v = random_vec4<double>(-100.0, 100.0);

    for (auto _ : state)
    {
        Vector4<double> result = v;
        result.normalize();
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_Normalization);

// Dot product benchmarks
static void BM_Vector4f_DotProduct(benchmark::State& state)
{
    Vector4<float> v1 = random_vec4<float>(-100.0f, 100.0f);
    Vector4<float> v2 = random_vec4<float>(-100.0f, 100.0f);

    for (auto _ : state)
    {
        float result = v1.dot(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_DotProduct);

static void BM_Vector4d_DotProduct(benchmark::State& state)
{
    Vector4<double> v1 = random_vec4<double>(-100.0, 100.0);
    Vector4<double> v2 = random_vec4<double>(-100.0, 100.0);

    for (auto _ : state)
    {
        double result = v1.dot(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_DotProduct);

// Magnitude benchmarks
static void BM_Vector4f_Magnitude(benchmark::State& state)
{
    Vector4<float> v = random_vec4<float>(-100.0f, 100.0f);

    for (auto _ : state)
    {
        float result = v.magnitude();
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_Magnitude);

static void BM_Vector4d_Magnitude(benchmark::State& state)
{
    Vector4<double> v = random_vec4<double>(-100.0, 100.0);

    for (auto _ : state)
    {
        double result = v.magnitude();
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_Magnitude);

// Angle calculation benchmarks
static void BM_Vector4f_Angle(benchmark::State& state)
{
    Vector4<float> v1 = random_vec4<float>(-100.0f, 100.0f);
    Vector4<float> v2 = random_vec4<float>(-100.0f, 100.0f);

    for (auto _ : state)
    {
        float result = v1.angle(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_Angle);

static void BM_Vector4d_Angle(benchmark::State& state)
{
    Vector4<double> v1 = random_vec4<double>(-100.0, 100.0);
    Vector4<double> v2 = random_vec4<double>(-100.0, 100.0);

    for (auto _ : state)
    {
        double result = v1.angle(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_Angle);

// MAD (Multiply-Add) benchmarks
static void BM_Vector4f_MAD(benchmark::State& state)
{
    Vector4<float> v1 = random_vec4<float>(-100.0f, 100.0f);
    Vector4<float> v2 = random_vec4<float>(-100.0f, 100.0f);
    float scalar = 2.5f;

    for (auto _ : state)
    {
        Vector4<float> result = v1;
        result.mad(v2, scalar);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_MAD);

static void BM_Vector4d_MAD(benchmark::State& state)
{
    Vector4<double> v1 = random_vec4<double>(-100.0, 100.0);
    Vector4<double> v2 = random_vec4<double>(-100.0, 100.0);
    double scalar = 2.5;

    for (auto _ : state)
    {
        Vector4<double> result = v1;
        result.mad(v2, scalar);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_MAD);

// Comparison benchmarks
static void BM_Vector4f_Comparison(benchmark::State& state)
{
    Vector4<float> v1 = random_vec4<float>(-100.0f, 100.0f);
    Vector4<float> v2 = v1;  // Make them equal

    for (auto _ : state)
    {
        bool result = v1.equal(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4f_Comparison);

static void BM_Vector4d_Comparison(benchmark::State& state)
{
    Vector4<double> v1 = random_vec4<double>(-100.0, 100.0);
    Vector4<double> v2 = v1;  // Make them equal

    for (auto _ : state)
    {
        bool result = v1.equal(v2);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector4d_Comparison);

}  // namespace ksemath