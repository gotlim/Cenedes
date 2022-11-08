#pragma once

#include "MedicMedicialSpeciality.g.h"

#include <Cenedes.Models.MedicMedicialSpeciality.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct MedicMedicialSpeciality : MedicMedicialSpecialityT<MedicMedicialSpeciality>
  {
  public:
    MedicMedicialSpeciality() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::MedicMedicialSpeciality m_MedicMedicialSpeciality;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct MedicMedicialSpeciality : MedicMedicialSpecialityT<MedicMedicialSpeciality, implementation::MedicMedicialSpeciality>
  {
  };
}
