//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    Decrements a value by 1 if a predicate is true.

    @par Semantic:

    For every parameters of types respectively COND, T:

    @code
    T1 r = seldec(cond,t);
    @endcode

    is similar to:

    @code
    T1 r = cond : t-one : t;
    @endcode

    @par Alias:
    @c if_dec



    @return a value of the same type as the second parameter

**/
  template<typename COND, typename T> auto seldec(COND const& cond, T const& t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      Decrements a value by 1 if a predicate is true.


      Function object tied to simd::seldec

      @see simd::seldec
    **/
    const boost::dispatch::functor<tag::seldec_> seldec = {};
  }
} }
#endif

#include <boost/simd/function/definition/seldec.hpp>
#include <boost/simd/arch/common/scalar/function/seldec.hpp>
#include <boost/simd/function/simd/seldec.hpp>

#endif
