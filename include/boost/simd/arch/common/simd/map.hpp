//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_MAP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_MAP_HPP_INCLUDED

#include <boost/simd/function/simd/insert.hpp>
#include <boost/simd/function/simd/extract.hpp>
#include <boost/simd/function/simd/make.hpp>
#include <boost/simd/operator/specific/utils.hpp>
#include <boost/simd/sdk/simd/meta/vector_of.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

#define BOOST_SIMD_MAX_LOG2_CARDINAL_MAKE_MAP 3

#if !defined(BOOST_SIMD_DONT_USE_PREPROCESSED_FILES)
#include <boost/simd/operator/function/simd/common/preprocessed/map.hpp>
#else
#include <boost/dispatch/details/parameters.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/slot/slot.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;

   BOOST_DISPATCH_OVERLOAD(map_

                          , bd::cpu
                          , )

  {
using  = ;
    BOOST_FORCEINLINE result operator()(Func const& f, BOOST_PP_ENUM_BINARY_PARAMS(n, A, const & a)) const
    {
      return impl<N>::call(f, BOOST_PP_ENUM_PARAMS(n, a));
    }
  };


  #undef n

#elif BOOST_PP_ITERATION_DEPTH() == 2

  #define BOOST_PP_VALUE BOOST_PP_SLOT(2)*2
  #include BOOST_PP_ASSIGN_SLOT(2)

    template<class Dummy>
    struct impl<BOOST_PP_SLOT(2), Dummy>
    {
      BOOST_FORCEINLINE static result_type call(Func const& f, BOOST_PP_ENUM_BINARY_PARAMS(n, A, const & a))
      {
        return make<result_type>(BOOST_PP_ENUM(BOOST_PP_SLOT(2), M5, n));
      }
    };

#endif
#endif

