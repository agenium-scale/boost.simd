//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SATURATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SATURATE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the saturated value of the first input in the template parameter type,
    but in the same type as the input.

    @par Semantic:

    @code
    T r = saturate<S>(x)
    @endcode

    is similar to:

    @code
    if (a0 > Inf<S>()) r =  T(Inf<S>());
    else if  (a0 <  Minf<S>()) r =  T(Minf<S>());
    else r = a0;
    @endcode


    @return a value of same type as the inputs

**/
  template<typename T> auto saturate(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::saturate

      @see simd::saturate
    **/
    const boost::dispatch::functor<tag::saturate_> saturate = {};
  }
} }
#endif

#include <boost/simd/function/definition/saturate.hpp>
#include <boost/simd/arch/common/generic/function/saturate.hpp>
//#include <boost/simd/arch/common/function/simd/saturate.hpp>

#endif
