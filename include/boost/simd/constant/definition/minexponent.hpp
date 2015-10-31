//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MINEXPONENT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MINEXPONENT_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>
//TODO
namespace boost { namespace simd
{
  namespace tag
  {
    struct minexponent_ : boost::dispatch::constant_value_<minexponent_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,minexponent_,boost::dispatch::constant_value_<minexponent_>);

      struct value_map
      {
        template<typename X>
        static std::integral_constant<X,0> value(boost::dispatch::integer_<X> const&);

        template<typename X>
        static std::integral_constant<std::int32_t,-126> value(boost::dispatch::single_<X> const&);

        template<typename X>
       static std::integral_constant<std::int64_t,-1022> value(boost::dispatch::double_<X> const&);
      };
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,minexponent_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::minexponent_,minexponent);
  }

  template<typename T> BOOST_FORCEINLINE auto Minexponent() BOOST_NOEXCEPT
  -> decltype(functional::minexponent( boost::dispatch::as_<T>{}))
  {
    return functional::minexponent( boost::dispatch::as_<T>{} );
  }
} }

#endif
