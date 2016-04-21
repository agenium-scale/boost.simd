//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_PLUS_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PLUS_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes the saturated sum of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = plus_s(x, y);
    @endcode

    The function coincide with plus for floating point parameters.
    For integers is similar to:

    @code
    T r = (x+y > Valmax) ? Valmax : (x+y < Valmin ? Valmin : x+y);
    @endcode

    @see  plus, oneplus_s, inc_s,  saturated_

    @return      a value of the same type as the input.
  **/
  template<typename T> auto plus_s(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated sum of its parameters.


      Function object tied to simd::plus_s

      @see simd::plus_s
    **/
    const boost::dispatch::functor<tag::plus_s_> plus_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/plus_s.hpp>
#include <boost/simd/function/simd/plus_s.hpp>

#endif
