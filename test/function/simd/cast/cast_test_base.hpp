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

template <typename T, typename Env> void test_val(Env& $)
{
  using sT =  typename T::value_type;
  sT base = (sT(-1) < 0) ? sT(-1) : sT(0);
  T x =  bs::enumerate<T>(base, sT(4)/3);

  std::cout << "Source type: pack<"   << stf::type_id<sT>()
                              << ","  << T::static_size
                              << ">"  << std::endl;

  STF_EQUAL(bs::pack_cast<std::int8_t  >(x), (res<T,std::int8_t  >::comp(x)));
  STF_EQUAL(bs::pack_cast<std::int16_t >(x), (res<T,std::int16_t >::comp(x)));
  STF_EQUAL(bs::pack_cast<std::int32_t >(x), (res<T,std::int32_t>::comp(x)));
  STF_EQUAL(bs::pack_cast<std::int64_t >(x), (res<T,std::int64_t >::comp(x)));
  STF_EQUAL(bs::pack_cast<std::uint8_t >(x), (res<T,std::uint8_t >::comp(x)));
  STF_EQUAL(bs::pack_cast<std::uint16_t>(x), (res<T,std::uint16_t>::comp(x)));
  STF_EQUAL(bs::pack_cast<std::uint32_t>(x), (res<T, std::uint32_t>::comp(x)));
  STF_EQUAL(bs::pack_cast<std::uint64_t>(x), (res<T,std::uint64_t>::comp(x)));
  STF_EQUAL(bs::pack_cast<float        >(x), (res<T,float        >::comp(x)));
  STF_EQUAL(bs::pack_cast<double       >(x), (res<T,double       >::comp(x)));
  std::cout << "=====================================================================\n" << std::endl;
}

#endif
