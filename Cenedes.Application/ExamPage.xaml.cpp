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

  void ExamPage::ButtonSave_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
  {
  }

  void ExamPage::ButtonCancel_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
  {
    this->ExamNameTextBox().Text(L"");
    this->ExamPriceTextBox().Text(L"");
  }
}
