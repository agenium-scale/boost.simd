//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIST_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the absolute value of the difference of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = dist(x, y);
    @endcode

    is similar to:

    @code
    T r = abs(x-y);
    @endcode

    @par Note

    The result can be negative for signed integers as @ref abs(@ref Valmin) is @ref Valmin.
    To avoid the problem you can use the saturated version dists.


    @see  dists, ulpdist


    @return      a value of the same type as the input.


**/
  template<typename T> auto dist(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the absolute value of the difference of its parameters.


      Function object tied to simd::dist

      @see simd::dist
    **/
    const boost::dispatch::functor<tag::dist_> dist = {};
  }
} }
#endif

#include <boost/simd/function/definition/dist.hpp>
#include <boost/simd/arch/common/scalar/function/dist.hpp>
#include <boost/simd/function/simd/dist.hpp>

#endif
