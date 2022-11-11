#pragma once

#include "Cenedes.Helpers.Concepts.h"
#include "Cenedes.Helpers.PatchValue.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <optional>

namespace Cenedes::Helpers::Entity
{
  inline constexpr const uint_fast64_t DefaultId = static_cast<uint_fast64_t>(-1);
}

#define SQLiteSet(ColumnName, ...)  __VA_ARGS__##" Set " __VA_ARGS__###ColumnName __VA_ARGS__##" = ? "
