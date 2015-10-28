//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the saturated negation of the input.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = negs(x);
    @endcode

    The code is equivalent to:

    @code
    T r = -x
    @endcode

    @par Note:
    For integers types @c negs(Valmin) returns @c Valmax.

    @c negs is not defined for unsigned types.

    @par Alias

    saturated_neg


    @return      a value of the same type as the input.


**/
  template<typename T> auto negs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated negation of the input.


      Function object tied to simd::negs

      @see simd::negs
    **/
    const boost::dispatch::functor<tag::negs_> negs = {};
  }
} }
#endif

#include <boost/simd/function/definition/negs.hpp>
#include <boost/simd/arch/common/scalar/function/negs.hpp>
//#include <boost/simd/arch/common/function/simd/negs.hpp>

#endif
