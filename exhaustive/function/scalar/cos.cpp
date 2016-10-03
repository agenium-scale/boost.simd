//==============================================================================
//         Copyright 2016        NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/cos.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>

#include <exhaustive.hpp>

#include <cmath>
#include <cstdlib>

struct raw_cos
{
  float operator()(float x) const
  {
    return std::cos(double(x));
  }
};

struct my_cos
{
  float operator()(float x) const
  {
    return bs::cos(x, bs::tag::big_tag());
  }
};

int main(int argc, char* argv[])
{
  float mini = bs::Zero<float>();
  float maxi = bs::Valmax<float>();
  if(argc >= 2) mini = std::atof(argv[1]);
  if(argc >= 3) maxi = std::atof(argv[2]);
  bs::exhaustive_test<float> ( mini
                              , maxi
                             , my_cos()
                              , raw_cos()
                              );

  return 0;
}

