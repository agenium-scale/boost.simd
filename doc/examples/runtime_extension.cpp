#include <boost/simd/pack.hpp>

#include "compute.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>

int main(){
  int size = 1000;
  std::vector<float> a(size), b(size), res(size);
  //![runtime-main]
  namespace bs = boost::simd;

  if(bs::avx2.is_supported()){
    compute(a.data(), b.data(), res.data(), size, bs::avx2_{});
  }
  else if(bs::avx.is_supported()){
    compute(a.data(), b.data(), res.data(), size, bs::avx_{});
  }
  else if(bs::sse4_2.is_supported()){
    compute(a.data(), b.data(), res.data(), size, bs::sse4_2_{});
  }
  else if(bs::sse4_1.is_supported()){
    compute(a.data(), b.data(), res.data(), size, bs::sse4_1_{});
  }
  else if(bs::sse2.is_supported()){
    compute(a.data(), b.data(), res.data(), size, bs::sse3_{});
  }
  //![runtime-main]
}
