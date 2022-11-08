#include "pch.h"
#include "Cenedes.ViewModels.Nurse.h"
#if __has_include("Nurse.g.cpp")
#include "Nurse.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Nurse::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_Nurse));
  }

  winrt::event_token Nurse::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void Nurse::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
