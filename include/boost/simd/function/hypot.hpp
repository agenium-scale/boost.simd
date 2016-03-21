//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_HYPOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_HYPOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes \f$(x^2 + y^2)^{1/2}\f$

    @par semantic:
    For any given value @c x,  @c y of floating type @c T:

    @code
    T r = hypot(x, y);
    @endcode

    The code is similar to:

    @code
    T r = sqrt(sqr(x)+sqr(y));
    @endcode

    @par Note

    - Provision are made to avoid overflow as possible and to compute
    @c hypot accurately.

    - If these considerations can be put aside, use the decorator fast_.

    @par Decorators

    std_,  fast_ for floating entries

    @return      a value of the same type as the input.


**/
  template<typename T> auto hypot(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes \f$(x^2 + y^2)^{1/2}\f$


      Function object tied to simd::hypot

      @see simd::hypot
    **/
    const boost::dispatch::functor<tag::hypot_> hypot = {};
  }
} }
#endif

#include <boost/simd/function/scalar/hypot.hpp>
#include <boost/simd/function/scalar/hypot.hpp>
#include <boost/simd/function/simd/hypot.hpp>

#endif
