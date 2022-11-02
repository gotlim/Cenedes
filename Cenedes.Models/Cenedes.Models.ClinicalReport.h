#pragma once

#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.Nurse.h"

namespace Cenedes::Models
{
  struct ClinicalReport : Entity
  {
    UInt64 ClinicalReportId;
    UInt64 PacientId;
    UInt64 NurseId;
    String Report;

    Nullable<Patient> Patient;
    Nullable<Nurse> Nurse;

    UInt64 GetId() const noexcept override
    {
      return ClinicalReportId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      ClinicalReportId = Id;
    }
  };
}