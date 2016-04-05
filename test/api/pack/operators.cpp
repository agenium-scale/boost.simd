//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/simd/function/plus.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

#undef STF_EQUAL
#define STF_EQUAL(a, b) $.stream() << a << " == " << b << std::endl

struct auto_nothing {
    template <typename T, typename U>
    BOOST_FORCEINLINE T operator()(T const& a, U const&) const { return a; }

    template <typename T, typename U>
    BOOST_FORCEINLINE void equal(T&, U const&) const {}
};

#define AUTO_ARITHMETIC_OP(name, sym)                                                              \
  struct name {                                                                                    \
    template <typename T, typename U>                                                              \
    BOOST_FORCEINLINE auto operator()(T const& a, U const& b) const                                \
    BOOST_NOEXCEPT_DECLTYPE_BODY(a sym b)                                                          \
                                                                                                   \
    template <typename T, typename U>                                                              \
    BOOST_FORCEINLINE void equal(T& a, U const& b) const                                           \
    { a BOOST_PP_CAT(sym, =) b; }                                                                  \
  }                                                                                                \
  /**/

#define AUTO_LOGICAL_OP(name, sym)                                                                 \
  struct name {                                                                                    \
    template <typename T, typename U>                                                              \
    BOOST_FORCEINLINE auto operator()(T const& a, U const& b) const                                \
    BOOST_NOEXCEPT_DECLTYPE_BODY(a sym b)                                                          \
  }                                                                                                \
  /**/

AUTO_ARITHMETIC_OP(auto_add, +);
AUTO_ARITHMETIC_OP(auto_sub, -);
AUTO_ARITHMETIC_OP(auto_mul, *);
AUTO_ARITHMETIC_OP(auto_div, /);
AUTO_ARITHMETIC_OP(auto_mod, %);

AUTO_LOGICAL_OP(auto_lt, <);
AUTO_LOGICAL_OP(auto_gt, >);
AUTO_LOGICAL_OP(auto_le, <=);
AUTO_LOGICAL_OP(auto_ge, >=);

template <typename P, typename T, typename U, typename Op, typename Env>
void test_op(Env& $, T const& s0, U const& s1, Op const& op)
{
  P p0(s0);
  P p1(s1);
  P ref = P(op(s0, s1));

  STF_EQUAL(op(p0, p1), ref);
  STF_EQUAL(op(s0, p1), ref);
  STF_EQUAL(op(p0, s1), ref);

  op.equal(p0, p1);
  STF_EQUAL(p0, ref);
}

template <typename P, typename T, typename U, typename Op, typename Env>
void test_logical_op(Env& $, T const& s0, U const& s1, Op const& op)
{
  P p0(s0);
  P p1(s1);
  P ref0 = P(boost::simd::logical<typename P::value_type>(op(s0, s1)));
  P ref1 = P(boost::simd::logical<typename P::value_type>(op(s1, s0)));

  STF_EQUAL(op(p0, p1), ref0);
  STF_EQUAL(op(s0, p1), ref0);
  STF_EQUAL(op(p0, s1), ref0);

  STF_EQUAL(op(p1, p0), ref1);
  STF_EQUAL(op(s1, p0), ref1);
  STF_EQUAL(op(p1, s0), ref1);
}

template <typename P, typename T, typename Env>
void test_unary_op(Env& $, T const& s0)
{
  //STF_EQUAL(!P(s0), P(!s0));
  STF_EQUAL(~P(s0), P(~s0));

  STF_EQUAL(-P(s0), P(-s0));
  STF_EQUAL(+P(s0), P(+s0));

  {
    P p(s0);
    STF_EQUAL(++p, P(s0 + T(1)));
  }
  {
    P p(s0);
    STF_EQUAL(p++, P(s0));
    STF_EQUAL(p,   P(s0 + T(1)));
  }

  {
    P p(s0);
    STF_EQUAL(--p, P(s0 - T(1)));
  }
  {
    P p(s0);
    STF_EQUAL(p--, P(s0));
    STF_EQUAL(p,   P(s0 - T(1)));
  }
}

template <typename T, std::size_t N, typename U, typename V, typename Env>
void test(Env& $, U const& s0, V const& s1)
{
  STF_INFO("With N = " << N);
  using p_t = boost::simd::pack<T, N>;
  using auto_mod_or_nothing =
    typename std::conditional<std::is_integral<T>::value, auto_mod, auto_nothing>::type;

  test_op<p_t>($, s0, s1, auto_add());
  test_op<p_t>($, s0, s1, auto_sub());
  test_op<p_t>($, s0, s1, auto_mul());
  test_op<p_t>($, s0, s1, auto_div());
  test_op<p_t>($, s0, s1, auto_mod_or_nothing());

  test_unary_op<p_t>($, s0);

#if 0
  test_logical_op<p_t>($, s0, s1, auto_lt());
  test_logical_op<p_t>($, s0, s1, auto_le());
  test_logical_op<p_t>($, s0, s1, auto_gt());
  test_logical_op<p_t>($, s0, s1, auto_ge());
#endif
}

STF_CASE_TPL("Check pack's operators", STF_NUMERIC_TYPES)
{
  test<T,  2>($, 2, 4);
  test<T,  4>($, 2, 4);
  test<T,  8>($, 2, 4);
  //test<T, 16>($, 2, 4);
  //test<T, 32>($, 2, 4);
}
