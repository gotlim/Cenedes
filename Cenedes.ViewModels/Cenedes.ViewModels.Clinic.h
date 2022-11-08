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

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::Clinic m_Clinic;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Clinic : ClinicT<Clinic, implementation::Clinic>
  {
  };
}
