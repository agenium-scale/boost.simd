//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_GENERIC_POW_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_GENERIC_POW_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/function/pow_abs.hpp>
#include <boost/simd/constant/nan.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  template<std::uintmax_t Exp, std::uintmax_t Odd = Exp%2>
  struct pow_expander;

  template<std::uintmax_t Exp>
  struct pow_expander<Exp, 0ULL>
  {
    template<class A0>
    static BOOST_FORCEINLINE A0 call( A0 const& a0) BOOST_NOEXCEPT
    {
      return pow_expander<Exp/2>::call(sqr(a0));
    }
  };

  template<std::uintmax_t Exp>
  struct pow_expander<Exp, 1ULL>
  {
    template<class A0>
    static BOOST_FORCEINLINE A0 call( A0 const& a0) BOOST_NOEXCEPT
    {
      return a0*pow_expander<Exp/2>::call(sqr(a0));
    }
  };

  template<>
  struct pow_expander<0ULL, 0ULL>
  {
    template<class A0>
    static BOOST_FORCEINLINE A0 call( A0 const&) BOOST_NOEXCEPT
    {
      return One<A0>();
    }
  };

  template<>
  struct pow_expander<0ULL, 1ULL>
  {
    template<class A0>
    static BOOST_FORCEINLINE A0 call( A0 const&) BOOST_NOEXCEPT
    {
      return One<A0>();
    }
  };

  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bd::constant_< bd::scalar_< bd::uint_<A1> > >
                          )
  {
    using result_type = A0;

    BOOST_FORCEINLINE result_type operator() ( A0 const& a0, A1) const BOOST_NOEXCEPT
    {
      return pow_expander<A1::value>::call(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::constant_< bd::scalar_< bd::int_<A1> > >
                          )
  {
    using result_type = A0;

    BOOST_FORCEINLINE result_type operator() ( A0 const& a0, A1) const BOOST_NOEXCEPT
    {
      return eval(a0, boost::mpl::bool_<(A1::value >= 0)>());
    }

    BOOST_FORCEINLINE result_type eval( A0 const& a0, boost::mpl::true_) const BOOST_NOEXCEPT
    {
      return pow_expander<A1::value>::call(a0);
    }

    BOOST_FORCEINLINE result_type eval( A0 const& a0, boost::mpl::false_) const BOOST_NOEXCEPT
    {
      return pow_expander<-A1::value>::call(rec(a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bd::scalar_< bd::uint_<A1> >
                          )
  {
    using result_type = A0;

    A0 operator() ( A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      A0 base = a0;
      A1 exp = a1;

      result_type result = One<result_type>();
      while(exp)
      {
        if(is_odd(exp))
          result *= base;
        exp >>= 1;
        base = sqr(base);
      }

      return result;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::integer_<A0> >
                          , bd::generic_< bd::int_<A1> >
                          )
  {
    using result_type = A0;

    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG( boost::simd::assert_all(a1 >= 0), "integral pow with signed exponent" );

      using u_t =  bd::as_integer_t<A1>;
      return pow(a0, bitwise_cast<u_t>(a1));
    }
  };


  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::int_<A1> >
                          )
  {
    using result_type = A0;

    A0 operator() ( A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      using u_t =  bd::as_integer_t<A1>;
      auto ltza1 = is_ltz(a1);
      A0 p = pow(a0, bitwise_cast<u_t>(negif(ltza1, a1)));
      return if_else(ltza1, rec(p), p);
    }
  };
} } }


#endif
