#include "pch.h"
#include "Cenedes.ViewModels.Clinic.h"
#if __has_include("Clinic.g.cpp")
#include "Clinic.g.cpp"
#endif

#include "Cenedes.Helpers.String.h"

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Clinic::ClinicId() const noexcept
  {
    return m_Clinic.ClinicId;
  }

  void Clinic::ClinicId(const uint64_t clinic_id) noexcept
  {
    m_Clinic.ClinicId = clinic_id;
  }

  hstring Clinic::Name() const noexcept
  {
    return m_Clinic.Name;
  }

  void Clinic::Name(const hstring& name) noexcept
  {
    m_Clinic.Name = name;
  }

  hstring Clinic::Phone() const noexcept
  {
    return m_Clinic.Phone.value_or(::Cenedes::Helpers::String::Empty);
  }

  void Clinic::Phone(const hstring& phone) noexcept
  {
    m_Clinic.Phone = phone;
  }

  hstring Clinic::Address() const noexcept
  {
    return m_Clinic.Address.value_or(::Cenedes::Helpers::String::Empty);
  }

  void Clinic::Address(const hstring& address) noexcept
  {
    m_Clinic.Address = address;
  }

  uint64_t Clinic::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_Clinic));
  }

  winrt::event_token Clinic::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void Clinic::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
