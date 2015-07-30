/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#ifndef BRIGAND_INCLUDED
#define BRIGAND_INCLUDED

namespace brigand
{
  template <class A, template<class...> class B> struct apply_impl;

  template<template<class...> class A, class... T, template<class...> class B>
  struct apply_impl<A<T...>, B>
  {
    using type = B<T...>;
  };

  template<class A, template<class...> class B>
  using apply = typename apply_impl<A, B>::type;
}

namespace brigand
{
            struct no_such_type_ {};
}

namespace std
{
  template<class, class>
  struct pair;
}

namespace brigand
{
  template <typename... T>
  struct pair_wrapper
  {
    static_assert (sizeof...(T) == 2
                  , "as_pair requires a type list of exactly two types"
                  );

        using type = no_such_type_;
  };

  template <typename T, typename U>
  struct pair_wrapper<T,U>
  {
      using type = std::pair<T,U>;
  };

  template <typename L>
  using as_pair = apply<L, pair_wrapper>;
}


namespace std
{
  template<class...>
  class tuple;
}

namespace brigand
{
  template <typename... T>
  struct tuple_wrapper
  {
      using type = typename std::tuple<T...>;
  };

  template <typename L>
  using as_tuple = apply<L, tuple_wrapper>;
}


namespace boost
{

    template <typename... T>
    class variant;

}

namespace brigand
{

    template <typename... T>
    struct variant_wrapper
    {
        using type = typename boost::variant<T...>;
    };

    template <typename L>
    using as_variant = apply<L, variant_wrapper>;

}



#include <type_traits>

namespace brigand
{
  template <bool B>
  using bool_ = std::integral_constant<bool, B>;

  using true_ = bool_<true>;
  using false_ = bool_<false>;
}

namespace brigand { namespace detail
{
    template<typename T> using non_null = bool_< T::value != 0 >;
} }
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    template <bool...> struct bools_ {};
    template< typename Sequence, template<class> class Predicate, typename... Ts> struct all;

    template< template<class...> class Sequence, template<class> class Predicate, typename... Ts>
    struct  all<Sequence<Ts...>,Predicate>
          : std::is_same< bools_<true, Predicate<Ts>::value...>
                        , bools_<Predicate<Ts>::value..., true>
                        >
    {};
  }

    template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using all = typename detail::all<Sequence,Predicate>::type;
}


namespace brigand
{
  namespace detail
  {
    template< typename Sequence
            , template<class> class Predicate = detail::non_null
            >
    struct any : bool_<!all<Sequence,Predicate>::value> {};
  }

    template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using any = typename detail::any<Sequence,Predicate>::type;
}
#include <type_traits>

namespace brigand
{
  template<class... T>
  using count = std::integral_constant<std::size_t, sizeof...(T)>;
}



namespace brigand { namespace detail
{
    template< template<class> class Predicate, class Sequence>
  struct find_if_impl
  {
    using type = Sequence;
  };

    template<typename Status, template<class> class Predicate, class Sequence>
  struct find_if_shortcut;

    template< template<class> class Predicate
          , template<class...> class Sequence
          , typename H, typename... T
          >
  struct  find_if_impl<Predicate,Sequence<H,T...>>
        : find_if_shortcut<Predicate<H>, Predicate, Sequence<H,T...> >
  {};

    template<template<class> class Predicate, class Sequence>
  struct find_if_shortcut<true_,Predicate,Sequence>
  {
    using type = Sequence;
  };

    template< template<class> class Predicate
          , template<class...> class Sequence
          , typename H, typename... T
          >
  struct  find_if_shortcut<false_,Predicate, Sequence<H,T...>>
        : find_if_impl<Predicate,Sequence<T...>>
  {};
} }

#include <type_traits>
#include <cstddef>

