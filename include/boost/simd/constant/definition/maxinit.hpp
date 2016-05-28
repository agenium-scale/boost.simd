//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MAXINIT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MAXINIT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/simd/constant/definition/valmin.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct maxinit_ : boost::dispatch::constant_value_<maxinit_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,maxinit_,boost::dispatch::constant_value_<maxinit_>);

      struct value_map
      {
        template<typename X>
        static auto value(X const& x) -> decltype(valmin_::value_map::value(x));

        template<typename X>
        static brigand::single_<0xFF800000U> value(boost::dispatch::single_<X> const&);

        template<typename X>
        static brigand::double_<0xFFF0000000000000ULL> value(boost::dispatch::double_<X> const&);
      };
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,maxinit_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::maxinit_,maxinit);
  }

  template<typename T> BOOST_FORCEINLINE auto Maxinit()
  BOOST_NOEXCEPT_DECLTYPE(detail::maxinit( boost::dispatch::as_<T>{}))
  {
    return detail::maxinit( boost::dispatch::as_<T>{} );
  }
} }

#endif
