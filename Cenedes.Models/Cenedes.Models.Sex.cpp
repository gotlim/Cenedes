#include "pch.h"
#include "Cenedes.Models.Sex.h"

#include "Cenedes.Helpers.ApplicationException.h"
#include "Cenedes.Helpers.Constants.h"

namespace Cenedes::Models
{
  winrt::hstring to_hstring(const Sex value)
  {
    using enum Sex;

    switch (value)
    {
      case Male:   return L"Hombre";
      case Female: return L"Mujer";
    }

    throw Helpers::ApplicationException
    {
      Helpers::ErrorInvalidEnum,
      L"Cenedes::Models::Sex",
      {
        { Helpers::Constants::EnumValueKey, value }
      }
    };
  }
}
