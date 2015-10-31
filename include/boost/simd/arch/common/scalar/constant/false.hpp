//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_CONSTANT_FALSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_CONSTANT_FALSE_HPP_INCLUDED

#include <boost/simd/logical.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/models.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD ( false_, (typename T), bd::cpu_
                          , bd::target_<bd::scalar_<bd::unspecified_<T>>>
                          )
  {
    static_assert ( bd::models<typename T::type,bd::scalar_<logical_<brigand::_1>>>::type::value
                  , "boost::simd::False requires logical target types"
                  );

    BOOST_FORCEINLINE typename T::type operator()(T const&) const BOOST_NOEXCEPT
    {
      return {false};
    }
  };
} } }


#endif
