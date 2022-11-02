#pragma once

#include "Repository.g.h"

namespace winrt::Cenedes::Repository::implementation
{
  struct Repository : RepositoryT<Repository>
  {
    Repository() = default;
  };
}

namespace winrt::Cenedes::Repository::factory_implementation
{
  struct Repository : RepositoryT<Repository, implementation::Repository>
  {
  };
}
