//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FDIM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FDIM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
                  {
  /*!
    @ingroup group-arithmetic

    Returns the positive difference between x and y, that is, if x>y, returns x-y, otherwise
    returns +0.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = fdim(x, y);
    @endcode

    The code is equivalent to:

    @code
    T r = max(x-y, Zero<T>();
    @endcode

    except for Nans: if x or y is Nan,  Nan is returned.

    @see max, maxnum

    @return      a value of the same type as the input.
  **/
  template<typename T> auto fdim(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the arithmetic mean of its parameters.


      Function object tied to simd::fdim

      @see simd::fdim
    **/
    const boost::dispatch::functor<tag::fdim_> fdim = {};
  }
} }
#endif

#include <boost/simd/function/scalar/fdim.hpp>
#include <boost/simd/function/simd/fdim.hpp>

#endif
