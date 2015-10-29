//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGIF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGIF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    The function returns -x if cond is true and x otherwise.

    @par Semantic:

    For every parameters of types respectively COND, T:

    @code
    T r = negif(cond,x);
    @endcode

    is similar to:

    @code
    T r = cond ? -x : x;
    @endcode



    @return a value of the same type as the second parameter

**/
  template<typename COND, typename T> auto negif(COND const& cond, T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      The function returns -x if cond is true and x otherwise.


      Function object tied to simd::negif

      @see simd::negif
    **/
    const boost::dispatch::functor<tag::negif_> negif = {};
  }
} }
#endif

#include <boost/simd/function/definition/negif.hpp>
#include <boost/simd/arch/common/scalar/function/negif.hpp>
#include <boost/simd/function/simd/negif.hpp>

#endif
