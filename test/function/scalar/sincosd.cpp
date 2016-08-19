//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sincosd.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/function/sind.hpp>
#include <boost/simd/function/cosd.hpp>


STF_CASE_TPL (" sincosd",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::sincosd;
  T a[] = {bs::Zero<T>(), bs::One<T>(), T(120), T(180),
           T(90), bs::Inf<T>(), bs::Minf<T>(), bs::Nan<T>()};
  size_t N =  sizeof(a)/sizeof(T);

  STF_EXPR_IS( (sincosd(T()))
             , (std::pair<T,T>)
             );

  {
    for(size_t i=0; i < N; ++i)
    {
      std::pair<T,T> p = sincosd(a[i]);
      STF_IEEE_EQUAL(p.first,  bs::sind(a[i]));
      STF_IEEE_EQUAL(p.second, bs::cosd(a[i]));
      std::pair<T,T> q = bs::restricted_(sincosd)(a[i]);
      STF_IEEE_EQUAL(q.first,  bs::restricted_(bs::sind)(a[i]));
      STF_IEEE_EQUAL(q.second, bs::restricted_(bs::cosd)(a[i]));
    }
  }
}



