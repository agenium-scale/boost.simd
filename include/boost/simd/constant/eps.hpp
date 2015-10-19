//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_EPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_EPS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate two times the machine epsilon.

    @par Semantic:

    @code
    T r = Eps<T>();
    @endcode

    is similar to:

    @code
    if T is integral
      r = T(1)
    else if T is double
      r =  pow(2.0, -53);
    else if T is float
      r =  pow(2.0f, -23);
    @endcode

    @return The Eps constant for the proper type
  **/
  template<typename T> T Eps();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant eps.

      @return The Eps constant for the proper type
    **/
    const boost::dispatch::functor<tag::eps_> eps = {};
  }
} }
#endif

#include <boost/simd/constant/definition/eps.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
