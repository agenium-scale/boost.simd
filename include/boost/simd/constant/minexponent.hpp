//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MINEXPONENT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MINEXPONENT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the smallest floating point exponent.

    @par Semantic:

    @code
    T r = Minexponent<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r =  -1022;
    else if T is float
      r = -126;
    @endcode

    @return The Minexponent constant for the proper type
  **/
  template<typename T> T Minexponent();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant minexponent.

      @return The Minexponent constant for the proper type
    **/
    const boost::dispatch::functor<tag::minexponent_> minexponent = {};
  }
} }
#endif

#include <boost/simd/constant/definition/minexponent.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
