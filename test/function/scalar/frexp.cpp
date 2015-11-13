//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/frexp.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/options.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>

STF_CASE_TPL(" frexp0", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::frexp;
  using iT = bd::as_integer_t<T,signed>;

   {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T  a = bs::Mzero<T>();
    frexp(a, m, e);
    STF_ULP_EQUAL(m, bs::Zero<T>(), 0);
    STF_EQUAL(e, bs::Zero<iT>());
    STF_EQUAL(ldexp(m,e),a);
    STF_EXPECT(bs::is_negative(m));
  }
  {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T  a = bs::Zero<T>();
    frexp(a, m, e);
    STF_ULP_EQUAL(m, bs::Zero<T>(), 0);
    STF_EQUAL(e, bs::Zero<iT>());
    STF_EQUAL(ldexp(m,e),a);
    STF_EXPECT(bs::is_positive(m));
  }
  {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T  a = bs::Inf<T>();
    frexp(a, m, e);
    STF_ULP_EQUAL(m, bs::Inf<T>(), 0);
    STF_EQUAL(e, bs::Zero<iT>());
    STF_EQUAL(ldexp(m,e),a);
  }
  {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T  a = bs::Minf<T>();
    frexp(a, m, e);
    STF_ULP_EQUAL(m, bs::Minf<T>(), 0);
    STF_EQUAL(e, bs::Zero<iT>());
    STF_EQUAL(ldexp(m,e),a);
  }
  {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T  a = bs::Valmax<T>();
    frexp(a, m, e);
    STF_ULP_EQUAL(m, bs::One<T>()-bs::Halfeps<T>(), 1);
    STF_EQUAL(e, bs::Limitexponent<T>());
    STF_EQUAL(ldexp(m,e),a);
  }

#ifndef STF_NO_DENORMALS
  {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T a = bs::Mindenormal<T>();
    frexp(a, m, e);
    STF_ULP_EQUAL(m, bs::Half<T>(), 1);
    STF_EQUAL(e, bs::Minexponent<T>()-bs::Nbmantissabits<T>()+bs::One<T>());
    STF_EQUAL(ldexp(m,e),a);
  }

  {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T a = bs::Smallestposval<T>()/2;
    frexp(a, m, e);
    STF_ULP_EQUAL(m, bs::Half<T>(), 1);
    STF_EQUAL(e, bs::Minexponent<T>());
    STF_EQUAL(ldexp(m,e),a);
  }


  {
    namespace bs = boost::simd;
    iT e;
    T  m;
    T a = bs::Smallestposval<T>()/4;
    frexp(a, m, e);
    STF_ULP_EQUAL(m, bs::Half<T>(), 1);
    STF_EQUAL(e, bs::Minexponent<T>()-bs::One<T>());
    STF_EQUAL(ldexp(m,e),a);
  }
#endif

}

STF_CASE_TPL(" frexp", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::frexp;
  using iT = bd::as_integer_t<T,signed>;


  STF_EXPR_IS( (frexp(T()))
             , (std::pair<T,iT>)
             );

  {
    namespace bs = boost::simd;
    iT e;
    T  m;

    frexp(bs::One<T>(), m, e);
    STF_EQUAL(m, bs::Half<T>());
    STF_EQUAL(e, bs::One<iT>());
  }

  {
    namespace bs = boost::simd;
    iT e;
    T  m;

    m = frexp(bs::One<T>(), e);
    STF_EQUAL(m, bs::Half<T>());
    STF_EQUAL(e, bs::One<iT>());
  }

  {
    namespace bs = boost::simd;
    std::pair<T,iT> p;

    p = frexp(bs::One<T>());
    STF_EQUAL(p.first  , bs::Half<T>());
    STF_EQUAL(p.second , bs::One<iT>());
  }
}

