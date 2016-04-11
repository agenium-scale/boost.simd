//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

STF_CASE_TPL ("Check genmask generic behavior", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;
  static const std::size_t N = bs::pack<T>::static_size;

  STF_TYPE_IS(decltype(bs::genmask(bs::pack<T,N  >())), (bs::pack<T,N  >) );
  STF_TYPE_IS(decltype(bs::genmask(bs::pack<T,N/2>())), (bs::pack<T,N/2>) );
  STF_TYPE_IS(decltype(bs::genmask(bs::pack<T,N*2>())), (bs::pack<T,N*2>) );

  STF_IEEE_EQUAL(genmask(bs::pack<T,N  >(42))  , (bs::Allbits<bs::pack<T,N>>())   );
  STF_IEEE_EQUAL(genmask(bs::pack<T,N/2>(42)), (bs::Allbits<bs::pack<T,N/2>>()) );
  STF_IEEE_EQUAL(genmask(bs::pack<T,N*2>(42)), (bs::Allbits<bs::pack<T,N*2>>()) );

  STF_IEEE_EQUAL(genmask(bs::pack<T,N  >(T(0))), (bs::pack<T,N  >(T(0))) );
  STF_IEEE_EQUAL(genmask(bs::pack<T,N/2>(T(0))), (bs::pack<T,N/2>(T(0))) );
  STF_IEEE_EQUAL(genmask(bs::pack<T,N*2>(T(0))), (bs::pack<T,N*2>(T(0))) );
}

// TODO when if_else_zero is available
#if 0
STF_CASE_TPL ("Check genmask behavior when re-targeted",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;
  static const std::size_t N = bs::pack<T>::static_size;

  STF_TYPE_IS ( decltype(bs::genmask<bs::pack<char,N*sizeof(T)>>(bs::pack<T,N>()))
              , (bs::pack<char,N*sizeof(T)>)
              );
  STF_TYPE_IS ( decltype(bs::genmask<bs::pack<char,(N*sizeof(T))/2>>(bs::pack<T,N>()))
              , (bs::pack<char,(N*sizeof(T))/2>)
              );
  STF_TYPE_IS ( decltype(bs::genmask<bs::pack<char,N*sizeof(T)*2>>(bs::pack<T,N>()))
              , (bs::pack<char,N*sizeof(T)*2>)
              );

  STF_EQUAL ( (genmask<bs::pack<char,N*sizeof(T)>>(bs::pack<T,N>(42)))
            , (bs::Allbits<bs::pack<char,N*sizeof(T)>>())
            );

  // STF_EQUAL(genmask<bs::pack<char,N*sizeof(T)>>(T(0)) , char(0));
}
#endif

#ifndef STF_NO_INVALIDS
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>

STF_CASE_TPL ("Check genmask behavior on IEEE754 special values",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;
  static const std::size_t N = bs::pack<T>::static_size;

  STF_IEEE_EQUAL(genmask(bs::Inf <bs::pack<T,N>>()) , (bs::Allbits<bs::pack<T,N>>()) );
  STF_IEEE_EQUAL(genmask(bs::Minf<bs::pack<T,N>>()) , (bs::Allbits<bs::pack<T,N>>()) );
  STF_IEEE_EQUAL(genmask(bs::Nan <bs::pack<T,N>>()) , (bs::Allbits<bs::pack<T,N>>()) );

  STF_IEEE_EQUAL(genmask(bs::Inf <bs::pack<T,N/2>>()) , (bs::Allbits<bs::pack<T,N/2>>()) );
  STF_IEEE_EQUAL(genmask(bs::Minf<bs::pack<T,N/2>>()) , (bs::Allbits<bs::pack<T,N/2>>()) );
  STF_IEEE_EQUAL(genmask(bs::Nan <bs::pack<T,N/2>>()) , (bs::Allbits<bs::pack<T,N/2>>()) );

  STF_IEEE_EQUAL(genmask(bs::Inf <bs::pack<T,N*2>>()) , (bs::Allbits<bs::pack<T,N*2>>()) );
  STF_IEEE_EQUAL(genmask(bs::Minf<bs::pack<T,N*2>>()) , (bs::Allbits<bs::pack<T,N*2>>()) );
  STF_IEEE_EQUAL(genmask(bs::Nan <bs::pack<T,N*2>>()) , (bs::Allbits<bs::pack<T,N*2>>()) );
}
#endif
