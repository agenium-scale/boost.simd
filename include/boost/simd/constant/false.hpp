//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FALSE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FALSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant false.

    @return The False constant for the proper type
  **/
  template<typename T> T False();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the constant false.

      @return The False constant for the proper type
    **/
    const boost::dispatch::functor<tag::false_> false_ = {};
  }
} }
#endif

#include <boost/simd/constant/definition/false.hpp>
#include <boost/simd/arch/common/scalar/constant/false.hpp>

#endif
