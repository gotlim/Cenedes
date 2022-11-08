#pragma once

#include "PatientExam.g.h"

#include <Cenedes.Models.PatientExam.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct PatientExam : PatientExamT<PatientExam>
  {
  public:
    PatientExam() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::PatientExam m_PatientExam;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct PatientExam : PatientExamT<PatientExam, implementation::PatientExam>
  {
  };
}
