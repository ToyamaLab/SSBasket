/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
    template <
        template <typename> class Actor
      , typename Tag
      , typename A0 = void , typename A1 = void , typename A2 = void , typename A3 = void , typename A4 = void , typename A5 = void , typename A6 = void , typename A7 = void , typename A8 = void , typename A9 = void , typename A10 = void , typename A11 = void , typename A12 = void , typename A13 = void , typename A14 = void , typename A15 = void , typename A16 = void , typename A17 = void , typename A18 = void , typename A19 = void , typename A20 = void , typename A21 = void , typename A22 = void , typename A23 = void , typename A24 = void , typename A25 = void , typename A26 = void , typename A27 = void , typename A28 = void , typename A29 = void
      , typename Dummy = void>
    struct expr_ext;
    template <
        typename Tag
      , typename A0 = void , typename A1 = void , typename A2 = void , typename A3 = void , typename A4 = void , typename A5 = void , typename A6 = void , typename A7 = void , typename A8 = void , typename A9 = void , typename A10 = void , typename A11 = void , typename A12 = void , typename A13 = void , typename A14 = void , typename A15 = void , typename A16 = void , typename A17 = void , typename A18 = void , typename A19 = void , typename A20 = void , typename A21 = void , typename A22 = void , typename A23 = void , typename A24 = void , typename A25 = void , typename A26 = void , typename A27 = void , typename A28 = void , typename A29 = void
      , typename Dummy = void
    >
    struct expr : expr_ext<actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29> {};
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0>
    struct expr_ext<Actor, Tag, A0>
        : proto::transform<expr_ext<Actor, Tag, A0>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1>
    struct expr_ext<Actor, Tag, A0 , A1>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2>
    struct expr_ext<Actor, Tag, A0 , A1 , A2>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A21>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type , typename proto::detail::uncvref<A21>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20 , typename call_traits<A21>::param_type a21)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20 , typename boost::add_reference<typename boost::add_const<A21>::type>::type a21)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20; typedef A21 proto_child21;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A21>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A22>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type , typename proto::detail::uncvref<A21>::type , typename proto::detail::uncvref<A22>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20 , typename call_traits<A21>::param_type a21 , typename call_traits<A22>::param_type a22)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20 , typename boost::add_reference<typename boost::add_const<A21>::type>::type a21 , typename boost::add_reference<typename boost::add_const<A22>::type>::type a22)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20; typedef A21 proto_child21; typedef A22 proto_child22;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A21>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A22>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A23>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type , typename proto::detail::uncvref<A21>::type , typename proto::detail::uncvref<A22>::type , typename proto::detail::uncvref<A23>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20 , typename call_traits<A21>::param_type a21 , typename call_traits<A22>::param_type a22 , typename call_traits<A23>::param_type a23)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20 , typename boost::add_reference<typename boost::add_const<A21>::type>::type a21 , typename boost::add_reference<typename boost::add_const<A22>::type>::type a22 , typename boost::add_reference<typename boost::add_const<A23>::type>::type a23)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20; typedef A21 proto_child21; typedef A22 proto_child22; typedef A23 proto_child23;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A21>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A22>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A23>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A24>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type , typename proto::detail::uncvref<A21>::type , typename proto::detail::uncvref<A22>::type , typename proto::detail::uncvref<A23>::type , typename proto::detail::uncvref<A24>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20 , typename call_traits<A21>::param_type a21 , typename call_traits<A22>::param_type a22 , typename call_traits<A23>::param_type a23 , typename call_traits<A24>::param_type a24)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20 , typename boost::add_reference<typename boost::add_const<A21>::type>::type a21 , typename boost::add_reference<typename boost::add_const<A22>::type>::type a22 , typename boost::add_reference<typename boost::add_const<A23>::type>::type a23 , typename boost::add_reference<typename boost::add_const<A24>::type>::type a24)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20; typedef A21 proto_child21; typedef A22 proto_child22; typedef A23 proto_child23; typedef A24 proto_child24;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A21>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A22>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A23>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A24>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A25>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type , typename proto::detail::uncvref<A21>::type , typename proto::detail::uncvref<A22>::type , typename proto::detail::uncvref<A23>::type , typename proto::detail::uncvref<A24>::type , typename proto::detail::uncvref<A25>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20 , typename call_traits<A21>::param_type a21 , typename call_traits<A22>::param_type a22 , typename call_traits<A23>::param_type a23 , typename call_traits<A24>::param_type a24 , typename call_traits<A25>::param_type a25)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20 , typename boost::add_reference<typename boost::add_const<A21>::type>::type a21 , typename boost::add_reference<typename boost::add_const<A22>::type>::type a22 , typename boost::add_reference<typename boost::add_const<A23>::type>::type a23 , typename boost::add_reference<typename boost::add_const<A24>::type>::type a24 , typename boost::add_reference<typename boost::add_const<A25>::type>::type a25)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20; typedef A21 proto_child21; typedef A22 proto_child22; typedef A23 proto_child23; typedef A24 proto_child24; typedef A25 proto_child25;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A21>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A22>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A23>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A24>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A25>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A26>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type , typename proto::detail::uncvref<A21>::type , typename proto::detail::uncvref<A22>::type , typename proto::detail::uncvref<A23>::type , typename proto::detail::uncvref<A24>::type , typename proto::detail::uncvref<A25>::type , typename proto::detail::uncvref<A26>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20 , typename call_traits<A21>::param_type a21 , typename call_traits<A22>::param_type a22 , typename call_traits<A23>::param_type a23 , typename call_traits<A24>::param_type a24 , typename call_traits<A25>::param_type a25 , typename call_traits<A26>::param_type a26)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20 , typename boost::add_reference<typename boost::add_const<A21>::type>::type a21 , typename boost::add_reference<typename boost::add_const<A22>::type>::type a22 , typename boost::add_reference<typename boost::add_const<A23>::type>::type a23 , typename boost::add_reference<typename boost::add_const<A24>::type>::type a24 , typename boost::add_reference<typename boost::add_const<A25>::type>::type a25 , typename boost::add_reference<typename boost::add_const<A26>::type>::type a26)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20; typedef A21 proto_child21; typedef A22 proto_child22; typedef A23 proto_child23; typedef A24 proto_child24; typedef A25 proto_child25; typedef A26 proto_child26;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A21>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A22>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A23>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A24>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A25>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A26>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A27>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type , typename proto::detail::uncvref<A21>::type , typename proto::detail::uncvref<A22>::type , typename proto::detail::uncvref<A23>::type , typename proto::detail::uncvref<A24>::type , typename proto::detail::uncvref<A25>::type , typename proto::detail::uncvref<A26>::type , typename proto::detail::uncvref<A27>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20 , typename call_traits<A21>::param_type a21 , typename call_traits<A22>::param_type a22 , typename call_traits<A23>::param_type a23 , typename call_traits<A24>::param_type a24 , typename call_traits<A25>::param_type a25 , typename call_traits<A26>::param_type a26 , typename call_traits<A27>::param_type a27)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20 , typename boost::add_reference<typename boost::add_const<A21>::type>::type a21 , typename boost::add_reference<typename boost::add_const<A22>::type>::type a22 , typename boost::add_reference<typename boost::add_const<A23>::type>::type a23 , typename boost::add_reference<typename boost::add_const<A24>::type>::type a24 , typename boost::add_reference<typename boost::add_const<A25>::type>::type a25 , typename boost::add_reference<typename boost::add_const<A26>::type>::type a26 , typename boost::add_reference<typename boost::add_const<A27>::type>::type a27)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20; typedef A21 proto_child21; typedef A22 proto_child22; typedef A23 proto_child23; typedef A24 proto_child24; typedef A25 proto_child25; typedef A26 proto_child26; typedef A27 proto_child27;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A21>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A22>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A23>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A24>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A25>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A26>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A27>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A28>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type , typename proto::detail::uncvref<A21>::type , typename proto::detail::uncvref<A22>::type , typename proto::detail::uncvref<A23>::type , typename proto::detail::uncvref<A24>::type , typename proto::detail::uncvref<A25>::type , typename proto::detail::uncvref<A26>::type , typename proto::detail::uncvref<A27>::type , typename proto::detail::uncvref<A28>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20 , typename call_traits<A21>::param_type a21 , typename call_traits<A22>::param_type a22 , typename call_traits<A23>::param_type a23 , typename call_traits<A24>::param_type a24 , typename call_traits<A25>::param_type a25 , typename call_traits<A26>::param_type a26 , typename call_traits<A27>::param_type a27 , typename call_traits<A28>::param_type a28)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20 , typename boost::add_reference<typename boost::add_const<A21>::type>::type a21 , typename boost::add_reference<typename boost::add_const<A22>::type>::type a22 , typename boost::add_reference<typename boost::add_const<A23>::type>::type a23 , typename boost::add_reference<typename boost::add_const<A24>::type>::type a24 , typename boost::add_reference<typename boost::add_const<A25>::type>::type a25 , typename boost::add_reference<typename boost::add_const<A26>::type>::type a26 , typename boost::add_reference<typename boost::add_const<A27>::type>::type a27 , typename boost::add_reference<typename boost::add_const<A28>::type>::type a28)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20; typedef A21 proto_child21; typedef A22 proto_child22; typedef A23 proto_child23; typedef A24 proto_child24; typedef A25 proto_child25; typedef A26 proto_child26; typedef A27 proto_child27; typedef A28 proto_child28;
    };
    
    
    
    
    
    
    
    template <template <typename> class Actor, typename Tag, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29>
    struct expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29>
        : proto::transform<expr_ext<Actor, Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain 
