//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CUMMIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CUMMIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    @brief compute the cumulate minimum of the vector elements

    @par Semantic:

    For every parameter of type T0

    @code
    T0 r = cummin(a0);
    @endcode

    is similar to:

    @code
    T r =x;
    for(int i=0;i < T::static_size; ++i)
      r[i] += min(r[i-1], r[i]);
    @endcode


    @return a value of the same type as the second parameter

**/
  template<typename T> auto cummin(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::cummin

      @see simd::cummin
    **/
    const boost::dispatch::functor<tag::cummin_> cummin = {};
  }
} }
#endif

#include <boost/simd/function/definition/cummin.hpp>
#include <boost/simd/arch/common/scalar/function/cummin.hpp>
//#include <boost/simd/arch/common/function/simd/cummin.hpp>

#endif
