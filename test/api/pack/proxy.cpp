//==================================================================================================
/*
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/simd/pack.hpp>
#include <numeric>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  // T(...) cast operator and assignment
  {
    std::array<T, N> a;
    std::iota(a.begin(), a.end(), T(1));
    bs::pack<T, N> p0(a.begin(), a.end()), ref(a.begin(), a.end());

    std::transform(p0.begin(),p0.end(),ref.begin(), [](T e) { return e; } );
    STF_EXPECT(( std::equal(ref.begin(),ref.end(), a.begin()) ));
  }

  // ==
  {
    std::array<T, N> a;
    std::iota(a.begin(), a.end(), T(1));
    bs::pack<T, N> p0(a.begin(), a.end()), ref(a.begin(), a.end());

    bool compares_equals = true;
    for (auto it0 = p0.begin(); it0 != p0.end() ; ++it0)
      compares_equals = compares_equals && (*it0 == *it0);

    STF_EXPECT( compares_equals );
  }

  // !=
  {
    std::array<T, N> a;
    std::iota(a.begin(), a.end(), T(1));
    bs::pack<T, N> p0(a.begin(), a.end()), ref(a.begin(), a.end());

    bool compares_not_equals = true;
    for (auto it0 = p0.begin(); it0 != p0.end() ; ++it0)
      compares_not_equals = compares_not_equals && ((*it0+1) != *it0);

    STF_EXPECT( compares_not_equals );
  }

  // !
  {
    std::array<T, N> a;
    std::iota(a.begin(), a.end(), T(1));
    bs::pack<T, N> p0(a.begin(), a.end()), ref(a.begin(), a.end());

    bool supports_logical_not = true;
    for (auto it0 = p0.begin(); it0 != p0.end(); ++it0)
      supports_logical_not = supports_logical_not && !(!(*it0));

    STF_EXPECT( supports_logical_not );
  }

  // a ? b
  {
    std::array<T, N> a;
    std::iota(a.begin(), a.end(), T(1));
    bs::pack<T, N> p0(a.begin(), a.end()), ref(a.begin(), a.end());

    bool supports_plus    = true;
    bool supports_minus   = true;
    bool supports_times   = true;
    bool supports_divides = true;

    auto it0 = p0.begin();
    auto it1 = a.begin();

    for (; it0 != p0.end() && it1 != a.end(); ++it0, ++it1)
    {
      supports_plus    = supports_plus    && ((*it0 + *it0) == T(*it1 + *it1));
      supports_minus   = supports_minus   && ((*it0 - *it0) == T(*it1 - *it1));
      supports_times   = supports_times   && ((*it0 * *it0) == T(*it1 * *it1));
      supports_divides = supports_divides && ((*it0 / *it0) == T(*it1 / *it1));
    }

    STF_EXPECT( supports_plus     );
    STF_EXPECT( supports_minus    );
    STF_EXPECT( supports_times    );
    STF_EXPECT( supports_divides  );
  }

  // a ?= b
  {
    std::array<T, N> a;
    std::iota(a.begin(), a.end(), T(1));

    bool supports_plus_assign    = true;
    bool supports_minus_assign   = true;
    bool supports_times_assign   = true;
    bool supports_div_assign = true;
    T inc{2};

    bs::pack<T, N> p0 = bs::pack<T, N>(a.begin(), a.end());
    auto it0 = p0.begin();
    auto it1 = a.begin();
    for (; it0 != p0.end() && it1 != a.end(); ++it0, ++it1)
      supports_plus_assign = supports_plus_assign && ((*it0 += inc) == T(*it1 + inc));

    it0 = p0.begin();
    it1 = a.begin();
    p0 = bs::pack<T, N>(a.begin(), a.end());
    for (; it0 != p0.end() && it1 != a.end(); ++it0, ++it1)
      supports_minus_assign = supports_minus_assign && ((*it0 -= inc) == T(*it1 - inc));

    it0 = p0.begin();
    it1 = a.begin();
    p0 = bs::pack<T, N>(a.begin(), a.end());
    for (; it0 != p0.end() && it1 != a.end(); ++it0, ++it1)
      supports_times_assign = supports_times_assign && ((*it0 *= inc) == T(*it1 * inc));

    it0 = p0.begin();
    it1 = a.begin();
    p0 = bs::pack<T, N>(a.begin(), a.end());
    for (; it0 != p0.end() && it1 != a.end(); ++it0, ++it1)
      supports_div_assign = supports_div_assign && ((*it0 /= inc) == T(*it1 / inc));

    STF_EXPECT( supports_plus_assign  );
    STF_EXPECT( supports_minus_assign );
    STF_EXPECT( supports_times_assign );
    STF_EXPECT( supports_div_assign   );
  }
}

STF_CASE_TPL( "Check pack's operators" , STF_NUMERIC_TYPES)
{
  test<T,  2>($);
  test<T,  4>($);
  test<T,  8>($);
  test<T, 16>($);
  test<T, 32>($);
}
