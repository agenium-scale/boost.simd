//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ELSE_ALLBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ELSE_ALLBITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    If a0 is true returns a1 else returns allbits

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T r = if_else_allbits(a0,a1);
    @endcode

    is similar to:

    @code
    T r = a0 ? a1 : allbits;
    @endcode


    @par Alias:
    @c  if_else_nan,
    @c  ifelsenan,
    @c  ifnot_nan_else,
    @c  ifnotnanelse,
    @c  if_else_allbits,
    @c  ifelseallbits,
    @c  ifnot_allbits_else,
    @c  ifnotallbitselse,



    @return a value of the same type as the second parameter

**/
  template<typename T> auto if_else_allbits(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::if_else_allbits

      @see simd::if_else_allbits
    **/
    const boost::dispatch::functor<tag::if_else_allbits_> if_else_allbits = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_else_allbits.hpp>
#include <boost/simd/arch/common/scalar/function/if_else_allbits.hpp>
//#include <boost/simd/arch/common/function/simd/if_else_allbits.hpp>

#endif
