//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FRAC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FRAC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    This function returns the fractional part of the input

    @par Semantic:

    @code
    T r = frac(x);
    @endcode

    is similar to:

    @code
    T r =  x-trunc(x);
    @endcode

    @see trunc

    @return a value of same type as the input

**/
  template<typename T> auto frac(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      This function returns the fractional part of the input


      Function object tied to simd::frac

      @see simd::frac
    **/
    const boost::dispatch::functor<tag::frac_> frac = {};
  }
} }
#endif

#include <boost/simd/function/definition/frac.hpp>
#include <boost/simd/arch/common/scalar/function/frac.hpp>
#include <boost/simd/function/simd/frac.hpp>

#endif
