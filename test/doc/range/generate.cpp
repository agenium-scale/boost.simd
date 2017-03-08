//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [generate]
#include <boost/simd/algorithm/generate.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

namespace bs =  boost::simd;

struct g
{
  g(float seed = 0.0f, float step = 1.0f)
    : i_(seed),  step_(step)  {}
  template < typename T> T operator()(bs::as_<T>)
  {
    auto z = bs::enumerate<T>(i_, step_);
    i_+= bs::cardinal_of<T>::value*step_;
    return z;
  }
  float i_;
  float step_;
};

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d(8);
  d[7] = 42.0f;
  bs::generate( d.data(),d.data()+7, g() );
  std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;
  bs::generate( d.data(),d.data()+7, g(2.0f, 0.5f) );
  std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;
  bs::generate( d.data()+1,d.data()+8, g() );
  std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;
  bs::generate( d.data()+1,d.data()+8, g(2.0f, 0.5f) );
  std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;
  return 0;
 }
//! [generate]
