//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POSMAX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POSMAX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns the index of the first occurence of greatest element of the SIMD vector

    @par Semantic:

    For every parameter of type T

    @code
    std::size_t r = posmax(x);
    @endcode

    is similar to:

    @code
      scalar_of_t<T> m =  maximum(x);
      std::size_t r;
      for(std::size_t i=0; i < cardinal_of<T>; i++)
        if (m == x[i]) { r = i;  break; }
    @endcode


    @return a std::size_t value

**/
  template<typename T> auto posmax(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns the index of the first occurence of greatest element of the SIMD vector


      Function object tied to simd::posmax

      @see simd::posmax
    **/
    const boost::dispatch::functor<tag::posmax_> posmax = {};
  }
} }
#endif

#include <boost/simd/function/definition/posmax.hpp>
#include <boost/simd/arch/common/scalar/function/posmax.hpp>
//#include <boost/simd/arch/common/function/simd/posmax.hpp>

#endif
