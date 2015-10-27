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
#ifndef BOOST_SIMD_FUNCTION_MAXIMUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAXIMUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns the greatest element of the SIMD vector

    @par Semantic:

    For every parameter of type T0

    @code
    scalar_of_t<T0> r = maximum(a0);
    @endcode

    is similar to:

    @code
      scalar_of_t<T0> r = Minf;
      for(std::size_t i=0;i<cardinal_of<T0>;++i)
        r =  r < a0[i] ? a0[i] : r;
    @endcode


    @return a value of the scalar type associated to the parameter

**/
  template<typename T> auto maximum(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-reduction

      Function object tied to simd::maximum

      @see simd::maximum
    **/
    const boost::dispatch::functor<tag::maximum_> maximum = {};
  }
} }
#endif

#include <boost/simd/function/definition/maximum.hpp>
#include <boost/simd/arch/common/scalar/function/maximum.hpp>
//#include <boost/simd/arch/common/function/simd/maximum.hpp>

#endif
