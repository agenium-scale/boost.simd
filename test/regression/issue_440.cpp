//==================================================================================================
/*!
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/memory/aligned_object.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <iostream>
#include <vector>

struct foo
{
  BOOST_SIMD_ALIGNED_OBJECT(foo);

  foo() = default;
  foo(boost::simd::pack<float> const& a) : p(a) {}

  boost::simd::pack<char,16> q;
  boost::simd::pack<float> p;
};

int main()
{
  std::vector<foo, boost::simd::allocator<foo>> p(5, foo{ boost::simd::pack<float>{3.f} });

  for(auto const& e : p)
    std::cout << (void*)(&e) << " " << e.p << "\n";
}
