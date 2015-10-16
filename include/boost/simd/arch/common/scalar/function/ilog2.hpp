//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ILOG2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ILOG2_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/clz.hpp>
#include <boost/simd/function/scalar/exponent.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( ilog2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0> operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return exponent(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( ilog2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG( a0 > 0, "Logarithm is not defined for zero or negative values." );
      return A0(sizeof(A0)*8-bs::clz(a0)-1);
    }
  };

#if defined(BOOST_MSVC)
  BOOST_DISPATCH_OVERLOAD ( ilog2_
                          , (typename A0)
                          , bd::cpu_
                          , (mpl::less_equal< mpl::sizeof_<A0>, mpl::size_t<4> >)
                          , bd::scalar_< bd::integer_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0  a0) const BOOST_NOEXCEPT
    {
      return impl(a0, typename brigand::bool_<sizeof(A0) <= 4>::type());
    }

    static BOOST_FORCEINLINE A0 impl( A0  a0,  brigand::true_ const &) BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG( a0 > 0, "Logarithm is not defined for zero or negative values." );
      __assume( a0 > 0 );
      unsigned long index;
      BOOST_VERIFY(::_BitScanReverse(&index, a0));
      return A0(index);
    }
#if defined(_WIN64)
    static BOOST_FORCEINLINE A0 impl( A0  a0,  brigand::false_ const &) BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG( a0 > 0, "Logarithm is not defined for zero or negative values." );
      __assume( a0 > 0 );
      unsigned long index;
      BOOST_VERIFY(::_BitScanReverse64(&index, a0));
      return index;
    };
#else
    static BOOST_FORCEINLINE A0 impl( A0  a0,  brigand::false_ const &) BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG( a0 > 0, "Logarithm is not defined for zero or negative values." );
      return A0(sizeof(A0)*8-bs::clz(a0)-1);
    };
#endif
#endif

} } }


#endif
