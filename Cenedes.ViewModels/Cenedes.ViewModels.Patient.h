#pragma once

#include "Patient.g.h"

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Patient : PatientT<Patient>
  {
    Patient() = default;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Patient : PatientT<Patient, implementation::Patient>
  {
  };
}
