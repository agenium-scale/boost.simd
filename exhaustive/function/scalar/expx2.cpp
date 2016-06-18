//==============================================================================
//         Copyright 2009 - 2013 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2013        MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/include/functions/expx2.hpp>
#include <nt2/include/constants/minlog.hpp>
#include <nt2/include/constants/mtwo.hpp>

extern "C" { double cephes_expx2(double x, int sign);}

#include <nt2/sdk/exhaustive/exhaustive.hpp>

#define NT2_ASSERTS_AS_TRAP
#include <nt2/sdk/error/assert_as_trap.hpp>

#include <cmath>
#include <cstdlib>

struct raw_expx2p
{
  float operator()(float x) const
  {
    return ::cephes_expx2(double(x), 0);
  }
};
struct raw_expx2m
{
  float operator()(float x) const
  {
    return ::cephes_expx2(double(x), -1);
  }
};

struct expx2m
{
template < class T>  T operator()(T x) const
  {
    return nt2::expx2(x, nt2::Mtwo<T>());
  }
};

int main(int argc, char* argv[])
{
  float mini = -9.4f;
  float maxi = 9.4f;
  if(argc >= 2) mini = std::atof(argv[1]);
  if(argc >= 3) maxi = std::atof(argv[2]);
  nt2::exhaustive_test<float> ( mini
                              , maxi
                              , nt2::functor<nt2::tag::expx2_>()
                              , raw_expx2p()
                              );
 nt2::exhaustive_test<float> ( mini
                              , maxi
                              , expx2m()
                              , raw_expx2m()
                              );

  return 0;
}
