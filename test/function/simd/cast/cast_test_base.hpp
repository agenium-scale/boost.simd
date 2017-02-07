//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef CAST_TEST_BASE_HPP_INCLUDED
#define CAST_TEST_BASE_HPP_INCLUDED

#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/function/abs.hpp>
#include <type_traits>

namespace bs = boost::simd;

template<typename T, typename R> struct res
{
  using result = typename T::template rebind<R>;
  static result comp(const T& a0)
  {
    result r;
    for(size_t i=0; i < T::static_size; ++i)
    {
      r[i] = static_cast<R>(a0[i]);
    }
    return r;
  }
};

template <typename T, typename Env> void test_val(Env& runtime)
{
  using sT =  typename T::value_type;
  sT base = (sT(-1) < 0) ? sT(-1) : sT(0);
  T x =  bs::enumerate<T>(base, sT(4)/3);

  STF_EQUAL(bs::pack_cast<float        >(x), (res<T,float        >::comp(x)));
  STF_EQUAL(bs::pack_cast<double       >(x), (res<T,double       >::comp(x)));
  STF_EQUAL(bs::pack_cast<std::int8_t  >(x), (res<T,std::int8_t  >::comp(x)));
  STF_EQUAL(bs::pack_cast<std::int16_t >(x), (res<T,std::int16_t >::comp(x)));
  STF_EQUAL(bs::pack_cast<std::int32_t >(x), (res<T,std::int32_t>::comp(x)));
  STF_EQUAL(bs::pack_cast<std::int64_t >(x), (res<T,std::int64_t >::comp(x)));

  /*
    As per the standard static_cast<std::uint*_t>(-1.) is undefined so we don't test
    for undefined cases.

    See: http://www.embeddeduse.com/2013/08/25/casting-a-negative-float-to-an-unsigned-int/
    See: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3337.pdf

    Section 4.9:
    " A prvalue of a floating point type can be converted to a prvalue of an
      integer type. The conversion truncates; that is, the fractional part
      is discarded. The behavior is undefined if the truncated value cannot
      be represented in the destination type."
  */
  if(std::is_floating_point<sT>::value)
  {
    x = bs::abs(x);
  }

  STF_EQUAL(bs::pack_cast<std::uint8_t >(x), (res<T,std::uint8_t >::comp(x)));
  STF_EQUAL(bs::pack_cast<std::uint16_t>(x), (res<T,std::uint16_t>::comp(x)));
  STF_EQUAL(bs::pack_cast<std::uint32_t>(x), (res<T,std::uint32_t>::comp(x)));
  STF_EQUAL(bs::pack_cast<std::uint64_t>(x), (res<T,std::uint64_t>::comp(x)));

  std::cout << "=====================================================================\n" << std::endl;
}

#endif
