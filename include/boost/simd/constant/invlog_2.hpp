//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INVLOG_2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INVLOG_2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant invlog_2.

    @return The Invlog_2 constant for the proper type
  **/
  template<typename T> T Invlog_2();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant invlog_2.

      @return The Invlog_2 constant for the proper type
    **/
    const boost::dispatch::functor<tag::invlog_2_> invlog_2 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/invlog_2.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
