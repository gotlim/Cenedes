#pragma once

#include "Cenedes.Models.Entity.h"

namespace Cenedes::Models
{
  struct Exam : public Entity
  {
    EntityIdType ExamId;
    String       Name;
    Double       Price;
  };
}
