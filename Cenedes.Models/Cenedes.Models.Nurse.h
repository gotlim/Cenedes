#pragma once

#include "Cenedes.Models.Person.h"

namespace Cenedes::Models
{
  struct Nurse : Person
  {
    UInt64 NurseId;
  };
}