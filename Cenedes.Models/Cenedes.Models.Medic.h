#pragma once

#include "Cenedes.Models.Person.h"

namespace Cenedes::Models
{
  struct Medic : Person
  {
    UInt64 MedicId;

    UInt64 GetId() const noexcept override
    {
      return MedicId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      MedicId = Id;
    }
  };
}