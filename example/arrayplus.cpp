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
#include <boost/simd/function/minus.hpp>
//! [sum-include]

int main(int argc, char **argv) {
  if(argc < 2){
    std::cerr << " incorrect number of arguments: " << argv[0] << " <scalar> " << std::endl;
  }
  namespace bs = boost::simd;
  int size = 128;
  using ipack_t = bs::pack<int>;
  //! [sum-cardinal]
  size_t ipack_card = bs::cardinal_of<ipack_t>();
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
  //! [sum-pointer]
  // Using pointer construction
  ipack_t one28{scalar};
  for ( size_t i = 0 ; i < size ; i += ipack_card ) {
    ipack_t p_arr(array.data() + i);
    p_out = p_arr - one28;
    bs::store(p_out , out.data() + i);
  }
  //! [sum-pointer]
  }
  
  {
  //! [sum-load]
  // Using explicit load/store
  ipack_t p_out;
  ipack_t p_arr;
  ipack_t one28{scalar};
  for ( size_t i = 0 ; i < size ; i += ipack_card ) {
    p_arr = bs::load<ipack_t>(array.data() + i);
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
  ipack_t p_out;
  ipack_t p_arr;
  ipack_t one28{scalar};
  size_t i = 0;
  for (; i + ipack_card <= size ; i += ipack_card ) {
    p_arr = bs::load<ipack_t>(array.data() + i);
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
