//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_EXPX2C1_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_EXPX2C1_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant expx2c1.

    @return The Expx2c1 constant for the proper type
  **/
  template<typename T> T Expx2c1();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant expx2c1.

      @return The Expx2c1 constant for the proper type
    **/
    const boost::dispatch::functor<tag::expx2c1_> expx2c1 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/expx2c1.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
