#include "pch.h"
#include "ExamPage.xaml.h"
#if __has_include("ExamPage.g.cpp")
#include "ExamPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Cenedes::Application::implementation
{
  ExamPage::ExamPage()
  {
    InitializeComponent();
  }

  void ExamPage::OnNavigatedTo(NavigationEventArgs const& args)
  {
    Window window = args.Parameter().as<Window>();
    MainWindow main_window = window.as<MainWindow>();
    m_MainAppWindow = main_window.MainAppWindow();
  }

  IAsyncAction ExamPage::ButtonSave_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
  {
    try
    {
      Microsoft::UI::Xaml::Controls::ContentDialog content_dialog;
      content_dialog.XamlRoot(this->XamlRoot());
      content_dialog.Title(box_value(L"Título del Diálogo"));
      content_dialog.Content(box_value(L"Contenido del Diálogo"));
      content_dialog.PrimaryButtonText(L"Boton Principal");
      content_dialog.SecondaryButtonText(L"Boton Secundario");
      content_dialog.CloseButtonText(L"Boton de Cierre");
      auto dialog_result = co_await content_dialog.ShowAsync();
    }
    catch (winrt::hresult_error const& ex)
    {
      winrt::hresult hr = ex.code();
      winrt::hstring message = ex.message();
    }
  }

  void ExamPage::ButtonCancel_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
  {
    this->ExamNameTextBox().Text(L"");
    this->ExamPriceTextBox().Text(L"");
  }
}
