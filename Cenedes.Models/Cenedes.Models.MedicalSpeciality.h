#pragma once

#include "Cenedes.Models.Entity.h"

namespace Cenedes::Models
{
  struct MedicalSpeciality : Entity
  {
    UInt64 MedicalSpecialityId;
    String Name;

    UInt64 GetId() const noexcept override
    {
      return MedicalSpecialityId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      MedicalSpecialityId = Id;
    }
  };
}
