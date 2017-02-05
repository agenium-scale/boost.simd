//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

STF_CASE_TPL("Check basic behavior of raw_(ifrexp)", STF_IEEE_TYPES)
{
  STF_EXPR_IS ( (bs::raw_(bs::ifrexp)(T(0)))
              , (std::pair<T,bd::as_integer_t<T,signed>>)
              );

  auto p = bs::raw_(bs::ifrexp)(T(1));
  STF_EQUAL(p.first  , T(0.5));
  STF_EQUAL(p.second , T(1));
}

STF_CASE_TPL("Check behavior of raw_(ifrexp) on Valmax", STF_IEEE_TYPES)
{
  auto r = bs::raw_(bs::ifrexp)(bs::Valmax<T>());

  STF_ULP_EQUAL (r.first , T(1)-bs::Halfeps<T>(), 1);
  STF_EQUAL     (r.second, bs::Limitexponent<T>());
  STF_EQUAL     (ldexp(r.first,r.second),bs::Valmax<T>());
}
