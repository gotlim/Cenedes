#include "pch.h"
#include "Cenedes.ViewModels.ConsultExam.h"
#if __has_include("ConsultExam.g.cpp")
#include "ConsultExam.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t ConsultExam::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_ConsultExam));
  }

  winrt::event_token ConsultExam::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void ConsultExam::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