namespace brigand
{
  template<char V>      using char_       = std::integral_constant<char     , V>;
  template<short V>     using short_      = std::integral_constant<short    , V>;
  template<int V>       using int_        = std::integral_constant<int      , V>;
  template<long V>      using long_       = std::integral_constant<long     , V>;
  template<long long V> using long_long_  = std::integral_constant<long long, V>;

  template<unsigned char V>      using uchar_       = std::integral_constant<unsigned char     , V>;
  template<unsigned short V>     using ushort_      = std::integral_constant<unsigned short    , V>;
  template<unsigned int V>       using uint_        = std::integral_constant<unsigned int      , V>;
  template<unsigned long V>      using ulong_       = std::integral_constant<unsigned long     , V>;
  template<unsigned long long V> using ulong_long_  = std::integral_constant<unsigned long long, V>;

  template<std::size_t V>     using size_t    = std::integral_constant<std::size_t, V>;
  template<std::ptrdiff_t V>  using ptrdiff_t = std::integral_constant<std::ptrdiff_t, V>;
}

namespace brigand
{
  template<class L>
  using size = apply<L, count>;
}


#include <type_traits>

namespace brigand
{
    template <class... T> struct list {};

    template<typename T, T... Values>
  using integral_list = brigand::list< std::integral_constant<T,Values>...>;

    using empty_list = brigand::list<>;
}

namespace brigand
{
  template <class... L> struct append_impl;

  template <class... L> using append = typename append_impl<L...>::type;

  template <> struct append_impl<>
  {
    using type = brigand::empty_list;
  };

  template<template<class...> class L, class... T>
  struct append_impl<L<T...>>
  {
    using type = L<T...>;
  };

  template<template<class...> class L1, class... T1, template<class...> class L2, class... T2, class... Lr>
  struct append_impl<L1<T1...>, L2<T2...>, Lr...>
  {
    using type = append<L1<T1..., T2...>, Lr...>;
  };
}

namespace brigand
{
namespace detail
{

    template <template <class...> class L, class First, class... R>
    struct reverse_elements
    {
        using head = L<First>;
        using tail = typename reverse_elements<L, R...>::type;
        using type = typename brigand::append<tail, head>;
    };

    template <template <class...> class L, class T0>
    struct reverse_elements<L, T0>
    {
        using type = L<T0>;
    };

        template <template <class...> class L, class T0, class T1>
    struct reverse_elements<L, T0, T1>
    {
        using type = L<T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2>
    struct reverse_elements<L, T0, T1, T2>
    {
        using type = L<T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3>
    struct reverse_elements<L, T0, T1, T2, T3>
    {
        using type = L<T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4>
    struct reverse_elements<L, T0, T1, T2, T3, T4>
    {
        using type = L<T4, T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4, class T5>
    struct reverse_elements<L, T0, T1, T2, T3, T4, T5>
    {
        using type = L<T5, T4, T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4, class T5, class T6>
    struct reverse_elements<L, T0, T1, T2, T3, T4, T5, T6>
    {
        using type = L<T6, T5, T4, T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    struct reverse_elements<L, T0, T1, T2, T3, T4, T5, T6, T7>
    {
        using type = L<T7, T6, T5, T4, T3, T2, T1, T0>;
    };

    template <class L, class Count = brigand::size<L>> struct reverse_impl;

    template<template<class...> class L, class... U, class Count>
    struct reverse_impl<L<U...>,Count>
    {
        using type = typename reverse_elements<L, U...>::type;
    };

    template<template<class...> class L, class... U>
    struct reverse_impl<L<U...>, brigand::size_t<0>>
    {
        using type = L<U...>;
    };

}

    template <typename L>
    using reverse = typename detail::reverse_impl<L>::type;
}

namespace brigand
{
    template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using find = typename detail::find_if_impl<Predicate, Sequence>::type;

    template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using reverse_find = reverse< find< reverse<Sequence>, Predicate> >;

    template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using not_found = typename std::is_same<find<Sequence,Predicate>,empty_list>::type;

