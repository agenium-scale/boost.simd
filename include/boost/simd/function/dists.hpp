//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DISTS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DISTS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the (saturated) absolute value of the difference of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = dists(x, y);
    @endcode

    is similar to:

    @code
    T r = abss(x-y);
    @endcode

    @par Note

    The result is never negative. For floating, it can of course be Nan.

    @see  ulpdist

    @alias  saturated_dist

    @return      a value of the same type as the input.


**/
  template<typename T> auto dists(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the (saturated) absolute value of the difference of its parameters.


      Function object tied to simd::dists

      @see simd::dists
    **/
    const boost::dispatch::functor<tag::dists_> dists = {};
  }
} }
#endif

#include <boost/simd/function/definition/dists.hpp>
#include <boost/simd/arch/common/scalar/function/dists.hpp>
#include <boost/simd/function/simd/dists.hpp>

#endif
