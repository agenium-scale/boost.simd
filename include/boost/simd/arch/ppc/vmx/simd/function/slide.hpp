//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SLIDE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SLIDE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/meta/as_arithmetic.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  // -----------------------------------------------------------------------------------------------
  // Unary slide
  BOOST_DISPATCH_OVERLOAD ( slide_
                          , (typename T, typename Offset)
                          , bs::vmx_
                          , bs::pack_< bd::arithmetic_<T>, bs::vmx_ >
                          , bd::constant_<bd::integer_<Offset>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a0, Offset const&) const
    {
      return eval(a0, brigand::bool_<(Offset::value>=0)>{});
    }

    BOOST_FORCEINLINE T eval( T const& a0, std::true_type const& ) const
    {
      using offset = std::integral_constant < char
                                            , ( Offset::value
                                              * sizeof(typename T::value_type)
                                              )<<3
                                            >;

      __vector unsigned char const s = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,offset::value};
      return vec_slo( a0.storage(),s );
    }

    BOOST_FORCEINLINE T eval( T const& a0, std::false_type const& ) const
    {
      using offset = std::integral_constant < char
                                            , ( (-Offset::value)
                                              * sizeof(typename T::value_type)
                                              )<<3
                                            >;

      __vector unsigned char const s = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,offset::value};
      return vec_sro( a0.storage(), s );
    }
  };

  BOOST_DISPATCH_OVERLOAD ( slide_
                          , (typename T, typename Offset)
                          , bs::vmx_
                          , bs::pack_< bs::logical_<T>, bs::vmx_ >
                          , bd::constant_<bd::integer_<Offset>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a0, Offset const&) const
    {
      return bitwise_cast<T>(slide<Offset::value>(bitwise_cast<as_arithmetic_t<T>>(a0)));
    }
  };


  BOOST_DISPATCH_OVERLOAD ( slide_
                          , (typename T, typename Offset)
                          , bs::vmx_
                          , bs::pack_< bs::logical_<T>, bs::vmx_ >
                          , bd::constant_<bd::integer_<Offset>>
                          , bd::constant_<bd::integer_<Offset>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a0, T const& a1, Offset const&) const
    {
      return bitwise_cast<T>(slide<Offset::value> ( bitwise_cast<as_arithmetic_t<T>>(a0)
                                                  , bitwise_cast<as_arithmetic_t<T>>(a1)
                                                  )
                            );
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Binary slide
  BOOST_DISPATCH_OVERLOAD ( slide_
                          , (typename T, typename Offset)
                          , bs::vmx_
                          , bs::pack_< bd::arithmetic_<T>, bs::vmx_ >
                          , bs::pack_< bd::arithmetic_<T>, bs::vmx_ >
                          , bd::constant_<bd::integer_<Offset>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a0, T const& a1, Offset const&) const
    {
      using offset = std::integral_constant<int, Offset::value* sizeof(typename T::value_type)>;
      return vec_sld( a0.storage(), a1.storage() , offset::value );
    }
  };
} } }

#endif