      template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using found = bool_<!std::is_same<find<Sequence,Predicate>,empty_list>::value>;
}


namespace brigand { namespace detail
{
    template<template<class,class> class Functor, class State, class Sequence>
  struct fold_impl
  {
    using type = State;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence, typename T
          >
  struct fold_impl<Functor, State, Sequence<T>>
  {
    using type = Functor<State,T>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1
          >
  struct fold_impl<Functor, State, Sequence<T0,T1>>
  {
    using state0 = Functor<State,T0>;
    using type   = Functor<state0, T1>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using type   = Functor<state1, T2>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2, typename T3
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using type   = Functor<state2, T3>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2, typename T3, typename T4
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using type   = Functor<state3, T4>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          , typename T3, typename T4, typename T5
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using type   = Functor<state4, T5>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          , typename T3, typename T4, typename T5
          , typename T6
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5,T6>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using state5 = Functor<state4, T5>;
    using type   = Functor<state5, T6>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          , typename T3, typename T4, typename T5
          , typename T6, typename T7
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5,T6,T7>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using state5 = Functor<state4, T5>;
    using state6 = Functor<state5, T6>;
    using type   = Functor<state6, T7>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2, typename T3
          , typename T4, typename T5, typename T6, typename T7
          , class... T
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5,T6,T7,T...>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using state5 = Functor<state4, T5>;
    using state6 = Functor<state5, T6>;
    using state7 = Functor<state6, T7>;
    using type = typename fold_impl<Functor,state7, Sequence<T...>>::type;
  };
} }

namespace brigand
{
    template<template<class,class> class Functor, class State, class Sequence>
  using fold = typename detail::fold_impl<Functor, State, Sequence>::type;
}

#include <initializer_list>
#include <functional>

namespace brigand
{
  template<class F, class...Ts> F for_each_args(F f, Ts&&...a)
  {
    return (void)std::initializer_list<int>{((void)std::ref(f)(static_cast<Ts&&>(a)),0)...}, f;
  }
}

namespace brigand
{
  template<typename T> struct type_ { using type = T; };

  template<typename T> using type_from = typename T::type;
}

namespace brigand
{
  namespace detail
  {
    template<template<class...> class List, typename... Elements, typename Functor>
    Functor for_each_impl( List<Elements...>&&, Functor f )
    {
      return for_each_args( f, type_<Elements>()... );
    }
  }

  template<typename List, typename Functor> Functor for_each( Functor f )
  {
    return detail::for_each_impl( List{}, f );
  }
}


#include <type_traits>

namespace brigand
{
  template <typename A>
  using next = std::integral_constant<typename A::value_type, A::value+1>;
}

namespace brigand
{
namespace detail
{
  template<class Start, unsigned N, template<class> class Next, class List, bool = (N > 8)>
  struct make_sequence_impl;

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 0, Next, List<E...>, false>
  {
    using type = List<E...>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 1, Next, List<E...>, false>
  {
    using type = List<E..., Start>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 2, Next, List<E...>, false>
  {
    using type = List<E..., Start, Next<Start>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 3, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using type = List<E..., Start, t1, Next<t1>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 4, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using type = List<E..., Start, t1, t2, Next<t2>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 5, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using type = List<E..., Start, t1, t2, t3, Next<t3>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 6, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using type = List<E..., Start, t1, t2, t3, t4, Next<t4>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 7, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using t5 = Next<t4>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, Next<t5>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 8, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using t5 = Next<t4>;
    using t6 = Next<t5>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, Next<t6>>;
  };

  template<class Start, unsigned N, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, N, Next, List<E...>, true>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using t5 = Next<t4>;
    using t6 = Next<t5>;
    using t7 = Next<t6>;
    using type = typename make_sequence_impl<Next<t7>, N-8, Next, List<E..., Start, t1, t2, t3, t4, t5, t6, t7>>::type;
  };
}

