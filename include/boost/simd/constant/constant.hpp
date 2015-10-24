//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_CONSTANT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_CONSTANT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant
    @brief Generate a constant from a static bits pattern representation.

    @tparam Type  Type of the generated constant
    @tparam Bits  Bits pattern of the generated constant
  **/
  template<typename Type, std::intmax_t Bits> auto Constant();
} }
#endif

#include <boost/simd/constant/definition/constant.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
