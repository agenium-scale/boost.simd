//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_EIGHT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_EIGHT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant eight.

    @return The Eight constant for the proper type
  **/
  template<typename T> T Eight();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant eight.

      @return The Eight constant for the proper type
    **/
    const boost::dispatch::functor<tag::eight_> eight = {};
  }
} }
#endif

#include <boost/simd/constant/definition/eight.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
