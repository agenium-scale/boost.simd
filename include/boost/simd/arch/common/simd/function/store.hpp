//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_STORE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_STORE_HPP_INCLUDED
#include <boost/simd/pack.hpp>
#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/insert.hpp>
#include <boost/config.hpp>
#include <tuple>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  /// INTERNAL ONLY - SIMD store without offset
  BOOST_DISPATCH_OVERLOAD ( store_
                          , (typename Src, typename Pointer)
                          , bd::cpu_
                          , bs::pack_<bd::unspecified_<Src>,bs::simd_emulation_>
                          , bd::pointer_<bd::scalar_<bd::unspecified_<Pointer>>,1u>
                          )
  {
    using storage_t = typename Src::storage_type;
    using src_t  = Src;
    using value_t   = typename storage_t::value_type;
    using s_t       = typename boost::pointee<Pointer>::type;
    // How many elements does each store stores ?
    template<typename I>
    using rsize_t = std::integral_constant<std::size_t,I::value*src_t::traits::element_size>;

    BOOST_FORCEINLINE void operator()(const Src& s, Pointer p) const BOOST_NOEXCEPT
    {
      do_(s, p, brigand::range<std::size_t,0,rsize_t<std::tuple_size<storage_t>>::value>{} );
    }

    template < typename I>
    static BOOST_FORCEINLINE s_t sto_(const Src& s, Pointer  p) BOOST_NOEXCEPT
    {
      return p[I::value] = static_cast<s_t>( s[I::value]);
    }

    template<typename... N>
    static inline void do_(Src const & s, Pointer p, brigand::list<N...> const&)
    {
      (void)std::initializer_list<bool>{(sto_<N>(s,p),true)...};
    }
  };


} } }

#endif
