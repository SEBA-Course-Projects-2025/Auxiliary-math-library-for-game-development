#pragma once
#include <type_traits>

namespace ksemath
{
template <typename Ar>
concept arithmetic = std::is_arithmetic_v<Ar>;
}