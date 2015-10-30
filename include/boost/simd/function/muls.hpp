//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MULS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MULS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the saturated multiplication of the two inputs.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = muls(x, y);
    @endcode

    The code is similar to:

    @code
    T r = x*y
    @endcode

    But is saturated for integer types

    @return      a value of the same type as the input.


**/
  template<typename T> auto muls(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated multiplication of the two inputs.


      Function object tied to simd::muls

      @see simd::muls
    **/
    const boost::dispatch::functor<tag::muls_> muls = {};
  }
} }
#endif

#include <boost/simd/function/definition/muls.hpp>
#include <boost/simd/arch/common/scalar/function/muls.hpp>
#include <boost/simd/function/simd/muls.hpp>

#endif
