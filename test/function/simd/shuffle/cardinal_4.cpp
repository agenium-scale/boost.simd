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

template< typename T
        , int IA, int IB, int IC, int ID
        , typename Env
        >
void unary_shuffle(Env& runtime)
{
  using p_t = pack<T,4>;

  p_t a{ Valmax<T>(), T(55), T(42), Valmin<T>() };

  std::size_t ia = static_cast<std::size_t>(IA);
  std::size_t ib = static_cast<std::size_t>(IB);
  std::size_t ic = static_cast<std::size_t>(IC);
  std::size_t id = static_cast<std::size_t>(ID);

  std::array<T,4> ref = { (IA == -1) ? T(0) : a[ia]
                        , (IB == -1) ? T(0) : a[ib]
                        , (IC == -1) ? T(0) : a[ic]
                        , (ID == -1) ? T(0) : a[id]
                        };

  STF_ALL_EQUAL( (shuffle<IA,IB,IC,ID>(a)), ref);
}

template< typename T
        , int IA, int IB, int IC, int ID
        , typename Env
        >
void binary_shuffle(Env& runtime)
{
  using p_t = pack<T,4>;

  p_t a{ Valmax<T>(), T(42), T(13), Valmin<T>() };
  p_t b{ T(69), Valmin<T>(), T(37), T(0) };

  std::size_t ia = static_cast<std::size_t>(IA);
  std::size_t ib = static_cast<std::size_t>(IB);
  std::size_t ic = static_cast<std::size_t>(IC);
  std::size_t id = static_cast<std::size_t>(ID);

  std::array<T,4> ref = { (IA == -1) ? T(0) : (IA<4 ? a[ia] : b[ia-4])
                        , (IB == -1) ? T(0) : (IB<4 ? a[ib] : b[ib-4])
                        , (IC == -1) ? T(0) : (IC<4 ? a[ic] : b[ic-4])
                        , (ID == -1) ? T(0) : (ID<4 ? a[id] : b[id-4])
                        };

  STF_ALL_EQUAL( (shuffle<IA,IB,IC,ID>(a,b)), ref);
}

//STF_NUMERIC_TYPES

STF_CASE_TPL( "identity shuffle", (float)(std::uint32_t)(std::int32_t))
{
  unary_shuffle <T, 0, 1, 2, 3>(runtime);
  binary_shuffle<T, 0, 1, 2, 3>(runtime);
  binary_shuffle<T, 4, 5, 6, 7>(runtime);
}

STF_CASE_TPL( "zero shuffle", (float)(std::uint32_t)(std::int32_t))
{
  unary_shuffle<T,-1,-1,-1,-1>(runtime);
  binary_shuffle<T,-1,-1,-1,-1>(runtime);
}

