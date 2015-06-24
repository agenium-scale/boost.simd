//==================================================================================================
/*!
  @file

  Defines the is_container meta-function

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_DETAIL_IS_CONTAINER_HPP_INCLUDED
#define NSTEST_COMMON_DETAIL_IS_CONTAINER_HPP_INCLUDED

#include <cstddef>
#include <type_traits>

namespace nstest { namespace detail
{
  /*!
    @ingroup group-details

    Checks if a type fulfills the requirement of being accessible
    via a @c begin()/end()/size() interface.

    @par Model:

    @metafunction

    @par Semantic:

    For any type @c T:

    @code
    using type = nstest::detail::is_container<T>::type;
    @endcode

    is equivalent to @true_ if:

    @code
    T t;
    auto b = t.begin();
    auto e = t.end();
    auto s = t.size();
    @endcode

    is well-formed. Otherwise, it i equivalent to @false_ .

    @tparam T Type to check
  **/
  template<typename T> struct is_container
  {
    template<typename U>
    static auto test( int ) -> decltype ( std::declval<U>().begin()
                                        , std::declval<U>().end()
                                        , std::declval<U>().size()
                                        , std::true_type()
                                        );

    template<typename>
    static auto test( ... ) -> std::false_type;

    typedef std::is_same<decltype(test<T>(0)),std::true_type> type;
  };

  /*!
    @brief SFINAE trigger for container types
    @ingroup group-details

    This template alias is to be used in SFINAE context to discriminate function dealing
    with container type only.

    @tparam T Type to check as a container
    @tparam R Return type of the function to use if substitution succeed
  **/
  template <typename T, typename R>
  using if_container = typename std::enable_if<is_container<T>::type::value,R>::type;


  /*!
    @brief SFINAE trigger for non-container types
    @ingroup group-details

    This template alias is to be used in SFINAE context to discriminate function dealing
    with non-container type only.

    @tparam T Type to check as a non-container
    @tparam R Return type of the function to use if substitution succeed
  **/
  template <typename T, typename R>
  using if_not_container = typename std::enable_if<!is_container<T>::type::value,R>::type;

#if defined(DOXYGEN_ONLY)

  /*!
    @ingroup group-details

    @brief Generic @c size function.

    Returns the size of any value @c v.

    @par Semantic:

    For any value @c v of type @c T,

    @code
    auto s = size(v);
    @endcode

    is equivalent to

    @code
    auto s = v.size();
    @endcode

    if @c T models @c Container and to:

    @code
    auto s = 1ull;
    @endcode

    otherwise.

    @param v Value which size is to be computed
    @return The number of value stored in @c v
  **/
  template<typename C> inline std::size_t size(C const& v);

  /*!
    @ingroup group-details

    @brief Generic @c begin function.

    Returns an iterator to the first element of any value @c v .

    @par Semantic:

    For any value @c v of type @c T,

    @code
    auto i = begin(v);
    @endcode

    is equivalent to

    @code
    auto i = v.begin();
    @endcode

    if @c T models @c Container and to:

    @code
    auto i = &v;
    @endcode

    otherwise.

    @param v Value to access
    @return An iterator to the first value of @c v
  **/
  template<typename C> inline auto begin(C const& v);

  /*!
    @ingroup group-details

    @brief Generic @c end function.

    Returns an iterator past the last element of any value @c v.

    @par Semantic:

    For any value @c v of type @c T,

    @code
    auto i = end(v);
    @endcode

    is equivalent to

    @code
    auto i = v.end();
    @endcode

    if @c T models @c Container and to:

    @code
    auto i = &v+1;
    @endcode


    @param v Value to access
    @return An iterator past last first value of @c v

  **/
  template<typename C> inline auto end(C const& v);

#else

  template<typename C>
  inline detail::if_container<C,std::size_t> size(C const& c)   { return c.size(); }

  template<typename C>
  inline detail::if_not_container<C,std::size_t> size(C const&) { return 1ull; }

  template<typename C>
  inline detail::if_container<C,typename C::const_iterator> begin(C const& c) { return c.begin(); }

  template<typename C>
  inline detail::if_not_container<C,C const*> begin(C const& t) { return &t; }

  template<typename C>
  inline detail::if_container<C,typename C::const_iterator> end(C const& c) { return c.end(); }

  template<typename C>
  inline detail::if_not_container<C,C const*> end(C const& t) { return (&t)+1; }

#endif
} }

#endif
