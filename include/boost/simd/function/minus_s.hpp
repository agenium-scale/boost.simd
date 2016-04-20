//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINUS_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINUS_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the saturated difference of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = minus_s(x, y);
    @endcode

    This function coincides with @ref minus for floating point parameters.
    For integral type, it is similar to:

    @code
    T r = (x-y > Valmax) ? Valmax : (x-y < Valmin ? Valmin : x-y);
    @endcode

    @return      a value of the same type as the input.


**/
  template<typename T> auto minus_s(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated difference of its parameters.


      Function object tied to simd::minus_s

      @see simd::minus_s
    **/
    const boost::dispatch::functor<tag::minus_s_> minus_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/minus_s.hpp>
#include <boost/simd/function/simd/minus_s.hpp>

#endif
