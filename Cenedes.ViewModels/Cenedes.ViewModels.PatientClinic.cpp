#include "pch.h"
#include "Cenedes.ViewModels.PatientClinic.h"
#if __has_include("PatientClinic.g.cpp")
#include "PatientClinic.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t PatientClinic::PatientClinicId() const
  {
    return this->m_PatientClinicId;
  }

  void PatientClinic::PatientClinicId(const uint64_t patient_clinic_id)
  {
    if (this->m_PatientClinicId != patient_clinic_id)
    {
      this->m_PatientClinicId = patient_clinic_id;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"PatientClinicId" });
    }
  }

  uint64_t PatientClinic::PatientId() const
  {
    return this->m_PatientId;
  }

  void PatientClinic::PatientId(const uint64_t patient_id)
  {
    if (this->m_PatientId != patient_id)
    {
      this->m_PatientId = patient_id;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"PatientId" });
    }
  }

  ViewModels::Patient PatientClinic::Patient() const
  {
    return this->m_Patient;
  }

  void PatientClinic::Patient(const ViewModels::Patient& patient)
  {
    if (this->m_Patient != patient)
    {
      this->m_Patient = patient;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Patient" });
    }
  }

  uint64_t PatientClinic::ClinicId() const
  {
    return this->m_ClinicId;
  }

  void PatientClinic::ClinicId(const uint64_t clinic_id)
  {
    if (this->m_ClinicId != clinic_id)
    {
      this->m_ClinicId = clinic_id;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"ClinicId" });
    }
  }

  ViewModels::Clinic PatientClinic::Clinic() const
  {
    return this->m_Clinic;
  }

  void PatientClinic::Clinic(const ViewModels::Clinic& clinic)
  {
    if (this->m_Clinic != clinic)
    {
      this->m_Clinic = clinic;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Clinic" });
    }
  }

  winrt::event_token PatientClinic::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void PatientClinic::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
