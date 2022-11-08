#include "pch.h"
#include "Cenedes.ViewModels.MedicalAppointment.h"
#if __has_include("MedicalAppointment.g.cpp")
#include "MedicalAppointment.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t MedicalAppointment::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_MedicalAppointment));
  }

  winrt::event_token MedicalAppointment::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void MedicalAppointment::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
