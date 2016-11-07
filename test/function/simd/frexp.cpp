//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <tuple>
#include <utility>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/halfeps.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], m[N];
  T e[N];

  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     std::tie(m[i], e[i])   = bs::frexp(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t mm1, mm(&m[0], &m[0]+N);
  p_t ee1, ee(&e[0], &e[0]+N);

  std::tie(mm1, ee1) = bs::frexp(aa1);
  STF_IEEE_EQUAL(mm1, mm);
  STF_IEEE_EQUAL(ee1, ee);
}

STF_CASE_TPL("Check frexp on pack" , STF_IEEE_TYPES)
{

  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

// template <typename T, std::size_t N, typename Env>
// void test_fast(Env& $)
// {
//   using p_t = bs::pack<T, N>;

//   T a1[N], m[N];
//   T e[N];

//   for(std::size_t i = 0; i < N; ++i)
//   {
//     a1[i] = (i%2) ? T(1+i) : T(1-i);
//     std::tie(m[i], e[i]) = bs::fast_(bs::frexp)(a1[i]);
//   }

//   p_t aa1(&a1[0], &a1[0]+N);
//   p_t mm , mm1(&m[0], &m[0]+N);
//   p_t ee , ee1(&e[0], &e[0]+N);
// //  std::tie(mm, ee) = bs::fast_(bs::frexp)(aa1);

//   STF_IEEE_EQUAL(mm, mm1);
//   STF_IEEE_EQUAL(ee, ee1);
// }

// STF_CASE_TPL("Check fast(frexp) on pack" , STF_IEEE_TYPES)
// {

//   using p_t = bs::pack<T>;
//   static const std::size_t N = bs::cardinal_of<p_t>::value;
//   test_fast<T, N>($);
//   test_fast<T, N/2>($);
//   test_fast<T, N*2>($);
// }


STF_CASE_TPL(" frexp0", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::frexp;
  using p_t = bs::pack<T>;

  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;
    p_t a = bs::Valmax<p_t>();
    std::tie(m, e) = frexp(a);
    STF_ULP_EQUAL(m, bs::One<p_t>()-bs::Halfeps<p_t>(), 1);
    STF_EQUAL(e, bs::tofloat(bs::Limitexponent<p_t>()));
  }

#ifndef BOOST_SIMD_NO_DENORMALS
  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;
    p_t a = bs::Mindenormal<p_t>();
    std::tie(m, e) = frexp(a);
    STF_ULP_EQUAL(m, bs::Half<p_t>(), 1);
    STF_EQUAL(e,  bs::tofloat(bs::Minexponent<p_t>()-bs::Nbmantissabits<p_t>())+bs::One<p_t>());
  }

  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;
    p_t a = bs::Smallestposval<p_t>()/2;
    std::tie(m, e) = frexp(a);
    STF_ULP_EQUAL(m, bs::Half<p_t>(), 1);
    STF_EQUAL(e, bs::tofloat(bs::Minexponent<p_t>()));
  }

  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;
    p_t a = bs::Smallestposval<p_t>()/4;
    std::tie(m, e) = frexp(a);
    STF_ULP_EQUAL(m, bs::Half<p_t>(), 1);
    STF_EQUAL(e, bs::tofloat(bs::Minexponent<p_t>())-bs::One<p_t>());
  }
#endif

}

STF_CASE_TPL(" frexp", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::frexp;
  using p_t = bs::pack<T>;


  STF_EXPR_IS( (frexp(p_t()))
             , (std::pair<p_t,p_t>)
             );

  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;

    std::tie(m, e) = frexp(bs::One<p_t>());
    STF_EQUAL(m, bs::Half<p_t>());
    STF_EQUAL(e, bs::One<p_t>());
  }

  {
    namespace bs = boost::simd;
    std::pair<p_t,p_t> p;

    p = frexp(bs::One<p_t>());
    STF_EQUAL(p.first  , bs::Half<p_t>());
    STF_EQUAL(p.second , bs::One<p_t>());
  }
}

STF_CASE_TPL(" frexp0", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::frexp;
  using p_t = bs::pack<T>;

  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;
    p_t a = bs::Valmax<p_t>();
    std::tie(m, e) = frexp(a);
    STF_ULP_EQUAL(m, bs::One<p_t>()-bs::Halfeps<p_t>(), 1);
    STF_EQUAL(e, bs::tofloat(bs::Limitexponent<p_t>()));
  }

#ifndef BOOST_SIMD_NO_DENORMALS
  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;
    p_t a = bs::Mindenormal<p_t>();
    std::tie(m, e) = frexp(a);
    STF_ULP_EQUAL(m, bs::Half<p_t>(), 1);
    STF_EQUAL(e, bs::tofloat(bs::Minexponent<p_t>()-bs::Nbmantissabits<p_t>())+bs::One<p_t>());
  }

  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;
    p_t a = bs::Smallestposval<p_t>()/2;
    std::tie(m, e) = frexp(a);
    STF_ULP_EQUAL(m, bs::Half<p_t>(), 1);
    STF_EQUAL(e, bs::tofloat(bs::Minexponent<p_t>()));
  }

  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;
    p_t a = bs::Smallestposval<p_t>()/4;
    std::tie(m, e) = frexp(a);
    STF_ULP_EQUAL(m, bs::Half<p_t>(), 1);
    STF_EQUAL(e, bs::tofloat(bs::Minexponent<p_t>())-bs::One<p_t>());
  }
#endif

}

STF_CASE_TPL(" frexp fast", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::frexp;
  using bs::fast_;
  using p_t = bs::pack<T>;


  STF_EXPR_IS( (bs::fast_(frexp)(p_t()))
             , (std::pair<p_t,p_t>)
             );

  {
    namespace bs = boost::simd;
    p_t e;
    p_t m;

    std::tie(m, e) = bs::fast_(frexp)(bs::One<p_t>());
    STF_EQUAL(m, bs::Half<p_t>());
    STF_EQUAL(e, bs::One<p_t>());
  }

  {
    namespace bs = boost::simd;
    std::pair<p_t,p_t> p;

    p = bs::fast_(frexp)(bs::One<p_t>());
    STF_EQUAL(p.first  , bs::Half<p_t>());
    STF_EQUAL(p.second , bs::One<p_t>());
  }
}

