#pragma once

#include "Cenedes.Models.Person.h"

namespace Cenedes::Models
{
  struct Patient : Person
  {
    UInt64 PatientId{ 0 };

    UInt64 GetId() const noexcept override
    {
      return PatientId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      PatientId = Id;
    }
  };
}
