//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED

#include <boost/simd/sdk/masked.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/std/iterator.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;

  //------------------------------------------------------------------------------------------------
  // aligned_load from an input iterator
  BOOST_DISPATCH_OVERLOAD ( aligned_load_
                          , (typename Target, typename Pointer)
                          , bd::cpu_
                          , bd::input_iterator_<bd::scalar_<bd::unspecified_<Pointer>>>
                          , bd::target_< bd::scalar_<bd::unspecified_<Target>> >
                          )
  {
    using target = typename Target::type;

    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const BOOST_NOEXCEPT
    {
      return static_cast<target>(*p);
    }
  };

  //------------------------------------------------------------------------------------------------
  // aligned_load from a masked pointer
  BOOST_DISPATCH_OVERLOAD ( aligned_load_
                          , (typename Target, typename Pointer)
                          , bd::cpu_
                          , bd::masked_pointer_<bd::scalar_<bd::unspecified_<Pointer>>>
                          , bd::target_< bd::scalar_<bd::unspecified_<Target>> >
                          )
  {
    using target = typename Target::type;

    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const BOOST_NOEXCEPT
    {
      return p.mask() ? boost::simd::aligned_load<target>(p.get()) : static_cast<target>(p.value());
    }
  };
} } }

#endif
