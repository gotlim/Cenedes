#pragma once

#include "Cenedes.Models.Exam.h"
#include "Cenedes.Models.Consult.h"

namespace Cenedes::Models
{
  struct ConsultExam : public Entity
  {
    EntityIdType      ConsultExamId;
    EntityIdType      ConsultId;
    Nullable<Consult> Consult;
    EntityIdType      ExamId;
    Nullable<Exam>    Exam;
    DateTime          ExamDate;
    Double            Price;
  };
}
