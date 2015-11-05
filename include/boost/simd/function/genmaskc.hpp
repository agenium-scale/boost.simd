//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GENMASKC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GENMASKC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns a mask of bits. All ones if the
    input element is @ref Zero else all zeros.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = genmaskc(x);
    @endcode

    is similar to

    @code
    T r = x ? Zero : Allbits;
    @endcode

    @par Alias:
    @c if_zero_else_allbits

    @see if_else_allbits

    @return      a value of the type of the input.


**/
  template<typename T> auto genmaskc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns a mask of bits. All ones if the
      input element is @ref Zero else all zeros.


      Function object tied to simd::genmaskc

      @see simd::genmaskc
    **/
    const boost::dispatch::functor<tag::genmaskc_> genmaskc = {};
  }
} }
#endif

#include <boost/simd/function/definition/genmaskc.hpp>
#include <boost/simd/arch/common/scalar/function/genmaskc.hpp>
#include <boost/simd/function/simd/genmaskc.hpp>

#endif
