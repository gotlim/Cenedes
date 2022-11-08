#pragma once

#include "MedicalSchedule.g.h"

#include <Cenedes.Models.MedicalSchedule.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct MedicalSchedule : MedicalScheduleT<MedicalSchedule>
  {
  public:
    MedicalSchedule() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::MedicalSchedule m_MedicalSchedule;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct MedicalSchedule : MedicalScheduleT<MedicalSchedule, implementation::MedicalSchedule>
  {
  };
}
