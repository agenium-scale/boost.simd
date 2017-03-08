//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [select]
#include <boost/simd/algorithm/select.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <iostream>
#include <vector>

namespace bs =  boost::simd;

struct p
{

  template < typename T >
  auto  operator()(const T & x, const T & y)  -> decltype(bs::is_gtz(x+y)) const
  {
    return bs::is_gtz(x+y);
  }
};

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d1{1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};
  std::vector<float> d2{-8.0f, -7.0f, -6.0f, -5.0f, -4.0f, -3.0f, -2.0f, -1.0f};
  std::vector<float> d(8);

  bs::select( d1.data(),d1.data()+8,  d2.data(), d.data(), p());
  std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;

  return 0;
 }
//! [select]
