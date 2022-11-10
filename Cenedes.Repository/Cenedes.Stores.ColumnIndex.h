#pragma once

namespace Cenedes::Stores
{
  template<int32_t Index>
  inline constexpr int32_t ColumnIndex = Index;

  template<int32_t Index>
  inline constexpr int32_t ArgumentIndex = Index;
}
