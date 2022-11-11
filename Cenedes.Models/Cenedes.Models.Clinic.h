#pragma once

#include "Cenedes.Models.Entity.h"

namespace Cenedes::Models
{
  struct Clinic : Entity
  {
    UInt64           ClinicId;
    String           Name;
    Nullable<String> Phone;
    Nullable<String> Address;
  };
}
