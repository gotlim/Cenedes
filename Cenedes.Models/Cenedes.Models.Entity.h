#pragma once

#include "Cenedes.Models.EntityBase.h"

namespace Cenedes::Models
{
  struct Entity abstract : EntityBase
  {
    DateTime            CreatedDate;
    Nullable<DateTime>  ModifiedDate;
    Nullable<DateTime>  DeletedDate;
    Boolean             IsEdit;
    Boolean             IsDelete;
  };
}
