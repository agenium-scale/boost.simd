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
#ifndef BOOST_SIMD_FUNCTION_MINUSONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINUSONE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Return the entry minus one, saturated in the entry type.
    If @c x is not Nan, @c minusone(x) is always less or equal to x.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = minusone(x);
    @endcode

    is similar to:

    @code
    T r = (x > Valmin) ? x-1 : x;
    @endcode


    @return      a value of the same type as the input.


**/
  template<typename T> auto minusone(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::minusone

      @see simd::minusone
    **/
    const boost::dispatch::functor<tag::minusone_> minusone = {};
  }
} }
#endif

#include <boost/simd/function/definition/minusone.hpp>
#include <boost/simd/arch/common/scalar/function/minusone.hpp>
//#include <boost/simd/arch/common/function/simd/minusone.hpp>

#endif
