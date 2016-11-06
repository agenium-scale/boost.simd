//==============================================================================
//         Copyright 2016        NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/cotpi.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>

#include <exhaustive.hpp>

#include <cmath>
#include <cstdlib>

struct raw_cotpi
{
  float operator()(float x) const
  {
    return bs::cotpi(double(x));
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
                              , bs::cotpi
                              , raw_cotpi()
                              );

  return 0;
}

