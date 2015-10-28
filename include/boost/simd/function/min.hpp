//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the smallest of its parameter.

    @par semantic:
    For any given value @c x and @c y of type @c T:

    @code
    T r = min(x, y);
    @endcode

    is similar to:

    @code
    T r =  if (x < y) ? x : y;
    @endcode


    @return a value of the same type as the input.


**/
  template<typename T> auto min(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the smallest of its parameter.


      Function object tied to simd::min

      @see simd::min
    **/
    const boost::dispatch::functor<tag::min_> min = {};
  }
} }
#endif

#include <boost/simd/function/definition/min.hpp>
#include <boost/simd/arch/common/scalar/function/min.hpp>
//#include <boost/simd/arch/common/function/simd/min.hpp>

#endif
