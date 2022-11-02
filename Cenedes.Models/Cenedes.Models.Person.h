#pragma once

#include "Cenedes.Models.Entity.h"
#include "Cenedes.Models.Sex.h"

namespace Cenedes::Models
{
  struct Person abstract : Entity
  {
    UInt64   PersonId;
    String   Carnet;
    String   Name;
    String   LastName;
    UInt16   Age;
    DateTime Birthday;
    Sex      Sex;
    String   Address;
    Nullable<String> Phone;

    UInt64 GetId() const noexcept override
    {
      return PersonId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      PersonId = Id;
    }
  };
}
