#pragma once

#include "ExamPage.g.h"

namespace winrt::Cenedes::Application::implementation
{
  struct ExamPage : ExamPageT<ExamPage>
  {
  public:
    ExamPage();
    void OnNavigatedTo(NavigationEventArgs const& args);
    IAsyncAction ButtonSave_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    void ButtonCancel_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

  private:
    AppWindow m_MainAppWindow{ nullptr };
  };
}

namespace winrt::Cenedes::Application::factory_implementation
{
  struct ExamPage : ExamPageT<ExamPage, implementation::ExamPage>
  {
  };
}
