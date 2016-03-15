//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_MAP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_MAP_HPP_INCLUDED

#include <boost/simd/options.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/arch/common/tags.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename P, typename Ext)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   )
  {
    using functor = bd::functor<F>;
    using storage_type    = typename P::traits::storage_type;
    using substorage_type = typename P::traits::substorage_type;
    using static_range    = typename P::traits::static_range;

    P operator()( P const& p0
                ) const BOOST_NOEXCEPT
    {
      return do_(typename P::traits::storage_kind{}, p0.storage(), static_range{});
    }

    template <std::size_t N>
    BOOST_FORCEINLINE
    static substorage_type at_( storage_type const& s0
                              ) BOOST_NOEXCEPT
    {
      return { functor{}(s0[N]) };
    }

    template <typename... N>
    BOOST_FORCEINLINE
    static P do_( ::boost::simd::aggregate_storage
                , storage_type const& s0
                , brigand::list<N...> const&
                ) BOOST_NOEXCEPT
    {
      #pragma GCC diagnostic push
      #pragma GCC diagnostic ignored "-Wmissing-braces"
      // For some reasons, Clang is complaining about missing braces here, and adding them does give
      // a compilation error.
      // This probably because adding those braces will give different meaning to the expression.
      // Anyway, adding this pragma will get rid of the warning and get the intended result.
      return {{ at_<N::value>(s0)... }};
      #pragma GCC diagnostic pop
    }

    template <typename StorageKind, typename... N>
    BOOST_FORCEINLINE
    static P do_( StorageKind
                , storage_type const& s0
                , brigand::list<N...> const&
                ) BOOST_NOEXCEPT
    {
      return { at_<N::value>(s0)... };
    }
  };

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename P, typename Ext)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   )
  {
    using functor = bd::functor<F>;
    using storage_type    = typename P::traits::storage_type;
    using substorage_type = typename P::traits::substorage_type;
    using static_range    = typename P::traits::static_range;

    P operator()( P const& p0
                , P const& p1
                ) const BOOST_NOEXCEPT
    {
      return do_(typename P::traits::storage_kind{}, p0.storage(), p1.storage(), static_range{});
    }

    template <std::size_t N>
    BOOST_FORCEINLINE
    static substorage_type at_( storage_type const& s0
                              , storage_type const& s1
                              ) BOOST_NOEXCEPT
    {
      return { functor{}(s0[N], s1[N]) };
    }

    template <typename... N>
    BOOST_FORCEINLINE
    static P do_( ::boost::simd::aggregate_storage
                , storage_type const& s0
                , storage_type const& s1
                , brigand::list<N...> const&
                ) BOOST_NOEXCEPT
    {
      return {{ at_<N::value>(s0, s1)... }};
    }

    template <typename StorageKind, typename... N>
    BOOST_FORCEINLINE
    static P do_( StorageKind
                , storage_type const& s0
                , storage_type const& s1
                , brigand::list<N...> const&
                ) BOOST_NOEXCEPT
    {
      return { at_<N::value>(s0, s1)... };
    }

  };

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename P, typename Ext)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   )
  {
    using functor = bd::functor<F>;
    using storage_type    = typename P::traits::storage_type;
    using substorage_type = typename P::traits::substorage_type;
    using static_range    = typename P::traits::static_range;

    P operator()( P const& p0
                , P const& p1
                , P const& p2
                ) const BOOST_NOEXCEPT
    {
      return do_( typename P::traits::storage_kind{}
                , p0.storage()
                , p1.storage()
                , p2.storage()
                , static_range{}
                );
    }

    template <std::size_t N>
    BOOST_FORCEINLINE
    static substorage_type at_( storage_type const& s0
                              , storage_type const& s1
                              , storage_type const& s2
                              ) BOOST_NOEXCEPT
    {
      return { functor{}(s0[N], s1[N], s2[N]) };
    }

    template <typename... N>
    BOOST_FORCEINLINE
    static P do_( ::boost::simd::aggregate_storage
                , storage_type const& s0
                , storage_type const& s1
                , storage_type const& s2
                , brigand::list<N...> const&
                ) BOOST_NOEXCEPT
    {
      return {{ at_<N::value>(s0, s1, s2)... }};
    }

    template <typename StorageKind, typename... N>
    BOOST_FORCEINLINE
    static P do_( StorageKind
                , storage_type const& s0
                , storage_type const& s1
                , storage_type const& s2
                , brigand::list<N...> const&
                ) BOOST_NOEXCEPT
    {
      return { at_<N::value>(s0, s1, s2)... };
    }
  };

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( (typename F, typename P, typename Ext)
                                   , bd::elementwise_<F>
                                   , bd::cpu_
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   , bs::pack_<bd::unspecified_<P>, Ext>
                                   )
  {
    using functor = bd::functor<F>;
    using storage_type    = typename P::traits::storage_type;
    using substorage_type = typename P::traits::substorage_type;
    using static_range    = typename P::traits::static_range;

    P operator()( P const& p0
                , P const& p1
                , P const& p2
                , P const& p3
                ) const BOOST_NOEXCEPT
    {
      return do_( typename P::traits::storage_kind{}
                , p0.storage()
                , p1.storage()
                , p2.storage()
                , p3.storage()
                , static_range{}
                );
    }

    template <std::size_t N>
    BOOST_FORCEINLINE
    static substorage_type at_( storage_type const& s0
                              , storage_type const& s1
                              , storage_type const& s2
                              , storage_type const& s3
                              ) BOOST_NOEXCEPT
    {
      return { functor{}(s0[N], s1[N], s2[N], s3[N]) };
    }

    template <typename... N>
    BOOST_FORCEINLINE
    static P do_( ::boost::simd::aggregate_storage
                , storage_type const& s0
                , storage_type const& s1
                , storage_type const& s2
                , storage_type const& s3
                , brigand::list<N...> const&
                ) BOOST_NOEXCEPT
    {
      return {{ at_<N::value>(s0, s1, s2, s3)... }};
    }

    template <typename StorageKind, typename... N>
    BOOST_FORCEINLINE
    static P do_( StorageKind
                , storage_type const& s0
                , storage_type const& s1
                , storage_type const& s2
                , storage_type const& s3
                , brigand::list<N...> const&
                ) BOOST_NOEXCEPT
    {
      return { at_<N::value>(s0, s1, s2, s3)... };
    }
  };

} } }

#endif
