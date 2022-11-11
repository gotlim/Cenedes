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
  };
}
