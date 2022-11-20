#pragma once

#include <concepts>
#include <utility>
#include <functional>
#include <tuple>

#include "Cenedes.Helpers.Concepts.h"

namespace Cenedes::Helpers::Extensions
{
  template<typename Object, typename Function>
    requires std::is_invocable_v<Function, Object>
  inline constexpr auto operator->*(Object&& object, Function&& function)
    noexcept(noexcept(std::invoke(function, std::forward<Object>(object))))
    -> decltype(std::invoke(function, std::forward<Object>(object)))
  {
    return std::invoke(function, std::forward<Object>(object));
  }

  template<typename Object, typename Field>
  inline constexpr Field&& operator->*(Object&& object, Field Object::* field)
  {
    if constexpr (std::is_pointer_v<Object>)
    {
      return (object->*field);
    }
    else
    {
      return (object.*field);
    }
  }

  //template<typename Object, typename Return, typename ...Arguments>
  //inline constexpr auto operator->*(Object&& object, Return(Object::* method)(Arguments...))
  //{
  //  return std::bind_front(method, object);
  //}

  //template<typename Function, typename ...Arguments>
  //  requires std::is_invocable_v<Function, Arguments...>
  //inline constexpr auto&& operator->*(Function&& function, std::tuple<Arguments...>&& values)
  //{
  //  return[&] <size_t ...Index> (std::index_sequence<Index...>) -> auto&&
  //  {
  //    return std::invoke(function, std::forward<Arguments>(std::get<Index>(values))...);
  //  } (std::index_sequence_for<Arguments...>{  });
  //}

  //template <typename ...Arguments>
  //inline auto Args(Arguments &&...arguments) noexcept
  //{
  //  return std::forward_as_tuple(std::forward<Arguments>(arguments)...);
  //}

  namespace PropertyDetails
  {
  }

  template <typename NativeModel>
  inline auto Model() noexcept
  {
    return[] <typename WinRTClass> (WinRTClass && winrt_class) noexcept -> NativeModel*
    {
      if constexpr (requires { reinterpret_cast<NativeModel*>(winrt_class.Model()); })
      {
        return reinterpret_cast<NativeModel*>(winrt_class.Model());
      }
      else if constexpr (requires { reinterpret_cast<NativeModel*>(winrt_class->Model()); })
      {
        return reinterpret_cast<NativeModel*>(winrt_class->Model());
      }
      else
      {
        static_assert(Cenedes::Helpers::Concepts::AlwaysFalse<NativeModel>);
      }
    };
  }
}
