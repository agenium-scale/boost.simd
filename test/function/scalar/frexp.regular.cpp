//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL("Check basic behavior of frexp", STF_IEEE_TYPES)
{
  STF_EXPR_IS( (bs::frexp(T(0))), (std::pair<T,T>) );

  auto p = bs::frexp(T(1));
  STF_EQUAL(p.first  , T(0.5));
  STF_EQUAL(p.second , T(1));
}

STF_CASE_TPL("Check behavior of frexp on Zero", STF_IEEE_TYPES)
{
  auto r = bs::frexp(T(0));

  STF_EQUAL (r.first , T(0));
  STF_EQUAL (r.second, T(0));
  STF_EQUAL (ldexp(r.first,bs::toint(r.second)), T(0));
}

STF_CASE_TPL("Check behavior of frexp on Valmax", STF_IEEE_TYPES)
{
  auto r = bs::frexp(bs::Valmax<T>());

  STF_ULP_EQUAL (r.first , T(1)-bs::Halfeps<T>(), 1);
  STF_EQUAL     (r.second, bs::Limitexponent<T>());
  STF_EQUAL     (ldexp(r.first,bs::toint(r.second)),bs::Valmax<T>());
}
