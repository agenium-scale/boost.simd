//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_AUTOFOLD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_AUTOFOLD_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/detail/diagnostic.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/arch/common/tags.hpp>
#include <boost/simd/as.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD_FALLBACK (  ( typename F, typename BinOp, typename NeutralElement
                                      , typename Arg, typename Ext
                                      )
                                   , bd::reduction_<F,BinOp,NeutralElement>
                                   , bs::simd_
                                   , bs::pack_<bd::unspecified_<Arg>, Ext>
                                   )
  {
    using value_t  = typename Arg::value_type;
    using result_t = decltype( bd::functor<F>()( std::declval<value_t>() ) );

    template<typename N>
    BOOST_FORCEINLINE result_t fold_(Arg const& a0, brigand::list<N> const&) const
    {
      // Condense if needed over the only element we require
      return bd::functor<F>( bs::extract<0>(a0) );
    }

    template<typename K, typename N0, typename... N>
    BOOST_FORCEINLINE result_t fold_(Arg const& a0, brigand::list<N0,N...> const&, K const&) const
    {
      bd::functor<BinOp> bop;
      bd::functor<NeutralElement> ne;

      auto r = bop( ne( as_<typename Arg::value_type>{} ), bs::extract<0>(a0) );
      (void)std::initializer_list<bool> { ((r = bop(r, bs::extract<N::value>(a0))),true)... };

      return bd::functor<F>{}(r);
    }

    template<typename N0, typename... N>
    BOOST_FORCEINLINE result_t fold_(Arg const& a0, brigand::list<N0,N...> const&, aggregate_storage const&) const
    {
      bd::functor<BinOp> bop;
      bd::functor<NeutralElement> ne;

      auto r = bop( ne( as_<typename Arg::value_type>{} ), a0.storage()[0]);
      (void)std::initializer_list<bool> { ((r = bop(r, a0.storage()[N::value])),true)... };

      return bd::functor<F>{}(r);
    }

    BOOST_FORCEINLINE result_t operator()(Arg const& a0) const
    {
      using kind_t        = typename Arg::storage_kind;
      using storage_range = typename Arg::traits::static_range;
      using element_range = br::range<std::size_t, 0, Arg::static_size>;
      using count_range   = std::conditional< std::is_same<kind_t,aggregate_storage>::value
                                            , storage_range
                                            , element_range
                                            >;

      BOOST_SIMD_DIAG("autofold for: " << *this);

      return fold_( a0, typename count_range::type{}, kind_t{} );
    }
  };
} } }

#endif
