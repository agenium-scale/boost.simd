//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_DIV_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_DIV_HPP_INCLUDED

#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/iceil.hpp>
#include <boost/simd/function/ifloor.hpp>
#include <boost/simd/function/iround.hpp>
#include <boost/simd/function/iround2even.hpp>
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/round.hpp>
#include <boost/simd/function/round2even.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
#ifdef BOOST_MSVC
  #pragma warning(push)
  #pragma warning(disable: 4723) // potential divide by 0
#endif

  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::ifix_
                          , bd::generic_<bd::floating_<T>>
                          , bd::generic_<bd::floating_<T>>
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<T> operator()( bd::functor<bs::tag::ifix_> const&
                                                    , T const& a, T const& b ) const BOOST_NOEXCEPT
    {
      return saturated_(toint)(a/b);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::iceil_
                          , bd::generic_<bd::floating_<T>>
                          , bd::generic_<bd::floating_<T>>
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<T> operator()( bd::functor<bs::tag::iceil_> const&
                                                    , T const& a, T const& b ) const BOOST_NOEXCEPT
    {
      return iceil(a/b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::ifloor_
                          , bd::generic_<bd::floating_<T>>
                          , bd::generic_<bd::floating_<T>>
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<T> operator()( bd::functor<bs::tag::ifloor_> const&
                                                    ,T const& a, T const& b) const BOOST_NOEXCEPT
    {
      return ifloor(a/b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::iround_
                          , bd::generic_<bd::floating_<T>>
                          , bd::generic_<bd::floating_<T>>
                          )
  {
    BOOST_FORCEINLINE  bd::as_integer_t<T>  operator()( bd::functor<bs::tag::iround_> const&
                                                      ,T const& a, T const& b) const BOOST_NOEXCEPT
    {
      return iround(a/b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::iround2even_
                          , bd::generic_<bd::floating_<T>>
                          , bd::generic_<bd::floating_<T>>
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<T> operator()( bd::functor<bs::tag::iround2even_> const&
                                                    ,T const& a, T const& b) const BOOST_NOEXCEPT
    {
      return iround2even(a/b);
    }
  };

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::ifix_
                          , bd::generic_<bd::integer_<T>>
                          , bd::generic_<bd::integer_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()( bd::functor<bs::tag::ifix_> const&
                                                    , T const& a, T const& b ) const BOOST_NOEXCEPT
    {
      return  div(fix, a, b);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::iceil_
                          , bd::generic_<bd::integer_<T>>
                          , bd::generic_<bd::integer_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()( bd::functor<bs::tag::iceil_> const&
                                                    , T const& a, T const& b ) const BOOST_NOEXCEPT
    {
      return div(ceil, a, b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::ifloor_
                          , bd::generic_<bd::integer_<T>>
                          , bd::generic_<bd::integer_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()( bd::functor<bs::tag::ifloor_> const&
                                                    ,T const& a, T const& b) const BOOST_NOEXCEPT
    {
      return  div(floor, a, b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::iround_
                          , bd::generic_<bd::integer_<T>>
                          , bd::generic_<bd::integer_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()( bd::functor<bs::tag::iround_> const&
                                                    ,T const& a, T const& b) const BOOST_NOEXCEPT
    {
      return div(round, a, b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::iround2even_
                          , bd::generic_<bd::integer_<T>>
                          , bd::generic_<bd::integer_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()( bd::functor<bs::tag::iround2even_> const&
                                  ,T const& a, T const& b) const BOOST_NOEXCEPT
    {
      return  div(round2even, a, b);
    }
  };


} } }

#endif
