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
#ifndef BOOST_SIMD_FUNCTION_IDIVFLOOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IDIVFLOOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the integer conversion of the truncated division of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = idivfix(x, y);
    @endcode

    The code is similar to:

    @code
    as_integer_t<T> r = toints(floor(x/y));
    @endcode

    If y is null, it returns Valmax (resp. Valmin)
    if x is positive (resp. negative) and 0 if x is null.

    @see toints, floor

    @return      a value of the integral type associated to the input.


**/
  template<typename T> auto idivfloor(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the integer conversion of the truncated division of its parameters.


      Function object tied to simd::idivfloor

      @see simd::idivfloor
    **/
    const boost::dispatch::functor<tag::idivfloor_> idivfloor = {};
  }
} }
#endif

#include <boost/simd/function/definition/idivfloor.hpp>
#include <boost/simd/arch/common/generic/function/idivfloor.hpp>
//#include <boost/simd/arch/common/function/simd/idivfloor.hpp>

#endif
