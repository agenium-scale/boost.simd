//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_THOUSAND_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_THOUSAND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant thousand.

    @return The Thousand constant for the proper type
  **/
  template<typename T> T Thousand();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant thousand.

      @return The Thousand constant for the proper type
    **/
    const boost::dispatch::functor<tag::thousand_> thousand = {};
  }
} }
#endif

#include <boost/simd/constant/definition/thousand.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
