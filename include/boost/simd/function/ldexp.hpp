//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LDEXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    The function multiply a floating entry \f$x\f$
    by \f$2^{n}\f$

    @ref cardinal_of the types of x and n must be identical

    @par Semantic:

    @code
    T r = ldexp(x,n);
    @endcode

    is similar to:

    @code
    T r = x*pow(2, n);
    @endcode



    @return a value of same type as the inputs

**/
  template<typename T, typename N> auto ldexp(T const& x, N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      The function multiply a floating entry \f$x\f$
      by \f$2^{n}\f$


      Function object tied to simd::ldexp

      @see simd::ldexp
    **/
    const boost::dispatch::functor<tag::ldexp_> ldexp = {};
  }
} }
#endif

#include <boost/simd/function/definition/ldexp.hpp>
#include <boost/simd/arch/common/scalar/function/ldexp.hpp>
#include <boost/simd/function/simd/ldexp.hpp>

#endif
