//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_ENUMERATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_ENUMERATE_HPP_INCLUDED

#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, enumerate_, boost::dispatch::elementwise_<enumerate_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, enumerate_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::enumerate_,enumerate);
  }

  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::enumerate_, enumerate);

} }

namespace boost { namespace simd
{
  template < class T> T enumerate()
  {
    return enumerate(Zero<T>(), as_<T>());
  }
  template < class T,  class A> T enumerate(const A& a)
  {
    return enumerate(a, as_<T>());
  }
  template < class T,  class A, class B> T enumerate(const A& a, const B& )
  {
    return enumerate(a, as_<T>());
  }
} }

#endif
