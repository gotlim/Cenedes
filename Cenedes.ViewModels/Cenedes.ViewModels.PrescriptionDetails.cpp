#include "pch.h"
#include "Cenedes.ViewModels.PrescriptionDetails.h"
#if __has_include("PrescriptionDetails.g.cpp")
#include "PrescriptionDetails.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t PrescriptionDetails::PrescriptionId() const
  {
    return this->m_PrescriptionDetails.PrescriptionId;
  }

  void PrescriptionDetails::PrescriptionId(const uint64_t prescription_id)
  {
    if (this->m_PrescriptionDetails.PrescriptionId != prescription_id)
    {
      this->m_PrescriptionDetails.PrescriptionId = prescription_id;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"PrescriptionId" });
    }
  }

  winrt::hstring PrescriptionDetails::Medicine() const
  {
    return this->m_PrescriptionDetails.Medicine;
  }

  void PrescriptionDetails::Medicine(const winrt::hstring& medicine)
  {
    if (this->m_PrescriptionDetails.Medicine != medicine)
    {
      this->m_PrescriptionDetails.Medicine = medicine;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Medicine" });
    }
  }

  Windows::Foundation::IReference<uint32_t> PrescriptionDetails::MedicineAmountPerDay() const
  {
    return this->m_PrescriptionDetails.MedicineAmountPerDay;
  }

  void PrescriptionDetails::MedicineAmountPerDay(const Windows::Foundation::IReference<uint32_t>& medicine_amount_per_day)
  {
    if (this->m_PrescriptionDetails.MedicineAmountPerDay != static_cast<std::optional<uint32_t>>(medicine_amount_per_day))
    {
      this->m_PrescriptionDetails.MedicineAmountPerDay = medicine_amount_per_day;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"MedicineAmountPerDay" });
    }
  }

  winrt::IReference<winrt::TimeSpan> PrescriptionDetails::TimeTakeMedicine() const
  {
    return this->m_PrescriptionDetails.TimeTakeMedicine;
  }

  void PrescriptionDetails::TimeTakeMedicine(const winrt::IReference<winrt::TimeSpan>& time_take_medicine)
  {
    if (this->m_PrescriptionDetails.TimeTakeMedicine != static_cast<std::optional<winrt::TimeSpan>>(time_take_medicine))
    {
      this->m_PrescriptionDetails.TimeTakeMedicine = time_take_medicine;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"MedicineAmountPerDay" });
    }
  }

  winrt::hstring PrescriptionDetails::MedicineDetails() const
  {
    return this->m_PrescriptionDetails.MedicineDetails;
  }

  void PrescriptionDetails::MedicineDetails(const winrt::hstring medicine_details)
  {
    if (this->m_PrescriptionDetails.MedicineDetails != medicine_details)
    {
      this->m_PrescriptionDetails.MedicineDetails = medicine_details;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"MedicineDetails" });
    }
  }

  Windows::Foundation::DateTime PrescriptionDetails::BeginDate() const
  {
    return this->m_PrescriptionDetails.BeginDate;
  }

  void PrescriptionDetails::BeginDate(const Windows::Foundation::DateTime begin_date)
  {
    if (this->m_PrescriptionDetails.BeginDate != begin_date)
    {
      this->m_PrescriptionDetails.BeginDate = begin_date;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"BeginDate" });
    }
  }

  Windows::Foundation::DateTime PrescriptionDetails::EndDate() const
  {
    return this->m_PrescriptionDetails.EndDate;
  }

  void PrescriptionDetails::EndDate(const Windows::Foundation::DateTime end_date)
  {
    if (this->m_PrescriptionDetails.EndDate != end_date)
    {
      this->m_PrescriptionDetails.EndDate = end_date;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"EndDate" });
    }
  }

  uint64_t PrescriptionDetails::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_PrescriptionDetails));
  }

  winrt::event_token PrescriptionDetails::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void PrescriptionDetails::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
