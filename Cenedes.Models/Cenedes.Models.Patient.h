#pragma once

#include "Cenedes.Models.Person.h"

namespace Cenedes::Models
{
  struct Patient : public Person
  {
    EntityIdType PatientId;
  };
}
