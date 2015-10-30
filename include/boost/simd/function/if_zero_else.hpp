//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    If cond is @ref True returns @ref Zero else returns f

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T r = if_zero_else(cond,f);
    @endcode

    is similar to:

    @code
    T r = cond ? Zero<T>() : f;
    @endcode

    @return a value of the same type as the second parameter

**/
  template<typename T> auto if_zero_else(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is @ref True returns @ref Zero else returns f


      Function object tied to simd::if_zero_else

      @see simd::if_zero_else
    **/
    const boost::dispatch::functor<tag::if_zero_else_> if_zero_else = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_zero_else.hpp>
#include <boost/simd/arch/common/scalar/function/if_zero_else.hpp>
#include <boost/simd/function/simd/if_zero_else.hpp>

#endif
