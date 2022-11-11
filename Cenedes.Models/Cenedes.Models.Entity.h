#pragma once

#include "Cenedes.Models.EntityBase.h"

namespace Cenedes::Models
{
  struct Entity : EntityBase
  {
    DateTime            CreatedDate;
    Nullable<DateTime>  ModifiedDate;
    Nullable<DateTime>  DeletedDate;
    Boolean             IsEdit;
    Boolean             IsDelete;
  };
}