  template<class Start, unsigned N, template<class> class Next = next, template<class...> class List = list>
  using make_sequence = typename detail::make_sequence_impl<Start, N, Next, List<>>::type;
}

namespace brigand
{
namespace detail
{
  template<class Ints, class...T>
  struct is_set_impl
  {
    template<class U>
    static std::true_type is_set(U);

    static std::true_type is_set();
  };

  template<class, class T>
  struct unique_x_t
  { operator type_<T> (); };

  template<class... T>
  struct unique_set : T... {};

  template<class Int, class... Ints, class L, class... R>
  struct is_set_impl<list<Int, Ints...>, L, R...>
  {
    template<class U, class = decltype(static_cast<type_<U>>(unique_set<unique_x_t<Int, L>, unique_x_t<Ints, R>...>()))>
    static std::false_type is_set(type_<U>);

    template<class U>
    static decltype(is_set_impl<list<Ints...>, R...>::is_set(type_<L>()))
    is_set(U);

    static decltype(is_set_impl<list<Ints...>, R...>::is_set(type_<L>()))
    is_set();
  };
}

  template <class... T>
  using is_set = decltype(detail::is_set_impl<make_sequence<uint_<0>, sizeof...(T)>, T...>::is_set());
}


namespace brigand
{
  namespace detail
  {
    template<typename Sequence, template<class> class Predicate> struct none
    {
      template<typename T> struct nope : bool_< !Predicate<T>::value > {};
      using type = all<Sequence, nope>;
    };
  }

    template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using none = typename detail::none<Sequence,Predicate>::type;
}

namespace brigand
{
  namespace detail
  {
    template< template<class...> class Functor, class... Sequence>
    struct transform_impl;

        template< template<class> class Functor
            , template<class...> class Sequence, class... T
            >
    struct transform_impl<Functor, Sequence<T...>>
    {
      using type = Sequence< Functor<T>... >;
    };

        template< template<class,class> class Functor
            , template<class...> class Sequence1, class... T1
            , template<class...> class Sequence2, class... T2
            >
    struct transform_impl<Functor, Sequence1<T1...>, Sequence2<T2...>>
    {
      static_assert ( sizeof...(T1) == sizeof...(T2)
                    , "The arguments of transform should be of the same size"
                    );

      using type = Sequence1< Functor<T1,T2>... >;
    };
  }

    template<template<class...> class Functor, class... Sequence >
  using transform = typename detail::transform_impl<Functor, Sequence...>::type;
}


#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using plus = std::integral_constant<typename A::value_type, A::value + B::value>;
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using minus = std::integral_constant<typename A::value_type, A::value - B::value>;
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using times = std::integral_constant<typename A::value_type, A::value * B::value>;
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using divides = std::integral_constant<typename A::value_type, A::value / B::value>;
}

namespace brigand
{
  template<class T>
  using identity = T;
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using max = std::integral_constant< typename A::value_type
                                    , (A::value < B::value) ? B::value : A::value
                                    >;
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using min = std::integral_constant< typename A::value_type
                                    , (A::value < B::value) ? A::value : B::value
                                    >;
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using modulo = std::integral_constant<typename A::value_type, A::value % B::value>;
}
#include <type_traits>

namespace brigand
{
  template <typename A>
  using prev = std::integral_constant<typename A::value_type, A::value-1>;
}
#include <type_traits>

namespace brigand
{
  template <typename A>
  using negate = std::integral_constant<typename A::value_type, -A::value>;
}
#include <type_traits>

namespace brigand
{
  template <typename A>
  using complement = std::integral_constant < typename A::value_type
                                            , typename A::value_type(~A::value)
                                            >;
}


namespace brigand
{
  template <typename A, typename B>
  using less = bool_<(A::value < B::value)>;
}

namespace brigand
{
  template <typename A, typename B>
  using less_equal = bool_<(A::value <= B::value)>;
}

namespace brigand
{
  template <typename A, typename B>
  using greater = bool_<(A::value > B::value)>;
}

namespace brigand
{
  template <typename A, typename B>
  using greater_equal = bool_<(A::value >= B::value)>;
}

namespace brigand
{
  template <typename A, typename B>
  using equal_to = bool_<(A::value == B::value)>;
}

namespace brigand
{
  template <typename A, typename B>
  using not_equal_to = bool_<(A::value != B::value)>;
}

#include <type_traits>

namespace brigand
{
  template <typename T>
  using not_ = std::integral_constant<typename T::value_type, !T::value>;
}

#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using and_ = std::integral_constant<typename A::value_type, A::value && B::value>;
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using xor_ = std::integral_constant < typename A::value_type
                                      , A::value != B::value
                                      >;
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using or_ = std::integral_constant<typename A::value_type, A::value || B::value>;
}

#include <type_traits>

namespace brigand
{
    template <typename First, typename Second>
    struct pair
    {
        using first_type = First;
        using second_type = Second;
    };

}

namespace brigand
{
namespace detail
{
    template <class... T>
    struct map_impl;

