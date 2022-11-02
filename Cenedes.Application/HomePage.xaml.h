#pragma once

#include "HomePage.g.h"

namespace winrt::Cenedes::Application::implementation
{
  struct HomePage : HomePageT<HomePage>
  {
  public:
    HomePage();
    void OnNavigatedTo(NavigationEventArgs const& args);
    void ButtonClick(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

  private:
    AppWindow m_MainAppWindow{ nullptr };
  };
}

namespace winrt::Cenedes::Application::factory_implementation
{
  struct HomePage : HomePageT<HomePage, implementation::HomePage>
  {
  };
}
