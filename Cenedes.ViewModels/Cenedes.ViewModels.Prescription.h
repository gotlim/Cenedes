#pragma once

#include "Prescription.g.h"
#include "Cenedes.ViewModels.Patient.h"

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Prescription : PrescriptionT<Prescription>
  {
  public:
    Prescription() = default;

    uint64_t PrescriptionId() const;
    void PrescriptionId(const uint64_t prescription_id);

    uint64_t ConsultId() const;
    void ConsultId(const uint64_t consult_id);

    uint64_t PatientId() const;
    void PatientId(const uint64_t patient_id);

    ViewModels::Patient Patient() const;
    void Patient(const ViewModels::Patient& patient);

    Windows::Foundation::DateTime PrescriptionDate() const;
    void PrescriptionDate(const Windows::Foundation::DateTime& prescription_date);

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& value);
    void PropertyChanged(winrt::event_token const& token);

  private:
    uint64_t                      m_PrescriptionId;
    uint64_t                      m_ConsultId;
    uint64_t                      m_PatientId;
    Cenedes::ViewModels::Patient  m_Patient;
    Windows::Foundation::DateTime m_PrescriptionDate;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Prescription : PrescriptionT<Prescription, implementation::Prescription>
  {
  };
}
