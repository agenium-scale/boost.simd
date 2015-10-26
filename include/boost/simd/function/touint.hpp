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
#ifndef BOOST_SIMD_FUNCTION_TOUINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOUINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Convert to unsigned integer by truncation.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer<T, unsigned> r = touint(x);
    @endcode

    The code is similar to:

    @code
    as_integer<T, unsigned> r = static_cast<as_integer<T, unsigned> >(x)
    @endcode

    @par Notes:

    @c toint cast a floating value to the signed integer value of the same bit size.

    This is done by C casting for scalars and corresponding intrinsic in simd (if available).

    Peculiarly,  that implies that the behaviour of this function on invalid or negative
    entries is not defined and possibly unpredictable.

    If you intend to use nans, infs or negative entries, consider using touints instead.

    @return      a value of the unsigned integer type associated to the input.


**/
  template<typename T> auto touint(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::touint

      @see simd::touint
    **/
    const boost::dispatch::functor<tag::touint_> touint = {};
  }
} }
#endif

#include <boost/simd/function/definition/touint.hpp>
#include <boost/simd/arch/common/scalar/function/touint.hpp>
//#include <boost/simd/arch/common/function/simd/touint.hpp>

#endif
