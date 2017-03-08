//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale (SAS)

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/definition/extract.hpp>
#include <boost/simd/arch/common/generic/function/autosplat.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, pack_printer_, boost::dispatch::elementwise_<pack_printer_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, pack_printer_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::pack_printer_, pack_printer);

  namespace ext
  {

    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( pack_printer_
                            , ( typename P0, typename P1
                              , typename E0, typename E1
                              )
                            , bd::cpu_
                            , bs::pack_<bd::unspecified_<P0>, E0>
                            , bs::pack_<bd::unspecified_<P1>, E1>
                            )
    {
      void operator()(P0 const& p0, P1 const& p1) const BOOST_NOEXCEPT
      {
        std::cout << p0 << std::endl;
        std::cout << p1 << std::endl;
      }
    };


    // ---------------------------------------------------------------------------------------------

    BOOST_DISPATCH_OVERLOAD ( pack_printer_
                            , ( typename P0, typename P1, typename P2
                              , typename E0, typename E1, typename E2
                              )
                            , bd::cpu_
                            , bs::pack_<bd::unspecified_<P0>, E0>
                            , bs::pack_<bd::unspecified_<P1>, E1>
                            , bs::pack_<bd::unspecified_<P2>, E2>
                            )
    {
      void operator()(P0 const& p0, P1 const& p1, P2 const& p2) const BOOST_NOEXCEPT
      {
        std::cout << p0 << std::endl;
        std::cout << p1 << std::endl;
        std::cout << p2 << std::endl;
      }
    };

  }

} }

template <std::size_t N, typename T>
bs::pack<T, N> make_pack(T const& t)
{
  return bs::pack<T, N>{t};
}

template <std::size_t N, typename T, typename U, typename Env>
void test(Env& runtime, T const& v, U const& s)
{
  bs::pack<T, N> p{v};

  STF_INFO("(P, S)");
  bs::pack_printer(p, s);

  STF_INFO("(S, P)");
  bs::pack_printer(s, p);

  STF_INFO("-----------------------------------------");

  STF_INFO("(P, P, S)");
  bs::pack_printer(p, p, s);

  STF_INFO("(P, S, P)");
  bs::pack_printer(p, s, p);

  STF_INFO("(S, P, P)");
  bs::pack_printer(s, p, p);

  STF_INFO("-----------------------------------------");

  STF_INFO("(S, S, P)");
  bs::pack_printer(s, s, p);

  STF_INFO("(S, P, S)");
  bs::pack_printer(s, p, s);

  STF_INFO("(P, S, S)");
  bs::pack_printer(p, s, s);

  STF_INFO("-----------------------------------------");
}

STF_CASE("Check autosplatting behaviour")
{
  test<2>(runtime, 2., 4.f);
  test<4>(runtime, 2., 4.f);
  test<8>(runtime, 2., 4.f);

  // --

  STF_PASS("This should always print pack of the same size");
}
