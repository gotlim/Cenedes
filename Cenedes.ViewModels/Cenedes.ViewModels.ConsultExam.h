#pragma once

#include "ConsultExam.g.h"

#include <Cenedes.Models.ConsultExam.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct ConsultExam : ConsultExamT<ConsultExam>
  {
  public:
    ConsultExam() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::ConsultExam m_ConsultExam;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct ConsultExam : ConsultExamT<ConsultExam, implementation::ConsultExam>
  {
  };
}
