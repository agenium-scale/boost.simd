//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL("Check basic behavior of pedantic_(frexp)", STF_IEEE_TYPES)
{
  STF_EXPR_IS( (bs::pedantic_(bs::frexp)(T(0))), (std::pair<T,T>) );

  auto p = bs::pedantic_(bs::frexp)(T(1));
  STF_EQUAL(p.first  , T(0.5));
  STF_EQUAL(p.second , T(1));
}

STF_CASE_TPL("Check behavior of pedantic_(frexp) on Zero", STF_IEEE_TYPES)
{
  auto r = bs::pedantic_(bs::frexp)(T(0));

  STF_EQUAL (r.first , T(0));
  STF_EQUAL (r.second, T(0));
  STF_EQUAL (ldexp(r.first,bs::toint(r.second)), T(0));
}

STF_CASE_TPL("Check behavior of pedantic_(frexp) on Valmax", STF_IEEE_TYPES)
{
  auto r = bs::pedantic_(bs::frexp)(bs::Valmax<T>());

  STF_ULP_EQUAL (r.first , T(1)-bs::Halfeps<T>(), 1);
  STF_EQUAL     (r.second, bs::Limitexponent<T>());
  STF_EQUAL     (ldexp(r.first,bs::toint(r.second)),bs::Valmax<T>());
}

#ifndef BOOST_SIMD_NO_INVALID
#include <boost/simd/constant/nan.hpp>

STF_CASE_TPL("Check behavior of pedantic_(frexp) on NaN", STF_IEEE_TYPES)
{
  auto r = bs::pedantic_(bs::frexp)(bs::Nan<T>());

  STF_IEEE_EQUAL(r.first , bs::Nan<T>());
  STF_EQUAL     (r.second, T(0));
  STF_IEEE_EQUAL(ldexp(r.first,bs::toint(r.second)), bs::Nan<T>());
}
#endif

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>

STF_CASE_TPL("Check behavior of pedantic_(frexp) on infinites", STF_IEEE_TYPES)
{
  auto r = bs::pedantic_(bs::frexp)(bs::Inf<T>());
  auto q = bs::pedantic_(bs::frexp)(bs::Minf<T>());

  STF_IEEE_EQUAL(r.first , bs::Inf<T>());
  STF_EQUAL     (r.second, T(0));
  STF_IEEE_EQUAL(ldexp(r.first,bs::toint(r.second)), bs::Inf<T>());

  STF_IEEE_EQUAL(q.first , bs::Minf<T>());
  STF_EQUAL     (q.second, T(0));
  STF_IEEE_EQUAL(ldexp(q.first,bs::toint(q.second)), bs::Minf<T>());
}
#endif

#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/constant/mindenormal.hpp>

STF_CASE_TPL("Check behavior of pedantic_(frexp) on denormals", STF_IEEE_TYPES)
{
  auto r = bs::pedantic_(bs::frexp)(bs::Mindenormal<T>());

  STF_ULP_EQUAL (r.first, T(0.5), 1);
  STF_EQUAL     (r.second, bs::Minexponent<T>()-bs::Nbmantissabits<T>()+1);
  STF_EQUAL     (ldexp(r.first,bs::toint(r.second)),bs::Mindenormal<T>());
}
#endif
