#include "pch.h"
#include "Cenedes.ViewModels.MedicMedicialSpeciality.h"
#if __has_include("MedicMedicialSpeciality.g.cpp")
#include "MedicMedicialSpeciality.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t MedicMedicialSpeciality::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_MedicMedicialSpeciality));
  }

  winrt::event_token MedicMedicialSpeciality::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void MedicMedicialSpeciality::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