STF_CASE_TPL(" frexp fast", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::frexp;
  using bs::fast_;
  using iT = bd::as_integer_t<T,signed>;


  STF_EXPR_IS( (frexp(T(), fast_))
             , (std::pair<T,iT>)
             );

  {
    namespace bs = boost::simd;
    iT e;
    T  m;

    frexp(bs::One<T>(), m, e, fast_);
    STF_EQUAL(m, bs::Half<T>());
    STF_EQUAL(e, bs::One<iT>());
  }

  {
    namespace bs = boost::simd;
    iT e;
    T  m;

    m = frexp(bs::One<T>(), e, fast_);
    STF_EQUAL(m, bs::Half<T>());
    STF_EQUAL(e, bs::One<iT>());
  }

  {
    namespace bs = boost::simd;
    std::pair<T,iT> p;

    p = frexp(bs::One<T>(), fast_);
    STF_EQUAL(p.first  , bs::Half<T>());
    STF_EQUAL(p.second , bs::One<iT>());
  }
}


STF_CASE_TPL(" frexp std", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::frexp;
  using iT = bd::as_integer_t<T,signed>;

   {
    namespace bs = boost::simd;
    iT e;
    T  a = bs::Mzero<T>();
    T m = frexp(a, e, bs::std_);
    STF_ULP_EQUAL(m, bs::Zero<T>(), 0);
    STF_EQUAL(e, bs::Zero<iT>());
    STF_EQUAL(ldexp(m,e),a);
    STF_EXPECT(bs::is_negative(m));
  }
  {
    namespace bs = boost::simd;
    iT e;
    T  a = bs::Zero<T>();
    T m = frexp(a, e, bs::std_);
    STF_ULP_EQUAL(m, bs::Zero<T>(), 0);
    STF_EQUAL(e, bs::Zero<iT>());
    STF_EQUAL(ldexp(m,e),a);
    STF_EXPECT(bs::is_positive(m));
  }
  {
    namespace bs = boost::simd;
    iT e;
    T  a = bs::Inf<T>();
    T m = frexp(a, e, bs::std_);
    STF_ULP_EQUAL(m, bs::Inf<T>(), 0);
    STF_EQUAL(e, bs::Zero<iT>());
    STF_EQUAL(ldexp(m,e),a);
  }
  {
    namespace bs = boost::simd;
    iT e;
    T  a = bs::Minf<T>();
    T m = frexp(a, e, bs::std_);
    STF_ULP_EQUAL(m, bs::Minf<T>(), 0);
    STF_EQUAL(e, bs::Zero<iT>());
    STF_EQUAL(ldexp(m,e),a);
  }
  {
    namespace bs = boost::simd;
    iT e;
    T  a = bs::Valmax<T>();
    T m = frexp(a, e, bs::std_);
    STF_ULP_EQUAL(m, bs::One<T>()-bs::Halfeps<T>(), 1);
    STF_EQUAL(e, bs::Limitexponent<T>());
    STF_EQUAL(ldexp(m,e),a);
  }

#ifndef STF_NO_DENORMALS
  {
    namespace bs = boost::simd;
    iT e;
    T a = bs::Mindenormal<T>();
    T m = frexp(a, e, bs::std_);
    STF_ULP_EQUAL(m, bs::Half<T>(), 1);
    STF_EQUAL(e, bs::Minexponent<T>()-bs::Nbmantissabits<T>()+bs::One<T>());
    STF_EQUAL(ldexp(m,e),a);
  }

  {
    namespace bs = boost::simd;
    iT e;
    T a = bs::Smallestposval<T>()/2;
    T m = frexp(a, e, bs::std_);
    STF_ULP_EQUAL(m, bs::Half<T>(), 1);
    STF_EQUAL(e, bs::Minexponent<T>());
    STF_EQUAL(ldexp(m,e),a);
  }


  {
    namespace bs = boost::simd;
    iT e;
    T a = bs::Smallestposval<T>()/4;
    T m = frexp(a, e, bs::std_);
    STF_ULP_EQUAL(m, bs::Half<T>(), 1);
    STF_EQUAL(e, bs::Minexponent<T>()-bs::One<T>());
    STF_EQUAL(ldexp(m,e),a);
  }
#endif

}
