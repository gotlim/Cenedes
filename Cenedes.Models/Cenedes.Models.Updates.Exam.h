#pragma once

#include <Cenedes.Helpers.Types.h>
#include <Cenedes.Helpers.PatchValue.h>

namespace Cenedes::Models::Updates
{
  struct Exam
  {
    Helpers::PatchValue<String> Name;
    Helpers::PatchValue<Nullable<Double>> Price;
  };
}
