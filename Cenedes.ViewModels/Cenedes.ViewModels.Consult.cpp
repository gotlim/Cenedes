#include "pch.h"
#include "Cenedes.ViewModels.Consult.h"
#if __has_include("Consult.g.cpp")
#include "Consult.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Consult::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_Consult));
  }

  winrt::event_token Consult::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void Consult::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
