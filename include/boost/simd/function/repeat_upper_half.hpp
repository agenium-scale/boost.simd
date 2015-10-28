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
#ifndef BOOST_SIMD_FUNCTION_REPEAT_UPPER_HALF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REPEAT_UPPER_HALF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

        Repeat upper half of a vector

    @par Semantic:

    For every parameter of type T

    @code
    T r = repeat_upper_half(x);
    @endcode

    is similar to:

    @code
      T r;
      const std::size_t       n = meta::cardinal_of<T>::value;
      const std::size_t  middle = meta::cardinal_of<T>::value/2;
      for(std::size_t i=middle;i<n;++i)
      {
        r[i] = r[i-middle] = x[i];
      }
    @endcode


    @return a value of the same type as the parameter

**/
  template<typename T> auto repeat_upper_half(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

          Repeat upper half of a vector


      Function object tied to simd::repeat_upper_half

      @see simd::repeat_upper_half
    **/
    const boost::dispatch::functor<tag::repeat_upper_half_> repeat_upper_half = {};
  }
} }
#endif

#include <boost/simd/function/definition/repeat_upper_half.hpp>
#include <boost/simd/arch/common/scalar/function/repeat_upper_half.hpp>
//#include <boost/simd/arch/common/function/simd/repeat_upper_half.hpp>

#endif
