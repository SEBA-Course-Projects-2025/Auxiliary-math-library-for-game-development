#include <benchmark/benchmark.h>
#include "include/vector2.hpp"

namespace bm = benchmark;

// Базові арифметичні операції
static void BM_Vector2_Add(bm::State& state) {
    ksemath::vec2f v1(1.0f, 2.0f);
    ksemath::vec2f v2(3.0f, 4.0f);
    
    for (auto _ : state) {
        auto result = v1.add(v2);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector2_Add);

static void BM_Vector2_Sub(bm::State& state) {
    ksemath::vec2f v1(5.0f, 6.0f);
    ksemath::vec2f v2(3.0f, 4.0f);
    
    for (auto _ : state) {
        auto result = v1.sub(v2);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector2_Sub);

static void BM_Vector2_Scale(bm::State& state) {
    ksemath::vec2f v(1.0f, 2.0f);
    float scalar = 2.5f;
    
    for (auto _ : state) {
        auto result = v.scale(scalar);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector2_Scale);

// Операції з векторами
static void BM_Vector2_Dot(bm::State& state) {
    ksemath::vec2f v1(1.0f, 2.0f);
    ksemath::vec2f v2(3.0f, 4.0f);
    
    for (auto _ : state) {
        auto result = v1.dot(v2);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector2_Dot);

static void BM_Vector2_Magnitude(bm::State& state) {
    ksemath::vec2f v(3.0f, 4.0f);
    
    for (auto _ : state) {
        auto result = v.magnitude();
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector2_Magnitude);

static void BM_Vector2_Normalize(bm::State& state) {
    ksemath::vec2f v(3.0f, 4.0f);
    
    for (auto _ : state) {
        auto result = v.normalize();
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector2_Normalize);

// Порівняння різних типів
static void BM_Vector2f_vs_Vector2d(bm::State& state) {
    if (state.range(0)) {
        ksemath::vec2f v(1.0f, 2.0f);
        for (auto _ : state) {
            auto result = v.magnitude();
            bm::DoNotOptimize(result);
        }
    } else {
        ksemath::vec2d v(1.0, 2.0);
        for (auto _ : state) {
            auto result = v.magnitude();
            bm::DoNotOptimize(result);
        }
    }
}
BENCHMARK(BM_Vector2f_vs_Vector2d)->Arg(0)->Arg(1);

// Тестування з різними розмірами даних
static void BM_Vector2_Add_Range(bm::State& state) {
    float val = static_cast<float>(state.range(0));
    ksemath::vec2f v1(val, val);
    ksemath::vec2f v2(val + 1.0f, val + 1.0f);
    
    for (auto _ : state) {
        auto result = v1.add(v2);
        bm::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Vector2_Add_Range)->Range(1, 1<<10);

BENCHMARK_MAIN();