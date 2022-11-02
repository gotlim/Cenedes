#pragma once

#include "Cenedes.Models.Exam.h"
#include "Cenedes.Models.Consult.h"

namespace Cenedes::Models
{
  struct ConsultExam : Entity
  {
    UInt64           ConsultExamId;
    UInt64           ConsultId;
    UInt64           ExamId;
    DateTime         ExamDate;
    Nullable<Double> Price;

    UInt64 GetId() const noexcept override
    {
      return ConsultExamId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      ConsultExamId = Id;
    }
  };
}
