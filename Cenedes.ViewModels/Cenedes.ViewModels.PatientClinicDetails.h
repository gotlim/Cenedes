#pragma once

#include "PatientClinicDetails.g.h"

#include <Cenedes.Models.PatientClinicDetails.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct PatientClinicDetails : PatientClinicDetailsT<PatientClinicDetails>
  {
  public:
    PatientClinicDetails() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::PatientClinicDetails m_PatientClinicDetails;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct PatientClinicDetails : PatientClinicDetailsT<PatientClinicDetails, implementation::PatientClinicDetails>
  {
  };
}
