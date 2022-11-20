#pragma once

#include "Cenedes.Models.Exports.Api.h"
#include <winrt/Windows.Foundation.h>

namespace Cenedes::Models
{
  enum struct Sex
  {
    Male = 1,
    Female = 2
  };

  CENEDES_MODELS_API winrt::hstring to_hstring(const Sex value);
}