<<<<<<< HEAD
              , typename proto::detail::uncvref<typename call_traits<A0>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A1>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A2>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A3>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A4>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A5>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A6>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A7>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A8>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A9>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A10>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A11>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A12>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A13>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A14>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A15>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A16>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A17>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A18>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A19>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A20>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A21>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A22>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A23>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A24>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A25>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A26>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A27>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A28>::value_type>::type , typename proto::detail::uncvref<typename call_traits<A29>::value_type>::type
=======
              , typename proto::detail::uncvref<A0>::type , typename proto::detail::uncvref<A1>::type , typename proto::detail::uncvref<A2>::type , typename proto::detail::uncvref<A3>::type , typename proto::detail::uncvref<A4>::type , typename proto::detail::uncvref<A5>::type , typename proto::detail::uncvref<A6>::type , typename proto::detail::uncvref<A7>::type , typename proto::detail::uncvref<A8>::type , typename proto::detail::uncvref<A9>::type , typename proto::detail::uncvref<A10>::type , typename proto::detail::uncvref<A11>::type , typename proto::detail::uncvref<A12>::type , typename proto::detail::uncvref<A13>::type , typename proto::detail::uncvref<A14>::type , typename proto::detail::uncvref<A15>::type , typename proto::detail::uncvref<A16>::type , typename proto::detail::uncvref<A17>::type , typename proto::detail::uncvref<A18>::type , typename proto::detail::uncvref<A19>::type , typename proto::detail::uncvref<A20>::type , typename proto::detail::uncvref<A21>::type , typename proto::detail::uncvref<A22>::type , typename proto::detail::uncvref<A23>::type , typename proto::detail::uncvref<A24>::type , typename proto::detail::uncvref<A25>::type , typename proto::detail::uncvref<A26>::type , typename proto::detail::uncvref<A27>::type , typename proto::detail::uncvref<A28>::type , typename proto::detail::uncvref<A29>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type
            base_type;
        typedef Actor<base_type> type;
        typedef
            typename proto::nary_expr<Tag, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29>::proto_grammar
            proto_grammar;
