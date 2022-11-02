#include "pch.h"
#include "HomePage.xaml.h"
#if __has_include("HomePage.g.cpp")
#include "HomePage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Cenedes::Application::implementation
{
  HomePage::HomePage()
  {
    InitializeComponent();
  }

  void HomePage::OnNavigatedTo(NavigationEventArgs const& args)
  {
    Window window = args.Parameter().as<Window>();
    MainWindow main_window = window.as<MainWindow>();
    m_MainAppWindow = main_window.MainAppWindow();
  }

  void HomePage::ButtonClick(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
  {
  }
}
