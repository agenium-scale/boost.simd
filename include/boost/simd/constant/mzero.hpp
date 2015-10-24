//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MZERO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MZERO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate value -0

    @par Semantic:

    @code
    T r = Mzero<T>();
    @endcode

    is similar to:

    @code
    T r = -T(0);
    @endcode

    @ par Note:

    This is a special constant as it can be used and considered
    identical to zero, except that for floating point numbers,
    there is two different representation of zero with different bit of sign.

    The existence of the sign can be used in special circumstances as
    choosing between \f$+\infty\f$ and \f$-\infty\f$ instead of nan in computing 1/0.
    \par

    The sign of zero can be accessed through the @c boost::simd::is_negative
    and @c boost::simd::is_positive predicates or the boost::simd::bitofsign function.

    @return The Mzero constant for the proper type
  **/
  template<typename T> T Mzero();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant mzero.

      @return The Mzero constant for the proper type
    **/
    const boost::dispatch::functor<tag::mzero_> mzero = {};
  }
} }
#endif

#include <boost/simd/constant/definition/mzero.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
