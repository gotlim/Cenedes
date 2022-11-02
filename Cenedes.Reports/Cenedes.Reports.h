#pragma once

#include "Report.g.h"

namespace winrt::Cenedes::Reports::implementation
{
  struct Report : ReportT<Report>
  {
    Report() = default;
  };
}

namespace winrt::Cenedes::Reports::factory_implementation
{
  struct Report : ReportT<Report, implementation::Report>
  {
  };
}
