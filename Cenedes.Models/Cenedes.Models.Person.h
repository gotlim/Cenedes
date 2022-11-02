#pragma once

#include <winrt/Windows.Foundation.h>

#include "Cenedes.Models.Sex.h"

namespace Cenedes::Models
{
  struct Person
  {
    uint64_t                      PersonId;
    winrt::hstring                Carnet;
    winrt::hstring                Name;
    winrt::hstring                LastName;
    uint16_t                      Age;
    std::tm                       Birthday;
    Cenedes::Models::Sex          Sex;
    winrt::hstring                Address;
    std::optional<winrt::hstring> Phone;
  };
}
