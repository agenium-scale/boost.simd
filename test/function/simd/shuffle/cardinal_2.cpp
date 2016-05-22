//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

template<typename T, int IA, int IB, typename Env> void unary_shuffle(Env& $)
{
  using p_t = pack<T,2>;

  p_t a{ Valmax<T>(), T(42) };

  std::size_t ia = static_cast<std::size_t>(IA);
  std::size_t ib = static_cast<std::size_t>(IB);

  std::array<T,2> ref = { (IA == -1) ? T(0) : a[ia]
                        , (IB == -1) ? T(0) : a[ib]
                        };

  STF_ALL_EQUAL( (shuffle<IA,IB>(a)), ref);
}


template<typename T, int IA, int IB, typename Env> void binary_shuffle(Env& $)
{
  using p_t = pack<T,2>;

  p_t a{ Valmax<T>(), T(42) };
  p_t b{ T(69), Valmin<T>() };

  std::size_t ia = static_cast<std::size_t>(IA);
  std::size_t ib = static_cast<std::size_t>(IB);

  std::array<T,2> ref = { (IA == -1) ? T(0) : (IA<2 ? a[ia] : b[ia-2])
                        , (IB == -1) ? T(0) : (IB<2 ? a[ib] : b[ib-2])
                        };

  STF_ALL_EQUAL( (shuffle<IA,IB>(a,b)), ref);
}

template<int... I, typename T>
std::array<typename T::value_type,sizeof...(I)> binary_ref(T const& a, T const& b)
{
  using type = typename T::value_type;
  static const auto s = sizeof...(I);

  std::array<type,sizeof...(I)>
  ref = { (I == -1) ? type(0) :
                    ( I<2 ? a[static_cast<std::size_t>(I)]
                          : b[static_cast<std::size_t>(I)-s]
                    )...
        };

  return ref;
}
/*
//STF_NUMERIC_TYPES
STF_CASE_TPL( "identity shuffle", (double)(std::uint64_t)(std::int64_t))
{
  unary_shuffle <T, 0, 1>($);
  binary_shuffle<T, 0, 1>($);
  binary_shuffle<T, 2, 3>($);
}

STF_CASE_TPL( "zero shuffle", (double)(std::uint64_t)(std::int64_t))
{
  unary_shuffle <T,-1,-1>($);
  binary_shuffle<T,-1,-1>($);
}

STF_CASE_TPL( "unary shuffle", (double)(std::uint64_t)(std::int64_t))
{
  unary_shuffle<T, 0, 0>($);
  unary_shuffle<T, 0,-1>($);
  unary_shuffle<T, 1, 0>($);
  unary_shuffle<T, 1, 1>($);
  unary_shuffle<T, 1,-1>($);
  unary_shuffle<T,-1, 0>($);
  unary_shuffle<T,-1, 1>($);
}

STF_CASE_TPL( "binary shuffle over a0", (double)(std::uint64_t)(std::int64_t))
{
  // All is A
  binary_shuffle<T, 0, 0>($);
  binary_shuffle<T, 0,-1>($);
  binary_shuffle<T, 1, 0>($);
  binary_shuffle<T, 1, 1>($);
  binary_shuffle<T, 1,-1>($);
  binary_shuffle<T,-1, 0>($);
  binary_shuffle<T,-1, 1>($);
}
*/
STF_CASE_TPL( "binary shuffle over a1", (double)(std::uint64_t)(std::int64_t))
{
  bs::pack<T,2> a{ Valmax<T>(), T(42) };
  bs::pack<T,2> b{ T(69), Valmin<T>() };

  // All is b
  //binary_shuffle<T, 2, 2>($);
  //binary_shuffle<T, 2,-1>($);
  STF_ALL_EQUAL( (shuffle<2,-1>(a,b)), (binary_ref<2,-1>(a,b)) );

  //binary_shuffle<T, 3, 2>($);
  //binary_shuffle<T, 3, 3>($);
/*  binary_shuffle<T, 3,-1>($);
  binary_shuffle<T,-1, 2>($);
  binary_shuffle<T,-1, 3>($);*/
}
/*
STF_CASE_TPL( "mixed binary shuffle", (double)(std::uint64_t)(std::int64_t))
{
  // Mixed a/b
  binary_shuffle<T, 0, 2>($);
  binary_shuffle<T, 0, 3>($);
  binary_shuffle<T, 1, 2>($);
  binary_shuffle<T, 1, 3>($);
  binary_shuffle<T, 2, 0>($);
  binary_shuffle<T, 2, 1>($);
  binary_shuffle<T, 3, 0>($);
  binary_shuffle<T, 3, 1>($);
}
*/
