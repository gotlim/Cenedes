#include "pch.h"
#include "Cenedes.ViewModels.ClinicalReport.h"
#if __has_include("ClinicalReport.g.cpp")
#include "ClinicalReport.g.cpp"
#endif

namespace winrt::Cenedes::ViewModels::implementation
{
  uint64_t ClinicalReport::Model() const noexcept
  {
    return reinterpret_cast<uint64_t>(std::addressof(m_ClinicalReport));
  }
}
