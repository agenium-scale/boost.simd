//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/simd/make.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <algorithm>
#include <simd_test.hpp>

#if !(defined(BOOST_INTEL_CXX_VERSION) && BOOST_INTEL_CXX_VERSION < 1600)
// Unless variadic template support sucks big time, these must be tested

STF_CASE_TPL( "Check make(a0,a1)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<bs::logical<T>,2> ref = {{ true,false }};
  auto p = bs::make<bs::pack<bs::logical<T>,2>>(true,false);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(a0,...,a3)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  std::array<bs::logical<T>,4> ref = {{ true,false,false,true }};
  auto p = bs::make<bs::pack<bs::logical<T>,4>>(true,false,false,true);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(a0,...,a7)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  std::array<bs::logical<T>,8> ref = {{ true,false,false,true,true,false,false,true }};
  auto p = bs::make<bs::pack<bs::logical<T>,8>>(true,false,false,true,true,false,false,true);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(a0,...,a15)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<bs::logical<T>,16> ref  =  {{  true,false,false,true,true,false,false,true
                                        ,   true,false,false,true,true,false,false,true
                                        }};

  auto p = bs::make< bs::pack<bs::logical<T>,16> >
                    ( true,false,false,true,true,false,false,true
                    , true,false,false,true,true,false,false,true
                    );

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(a0,...,a31)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<bs::logical<T>,32> ref = {{  true,false,false,true,true,false,false,true
                                      ,   true,false,false,true,true,false,false,true
                                      ,   true,false,false,true,true,false,false,true
                                      ,   true,false,false,true,true,false,false,true
                                      }};

  auto p = bs::make< bs::pack<bs::logical<T>,32> >
                    ( true,false,false,true,true,false,false,true
                    , true,false,false,true,true,false,false,true
                    , true,false,false,true,true,false,false,true
                    , true,false,false,true,true,false,false,true
                    );

  STF_ALL_EQUAL(p, ref);
}

#endif // BOOST_INTEL_CXX_VERSION

// These must work anyway

STF_CASE_TPL( "Check make(as_<tag>{},a0,a1)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<bs::logical<T>,2> ref = {{ true,false }};
  auto p = bs::make(bs::as_<bs::pack<bs::logical<T>,2>>{}, true,false);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(as_<tag>{},a0,...,a3)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  std::array<bs::logical<T>,4> ref = {{ true,false,false,true }};
  auto p = bs::make(bs::as_<bs::pack<bs::logical<T>,4>>{}, true,false,false,true);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(as_<tag>{},a0,...,a7)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  std::array<bs::logical<T>,8> ref = {{ true,false,false,true,true,false,false,true }};
  auto p = bs::make(bs::as_<bs::pack<bs::logical<T>,8>>{},true,false,false,true,true,false,false,true);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(as_<tag>{},a0,...,a15)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<bs::logical<T>,16> ref  =  {{  true,false,false,true,true,false,false,true
                                        ,   true,false,false,true,true,false,false,true
                                        }};

  auto p = bs::make(bs::as_< bs::pack<bs::logical<T>,16> >{}
                   , true,false,false,true,true,false,false,true
                   , true,false,false,true,true,false,false,true
                   );

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(as_<tag>{},a0,...,a31)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<bs::logical<T>,32> ref = {{  true,false,false,true,true,false,false,true
                                      ,   true,false,false,true,true,false,false,true
                                      ,   true,false,false,true,true,false,false,true
                                      ,   true,false,false,true,true,false,false,true
                                      }};

  auto p = bs::make(bs::as_< bs::pack<bs::logical<T>,32> >{}
                    , true,false,false,true,true,false,false,true
                    , true,false,false,true,true,false,false,true
                    , true,false,false,true,true,false,false,true
                    , true,false,false,true,true,false,false,true
                    );

  STF_ALL_EQUAL(p, ref);
}
