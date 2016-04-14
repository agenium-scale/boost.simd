//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale (SAS)

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#define BOOST_SIMD_ENABLE_DIAG
#include <boost/simd/pack.hpp>
#include <boost/simd/function/definition/extract.hpp>
#include <boost/simd/arch/common/generic/function/automap.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

static std::size_t fake_count;

void reset() {
  fake_count = 1;
}

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, fake_counter_, boost::dispatch::elementwise_<fake_counter_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, fake_counter_);
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::fake_counter_, fake_counter);

  namespace ext
  {

    // double -> float
    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bd::scalar_<bd::double_<T>>
                            )
    {
      float operator()(T const&) const BOOST_NOEXCEPT
      {
        return static_cast<float>(fake_count++);
      }
    };

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bs::pack_<bd::double_<T>, bs::sse_>
                            )
    {
      boost::simd::pack<float, T::static_size> operator()(T const&) const BOOST_NOEXCEPT
      {
        return bs::pack<float, T::static_size>{static_cast<float>(fake_count++)};
      }
    };

    // float -> double
    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bd::scalar_<bd::single_<T>>
                            )
    {
      double operator()(T const&) const BOOST_NOEXCEPT
      {
        return static_cast<double>(fake_count++);
      }
    };

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bs::pack_<bd::single_<T>, bs::sse_>
                            )
    {
      boost::simd::pack<double, T::static_size> operator()(T const&) const BOOST_NOEXCEPT
      {
        return bs::pack<double, T::static_size>{static_cast<double>(fake_count++)};
      }
    };

    // int -> float
    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bd::scalar_<bd::int32_<T>>
                            )
    {
      float operator()(T const&) const BOOST_NOEXCEPT
      {
        return static_cast<float>(fake_count++);
      }
    };

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bs::pack_<bd::int32_<T>, bs::sse_>
                            )
    {
      boost::simd::pack<float, T::static_size> operator()(T const&) const BOOST_NOEXCEPT
      {
        return bs::pack<float, T::static_size>{static_cast<float>(fake_count++)};
      }
    };

    // char -> short
    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bd::scalar_<bd::int8_<T>>
                            )
    {
      short operator()(T const&) const BOOST_NOEXCEPT
      {
        return static_cast<short>(fake_count++);
      }
    };

    // (double, double) -> float
    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bd::scalar_<bd::double_<T>>
                            , bd::scalar_<bd::double_<T>>
                            )
    {
      float operator()(T const&, T const&) const BOOST_NOEXCEPT
      {
        return static_cast<float>(fake_count++);
      }
    };

    // (float, float) -> double
    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bd::scalar_<bd::single_<T>>
                            , bd::scalar_<bd::single_<T>>
                            )
    {
      double operator()(T const&, T const&) const BOOST_NOEXCEPT
      {
        return static_cast<double>(fake_count++);
      }
    };

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bs::pack_<bd::single_<T>, bs::sse_>
                            , bs::pack_<bd::single_<T>, bs::sse_>
                            )
    {
      bs::pack<double, T::static_size> operator()(T const&, T const&) const BOOST_NOEXCEPT
      {
        return bs::pack<double, T::static_size>{static_cast<double>(fake_count++)};
      }
    };

    // (int, int) -> float
    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bd::scalar_<bd::int32_<T>>
                            , bd::scalar_<bd::int32_<T>>
                            )
    {
      float operator()(T const&, T const&) const BOOST_NOEXCEPT
      {
        return static_cast<float>(fake_count++);
      }
    };

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bs::pack_<bd::int32_<T>, bs::sse_>
                            , bs::pack_<bd::int32_<T>, bs::sse_>
                            )
    {
      bs::pack<float, T::static_size> operator()(T const&, T const&) const BOOST_NOEXCEPT
      {
        return bs::pack<float, T::static_size>{static_cast<float>(fake_count++)};
      }
    };

    // (char, char) -> short
    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( fake_counter_
                            , (typename T)
                            , bd::cpu_
                            , bd::scalar_<bd::int8_<T>>
                            , bd::scalar_<bd::int8_<T>>
                            )
    {
      short operator()(T const&, T const&) const BOOST_NOEXCEPT
      {
        return static_cast<short>(fake_count++);
      }
    };

  }

} }

template <typename T, std::size_t N, typename Env>
void test1(Env& $)
{
  using p_t = bs::pack<T, N>;

  p_t p0{T{}};
  using return_t = decltype(bs::fake_counter(p0));

  STF_INFO("-- Using pack         : " << stf::type_id<p_t>());
  STF_INFO("-- Input storage pack : " << stf::type_id<typename p_t::storage_type>());
  STF_INFO("-- Output storage pack: " << stf::type_id<typename return_t::storage_type>());

  reset();
  return_t p1 = bs::fake_counter(p0);

  STF_INFO("p0: " << p0);
  STF_INFO("p1: " << p1);

  STF_INFO("-----------------------------------------");
}

template <typename T, std::size_t N, typename Env>
void test2(Env& $)
{
  using p_t = bs::pack<T, N>;

  p_t p0{T{}};
  p_t p1{T{}};
  using return_t = decltype(bs::fake_counter(p0, p1));

  STF_INFO("-- Using pack         : " << stf::type_id<p_t>());
  STF_INFO("-- Input storage pack : " << stf::type_id<typename p_t::storage_type>());
  STF_INFO("-- Output storage pack: " << stf::type_id<typename return_t::storage_type>());

  reset();
  return_t p2 = bs::fake_counter(p0, p1);

  STF_INFO("p0: " << p0);
  STF_INFO("p1: " << p1);
  STF_INFO("p2: " << p2);

  STF_INFO("-----------------------------------------");
}

STF_CASE("Check automap behaviour on pack")
{
  test1<double, 2>($);
  test1<double, 4>($);
  test1<double, 8>($);

  test1<float, 4>($);
  test1<float, 8>($);

  test1<int, 4>($);
  test1<int, 8>($);
  test1<int, 16>($);

  test1<char, 4>($);
  test1<char, 8>($);
  // --

  test2<double, 2>($);
  test2<double, 4>($);
  test2<double, 8>($);

  test2<float, 4>($);
  test2<float, 8>($);

  test2<int, 4>($);
  test2<int, 8>($);
  test2<int, 16>($);

  test2<char, 4>($);
  test2<char, 8>($);

  // --

  STF_PASS("Now take a look on how packs have been filled using automap");
}
