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
#ifndef BOOST_SIMD_FUNCTION_REMQUO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REMQUO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Remainder and bits of quotient

    remquo computes the remainder (rem) and a part of the quotient (quo) upon division of
    @c x by @c y. By design, the value of the remainder is the same as that
    computed by the @ref remainder function. The value of the computed quotient has
    the sign of @c x/y and agrees with the actual quotient in at least the low
    order 3 bits.

    @par semantic:

    For any given value @c x, @c y of type @c T:

    @code
    as_integer_t<T>& quo;
    T rem = remquo(x, y, quo);
    @endcode

    or

    @code
    std::pair< T, as_integer_t<T> > p = remquo(x, y);
    @endcode

    computes the two values.

    @par Note
    This function mimics a standard C library one that was mainly written in its time to
    help computation of trigonometric functions : three bits of quo allowing to know the
    'quadrant'
**/
  template<typename T, typename I> auto remquo(T const& x, T const& y, I & quo) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Remainder and bits of quotient


      Function object tied to simd::remquo

      @see simd::remquo
    **/
    const boost::dispatch::functor<tag::remquo_> remquo = {};
  }
} }
#endif

#include <boost/simd/function/definition/remquo.hpp>
#include <boost/simd/arch/common/scalar/function/remquo.hpp>
#include <boost/simd/function/simd/remquo.hpp>

#endif
