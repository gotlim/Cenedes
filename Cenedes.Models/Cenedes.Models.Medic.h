#pragma once

#include "Cenedes.Models.Person.h"

namespace Cenedes::Models
{
  struct Medic : Person
  {
    UInt64 MedicId;
  };
}