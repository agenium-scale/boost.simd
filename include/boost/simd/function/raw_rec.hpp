//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RAW_REC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RAW_REC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes an rough approximation of the inverse of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = raw_rec(x);
    @endcode

    is similar to:

    @code
    T r = T(1)/x;
    @endcode

    @par Note:

    Raw means that the computation is possibly done with the most speed available
    on current hardware but with the least precision.


    @see raw_rec, rec

    @return      a value of the type of the input.


**/
  template<typename T> auto raw_rec(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes an rough approximation of the inverse of its parameter.


      Function object tied to simd::raw_rec

      @see simd::raw_rec
    **/
    const boost::dispatch::functor<tag::raw_rec_> raw_rec = {};
  }
} }
#endif

#include <boost/simd/function/scalar/raw_rec.hpp>
#include <boost/simd/function/simd/raw_rec.hpp>

#endif
