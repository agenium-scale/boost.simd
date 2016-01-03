//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOG10_EHI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOG10_EHI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant log10_ehi.This constant is coupled with Log10_elo and is
    used in the float logarithms computations
    We have double(log10_ehi<float>())+double(Log10_elo<float>()) == Log_10(e)

    @par Semantic:

    @code
    T r = log10_ehi<T>();
    @endcode


**/
  template<typename T> T Log10_ehi();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant log10_ehi.This constant is coupled with Log10_elo and is
      used in the float logarithms computations
      We have double(log10_ehi<float>())+double(Log10_elo<float>()) == Log_10(e)

      Generate the  constant log10_ehi.

      @return The Log10_ehi constant for the proper type
    **/
    const boost::dispatch::functor<tag::log10_ehi_> log10_ehi = {};
  }
} }
#endif

#include <boost/simd/constant/definition/log10_ehi.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
