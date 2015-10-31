//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MASK1FREXP_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MASK1FREXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant mask1frexp,  a utility mask for frexp implementation.

    @par Semantic:

    @code
    as_integer<T> r = Mask1frexp<T>();
    @endcode

    @code
    if T is double
      r =  9218868437227405312l;
    else if T is float
      r =  2139095040;
    @endcode

    @return The Mask1frexp constant for the proper type
  **/
  template<typename T> T Mask1frexp();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant mask1frexp.

      @return The Mask1frexp constant for the proper type
    **/
    const boost::dispatch::functor<tag::mask1frexp_> mask1frexp = {};
  }
} }
#endif

#include <boost/simd/constant/definition/mask1frexp.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
