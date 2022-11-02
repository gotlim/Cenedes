#pragma once

#include "Cenedes.Models.Consult.h"
#include "Cenedes.Models.ConsultExam.h"
#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.PatientExam.h"
#include "Cenedes.Models.Prescription.h"

namespace Cenedes::Models
{
  struct Epicrisis : Entity
  {
    UInt64           EpicrisisId;
    String           EpicrisisCode;
    Nullable<UInt64> ConsultId;
    Nullable<UInt64> ConsultExamId;
    Nullable<UInt64> PatientExamId;
    Nullable<UInt64> PrescriptionId;
    UInt64           PatientId;
    UInt64           MedicId;
    String           Diagnosis;
    DateTime         EpicrisisDate;

    Nullable<Consult>      Consult;
    Nullable<ConsultExam>  ConsultExam;
    Nullable<PatientExam>  PatientExam;
    Nullable<Prescription> Prescription;
    Nullable<Patient>      Patient;
    Nullable<Medic>        Medic;

    UInt64 GetId() const noexcept override
    {
      return EpicrisisId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      EpicrisisId = Id;
    }
  };
}