#pragma once

namespace Cenedes::Helpers::ViewModels
{
  template <typename Model, typename ViewModel>
  Model& ModelOf(ViewModel&& view_model) noexcept
  {
    return *reinterpret_cast<Model*>(view_model.Model());
  }
}