    template <>
    struct map_impl<>
    {
        template <typename U>
        static no_such_type_ at(U);
    };

        template <class T0>
    struct map_impl<T0>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1>
    struct map_impl<T0, T1>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2>
    struct map_impl<T0, T1, T2>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3>
    struct map_impl<T0, T1, T2, T3>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4>
    struct map_impl<T0, T1, T2, T3, T4>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5>
    struct map_impl<T0, T1, T2, T3, T4, T5>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
    struct map_impl<T0, T1, T2, T3, T4, T5, T6>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);
        static typename T6::second_type at(type_<typename T6::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    struct map_impl<T0, T1, T2, T3, T4, T5, T6, T7>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);
        static typename T6::second_type at(type_<typename T6::first_type>);
        static typename T7::second_type at(type_<typename T7::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };


    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class... T>
    struct map_impl<T0, T1, T2, T3, T4, T5, T6, T7, T...>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);
        static typename T6::second_type at(type_<typename T6::first_type>);
        static typename T7::second_type at(type_<typename T7::first_type>);

        template <typename U>
        static decltype(map_impl<T...>::at(U{})) at(U);
    };

            template<class... Ts>
    struct make_map : type_<typename Ts::first_type>... {
      using type = map_impl<Ts...>;
    };
}
    template<class... Ts>
    using map = typename detail::make_map<Ts...>::type;

    template <typename M, typename K>
    using lookup = decltype(M::at(type_<K>{}));
}

namespace brigand
{
namespace detail
{
        template <int Index, class First, class... T>
    struct element_at
    {
        using type = typename element_at<Index - 1, T...>::type;
    };

    template <class First, class... T>
    struct element_at<0, First, T...>
    {
        using type = First;
    };

    template <int Index, class L> struct at_impl;

    template<int Index, template<class...> class L, class... U>
    struct at_impl<Index, L<U...>>
    {
        using type = typename element_at<Index, U...>::type;
    };
}

    template <class L, int Index>
    using at_c = typename detail::at_impl<Index, L>::type;

namespace detail
{
    template <typename T>
    struct has_at_method
    {
        struct dummy {};
        template <typename C, typename P>
        static auto test(P * p) -> decltype(C::at(*p), std::true_type());

        template <typename, typename>
        static std::false_type test(...);

        static const bool value = std::is_same<std::true_type, decltype(test<T, dummy>(nullptr))>::value;
    };

    template <class L, typename Index, bool>
    struct at_dispatch
    {
        using type = at_c<L, Index::value>;
    };

    template <class L, typename Index>
    struct at_dispatch<L, Index, true>
    {
        using type = lookup<L, Index>;
    };
}

    template <class Seq, typename K>
    using at = typename detail::at_dispatch<Seq, K, detail::has_at_method<Seq>::value>::type;
}



namespace brigand { namespace detail
{
  template <template <class...> class L, class First, class... R>
  struct without_last_element
  {
    using type = append<L<First>, typename without_last_element<L, R...>::type>;
  };

