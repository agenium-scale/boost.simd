//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXEXPONENT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXEXPONENT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the maximum exposant of floating point numbers

    @par Semantic:

    @code
    as_integer<T> r = Maxexponent<T>();
    @endcode

    @code
    if T is double
      r =  1023;
    else if T is float
      r =  127;
    @endcode

    @return The Maxexponent constant for the proper type
  **/
  template<typename T> T Maxexponent();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant maxexponent.

      @return The Maxexponent constant for the proper type
    **/
    const boost::dispatch::functor<tag::maxexponent_> maxexponent = {};
  }
} }
#endif

#include <boost/simd/constant/definition/maxexponent.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
