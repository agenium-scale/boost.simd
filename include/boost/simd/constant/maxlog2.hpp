//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXLOG2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXLOG2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant MaxLog2 used in logarithm/exponential computations
    log2(x) return inf if x is greater than Maxlog2 (overflow)

    @par Semantic:

    @code
    T r = Maxlog2<T>();
    @endcode

    is similar to:

    @code
    if T is double
    r = 1023.0;
    else if T is float
    r = 127.0;

    @endcode


**/
  template<typename T> T Maxlog2();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant Maxlog2 used in logarithm/exponential computations

      Generate the  constant maxlog2.

      @return The Maxlog2 constant for the proper type
    **/
    const boost::dispatch::functor<tag::maxlog2_> maxlog2 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/maxlog2.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
