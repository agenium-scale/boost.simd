//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TEN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant ten.

    @return The Ten constant for the proper type
  **/
  template<typename T> T Ten();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant ten.

      @return The Ten constant for the proper type
    **/
    const boost::dispatch::functor<tag::ten_> ten = {};
  }
} }
#endif

#include <boost/simd/constant/definition/ten.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
