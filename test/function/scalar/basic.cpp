#include <iostream>
#include <boost/simd/pack.hpp>
#include <vector>
#include <list>
int main()
{
  namespace bs = boost::simd;
  using pack_t = bs::pack<float,8>;
  pack_t res;
  pack_t tens{10};
  pack_t elevens(11);
  std::vector<float> values {10, 11, 12, 13, 14, 15, 16, 17};
  pack_t ptr_pack(values.data());
//   std::list<float> values {10, 11, 12, 13, 14, 15, 16, 17};
//   pack_t ptr_pack(values.begin(), values.end());
  res = (tens + elevens) * 2.f;
  std::cout << res << std::endl;
  std::cout << ptr_pack << std::endl;
  return 0;
}
