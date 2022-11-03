#pragma once

#include "Clinic.g.h"

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Clinic : ClinicT<Clinic>
  {
  public:
    Clinic() = default;

    uint64_t ClinicId() const;
    void ClinicId(const uint64_t clinic_id);

    hstring Name() const;
    void Name(const hstring& name);

    hstring Phone() const;
    void Phone(const hstring& phone);

    hstring Address() const;
    void Address(const hstring& address);

  private:
    uint64_t m_ClinicId;
    hstring  m_Name;
    hstring  m_Phone;
    hstring  m_Address;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Clinic : ClinicT<Clinic, implementation::Clinic>
  {
  };
}