<<<<<<< HEAD
        static type make(typename call_traits<A0>::param_type a0 , typename call_traits<A1>::param_type a1 , typename call_traits<A2>::param_type a2 , typename call_traits<A3>::param_type a3 , typename call_traits<A4>::param_type a4 , typename call_traits<A5>::param_type a5 , typename call_traits<A6>::param_type a6 , typename call_traits<A7>::param_type a7 , typename call_traits<A8>::param_type a8 , typename call_traits<A9>::param_type a9 , typename call_traits<A10>::param_type a10 , typename call_traits<A11>::param_type a11 , typename call_traits<A12>::param_type a12 , typename call_traits<A13>::param_type a13 , typename call_traits<A14>::param_type a14 , typename call_traits<A15>::param_type a15 , typename call_traits<A16>::param_type a16 , typename call_traits<A17>::param_type a17 , typename call_traits<A18>::param_type a18 , typename call_traits<A19>::param_type a19 , typename call_traits<A20>::param_type a20 , typename call_traits<A21>::param_type a21 , typename call_traits<A22>::param_type a22 , typename call_traits<A23>::param_type a23 , typename call_traits<A24>::param_type a24 , typename call_traits<A25>::param_type a25 , typename call_traits<A26>::param_type a26 , typename call_traits<A27>::param_type a27 , typename call_traits<A28>::param_type a28 , typename call_traits<A29>::param_type a29)
