#pragma once

#include "Cenedes.Models.Prescription.h"

namespace Cenedes::Models
{
  struct PrescriptionDetails : Entity
  {
    UInt64             PrescriptionDetailId;
    UInt64             PrescriptionId;
    String             Medicine;
    Nullable<UInt32>   MedicineAmountPerDay;
    Nullable<TimeSpan> TimeTakeMedicine;
    String             MedicineDetails;
    DateTime           BeginDate;
    DateTime           EndDate;

    Nullable<Prescription> Prescription;
  };
}
