#pragma once

#include "Consult.g.h"

#include <Cenedes.Models.Consult.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Consult : ConsultT<Consult>
  {
  public:
    Consult() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::Consult m_Consult;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Consult : ConsultT<Consult, implementation::Consult>
  {
  };
}
