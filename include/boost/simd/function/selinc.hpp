//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SELINC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELINC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    Increments a value by @ref One if a predicate is @ref True.

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T1 r = selinc(cond,y);
    @endcode

    is similar to:

    @code
    T1 r = cond ? t+One<T>() : t  ;
    @endcode

    @par Alias:
    @c if_inc



    @return a value of the same type as the second parameter

**/
  template<typename C, typename T> auto selinc(C const& cond, T const& t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      Increments a value by @ref One if a predicate is true.


      Function object tied to simd::selinc

      @see simd::selinc
    **/
    const boost::dispatch::functor<tag::selinc_> selinc = {};
  }
} }
#endif

#include <boost/simd/function/scalar/selinc.hpp>
#include <boost/simd/function/simd/selinc.hpp>

#endif
