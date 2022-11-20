#pragma once

#include "Cenedes.Helpers.Errors.h"
#include <unordered_map>
#include <any>

namespace Cenedes::Helpers
{
  class CENEDES_HELPERS_API ApplicationException
  {
  public:
    ApplicationException(const ErrorCode error_code);
    ApplicationException(const ErrorCode error_code, std::unordered_map<std::string, std::any>&& data);
    ApplicationException(const ErrorCode error_code, const std::wstring_view message);
    ApplicationException(const ErrorCode error_code, const std::wstring_view message, std::unordered_map<std::string, std::any>&& data);
    const std::unordered_map<std::string, std::any>& Data() const noexcept;
    const Helpers::ErrorCode& ErrorCode() const noexcept;
    const winrt::hstring& Message() const noexcept;

  private:
    std::any pImpl;
  };
}
