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

    UInt64 GetId() const noexcept override { return Helpers::Entity::DefaultId; }
    void SetId([[maybe_unused]] const UInt64 Id) noexcept override { }
  };
}
