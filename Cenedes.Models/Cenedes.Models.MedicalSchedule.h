#pragma once

#include "Cenedes.Models.Medic.h"

namespace Cenedes::Models
{
  struct MedicalSchedule : Entity
  {
    UInt64   MedicalScheduleId;
    UInt64   MedicId;
    DateTime BeginDate;
    DateTime EndDate;
  };
}
