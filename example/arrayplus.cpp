#include <iostream>

//! [sum]
#include <boost/simd/pack.hpp>
//! [sum-include]
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/store.hpp>
//! [sum-include]

#define size 256

int main(void) {
  namespace bs = boost::simd;
  using ipack_t = bs::pack<int>;
  size_t ipack_card = bs::cardinal_of<ipack_t>();

  int *array = new int[size];
  int *out   = new int[size];

  // Initialize input array
  for ( size_t i = 0 ; i < size ; ++i )
    array[i] = i;

//! [sum-scalar]
  // Scalar version
  ipack_t one28{128};
  for ( size_t i = 0 ; i < size ; ++i )
    out[i] = array[i] - 128;
//! [sum-scalar]

//! [sum-load]
  // Using explicit load/store
  ipack_t p_out;
  ipack_t p_arr;
  for ( size_t i = 0 ; i < size ; i += ipack_card ) {
    p_out = bs::load<ipack_t>(out   + i);
    p_arr = bs::load<ipack_t>(array + i);
    p_out = p_arr - one28;
    bs::store(p_out , out + i);
  }
//! [sum-load]

//! [sum-pointer]
  // Using pointer construction
  for ( size_t i = 0 ; i < size ; i += ipack_card ) {
    ipack_t p_out(out   + i);
    ipack_t p_arr(array + i);
    p_out = p_arr - one28;
    bs::store(p_out , out + i);
  }
//! [sum-pointer]

//! [sum-packs]
  // Using large packs
  bs::pack<int,size> full_arr;
  bs::pack<int,size> full_out;
  bs::pack<int,size> full_128{128};

  full_arr = bs::load<bs::pack<int,size>>(array);
  full_out = full_arr - full_128;
  bs::store(full_out , out);
//! [sum-packs]

  return 0;
}
//! [sum]
