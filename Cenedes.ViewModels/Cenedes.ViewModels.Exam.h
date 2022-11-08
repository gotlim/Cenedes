#pragma once

#include "Exam.g.h"

#include <Cenedes.Models.Exam.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Exam : ExamT<Exam>
  {
  public:
    Exam() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::Exam m_Exam;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Exam : ExamT<Exam, implementation::Exam>
  {
  };
}
