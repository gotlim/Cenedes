#include "pch.h"
#include "Cenedes.ViewModels.Clinic.h"
#if __has_include("Clinic.g.cpp")
#include "Clinic.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Clinic::ClinicId() const
  {
    return m_ClinicId;
  }

  void Clinic::ClinicId(const uint64_t clinic_id)
  {
    m_ClinicId = clinic_id;
  }

  hstring Clinic::Name() const
  {
    return m_Name;
  }

  void Clinic::Name(const hstring& name)
  {
    m_Name = name;
  }

  hstring Clinic::Phone() const
  {
    return m_Phone;
  }

  void Clinic::Phone(const hstring& phone)
  {
    m_Phone = phone;
  }

  hstring Clinic::Address() const
  {
    return m_Address;
  }

  void Clinic::Address(const hstring& address)
  {
    m_Address = address;
  }
}
