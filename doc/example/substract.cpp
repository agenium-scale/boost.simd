//! [substract]
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <boost/simd/pack.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/simd/function/minus.hpp>

template < typename T>
void print(std::string mes, const T & out)
{
  std::cout << mes << std::endl;
  for(size_t i = 0; i < out.size(); ++i)
  {
    if(i && (i%8 == 0)) std::cout << std::endl;
    std::cout << std::setw(5) << out[i] << " ";
  }
  std::cout << std::endl << std::endl;
}


int main() {
  namespace bs = boost::simd;
  size_t size = 128;
  std::vector<int32_t> array(size);
  std::vector<int32_t> out(size);
  // Initialize input array
  std::iota(array.begin(), array.end(), 0);
  int32_t scalar = 42;

  using pack_t = bs::pack<int32_t>;
  size_t pack_card = bs::cardinal_of<pack_t>();

  // Scalar version
  for ( size_t i = 0; i < size; ++i ){
    out[i] = array[i] - scalar;
  }
  print("scalar loop output", out);

  {
    pack_t p_out, pkvalue(scalar);
    for ( size_t i = 0; i < size; i += pack_card ) {
      pack_t p_arr(array.data() + i);
      p_out = p_arr - pkvalue;
      bs::store(p_out, out.data() + i);
    }
    print("SIMD 1 loop output", out);
  }

  {
    pack_t p_out, p_arr, pkvalue{scalar};
    for ( size_t i = 0; i < size; i += pack_card ) {
      p_arr = bs::load<pack_t>(array.data() + i);
      p_out = p_arr - pkvalue;
      bs::store(p_out, out.data() + i);
    }
    print("SIMD 2 loop output", out);
  }


  {
    // set size to an arbitrary value
    size = 133;
    pack_t p_out, p_arr, pkvalue{scalar};
    array.resize(size);
    out.resize(size);
    std::iota(array.begin(), array.end(), 0);
    size_t i = 0;
    for (; i + pack_card <= size; i += pack_card ) {
      p_arr = bs::load<pack_t>(array.data() + i);
      p_out = p_arr - pkvalue;
      bs::store(p_out, out.data() + i);
    }

    for (; i < size; ++i){
      out[i] = array[i] - scalar;
    }
    print("SIMD 3 loop output", out);
  }
  return 0;
}
// This code can be compiled using (for instance for gcc)
// g++ substract.cpp -msse4.2 -std=c++11 -O3 -DNDEBUG -o substract -I/path_to/boost_simd/ -I/path_to/boost/
//! [substract]
