#pragma once

#include "Cenedes.Helpers.Concepts.h"
#include "Cenedes.Helpers.PatchValue.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <optional>

namespace Cenedes::Helpers::Entity
{
  inline constexpr const uint_fast64_t DefaultId = static_cast<uint_fast64_t>(-1);

  template<typename C>
  std::basic_string<C> Character(const char16_t letter)
  {
    return std::basic_string<C>(1, static_cast<C>(letter));
  }

  template<typename C>
  auto SqlParameter(std::nullptr_t)
  {
    if constexpr (std::same_as<C, char>)
    {
      return "NULL";
    }
    else if constexpr (std::same_as<C, wchar_t>)
    {
      return L"NULL";
    }
    else if constexpr (std::same_as<C, char8_t>)
    {
      return u8"NULL";
    }
    else if constexpr (std::same_as<C, char16_t>)
    {
      return u"NULL";
    }
    else if constexpr (std::same_as<C, char32_t>)
    {
      return U"NULL";
    }
    else
    {
      static_assert(AlwaysFalse<C>);
    }
  }

  template<typename C>
  auto SqlParameter(std::nullopt_t)
  {
    return SqlParameter<C>(nullptr);
  }

  template<typename C>
  std::basic_string<C> RemoveQuotedIfHasQuoted(std::basic_string<C>&& parameter)
  {
    if (parameter.starts_with(Character<C>(u'\"').c_str()) && parameter.ends_with(Character<C>(u'\"').c_str()))
    {
      return std::basic_string<C>(parameter.cbegin() + 1, parameter.cend() - 2);
    }
    else
    {
      return parameter;
    }
  }

  template<typename C, typename Type>
  std::basic_string<C> ValueOrNull(const std::optional<Type>& parameter)
  {
    if (parameter.has_value())
    {
      std::basic_ostringstream<C> output;
      output << parameter.value();
      return output.str();
    }
    else
    {
      return SqlParameter<C>(nullptr);
    }
  }

  template<typename C, typename Parameter>
  std::basic_string<C> QuotedValue(Parameter&& parameter, const bool use_quotes)
  {
    std::basic_ostringstream<C> output;
    output << std::forward<Parameter>(parameter);

    if (use_quotes)
    {
      auto output_string = output.str();
      output = decltype(output)();
      output << std::quoted(output_string);
      return output.str();
    }
    else
    {
      return output.str();
    }
  }

  template<typename C, typename Parameter>
  std::basic_string<C> SqlParameter(Parameter&& parameter, const bool use_quotes = false)
  {
    return QuotedValue<C>(std::forward<Parameter>(parameter), use_quotes);
  }

  template<typename C, typename Type>
  std::basic_string<C> SqlParameter(const std::optional<Type>& parameter, const bool use_quotes = false)
  {
    return RemoveQuotedIfHasQuoted<C>(QuotedValue<C>(ValueOrNull<C>(parameter), use_quotes));
  }

  template<typename C, typename Type>
  std::basic_string<C> SqlParameter(const Helpers::PatchValue<Type>& parameter, const bool use_quotes = false)
  {
    return SqlParameter<C>(*parameter, use_quotes);
  }
}
