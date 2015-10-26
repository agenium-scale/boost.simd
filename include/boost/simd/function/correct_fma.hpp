//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CORRECT_FMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CORRECT_FMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes fused multiply/add of its parameter.

    @par semantic:
    For any given value @c a, @c b, @c c of type @c T:

    @code
    T r = correct_fma(a, b, c);
    @endcode

    is similar to:

    @code
    T r = a*b+c;
    @endcode

    but with only one rounding

    @par Note:

    For integer a*b+c is performed

    For floating points numbers, always compute the correct fused multiply add,
    this means the computation of a0*a1+a2 with only one rounding operation.
    On machines not possessing this hard wired capability this can be very
    expansive.

    @c correct_fma is in fact a transitory function that allows to ensure
    strict fma capabilities,  i.e. only one rounding operation and no undue
    overflow in intermediate computations.

    If you are using this function for a system with no hard wired fma
    and are sure that overflow is not a problem
    you can define BOOST_SIMD_DONT_CARE_CORRECT_FMA_OVERFLOW to get better
    performances

    This function is never used internally in boost/simd. See also
    the fma function.

    @see  fma



    @return      a value of the same type as the input.


**/
  template<typename T> auto correct_fma(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::correct_fma

      @see simd::correct_fma
    **/
    const boost::dispatch::functor<tag::correct_fma_> correct_fma = {};
  }
} }
#endif

#include <boost/simd/function/definition/correct_fma.hpp>
#include <boost/simd/arch/common/scalar/function/correct_fma.hpp>
//#include <boost/simd/arch/common/function/simd/correct_fma.hpp>

#endif
