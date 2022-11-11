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
  };
}