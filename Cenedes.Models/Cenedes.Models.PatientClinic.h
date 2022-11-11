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
  };
}