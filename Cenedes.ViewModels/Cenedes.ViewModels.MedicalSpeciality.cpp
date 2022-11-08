#include "pch.h"
#include "Cenedes.ViewModels.MedicalSpeciality.h"
#if __has_include("MedicalSpeciality.g.cpp")
#include "MedicalSpeciality.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t MedicalSpeciality::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_MedicalSpeciality));
  }

  winrt::event_token MedicalSpeciality::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void MedicalSpeciality::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
