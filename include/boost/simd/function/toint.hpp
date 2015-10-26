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
#ifndef BOOST_SIMD_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Convert to integer by truncation.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer<T> r = toint(x);
    @endcode

    The code is similar to:

    @code
    as_integer<T> r = static_cast<as_integer<T> >(x)
    @endcode

    @par Notes:

    @c toint cast a floating value to the signed integer value of the same bit size.

    This is done by C casting for scalars and corresponding intrinsic in simd (if available).

    Peculiarly,  that implies that the behaviour of this function on invalid entries is
    not defined and quite unpredictable.

    (For instance it is quite frequent that the test:

    @code
    toint(Inf<double>()) ==  toint(1.0/0.0)
    @endcode


    will return false whilst the test:

    @code
    Inf<double>() == 1.0/0.0
    @endcode


    returns true !)

    If you intend to use nans and infs entries,  consider using toints instead.
    On integral typed values, it acts as identity.

    @return      a value of the integer type associated to the input.


**/
  template<typename T> auto toint(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::toint

      @see simd::toint
    **/
    const boost::dispatch::functor<tag::toint_> toint = {};
  }
} }
#endif

#include <boost/simd/function/definition/toint.hpp>
#include <boost/simd/arch/common/scalar/function/toint.hpp>
//#include <boost/simd/arch/common/function/simd/toint.hpp>

#endif
