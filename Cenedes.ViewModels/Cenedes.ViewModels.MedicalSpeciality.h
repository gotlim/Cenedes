#pragma once

#include "MedicalSpeciality.g.h"

#include <Cenedes.Models.MedicalSpeciality.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct MedicalSpeciality : MedicalSpecialityT<MedicalSpeciality>
  {
  public:
    MedicalSpeciality() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::MedicalSpeciality m_MedicalSpeciality;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct MedicalSpeciality : MedicalSpecialityT<MedicalSpeciality, implementation::MedicalSpeciality>
  {
  };
}
