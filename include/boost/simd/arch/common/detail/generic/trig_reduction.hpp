//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSbd:E_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_DETAIL_GENERIC_TRIG_REDUCTION_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_DETAIL_GENERIC_TRIG_REDUCTION_HPP_INCLUDED

#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/rem_pio2_medium.hpp>
#include <boost/simd/function/rem_pio2_cephes.hpp>
#include <boost/simd/function/rem_pio2_straight.hpp>
#include <boost/simd/function/rem_pio2.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/split.hpp>
#include <boost/simd/function/group.hpp>
#include <boost/dispatch/meta/upgrade.hpp>

#include <boost/simd/function/all.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/round2even.hpp>
#include <boost/simd/function/if_else_nan.hpp>
#include <boost/simd/function/is_ngt.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/function/inrad.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/medium_pi.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/constant/real.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <utility>

//#include <nt2/sdk/meta/as_logical.hpp>
//#include <boost/simd/sdk/meta/is_upgradable.hpp>



namespace boost { namespace simd
{
  namespace detail
  {
    template< class A0
            , class unit_tag
            , class style
            , class mode
            , class base_A0 = bd::scalar_of_t<A0>
    >
    struct trig_reduction;

    // This class exposes the public static member:
    // reduce:                to provide range reduction
    //
    // unit_tag allows to choose statically the scaling  among radian_tag, pi_tag, degree_tag
    // meaning that the cosa function will (for example) define respectively
    // x-->cos(x)          (radian_tag),
    // x-->cos(p*x)        (pi_tag)
    // x-->cos((pi/180)*x) (degree_tag)
    //

    // trigonometric reduction strategies in the [-pi/4, pi/4] range.
    // these reductions are used in the accurate and fast
    // trigonometric functions with different policies

    template<class A0, class style, class mode>
    struct trig_reduction < A0, tag::radian_tag, style, mode>
    {
      using i_t = bd::as_integer_t<A0, signed>;
      using l_t = bs::as_logical_t<A0>;
      using conversion_allowed_t = std::false_type; //bd::is_upgradable_on_ext_<A0>; // TODO

      static BOOST_FORCEINLINE auto is_0_pio4_reduced(const A0&a0) BOOST_NOEXCEPT
      ->  decltype(is_ngt(a0, Pio_4<A0>()))
      {
        return is_ngt(a0, Pio_4<A0>());
      }
      static BOOST_FORCEINLINE auto is_pio4_pio2_reduced(const A0&a0) BOOST_NOEXCEPT
      ->  decltype(is_ngt(a0, Pio_2<A0>()))
      {
        return bitwise_and(is_ngt(a0, Pio_2<A0>()), is_greater(a0, Pio_4<A0>() ));
      }
      static BOOST_FORCEINLINE auto is_0_20pi_reduced(const A0&a0) BOOST_NOEXCEPT
      ->  decltype(is_ngt(a0, Real<A0, 0X404F6A7A2955385EULL, 0X427B53D1UL>()))
      {
        return is_ngt(a0, Real<A0, 0X404F6A7A2955385EULL, 0X427B53D1UL>()); //20 pi;
      }
      static BOOST_FORCEINLINE auto is_0_mpi_reduced (const A0&a0) BOOST_NOEXCEPT
      ->  decltype(is_ngt(a0, Medium_pi<A0>()))
      {
        return is_ngt(a0, Medium_pi<A0>()); //2^6 pi
      }
      static BOOST_FORCEINLINE auto is_0_dmpi_reduced(const A0&a0) BOOST_NOEXCEPT
      ->  decltype(is_ngt(a0,Constant<A0,262144>()))
      {
        return is_ngt(a0, Ratio<A0,262144>()); //2^18 pi
      }

      static BOOST_FORCEINLINE l_t cot_invalid(const A0& )  BOOST_NOEXCEPT
      {
        return False<l_t>();
      }
      static BOOST_FORCEINLINE l_t tan_invalid(const A0& )  BOOST_NOEXCEPT
      {
        return False<l_t>();
      }

      static BOOST_FORCEINLINE i_t reduce(const A0& x, A0& xr)  BOOST_NOEXCEPT
      {
        return inner_reduce(x, xr);
      }

      static BOOST_FORCEINLINE i_t inner_reduce(const A0& x, A0& xr) BOOST_NOEXCEPT
      {
        A0 xx =  preliminary<mode>::clip(x);
        return select_mode(xx, xr, boost::mpl::int_<mode::start>());
      }

      template < class Mode, bool clipped = Mode::clipped>
      struct preliminary
      {
        static BOOST_FORCEINLINE A0 const& clip(const A0& x) BOOST_NOEXCEPT  { return x; }
      };


