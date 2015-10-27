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
#ifndef BOOST_SIMD_FUNCTION_COMPARE_GREATER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_GREATER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    return a bool that is the result of the lexicographic
    test for > on all elements of the entries

    It is probably not what you wish. Have a look to is_greater

    @par Semantic:

    For every parameters of type T0:

    @code
    as_logical_t<scalar_of_t<T0>> r = compare_greater(a0,a1);
    @endcode

    is similar to:

    @code
      as_logical_t<scalar_of_t<T0>> r = False;
      for(std::size_t i=0;i<cardinal_of<A0>;++i)
      {
        if (a0[i] > a1[i])  {r =  True; break;}
        if (a1[i] > a0[i])  {r = False; break;}
      }
    @endcode

    @par Alias:
    @c compare_gt

    @see is_greater


    @return a value of the scalar logical type associated to the parameters

**/
  template<typename T> auto compare_greater(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-reduction

      Function object tied to simd::compare_greater

      @see simd::compare_greater
    **/
    const boost::dispatch::functor<tag::compare_greater_> compare_greater = {};
  }
} }
#endif

#include <boost/simd/function/definition/compare_greater.hpp>
#include <boost/simd/arch/common/scalar/function/compare_greater.hpp>
//#include <boost/simd/arch/common/function/simd/compare_greater.hpp>

#endif
