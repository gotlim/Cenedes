#include "pch.h"

#include "Cenedes.Models.Entity.h"

namespace Cenedes::Models
{
  Entity::Entity() noexcept
    : CreatedDate{ DateTime::clock::now().time_since_epoch() }
    , ModifiedDate{ std::nullopt }
    , DeletedDate{ std::nullopt }
    , IsEdit{ false }
    , IsDelete{ false }
  {
  }
};
