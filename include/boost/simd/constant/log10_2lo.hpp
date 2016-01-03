//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOG10_2LO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOG10_2LO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant log10_2lo.This constant is coupled with Log10_2hi and is
    used in the float logarithms computations
    We have abs( double(log10_2lo<float>())+double(Log10_2hi<float>()) - Log10(2.0))) < 3e-11

    @par Semantic:

    @code
    T r = log10_2lo<T>();
    @endcode


**/
  template<typename T> T Log10_2lo();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant log10_2lo.This constant is coupled with Log10_2hi and is
      used in the float logarithms computations
      We have abs( double(log10_2lo<float>())+double(Log10_2hi<float>()) - Log10(2.0))) < 3e-11

      Generate the  constant log10_2lo.

      @return The Log10_2lo constant for the proper type
    **/
    const boost::dispatch::functor<tag::log10_2lo_> log10_2lo = {};
  }
} }
#endif

#include <boost/simd/constant/definition/log10_2lo.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
