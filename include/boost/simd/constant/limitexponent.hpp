//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LIMITEXPONENT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LIMITEXPONENT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the limit exposant of floating point numbers,  that is Maxexponant+1

    @par Semantic:

    @code
    as_integer<T> r = Limitexponent<T>();
    @endcode

    @code
    if T is double
      r =  1024;
    else if T is float
      r =  128;
    @endcode

    @return The Limitexponent constant for the proper type
  **/
  template<typename T> T Limitexponent();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant limitexponent.

      @return The Limitexponent constant for the proper type
    **/
    const boost::dispatch::functor<tag::limitexponent_> limitexponent = {};
  }
} }
#endif

#include <boost/simd/constant/definition/limitexponent.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
