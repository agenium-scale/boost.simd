//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEG_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEG_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the saturated negation of the input.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = neg_s(x);
    @endcode

    For floating the code is equivalent to:

    @code
    T r = -x
    @endcode


    @par Note:

    - For signed integral types neg_s(@ref Valmin) returns @ref Valmax.

    - For unsigned integral types neg_s always returns 0.

     @return      a value of the same type as the input.


**/
  template<typename T> auto neg_s(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated negation of the input.


      Function object tied to simd::neg_s

      @see simd::neg_s
    **/
    const boost::dispatch::functor<tag::neg_s_> neg_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/neg_s.hpp>
#include <boost/simd/function/simd/neg_s.hpp>

#endif
