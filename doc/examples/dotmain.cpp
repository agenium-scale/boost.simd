//! [dot-main]
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/pack.hpp>

template <typename Value>
Value scaldot(Value* first1, Value* last1, Value* first2)
{
  Value v(0);

  for (; first1 < last1; ++first1, ++first2) {
    v += (*first1) * (*first2);
  }
  return v;
}

template <typename Value>
Value simddot(Value* first1, Value* last1, Value* first2)
{
  namespace bs = boost::simd;
  using pack_t = bs::pack<Value>;

  pack_t tmp{0};
  int card = pack_t::static_size;

  for (; first1 + card <= last1; first1 += card, first2 += card) {
    // Load current values from the datasets
    pack_t x1 = bs::load<pack_t>(first1);
    pack_t x2 = bs::load<pack_t>(first2);
    // Computation
    tmp = tmp + x1 * x2;
  }

  Value dot_product = bs::sum(tmp);
  for (; first1 < last1; ++first1, ++first2) {
    dot_product += (*first1) * (*first2);
  }

  return dot_product;
}

int main()
{
  namespace bs = boost::simd;
  using pack_t = bs::pack<float>;

  const size_t size = 113;
  float card_float  = bs::cardinal_of<pack_t>();

  std::vector<float> v1(size), v2(size);
  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 1);
  std::cout << "scalar dot product output " << scaldot(v1.data(), v1.data() + size, v2.data())
            << std::endl;
  std::cout << "simd   dot product output " << simddot(v1.data(), v1.data() + size, v2.data())
            << std::endl;
};
// This code can be compiled using (for instance for gcc)
// g++ dotmain.cpp -msse4.2 -std=c++11 -O3 -DNDEBUG -o dotmain
// -I/path_to/boost_simd/ -I/path_to/boost/
//! [dot-main]
