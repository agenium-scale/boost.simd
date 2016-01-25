//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/eq.hpp>
#include <boost/simd/sdk/as_logical.hpp>
#include <boost/simd/cardinal_of.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/utility/enable_if.hpp>


#include <boost/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd {

   namespace bs = boost::simd;

  namespace ext
  {
    namespace bd = boost::dispatch;

    BOOST_DISPATCH_OVERLOAD(multiplies_
                           , (typename A0, typename X)
                           , bd::cpu_
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1
                                     ) const BOOST_NOEXCEPT
      {
        A0 r;
        using sA0 = typename A0::value_type;
        for(unsigned int i=0; i < bs::cardinal_of<A0>::value; ++i)
        {
          r[i] =  multiplies(sA0(a0[i]), sA0(a1[i]));
        }
        return r;
      }
    };

  }

  template < typename T, std::size_t N>
  BOOST_FORCEINLINE bs::pack<T, N> operator*( const bs::pack<T, N>& a0
                                            , const bs::pack<T, N>& a1)  BOOST_NOEXCEPT
  {
    return bs::multiplies(a0, a1);
  }

} }

#endif

