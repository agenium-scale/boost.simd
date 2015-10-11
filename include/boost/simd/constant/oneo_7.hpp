//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_ONEO_7_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_ONEO_7_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant oneo_7.

    @return The Oneo_7 constant for the proper type
  **/
  template<typename T> T Oneo_7();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant oneo_7.

      @return The Oneo_7 constant for the proper type
    **/
    const boost::dispatch::functor<tag::oneo_7_> oneo_7 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/oneo_7.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
