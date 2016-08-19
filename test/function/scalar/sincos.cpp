//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sincos.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/function/sin.hpp>
#include <boost/simd/function/cos.hpp>


STF_CASE_TPL (" sincos",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::sincos;
  T a[] = {bs::Zero<T>(), bs::One<T>(), bs::Pio2_3<T>(), bs::Pi<T>(),
           bs::Pio_2<T>(), bs::Inf<T>(), bs::Minf<T>(), bs::Nan<T>()};
  size_t N =  sizeof(a)/sizeof(T);

  STF_EXPR_IS( (sincos(T()))
             , (std::pair<T,T>)
             );

   {
    for(size_t i=0; i < N; ++i)
    {
      std::pair<T,T> p = sincos(a[i]);
      STF_IEEE_EQUAL(p.first,  bs::sin(a[i]));
      STF_IEEE_EQUAL(p.second, bs::cos(a[i]));
      std::pair<T,T> q = bs::restricted_(bs::sincos)(a[i]);
      STF_IEEE_EQUAL(q.first,  bs::restricted_(bs::sin)(a[i]));
      STF_IEEE_EQUAL(q.second, bs::restricted_(bs::cos)(a[i]));
    }
   }

}
