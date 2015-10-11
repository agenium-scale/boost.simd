//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_PI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate value \f$\pi\f$ that is the half length of a circle of radius one
    ... in normal temperature and pressure conditions.

    @par Semantic:

    @code
    T r = Pi<T>();
    @endcode

    is similar to:

    @code
    T r = T(4*atan(1));
    @endcode

    @return The Pi constant for the proper type
  **/
  template<typename T> T Pi();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant pi.

      @return The Pi constant for the proper type
    **/
    const boost::dispatch::functor<tag::pi_> pi = {};
  }
} }
#endif

#include <boost/simd/constant/definition/pi.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
