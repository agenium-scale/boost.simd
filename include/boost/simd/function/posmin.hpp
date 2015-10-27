//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POSMIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POSMIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns the index of the first occurence of least element of the SIMD vector

    @par Semantic:

    For every parameter of type T0

    @code
    size_t r = posmin(a0);
    @endcode

    is similar to:

    @code
      T0 m =  minimum(a0);
      size_t r;
      for(size_t i=0; i < cardinal_of<T0>; i++)
        if (m == a0[i]) { r = i;  break; }
    @endcode


    @return a size_t value

**/
  template<typename T> auto posmin(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-reduction

      Function object tied to simd::posmin

      @see simd::posmin
    **/
    const boost::dispatch::functor<tag::posmin_> posmin = {};
  }
} }
#endif

#include <boost/simd/function/definition/posmin.hpp>
#include <boost/simd/arch/common/scalar/function/posmin.hpp>
//#include <boost/simd/arch/common/function/simd/posmin.hpp>

#endif
