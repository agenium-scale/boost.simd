//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEC_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEC_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Return the entry minus one, saturated in the entry type.
    If @c x is not @ref Nan, @c dec_s(x) is less or equal to x.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = dec_s(x);
    @endcode

    is similar to:

    @code
    T r = (x > Valmin) ? x-1 : x;
    @endcode


    @return      a value of the same type as the input.


**/
  template<typename T> auto dec_s(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Return the entry minus one, saturated in the entry type.
      If @c x is not @ref Nan, @c dec_s(x) is always less or equal to x.


      Function object tied to simd::dec_s

      @see simd::dec_s
    **/
    const boost::dispatch::functor<tag::dec_s_> dec_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/dec_s.hpp>
#include <boost/simd/function/simd/dec_s.hpp>

#endif
