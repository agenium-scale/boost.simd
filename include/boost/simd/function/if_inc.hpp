//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_INC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_INC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    Increments a value by @ref One if a predicate is true.

    This is a convenient alias of @ref selinc
**/
  template<typename C, typename T> auto if_inc(C const& cond, T const& t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      Increments a value by @ref One if a predicate is true.


      Function object tied to simd::if_inc

      @see simd::if_inc
    **/
    const boost::dispatch::functor<tag::if_inc_> if_inc = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_inc.hpp>
#include <boost/simd/arch/common/scalar/function/selinc.hpp>
#include <boost/simd/function/simd/if_inc.hpp>

#endif
