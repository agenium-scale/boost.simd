//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INC_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INC_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Returns the entry plus one, saturated in the entry type.
    If @c x is not @ref Nan, @c inc_s(x) is greater or equal to x.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = inc_s(x);
    @endcode

    The code is similar to:

    @code
    T r = (x == Valmax) ? x : inc(x)
    @endcode

    @see inc, plus, adds

    @par Alias

    incs

    @return a value of the same type as the input.


**/
  template<typename T> auto inc_s(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Returns the entry plus one, saturated in the entry type.
      If @c x is not @ref Nan, @c inc_s(x) is greater or equal to x.


      Function object tied to simd::inc_s

      @see simd::inc_s
    **/
    const boost::dispatch::functor<tag::inc_s_> inc_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/inc_s.hpp>
#include <boost/simd/function/simd/inc_s.hpp>

#endif
