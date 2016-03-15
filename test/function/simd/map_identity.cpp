//==================================================================================================
/*!
  @file

  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/definition/extract.hpp>
#include <boost/simd/arch/common/generic/function/map.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, identity_, boost::dispatch::elementwise_<identity_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, identity_);
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::identity_, printer);

  namespace ext
  {
    BOOST_DISPATCH_OVERLOAD ( identity_
                            , (typename P)
                            , bd::cpu_
                            , bs::pack_<bd::double_<P>, bs::sse_>
                            )
    {
      P operator()(P const& p) const BOOST_NOEXCEPT
      {
        return p;
      }
    };


    BOOST_DISPATCH_OVERLOAD ( identity_
                            , (typename T)
                            , bd::cpu_
                            , bd::scalar_<bd::single_<T>>
                            )
    {
      T operator()(T const& f) const BOOST_NOEXCEPT
      {
        return f;
      }
    };
  }

} }

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  STF_INFO(stf::type_id<p_t>());
  STF_INFO(stf::type_id<typename p_t::storage_type>());

  p_t p0;
  STF_INFO(p0);
  p_t p1 = bs::printer(p0);
  STF_INFO(p1);
  STF_INFO("-----------------------------------------");
}

STF_CASE_TPL("Check map identity on pack" , STF_NUMERIC_TYPES)
{
  test<double, 2>($);
  test<double, 4>($);
  test<double, 8>($);
  test<float, 2>($);
}
