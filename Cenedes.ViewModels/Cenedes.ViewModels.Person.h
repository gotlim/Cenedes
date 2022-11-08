#pragma once

#include "Person.g.h"

#include <Cenedes.Models.Person.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct Person : PersonT<Person>
  {
  public:
    Person() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::Person m_Person;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct Person : PersonT<Person, implementation::Person>
  {
  };
}
