#pragma once

#include "ClinicalReport.g.h"

#include <Cenedes.Models.ClinicalReport.h>

namespace winrt::Cenedes::ViewModels::implementation
{
  struct ClinicalReport : ClinicalReportT<ClinicalReport>
  {
  public:
    ClinicalReport() = default;

    uint64_t Model() const noexcept;

    winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
    void PropertyChanged(winrt::event_token const& token);

  private:
    ::Cenedes::Models::ClinicalReport m_ClinicalReport;

    winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_PropertyChanged;
  };
}

namespace winrt::Cenedes::ViewModels::factory_implementation
{
  struct ClinicalReport : ClinicalReportT<ClinicalReport, implementation::ClinicalReport>
  {
  };
}
