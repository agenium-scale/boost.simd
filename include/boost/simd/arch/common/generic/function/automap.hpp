//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_MAP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_MAP_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/arch/common/tags.hpp>
#include <boost/simd/detail/diagnostic.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  namespace br = brigand;

  BOOST_DISPATCH_OVERLOAD_FALLBACK ( ( typename F
                                     , typename... Pn, typename... En
                                     )
                                   , bd::elementwise_<F>
                                   , bs::simd_
                                   , bs::pack_<bd::unspecified_<Pn>, En>...
                                   )
  {
    // The functor
    using functor             = bd::functor<F>;

    // Use the very first pack as reference
    using pack                = br::front<br::list<Pn...>>;
    using traits              = typename pack::traits;

    // We build the return pack as a pack of same cardinal but which type is the scalar return
    // type of functor applied to the input parameter value type.
    using return_type         = decltype(functor()(std::declval<typename Pn::value_type>()...));
    using result_type         = typename pack::template rebind<return_type>;
    using result_storage_type = typename result_type::storage_type;
    using result_traits       = typename result_type::traits;

    // We need to iterate over output type cardinal to fill it
    using result_static_range = typename result_traits::static_range;
    using element_range       = br::range<std::size_t, 0, pack::static_size>;

    // Constructing the output depends on the storage_kind of both input and output
    using storage_kind        = typename traits::storage_kind;
    using result_storage_kind = typename result_traits::storage_kind;

    template <typename S, typename E>
    struct traits_checker {
      using type = br::pair< br::bool_<  S::first_type::value
                                      && std::size_t(E::static_size)
                                      == std::size_t(traits::static_size)
                                      >
                           , br::bool_<  S::second_type::value
                                      && std::size_t(E::number_of_vectors)
                                      == std::size_t(result_traits::number_of_vectors)
                                      >
                           >;
    };

    using traits_info = br::fold< br::list<typename Pn::traits...>
                                , br::pair<br::bool_<true>, br::bool_<true>>
                                , br::quote<traits_checker>
                                >;

    enum {
      same_static_size = traits_info::first_type::value,
      same_number_of_vectors = traits_info::second_type::value,
      is_noexcept = BOOST_NOEXCEPT_EXPR(functor()(std::declval<Pn>()[0]...))
    };

    static_assert( same_static_size
                 , "automap fallback: all packs must have the same size"
                 );

    // ---------------------------------------------------------------------------------------------
    // (P)

    template <typename P0, typename... N, typename... M>
    BOOST_FORCEINLINE static result_type map_( br::bool_<true> const&
                                             , br::list<N...> const&
                                             , br::list<M...> const&
                                             , P0 const& p0
                                             )
    BOOST_NOEXCEPT_IF_EXPR(functor()(std::declval<Pn>().storage()[0]...))
    {
      functor f;
      return result_storage_type{{ f(p0.storage()[M::value])... }};
    }

    template <typename P0, typename... N, typename... M>
    BOOST_FORCEINLINE static result_type map_( br::bool_<false> const&
                                             , br::list<N...> const&
                                             , br::list<M...> const&
                                             , P0 const& p0
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return { f(p0[N::value])... };
    }

    template <typename P0, typename SK, typename... N>
    BOOST_FORCEINLINE static result_type map_( SK const&
                                             , ::boost::simd::scalar_storage const&
                                             , br::list<N...> const&
                                             , P0 const& p0
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return result_storage_type{{ f(p0[N::value])... }};
    }

    template <typename P0, typename SKI, typename SKO, typename... N>
    BOOST_FORCEINLINE static result_type map_( SKI const&
                                             , SKO const& // {aggregate,native}_storage
                                             , br::list<N...> const&
                                             , P0 const& p0
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return { f(p0[N::value])... };
    }

    // ---------------------------------------------------------------------------------------------
    // (P, P)

    template <typename P0, typename P1, typename... N, typename... M>
    BOOST_FORCEINLINE static result_type map_( br::bool_<true> const&
                                             , br::list<N...> const&
                                             , br::list<M...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             )
    BOOST_NOEXCEPT_IF_EXPR(functor()(std::declval<Pn>().storage()[0]...))
    {
      functor f;
      return result_storage_type{{
        f( p0.storage()[M::value]
         , p1.storage()[M::value]
         )...
      }};
    }

    template <typename P0, typename P1, typename... N, typename... M>
    BOOST_FORCEINLINE static result_type map_( br::bool_<false> const&
                                             , br::list<N...> const&
                                             , br::list<M...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return { f(p0[N::value], p1[N::value])... };
    }

    template <typename P0, typename P1, typename SK, typename... N>
    BOOST_FORCEINLINE static result_type map_( SK const&
                                             , ::boost::simd::scalar_storage const&
                                             , br::list<N...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return result_storage_type{{ f( p0[N::value] , p1[N::value])...  }};
    }

    template <typename P0, typename P1, typename SKI, typename SKO, typename... N>
    BOOST_FORCEINLINE static result_type map_( SKI const&
                                             , SKO const& // {aggregate,native}_storage
                                             , br::list<N...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return { f(p0[N::value], p1[N::value])...  };
    }


    // ---------------------------------------------------------------------------------------------
    // (P, P, P)

    template <typename P0, typename P1, typename P2, typename... N, typename... M>
    BOOST_FORCEINLINE static result_type map_( br::bool_<true> const&
                                             , br::list<N...> const&
                                             , br::list<M...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             , P2 const& p2
                                             )
    BOOST_NOEXCEPT_IF_EXPR(functor()(std::declval<Pn>().storage()[0]...))
    {
      functor f;
      return result_storage_type{{
        f( p0.storage()[M::value]
         , p1.storage()[M::value]
         , p2.storage()[M::value]
         )...
      }};
    }

    template <typename P0, typename P1, typename P2, typename... N, typename... M>
    BOOST_FORCEINLINE static result_type map_( br::bool_<false> const&
                                             , br::list<N...> const&
                                             , br::list<M...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             , P2 const& p2
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return { f(p0[N::value], p1[N::value], p2[N::value])... };
    }

    template <typename P0, typename P1, typename P2, typename SK, typename... N>
    BOOST_FORCEINLINE static result_type map_( SK const&
                                             , ::boost::simd::scalar_storage const&
                                             , br::list<N...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             , P2 const& p2
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return result_storage_type{{ f(p0[N::value], p1[N::value], p2[N::value])...  }};
    }

    template <typename P0, typename P1, typename P2, typename SKI, typename SKO, typename... N>
    BOOST_FORCEINLINE static result_type map_( SKI const&
                                             , SKO const& // {aggregate,native}_storage
                                             , br::list<N...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             , P2 const& p2
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return { f(p0[N::value], p1[N::value], p2[N::value])... };
    }

    // ---------------------------------------------------------------------------------------------
    // (P, P, P, P)

    template <typename P0, typename P1, typename P2, typename P3, typename... N, typename... M>
    BOOST_FORCEINLINE static result_type map_( br::bool_<true> const&
                                             , br::list<N...> const&
                                             , br::list<M...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             , P2 const& p2
                                             , P3 const& p3
                                             )
    BOOST_NOEXCEPT_IF_EXPR(functor()(std::declval<Pn>().storage()[0]...))
    {
      functor f;
      return result_storage_type{{
        f( p0.storage()[M::value]
         , p1.storage()[M::value]
         , p2.storage()[M::value]
         , p3.storage()[M::value]
         )...
      }};
    }

    template <typename P0, typename P1, typename P2, typename P3, typename... N, typename... M>
    BOOST_FORCEINLINE static result_type map_( br::bool_<false> const&
                                             , br::list<N...> const&
                                             , br::list<M...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             , P2 const& p2
                                             , P3 const& p3
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return {
        f( p0[N::value]
         , p1[N::value]
         , p2[N::value]
         , p3[N::value]
         )...
      };
    }

    template <typename P0, typename P1, typename P2, typename P3, typename SK, typename... N>
    BOOST_FORCEINLINE static result_type map_( SK const&
                                             , ::boost::simd::scalar_storage const&
                                             , br::list<N...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             , P2 const& p2
                                             , P3 const& p3
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return result_storage_type{{
        f( p0[N::value]
         , p1[N::value]
         , p2[N::value]
         , p3[N::value]
         )...
      }};
    }

    template < typename P0, typename P1, typename P2, typename P3
             , typename SKI, typename SKO
             , typename... N
             >
    BOOST_FORCEINLINE static result_type map_( SKI const&
                                             , SKO const& // {aggregate,native}_storage
                                             , br::list<N...> const&
                                             , P0 const& p0
                                             , P1 const& p1
                                             , P2 const& p2
                                             , P3 const& p3
                                             )
    BOOST_NOEXCEPT_IF(is_noexcept)
    {
      functor f;
      return { f(p0[N::value], p1[N::value], p2[N::value], p3[N::value])... };
    }

    // ---------------------------------------------------------------------------------------------
    // Map special dispatcher + operator()

    template <typename... N>
    BOOST_FORCEINLINE static auto map_( ::boost::simd::aggregate_storage const&
                                      , ::boost::simd::aggregate_storage const&
                                      , br::list<N...> const& element_range
                                      , Pn const&... pn
                                      )
    BOOST_NOEXCEPT_DECLTYPE_BODY
    ( map_( br::bool_<same_number_of_vectors>{}
          , element_range
          , result_static_range{} // ::static_range is the number of vectors for aggregate_storage
          , pn...
          )
    )

    BOOST_FORCEINLINE auto operator()(Pn const&... pn) const
    BOOST_NOEXCEPT_DECLTYPE
    ( map_( storage_kind{}
          , result_storage_kind{}
          , element_range{}
          , pn...
          )
    )
    {
      BOOST_SIMD_DIAG("automap for: " << *this);
      return map_( storage_kind{}
                 , result_storage_kind{}
                 , element_range{}
                 , pn...
                 );
    }

  };

  // -----------------------------------------------------------------------------------------------

} } }

#endif
