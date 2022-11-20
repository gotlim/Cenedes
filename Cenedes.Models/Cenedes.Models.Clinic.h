#pragma once

#include "Cenedes.Models.Entity.h"

namespace Cenedes::Models
{
  struct Clinic : public Entity
  {
    EntityIdType     ClinicId;
    String           Name;
    Nullable<String> Phone;
    Nullable<String> Address;
  };
}
