//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_PREDECESSOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PREDECESSOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the n-th greatest element strictly less than the parameter

    @par Semantic:

    @code
    T r = predecessor(x,n);
    @endcode

    computes the @c n-th greatest value strictly less than x in its type.
    n must be positive or null.
    For integer it saturate at Valmin, for floating point numbers Minf
    strict predecessors are Nan



    @return a value of same type as the inputs

**/
  template<typename T> auto predecessor(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::predecessor

      @see simd::predecessor
    **/
    const boost::dispatch::functor<tag::predecessor_> predecessor = {};
  }
} }
#endif

#include <boost/simd/function/definition/predecessor.hpp>
#include <boost/simd/arch/common/scalar/function/predecessor.hpp>
//#include <boost/simd/arch/common/function/simd/predecessor.hpp>

#endif
