#include "pch.h"
#include "HomePage.xaml.h"
#if __has_include("HomePage.g.cpp")
#include "HomePage.g.cpp"
#endif

#include <filesystem>

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

  fire_and_forget HomePage::ButtonClick(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
  {
    Microsoft::UI::Xaml::Controls::ContentDialog content_dialog;
    content_dialog.XamlRoot(this->XamlRoot());
    content_dialog.Title(box_value(L"Título del Diálogo"));
    content_dialog.Content(box_value(L"Contenido del Diálogo"));
    content_dialog.PrimaryButtonText(L"Centrar La Ventana");
    content_dialog.SecondaryButtonText(L"Boton Secundario");
    content_dialog.CloseButtonText(L"Boton de Cierre");

    content_dialog.PrimaryButtonClick([&](const auto&, const auto&)
      {
        // Center MainWindow

        int32_t screen_x = ::GetSystemMetrics(SM_CXSCREEN);
        int32_t screen_y = ::GetSystemMetrics(SM_CYSCREEN);
        m_MainAppWindow.Move({
          .X = screen_x / 2 - m_MainAppWindow.Size().Width / 2,
          .Y = screen_y / 2 - m_MainAppWindow.Size().Height / 2
          });
      });

    auto dialog_result = co_await content_dialog.ShowAsync();
  }
}
