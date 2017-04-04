//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [replace_if]
#include <boost/simd/algorithm/replace_if.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

namespace bs =  boost::simd;

struct p
{

  template < typename T >
  auto operator()(const T & t) const -> decltype((t >= 3.5f)&&(t < 5.0f))
  {
    return (t >= 3.5f)&&(t < 5.0f);
  }
};


int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d{2.0f, 2.5f, 4.0f, 3.5f, 4.0f, 4.0f, 5.0f, 4.0f};
  d[7] = 42.0f;
  bs::replace_if( d.data(),d.data()+7, p(),  0.0f);
  std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;

  std::vector<float> d1{4.0f, 2.5f, 4.0f, 3.5f, 4.0f, 4.0f, 5.0f, 4.0f};
  bs::replace_if( d1.data()+1,d1.data()+8, p(),  0.0f);
  std::cout << "d1 =  (" ;
  for( auto e : d1) std::cout << e << " ";
  std::cout << ") " << std::endl;

  return 0;
 }
//! [replace_if]
