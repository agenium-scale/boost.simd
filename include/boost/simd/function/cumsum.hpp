//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CUMSUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CUMSUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    compute the cumulate sum of the vector elements

    @par Semantic:

    For every parameter of type T0

    @code
    T0 r = cumsum(x);
    @endcode

    is similar to:

    @code
    T r =x;
    for(int i=0;i < T::static_size; ++i)
      r[i] += r[i-1];
    @endcode


    @return a value of the same type as the second parameter

**/
  template<typename T> auto cumsum(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      compute the cumulate sum of the vector elements


      Function object tied to simd::cumsum

      @see simd::cumsum
    **/
    const boost::dispatch::functor<tag::cumsum_> cumsum = {};
  }
} }
#endif

#include <boost/simd/function/definition/cumsum.hpp>
#include <boost/simd/arch/common/scalar/function/cumsum.hpp>
//#include <boost/simd/arch/common/function/simd/cumsum.hpp>

#endif
