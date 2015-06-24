//==================================================================================================
/*!
  @file

  Defines the is_streamable meta-function

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_DETAIL_IS_STREAMABLE_HPP_INCLUDED
#define NSTEST_COMMON_DETAIL_IS_STREAMABLE_HPP_INCLUDED

#include <cstddef>
#include <iostream>
#include <type_traits>

namespace nstest { namespace detail
{
  /*!
    @ingroup group-details

    Checks if a type fulfills the requirement of being inserted into an output stream

    @par Model:

    @metafunction

    @par Semantic:

    For any type @c T:

    @code
    using type = nstest::detail::is_streamable<T>::type;
    @endcode

    is equivalent to @true_ if, for any instance @c os of any @c std::ostream class :

    @code
    T t;
    os << t;
    @endcode

    is well-formed. Otherwise, it i equivalent to @false_ .

    @tparam T Type to check
  **/
  template<typename T> struct is_streamable
  {
    template<typename U>
    static auto test( int ) -> decltype ( std::cout << std::declval<U>()
                                        , std::true_type()
                                        );

    template<typename>
    static auto test( ... ) -> std::false_type;

    typedef std::is_same<decltype(test<T>(0)),std::true_type> type;
  };

  /*!
    @brief SFINAE trigger for streamable types
    @ingroup group-details

    This template alias is to be used in SFINAE context to discriminate function dealing
    with streamable type only.

    @tparam T Type to check as a streamable type
    @tparam R Return type of the function to use if substitution succeed
  **/
  template <typename T, typename R>
  using if_streamable = typename std::enable_if<is_streamable<T>::type::value,R>::type;


  /*!
    @brief SFINAE trigger for non-streamable types
    @ingroup group-details

    This template alias is to be used in SFINAE context to discriminate function dealing
    with non-streamable type only.

    @tparam T Type to check as a non-streamable type
    @tparam R Return type of the function to use if substitution succeed
  **/
  template <typename T, typename R>
  using if_not_streamable = typename std::enable_if<!is_streamable<T>::type::value,R>::type;
} }

#endif
