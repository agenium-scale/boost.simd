//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FIRSTBITUNSET_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FIRSTBITUNSET_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the bit pattern in which the only bit set is
    the first bit unset (beginning with the least significant bit) in the parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T,unsigned> r = firstbitunset(x);
    @endcode

    @see  ffs,  firstbitset

    @return      a value of the unsigned integral type associated to the input.


**/
  template<typename T> auto firstbitunset(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns the bit pattern in which the only bit set is
      the first bit unset (beginning with the least significant bit) in the parameter.


      Function object tied to simd::firstbitunset

      @see simd::firstbitunset
    **/
    const boost::dispatch::functor<tag::firstbitunset_> firstbitunset = {};
  }
} }
#endif

#include <boost/simd/function/scalar/firstbitunset.hpp>
#include <boost/simd/function/simd/firstbitunset.hpp>

#endif
