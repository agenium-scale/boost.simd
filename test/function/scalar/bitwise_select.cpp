//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitwise_select.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL("bitwise_select", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::splat;
  using bs::bitwise_cast;
  using bs::bitwise_select;

  using iT = bd::as_integer_t<T, unsigned>;

  STF_EXPR_IS(bitwise_select(T(),T(),T()), T);
  STF_EXPR_IS(bitwise_select(iT(),T(),T()), T);

  std::uint64_t base = 0xF5555552F552F5F2ULL;
  iT imask = splat<iT>(base & std::uint64_t(~iT(0)));
  T  mask  = bitwise_cast<T>(imask);

  STF_EQUAL( bitwise_select( imask
                                , bs::Allbits<T>()
                                , bs::Zero<T>()
                                )
                , mask
                );

  STF_EQUAL( bitwise_select( mask
                                , bs::Allbits<T>()
                                , bs::Zero<T>()
                                )
                , mask
                );
}


