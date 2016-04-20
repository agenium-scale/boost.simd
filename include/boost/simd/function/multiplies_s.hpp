//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MULTIPLIES_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MULTIPLIES_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the saturated multiplication of the two inputs.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = multiplies_s(x, y);
    @endcode

    The code is similar to:

    @code
    T r = x*y
    @endcode

    But is saturated for integer types

    @return      a value of the same type as the input.


**/
  template<typename T> auto multiplies_s(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated multiplication of the two inputs.


      Function object tied to simd::multiplies_s

      @see simd::multiplies_s
    **/
    const boost::dispatch::functor<tag::multiplies_s_> multiplies_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/multiplies_s.hpp>
#include <boost/simd/function/simd/multiplies_s.hpp>

#endif
