//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_ASSERT_UTILS_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_ASSERT_UTILS_HPP_INCLUDED

#include <boost/simd/function/simd/extract.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd
{
  namespace bs = boost::simd;
  template<typename T> BOOST_FORCEINLINE bool assert_all( T const& t )
  {
    for(std::size_t i = 0; i != cardinal_of<T>::value; ++i)
      if(!bs::extract(t, i)) return false; //extract(t, i);
    return true;
  }

  template<typename T> BOOST_FORCEINLINE bool assert_is_mask( T const& t )
  {
    for(std::size_t i = 0; i != cardinal_of<T>::value; ++i)
    {
      typedef dispatch::scalar_of_t<T> sT;
      typedef dispatch::as_integer_t<sT, unsigned> uT;

      sT v = bs::extract(t, i);
      uT uv = bitwise_cast<uT>(v);

      if(uv != Zero<uT>() && uv != Allbits<uT>()) return false;
    }
    return true;
  }

  template<typename A0, typename A1> BOOST_FORCEINLINE bool assert_good_shift( A1 const& t )
  {
    for(std::size_t i = 0; i != cardinal_of<A0>::value; ++i)
    {
      typedef dispatch::scalar_of_t<A1> sA1;
      typedef dispatch::scalar_of_t<A0> sA0;
      const sA1 N = sizeof(sA0)*8;
      sA1 v = bs::extract(t, i);

      if(v < Zero<sA1>() || v >= N)  return false;
    }

    return true;
  }
} }

#endif
