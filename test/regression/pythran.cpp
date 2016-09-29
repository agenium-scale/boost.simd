//==================================================================================================
/*!
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <utility>
#include <array>

template<class T>
auto foo(T & t) -> typename std::enable_if<std::is_scalar<T>::value, decltype(boost::simd::sqr(t))>::type
{
  return boost::simd::sqr(t);
}

template<class T>
auto foo(T &t) -> typename std::enable_if<!std::is_scalar<T>::value, T &>::type
{
  for(std::size_t i = 0; i < t.size(); ++i)
    t[i] = foo(t[i]);
  return t;
}

int main()
{
  std::array<int, 3> data = {{1,2,3}};
  foo(data);

  return 0;
}
