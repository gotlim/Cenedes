#pragma once

#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.Medic.h"

namespace Cenedes::Models
{
  struct MedicalAppointment : Entity
  {
    UInt64   MedicalAppointmentId;
    UInt64   PatientId;
    UInt64   MedicId;
    DateTime AppointmentDate;
    String   Description;
    Boolean  Attended;

    Nullable<Patient> Patient;
    Nullable<Medic>   Medic;
  };
}
