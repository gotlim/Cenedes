#pragma once

#include "Cenedes.SQLite.h"
#include "Cenedes.Helpers.PatchValue.h"

namespace Cenedes::Stores
{
  namespace Details
  {
    template<typename Type>
    void PatchBindArgument(int32_t& argument_index, SQLite::SQLiteStatement& statement, Type&& value)
    {
      statement.Bind(++argument_index, value);
    }

    template<typename Type>
    void PatchBindArgument(int32_t& argument_index, SQLite::SQLiteStatement& statement, Helpers::PatchValue<Type>& value)
    {
      if (value)
      {
        statement.Bind(++argument_index, *value);
      }
    }
  }

  template<typename ...Type>
  inline void BindIfHasValue(SQLite::SQLiteStatement& statement, Type &&...value)
  {
    int32_t argument_index = 0;
    (Details::PatchBindArgument(argument_index, statement, std::forward<Type>(value)), ...);
  }
}