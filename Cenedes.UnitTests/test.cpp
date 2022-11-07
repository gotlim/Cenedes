#include "pch.h"

#include <Cenedes.Helpers.h>
#include <Cenedes.ViewModels.Clinic.h> // Implementation


using namespace Cenedes;
using namespace Helpers::Extensions;

using namespace winrt::Cenedes;

TEST(TestCaseName, TestName)
{
  ViewModels::Clinic clinic;
  clinic.Name(L"Denis West");
  EXPECT_EQ(clinic.Name(), winrt::to_hstring(L"Denis West"));

  try
  {
    auto native_model = clinic->*Model<Models::Clinic>();
    EXPECT_EQ(native_model->Name, winrt::to_hstring(L"Denis West"));
    EXPECT_EQ(clinic->*Model<Models::Clinic>()->*&Models::Clinic::Name, winrt::to_hstring(L"Denis West"));

    (clinic->*Model<Models::Clinic>()->*&Models::Clinic::Name) = L"Javier";
    EXPECT_EQ(native_model->Name, winrt::to_hstring(L"Javier"));
  }
  catch (const winrt::hresult_error& ex)
  {
    [[maybe_unused]] auto error_code = ex.code();
    [[maybe_unused]] auto error_message = ex.message();
  }
}
