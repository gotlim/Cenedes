#include "pch.h"
#include "Cenedes.ViewModels.MedicalSchedule.h"
#if __has_include("MedicalSchedule.g.cpp")
#include "MedicalSchedule.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t MedicalSchedule::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_MedicalSchedule));
  }

  winrt::event_token MedicalSchedule::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void MedicalSchedule::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
