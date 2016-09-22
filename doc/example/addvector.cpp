#include <iostream>
#include <vector>

#include <boost/simd/algorithm.hpp>
#include <boost/simd/function/load.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/pack.hpp>

int main()
{
  int size = 16;
  std::vector<float, boost::simd::allocator<float>> data0(size);
  std::vector<float, boost::simd::allocator<float>> data1(size);
  std::vector<float, boost::simd::allocator<float>> res(size);

  for (int i = 0; i < size; ++i) {
    data0[i] = i;
    data1[i] = i * 2;
  }

  //! [scalar-loop]
  for (int i = 0; i < size; ++i) {
    res[i] = data0[i] + data1[i];
  }
  //! [scalar-loop]

  //! [sse2-simd-loop]
  std::size_t card_sse = 4;
  for (int i = 0; i < size; i += card_sse) {
    __m128 v0_sse = _mm_load_ps(&data0[i]);
    __m128 v1_sse = _mm_load_ps(&data1[i]);
    __m128 r_sse  = _mm_add_ps(v0_sse, v1_sse);

    _mm_store_ps(&res[i], r_sse);
  }
  //! [sse2-simd-loop]

  //! [avx-simd-loop]
  std::size_t card_avx = 8;
  for (int i = 0; i < size; i += card_avx) {
    __m256 v0_avx = _mm256_load_ps(&data0[i]);
    __m256 v1_avx = _mm256_load_ps(&data1[i]);
    __m256 r_avx  = _mm256_add_ps(v0_avx, v1_avx);

    _mm256_store_ps(&res[i], r_avx);
  }
  //! [avx-simd-loop]

  //! [vmx-simd-loop]
  std::size_t card_vmx = 4;
  for (int i = 0; i < size; i += card_vmx) {
    vector float v0_ibm = vec_ld(i, &data0[0]);
    vector float v1_ibm = vec_ld(i, &data1[0]);
    vector float r_ibm  = vec_add(v0_ibm, v1_ibm);

    vec_st(r_ibm, i, &res[0]);
  }
  //! [vmx-simd-loop]

  //! [bs-simd-loop]
  for (int i = 0; i < size; i += boost::simd::pack<float>::static_size) {
    boost::simd::pack<float> v0(&data0[i]), v1(&data1[i]);
    bs::aligned_store(v0 + v1, &res[i]);
  }
  //! [bs-simd-loop]

  //! [bs-simd-transform]
  boost::simd::transform(&data[0], &data[0] + size, &data1[0], &res[0], boost::simd::plus);
//! [bs-simd-transform]

#if 0
  //! [bs-simd-transform-14]
  boost::simd::transform( &data[0],&data[0]+size, &data1[0], &res[0], [](auto const& a, auto const& b) { return a+b; });
  //! [bs-simd-transform-14]
#endif

  return 0;
}
