//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NTHROOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NTHROOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    nth root function: \f$\sqrt[n]{x}\f$
    \arg n must be of integer type
    \arg if n is even and x negative the result is @ref Nan
    \arg if x is null the result is @ref Zero
    \arg if x is one  the result is @ref One

    @par Semantic:

    For every parameters of  floating type T and integral type N:

    @code
    T r = nthroot(x, n);
    @endcode

    is similar to:

    @code
    T r = n >= 0 ? pow(x, rec(tofloat(n))) : Nan;
    @endcode

    @par Note:
    nthroot is more expansive than pow(x, rec(tofloat(n))) because
    it takes care of some limits issues that @ref pow does not mind of.

    See if it suits you better.

    @see pow, rec, sqrt, cbrt


    @return a value of the same type as the parameter

**/
  template<typename T, typename N> auto nthroot(T const& x, N const & n) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      nth root function: \f$\sqrt[a_1]{a_0}\f$
      \arg a1 must be of integer type
      \arg if a1 is even and x negative the result is nan
      \arg if x is null the result is zero
      \arg if x is one  the result is one


      Function object tied to simd::nthroot

      @see simd::nthroot
    **/
    const boost::dispatch::functor<tag::nthroot_> nthroot = {};
  }
} }
#endif

#include <boost/simd/function/scalar/nthroot.hpp>
#include <boost/simd/function/simd/nthroot.hpp>

#endif
