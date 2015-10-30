//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_REAL_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_REAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant
    @brief Generate a constant from a static real number representation.

    @tparam Type    Type of the generated constant
    @tparam Double  Numerator of the generated constant
    @tparam Single  Denumerator of the generated constant
  **/
  template<typename Type, std::uintmax_t Double, std::uintmax_t Single> auto Real();
} }
#endif

#include <boost/simd/constant/definition/real.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
