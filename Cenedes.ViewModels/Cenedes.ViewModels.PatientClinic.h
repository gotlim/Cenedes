#pragma once

#include "PatientClinic.g.h"

#include "Cenedes.ViewModels.Patient.h"
#include "Cenedes.ViewModels.Clinic.h"

#include "Cenedes.Models.PatientClinic.h"

using namespace Cenedes;

namespace winrt::Cenedes::ViewModels::implementation
{
  struct PatientClinic : PatientClinicT<PatientClinic>
  {
  public:
    PatientClinic() = default;

    uint64_t PatientClinicId() const;
    void PatientClinicId(const uint64_t patient_clinic_id);

    uint64_t PatientId() const;
    void PatientId(const uint64_t patient_id);

    ViewModels::Patient Patient() const;
    void Patient(const ViewModels::Patient& patient);

    uint64_t ClinicId() const;
    void ClinicId(const uint64_t clinic_id);

    ViewModels::Clinic Clinic() const;
    void Clinic(const ViewModels::Clinic& clinic);

    Models::PatientClinic& Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    Models::PatientClinic m_PatientClinic;
    ViewModels::Patient   m_Patient;
    ViewModels::Clinic    m_Clinic;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct PatientClinic : PatientClinicT<PatientClinic, implementation::PatientClinic>
  {
  };
}
