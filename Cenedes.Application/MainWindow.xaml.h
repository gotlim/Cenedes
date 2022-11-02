#pragma once

#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime

#include "MainWindow.g.h"

#pragma pop_macro("GetCurrentTime")

namespace winrt::Cenedes::Application::implementation
{
  struct MainWindow : MainWindowT<MainWindow>
  {
  public:
    MainWindow();
    Microsoft::UI::Windowing::AppWindow MainAppWindow();

    void NavigationView_Loaded(IInspectable const& sender, RoutedEventArgs const& args);
    void NavigationView_ItemInvoked(IInspectable const& sender, NavigationViewItemInvokedEventArgs const& args);
    void NavigationView_BackRequested(NavigationView const& sender, NavigationViewBackRequestedEventArgs const& args);
    void CenedesIcon_DoubleTapped(IInspectable const& sender, Microsoft::UI::Xaml::Input::DoubleTappedRoutedEventArgs const& args);

  private:
    winrt::AppWindow GetAppWindowForCurrentWindow();

    winrt::AppWindow m_MainAppWindow{ nullptr };
    hstring m_WindowTitle = L"WinUI Desktop C++ App";
  };
}

namespace winrt::Cenedes::Application::factory_implementation
{
  struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
  {
  };
}
