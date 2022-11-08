#include "pch.h"
#include "Cenedes.ViewModels.PatientClinicDetails.h"
#if __has_include("PatientClinicDetails.g.cpp")
#include "PatientClinicDetails.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t PatientClinicDetails::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_PatientClinicDetails));
  }

  winrt::event_token PatientClinicDetails::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void PatientClinicDetails::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
