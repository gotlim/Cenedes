#include "pch.h"
#include "Cenedes.ViewModels.PatientExam.h"
#if __has_include("PatientExam.g.cpp")
#include "PatientExam.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t PatientExam::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_PatientExam));
  }

  winrt::event_token PatientExam::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void PatientExam::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
