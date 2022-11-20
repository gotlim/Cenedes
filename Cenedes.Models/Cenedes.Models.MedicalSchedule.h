#pragma once

#include "Cenedes.Models.Medic.h"

namespace Cenedes::Models
{
  struct MedicalSchedule : public Entity
  {
    EntityIdType    MedicalScheduleId;
    EntityIdType    MedicId;
    Nullable<Medic> Medic;
    DateTime        BeginDate;
    DateTime        EndDate;
  };
}
