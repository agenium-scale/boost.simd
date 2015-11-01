//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_EXPX2C2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_EXPX2C2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant expx2c2.

    @return The Expx2c2 constant for the proper type
  **/
  template<typename T> T Expx2c2();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant expx2c2.

      @return The Expx2c2 constant for the proper type
    **/
    const boost::dispatch::functor<tag::expx2c2_> expx2c2 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/expx2c2.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
