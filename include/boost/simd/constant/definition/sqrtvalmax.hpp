//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_SQRTVALMAX_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_SQRTVALMAX_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct sqrtvalmax_ : boost::dispatch::constant_value_<sqrtvalmax_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,sqrtvalmax_,boost::dispatch::constant_value_<sqrtvalmax_>);

      struct value_map
      {
        template<typename X>
        static brigand::single_<0x5f7FFFFEU> value(boost::dispatch::single_<X> const&);
        template<typename X>
        static brigand::double_<0x5fEFFFFFFFFFFFFFULL> value(boost::dispatch::double_<X> const&);
        template<typename X>
        static std::integral_constant<X,15> value(boost::dispatch::uint8_<X> const&);

        template<typename X>
        static std::integral_constant<X,255> value(boost::dispatch::uint16_<X> const&);

        template<typename X>
        static std::integral_constant<X,65535> value(boost::dispatch::uint32_<X> const&);

        template<typename X>
        static std::integral_constant<X,4294967296ULL> value(boost::dispatch::uint64_<X> const&);
        template<typename X>
        static std::integral_constant<X,11> value(boost::dispatch::int8_<X> const&);

        template<typename X>
        static std::integral_constant<X,181> value(boost::dispatch::int16_<X> const&);

        template<typename X>
        static std::integral_constant<X,46340> value(boost::dispatch::int32_<X> const&);

        template<typename X>
        static std::integral_constant<X,3037000499LL> value(boost::dispatch::int64_<X> const&);
      };
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,sqrtvalmax_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::sqrtvalmax_,sqrtvalmax);
  }

  template<typename T> BOOST_FORCEINLINE auto Sqrtvalmax() BOOST_NOEXCEPT
  -> decltype(functional::sqrtvalmax( boost::dispatch::as_<T>{}))
  {
    return functional::sqrtvalmax( boost::dispatch::as_<T>{} );
  }
} }

#endif
