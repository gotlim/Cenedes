#include "pch.h"
#include "Cenedes.ViewModels.Patient.h"
#if __has_include("Patient.g.cpp")
#include "Patient.g.cpp"
#endif

#include "Cenedes.Helpers.String.h"

using namespace Cenedes;
using namespace Cenedes::Helpers;

namespace winrt::Cenedes::ViewModels::implementation
{
  Windows::Foundation::IInspectable Patient::Model() const noexcept
  {
    return {};
  }
}