  template <template <class...> class L, class Last>
  struct without_last_element<L, Last>
  {
    using type = empty_list;
  };

    template <class... R> struct last_element;

  template <class T0>
  struct last_element<T0>
  {
    using type = T0;
  };

  template <class T0,class T1>
  struct last_element<T0,T1>
  {
    using type = T1;
  };

  template <class T0,class T1,class T2>
  struct last_element<T0,T1,T2>
  {
    using type = T2;
  };

  template <class T0,class T1,class T2,class T3>
  struct last_element<T0,T1,T2,T3>
  {
    using type = T3;
  };

  template <class T0,class T1,class T2,class T3,class T4>
  struct last_element<T0,T1,T2,T3,T4>
  {
    using type = T4;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5>
  struct last_element<T0,T1,T2,T3,T4,T5>
  {
    using type = T5;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5,class T6>
  struct last_element<T0,T1,T2,T3,T4,T5,T6>
  {
    using type = T6;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5,class T6,class T7>
  struct last_element<T0,T1,T2,T3,T4,T5,T6,T7>
  {
    using type = T7;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5,class T6,class T7,class... R>
  struct last_element<T0,T1,T2,T3,T4,T5,T6,T7,R...>
  {
    using type = typename last_element<R...>::type;
  };
} }

namespace brigand
{
    namespace detail
  {
    template<class L, class... T> struct push_back_impl;

    template<template<class...> class L, class... U, class... T>
    struct push_back_impl<L<U...>, T...>
    {
        using type = L<U..., T...>;
    };
  }

  template<class L, class... T>
  using push_back = typename detail::push_back_impl<L, T...>::type;

    namespace detail
  {
    template<class L> struct back_impl;

    template<template<class...> class L, class... U>
    struct back_impl<L<U...>>
    {
      using type = typename last_element<U...>::type;
    };

  }

  template <class L>
  using back = typename detail::back_impl<L>::type;

    namespace detail
  {
    template <class L> struct pop_back_impl;

    template<template<class...> class L, class... U>
    struct pop_back_impl<L<U...>>
    {
        using type = typename without_last_element<L, U...>::type;
    };
  }

  template <class L>
  using pop_back = typename detail::pop_back_impl<L>::type;
}

namespace brigand
{
    template<class L, class... T> struct push_front_impl;

  template<template<class...> class L, class... U, class... T>
  struct push_front_impl<L<U...>, T...>
  {
      using type = L<T..., U...>;
  };

  template<class L, class... T>
  using push_front = typename push_front_impl<L, T...>::type;

    template <class First, class...>
  struct first_element
  {
      using type = First;
  };

  template<class L> struct front_impl;

  template<template<class...> class L, class... U>
  struct front_impl<L<U...>>
  {
      using type = typename first_element<U...>::type;
  };

  template <class L>
  using front = typename front_impl<L>::type;

    template <template <class...> class L, class First, class... R>
  struct without_first_element
  {
      using type = L<R...>;
  };

  template <class L> struct pop_front_impl;

  template<template<class...> class L, class... U>
  struct pop_front_impl<L<U...>>
  {
      using type = typename without_first_element<L, U...>::type;
  };

  template <class L>
  using pop_front = typename pop_front_impl<L>::type;
}
#include <type_traits>

namespace brigand
{
namespace detail
{
    template<class... Ts>
    struct make_set;

    template <class... T>
    struct set_impl
    {
        template <typename U, typename = decltype(static_cast<type_<U>>(make_set<T...>()))>
        static true_ contains(type_<U>);

        template <typename U>
        static false_ contains(U);
    };

            template<class... Ts>
    struct make_set : type_<Ts>...
    {
      using type = set_impl<Ts...>;
    };
}
    template<class... Ts>
    using set = typename detail::make_set<Ts...>::type;

    template <typename M, typename K>
    using contains = decltype(M::contains(type_<K>{}));
}

#endif
