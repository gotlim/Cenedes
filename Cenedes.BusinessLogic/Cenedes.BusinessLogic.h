#pragma once

#include "BusinessLogic.g.h"

namespace winrt::Cenedes::BusinessLogic::implementation
{
  struct BusinessLogic : BusinessLogicT<BusinessLogic>
  {
    BusinessLogic() = default;
  };
}

namespace winrt::Cenedes::BusinessLogic::factory_implementation
{
  struct BusinessLogic : BusinessLogicT<BusinessLogic, implementation::BusinessLogic>
  {
  };
}