      template < class Mode>
      struct preliminary<Mode, true>
      {
        static BOOST_FORCEINLINE A0 clip(const A0& x) BOOST_NOEXCEPT
        {
          return clipto(x, boost::mpl::int_<Mode::range>());
        }
      private :
        static BOOST_FORCEINLINE A0 clipto(const A0& x
                                          , boost::mpl::int_<tag::r_0_pio4> const&) BOOST_NOEXCEPT
        {
          return if_else_nan(is_0_pio4_reduced(x), x);
        }
        static BOOST_FORCEINLINE A0 clipto(const A0& x
                                          , boost::mpl::int_<tag::r_0_20pi> const&) BOOST_NOEXCEPT
        {
          return if_else_nan(is_0_20pi_reduced(x), x);
        }
        static BOOST_FORCEINLINE A0 clipto(const A0& x
                                          , boost::mpl::int_<tag::r_0_mpi> const&) BOOST_NOEXCEPT
        {
          return if_else_nan(is_0_mpi_reduced(x), x);
        }
        static BOOST_FORCEINLINE A0 clipto(const A0& x
                                          , boost::mpl::int_<tag::r_0_dmpi> const&) BOOST_NOEXCEPT
        {
          return if_else_nan(is_0_dmpi_reduced(x), x);
        }
      };

      static BOOST_FORCEINLINE i_t
      select_range( const A0& xx, A0& xr
                  , boost::mpl::true_ const&
                  , boost::mpl::int_<tag::r_0_pio4> const&
                  ) BOOST_NOEXCEPT
      {
        xr = xx;
        return Zero<i_t>();
      }

      static BOOST_FORCEINLINE i_t
      select_range( const A0& xx, A0& xr
                  , boost::mpl::false_ const&
                  , boost::mpl::int_<tag::r_0_pio4> const& r
                  ) BOOST_NOEXCEPT
      {
        if(all(is_0_pio4_reduced(xx)))
          return select_range(xx,xr,boost::mpl::true_(), r);

        return select_mode(xx,xr,boost::mpl::int_<tag::r_0_pio2>());
      }

      static BOOST_FORCEINLINE i_t
      select_mode(const A0& xx, A0& xr
                 , boost::mpl::int_<tag::r_0_pio4> const& r) BOOST_NOEXCEPT
      {
        return select_range(xx,xr,boost::mpl::bool_<mode::range == tag::r_0_pio4>(),r);
      }

      static BOOST_FORCEINLINE i_t
      select_mode(const A0& xx, A0& xr
                 , boost::mpl::int_<tag::r_0_pio2> const&) BOOST_NOEXCEPT
      {
        if(all(is_pio4_pio2_reduced(xx)))
        {
          i_t n;
          std::tie(n, xr) = rem_pio2_straight(xx);
          return n;
        }

        return select_mode(xx,xr,boost::mpl::int_<tag::r_0_20pi>());
      }

      static BOOST_FORCEINLINE i_t
      select_range( const A0& xx, A0& xr
                  , boost::mpl::true_ const&
                  , boost::mpl::int_<tag::r_0_20pi> const&
                  ) BOOST_NOEXCEPT
      {
        i_t n;
        std::tie(n, xr) = rem_pio2_cephes(xx);
        return n;
      }

      static BOOST_FORCEINLINE i_t
      select_range( const A0& xx, A0& xr
                  , boost::mpl::false_ const&
                  , boost::mpl::int_<tag::r_0_20pi> const& r
                  ) BOOST_NOEXCEPT
      {
        if(all(is_0_20pi_reduced(xx)))
          return select_range(xx,xr,boost::mpl::true_(), r);

        return select_mode(xx,xr,boost::mpl::int_<tag::r_0_mpi>());
      }

      static BOOST_FORCEINLINE i_t
      select_mode(const A0& xx, A0& xr
                 , boost::mpl::int_< tag::r_0_20pi> const& r) BOOST_NOEXCEPT
      {
        return select_range(xx,xr,boost::mpl::bool_<mode::range == tag::r_0_20pi>(),r);
      }



      static BOOST_FORCEINLINE i_t
      select_range( const A0& xx, A0& xr
                  , boost::mpl::true_ const&
                  , boost::mpl::int_<tag::r_0_mpi> const&
                  ) BOOST_NOEXCEPT
      {
        i_t n;
        std::tie(n, xr) = rem_pio2_medium(xx);
        return n;
      }

      static BOOST_FORCEINLINE i_t
      select_range( const A0& xx, A0& xr
                  , boost::mpl::false_ const&
                  , boost::mpl::int_<tag::r_0_mpi> const& r
                  ) BOOST_NOEXCEPT
      {
        if(all(is_0_mpi_reduced(xx)))
          return select_range(xx,xr,boost::mpl::true_(), r);

        return select_mode(xx,xr,boost::mpl::int_<tag::r_0_dmpi>());
      }

      static BOOST_FORCEINLINE i_t
      select_mode(const A0& xx, A0& xr
                 , boost::mpl::int_< tag::r_0_mpi> const& r) BOOST_NOEXCEPT
      {
        return select_range(xx,xr,boost::mpl::bool_<mode::range == tag::r_0_mpi>(),r);
      }

      static BOOST_FORCEINLINE i_t
      select_mode(const A0& xx, A0& xr
                 , boost::mpl::int_< tag::r_0_dmpi> const&) BOOST_NOEXCEPT
      {
        if(all(is_0_dmpi_reduced(xx)))
           return use_conversion(xx, xr, style(), conversion_allowed_t());
        i_t n;
        std::tie(n, xr) = rem_pio2(xx);
        return n;
      }

