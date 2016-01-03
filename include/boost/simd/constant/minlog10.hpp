//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MINLOG10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MINLOG10_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant Minlog10 used in logarithm/exponential computations
    nt2::log10(x) return  0 if x is less than Minlog10 (underflow)

    @par Semantic:

    @code
    T r = Minlog10<T>();
    @endcode

    is similar to:

    @code
    if T is double
    r = -308.2547155599167;
    else if T is float
    r = -37.89999771118164;
    @endcode


**/
  template<typename T> T Minlog10();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant Minlog10 used in logarithm/exponential computations

      Generate the  constant minlog10.

      @return The Minlog10 constant for the proper type
    **/
    const boost::dispatch::functor<tag::minlog10_> minlog10 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/minlog10.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
