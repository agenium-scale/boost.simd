//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MLOGEPS2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MLOGEPS2_HPP_INCLUDED

#include <boost/simd/config.hpp>
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
    struct mlogeps2_ : boost::dispatch::constant_value_<mlogeps2_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mlogeps2_,boost::dispatch::constant_value_<mlogeps2_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x40FF1402UL, 0x403205966F2B4F13ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mlogeps2_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mlogeps2_,mlogeps2);
  }

  template<typename T> BOOST_FORCEINLINE auto Mlogeps2() BOOST_NOEXCEPT
  -> decltype(functional::mlogeps2( boost::dispatch::as_<T>{}))
  {
    return functional::mlogeps2( boost::dispatch::as_<T>{} );
  }
} }

#endif
