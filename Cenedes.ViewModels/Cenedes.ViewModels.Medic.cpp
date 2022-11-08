#include "pch.h"
#include "Cenedes.ViewModels.Medic.h"
#if __has_include("Medic.g.cpp")
#include "Medic.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Medic::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_Medic));
  }

  winrt::event_token Medic::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void Medic::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
