#include "pch.h"
#include "Cenedes.ViewModels.Patient.h"
#if __has_include("Patient.g.cpp")
#include "Patient.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Patient::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_Patient));
  }

  winrt::event_token Patient::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void Patient::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
