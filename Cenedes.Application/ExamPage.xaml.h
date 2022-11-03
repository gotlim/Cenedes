#pragma once

#include "ExamPage.g.h"

namespace winrt::Cenedes::Application::implementation
{
  struct ExamPage : ExamPageT<ExamPage>
  {
    ExamPage();
    void ButtonSave_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    void ButtonCancel_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
  };
}

namespace winrt::Cenedes::Application::factory_implementation
{
  struct ExamPage : ExamPageT<ExamPage, implementation::ExamPage>
  {
  };
}
