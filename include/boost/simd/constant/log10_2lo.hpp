//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

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

    Generate the constant log10_2lo.

    @return The Log10_2lo constant for the proper type
  **/
  template<typename T> T Log10_2lo();

  namespace functional
  {
    /*!
      @ingroup group-constant
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
