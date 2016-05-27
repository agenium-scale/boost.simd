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

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/detail/diagnostic.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/arch/common/tags.hpp>
#include <boost/simd/as.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
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

    template<typename K, typename N>
    BOOST_FORCEINLINE result_t fold_(Arg const& a0, brigand::list<N> const&, K const&) const
    {
      bd::functor<BinOp> bop;
      bd::functor<NeutralElement> ne;
      auto r = bop( ne( as_<result_t>{} ), bs::extract<0>(a0) );

      return bd::functor<F>()( r );
    }

    template<typename K, typename N0, typename N1, typename... N>
    BOOST_FORCEINLINE result_t fold_(Arg const& a0, brigand::list<N0,N1,N...> const&, K const&) const
    {
      bd::functor<BinOp> bop;
      bd::functor<NeutralElement> ne;

      auto r = bop( ne( as_<result_t>{} ), bs::extract<0>(a0) );
           r = bop( r                    , bs::extract<1>(a0) );

      (void)std::initializer_list<bool> { ((r = bop(r, bs::extract<N::value>(a0))),true)... };
      return bd::functor<F>{}(r);
    }

    template<typename N0, typename N1, typename... N>
    BOOST_FORCEINLINE result_t fold_( Arg const& a0, brigand::list<N0,N1,N...> const&
                                    , aggregate_storage const&
                                    ) const
    {
      bd::functor<BinOp> bop;
      bd::functor<NeutralElement> ne;
      using presult_t = typename Arg::substorage_type::template rebind<result_t>;

      auto r = bop( ne( as_<presult_t>{} ), a0.storage()[0]);
           r = bop( r                     , a0.storage()[1]);

      return bd::functor<F>{}(r);
    }

    BOOST_FORCEINLINE result_t operator()(Arg const& a0) const
    {
      BOOST_SIMD_DIAG("autofold for: " << *this);

      return fold_( a0, typename Arg::traits::static_range{}, typename Arg::storage_kind{} );
    }
  };
} } }

#endif
