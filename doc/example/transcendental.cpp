#include <iostream>
#include <vector>
#include <cmath>

#include <boost/align/aligned_allocator.hpp>
#include <boost/align/aligned_delete.hpp>

#include <boost/simd/pack.hpp>
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/simd/function/sin.hpp>
#include <boost/simd/function/cos.hpp>
#include <boost/simd/function/sincos.hpp>

int main(int argc, char **argv){
  namespace bs = boost::simd;
  namespace ba = boost::alignment;

  using pack_t = bs::pack<float>;

  std::size_t num_elements = 1024;
  std::size_t alignment = pack_t::alignment;
  //! [transcendental-declare]
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> X(num_elements);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> sinX(num_elements);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> cosX(num_elements);
  //! [transcendental-declare]

  //! [transcendental-scalar]
  for(int i = 0; i < num_elements; ++i){
    sinX[i] = std::sin(X[i]);
    cosX[i] = std::cos(X[i]);
  }
  //! [transcendental-scalar]

  //! [transcendental-calc-individ]
  for(int i = 0; i < num_elements; i += pack_t::static_size){
    pack_t v0 = bs::load<pack_t>(&X[i]);
    bs::store(bs::sin(v0), &sinX[i]);
    bs::store(bs::cos(v0), &sinX[i]);
  }
  //! [transcendental-calc-individ]

  //! [transcendental-calc-combine]
  for(int i = 0; i < num_elements; i += pack_t::static_size){
    pack_t v0 = bs::load<pack_t>(&X[i]);
    auto res = bs::sincos(v0);
    bs::store(res.first, &sinX[i]);
    bs::store(res.second, &cosX[i]);
  }
  //! [transcendental-calc-combine]

  //! [transcendental-calc-small]
  for(int i = 0; i < num_elements; i += pack_t::static_size){
    pack_t v0 = bs::load<pack_t>(&X[i]);
    bs::store(bs::sin(v0, bs::tag::small_), &sinX[i]);
  }
  //! [transcendental-calc-small]
}
