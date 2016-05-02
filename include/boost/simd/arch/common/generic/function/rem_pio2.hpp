//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REM_PIO2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REM_PIO2_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/simd/rem_pio2_cephes.hpp>
#include <boost/simd/function/simd/rem_pio2_medium.hpp>
#include <boost/simd/function/simd/rem_pio2_straight.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <boost/fusion/tuple.hpp>


namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( rem_pio2_
                          , (typename A0)
                          ,  bd::cpu_
                          ,  bd::generic_ < bd::floating_<A0> >
                          )
  {
    using itype = bd::as_integer_t<A0>;
    using result = boost::fusion::tuple<itype,A0,A0>;

    BOOST_FORCEINLINE result operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 second, third;
      itype const first = rem_pio2(a0, second,third);
      return result(first, second, third); //brace constructor is explicit in copy initialisation.
    }
  };

  BOOST_DISPATCH_OVERLOAD (rem_pio2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_ < bd::floating_<A0> >
                          , bd::generic_ < bd::floating_<A0> >
                          )
  {
    using result = bd::as_integer_t<A0>;
    BOOST_FORCEINLINE result operator() ( A0 const& a0,
                                            A0 & xr) const BOOST_NOEXCEPT
    {
      A0 xc;
      return rem_pio2(a0, xr, xc);
    }
  };


  BOOST_DISPATCH_OVERLOAD ( rem_pio2_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_ <bd::floating_<A0>  >
                          , bd::generic_ <bd::floating_<A0>  >
                          , bd::target_ <bd::unspecified_<A1> >
                          )
  {
    using result = bd::as_integer_t<A0>;

    BOOST_FORCEINLINE result operator() ( A0 const& a0, A0 & xr, A1 const&) const BOOST_NOEXCEPT
    {
      typedef typename A1::type selector;
      return rempio2<selector, void>::rem(a0, xr);
    }

    template < class T, class dummy = void> struct rempio2
    {
      static BOOST_FORCEINLINE result rem( A0 const&, A0 &) BOOST_NOEXCEPT
      {
        BOOST_ASSERT_MSG(false, "wrong target for rem_pio2");
        return Zero<result>();
      }
    };

    template < class dummy> struct rempio2 < tag::big_tag, dummy>
    {
      static BOOST_FORCEINLINE result rem( A0 const& x, A0 & xr) BOOST_NOEXCEPT
      {
        return rem_pio2(x, xr);
      }
    };

    template < class dummy> struct rempio2 < tag::very_small_tag, dummy >
    {
      static BOOST_FORCEINLINE result rem( A0 const& x, A0 & xr) BOOST_NOEXCEPT
      {
        return rem_pio2_straight(x, xr);
      }
    };

    template < class dummy> struct rempio2 < tag::small_tag, dummy >
    {
      static BOOST_FORCEINLINE result rem( A0 const& x, A0 & xr) BOOST_NOEXCEPT
      {
        return rem_pio2_cephes(x, xr);
      }
    };

    template < class dummy> struct rempio2 < tag::medium_tag, dummy >
    {
      static BOOST_FORCEINLINE result rem( A0 const& x, A0 & xr) BOOST_NOEXCEPT
      {
        return rem_pio2_medium(x, xr);
      }
    };
  };

} } }


#endif
