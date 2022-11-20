#pragma once

#include "Cenedes.Models.Prescription.h"

namespace Cenedes::Models
{
  struct PrescriptionDetails : Entity
  {
    EntityIdType           PrescriptionDetailId;
    EntityIdType           PrescriptionId;
    Nullable<Prescription> Prescription;
    String                 Medicine;
    Nullable<UInt32>       MedicineAmountPerDay;
    Nullable<TimeSpan>     TimeTakeMedicine;
    String                 MedicineDetails;
    DateTime               BeginDate;
    DateTime               EndDate;
  };
}
