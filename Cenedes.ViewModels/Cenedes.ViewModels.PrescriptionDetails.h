#pragma once

#include "PrescriptionDetails.g.h"

#include <Cenedes.Models.PrescriptionDetails.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct PrescriptionDetails : PrescriptionDetailsT<PrescriptionDetails>
  {
  public:
    PrescriptionDetails() = default;

    uint64_t PrescriptionId() const;
    void PrescriptionId(const uint64_t prescription_id);

    winrt::hstring Medicine() const;
    void Medicine(const winrt::hstring& medicine);

    winrt::IReference<uint32_t> MedicineAmountPerDay() const;
    void MedicineAmountPerDay(const Windows::Foundation::IReference<uint32_t>& medicine_amount_per_day);

    winrt::IReference<winrt::TimeSpan> TimeTakeMedicine() const;
    void TimeTakeMedicine(const winrt::IReference<winrt::TimeSpan>& time_take_medicine);

    winrt::hstring MedicineDetails() const;
    void MedicineDetails(const winrt::hstring medicine_details);

    Windows::Foundation::DateTime BeginDate() const;
    void BeginDate(const Windows::Foundation::DateTime begin_date);

    Windows::Foundation::DateTime EndDate() const;
    void EndDate(const Windows::Foundation::DateTime end_date);

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::PrescriptionDetails m_PrescriptionDetails;
    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct PrescriptionDetails : PrescriptionDetailsT<PrescriptionDetails, implementation::PrescriptionDetails>
  {
  };
}
