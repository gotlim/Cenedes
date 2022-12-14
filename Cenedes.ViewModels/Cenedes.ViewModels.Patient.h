#pragma once

#include "Patient.g.h"

#include <Cenedes.Models.Patient.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Patient : PatientT<Patient>
  {
  public:
    Patient() = default;
    
    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::Patient m_Patient;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Patient : PatientT<Patient, implementation::Patient>
  {
  };
}
