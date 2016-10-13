#include <iostream>
#include <typeinfo>

#include <boost/simd/pack.hpp>
#include <boost/simd/algorithm.hpp>

struct adder{
  template<typename T>
  T operator()(T const& a, T const& b){
    return a + b;
  }
};

//! [runtime-dec]
void compute(float *a, float *b, float *res, int size, BOOST_SIMD_DEFAULT_SITE const& arch){
//! [runtime-dec]
  std::cout<<" Architecture: " << typeid(arch).name() << std::endl;
  namespace bs = boost::simd;
  bs::transform(a, a + size, b, res, adder{});
}
