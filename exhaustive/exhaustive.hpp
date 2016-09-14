// -------------------------------------------------------------------------------------------------
/*!
  @file Main header for exhaustive components
  @copyright 2016 - NumScale SAS
  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
// -------------------------------------------------------------------------------------------------

#ifndef EXHAUSTIVE_EXHAUSTIVE_HPP_INCLUDED
#define EXHAUSTIVE_EXHAUSTIVE_HPP_INCLUDED

#include <boost/simd/function/load.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/successor.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/ulpdist.hpp>
#include <boost/simd/function/iround.hpp>
#include <boost/simd/function/ilog2.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstddef>
#include "omp.hpp"
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/config.hpp>
#include <boost/core/demangle.hpp>
#include <type_traits>


namespace bd = boost::dispatch;
namespace bs = boost::simd;
namespace boost { namespace simd {
  /*!
    @defgroup group-exhaustive exhaustive tests components
    Exhaustive components
  **/

  template<typename T> inline std::string type_id()
  {
    typedef std::is_const<typename std::remove_reference<T>::type>  const_t;
    typedef std::is_lvalue_reference<T>                             lref_t;
    typedef std::is_rvalue_reference<T>                             rref_t;
    std::string s = boost::core::demangle(typeid(T).name());
    s += const_t::value ? " const"  : "";
    s += lref_t::value   ? "&"      : "";
    s += rref_t::value   ? "&&"     : "";
    return s;
  }
  template<typename T> inline std::string type_id( const T& )
  {
    return type_id<T>();
  }

  /*!
    @brief Exhaustive precision test for single precision

    Perform a ULP test on every representable single precision value
    in a given interval. Results are reported using a bucket histogram that
    gives hint on how many values fall in a given range of ULPs,
    the smallest and greatest inputs in the chosen range
    leading to this precision and  the result from this minimum input
    against the awaited result.

    @par Note:
    Currently this function is designed to take care of single precision only as
    running such a test on double precision values take an absurd amount of time.

    @tparam Type          Data type used for computation
    @param  mini Lower    bound of the test interval
    @param  maxi Upper    bound of the test interval
    @param  test_f        Function to test
    @param  reference_f   Reference function to compare to

    @par Example:

    Here is an example to test SIMD single-precision nt2::log against scalar double-precision std::log.

    @code
    #include <boost/simd/function/log.hpp>
    #include <boost/simd/constant/zero.hpp>
    #include <boost/simd/constant/valmax.hpp>
    #include <boost/simd/pack.hpp>
    #include <exhaustive.hpp>

    #include <cmath>
    #include <cstdlib>

    // function object used for the reference
    struct std_log
    {
      float operator()(float x) const
      {
        return float(std::log(double(x)));
      }
    };

    int main(int argc, char* argv[])
    {
      // define boundaries from command-line arguments,
      // fallback to default values if not provided
      float mini = bs::Zero<float>();
      float maxi = bs::Valmax<float>();
      if(argc >= 2) mini = std::atof(argv[1]);
      if(argc >= 3) maxi = std::atof(argv[2]);


      using n_t = bs::pack<float>;

      // run the test
      bs::exhaustive_test<n_t>( mini
                              , maxi
                              , bs::log // function object to test
                              , std_log()
                              );
      return 0;
    }
    @endcode
    **/
    template<typename Type, typename TestF, typename RefF> inline
    void exhaustive_test(float mini, float maxi, TestF test_f, RefF reference_f)
    {
      typedef Type                                                     n_t;
      typedef bd::as_integer_t<Type>                                  in_t;

      static const std::uint32_t M = 128;
      static const std::uint32_t N = bs::cardinal_of<n_t>::value;
      in_t vN = bs::splat<in_t>(N);

      std::uint32_t histo[M+2];
      float maxin[M+2], minin[M+2], minref[M+2], minval[M+2];

      for(auto& e : histo ) e = 0;
      for(auto& e : minin ) e = bs::Valmax<float>();
      for(auto& e : maxin ) e = bs::Valmin<float>();
      for(auto& e : minval) e = bs::Nan<float>();
      for(auto& e : minref) e = bs::Valmax<float>();

      auto t_min = bs::bitwise_cast<std::uint32_t>(bs::abs(mini));
      auto t_max = bs::bitwise_cast<std::uint32_t>(bs::abs(maxi));

      auto diff  = (mini*maxi < 0)  ? std::max(t_max,t_min) + std::min(t_max,t_min)
        : std::max(t_max,t_min) - std::min(t_max,t_min);

      std::cout << "Exhaustive test for: " << bs::type_id(test_f)      << "\n"
                << "             versus: " << bs::type_id(reference_f) << "\n"
                << "             With T: " << bs::type_id<Type>()      << "\n"
                << "           in range: [" << mini << ", " << maxi << "]" << "\n"
                << "         # of tests: " << diff << "\n";
      std::cout << std::endl;

      std::uint32_t k = 0;

#ifdef _OPENMP
#pragma omp parallel firstprivate(mini,maxi,diff)
#endif
      {
        bool  hit_loc[M+2];
        std::uint32_t histo_loc[M+2];
        float maxin_loc[M+2] , minin_loc[M+2], minref_loc[M+2], minval_loc[M+2];

        for(auto& e : hit_loc   ) e = false;
        for(auto& e : histo_loc ) e = 0;
        for(auto& e : minin_loc ) e = bs::Valmax<float>();
        for(auto& e : maxin_loc ) e = bs::Valmin<float>();
        for(auto& e : minval_loc) e = bs::Nan<float>();
        for(auto& e : minref_loc) e = bs::Valmax<float>();

        std::size_t numThreads  = get_num_threads();
        std::size_t my_id       = get_thread_num();
        std::size_t num_inc     = diff / numThreads;

        float my_mini = bs::successor(mini,my_id*num_inc);
        float my_maxi = bs::successor(my_mini,num_inc);
        if (my_id == numThreads -1) my_maxi = maxi;

        // Fill up the reference SIMD register data
        float a[N];
        a[0] = my_mini;
        for(std::size_t i = 1; i < N; i++) a[i] = bs::successor(a[i-1], 1);
        n_t a0 = bs::load<n_t>(&a[0],0);

        std::uint32_t k_loc = 0;

        while( bs::extract(a0,1) < my_maxi )
        {
          n_t z = test_f(a0);

          for(std::size_t i = 0; i < N; i++)
          {
            if (bs::extract(a0,i)> my_maxi) break;
            float v = reference_f(bs::extract(a0,i));
            float sz = bs::extract(z,i);

            double u = bs::ulpdist(v, sz)*2.0+1.0;

            if(bs::is_invalid(u))
            {
              ++histo_loc[M+1];
              if (!hit_loc[M+1])
              {
                maxin_loc [M+1] = minin_loc [M+1] = bs::extract(a0,i);
                minref_loc[M+1] = v;
                minval_loc[M+1] = bs::extract(z,i);
                hit_loc[M+1] = true;
              }
              else
              {
                maxin_loc [M+1] = bs::extract(a0,i);
              }
            }
            else
            {
              int p = bs::min(int(M), int(bs::ilog2(bs::iround(u))));

              if (!hit_loc[p])
              {
                maxin_loc [p] = minin_loc [p] = bs::extract(a0,i);
                minref_loc[p] = v;
                minval_loc[p] = bs::extract(z,i);
                hit_loc[p] = true;
              }
              else
              {
                maxin_loc [p] = bs::extract(a0,i);
              }
              ++histo_loc[p];
            }

            ++k_loc;
          }
          a0 = bs::successor(a0, vN);
        }

#ifdef _OPENMP
#pragma omp critical
#endif
        {
          for (std::size_t kk=0;kk<M+2;kk++)
          {
            maxin[kk] = std::max(maxin_loc[kk],maxin[kk]);

            if (minin_loc[kk]<minin[kk])
            {
              minin[kk] = std::min(minin_loc[kk],minin[kk]);
              minval[kk] = minval_loc[kk];
            }

            minref[kk] = std::min(minref_loc[kk],minref[kk]);
            histo[kk] += histo_loc[kk];
          }
          k += k_loc;
        }
      } //end omp parallel

      std::cout << k << "/" << diff << " values computed.\n";

      double d = 1;
      for(std::size_t i = 0; i < M+1; i++, d*= 2.0)
      {
        if(histo[i])
        {
          printf("%10u values (%.2f%%)\twithin %1.1f ULPs\t"
                , histo[i], (histo[i]*100.0/k), (d < 2 ? 0 : d/4)
                );
          if(i)
            std::cout << std::scientific << std::setprecision(9)
                      << "in range [" << minin[i] << ", "<< maxin[i] << "]" << "."
                      << " Example: "<< minin[i] << " returns " << minval[i]
                      << " instead of " << minref[i];
          std::cout << std::endl;
        }
      }

      if( histo[M+1])
      {
        printf("%10u values (%.2f%%)\twith invalid result.\t"
              , histo[M+1], (histo[M+1]*100.0/k)
              );
        std::cout << std::scientific << std::setprecision(9)
                  << "in range [" << minin[M+1] << ", "<< maxin[M+1] << "]" << "."
                  << " Example: "<< minin[M+1] << " returns " << minval[M+1]
                  << " instead of " << minref[M+1]
                  << std::endl;
      }
    }
  }
}


#endif
