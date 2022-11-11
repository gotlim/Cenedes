#pragma once

#include "Cenedes.Models.Medic.h"
#include "Cenedes.Models.MedicalSpeciality.h"

namespace Cenedes::Models
{
  struct MedicMedicialSpeciality : Entity
  {
    UInt64 MedicId;
    UInt64 MedicalSpecialtyId;

    Nullable<Medic> Medic;
    Nullable<MedicalSpeciality> MedicalSpeciality;
  };
}
