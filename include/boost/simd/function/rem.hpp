//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the remainder of division.
    The return value is x-n*y, where n is the value x/y,
    rounded toward zero.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = rem(x, y);
    @endcode

    For floating point values the code is similar to:

    @code
    T r = x-divfix(x, y)*y;
    @endcode

    For floating entries:
       -  if x is +/-inf , Nan is returned
       -  if x is +/-0 and y is not 0 x is returned
       -  If y is +/-0, Nan is returned
       -  If either argument is NaN, Nan is returned

    If correct values for these limit cases do not matter for you, calling
    remainder(x, y, fast_) can gain some cycles.


    The returned value has the same sign as x and is less than y in magnitude.

    A call to rem(x, std_) uses the std::libc++ std::fmod function

    @par Alias

    @c fmod,  @c remfix

    @see remainder, mod, modulo

    @return      a value of the same type as the input.


**/
  template<typename T> auto rem(T const& x, T const & y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the remainder of division.
      The return value is x-n*y, where n is the value x/y,
      rounded toward zero.


      Function object tied to simd::rem

      @see simd::rem
    **/
    const boost::dispatch::functor<tag::rem_> rem = {};
  }
} }
#endif

#include <boost/simd/function/definition/rem.hpp>
#include <boost/simd/arch/common/scalar/function/rem.hpp>
#include <boost/simd/function/simd/rem.hpp>

#endif
