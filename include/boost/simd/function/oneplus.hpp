//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ONEPLUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ONEPLUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Returns the entry plus one, saturated in the entry type.
    If @c x is not @ref Nan, @c oneplus(x) is greater or equal to x.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = oneplus(x);
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
  template<typename T> auto oneplus(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Returns the entry plus one, saturated in the entry type.
      If @c x is not @ref Nan, @c oneplus(x) is greater or equal to x.


      Function object tied to simd::oneplus

      @see simd::oneplus
    **/
    const boost::dispatch::functor<tag::oneplus_> oneplus = {};
  }
} }
#endif

#include <boost/simd/function/definition/oneplus.hpp>
#include <boost/simd/arch/common/generic/function/oneplus.hpp>
#include <boost/simd/function/simd/oneplus.hpp>

#endif
