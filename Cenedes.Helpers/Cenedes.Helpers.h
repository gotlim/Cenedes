#pragma once

#include "Helper.g.h"

namespace winrt::Cenedes::Helpers::implementation
{
  struct Helper : HelperT<Helper>
  {
    Helper() = default;
  };
}

namespace winrt::Cenedes::Helpers::factory_implementation
{
  struct Helper : HelperT<Helper, implementation::Helper>
  {
  };
}
