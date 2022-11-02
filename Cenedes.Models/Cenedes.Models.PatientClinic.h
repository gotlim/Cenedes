#pragma once

#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.Clinic.h"

namespace Cenedes::Models
{
  struct PatientClinic : Entity
  {
    UInt64             PatientClinicId;
    UInt64             PatientId;
    UInt64             ClinicId;
    Nullable<DateTime> ApproximateDate;
    Nullable<Patient>  Patient;
    Nullable<Clinic>   Clinic;

    UInt64 GetId() const noexcept override
    {
      return PatientClinicId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      PatientClinicId = Id;
    }
  };
}