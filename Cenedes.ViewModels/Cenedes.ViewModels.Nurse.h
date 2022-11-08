#pragma once

#include "Nurse.g.h"

#include <Cenedes.Models.Nurse.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Nurse : NurseT<Nurse>
  {
  public:
    Nurse() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::Nurse m_Nurse;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Nurse : NurseT<Nurse, implementation::Nurse>
  {
  };
}
