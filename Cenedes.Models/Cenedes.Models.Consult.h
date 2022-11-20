#pragma once

#include "Cenedes.Models.Medic.h"
#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.ClinicalReport.h"
#include "Cenedes.Models.MedicalAppointment.h"

namespace Cenedes::Models
{
  struct Consult : public Entity
  {
    EntityIdType                 ConsultId;
    EntityIdType                 PacientId;
    Nullable<Patient>            Patient;
    EntityIdType                 MedicId;
    Nullable<Medic>              Medic;
    Nullable<EntityIdType>       ClinicalReportId;
    Nullable<ClinicalReport>     ClinicalReport;
    Nullable<EntityIdType>       MedicalAppointmentId;
    Nullable<MedicalAppointment> MedicalAppointment;
    Double                       Price;
    String                       Symptom;
    String                       Diagnosis;
    DateTime                     VisitDate;
  };
}
