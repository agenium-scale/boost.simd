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

    return the elementwise selected element from the second and third operand
    according to the non nullity of the first operand.

    @par Semantic:

    For every parameters of types respectively T0, T1, T2:

    T1 and T2 must share the same base type and T0 be an associated logical type.
    TODO rephrase or explain somewhere

    @code
    T1 r = if_else(cond,t,f);
    @endcode

    is similar to:

    @code
    T0 r = cond ? t : f;
    @endcode

    @par Alias:
    @c where, @c select,  @c sel


    @see  if_else_zero, if_else_allbits, if_zero_else,
    if_allbits_else, if_one_else_zero, if_zero_else_one, bitwise_select
    @param cond condition

    @param t true result

    @param f false result

    @return a value of the same type as the second parameter
  **/
  template<typename T0 typename T1, typename T2>
  auto if_else(T0 const& cond, T1 const& t, T2 const& f );
  namespace functional
  {
    /*!
      @ingroup group-operator

      Function object tied to boost::simd::if_else

      @see boost::simd::if_else
    **/
    const boost::dispatch::functor<tag::if_else_> if_else = {};
  }
} }
#endif

#include <boost/simd/function/scalar/if_else.hpp>
//#include <boost/simd/arch/common/function/simd/if_else.hpp>


#endif
