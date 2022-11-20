#pragma once

#include "Cenedes.Models.Consult.h"
#include "Cenedes.Models.ConsultExam.h"
#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.PatientExam.h"
#include "Cenedes.Models.Prescription.h"

namespace Cenedes::Models
{
  struct Epicrisis : public Entity
  {
    EntityIdType           EpicrisisId;
    String                 EpicrisisCode;
    Nullable<EntityIdType> ConsultId;
    Nullable<Consult>      Consult;
    Nullable<EntityIdType> ConsultExamId;
    Nullable<ConsultExam>  ConsultExam;
    Nullable<EntityIdType> PatientExamId;
    Nullable<PatientExam>  PatientExam;
    Nullable<EntityIdType> PrescriptionId;
    Nullable<Prescription> Prescription;
    EntityIdType           PatientId;
    Nullable<Patient>      Patient;
    EntityIdType           MedicId;
    Nullable<Medic>        Medic;
    String                 Diagnosis;
    DateTime               EpicrisisDate;
  };
}
