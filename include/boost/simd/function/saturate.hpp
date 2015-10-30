//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SATURATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SATURATE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the saturated value of the first input in the template parameter type,
    but in the same type as the input.

    @par Semantic:

    @code
    T r = saturate<Target>(x)
    @endcode

    is similar to:

    @code
    if (x >  Inf<Target>()) r =  T(Inf<Target>());
    else if  (x <  Minf<Target>()) r =  T(Minf<Target>());
    else r = x;
    @endcode

    @see Minf, Inf, Valmax, Valmin

    Note let us recall that @ref Valmin and @ref Minf (resp. @ref Valmax and @ref Inf)
    are identical if Target is  an integer type.

    @return a value of same type as the input

**/
  template<typename Target, typename T> auto saturate(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the saturated value of the first input in the template parameter type,
      but in the same type as the input.


      Function object tied to simd::saturate

      @see simd::saturate
    **/
    const boost::dispatch::functor<tag::saturate_> saturate = {};
  }
} }
#endif

#include <boost/simd/function/definition/saturate.hpp>
#include <boost/simd/arch/common/generic/function/saturate.hpp>
#include <boost/simd/function/simd/saturate.hpp>

#endif
