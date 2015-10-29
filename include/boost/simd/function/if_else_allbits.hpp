//==================================================================================================
/*!
  @file

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

    If cond is true returns t else returns allbits

    @par Semantic:

    For every parameters of types respectively COND, T:

    @code
    T r = if_else_allbits(cond,t);
    @endcode

    is similar to:

    @code
    T r = cond ? t : allbits;
    @endcode


    @par Alias:
    @c  if_else_nan,

    @return a value of the same type as the second parameter

**/
  template<typename COND, typename T> auto if_else_allbits(COND const& cond, const T& t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is true returns t else returns allbits


      Function object tied to simd::if_else_allbits

      @see simd::if_else_allbits
    **/
    const boost::dispatch::functor<tag::if_else_allbits_> if_else_allbits = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_else_allbits.hpp>
#include <boost/simd/arch/common/scalar/function/if_else_allbits.hpp>
#include <boost/simd/function/simd/if_else_allbits.hpp>

#endif
