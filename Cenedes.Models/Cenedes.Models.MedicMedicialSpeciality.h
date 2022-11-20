#pragma once

#include "Cenedes.Models.Medic.h"
#include "Cenedes.Models.MedicalSpeciality.h"

namespace Cenedes::Models
{
  struct MedicMedicialSpeciality : public Entity
  {
    EntityIdType                MedicId;
    Nullable<Medic>             Medic;
    EntityIdType                MedicalSpecialtyId;
    Nullable<MedicalSpeciality> MedicalSpeciality;
  };
}
