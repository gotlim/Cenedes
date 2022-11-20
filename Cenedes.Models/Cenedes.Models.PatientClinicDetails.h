#pragma once

#include "Cenedes.Models.PatientClinic.h"

namespace Cenedes::Models
{
  struct PatientClinicDetails : public Entity
  {
    EntityIdType            PatientClinicDetailId;
    EntityIdType            PatientClinicId;
    Nullable<PatientClinic> PatientClinic;
    Nullable<String>        MedicName;
    String                  Description;
  };
}
