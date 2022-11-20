#pragma once

#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.Clinic.h"

namespace Cenedes::Models
{
  struct PatientClinic : public Entity
  {
    EntityIdType       PatientClinicId;
    EntityIdType       PatientId;
    Nullable<Patient>  Patient;
    EntityIdType       ClinicId;
    Nullable<Clinic>   Clinic;
    Nullable<DateTime> ApproximateDate;
  };
}
