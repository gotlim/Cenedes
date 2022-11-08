#include "pch.h"
#include "Cenedes.ViewModels.PatientClinic.h"
#if __has_include("PatientClinic.g.cpp")
#include "PatientClinic.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t PatientClinic::PatientClinicId() const
  {
    return m_PatientClinic.PatientClinicId;
  }

  void PatientClinic::PatientClinicId(const uint64_t patient_clinic_id)
  {
    if (m_PatientClinic.PatientClinicId != patient_clinic_id)
    {
      m_PatientClinic.PatientClinicId = patient_clinic_id;
      m_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"PatientClinicId" });
    }
  }

  uint64_t PatientClinic::PatientId() const
  {
    return m_PatientClinic.PatientId;
  }

  void PatientClinic::PatientId(const uint64_t patient_id)
  {
    if (m_PatientClinic.PatientId != patient_id)
    {
      m_PatientClinic.PatientId = patient_id;
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
    return m_PatientClinic.ClinicId;
  }

  void PatientClinic::ClinicId(const uint64_t clinic_id)
  {
    if (m_PatientClinic.ClinicId != clinic_id)
    {
      m_PatientClinic.ClinicId = clinic_id;
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

  uint64_t PatientClinic::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_PatientClinic));
  }
}
