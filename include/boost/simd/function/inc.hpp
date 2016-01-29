//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Increments a value by 1. This operation is not saturated.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = inc(x);
    @endcode

    is equivalent to:

    @code
    T r =  x+T(1);
    @endcode

    @see  oneplus, plus

    @return      a value of the same type as the input.


**/
  template<typename T> auto inc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Increments a value by 1.


      Function object tied to simd::inc

      @see simd::inc
    **/
    const boost::dispatch::functor<tag::inc_> inc = {};
  }
} }
#endif

#include <boost/simd/function/scalar/inc.hpp>
#include <boost/simd/function/simd/inc.hpp>

#endif
