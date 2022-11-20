#pragma once

#include "Cenedes.Models.Exports.Api.h"
#include "Cenedes.Models.Types.h"

namespace Cenedes::Models
{
  struct CENEDES_MODELS_API Entity
  {
    Entity() noexcept;
    virtual ~Entity() noexcept = default;

    DateTime            CreatedDate;
    Nullable<DateTime>  ModifiedDate;
    Nullable<DateTime>  DeletedDate;
    Boolean             IsEdit;
    Boolean             IsDelete;
  };
}
