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

    UInt64 GetId() const noexcept override
    {
      return MedicalAppointmentId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      MedicalAppointmentId = Id;
    }
  };
}
