#pragma once

#include "Cenedes.Models.PatientClinic.h"

namespace Cenedes::Models
{
  struct PatientClinicDetails : Entity
  {
    UInt64           PatientClinicDetailId;
    UInt64           PatientClinicId;
    Nullable<String> MedicName;
    String           Description;

    UInt64 GetId() const noexcept override
    {
      return PatientClinicDetailId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      PatientClinicDetailId = Id;
    }
  };
}
