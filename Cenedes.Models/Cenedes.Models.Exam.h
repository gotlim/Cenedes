#pragma once

#include "Cenedes.Models.Entity.h"

namespace Cenedes::Models
{
  struct Exam : Entity
  {
    UInt64           ExamId;
    String           Name;
    Nullable<Double> Price;

    UInt64 GetId() const noexcept override
    {
      return ExamId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      ExamId = Id;
    }
  };
}