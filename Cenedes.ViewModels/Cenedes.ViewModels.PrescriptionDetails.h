#pragma once

#include "PrescriptionDetails.g.h"

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

    winrt::hstring MedicineAmountPerDay() const;
    void MedicineAmountPerDay(const winrt::hstring& medicine_amount_per_day);

    Windows::Foundation::DateTime TimeTakeMedicine() const;
    void TimeTakeMedicine(const Windows::Foundation::DateTime& time_take_medicine);

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
    uint64_t                      m_PrescriptionId;
    winrt::hstring                m_Medicine;
    winrt::hstring                m_MedicineAmountPerDay;
    Windows::Foundation::DateTime m_TimeTakeMedicine;
    winrt::hstring                m_MedicineDetails;
    Windows::Foundation::DateTime m_BeginDate;
    Windows::Foundation::DateTime m_EndDate;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct PrescriptionDetails : PrescriptionDetailsT<PrescriptionDetails, implementation::PrescriptionDetails>
  {
  };
}
