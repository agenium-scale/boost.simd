//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MLOG10TWO2NMB_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MLOG10TWO2NMB_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant mlog10two2nmb.

    @return The Mlog10two2nmb constant for the proper type
  **/
  template<typename T> T Mlog10two2nmb();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant mlog10two2nmb.

      @return The Mlog10two2nmb constant for the proper type
    **/
    const boost::dispatch::functor<tag::mlog10two2nmb_> mlog10two2nmb = {};
  }
} }
#endif

#include <boost/simd/constant/definition/mlog10two2nmb.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
