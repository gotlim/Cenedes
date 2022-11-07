#pragma once

#include "Patient.g.h"

#include "Cenedes.Models.Patient.h"

using namespace Cenedes;

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Patient : PatientT<Patient>
  {
  public:
    Patient() = default;
    uint64_t Model() const noexcept;

  private:
    Models::Patient m_Patient;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Patient : PatientT<Patient, implementation::Patient>
  {
  };
}
