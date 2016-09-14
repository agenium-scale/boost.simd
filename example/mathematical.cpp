//! [mathematical-all]
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#include <boost/align/aligned_allocator.hpp>
#include <boost/align/aligned_delete.hpp>

#include <boost/simd/pack.hpp>
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/simd/function/sin.hpp>
#include <boost/simd/function/cos.hpp>
#include <boost/simd/function/sincos.hpp>
#include <boost/simd/function/ulpdist.hpp>
#include <boost/simd/constant/pio_4.hpp>

namespace bs = boost::simd;

template < typename T>
void test_results(const std::string & mes, const T & scalr, const T& simdr)
{
  std::cout << mes;
  for(int i = 0; i < scalr.size(); ++i)
  {
    if (bs::ulpdist(scalr[i], simdr[i]) > 0.5)
    {
      std::cout <<  " failed" << std::endl;
      return;
    }
  }
  std::cout <<  " succeeded" << std::endl;
}


int main(int argc, char **argv){
  namespace ba = boost::alignment;

  using pack_t = bs::pack<float>;

  std::size_t num_elements = 1024;
  std::size_t alignment = pack_t::alignment;
  //! [mathematical-declare]
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> X(num_elements);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> sinX(num_elements), sc_sinX(num_elements);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> cosX(num_elements), sc_cosX(num_elements);
  //! [mathematical-declare]

  //! [fill-input]
  for(int i = 0; i < num_elements; ++i){
    X[i] = (float(i)/num_elements)*bs::Pio_4<float>();
  }

  //! [fill-input]
  //! [mathematical-scalar]
  for(int i = 0; i < num_elements; ++i){
    sc_sinX[i] = std::sin(X[i]);
    sc_cosX[i] = std::cos(X[i]);
  }
  //! [mathematical-scalar]

  //! [mathematical-calc-individ]
  for(int i = 0; i < num_elements; i += pack_t::static_size){
    pack_t v0 = bs::load<pack_t>(&X[i]);
    bs::store(bs::sin(v0), &sinX[i]);
    bs::store(bs::cos(v0), &cosX[i]);
  }
  //! [mathematical-calc-individ]
  test_results("sin test               ", sc_sinX, sinX);
  test_results("cos test               ",sc_cosX, cosX);

  //! [mathematical-calc-combine]
  for(int i = 0; i < num_elements; i += pack_t::static_size){
    pack_t v0 = bs::load<pack_t>(&X[i]);
    auto res = bs::sincos(v0);
    bs::store(res.first,  &sinX[i]);
    bs::store(res.second, &cosX[i]);
  }
  //! [mathematical-calc-combine]
  test_results("sincos test for sin    ", sc_sinX, sinX);
  test_results("sincos test for cos    ", sc_cosX, cosX);

  //! [mathematical-calc-restricted]
  for(int i = 0; i < num_elements; i += pack_t::static_size){
    pack_t v0 = bs::load<pack_t>(&X[i]);
    bs::store(bs::restricted_(bs::sin)(v0), &sinX[i]);
    bs::store(bs::restricted_(bs::cos)(v0), &cosX[i]);
  }
  //! [mathematical-calc-restricted]
  test_results("restricted_(sin) test  ", sc_sinX, sinX);
  test_results("restricted_(cos) test  ", sc_cosX, cosX);

  return 0;
}
// This code can be compiled using (for instance for gcc)
// g++ mathematical.cpp -msse4.2 -std=c++11 -O3 -DNDEBUG -o mathematical -I/path_to/boost_simd/ -I/path_to/boost/

//! [mathematical-all]
