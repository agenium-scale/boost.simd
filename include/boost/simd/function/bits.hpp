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
#ifndef BOOST_SIMD_FUNCTION_BITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns an unsigned integer value which has the same bits as the input

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = bits(x);
    @endcode

    is equivalent to:

    @code
    as_integer_t<T,unsigned> r = bitwase_cast< as_integer_t<T,unsigned>>(a0);
    @endcode


    @return      a value of the same type as the input.


**/
  template<typename T> auto bits(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::bits

      @see simd::bits
    **/
    const boost::dispatch::functor<tag::bits_> bits = {};
  }
} }
#endif

#include <boost/simd/function/definition/bits.hpp>
#include <boost/simd/arch/common/generic/function/bits.hpp>
//#include <boost/simd/arch/common/function/simd/bits.hpp>

#endif
