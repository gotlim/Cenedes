#pragma once

#include "Cenedes.Helpers.Types.h"
#include "Cenedes.Helpers.Entity.h"

namespace Cenedes::Models
{
  using namespace Helpers::Types;
}

namespace Cenedes::Models
{
  struct EntityBase abstract
  {
    virtual UInt64 GetId() const noexcept = 0;
    virtual void SetId(const UInt64 Id) noexcept = 0;

    __declspec(property(get = GetId, put = SetId)) UInt64 Id;
  };
}
