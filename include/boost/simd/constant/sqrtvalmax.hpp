//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SQRTVALMAX_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SQRTVALMAX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the square root of the greatest finite representable value

    @par Semantic:

    @code
    T r = Sqrtvalmax<T>();
    @endcode

    is similar to:

    @code
    T r =  sqrt(Valmax<T>();
    @endcode

    @return The Sqrtvalmax constant for the proper type
  **/
  template<typename T> T Sqrtvalmax();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant sqrtvalmax.

      @return The Sqrtvalmax constant for the proper type
    **/
    const boost::dispatch::functor<tag::sqrtvalmax_> sqrtvalmax = {};
  }
} }
#endif

#include <boost/simd/constant/definition/sqrtvalmax.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
