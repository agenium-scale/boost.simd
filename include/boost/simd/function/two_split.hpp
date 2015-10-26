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
#ifndef BOOST_SIMD_FUNCTION_TWO_SPLIT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWO_SPLIT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    @brief

    For any real @c a0, two_split computes two reals @c r0 and @c r1 so that:

    @code
    a0 = r0+r1
    @endcode

    and where @c r0 and @c r1 bit pattern don't overlap.


**/
  template<typename T> auto two_split(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::two_split

      @see simd::two_split
    **/
    const boost::dispatch::functor<tag::two_split_> two_split = {};
  }
} }
#endif

#include <boost/simd/function/definition/two_split.hpp>
#include <boost/simd/arch/common/generic/function/two_split.hpp>
//#include <boost/simd/arch/common/function/simd/two_split.hpp>

#endif
