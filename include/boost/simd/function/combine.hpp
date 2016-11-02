//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMBINE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMBINE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-swar
    This function object concatenates two values of the same type to build a boost::simd::pack
    but with a cardinal twice as large.

    @par Scalar Semantic:
    For any scalar value @c a and @c b of type @c T , the following code:
    @code
    auto c = combine(a,b);
    @endcode
    is equivalent to :
    @code
    pack<T, 2> c(a,b);
    @endcode

    @par SIMD Semantic:
    For any type value @c a and @c b of type boost::simd::pack<T,N>, the following code:
    @code
    pack<T,2*N> c = combine(a,b);
    @endcode
    is equivalent to :
    @code
    pack<T,2*N> c(a[0],....,a[N-1],b[0],....,b[N-1]);
    @endcode
    where @c N is equal to the cardinal of both @c a and @c b.

    @param v0 First  value to combine
    @param v1 Second value to combine

    @return The concatenation of both inputs
  **/
  auto combine(Value const& v0, Value const& v1);
} }
#endif

#include <boost/simd/function/simd/combine.hpp>

#endif
