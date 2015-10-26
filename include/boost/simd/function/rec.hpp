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
#ifndef BOOST_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Returns the inverse of the entry.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = rec(x);
    @endcode

    The code is similar to:

    @code
    T r = T(1)/x;
    @endcode



    @return      a value of the type of the input.


**/
  template<typename T> auto rec(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::rec

      @see simd::rec
    **/
    const boost::dispatch::functor<tag::rec_> rec = {};
  }
} }
#endif

#include <boost/simd/function/definition/rec.hpp>
#include <boost/simd/arch/common/scalar/function/rec.hpp>
#include <boost/simd/arch/common/generic/function/rec.hpp>
//#include <boost/simd/arch/common/function/simd/rec.hpp>

#endif
