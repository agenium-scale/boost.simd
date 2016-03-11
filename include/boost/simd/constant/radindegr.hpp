//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_RADINDEGR_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_RADINDEGR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Constant Radian in Degree residue can help to obtain better conversion
    from Radian to Degree

    @par Semantic:

    For type T:

    @code
    T r = Radindegr<T>();
    @endcode

    @return a value of type T

**/
  template<typename T> T Radindegr();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Constant Radian in Degree residue can help to obtain better conversion
      from Radian to Degree

      Generate the  constant radindegr.

      @return The Radindegr constant for the proper type
    **/
    const boost::dispatch::functor<tag::radindegr_> radindegr = {};
  }
} }
#endif

#include <boost/simd/constant/definition/radindegr.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
