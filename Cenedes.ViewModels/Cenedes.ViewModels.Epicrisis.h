#pragma once

#include "Epicrisis.g.h"

#include <Cenedes.Models.Epicrisis.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Epicrisis : EpicrisisT<Epicrisis>
  {
  public:
    Epicrisis() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::Epicrisis m_Epicrisis;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Epicrisis : EpicrisisT<Epicrisis, implementation::Epicrisis>
  {
  };
}
