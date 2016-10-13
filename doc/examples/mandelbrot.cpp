//! [mandelbrot-all]
#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>

#include <boost/simd/pack.hpp>
#include <boost/simd/memory/allocator.hpp>

#include <boost/simd/function/aligned_load.hpp>
#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/function/enumerate.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

typedef float T;
namespace bs = boost::simd;
using pack_t = bs::pack<T>;
using pack_i = bs::pack<int>;
using pack_l = bs::as_logical_t<pack_t>;

struct mandelbrot{
  int size, max_iter;
  T x_min, x_max, y_min, y_max, x_range, y_range;
  std::vector<int, bs::allocator<int>> iterations;

  mandelbrot(int size_, int max_iter_) : size(size_), max_iter(max_iter_){
    x_min = -2.5;
    x_max = 1;
    y_min = -1;
    y_max = 1;
    x_range = x_max - x_min;
    y_range = y_max - y_min;
    iterations.resize(size * size);
  }

  void evaluate_scalar(){
    for(int i = 0; i < size; ++i){
      T x0 = T(i) / T(size) * x_range + x_min;
      for(int j = 0; j < size; ++j){
	int iteration  = 0;
	T y0 = T(j) / T(size) * y_range + y_min;
	T x = 0;
	T y = 0;
	while(x * x + y * y < 4 && iteration < max_iter){
	  T x_temp = x * x - y * y + x0;
	  y = 2 * x * y + y0;
	  x = x_temp;
	  ++iteration ;
	}
	iterations[j + i * size] = iteration;
      }
    }
  }

  //! [mandelbrot-simd]
  void evaluate_simd(){
    pack_t step =  bs::enumerate<pack_t>(0);
    for(int i = 0; i < size; ++i){
      pack_t x0 {T(i) / T(size) * x_range + x_min};
      pack_t fac { y_range / T(size) };
      pack_t y_min_t {y_min};
      for(int j = 0; j < size; j += pack_t::static_size){
	int iteration  = 0;

	pack_t y0 = (step + j )* fac + y_min_t;
	pack_t x {0};
	pack_t y {0};
	pack_i iter {0};
	pack_l mask;
	do{
	  pack_t x2 = x * x;
	  pack_t y2 = y * y;

	  y = 2 * x * y + y0;
	  x = x2 - y2 + x0;
	  mask = x2 + y2 < 4;
	  ++iteration;
          iter = bs::if_inc(mask, iter);
	} while(bs::any(mask) && iteration < max_iter);
	bs::aligned_store(iter, &iterations[j + i * size]);
      }
    }
  }
  //! [mandelbrot-simd]

  void display() {
    cv::Mat display;
    cv::Mat A(size, size, CV_32SC1, iterations.data());
    A.convertTo(display, CV_8UC1, 255.0 / 1000.0);
    cv::applyColorMap(display, display, cv::COLORMAP_JET);
    cv::imshow("Mandelbrot", display);
    cv::waitKey(0);
  }
};

int main(int argc, char** argv)
{
  namespace chr = std::chrono;
  using hrc = chr::high_resolution_clock;

  int size = 1024;
  int max_iteration = 1000;
  mandelbrot image(size, max_iteration);
  auto t0 = hrc::now();
  image.evaluate_scalar();
  auto t1 = hrc::now();
  std::cout << " scalar " << chr::duration_cast<chr::milliseconds>(t1 - t0).count() << std::endl;

  t0 = hrc::now();
  image.evaluate_simd();
  t1 = hrc::now();
  std::cout << " simd " << chr::duration_cast<chr::milliseconds>(t1 - t0).count() << std::endl;
  image.display();
}
//! [mandelbrot-all]
