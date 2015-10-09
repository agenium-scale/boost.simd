//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_VALMAX_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_VALMAX_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/dispatch/meta/generation/as_integer.hpp>
#include <boost/dispatch/meta/generation/as_unsigned.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>
#include <climits>

namespace boost { namespace simd
{
  namespace tag
  {
    struct valmax_ : boost::dispatch::constant_value_<valmax_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,valmax_,boost::dispatch::constant_value_<valmax_>);

      template<typename T> struct value_map
      {
        template<typename X>
        static std::integral_constant<X,SCHAR_MAX> value(boost::dispatch::int8_<X> const&);

        template<typename X>
        static std::integral_constant<X,SHRT_MAX> value(boost::dispatch::int16_<X> const&);

        template<typename X>
        static std::integral_constant<X,LONG_MAX> value(boost::dispatch::int32_<X> const&);

        template<typename X>
        static std::integral_constant<X,LLONG_MAX> value(boost::dispatch::int64_<X> const&);

        template<typename X>
        static std::integral_constant<X,~X(0)> value(boost::dispatch::uint_<X> const&);

        template<typename X>
        static brigand::single_<0x7F7FFFFF> value(boost::dispatch::single_<X> const&);

        template<typename X>
        static brigand::double_<0x7FEFFFFFFFFFFFFFULL> value(boost::dispatch::double_<X> const&);

        using type = decltype( value(T()) );
      };
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,valmax_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::valmax_,valmax);
  }

  template<typename T> auto Valmax() -> decltype(functional::valmax(boost::dispatch::as_<T>{}))
  {
    return functional::valmax( boost::dispatch::as_<T>{} );
  }
} }

#endif
