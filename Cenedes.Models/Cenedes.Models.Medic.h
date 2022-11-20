#pragma once

#include "Cenedes.Models.Person.h"

namespace Cenedes::Models
{
  struct Medic : public Person
  {
    EntityIdType MedicId;
  };
}