#include "pch.h"

#include <Cenedes.Helpers.h>
#include <Cenedes.ViewModels.Clinic.h>
#include <Cenedes.ViewModels.Prescription.h>

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
    /*
     
     
     .*
     ->*
     Tipo Class::*member
     Return (Class::*)(Arguments)


    */

    //auto native_model = operator->*(clinic, Model<Models::Clinic>());
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

TEST(TestCaseName, ViewModelPropertyEvent)
{
  winrt::init_apartment(winrt::apartment_type::single_threaded);

  try
  {
    winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs args{ L"PropertyName" };

    winrt::hstring last_property_changed;

    ViewModels::Prescription prescription;
    prescription.PropertyChanged([&](winrt::IInspectable const&, winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs const& args)
      {
        last_property_changed = args.PropertyName();
      });


    prescription.PrescriptionDate(winrt::DateTime::clock::now());
    EXPECT_EQ(last_property_changed, winrt::to_hstring(L"PrescriptionDate"));
  }
  catch (const winrt::hresult_error& ex)
  {
    [[maybe_unused]] auto error_code = ex.code();
    [[maybe_unused]] auto error_message = ex.message();

    std::clog << "Error Code: " << error_code << std::endl;
    std::wclog << L"Error Message: " << error_message << std::endl;
  }
}