=======
        static type make(typename boost::add_reference<typename boost::add_const<A0>::type>::type a0 , typename boost::add_reference<typename boost::add_const<A1>::type>::type a1 , typename boost::add_reference<typename boost::add_const<A2>::type>::type a2 , typename boost::add_reference<typename boost::add_const<A3>::type>::type a3 , typename boost::add_reference<typename boost::add_const<A4>::type>::type a4 , typename boost::add_reference<typename boost::add_const<A5>::type>::type a5 , typename boost::add_reference<typename boost::add_const<A6>::type>::type a6 , typename boost::add_reference<typename boost::add_const<A7>::type>::type a7 , typename boost::add_reference<typename boost::add_const<A8>::type>::type a8 , typename boost::add_reference<typename boost::add_const<A9>::type>::type a9 , typename boost::add_reference<typename boost::add_const<A10>::type>::type a10 , typename boost::add_reference<typename boost::add_const<A11>::type>::type a11 , typename boost::add_reference<typename boost::add_const<A12>::type>::type a12 , typename boost::add_reference<typename boost::add_const<A13>::type>::type a13 , typename boost::add_reference<typename boost::add_const<A14>::type>::type a14 , typename boost::add_reference<typename boost::add_const<A15>::type>::type a15 , typename boost::add_reference<typename boost::add_const<A16>::type>::type a16 , typename boost::add_reference<typename boost::add_const<A17>::type>::type a17 , typename boost::add_reference<typename boost::add_const<A18>::type>::type a18 , typename boost::add_reference<typename boost::add_const<A19>::type>::type a19 , typename boost::add_reference<typename boost::add_const<A20>::type>::type a20 , typename boost::add_reference<typename boost::add_const<A21>::type>::type a21 , typename boost::add_reference<typename boost::add_const<A22>::type>::type a22 , typename boost::add_reference<typename boost::add_const<A23>::type>::type a23 , typename boost::add_reference<typename boost::add_const<A24>::type>::type a24 , typename boost::add_reference<typename boost::add_const<A25>::type>::type a25 , typename boost::add_reference<typename boost::add_const<A26>::type>::type a26 , typename boost::add_reference<typename boost::add_const<A27>::type>::type a27 , typename boost::add_reference<typename boost::add_const<A28>::type>::type a28 , typename boost::add_reference<typename boost::add_const<A29>::type>::type a29)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      { 
        
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain 
                    >(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28 , a29)
                };
            return e;
        }
        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        typedef Tag proto_tag;
        typedef A0 proto_child0; typedef A1 proto_child1; typedef A2 proto_child2; typedef A3 proto_child3; typedef A4 proto_child4; typedef A5 proto_child5; typedef A6 proto_child6; typedef A7 proto_child7; typedef A8 proto_child8; typedef A9 proto_child9; typedef A10 proto_child10; typedef A11 proto_child11; typedef A12 proto_child12; typedef A13 proto_child13; typedef A14 proto_child14; typedef A15 proto_child15; typedef A16 proto_child16; typedef A17 proto_child17; typedef A18 proto_child18; typedef A19 proto_child19; typedef A20 proto_child20; typedef A21 proto_child21; typedef A22 proto_child22; typedef A23 proto_child23; typedef A24 proto_child24; typedef A25 proto_child25; typedef A26 proto_child26; typedef A27 proto_child27; typedef A28 proto_child28; typedef A29 proto_child29;
    };
