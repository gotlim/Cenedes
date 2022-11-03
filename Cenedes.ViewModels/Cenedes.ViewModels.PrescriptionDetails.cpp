#include "pch.h"
#include "Cenedes.ViewModels.PrescriptionDetails.h"
#if __has_include("PrescriptionDetails.g.cpp")
#include "PrescriptionDetails.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t PrescriptionDetails::PrescriptionId() const
  {
    return this->m_PrescriptionId;
  }

  void PrescriptionDetails::PrescriptionId(const uint64_t prescription_id)
  {
    if (this->m_PrescriptionId != prescription_id)
    {
      this->m_PrescriptionId = prescription_id;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"PrescriptionId" });
    }
  }

  winrt::hstring PrescriptionDetails::Medicine() const
  {
    return this->m_Medicine;
  }

  void PrescriptionDetails::Medicine(const winrt::hstring& medicine)
  {
    if (this->m_Medicine != medicine)
    {
      this->m_Medicine = medicine;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Medicine" });
    }
  }

  winrt::hstring PrescriptionDetails::MedicineAmountPerDay() const
  {
    return this->m_MedicineAmountPerDay;
  }

  void PrescriptionDetails::MedicineAmountPerDay(const winrt::hstring& medicine_amount_per_day)
  {
    if (this->m_MedicineAmountPerDay != medicine_amount_per_day)
    {
      this->m_MedicineAmountPerDay = medicine_amount_per_day;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"MedicineAmountPerDay" });
    }
  }

  Windows::Foundation::DateTime PrescriptionDetails::TimeTakeMedicine() const
  {
    return this->m_TimeTakeMedicine;
  }

  void PrescriptionDetails::TimeTakeMedicine(const Windows::Foundation::DateTime& time_take_medicine)
  {
    if (this->m_TimeTakeMedicine != time_take_medicine)
    {
      this->m_TimeTakeMedicine = time_take_medicine;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"MedicineAmountPerDay" });
    }
  }

  winrt::hstring PrescriptionDetails::MedicineDetails() const
  {
    return this->m_MedicineDetails;
  }

  void PrescriptionDetails::MedicineDetails(const winrt::hstring medicine_details)
  {
    if (this->m_MedicineDetails != medicine_details)
    {
      this->m_MedicineDetails = medicine_details;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"MedicineDetails" });
    }
  }

  Windows::Foundation::DateTime PrescriptionDetails::BeginDate() const
  {
    return this->m_BeginDate;
  }

  void PrescriptionDetails::BeginDate(const Windows::Foundation::DateTime begin_date)
  {
    if (this->m_BeginDate != begin_date)
    {
      this->m_BeginDate = begin_date;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"BeginDate" });
    }
  }

  Windows::Foundation::DateTime PrescriptionDetails::EndDate() const
  {
    return this->m_EndDate;
  }

  void PrescriptionDetails::EndDate(const Windows::Foundation::DateTime end_date)
  {
    if (this->m_EndDate != end_date)
    {
      this->m_EndDate = end_date;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"EndDate" });
    }
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
