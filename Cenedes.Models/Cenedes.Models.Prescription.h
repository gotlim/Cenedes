#pragma once

#include "Cenedes.Models.Consult.h"

namespace Cenedes::Models
{
  struct Prescription : Entity
  {
    UInt64   PrescriptionId;
    UInt64   ConsultId;
    UInt64   PatientId;
    DateTime PrescriptionDate;

    Nullable<Consult> Consult;
    Nullable<Patient> Patient;

    UInt64 GetId() const noexcept override
    {
      return PrescriptionId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      PrescriptionId = Id;
    }
  };
}
