//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXINIT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXINIT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant maxinit whixh is identical to boost::simd::minf for
    arithmetic real types but that must be specialized for complex values ordring.

    maxinit is the value to be returned when a maximum of the elements function is used on an
    empty container.

    @return The Maxinit constant for the proper type
  **/
  template<typename T> T Maxinit();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant maxinit.

      @return The Maxinit constant for the proper type
    **/
    const boost::dispatch::functor<tag::maxinit_> maxinit = {};
  }
} }
#endif

#include <boost/simd/constant/definition/maxinit.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
