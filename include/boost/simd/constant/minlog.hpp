//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MINLOG_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MINLOG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant Minlog used in logarithm/exponential computations
    nt2::log(x) return  0 if x is less than Minlog (underflow)

    @par Semantic:

    @code
    T r = Minlog<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = -708.3964185322641;
    else if T is float
      r = -88.3762626647949
    @endcode

    @see Maxlog


**/
  template<typename T> T Minlog();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant Minlog used in logarithm/exponential computations
      nt2::log(x) return  0 if x is less than Minlog (underflow)

      Generate the  constant minlog.

      @return The Minlog constant for the proper type
    **/
    const boost::dispatch::functor<tag::minlog_> minlog = {};
  }
} }
#endif

#include <boost/simd/constant/definition/minlog.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
