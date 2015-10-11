//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SQRTSMALLESTPOSVAL_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SQRTSMALLESTPOSVAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the square root of the least non zero positive non denormal
    value of the chosen type.

    @par Semantic:

    @code
    T r = Sqrtsmallestposval<T>();
    @endcode

    is similar to:

    @code
    if T is integral
      r = 1
    else if T is double
      r =  1.491668146240041e-154;
    else if T is float
      r =   1.0842022e-19;
    @endcode

    @return The Sqrtsmallestposval constant for the proper type
  **/
  template<typename T> T Sqrtsmallestposval();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant sqrtsmallestposval.

      @return The Sqrtsmallestposval constant for the proper type
    **/
    const boost::dispatch::functor<tag::sqrtsmallestposval_> sqrtsmallestposval = {};
  }
} }
#endif

#include <boost/simd/constant/definition/sqrtsmallestposval.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
