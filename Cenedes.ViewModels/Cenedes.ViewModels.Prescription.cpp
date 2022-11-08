#include "pch.h"
#include "Cenedes.ViewModels.Prescription.h"
#if __has_include("Prescription.g.cpp")
#include "Prescription.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Prescription::PrescriptionId() const
  {
    return this->m_Prescription.PrescriptionId;
  }

  void Prescription::PrescriptionId(const uint64_t prescription_id)
  {
    if (this->m_Prescription.PrescriptionId != prescription_id)
    {
      this->m_Prescription.PrescriptionId = prescription_id;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"PrescriptionId" });
    }
  }

  uint64_t Prescription::ConsultId() const
  {
    return this->m_Prescription.ConsultId;
  }

  void Prescription::ConsultId(const uint64_t consult_id)
  {
    if (this->m_Prescription.ConsultId != consult_id)
    {
      this->m_Prescription.ConsultId = consult_id;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"ConsultId" });
    }
  }

  uint64_t Prescription::PatientId() const
  {
    return this->m_Prescription.PatientId;
  }

  void Prescription::PatientId(const uint64_t patient_id)
  {
    if (this->m_Prescription.PatientId != patient_id)
    {
      this->m_Prescription.PatientId = patient_id;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"PatientId" });
    }
  }

  ViewModels::Patient Prescription::Patient() const
  {
    return this->m_Patient;
  }

  void Prescription::Patient(const ViewModels::Patient& patient)
  {
    if (this->m_Patient != patient)
    {
      this->m_Patient = patient;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Patient" });
    }
  }

  Windows::Foundation::DateTime Prescription::PrescriptionDate() const
  {
    return this->m_Prescription.PrescriptionDate;
  }

  void Prescription::PrescriptionDate(const Windows::Foundation::DateTime& prescription_date)
  {
    if (this->m_Prescription.PrescriptionDate != prescription_date)
    {
      this->m_Prescription.PrescriptionDate = prescription_date;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"PrescriptionDate" });
    }
  }

  uint64_t Prescription::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_Prescription));
  }

  winrt::event_token Prescription::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void Prescription::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
