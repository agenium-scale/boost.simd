//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXLOG10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXLOG10_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant MaxLog10 used in logarithm/exponential computations
    log10(x) return inf if x is greater than Maxlog10 (overflow)

    @par Semantic:

    @code
    T r = Maxlog10<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 308.2547155599167;
    else if T is float
      r = 38.23080825805664;

    @endcode


**/
  template<typename T> T Maxlog10();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant Maxlog10 used in logarithm/exponential computations

      Generate the  constant maxlog10.

      @return The Maxlog10 constant for the proper type
    **/
    const boost::dispatch::functor<tag::maxlog10_> maxlog10 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/maxlog10.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
