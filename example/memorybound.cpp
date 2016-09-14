#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/cos.hpp>
#include <boost/simd/function/sin.hpp>

int main(){
  using namespace std::chrono;
  namespace bs = boost::simd;
  using pack_t = bs::pack<float>;
  int size = 80000000;
  std::vector<float, bs::allocator<float>> data(size);
  std::vector<float, bs::allocator<float>> output(size);

  auto t0 = high_resolution_clock::now();
  for(int i = 0; i < size; ++i){
    data[i] *= 2;
  }
  auto t1 = high_resolution_clock::now();
  std::cout<<" time " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
  t0 = high_resolution_clock::now();
  //! [memory-memory]
  for(int i = 0; i < size; i += pack_t::static_size){
    pack_t v0(&data[i]);
    v0 = v0 * 2;
    bs::aligned_store(v0, &output[i]);
  }
  //! [memory-memory]
  t1 = high_resolution_clock::now();
  std::cout<<" time " << duration_cast<microseconds>(t1 - t0).count() << std::endl;

  t0 = high_resolution_clock::now();
  for(int i = 0; i < size; ++i){
    data[i] = std::exp(std::exp(data[i]));
  }
  t1 = high_resolution_clock::now();
  std::cout<<" time " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
  //! [memory-compute]
  t0 = high_resolution_clock::now();
  for(int i = 0; i < size; i += pack_t::static_size){
    pack_t v0(&data[i]);
    v0 = bs::exp(bs::exp(v0));
    bs::aligned_store(v0, &output[i]);
  }
  //! [memory-compute]
  t1 = high_resolution_clock::now();
  std::cout<<" time " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
}
