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
#ifndef BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    Decrements a value by @ref One if a predicate is @ref True.

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T r = seldec(cond,t);
    @endcode

    is similar to:

    @code
    T r = cond : t-One<T>() : t;
    @endcode

    @par Alias:
    @c if_dec



    @return a value of the same type as the second parameter

**/
  template<typename C, typename T> auto seldec(C const& cond, T const& t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      Decrements a value by @ref One if a predicate is true.


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
