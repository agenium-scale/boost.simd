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
#ifndef BOOST_SIMD_FUNCTION_IS_INCLUDED_C_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_INCLUDED_C_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns True is only if all bits set in x are not set in y

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    logical<scalar_of_t<T0>> r = is_included_c(x,y);
    @endcode

    is similar to:

    @code
    logical<scalar_of_t<T0>> r = all(x&y == zero);
    @endcode

    @par Alias:
    @c testz, @c are_disjoint



    @return a value of the scalar logical type associated to the parameters

**/
  template<typename T> auto is_included_c(T0 const& x, T1 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns True is only if all bits set in x are not set in y


      Function object tied to simd::is_included_c

      @see simd::is_included_c
    **/
    const boost::dispatch::functor<tag::is_included_c_> is_included_c = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_included_c.hpp>
#include <boost/simd/arch/common/scalar/function/is_included_c.hpp>
//#include <boost/simd/arch/common/function/simd/is_included_c.hpp>

#endif
