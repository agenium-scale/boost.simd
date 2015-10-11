//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MINF_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MINF_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/simd/constant/definition/valmin.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

//TODO link it to valmin  for integers if possible to avoid duplication
namespace boost { namespace simd
{
  namespace tag
  {
    struct minf_ : boost::dispatch::constant_value_<minf_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,minf_,boost::dispatch::constant_value_<minf_>);

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
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,minf_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::minf_,minf);
  }

  template<typename T> BOOST_FORCEINLINE auto Minf() BOOST_NOEXCEPT
  -> decltype(functional::minf(boost::dispatch::as_<T>{}))
  {
    return functional::minf( boost::dispatch::as_<T>{} );
  }
} }

#endif

