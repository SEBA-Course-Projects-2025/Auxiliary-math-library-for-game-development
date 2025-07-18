#include <benchmark/benchmark.h>
#include "include/matrix4x4.hpp"

namespace ksemath {

// Helper function to create a test matrix
template <typename T>
Matrix4x4<T> createTestMatrix(T start = 0) {
    return Matrix4x4<T>(
        start+1, start+2, start+3, start+4,
        start+5, start+6, start+7, start+8,
        start+9, start+10, start+11, start+12,
        start+13, start+14, start+15, start+16
    );
}

// Benchmark for default constructor
static void BM_MatrixDefaultConstruct(benchmark::State& state) {
    for (auto _ : state) {
        Matrix4x4<float> m;
        benchmark::DoNotOptimize(m);
    }
}
BENCHMARK(BM_MatrixDefaultConstruct);

// Benchmark for parameterized constructor
static void BM_MatrixParamConstruct(benchmark::State& state) {
    for (auto _ : state) {
        Matrix4x4<float> m(
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f
        );
        benchmark::DoNotOptimize(m);
    }
}
BENCHMARK(BM_MatrixParamConstruct);

// Benchmark for matrix transposition
static void BM_MatrixTranspose(benchmark::State& state) {
    auto m = createTestMatrix<float>();
    for (auto _ : state) {
        auto result = m.transposed();
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_MatrixTranspose);

// Benchmark for matrix determinant
static void BM_MatrixDeterminant(benchmark::State& state) {
    auto m = createTestMatrix<float>();
    for (auto _ : state) {
        auto det = m.determinant();
        benchmark::DoNotOptimize(det);
    }
}
BENCHMARK(BM_MatrixDeterminant);

// Benchmark for matrix inversion
static void BM_MatrixInvert(benchmark::State& state) {
    // Use a matrix that's definitely invertible
    auto m = Matrix4x4<float>::rotationX(0.5f);
    for (auto _ : state) {
        auto inv = m.inverted();
        benchmark::DoNotOptimize(inv);
    }
}
BENCHMARK(BM_MatrixInvert);

// Benchmark for matrix multiplication
static void BM_MatrixMultiply(benchmark::State& state) {
    auto m1 = createTestMatrix<float>();
    auto m2 = createTestMatrix<float>(5.0f);
    for (auto _ : state) {
        // Note: Uncomment the operator* in your class to use this
        // auto result = m1 * m2;
        // benchmark::DoNotOptimize(result);

        // Alternative implementation if operator* isn't available
        Matrix4x4<float> result;
        for (size_t i = 0; i < 4; ++i) {
            for (size_t j = 0; j < 4; ++j) {
                float sum = 0;
                for (size_t k = 0; k < 4; ++k) {
                    sum += m1.at(i, k) * m2.at(k, j);
                }
                result.at(i, j) = sum;
            }
        }
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_MatrixMultiply);

// Benchmark for creating translation matrix
static void BM_MatrixTranslation(benchmark::State& state) {
    for (auto _ : state) {
        auto m = Matrix4x4<float>::translation(1.0f, 2.0f, 3.0f);
        benchmark::DoNotOptimize(m);
    }
}
BENCHMARK(BM_MatrixTranslation);

// Benchmark for creating rotation matrix
static void BM_MatrixRotation(benchmark::State& state) {
    for (auto _ : state) {
        auto m = Matrix4x4<float>::rotationZ(0.5f);
        benchmark::DoNotOptimize(m);
    }
}
BENCHMARK(BM_MatrixRotation);

// Benchmark for creating perspective matrix
static void BM_MatrixPerspective(benchmark::State& state) {
    for (auto _ : state) {
        auto m = Matrix4x4<float>::perspective(1.0f, 1.33f, 0.1f, 100.0f);
        benchmark::DoNotOptimize(m);
    }
}
BENCHMARK(BM_MatrixPerspective);

} // namespace ksemath