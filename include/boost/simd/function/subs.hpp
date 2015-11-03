//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SUBS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SUBS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the saturated difference of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = subs(x, y);
    @endcode

    This function coincides with @ref minus for floating point parameters.
    For integers is similar to:

    @code
    T r = (x-y > Valmax) ? Valmax : (x-y <  Valmin ? Valmin : x-y);
    @endcode

    @return      a value of the same type as the input.


**/
  template<typename T> auto subs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated difference of its parameters.


      Function object tied to simd::subs

      @see simd::subs
    **/
    const boost::dispatch::functor<tag::subs_> subs = {};
  }
} }
#endif

#include <boost/simd/function/definition/subs.hpp>
#include <boost/simd/arch/common/scalar/function/subs.hpp>
#include <boost/simd/function/simd/subs.hpp>

#endif
