//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_CONSTANT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_CONSTANT_HPP_INCLUDED

#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <cstdint>

namespace boost { namespace simd
{
  namespace tag
  {
    struct constant_ : boost::dispatch::constant_value_<constant_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,constant_,boost::dispatch::constant_value_<constant_>);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,constant_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::constant_,constant);
  }

  template<typename Type, std::uintmax_t Bits>
  BOOST_FORCEINLINE     auto Constant() BOOST_NOEXCEPT
                    ->  decltype(detail::constant(typename detail::constantify<Type,Bits>::type{}))
  {
    return detail::constant( typename detail::constantify<Type,Bits>::type{} );
  }
} }

#endif
