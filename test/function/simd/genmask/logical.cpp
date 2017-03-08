//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void testl(Env& runtime)
{
  namespace bs = boost::simd;
  using lT = bs::logical<T>;
  using pl_t = bs::pack<lT, N>;
  using p_t = bs::pack<T, N>;
  lT a1[N];
  T b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? bs::True<lT>() : bs::False<lT>();
    b[i] = bs::genmask(a1[i]);
  }
  pl_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::genmask(aa1), bb);
}

STF_CASE_TPL("Check genmask on pack of logical", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<bs::logical<T>>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  testl<T, N>(runtime);
  testl<T, N/2>(runtime);
  testl<T, N*2>(runtime);
}



// TODO when if_else_zero is available
#if 0
// STF_CASE_TPL ("Check genmask logical behavior when re-targeted",  STF_NUMERIC_TYPES)
// {
//   namespace bs = boost::simd;
//   using bs::genmask;

//   STF_TYPE_IS(decltype(bs::genmask<char>(bs::logical<T>())),char);

//   STF_IEEE_EQUAL(genmask<char>(bs::logical<T>(true)), bs::Allbits<char>());
//   STF_EQUAL(genmask<char>(bs::logical<T>(false)) , char(0));
// }
#endif
