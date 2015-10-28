//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CUMPROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CUMPROD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Computes the cumulated product of the vector elements

    Take care that overflow is very easy to get here especially for integral types
    char and unsigned char always overflow except for 0 and 1 !

    @par semantic:
    For any given vector @c x of type @c T:

    @code
    T r = cumprod(x);
    @endcode

    The function coincide with plus for floating point parameters.
    For integers is similar to:

    @code
    T r =x;
    for(int i=0;i < T::static_size; ++i)
      r[i]*= r[i-1];
    @endcode


    @return      a value of the same type as the input.


**/
  template<typename T> auto cumprod(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Computes the cumulated product of the vector elements


      Function object tied to simd::cumprod

      @see simd::cumprod
    **/
    const boost::dispatch::functor<tag::cumprod_> cumprod = {};
  }
} }
#endif

#include <boost/simd/function/definition/cumprod.hpp>
#include <boost/simd/arch/common/scalar/function/cumprod.hpp>
//#include <boost/simd/arch/common/function/simd/cumprod.hpp>

#endif
