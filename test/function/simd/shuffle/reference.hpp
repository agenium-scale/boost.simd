//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef REFERENCE_HPP_INCLUDED
#define REFERENCE_HPP_INCLUDED

#include <array>
#include <cstdint>

template<int... I, typename T>
std::array<typename T::value_type,sizeof...(I)> unary_ref(T const& a)
{
  using type = typename T::value_type;

  std::array<type,sizeof...(I)>
  ref = {{ ((I == -1) ? type(0) : a[static_cast<std::size_t>(I)])... }};

  return ref;
}

template<int... I, typename T>
std::array<typename T::value_type,sizeof...(I)> binary_ref(T const& a, T const& b)
{
  using type = typename T::value_type;
  static const auto s = sizeof...(I);

  std::array<type,sizeof...(I)>
  ref = {{ ( (I == -1) ? type(0) :
                        ( I<s ? a[static_cast<std::size_t>(I)]
                              : b[static_cast<std::size_t>(I)-s]
                        )
          )...
        }};

  return ref;
}

#endif
