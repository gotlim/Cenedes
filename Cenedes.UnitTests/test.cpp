#include "pch.h"

#include <Cenedes.ViewModels.Clinic.h> // Implementation

namespace Cenedes
{
  using namespace ::winrt::Cenedes;
}

TEST(TestCaseName, TestName)
{
  Cenedes::ViewModels::Clinic clinic;
  clinic.Name(L"Denis West");
  EXPECT_EQ(clinic.Name(), winrt::to_hstring(L"Denis West"));

  try
  {
    // auto clinic_impl = clinic.as<Cenedes::ViewModels::implementation::Clinic>();
    // EXPECT_EQ(clinic_impl->Model().Name, winrt::to_hstring(L"Denis West"));
  }
  catch (const winrt::hresult_error& ex)
  {
    [[maybe_unused]] auto error_code = ex.code();
    [[maybe_unused]] auto error_message = ex.message();
  }
}
