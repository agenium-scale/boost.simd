//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_LOAD_HPP_INCLUDED

#include <boost/simd/function/make.hpp>
#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from a pointer of single
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer)
                          , bs::sse_
                          , bd::pointer_<bd::scalar_<bd::single_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::single_<Target>,bs::sse_>>
                          )
  {
    using target_t = typename Target::type;

    BOOST_FORCEINLINE target_t operator()(Pointer p, Target const&) const
    {
      return _mm_loadu_ps(p);
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from a range of sse whatever
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Begin, typename End)
                          , bs::sse_
                          , bd::input_iterator_<bd::scalar_<bd::arithmetic_<Begin>>>
                          , bd::input_iterator_<bd::scalar_<bd::arithmetic_<End>>>
                          , bd::target_<bs::pack_<bd::arithmetic_<Target>,bs::sse_>>
                          )
  {
    using target_t  = typename Target::type;
    using value_t   = typename target_t::value_type;

    BOOST_FORCEINLINE target_t operator()(Begin const& b, End const&, Target const&) const BOOST_NOEXCEPT
    {
      return do_(b, brigand::range<std::size_t,0,target_t::static_size>{} );
    }

    template<typename N>
    static inline value_t value(Begin& b) BOOST_NOEXCEPT
    {
      return *b++;
    }

    template<typename... N>
    static inline target_t do_(Begin const& b, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      auto pb = b;
      std::initializer_list<value_t> lst{ value<N>(pb)... };

      auto p = lst.begin();
      return make<target_t>(p[N::value]...);
    }
  };
} } }

#endif
