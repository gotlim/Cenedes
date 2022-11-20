#pragma once

#include "Cenedes.Models.Entity.h"
#include "Cenedes.Models.Sex.h"

namespace Cenedes::Models
{
  struct Person : public Entity
  {
    EntityIdType     PersonId;
    String           Carnet;
    String           Name;
    String           LastName;
    UInt16           Age;
    DateTime         Birthday;
    Sex              Sex;
    String           Address;
    Nullable<String> Phone;
  };
}
