#pragma once

#include "Cenedes.Models.Entity.h"

namespace Cenedes::Models
{
  struct Exam : Entity
  {
    UInt64           ExamId;
    String           Name;
    Nullable<Double> Price;
  };
}