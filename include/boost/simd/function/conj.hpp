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
#ifndef BOOST_SIMD_FUNCTION_CONJ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CONJ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the conjugate value of its parameter (identity for reals).

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = conj(x);
    @endcode

    for real parameters is equivalent to:

    @code
    T r = x
    @endcode

    @par Alias

    conjugate


    @return      a value of the same type as the input.


**/
  template<typename T> auto conj(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::conj

      @see simd::conj
    **/
    const boost::dispatch::functor<tag::conj_> conj = {};
  }
} }
#endif

#include <boost/simd/function/definition/conj.hpp>
#include <boost/simd/arch/common/generic/function/conj.hpp>

//#include <boost/simd/arch/common/function/simd/conj.hpp>

#endif
