//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/ulpdist.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     b[i] = bs::ulpdist(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::ulpdist(aa1, aa2), bb);
}

STF_CASE_TPL("Check ulpdist on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}



STF_CASE_TPL (" ulpdist real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ulpdist;
  using p_t = bs::pack<T>;


  STF_EXPR_IS( ulpdist(p_t(), p_t()), p_t);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ulpdist(bs::Inf<p_t>(), bs::Inf<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(ulpdist(bs::Minf<p_t>(), bs::Minf<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(ulpdist(bs::Nan<p_t>(), bs::Nan<p_t>()), bs::Zero<p_t>());
#endif

  STF_EQUAL(ulpdist(bs::Mone<p_t>(), bs::Mone<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(ulpdist(bs::One<p_t>(), bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(ulpdist(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());

  STF_EQUAL( ulpdist(bs::One<p_t>(), bs::One<p_t>()+bs::Eps<p_t>())
                , p_t(0.5)
                );

  STF_EQUAL( ulpdist(bs::One<p_t>(), bs::One<p_t>()-bs::Eps<p_t>())
                , p_t(0.5)
                );

  STF_EQUAL( ulpdist(bs::One<p_t>(), bs::One<p_t>()-bs::Eps<p_t>()/2)
                , p_t(0.25)
                );
}

STF_CASE_TPL (" ulpdist signed_integral",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ulpdist;
  using p_t = bs::pack<T>;


  STF_EXPR_IS( ulpdist(p_t(), p_t()), p_t);

  STF_EQUAL(ulpdist(bs::Mone<p_t>(), bs::Mone<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(ulpdist(bs::One<p_t>(), bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(ulpdist(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());

  STF_EQUAL( ulpdist(bs::Zero<p_t>(), bs::Valmin<p_t>())
                , bs::Valmax<p_t>()
                );

  STF_EQUAL( ulpdist(bs::Valmin<p_t>(), bs::Zero<p_t>())
                , bs::Valmax<p_t>()
                );

  STF_EQUAL( ulpdist(bs::Zero<p_t>(), bs::Valmax<p_t>())
                , bs::Valmax<p_t>()
                );

  STF_EQUAL( ulpdist(bs::Valmax<p_t>(), bs::Zero<p_t>())
                , bs::Valmax<p_t>()
                );

  STF_EQUAL( ulpdist(bs::Valmin<p_t>(), bs::Valmax<p_t>())
                , bs::Valmax<p_t>()
                );
}

STF_CASE_TPL (" ulpdist unsigned_integral",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ulpdist;
  using p_t = bs::pack<T>;


  STF_EXPR_IS( ulpdist(p_t(), p_t()), p_t);

  STF_EQUAL(ulpdist(bs::Mone<p_t>(), bs::Mone<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(ulpdist(bs::One<p_t>(), bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(ulpdist(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());

  STF_EQUAL( ulpdist(bs::Zero<p_t>(), bs::Valmin<p_t>())
                , bs::Zero<p_t>()
                );

  STF_EQUAL( ulpdist(bs::Valmin<p_t>(), bs::Zero<p_t>())
                , bs::Zero<p_t>()
                );

  STF_EQUAL( ulpdist(bs::Zero<p_t>(), bs::Valmax<p_t>())
                , bs::Valmax<p_t>()
                );

  STF_EQUAL( ulpdist(bs::Valmax<p_t>(), bs::Zero<p_t>())
                , bs::Valmax<p_t>()
                );

  STF_EQUAL( ulpdist(bs::Valmin<p_t>(), bs::Valmax<p_t>())
                , bs::Valmax<p_t>()
                );
}


