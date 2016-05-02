//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_POW_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_POW_HPP_INCLUDED

#include <boost/simd/arch/common/detail/generic/pow_expander.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/assert.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/function/is_not_nan.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/negif.hpp>
#include <boost/simd/function/pow_abs.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

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

      using u_t =  bd::as_integer_t<A1, unsigned>;
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
      using u_t =  bd::as_integer_t<A1, unsigned>;
      auto ltza1 = is_ltz(a1);
      A0 p = pow(a0, bitwise_cast<u_t>(negif(ltza1, a1)));
      return if_else(ltza1, rec(p), p);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          , bd::scalar_< bd::arithmetic_<A0> >
                          , boost::simd::assert_tag
                           )
  {
    BOOST_FORCEINLINE A0 operator() ( A0  const& a0, A0 const&  a1
                                    , assert_tag const& ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(bs::assert_all((is_positive(a0)&&is_not_nan(a0)) || is_flint(a1)),
                       "pow(a0, a1, assert_) cannot produce complex result." );
      return  pow(a0, a1);
    }
  };

} } }


#endif
