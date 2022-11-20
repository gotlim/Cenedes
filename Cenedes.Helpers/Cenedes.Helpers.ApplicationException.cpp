#include "pch.h"
#include "Cenedes.Helpers.ApplicationException.h"

#include <tuple>

namespace Cenedes::Helpers
{
  using PrivateType = std::tuple<ErrorCode, winrt::hstring, std::unordered_map<std::string, std::any>>;

  ApplicationException::ApplicationException(const Helpers::ErrorCode error_code)
    : pImpl{ std::make_any<PrivateType>(error_code, GetErrorMessage(error_code), std::tuple_element_t<2, PrivateType>{ }) }
  {
  }

  ApplicationException::ApplicationException(const Helpers::ErrorCode error_code, const std::wstring_view message)
    : pImpl{ std::make_any<PrivateType>(error_code, GetErrorMessage(error_code, message.data()), std::tuple_element_t<2, PrivateType>{ }) }
  {
  }

  ApplicationException::ApplicationException(const Helpers::ErrorCode error_code, std::unordered_map<std::string, std::any>&& data)
    : pImpl{ std::make_any<PrivateType>(error_code, GetErrorMessage(error_code), std::move(data)) }
  {
  }

  ApplicationException::ApplicationException(const Helpers::ErrorCode error_code, const std::wstring_view message, std::unordered_map<std::string, std::any>&& data)
    : pImpl{ std::make_any<PrivateType>(error_code, GetErrorMessage(error_code, message.data()), std::move(data)) }
  {
  }

  const ErrorCode& ApplicationException::ErrorCode() const noexcept
  {
    return std::get<0>(std::any_cast<PrivateType const&>(pImpl));
  }

  const winrt::hstring& ApplicationException::Message() const noexcept
  {
    return std::get<1>(std::any_cast<PrivateType const&>(pImpl));
  }

  const std::unordered_map<std::string, std::any>& ApplicationException::Data() const noexcept
  {
    return std::get<2>(std::any_cast<PrivateType const&>(pImpl));
  }
};
