#pragma once

#include "Cenedes.Models.Person.h"

namespace Cenedes::Models
{
  struct Nurse : Person
  {
    UInt64 NurseId;

    UInt64 GetId() const noexcept override
    {
      return NurseId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      NurseId = Id;
    }
  };
}