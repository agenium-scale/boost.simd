//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ALL_REDUCE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ALL_REDUCE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar


**/
  template<typename T> auto all_reduce(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar



      Function object tied to simd::all_reduce

      @see simd::all_reduce
    **/
    const boost::dispatch::functor<tag::all_reduce_> all_reduce = {};
  }
} }
#endif

#include <boost/simd/function/definition/all_reduce.hpp>
#include <boost/simd/arch/common/scalar/function/all_reduce.hpp>
//#include <boost/simd/arch/common/function/simd/all_reduce.hpp>

#endif
