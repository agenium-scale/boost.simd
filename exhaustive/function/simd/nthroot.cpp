//==============================================================================
//         Copyright 2016        Numscale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/simd/nthroot.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/pack.hpp>
#include <exhaustive.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

#include <cmath>
#include <cstdlib>

struct raw_nth
{
  float operator()(float x) const
  {
    return bs::nthroot(double(x), 4);
  }
};

struct nth
{
  bs::pack<float> operator()(bs::pack<float> x) const
  {
    using pi_t = bd::as_integer_t<bs::pack<float>>;
    return bs::nthroot(x, pi_t(4));
  }
};

int main(int argc, char* argv[])
{

  float mini = bs::Zero<float>();
  float maxi = bs::Valmax<float>();
  if(argc >= 2) mini = std::atof(argv[1]);
  if(argc >= 3) maxi = std::atof(argv[2]);
  bs::exhaustive_test<bs::pack<float>> ( mini
                                       , maxi
                                       , nth()
                                       , raw_nth()
                                       );

  return 0;
}
