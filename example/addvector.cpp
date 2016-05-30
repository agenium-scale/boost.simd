#include <iostream>

//! [addvector]
#include <boost/simd/pack.hpp>

#include <boost/simd/function/load.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/simd/function/plus.hpp>

int main() {
  int size = 16;
  float *data0 = new float[size];
  float *data1 = new float[size];
  float *res   = new float[size];

  for ( int i = 0; i < size; ++i){
    data0[i] = i;
    data1[i] = i * 2;
  }

  //! [scalar-loop]
  for( int i = 0; i < size; ++i){
    res[i] = data0[i] + data1[i];
  }
  //! [scalar-loop]

  //! [sse2-simd-loop]
  __m128 v0_sse, v1_sse, r_sse;
  std::size_t f_card_sse = 4;
  for( int i = 0; i < size; i += f_card_sse){
    v0_sse = _mm_loadu_ps(&data0[i]);
    v1_sse = _mm_loadu_ps(&data1[i]);
    r_sse  = _mm_add_ps(v0_sse, v1_sse);
    _mm_storeu_ps(&res[i], r_sse);
  }
  //! [sse2-simd-loop]

  //! [avx-simd-loop]
  __m256 v0_avx, v1_avx, r_avx;
  std::size_t f_card_avx = 8;
  for( int i = 0; i < size; i += f_card_avx){
    v0_avx = _mm256_loadu_ps(&data0[i]);
    v1_avx = _mm256_loadu_ps(&data1[i]);
    r_avx  = _mm256_add_ps(v0_avx, v1_avx);
    _mm256_storeu_ps(&res[i], r_avx);
  }
  //! [avx-simd-loop]

  //! [arm-simd-loop]
  float32x4_t v0_arm, v1_arm, r_arm;
  std::size_t f_card_arm = 4;
  for( int i = 0; i < size; i += f_card_arm){
    v0_arm = vld1q_f32(&data0[i]);
    v1_arm = vld1q_f32(&data1[i]);
    r_arm  = vaddq_f32(v0_arm, v1_arm);
    vst1q_f32(&res[i], r_arm);
  }
  //! [arm-simd-loop]

  //! [bs-simd-loop]
  namespace bs = boost::simd;
  using pack_f = bs::pack<float>;

  pack_f v0, v1, r;
  size_t card = bs::cardinal_of<pack_f>();
  for( int i = 0; i < size; i += card){
    v0 = bs::load<pack_f>(&data0[i]);
    v1 = bs::load<pack_f>(&data1[i]);
    r  = bs::plus(v0, v1);
    bs::store(r, &res[i]);
  }
  //! [bs-simd-loop]
  delete [] data0;
  delete [] data1;
  delete [] res;

  return 0;
}
