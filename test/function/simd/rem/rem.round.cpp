//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/rem.hpp>
#include <boost/simd/function/round.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/all.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] =  T(i) ;
     a2[i] = T(i+N) ;
     b[i] = bs::pedantic_(bs::rem)(bs::round, a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::pedantic_(bs::rem)(bs::round, aa1, aa2), bb);
}

STF_CASE_TPL("Check rem on pack" , STF_SIGNED_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

template <typename T, std::size_t N, typename Env>
void testroundregular(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] =T(i);
     a2[i] =T(i+N);
     b[i] = bs::rem(bs::round, a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::rem(bs::round, aa1, aa2), bb);
}

STF_CASE_TPL("Check regular_(rem) on pack option round" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  testroundregular<T, N>(runtime);
  testroundregular<T, N/2>(runtime);
  testroundregular<T, N*2>(runtime);
}



STF_CASE_TPL("Check rem floor on pack limiting cases" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  STF_EXPECT(bs::all(bs::is_negative(bs::pedantic_(bs::rem)(bs::round, bs::Mzero<p_t>(), bs::One<p_t>()))));
  STF_EXPECT(bs::all(bs::is_positive(bs::pedantic_(bs::rem)(bs::round, bs::Zero<p_t>(), bs::One<p_t>()))));
  STF_IEEE_EQUAL(bs::pedantic_(bs::rem)(bs::round, bs::Mzero<p_t>(), bs::One<p_t>()), bs::Zero<p_t>());
  STF_IEEE_EQUAL(bs::pedantic_(bs::rem)(bs::round, bs::Zero<p_t>(), bs::One<p_t>()), bs::Zero<p_t>());
 #ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(bs::pedantic_(bs::rem)(bs::round, bs::Inf<p_t>(), bs::Inf<p_t>()), bs::Nan<p_t>());
  STF_IEEE_EQUAL(bs::pedantic_(bs::rem)(bs::round, bs::Minf<p_t>(), bs::Minf<p_t>()), bs::Nan<p_t>());
  STF_IEEE_EQUAL(bs::pedantic_(bs::rem)(bs::round, bs::Nan<p_t>(), bs::Nan<p_t>()), bs::Nan<p_t>());
  STF_IEEE_EQUAL(bs::pedantic_(bs::rem)(bs::round, bs::Inf<p_t>(), bs::One<p_t>()), bs::Nan<p_t>());
  STF_IEEE_EQUAL(bs::pedantic_(bs::rem)(bs::round, bs::One<p_t>(), bs::Zero<p_t>()), bs::Nan<p_t>());
  STF_IEEE_EQUAL(bs::pedantic_(bs::rem)(bs::round, bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Nan<p_t>());
#endif

}
