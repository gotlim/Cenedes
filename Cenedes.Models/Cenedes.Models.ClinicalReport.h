#pragma once

#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.Nurse.h"

namespace Cenedes::Models
{
  struct ClinicalReport : public Entity
  {
    EntityIdType      ClinicalReportId;
    EntityIdType      PacientId;
    Nullable<Patient> Patient;
    EntityIdType      NurseId;
    Nullable<Nurse>   Nurse;
    String            Report;
  };
}
