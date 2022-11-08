#include "pch.h"
#include "Cenedes.ViewModels.Exam.h"
#if __has_include("Exam.g.cpp")
#include "Exam.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Exam::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_Exam));
  }

  winrt::event_token Exam::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void Exam::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
