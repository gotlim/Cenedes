#include "pch.h"
#include "Cenedes.ViewModels.Epicrisis.h"
#if __has_include("Epicrisis.g.cpp")
#include "Epicrisis.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Epicrisis::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_Epicrisis));
  }

  winrt::event_token Epicrisis::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void Epicrisis::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
