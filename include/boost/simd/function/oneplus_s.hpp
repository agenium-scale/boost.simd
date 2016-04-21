//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ONEPLUS_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ONEPLUS_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Returns the entry plus one, saturated in the entry type.
    If @c x is not @ref Nan, @c oneplus_s(x) is greater or equal to x.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = oneplus_s(x);
    @endcode

    The code is similar to:

    @code
    T r = (x == Valmax) ? x : inc(x)
    @endcode

    @see inc, dec_s, saturated

    @par Alias

    inc_s

    @return a value of the same type as the input.


**/
  template<typename T> auto oneplus_s(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Returns the entry plus one, saturated in the entry type.
      If @c x is not @ref Nan, @c oneplus_s(x) is greater or equal to x.


      Function object tied to simd::oneplus_s

      @see simd::oneplus_s
    **/
    const boost::dispatch::functor<tag::oneplus_s_> oneplus_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/oneplus_s.hpp>
#include <boost/simd/function/simd/oneplus_s.hpp>

#endif
