#pragma once

#include "Cenedes.Models.Consult.h"

namespace Cenedes::Models
{
  struct Prescription : public Entity
  {
    EntityIdType      PrescriptionId;
    EntityIdType      ConsultId;
    Nullable<Consult> Consult;
    EntityIdType      PatientId;
    Nullable<Patient> Patient;
    DateTime          PrescriptionDate;
  };
}
