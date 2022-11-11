#pragma once

#include <type_traits>
#include <concepts>

namespace Cenedes::Helpers
{
  template <class... T>
  inline constexpr bool AlwaysFalse = false;
}
