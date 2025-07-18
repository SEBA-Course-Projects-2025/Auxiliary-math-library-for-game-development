#include <benchmark/benchmark.h>
#include "include/vector3.hpp"

namespace bm = benchmark;

// Базові арифметичні операції
static void BM_Vector3_Add(bm::State& state) {
    ksemath::vec3f v1(1.0f, 2.0f, 3.0f);
    ksemath::vec3f v2(4.0f, 5.0f, 6.0f);
    
    for (auto _ : state) {
        auto result = v1.add(v2);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_Add);

static void BM_Vector3_AddComponents(bm::State& state) {
    ksemath::vec3f v(1.0f, 2.0f, 3.0f);
    
    for (auto _ : state) {
        auto result = v.add(4.0f, 5.0f, 6.0f);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_AddComponents);

static void BM_Vector3_Sub(bm::State& state) {
    ksemath::vec3f v1(5.0f, 6.0f, 7.0f);
    ksemath::vec3f v2(3.0f, 4.0f, 5.0f);
    
    for (auto _ : state) {
        auto result = v1.sub(v2);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_Sub);

static void BM_Vector3_Mul(bm::State& state) {
    ksemath::vec3f v1(1.0f, 2.0f, 3.0f);
    ksemath::vec3f v2(4.0f, 5.0f, 6.0f);
    
    for (auto _ : state) {
        auto result = v1.mul(v2);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_Mul);

static void BM_Vector3_Scale(bm::State& state) {
    ksemath::vec3f v(1.0f, 2.0f, 3.0f);
    float scalar = 2.5f;
    
    for (auto _ : state) {
        auto result = v.scale(scalar);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_Scale);

// Векторні операції
static void BM_Vector3_Magnitude(bm::State& state) {
    ksemath::vec3f v(3.0f, 4.0f, 5.0f);
    
    for (auto _ : state) {
        auto result = v.magnitude();
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_Magnitude);

static void BM_Vector3_MagnitudeSqr(bm::State& state) {
    ksemath::vec3f v(3.0f, 4.0f, 5.0f);
    
    for (auto _ : state) {
        auto result = v.magnitude_sqr();
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_MagnitudeSqr);

static void BM_Vector3_Normalize(bm::State& state) {
    ksemath::vec3f v(3.0f, 4.0f, 5.0f);
    
    for (auto _ : state) {
        auto result = v.normalize();
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_Normalize);

static void BM_Vector3_Angle(bm::State& state) {
    ksemath::vec3f v1(1.0f, 0.0f, 0.0f);
    ksemath::vec3f v2(0.0f, 1.0f, 0.0f);
    
    for (auto _ : state) {
        auto result = v1.angle(v2);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_Angle);

static void BM_Vector3_Cos(bm::State& state) {
    ksemath::vec3f v1(1.0f, 2.0f, 3.0f);
    ksemath::vec3f v2(4.0f, 5.0f, 6.0f);
    
    for (auto _ : state) {
        auto result = v1.cos(v2);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_Cos);

// Операції з Vector2
static void BM_Vector3_FromVector2(bm::State& state) {
    ksemath::vec2f v2(1.0f, 2.0f);
    
    for (auto _ : state) {
        ksemath::vec3f v3(v2, 3.0f);
        bm::DoNotOptimize(v3);
    }
}
BENCHMARK(BM_Vector3_FromVector2);

static void BM_Vector3_AddVector2(bm::State& state) {
    ksemath::vec3f v3(1.0f, 2.0f, 3.0f);
    ksemath::vec2f v2(4.0f, 5.0f);
    
    for (auto _ : state) {
        auto result = v3.add(v2, 6.0f);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_AddVector2);

// Порівняння різних типів
static void BM_Vector3f_vs_Vector3d(bm::State& state) {
    if (state.range(0)) {
        ksemath::vec3f v(1.0f, 2.0f, 3.0f);
        for (auto _ : state) {
            auto result = v.magnitude();
            bm::DoNotOptimize(result);
        }
    } else {
        ksemath::vec3d v(1.0, 2.0, 3.0);
        for (auto _ : state) {
            auto result = v.magnitude();
            bm::DoNotOptimize(result);
        }
    }
}
BENCHMARK(BM_Vector3f_vs_Vector3d)->Arg(0)->Arg(1);

// Тестування з різними розмірами даних
static void BM_Vector3_Scale_Range(bm::State& state) {
    float val = static_cast<float>(state.range(0));
    ksemath::vec3f v(val, val, val);
    float scalar = 1.5f;
    
    for (auto _ : state) {
        auto result = v.scale(scalar);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector3_Scale_Range)->Range(1, 1<<10);