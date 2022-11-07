#pragma once

#include "Clinic.g.h"

#include "Cenedes.Models.Clinic.h"

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Clinic : ClinicT<Clinic>
  {
  public:
    Clinic() = default;

    uint64_t ClinicId() const noexcept;
    void ClinicId(const uint64_t clinic_id) noexcept;

    hstring Name() const noexcept;
    void Name(const hstring& name) noexcept;

    hstring Phone() const noexcept;
    void Phone(const hstring& phone) noexcept;

    hstring Address() const noexcept;
    void Address(const hstring& address) noexcept;

    ::Cenedes::Models::Clinic& Model() const noexcept;

  private:
    ::Cenedes::Models::Clinic m_Clinic;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Clinic : ClinicT<Clinic, implementation::Clinic>
  {
  };
}
