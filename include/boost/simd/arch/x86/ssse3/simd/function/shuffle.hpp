//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/permutation.hpp>

namespace boost { namespace simd { namespace detail
{
  namespace bsd =  boost::simd::detail;

  template<int... Ps, typename A0>
  BOOST_FORCEINLINE A0 unary_permute(bsd::pattern_<Ps...> const&, const A0 & a0) BOOST_NOEXCEPT
  {
    using bytes_t   = typename A0::template retype<std::uint8_t,16>;
    using ranges_t  = brigand::range<int,0,16>;
    using pattern_t = brigand::integral_list<int,Ps...>;

    return  bitwise_cast<A0>
            ( _mm_shuffle_epi8( bitwise_cast<bytes_t>(a0)
                              , detail::mask_all<16/A0::static_size>( ranges_t{}, pattern_t{} )
                              )
            );
  }

  template<int... Ps, typename A0> BOOST_FORCEINLINE
  A0 binary_permute(bsd::pattern_<Ps...> const&, const A0 & a0, const A0 & a1) BOOST_NOEXCEPT
  {
    using bytes_t   = typename A0::template retype<std::uint8_t,16>;
    using ranges_t  = brigand::range<int,0,16>;
    using pattern_t = brigand::integral_list<int,Ps...>;

    return  bitwise_or
            ( bitwise_cast<A0>
              ( _mm_shuffle_epi8( bitwise_cast<bytes_t>(a0)
                                , detail::mask_left<16/A0::static_size>( ranges_t{}, pattern_t{} )
                                )
              )
            , bitwise_cast<A0>
              ( _mm_shuffle_epi8( bitwise_cast<bytes_t>(a1)
                                , detail::mask_right<16/A0::static_size>( ranges_t{}, pattern_t{} )
                                )
              )
            );
  }
} } }

namespace boost { namespace simd { namespace ext
{
  namespace bd  =  boost::dispatch;
  namespace bs  =  boost::simd;
  namespace bsd =  boost::simd::detail;

  // -----------------------------------------------------------------------------------------------
  // Unary SSSE3 shuffle
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::ssse3_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::type64_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == cardinal_of<A0>::value
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE A0 operator()(bsd::pattern_<Ps...> const& p, const A0 & a0) const BOOST_NOEXCEPT
    {
      return bsd::unary_permute(p,a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::ssse3_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == cardinal_of<A0>::value
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE A0 operator()(bsd::pattern_<Ps...> const& p, const A0 & a0) const BOOST_NOEXCEPT
    {
      return bsd::unary_permute(p,a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::ssse3_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == cardinal_of<A0>::value
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE A0 operator()(bsd::pattern_<Ps...> const& p, const A0 & a0) const BOOST_NOEXCEPT
    {
      return bsd::unary_permute(p,a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::ssse3_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::fundamental_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == cardinal_of<A0>::value
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE A0 operator()(bsd::pattern_<Ps...> const& p, const A0 & a0) const BOOST_NOEXCEPT
    {
      return bsd::unary_permute(p,a0);
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Binary SSSE3 shuffle
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::ssse3_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::type64_<A0>, bs::sse_>
                          , bs::pack_<bd::type64_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == cardinal_of<A0>::value
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(bsd::pattern_<Ps...> const& p, const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return bsd::binary_permute(p,a0,a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::ssse3_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == cardinal_of<A0>::value
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(bsd::pattern_<Ps...> const& p, const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return bsd::binary_permute(p,a0,a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::ssse3_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == cardinal_of<A0>::value
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(bsd::pattern_<Ps...> const& p, const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return bsd::binary_permute(p,a0,a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::ssse3_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::fundamental_<A0>, bs::sse_>
                          , bs::pack_<bd::fundamental_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == cardinal_of<A0>::value
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(bsd::pattern_<Ps...> const& p, const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return bsd::binary_permute(p,a0,a1);
    }
  };
} } }

#endif
