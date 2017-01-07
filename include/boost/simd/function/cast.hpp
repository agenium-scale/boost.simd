//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CAST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CAST_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
/*!
      @ingroup group-bitwise
      Function object function implementing cast capabilities

      Performs a "static_cast" like of its parameters into an arbitrary
      type @c Target.

      On pack  entries cast preserves the cardinal. For instance :
      `cast<float>(pack<double, N>(1.0))` will produce a `pack<float, N>` full of `1.0f`.
      and `cast<float>(1.0)` is equivalent to `static_cast<float>(1.0)`.

      @par Semantic

      For any value @c x of type @c T and for type @c Target which is a scalar type.



      @code
      Target r = cast<Target>(x);
      @endcode

      @tparam Target @c Target type to cast toward
      @param  @c x Value to cast

      @return A value of type @c Target which is cast to @c x.
    **/
    Target cast(Value const& x);
  }
} }
#endif

#include <boost/simd/function/scalar/cast.hpp>
#include <boost/simd/function/simd/cast.hpp>

#endif
