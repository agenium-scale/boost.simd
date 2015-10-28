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
#ifndef BOOST_SIMD_FUNCTION_FIRSTBITSET_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FIRSTBITSET_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the bit pattern in which the only bit set is
    the first bit set (beginning with the least significant bit) in the parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T,unsigned> r = firstbitset(x);
    @endcode

    @see  ffs,  firstbitunset

    @return      a value of the unsigned integral type associated to the input.


**/
  template<typename T> auto firstbitset(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns the bit pattern in which the only bit set is
      the first bit set (beginning with the least significant bit) in the parameter.


      Function object tied to simd::firstbitset

      @see simd::firstbitset
    **/
    const boost::dispatch::functor<tag::firstbitset_> firstbitset = {};
  }
} }
#endif

#include <boost/simd/function/definition/firstbitset.hpp>
#include <boost/simd/arch/common/scalar/function/firstbitset.hpp>
//#include <boost/simd/arch/common/function/simd/firstbitset.hpp>

#endif
