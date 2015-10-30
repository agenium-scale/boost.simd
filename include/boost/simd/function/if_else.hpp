//==================================================================================================
/*!
  @file

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ELSE_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ELSE_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-boolean

    If cond is @ref True returns t else returns f

    @par Semantic:

    For every parameters of types respectively C, T1, T2:

    @code
    T1 r = if_else(cond,t,f);
    @endcode

    is similar to:

    @code
    T1 r = cond ? t : f;
    @endcode

    @par Alias:
    @c where, @c select,  @c sel


    @see  if_else_zero, if_else_allbits, if_zero_else,
    if_allbits_else, if_one_else_zero, if_zero_else_one, bitwise_select
    @param cond condition

    @param t @ref True result

    @param f @ref False result

    @return a value of the same type as the second parameter
  **/
  template<typename C typename T1, typename T2>
  auto if_else(C const& cond, T1 const& t, T2 const& f );
  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is @ref True returns t else returns f


      Function object tied to boost::simd::if_else

      @see boost::simd::if_else
    **/
    const boost::dispatch::functor<tag::if_else_> if_else = {};
  }
} }
#endif

#include <boost/simd/function/scalar/if_else.hpp>
#include <boost/simd/function/simd/if_else.hpp>


#endif
