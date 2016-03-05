//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MINLOG2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MINLOG2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant Minlog2 used in logarithm/exponential computations
    nt2::log2(x) return  0 if x is less than Minlog2 (underflow)

    @par Semantic:

    @code
    T r = Minlog2<T>();
    @endcode

    is similar to:

    @code
    if T is double
    r = -1023.0;
    else if T is float
    r = -127.0;

    @endcode


**/
  template<typename T> T Minlog2();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant Minlog2 used in logarithm/exponential computations

      Generate the  constant minlog2.

      @return The Minlog2 constant for the proper type
    **/
    const boost::dispatch::functor<tag::minlog2_> minlog2 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/minlog2.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
