#pragma once

#include <utility>
#include <concepts>

namespace Cenedes::Helpers
{
  template<typename Type>
    requires std::is_default_constructible_v<Type> and std::is_copy_assignable_v<Type>
  class PatchValue
  {
  public:
    using value_type = Type;

    PatchValue() noexcept : m_Value{ }, m_HasValue{ false }
    {
    }

    PatchValue(const Type& value) noexcept : m_Value{ value }, m_HasValue{ true }
    {
    }

    PatchValue& operator=(const Type& value) noexcept
    {
      m_Value = value;
      m_HasValue = true;
      return *this;
    }

    template<typename Self>
    const Type& operator*(this Self&& self)
    {
      return self.m_Value;
    }

    template<typename Self>
    decltype(auto) operator->(this Self&& self)
    {
      if constexpr (requires { self.m_Value.operator->(); })
      {
        return (self.m_Value);
      }
      else
      {
        return &self.m_Value;
      }
    }

    operator bool() const noexcept
    {
      return m_HasValue;
    }

    bool HasValue() const noexcept
    {
      return m_HasValue;
    }

    void Reset()
    {
      m_Value = Type();
      m_HasValue = false;
    }

  private:
    Type m_Value;
    bool m_HasValue;
  };
}
