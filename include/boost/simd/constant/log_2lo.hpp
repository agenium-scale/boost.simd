//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOG_2LO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOG_2LO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant Log_2lo.This constant is coupled with Log2_hi and is
    used in the float logarithms computations
    We have double(Log_2lo<float>())+double(Log2_hi<float>()) == Log_2<double>()

    @par Semantic:

    @code
    T r = log_2lo<T>();
    @endcode


**/
  template<typename T> T Log_2lo();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant Log_2lo.This constant is coupled with Log2_hi and is
      used in the float logarithms computations
      We have double(Log_2lo<float>())+double(Log2_hi<float>()) == Log_2<double>()

      Generate the  constant log_2lo.

      @return The Log_2lo constant for the proper type
    **/
    const boost::dispatch::functor<tag::log_2lo_> log_2lo = {};
  }
} }
#endif

#include <boost/simd/constant/definition/log_2lo.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
