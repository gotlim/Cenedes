#pragma once

#include "Cenedes.Models.Medic.h"
#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.ClinicalReport.h"
#include "Cenedes.Models.MedicalAppointment.h"

namespace Cenedes::Models
{
  struct Consult : Entity
  {
    UInt64           ConsultId;
    UInt64           PacientId;
    UInt64           MedicId;
    Nullable<UInt64> ClinicalReportId;
    Nullable<UInt64> MedicalAppointmentId;
    Double           Price;
    String           Symptom;
    String           Diagnosis;
    DateTime         VisitDate;

    Nullable<Medic> Medic;
    Nullable<Patient> Patient;
    Nullable<ClinicalReport> ClinicalReport;
    Nullable<MedicalAppointment> MedicalAppointment;
  };
}
