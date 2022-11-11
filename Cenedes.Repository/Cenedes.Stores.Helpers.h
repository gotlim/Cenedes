#pragma once

#include "Cenedes.SQLite.h"
#include "Cenedes.Helpers.PatchValue.h"

namespace Cenedes::Stores
{
  template<typename ...Type>
  inline void BindIfHasValue(SQLite::SQLiteStatement& statement, Type &&...value)
  {
    int32_t argument_index = 0;

    ([&]
      {
        if constexpr (requires { typename std::remove_cvref_t<Type>::patch_value; })
        {
          statement.Bind(++argument_index, *value);
        }
        else
        {
          statement.Bind(++argument_index, std::forward<Type>(value));
        }
      }(), ...);
  }

  template<typename ...Type>
  inline bool ModelHasUpdate(Type&&...value)
  {
    return (static_cast<bool>(value) || ...);
  }
}
