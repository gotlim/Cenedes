#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "HomePage.xaml.h"
#include "ExamPage.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Cenedes::Application::implementation
{
  MainWindow::MainWindow()
  {
    InitializeComponent();

    m_MainAppWindow = GetAppWindowForCurrentWindow();
    this->Title(m_WindowTitle);
  }

  Microsoft::UI::Windowing::AppWindow MainWindow::MainAppWindow()
  {
    return m_MainAppWindow;
  }

  winrt::AppWindow MainWindow::GetAppWindowForCurrentWindow()
  {
    // Get access to IWindowNative
    winrt::Cenedes::Application::MainWindow this_window = *this;
    winrt::com_ptr<IWindowNative> window_native = this_window.as<IWindowNative>();

    //Get the HWND for the XAML Window
    HWND hwnd;
    window_native->get_WindowHandle(&hwnd);

    // Get the WindowId for our window
    winrt::WindowId window_id;
    window_id = winrt::GetWindowIdFromWindow(hwnd);

    // Get the AppWindow for the WindowId
    Microsoft::UI::Windowing::AppWindow app_window = Microsoft::UI::Windowing::AppWindow::GetFromWindowId(window_id);

    return app_window;
  }

  void MainWindow::NavigationView_Loaded(IInspectable const& sender, RoutedEventArgs const& args)
  {
    ContentFrame().Navigate(xaml_typename<Cenedes::Application::HomePage>(), *this);
  }

  void MainWindow::NavigationView_ItemInvoked(IInspectable const& sender, NavigationViewItemInvokedEventArgs const& args)
  {
    if (args.InvokedItemContainer() != nullptr)
    {
      IInspectable tag = args.InvokedItemContainer().Tag();
      hstring tag_value = unbox_value<hstring>(tag);

      if (tag_value == L"Home")
      {
        ContentFrame().Navigate(xaml_typename<Cenedes::Application::HomePage>(), *this);
      }
      else if (tag_value == L"Exam")
      {
        ContentFrame().Navigate(xaml_typename<Cenedes::Application::ExamPage>(), *this);
      }
      else
      {
        ContentFrame().Navigate(xaml_typename<Cenedes::Application::HomePage>(), *this);
      }
    }
  }

  void MainWindow::NavigationView_BackRequested(NavigationView const& sender, NavigationViewBackRequestedEventArgs const& args)
  {
    if (ContentFrame().CanGoBack())
    {
      ContentFrame().GoBack();
    }
  }

  void MainWindow::CenedesIcon_DoubleTapped(IInspectable const& sender, Microsoft::UI::Xaml::Input::DoubleTappedRoutedEventArgs const& args)
  {
    this->MainAppWindow().Destroy();
  }
}
