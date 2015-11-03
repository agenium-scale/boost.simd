//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFLOOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFLOOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the integer conversion of the floor of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T> r = ifloor(x);
    @endcode

    is equivalent to:

    @code
    as_integer_t<T> r = toints(floor(x));
    @endcode

    @par Note:
    This operation is properly saturated

     @return an integral value of the integral type associated to the input.



**/
  template<typename T> auto ifloor(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the integer conversion of the floor of its parameter.


      Function object tied to simd::ifloor

      @see simd::ifloor
    **/
    const boost::dispatch::functor<tag::ifloor_> ifloor = {};
  }
} }
#endif

#include <boost/simd/function/definition/ifloor.hpp>
#include <boost/simd/arch/common/generic/function/ifloor.hpp>
#include <boost/simd/function/simd/ifloor.hpp>

#endif
