//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/splatted.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/arch/common/generic/function/autofold.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG ( ext, fake_sum_
                            , (boost::dispatch::reduction_<fake_sum_,plus_,zero_>)
                            );
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, fake_sum_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::fake_sum_, fake_sum);

  namespace ext
  {
    BOOST_DISPATCH_OVERLOAD( fake_sum_, (typename T), bd::cpu_, bd::scalar_<bd::fundamental_<T>> )
    {
      T operator()(T const& a0) const BOOST_NOEXCEPT { return a0; }
    };
  }
} }

template <typename T, std::size_t N, typename Env> void test(Env& runtime)
{
  using p_t = bs::pack<T,N>;

  T k = 1;
  p_t p;

  for(std::size_t i=0;i<N;i++) p[i] = k++;

  STF_EQUAL( bs::fake_sum(p), T( (N*(N+1))/2 ) );
  STF_EQUAL( bs::splatted_(bs::fake_sum)(p), p_t(T( (N*(N+1))/2 )) );
}

STF_CASE_TPL("Check autofold behaviour on pack", STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T,N>(runtime);
  test<T,N/2>(runtime);
  test<T,N*2>(runtime);
}
