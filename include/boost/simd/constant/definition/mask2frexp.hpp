//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MASK2FREXP_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MASK2FREXP_HPP_INCLUDED
//TODO
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
    struct mask2frexp_ : boost::dispatch::constant_value_<mask2frexp_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mask2frexp_,boost::dispatch::constant_value_<mask2frexp_>);

      struct value_map
      {
        template<typename X>
        static std::integral_constant<X,0> value(boost::dispatch::integer_<X> const&);

        template<typename X>
        static std::integral_constant<std::int32_t,0x3f000000UL> value(boost::dispatch::single_<X> const&);

        template<typename X>
        static std::integral_constant<std::int64_t,0x3fe0000000000000ULL> value(boost::dispatch::double_<X> const&);
      };
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mask2frexp_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mask2frexp_,mask2frexp);
  }

  template<typename T> BOOST_FORCEINLINE auto Mask2frexp() BOOST_NOEXCEPT
  -> decltype(functional::mask2frexp( boost::dispatch::as_<T>{}))
  {
    return functional::mask2frexp( boost::dispatch::as_<T>{} );
  }
} }

#endif
