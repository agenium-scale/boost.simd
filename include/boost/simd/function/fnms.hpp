//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FNMS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FNMS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the fused substract-multiply of three value.

    @par semantic:
    For any given value @c x,  @c y,  @c z of type @c T:

    @code
    T r = fnms(x, y, z);
    @endcode

    The code is similar to:

    @code
    T r = -(x*y-s);
    @endcode

    @par Note:

    fnms can be called with the same syntax as @ref fma

    @see  fms, fma, fnma, correct_fma

    @return a value of the same type as the input.

**/
  template<typename T> auto fnms(T const& x, T const& y, T const& z) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the fused substract-multiply of three value.


      Function object tied to simd::fnms

      @see simd::fnms
    **/
    const boost::dispatch::functor<tag::fnms_> fnms = {};
  }
} }
#endif

#include <boost/simd/function/scalar/fnms.hpp>
#include <boost/simd/function/simd/fnms.hpp>

#endif
