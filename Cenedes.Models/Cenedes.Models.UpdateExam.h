#pragma once

#include "Cenedes.Models.Types.h"

namespace Cenedes::Models
{
  struct UpdateExam
  {
    PatchValue<String> Name;
    PatchValue<Double> Price;
  };
}
