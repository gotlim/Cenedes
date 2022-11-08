#pragma once

#include "Medic.g.h"

#include <Cenedes.Models.Medic.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Medic : MedicT<Medic>
  {
  public:
    Medic() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::Medic m_Medic;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Medic : MedicT<Medic, implementation::Medic>
  {
  };
}
