//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns the sum of the elements of the SIMD vector

    @par Semantic:

    For every parameter of type T

    @code
    scalar<T> r = sum(x);
    @endcode

    is similar to:

    @code
    scalar<T> r = Zero;
    for(result_type i = 0; i != meta::cardinal_of<T>; ++i)
      r += x[i];
    @endcode


    @return a value of the scalar type associated to the parameter

**/
  template<typename T> auto sum(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns the sum of the elements of the SIMD vector


      Function object tied to simd::sum

      @see simd::sum
    **/
    const boost::dispatch::functor<tag::sum_> sum = {};
  }
} }
#endif

#include <boost/simd/function/definition/sum.hpp>
#include <boost/simd/arch/common/scalar/function/sum.hpp>
//#include <boost/simd/arch/common/function/simd/sum.hpp>

#endif
