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
#ifndef BOOST_SIMD_FUNCTION_TESTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TESTZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns True is only if all bits set in x are not set in y

    This is a convenient alias of is_included_c
**/
  template<typename T> auto testz(T0 const& x, T1 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns True is only if all bits set in x are not set in y


      Function object tied to simd::testz

      @see simd::testz
    **/
    const boost::dispatch::functor<tag::testz_> testz = {};
  }
} }
#endif

#include <boost/simd/function/definition/testz.hpp>
#include <boost/simd/arch/common/scalar/function/is_included_c.hpp>
#include <boost/simd/function/simd/testz.hpp>

#endif
