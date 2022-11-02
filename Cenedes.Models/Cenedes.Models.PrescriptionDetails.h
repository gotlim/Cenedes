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

    UInt64 GetId() const noexcept override
    {
      return PrescriptionDetailId;
    }

    void SetId(const UInt64 Id) noexcept override
    {
      PrescriptionDetailId = Id;
    }
  };
}
