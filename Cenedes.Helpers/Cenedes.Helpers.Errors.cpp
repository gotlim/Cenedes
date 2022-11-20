#include "pch.h"
#include "Cenedes.Helpers.Errors.h"

namespace Cenedes::Helpers
{
  winrt::hstring GetErrorMessage(const ErrorCode error_code, const wchar_t* message)
  {
    using enum ErrorCode;

    auto concat_string = [](auto &&...messages)
    {
      std::wostringstream output;
      ((output << messages), ...);
      return winrt::hstring(output.str());
    };

    switch (error_code)
    {
      case InvalidEnum: return concat_string(L"Invalid value in enum", L": \"", message, L"\"");
      default: return L"Ok";
    }
  }
}
