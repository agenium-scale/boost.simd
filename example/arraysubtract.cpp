#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>

//! [sum]
#include <boost/simd/pack.hpp>
#include <boost/simd/meta/cardinal_of.hpp>

//! [sum-include]
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/store.hpp>
//! [sum-include]
#include <boost/simd/function/minus.hpp>

int main(int argc, char **argv) {
  if(argc < 2){
    std::cerr << " incorrect number of arguments: " << argv[0] << " <scalar> " << std::endl;
  }
  namespace bs = boost::simd;
  int size = 128;
  using pack_t = bs::pack<int>;
  //! [sum-cardinal]
  size_t pack_card = bs::cardinal_of<pack_t>();
  //! [sum-cardinal]

  int scalar = std::atoi(argv[1]);
  std::vector<int> array(size);
  std::vector<int> out(size);

  // Initialize input array
  std::iota(array.begin(), array.end(), 0);

  //! [sum-scalar]
  // Scalar version
  for ( size_t i = 0 ; i < size ; ++i ){
    out[i] = array[i] - scalar;
  }
  //! [sum-scalar]

  {
  //! [sum-loop-con]
  for ( size_t i = 0 ; i < size ; i += pack_card ) {

  }
  //! [sum-loop-con]

  //! [sum-one28]
  pack_t one28(128);
  //! [sum-one28]

  //! [sum-pointer]
  for ( size_t i = 0 ; i < size ; i += pack_card ) {
    pack_t p_arr(array.data() + i);
    p_out = p_arr - one28;
    bs::store(p_out , out.data() + i);
  }
  //! [sum-pointer]
  }

  {
  //! [sum-load]
  // Using explicit load/store
  pack_t p_out;
  pack_t p_arr;
  pack_t one28{scalar};
  for ( size_t i = 0 ; i < size ; i += pack_card ) {
    p_arr = bs::load<pack_t>(array.data() + i);
    p_out = p_arr - one28;
    bs::store(p_out , out.data() + i);
  }
  //! [sum-load]
  }

  {
  //! [sum-remainder]
  // Using explicit load/store
  //set size to an arbitrary value
  size = 133;
  pack_t p_out;
  pack_t p_arr;
  pack_t one28{scalar};
  size_t i = 0;
  for (; i + pack_card <= size ; i += pack_card ) {
    p_arr = bs::load<pack_t>(array.data() + i);
    p_out = p_arr - one28;
    bs::store(p_out , out.data() + i);
  }

  for (; i < size ; ++i){
    out[i] = array[i] - scalar;
  }
  //! [sum-remainder]
  }
  return 0;
}
//! [sum]
