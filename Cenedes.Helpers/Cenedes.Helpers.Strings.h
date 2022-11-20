#pragma once

#include <string>
#include <string_view>
#include <cstring>
#include <cuchar>
#include <cwchar>

namespace Cenedes::Helpers::Strings
{
  inline constexpr const char* Empty = "";

  inline constexpr const wchar_t* WEmpty = L"";

  inline constexpr const char8_t* U8Empty = u8"";

  inline constexpr const char16_t* U16Empty = u"";

  inline constexpr const char32_t* U32Empty = U"";
}
