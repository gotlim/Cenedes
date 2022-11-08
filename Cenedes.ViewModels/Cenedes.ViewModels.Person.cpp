#include "pch.h"
#include "Cenedes.ViewModels.Person.h"
#if __has_include("Person.g.cpp")
#include "Person.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t Person::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_Person));
  }

  winrt::event_token Person::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
  {
    return this->m_PropertyChanged.add(handler);
  }

  void Person::PropertyChanged(winrt::event_token const& token)
  {
    this->m_PropertyChanged.remove(token);
  }
}
