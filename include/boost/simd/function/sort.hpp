//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SORT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SORT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    returns the sorted x vector in ascending order

    @par Semantic:

    For every parameter of type T0

    @code
    T0 r = sort(x);
    @endcode


    @return a value of the same type as the second parameter

**/
  template<typename T> auto sort(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      returns the sorted x vector in ascending order


      Function object tied to simd::sort

      @see simd::sort
    **/
    const boost::dispatch::functor<tag::sort_> sort = {};
  }
} }
#endif

#include <boost/simd/function/definition/sort.hpp>
#include <boost/simd/arch/common/scalar/function/sort.hpp>
#include <boost/simd/function/simd/sort.hpp>

#endif
