//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FNMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FNMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the fused negated add-multiply of three values.

    @par semantic:
    For any given value @c x,  @c y,  @c z of type @c T:

    @code
    T r = fnma(x, y, z);
    @endcode

    The code is similar to:

    @code
    T r = -(x+y*z);
    @endcode

    @see  fma, correct_fma

    @return a value of the same type as the input.

**/
  template<typename T> auto fnma(T const& x, T const& y, T const& z) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the fused negated add-multiply of three values.


      Function object tied to simd::fnma

      @see simd::fnma
    **/
    const boost::dispatch::functor<tag::fnma_> fnma = {};
  }
} }
#endif

#include <boost/simd/function/definition/fnma.hpp>
#include <boost/simd/arch/common/generic/function/fnma.hpp>
#include <boost/simd/function/simd/fnma.hpp>

#endif
