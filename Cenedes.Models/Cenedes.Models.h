#pragma once

#include "Model.g.h"

namespace winrt::Cenedes::Models::implementation
{
  struct Model : ModelT<Model>
  {
    Model() = default;
  };
}

namespace winrt::Cenedes::Models::factory_implementation
{
  struct Model : ModelT<Model, implementation::Model>
  {
  };
}
