//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the square root of its parameter. For integers it is the
    truncation of the real square root.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = sqrt(x);
    @endcode

    If full accuracy is not needed a sometimes faster less accurate version of the function
    can be used callling : sqrt(x, fast_).

    sqrt(x, std_) calls std::sqrt from stdlibc++

   @return      a value of the same type as the input.


**/
  template<typename T> auto sqrt(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the square root of its parameter. For integers it is the
      truncation of the real square root.


      Function object tied to simd::sqrt

      @see simd::sqrt
    **/
    const boost::dispatch::functor<tag::sqrt_> sqrt = {};
  }
} }
#endif

#include <boost/simd/function/definition/sqrt.hpp>
#include <boost/simd/arch/common/scalar/function/sqrt.hpp>
#include <boost/simd/function/simd/sqrt.hpp>

#endif
