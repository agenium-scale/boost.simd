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
#ifndef BOOST_SIMD_FUNCTION_IFNOTINC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOTINC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    Increments a value by @ref One if a predicate is @ref False.

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T r = ifnotdec(cond,t);
    @endcode

    is similar to:

    @code
    T r = cond : t : t+one;
    @endcode

    @return a value of the same type as the second parameter

**/
   template<typename C, typename T> auto ifnotinc(C const& cond, T const& t) {}


  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      Increments a value by @ref One if a predicate is false.


      Function object tied to simd::ifnotinc

      @see simd::ifnotinc
    **/
    const boost::dispatch::functor<tag::ifnotinc_> ifnotinc = {};
  }
} }
#endif

#include <boost/simd/function/definition/ifnotinc.hpp>
#include <boost/simd/arch/common/scalar/function/ifnotinc.hpp>
#include <boost/simd/function/simd/ifnotinc.hpp>

#endif
