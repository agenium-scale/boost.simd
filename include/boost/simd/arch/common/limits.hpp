//==================================================================================================
/*!
  @file

  Aggregate SIMD numerical and type limits

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_LIMITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_LIMITS_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-config
    @brief Type informations for SIMD extensions

    This aggregate traits gathers informations about available types and cardinals for any given
    SIMD extension.

    @tparam Tag SIMD Extension tag
  **/
  template<typename Tag> struct limits
  {
    static_assert( sizeof(Tag) == 0, "Unsupported SIMD extensions" );

    /// @brief Retrieves largest integer supported by current extension
    template<typename Sign> using largest_integer   = brigand::no_such_type_;

    /// @brief Retrieves smallest integer supported by current extension
    template<typename Sign> using smallest_integer  = brigand::no_such_type_;

    /// @brief Retrieves largest real supported by current extension
    using largest_real   = brigand::no_such_type_;

    /// @brief Retrieves smallest integer supported by current extension
    using smallest_real  = brigand::no_such_type_;

    /// @brief Type size informations
    enum  {
            bits  = 8 ///<  SIMD Register size in bits
          , bytes = 1 ///<  SIMD Register size in bytes
          };
  };
} }

#endif