      static BOOST_FORCEINLINE i_t
      use_conversion(const A0 & xx,  A0& xr
                    ,  const style &, std::false_type) BOOST_NOEXCEPT
      {
        i_t n;
        std::tie(n, xr) = rem_pio2(xx);
        return n;
      }

      static BOOST_FORCEINLINE i_t
      use_conversion(const A0 & xx,  A0& xr
                    ,  const tag::not_simd_type &, std::true_type) BOOST_NOEXCEPT
      {
        // all of x are in [0, 2^18*pi],  conversion to double is used to reduce
        using uA0 = bd::upgrade_t<A0>;
        using aux_reduction = trig_reduction< uA0,tag::radian_tag,tag::not_simd_type,mode,double>;
        uA0 ux = xx, uxr;
        i_t n = static_cast<i_t>(aux_reduction::reduce(ux, uxr));
        xr = static_cast<A0>(uxr);
        return n;
      }

      static BOOST_FORCEINLINE i_t
      use_conversion(const A0 & x,  A0& xr
                    , const tag::simd_type &,std::true_type) BOOST_NOEXCEPT
      {
        // all of x are in [0, 2^18*pi],  conversion to double is used to reduce
        using uA0 = bd::upgrade_t<A0>;
        using aux_reduc_t = trig_reduction< uA0, tag::radian_tag,  tag::simd_type, mode, double>;
        uA0 ux1, ux2, uxr1, uxr2;
        split(x, ux1, ux2);
        auto n1 = aux_reduc_t::reduce(ux1, uxr1);
        auto n2 = aux_reduc_t::reduce(ux2, uxr2);
        xr = group(uxr1, uxr2);
        split(xr, ux1, ux2);
        return group(n1, n2);
      }
    };

    template<class A0, class style>
    struct trig_reduction<A0,tag::degree_tag, style, tag::big_tag>
    {
      using i_t = bd::as_integer_t<A0, signed>;

      static BOOST_FORCEINLINE auto cot_invalid(const A0& x) BOOST_NOEXCEPT
      -> decltype(is_nez(x)&&is_flint(x*Ratio<A0,1,180>()))
      {
        return is_nez(x)&&is_flint(x*Ratio<A0,1,180>());
      }
      static BOOST_FORCEINLINE auto tan_invalid(const A0& x) BOOST_NOEXCEPT
      -> decltype(is_flint((x- Ratio<A0,90>())*Ratio<A0,1,180>()))
      {
        return is_flint((x- Ratio<A0,90>())*Ratio<A0,1,180>());
      }

      static BOOST_FORCEINLINE i_t reduce(const A0& x, A0& xr) BOOST_NOEXCEPT
      {
        A0 xi = round2even(x*Ratio<A0,1,90>());
        A0 x2 = x - xi * Ratio<A0,90>();

        xr =  inrad(x2);
        return bs::fast_(toint)(xi);
      }
    };

#ifdef BOOST_SIMD_HAS_X87
    template<class A0>
    struct trig_reduction<A0,degree_tag, tag::not_simd_type, tag::big_tag>
    {
      using i_t = bd::as_integer_t<A0, signed>;

      static BOOST_FORCEINLINE auto cot_invalid(const A0& x) BOOST_NOEXCEPT
      -> decltype(is_nez(x)&&is_flint(x*Ratio<A0,1,180>()))
      {
        return is_nez(x)&&is_flint(x/Constant<A0,180>());
      }
      static BOOST_FORCEINLINE auto tan_invalid(const A0& x) BOOST_NOEXCEPT
      -> decltype(is_flint((x- Ratio<A0,90>())/Constant<A0,180>()))
      {
        return is_flint((x- Ratio<A0,90>())*Ratio<A0,1,180>());
      }

      static BOOST_FORCEINLINE i_t reduce(const A0& x, A0& xr) BOOST_NOEXCEPT
      {
        A0 xi = round2even(x*Ratio<A0,1,90>());
        A0 x2 = x - xi * Ratio<A0,90>();

        xr =  inrad(x2);
        return bs::fast_(toint)(xi);
      }
    };
#endif

    template < class A0, class style>
    struct trig_reduction < A0, tag::pi_tag,  style, tag::big_tag>
    {
      using i_t = bd::as_integer_t<A0, signed>;

      static BOOST_FORCEINLINE auto cot_invalid(const A0& x) BOOST_NOEXCEPT
      -> decltype(is_nez(x)&&is_flint(x))
      {
        return is_nez(x)&&is_flint(x);
      }
      static BOOST_FORCEINLINE auto tan_invalid(const A0& x) BOOST_NOEXCEPT
      -> decltype(is_flint(x-Half<A0>()))
      {
        return is_flint(x-Half<A0>()) ;
      }

      static BOOST_FORCEINLINE i_t reduce(const A0& x,  A0& xr) BOOST_NOEXCEPT
      {
        A0 xi = round2even(x*Two<A0>());
        A0 x2 = x - xi * Half<A0>();
        xr = x2*Pi<A0>();
        return fast_(toint)(xi);
      }
    };
  }
} }


#endif
