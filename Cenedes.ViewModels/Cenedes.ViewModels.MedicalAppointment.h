#pragma once

#include "MedicalAppointment.g.h"

#include <Cenedes.Models.MedicalAppointment.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct MedicalAppointment : MedicalAppointmentT<MedicalAppointment>
  {
  public:
    MedicalAppointment() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::MedicalAppointment m_MedicalAppointment;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct MedicalAppointment : MedicalAppointmentT<MedicalAppointment, implementation::MedicalAppointment>
  {
  };
}
