#pragma once

#include "Cenedes.Models.Person.h"

namespace Cenedes::Models
{
  struct Nurse : public Person
  {
    EntityIdType NurseId;
  };
}