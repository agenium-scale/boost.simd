//==============================================================================
//         Copyright 2016        Numscale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/simd/exp2.hpp>
#include <boost/simd/constant/minlog2.hpp>
#include <boost/simd/constant/maxlog2.hpp>
#include <boost/simd/pack.hpp>
#include <exhaustive.hpp>

#include <cmath>
#include <cstdlib>

struct raw_exp2
{
  float operator()(float x) const
  {
    return ::exp2(double(x));
  }
};

int main(int argc, char* argv[])
{
  float mini = bs::Minlog2<float>();
  float maxi = bs::Maxlog2<float>();
  if(argc >= 2) mini = std::atof(argv[1]);
  if(argc >= 3) maxi = std::atof(argv[2]);
  bs::exhaustive_test<bs::pack<float>> ( mini
                                       , maxi
                                       , bs::exp2
                                       , raw_exp2()
                                       );

  return 0;
}
