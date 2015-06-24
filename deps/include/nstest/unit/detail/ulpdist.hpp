//==================================================================================================
/*!
  @file

  Defines the basic ulpdist function

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_DETAIL_ULPDIST_HPP_INCLUDED
#define NSTEST_UNIT_DETAIL_ULPDIST_HPP_INCLUDED

#include <nstest/common/detail/is_container.hpp>
#include <nstest/unit/detail/traits.hpp>
#include <algorithm>
#include <iterator>
#include <cmath>

namespace nstest
{
#if defined(DOXYGEN_ONLY)
  /*!
    @ingroup group-details

    @brief Distance in ULPs between values

    Computes the ULP distance between two values.

    @par Semantic:

    For any types @c T and @c U, any value @c a0 of type @c T and any value @c a1 of type @c U:

    @code
    auto r = ulpdist(a0,a1);
    @endcode

    is equivalent to:

    @code
    auto r = ulpdist( static_cast<std::common_t<T,U>>(a0), static_cast<std::common_t<T,U>>(a1));
    @endcode

    For any type @c T and any value of type @c T @c a0 and @c a1, then:

    @code
    auto r = ulpdist(a0,a1);
    @endcode

    is equivalent to:

    - if @c T is @c bool :
      @code
      auto r = a0==a1 ? 0. : 1.;
      @endcode

    - if @c T is an integral type:
      @code
      auto r = double( (a0>a1) ? a0-a1 : a1-a0 );
      @endcode
      i.e the number of different bits between @c a0 and @c a1

    - if @c T is a floating-point type, @c r is equal to the number of different bits between the
      normalized representation of @c a0 and @c a1 as defined by Golderg et al.

    - if @c T is a Container, @c r is a container containing the ULP distance between each pair of
    elements in @c a0 and @c a1

    @param a0 First value to compare
    @param a1 Second value to compare
    @return The distance in ULP between a0 and a1
  **/
  template<typename T, typename U> inline auto ulpdist(T a0, U a1);
#else

#endif

  inline double ulpdist(bool a0, bool a1) { return a0 == a1 ? 0. : 1.; }

  template<typename T>
  inline detail::if_integral<T,double> ulpdist(T const& a0, T const& a1)
  {
    using u_t = typename std::make_unsigned<T>::type;
    return static_cast<double>( (a0<a1) ? u_t(a1-a0) : u_t(a0-a1) );
  }

  template<typename T>
  inline detail::if_real<T,double> ulpdist(T const& a0, T const& a1)
  {
    if( (a0 == a1) || ((a0!=a0) && (a1!=a1)) )  return 0.;
    if( (a0!=a0) || (a1!=a1) )                  return std::numeric_limits<T>::infinity();

    int e1,e2;
    T   m1,m2;
    m1 = std::frexp(a0, &e1);
    m2 = std::frexp(a1, &e2);

    int expo = -std::max(e1, e2);

    T e = (e1 == e2)  ? std::abs(m1-m2)
                      : std::abs(std::ldexp(a0, expo)- std::ldexp(a1, expo));

    return double(e/std::numeric_limits<T>::epsilon());
  }

  template<typename T>
  inline detail::if_container<T,std::vector<double>> ulpdist(T const& a0, T const& a1)
  {
    using type = decltype(*a0.begin());
    std::vector<double> ulps;

    std::transform( a0.begin(), a0.end(), a1.begin()
                  , std::back_inserter(ulps)
                  , [](type const& a,type const& b) { using ::nstest::ulpdist; return ulpdist(a,b); }
                  );

    return ulps;
  }

  template<typename T, typename U>
  inline detail::if_container<T,std::vector<double>>
  ulpdist(T const& a0, U const& a1)
  {
    using type = decltype(*a0.begin());
    std::vector<double> ulps;

    std::transform( a0.begin(), a0.end()
                  , std::back_inserter(ulps)
                  , [&a1](type const& a) { using ::nstest::ulpdist; return ulpdist(a,a1); }
                  );

    return ulps;
  }

  template<typename T, typename U>
  inline detail::if_container<T,std::vector<double>>
  ulpdist(U const& a1,T const& a0)
  {
    using type = decltype(*a0.begin());
    std::vector<double> ulps;

    std::transform( a0.begin(), a0.end()
                  , std::back_inserter(ulps)
                  , [&a1](type const& a) { using ::nstest::ulpdist; return ulpdist(a1,a); }
                  );

    return ulps;
  }

  template<typename T, typename U, typename R>
  using are_not_containers = typename std::enable_if<   !detail::is_container<T>::type::value
                                                    &&  !detail::is_container<U>::type::value
                                                    ,   R
                                                  >::type;

  template<typename T, typename U>
  inline are_not_containers<T,U,double> ulpdist(T const& a0, U const& a1)
  {
    return ulpdist(static_cast<detail::common_t<T,U>>(a0), static_cast<detail::common_t<T,U>>(a1));
  }
}

#endif
