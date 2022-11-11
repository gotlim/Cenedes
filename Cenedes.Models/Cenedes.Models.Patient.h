#pragma once

#include "Cenedes.Models.Person.h"

namespace Cenedes::Models
{
  struct Patient : Person
  {
    UInt64 PatientId{ 0 };
  };
}
