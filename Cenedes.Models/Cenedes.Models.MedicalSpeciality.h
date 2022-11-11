#pragma once

#include "Cenedes.Models.Entity.h"

namespace Cenedes::Models
{
  struct MedicalSpeciality : Entity
  {
    UInt64 MedicalSpecialityId;
    String Name;
  };
}
