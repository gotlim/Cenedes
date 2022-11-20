#pragma once

#include "Cenedes.Models.Patient.h"
#include "Cenedes.Models.Exam.h"

namespace Cenedes::Models
{
  struct PatientExam : public Entity
  {
    EntityIdType      PatientExamId;
    EntityIdType      PatientId;
    Nullable<Patient> Patient;
    EntityIdType      ExamId;
    Nullable<Exam>    Exam;
    Double            Price;
  };
}
