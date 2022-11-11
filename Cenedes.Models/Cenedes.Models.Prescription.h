#pragma once

#include "Cenedes.Models.Consult.h"

namespace Cenedes::Models
{
  struct Prescription : Entity
  {
    UInt64   PrescriptionId{ 0 };
    UInt64   ConsultId{ 0 };
    UInt64   PatientId{ 0 };
    DateTime PrescriptionDate;

    Nullable<Consult> Consult;
    Nullable<Patient> Patient;
  };
}
