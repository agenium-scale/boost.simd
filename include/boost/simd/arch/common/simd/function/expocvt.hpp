//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPOCVT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPOCVT_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/nbexponentbits.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/detail/constant/pow2mask.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;


//   template < class T>
//   void writebits(T ia)
//   {
//     std::string s = "";
//     for (uint32_t i =  0;  i < sizeof(T)*8;  ++i)
//     {
//       s= ((ia == (ia/2)*2) ? "0" :"1")+s;
//     ia >>= T(1);
//     }
//     std::cout << s;
//   }

//   template < class T>
//   void writebits(bs::pack<T> a)
//   {
//     using iT =  bd::as_integer_t<T, unsigned>;

//     std::cout << "("; writebits(bs::bitwise_cast<iT>(a[0]));
//     std::cout << ",  ";
//     writebits(bs::bitwise_cast<iT>(a[1]));
//     std::cout << ")" ;
//   }


//   BOOST_DISPATCH_OVERLOAD_IF ( expocvt_
//                           , (typename A0, typename X)
//                           , (detail::is_native<X>)
//                           , bd::cpu_
//                           , bs::pack_<bd::single_<A0>, X>
//                           )
//   {
//     using result =  bd::as_integer_t<A0, unsigned>;
//     BOOST_FORCEINLINE result operator() ( A0 a0) const BOOST_NOEXCEPT
//     {
//       using sA0 = bd::scalar_of_t<A0>;
//       BOOST_ASSERT_MSG(is_flint(a0), "parameter is not a flint");
//       return bitwise_cast<result>(toint(a0)+Maxexponent<sA0>());
//     }
//   };

  BOOST_DISPATCH_OVERLOAD_IF ( expocvt_
                          , (typename A0, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
  {
    using result =  bd::as_integer_t<A0, unsigned>;
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      using sA0 = bd::scalar_of_t<A0>;
      BOOST_ASSERT_MSG(is_flint(a0), "parameter is not a flint");
      A0 oddv = fma(a0+Maxexponent<sA0>(), Two<sA0>(), (1 << (Nbexponentbits<sA0>()+1)) + 1);
      return shift_left(bitwise_and(Pow2mask<A0>(), oddv), Nbexponentbits<sA0>());
    }
  };

} } }


#endif
