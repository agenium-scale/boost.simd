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
#ifndef BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Retuns the first element negated is the the scond is less than 0

    @par Semantic:

    @code
    T r = negate(a0,a1);
    @endcode

    is similar to:

    @code
    T r =  a0*sign(a1);
    @endcode



    @return a value of same type as the inputs

**/
  template<typename T> auto negate(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::negate

      @see simd::negate
    **/
    const boost::dispatch::functor<tag::negate_> negate = {};
  }
} }
#endif

#include <boost/simd/function/definition/negate.hpp>
#include <boost/simd/arch/common/scalar/function/negate.hpp>
//#include <boost/simd/arch/common/function/simd/negate.hpp>

#endif
