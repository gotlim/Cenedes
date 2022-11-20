#pragma once

#include "Cenedes.Models.Entity.h"

namespace Cenedes::Models
{
  struct MedicalSpeciality : public Entity
  {
    EntityIdType MedicalSpecialityId;
    String       Name;
  };
}
