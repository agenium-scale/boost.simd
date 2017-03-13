//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [transform_reduce2]
#include <boost/simd/algorithm/transform_reduce.hpp>
#include <boost/simd/function/toint.hpp>
#include <iostream>
#include <vector>

namespace bs =  boost::simd;

struct f
{
  template < class T >
  auto operator()(const T & a, const T & b) -> decltype(bs::toint(a*b))
  {
    return bs::toint(a)*bs::toint(b);
  }
};

int main()
{
  std::vector<float> d{1.5f, 2.5f, 3.5f, 4.5f, 5.5f, 6.5f, 7.5f, 8.5f, 9.5f, 10.5f} ;
  std::vector<float> e{1.5f, 2.5f, 3.5f, 4.5f, 5.5f, 6.5f, 7.5f, 8.5f, 9.5f, 10.5f} ;



  auto s1 = bs::transform_reduce( d.data(), d.data()+10, e.data(), f(), 0, bs::plus);
  std::cout << "s1 = " << s1 << std::endl;

  return 0;
}
//! [transform_reduce2]
