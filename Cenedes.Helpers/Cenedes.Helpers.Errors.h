#pragma once

#include <sstream>
#include <stdexcept>

#include <winrt/Windows.Foundation.h>

#include "Cenedes.Helpers.Exports.Api.h"

namespace Cenedes::Helpers
{
  enum struct ErrorCode
  {
    Ok = 0,
    InvalidEnum = 1'000
  };

  inline constexpr ErrorCode ErrorOk{ ErrorCode::Ok };
  inline constexpr ErrorCode ErrorInvalidEnum{ ErrorCode::InvalidEnum };

  CENEDES_HELPERS_API winrt::hstring GetErrorMessage(const ErrorCode error_code, const wchar_t* message = nullptr);
}
