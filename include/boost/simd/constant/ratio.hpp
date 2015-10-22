//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_RATIO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_RATIO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate a constant from a static representation of a rational number.

    @return
  **/
  template<typename Type, std::uintmax_t Numerator, std::uintmax_t Denumerator> auto Ratio();
} }
#endif

#include <boost/simd/constant/definition/ratio.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
