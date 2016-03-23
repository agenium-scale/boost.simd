//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BROADCAST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BROADCAST_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing broadcast capabilities

    Vector element broadcast

    Splat the Nth element of a SIMD register into a new register

    @par Semantic:

    For every parameter of type T and any integer @c N

    @code
    Type r = broadcast<N>(x);
    @endcode

    is similar to:

    @code
    for(int i=0;i<Type::static_size;++i)
      r[i] = x[N];
    @endcode

    @tparam N index of the value to broadcast everywhere

  **/
  const boost::dispatch::functor<tag::broadcast_> broadcast = {};
} }
#endif

#include <boost/simd/function/scalar/broadcast.hpp>
#include <boost/simd/function/simd/broadcast.hpp>

#endif
