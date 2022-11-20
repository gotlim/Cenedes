#pragma once

#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.Medic.h"

namespace Cenedes::Models
{
  struct MedicalAppointment : public Entity
  {
    EntityIdType      MedicalAppointmentId;
    EntityIdType      PatientId;
    Nullable<Patient> Patient;
    EntityIdType      MedicId;
    Nullable<Medic>   Medic;
    DateTime          AppointmentDate;
    String            Description;
    Boolean           Attended;
  };
}
