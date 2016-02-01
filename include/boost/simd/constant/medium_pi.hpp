//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MEDIUM_PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MEDIUM_PI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Constant used in trigonometric reductions

    @par Semantic:

    For type T:

    @code
    T r = Medium_pi<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = Pi<T>()*pow2(18);
    else if T is float
      r = Pi<T>()*pow2(6);
    else
      r =  201
    @endcode

    @return a value of type T

**/
  template<typename T> T Medium_pi();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Constant used in trigonometric reductions

      Generate the  constant medium_pi.

      @return The Medium_pi constant for the proper type
    **/
    const boost::dispatch::functor<tag::medium_pi_> medium_pi = {};
  }
} }
#endif

#include <boost/simd/constant/definition/medium_pi.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
