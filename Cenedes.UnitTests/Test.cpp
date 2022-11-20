#include "pch.h"

#include "Cenedes.Helpers.h"
#include "Cenedes.ViewModels.Clinic.h"
#include "Cenedes.ViewModels.Prescription.h"

using namespace Cenedes;
using namespace Helpers::Extensions;
using namespace Helpers::ViewModels;

using namespace winrt::Cenedes;

TEST(ViewModels, CastToModels)
{
  ViewModels::Clinic clinic;
  clinic.Name(L"Denis West");
  EXPECT_EQ(clinic.Name(), winrt::to_hstring(L"Denis West"));

  try
  {
    auto&& native_model = ModelOf<Models::Clinic>(clinic);

    EXPECT_EQ(native_model.Name, winrt::to_hstring(L"Denis West"));
    EXPECT_EQ(ModelOf<Models::Clinic>(clinic).Name, winrt::to_hstring(L"Denis West"));

    ModelOf<Models::Clinic>(clinic).Name = L"Javier";
    EXPECT_EQ(native_model.Name, winrt::to_hstring(L"Javier"));
  }
  catch (const winrt::hresult_error& ex)
  {
    [[maybe_unused]] auto error_code = ex.code();
    [[maybe_unused]] auto error_message = ex.message();
  }
}

TEST(ViewModels, ViewModelPropertyEvent)
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
