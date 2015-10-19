//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FIVEO_8_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FIVEO_8_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant fiveo_8.

    @return The Fiveo_8 constant for the proper type
  **/
  template<typename T> T Fiveo_8();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant fiveo_8.

      @return The Fiveo_8 constant for the proper type
    **/
    const boost::dispatch::functor<tag::fiveo_8_> fiveo_8 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/fiveo_8.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
