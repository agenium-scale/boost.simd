//==================================================================================================
/*!
  @file

  Defines some useful traits wrapper

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_DETAIL_TRAITS_HPP_INCLUDED
#define NSTEST_UNIT_DETAIL_TRAITS_HPP_INCLUDED

#include <type_traits>

namespace nstest { namespace detail
{
  /*!
    @brief SFINAE trigger for integral types
    @ingroup group-details

    This template alias is to be used in SFINAE context to discriminate function dealing
    with integral type only.

    @tparam T Type to check as a integral type
    @tparam R Return type of the function to use if substitution succeed
  **/
  template<typename T, typename R>
  using if_integral = typename std::enable_if<std::is_integral<T>::value, R>::type;

  /*!
    @ingroup group-details

    @brief SFINAE trigger for floating-point types

    This template alias is to be used in SFINAE context to discriminate function dealing
    with floating-point type only.

    @tparam T Type to check as a floating-point type
    @tparam R Return type of the function to use if substitution succeed
  **/
  template<typename T, typename R>
  using if_real = typename std::enable_if<std::is_floating_point<T>::value, R>::type;

  // Short-cut for std::common_type
  template<typename T, typename U>
  using common_t = typename std::common_type<T,U>::type;
} }

#endif
