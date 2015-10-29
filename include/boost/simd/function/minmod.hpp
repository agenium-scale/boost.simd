//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINMOD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINMOD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Return the minimum of the two entries
    if they have the same sign, otherwise 0

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = minmod(x, y);
    @endcode

    is similar to:

    @code
    T r =  x*y > 0 ? min(x, y) : 0;
    @endcode


    @return      a value of the same type as the inputs.


**/
  template<typename T> auto minmod(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Return the minimum of the two entries
      if they have the same sign, otherwise 0


      Function object tied to simd::minmod

      @see simd::minmod
    **/
    const boost::dispatch::functor<tag::minmod_> minmod = {};
  }
} }
#endif

#include <boost/simd/function/definition/minmod.hpp>
#include <boost/simd/arch/common/scalar/function/minmod.hpp>
#include <boost/simd/function/simd/minmod.hpp>

#endif