/*
STF_CASE_TPL( "reverse shuffle", (float)(std::uint32_t)(std::int32_t))
{
  unary_shuffle <T,3,2,1,0>(runtime);
  binary_shuffle<T,7,6,5,4>(runtime);
}

STF_CASE_TPL( "interleave shuffle", (float)(std::uint32_t)(std::int32_t))
{
  unary_shuffle <T, 0, 0, 1, 1>(runtime);
  binary_shuffle<T, 0, 0, 1, 1>(runtime);

  unary_shuffle <T, 0,-1, 1,-1>(runtime);
  binary_shuffle<T, 0,-1, 1,-1>(runtime);

  unary_shuffle <T,-1, 0,-1, 1>(runtime);
  binary_shuffle<T,-1, 0,-1, 1>(runtime);

  unary_shuffle <T, 2, 2, 3, 3>(runtime);
  unary_shuffle <T, 2,-1, 3,-1>(runtime);
  unary_shuffle <T,-1, 2,-1, 3>(runtime);

  binary_shuffle<T, 2, 2, 3, 3>(runtime);
  binary_shuffle<T, 2,-1, 3,-1>(runtime);
  binary_shuffle<T,-1, 2,-1, 3>(runtime);

  binary_shuffle<T, 4, 4, 5, 5>(runtime);
  binary_shuffle<T,-1, 4,-1, 5>(runtime);
  binary_shuffle<T, 4,-1, 5,-1>(runtime);

  binary_shuffle<T, 6, 6, 7, 7>(runtime);
  binary_shuffle<T,-1, 6,-1, 7>(runtime);
  binary_shuffle<T, 6,-1, 7,-1>(runtime);

  binary_shuffle<T,0,4,1,5>(runtime);
  binary_shuffle<T,2,6,3,7>(runtime);
  binary_shuffle<T,0,4,2,6>(runtime);
  binary_shuffle<T,1,5,3,7>(runtime);
  binary_shuffle<T,0,2,4,6>(runtime);
  binary_shuffle<T,1,3,5,7>(runtime);
}
*/
STF_CASE_TPL( "broadcast shuffle", (float)(std::uint32_t)(std::int32_t))
{
  unary_shuffle <T,0,0,0,0>(runtime);
  unary_shuffle <T,1,1,1,1>(runtime);
  unary_shuffle <T,2,2,2,2>(runtime);
  unary_shuffle <T,3,3,3,3>(runtime);
  binary_shuffle<T,0,0,0,0>(runtime);
  binary_shuffle<T,1,1,1,1>(runtime);
  binary_shuffle<T,2,2,2,2>(runtime);
  binary_shuffle<T,3,3,3,3>(runtime);
  binary_shuffle<T,4,4,4,4>(runtime);
  binary_shuffle<T,5,5,5,5>(runtime);
  binary_shuffle<T,6,6,6,6>(runtime);
  binary_shuffle<T,7,7,7,7>(runtime);
}
/*
STF_CASE_TPL( "repeat shuffle", (float)(std::uint32_t)(std::int32_t))
{
  unary_shuffle <T, 0, 1, 0, 1>(runtime);
  unary_shuffle <T, 2, 3, 2, 3>(runtime);
  binary_shuffle<T, 0, 1, 0, 1>(runtime);
  binary_shuffle<T, 2, 3, 2, 3>(runtime);
  binary_shuffle<T, 4, 5, 4, 5>(runtime);
  binary_shuffle<T, 6, 7, 6, 7>(runtime);
}
*/
STF_CASE_TPL( "sse2 style shuffle", (float)(std::uint32_t)(std::int32_t))
{
  unary_shuffle <T,-1,-1, 0, 1>(runtime);
  binary_shuffle<T,-1,-1, 0, 1>(runtime);

  unary_shuffle <T, 0, 1,-1,-1>(runtime);
  binary_shuffle<T, 0, 1,-1,-1>(runtime);

  unary_shuffle <T,-1,-1, 2, 3>(runtime);
  binary_shuffle<T,-1,-1, 2, 3>(runtime);

  unary_shuffle <T, 2, 3,-1,-1>(runtime);
  binary_shuffle<T, 2, 3,-1,-1>(runtime);

  binary_shuffle<T,-1,-1, 4, 5>(runtime);
  binary_shuffle<T, 4, 5,-1,-1>(runtime);

  binary_shuffle<T,-1,-1, 6, 7>(runtime);
  binary_shuffle<T, 6, 7,-1,-1>(runtime);

  binary_shuffle<T,0,1,4,5>(runtime);
  binary_shuffle<T,2,3,6,7>(runtime);
  binary_shuffle<T,6,7,2,3>(runtime);
  binary_shuffle<T,4,5,0,1>(runtime);
}
/*
STF_CASE_TPL( "avx style shuffle", (float)(std::uint32_t)(std::int32_t))
{
  // perm2 based
  binary_shuffle<T, 0, 1, 4, 5>(runtime);
  unary_shuffle <T, 2, 3, 0, 1>(runtime);
  binary_shuffle<T, 2, 3, 0, 1>(runtime);
  binary_shuffle<T, 2, 3, 6, 7>(runtime);
  binary_shuffle<T, 4, 5, 0, 1>(runtime);
  binary_shuffle<T, 6, 7, 0, 1>(runtime);
  binary_shuffle<T, 6, 7, 2, 3>(runtime);
  binary_shuffle<T, 6, 7, 4, 5>(runtime);

  unary_shuffle <T, 0, 0, 2, 2>(runtime);
  binary_shuffle<T, 0, 0, 2, 2>(runtime);
  binary_shuffle<T, 4, 4, 6, 6>(runtime);

  // <0, 4, 2, 6> is interleave_even
  binary_shuffle<T, 4, 0, 6, 2>(runtime);
  // <0, 0, 2, 2> is just up

  binary_shuffle<T, 1, 4, 2, 6>(runtime);
  binary_shuffle<T, 5, 0, 6, 2>(runtime);
  unary_shuffle <T, 1, 0, 2, 2>(runtime);
  binary_shuffle<T, 1, 0, 2, 2>(runtime);

  binary_shuffle<T, 0, 5, 2, 6>(runtime);
  binary_shuffle<T, 4, 1, 6, 2>(runtime);
  unary_shuffle <T, 0, 1, 2, 2>(runtime);
  binary_shuffle<T, 0, 1, 2, 2>(runtime);

  binary_shuffle<T, 1,5,2,6>(runtime);
  binary_shuffle<T, 5,1,6,2>(runtime);
  unary_shuffle <T, 1,1,2,2>(runtime);
  binary_shuffle<T, 1,1,2,2>(runtime);

  binary_shuffle<T, 0,4,3,6>(runtime);
  binary_shuffle<T, 4,0,7,2>(runtime);
  unary_shuffle <T, 0,0,3,2>(runtime);
  binary_shuffle<T, 0,0,3,2>(runtime);

  binary_shuffle<T, 1,4,3,6>(runtime);
  binary_shuffle<T, 5,0,7,2>(runtime);
  unary_shuffle <T, 1,0,3,2>(runtime);
  binary_shuffle<T, 1,0,3,2>(runtime);

  binary_shuffle<T, 0,5,3,6>(runtime);
  binary_shuffle<T, 4,1,7,2>(runtime);
  unary_shuffle <T, 0,1,3,2>(runtime);
  binary_shuffle<T, 0,1,3,2>(runtime);

  binary_shuffle<T, 1,5,3,6>(runtime);
  binary_shuffle<T, 5,1,7,2>(runtime);
  unary_shuffle <T, 1,1,3,2>(runtime);
  binary_shuffle<T, 1,1,3,2>(runtime);

  binary_shuffle<T, 0,4,2,7>(runtime);
  binary_shuffle<T, 4,0,6,3>(runtime);
  unary_shuffle <T, 0,0,2,3>(runtime);
  binary_shuffle<T, 0,0,2,3>(runtime);

  binary_shuffle<T, 1,4,2,7>(runtime);
  binary_shuffle<T, 5,0,6,3>(runtime);
  unary_shuffle <T, 1,0,2,3>(runtime);
  binary_shuffle<T, 1,0,2,3>(runtime);

  binary_shuffle<T, 0,5,2,7>(runtime);
  binary_shuffle<T, 4,1,6,3>(runtime);
  // Dupe shuffle of <0 5 2 7> is <0 1 2 3>

  binary_shuffle<T, 1,5,2,7>(runtime);
  binary_shuffle<T, 5,1,6,3>(runtime);
  unary_shuffle <T, 1,1,2,3>(runtime);
  binary_shuffle<T, 1,1,2,3>(runtime);

  binary_shuffle<T, 0,4,3,7>(runtime);
  binary_shuffle<T, 4,0,7,3>(runtime);
  unary_shuffle <T, 0,0,3,3>(runtime);
  binary_shuffle<T, 0,0,3,3>(runtime);

  binary_shuffle<T, 1,4,3,7>(runtime);
  binary_shuffle<T, 5,0,7,3>(runtime);
  unary_shuffle <T, 1,0,3,3>(runtime);
  binary_shuffle<T, 1,0,3,3>(runtime);

  binary_shuffle<T, 0,5,3,7>(runtime);
  binary_shuffle<T, 4,1,7,3>(runtime);
  unary_shuffle <T, 0,1,3,3>(runtime);
  binary_shuffle<T, 0,1,3,3>(runtime);

  // <1,5,3,7> is interleave_odd
  binary_shuffle<T, 5,1,7,3>(runtime);
  unary_shuffle <T, 1,1,3,3>(runtime);
  binary_shuffle<T, 1,1,3,3>(runtime);
}

STF_CASE_TPL( avx_zero_shuffle, (float)(std::uint32_t)(std::int32_t))
{
  unary_shuffle <T, 1,-1, 2,-1>(runtime);
  binary_shuffle<T, 1,-1, 2,-1>(runtime);
  binary_shuffle<T, 4,-1, 6,-1>(runtime);
  unary_shuffle <T,-1, 0,-1, 2>(runtime);
  binary_shuffle<T,-1, 0,-1, 2>(runtime);

  binary_shuffle<T,-1, 4,-1, 6>(runtime);
  unary_shuffle <T, 0,-1, 2,-1>(runtime);
  binary_shuffle<T, 0,-1, 2,-1>(runtime);
  binary_shuffle<T, 5,-1, 6,-1>(runtime);
  unary_shuffle <T,-1, 1,-1, 2>(runtime);
  binary_shuffle<T,-1, 1,-1, 2>(runtime);

  binary_shuffle<T,-1, 5,-1, 6>(runtime);
  unary_shuffle <T, 1,-1, 2,-1>(runtime);
  binary_shuffle<T, 1,-1, 2,-1>(runtime);
  binary_shuffle<T, 5,-1, 6,-1>(runtime);
  unary_shuffle <T,-1, 1,-1, 2>(runtime);
  binary_shuffle<T,-1, 1,-1, 2>(runtime);
  binary_shuffle<T,-1, 5,-1, 6>(runtime);
}

STF_CASE_TPL( "avx blend shuffle", (float)(std::uint32_t)(std::int32_t))
{
  binary_shuffle <T, 0, 1, 2, 7>(runtime);
  binary_shuffle <T, 0, 1, 6, 3>(runtime);
  binary_shuffle <T, 0, 5, 2, 3>(runtime);
  binary_shuffle <T, 4, 1, 2, 3>(runtime);

  binary_shuffle <T, 0, 1, 6, 7>(runtime);
  binary_shuffle <T, 0, 5, 6, 3>(runtime);
  binary_shuffle <T, 4, 5, 2, 3>(runtime);
  binary_shuffle <T, 0, 5, 2, 7>(runtime);
  binary_shuffle <T, 4, 1, 6, 3>(runtime);
  binary_shuffle <T, 4, 1, 2, 7>(runtime);

  binary_shuffle <T, 0, 5, 6, 7>(runtime);
  binary_shuffle <T, 4, 5, 6, 3>(runtime);
  binary_shuffle <T, 4, 5, 2, 7>(runtime);
  binary_shuffle <T, 4, 1, 6, 7>(runtime);

}

*/
STF_CASE_TPL( "other shuffle", (float)(std::uint32_t)(std::int32_t))
{
  binary_shuffle<T,0,7,2,6>(runtime);
  binary_shuffle<T,0,3,7,4>(runtime);
  binary_shuffle<T,7,4,0,3>(runtime);

  binary_shuffle<T,0,-1,2,6>(runtime);
  binary_shuffle<T,0,3,7,-1>(runtime);

  binary_shuffle<T,7,4,-1,3>(runtime);
}
