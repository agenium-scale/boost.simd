//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TWOTOMNMBO_3_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TWOTOMNMBO_3_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant twotomnmbo_3.

    @return The Twotomnmbo_3 constant for the proper type
  **/
  template<typename T> T Twotomnmbo_3();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant twotomnmbo_3.

      @return The Twotomnmbo_3 constant for the proper type
    **/
    const boost::dispatch::functor<tag::twotomnmbo_3_> twotomnmbo_3 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/twotomnmbo_3.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
