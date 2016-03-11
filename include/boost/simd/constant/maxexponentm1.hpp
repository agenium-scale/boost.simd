//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXEXPONENTM1_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXEXPONENTM1_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the maximum exposant of floating point numbers minus one

    @par Semantic:

    @code
    as_integer<T> r = Maxexponentm1<T>();
    @endcode

    @code
    if T is double
      r =  1022;
    else if T is float
      r =  126;
    @endcode

    @return The Maxexponentm1 constant for the proper type
  **/
  template<typename T> T Maxexponentm1();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant maxexponentm1.

      @return The Maxexponentm1 constant for the proper type
    **/
    const boost::dispatch::functor<tag::maxexponentm1_> maxexponentm1 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/maxexponentm1.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
