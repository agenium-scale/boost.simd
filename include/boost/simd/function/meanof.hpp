//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MEANOF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MEANOF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the mean of its parameter avoiding overflow.

    @par semantic:
    For any given value @c x and @c y of type @c T:

    @code
    T r = meanof(x, y);
    @endcode

    is similar to:

    @code
    T r = (x+y)/2;
    @endcode

    @par Note:
    Take care that for integers the value returned can differ by one unit
    from \c ceil((a+b)/2.0) or \c floor((a+b)/2.0), but is always one of
    the two values.


    @return a value of the same type as the input.


**/
  template<typename T> auto meanof(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the mean of its parameter avoiding overflow.


      Function object tied to simd::meanof

      @see simd::meanof
    **/
    const boost::dispatch::functor<tag::meanof_> meanof = {};
  }
} }
#endif

#include <boost/simd/function/definition/meanof.hpp>
#include <boost/simd/arch/common/generic/function/meanof.hpp>
//#include <boost/simd/arch/common/function/simd/meanof.hpp>

#endif
