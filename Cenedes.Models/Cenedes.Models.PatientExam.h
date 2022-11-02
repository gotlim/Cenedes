#pragma once

#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.Exam.h"

namespace Cenedes::Models
{
  struct PatientExam : Entity
  {
    UInt64            PatientExamId;
    UInt64            PatientId;
    UInt64            ExamId;
    Nullable<Double>  Price;
    Nullable<Patient> Patient;
    Nullable<Exam>    Exam;

    UInt64 GetId() const noexcept override
    {
      return PatientExamId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      PatientExamId = Id;
    }
  };
}