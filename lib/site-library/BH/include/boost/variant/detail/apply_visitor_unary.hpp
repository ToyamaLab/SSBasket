//-----------------------------------------------------------------------------
// boost variant/detail/apply_visitor_unary.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003 Eric Friedman
<<<<<<< HEAD
// Copyright (c) 2014 Antony Polukhin
=======
// Copyright (c) 2014-2019 Antony Polukhin
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_VARIANT_DETAIL_APPLY_VISITOR_UNARY_HPP
#define BOOST_VARIANT_DETAIL_APPLY_VISITOR_UNARY_HPP

#include <boost/config.hpp>
<<<<<<< HEAD
#include <boost/detail/workaround.hpp>
#include <boost/variant/detail/generic_result_type.hpp>
#include <boost/move/utility.hpp>

#if BOOST_WORKAROUND(__EDG__, BOOST_TESTED_AT(302))
#include <boost/core/enable_if.hpp>
#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

=======
#include <boost/move/utility.hpp>

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#if !defined(BOOST_NO_CXX14_DECLTYPE_AUTO) && !defined(BOOST_NO_CXX11_DECLTYPE_N3276)
#   include <boost/mpl/distance.hpp>
#   include <boost/mpl/advance.hpp>
#   include <boost/mpl/deref.hpp>
#   include <boost/mpl/size.hpp>
#   include <boost/utility/declval.hpp>
#   include <boost/core/enable_if.hpp>
<<<<<<< HEAD
=======
#   include <boost/type_traits/copy_cv_ref.hpp>
#   include <boost/type_traits/remove_reference.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#   include <boost/variant/detail/has_result_type.hpp>
#endif

namespace boost {

//////////////////////////////////////////////////////////////////////////
// function template apply_visitor(visitor, visitable)
//
// Visits visitable with visitor.
//

//
// nonconst-visitor version:
//

<<<<<<< HEAD
#if !BOOST_WORKAROUND(__EDG__, BOOST_TESTED_AT(302))

#   define BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(V) \
    BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename V::result_type) \
    /**/

#else // EDG-based compilers

#   define BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(V) \
    typename enable_if< \
          mpl::not_< is_const< V > > \
        , BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename V::result_type) \
        >::type \
    /**/

#endif // EDG-based compilers workaround

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
template <typename Visitor, typename Visitable>
inline
    BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(Visitor)
=======
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
template <typename Visitor, typename Visitable>
inline typename Visitor::result_type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
apply_visitor(Visitor& visitor, Visitable&& visitable)
{
    return ::boost::forward<Visitable>(visitable).apply_visitor(visitor);
}
#else
template <typename Visitor, typename Visitable>
<<<<<<< HEAD
inline
    BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(Visitor)
=======
inline typename Visitor::result_type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
apply_visitor(Visitor& visitor, Visitable& visitable)
{
    return visitable.apply_visitor(visitor);
}
#endif

<<<<<<< HEAD
#undef BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
//
// const-visitor version:
//

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
template <typename Visitor, typename Visitable>
<<<<<<< HEAD
inline
    BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
=======
inline typename Visitor::result_type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
apply_visitor(const Visitor& visitor, Visitable&& visitable)
{
    return ::boost::forward<Visitable>(visitable).apply_visitor(visitor);
}
#else
template <typename Visitor, typename Visitable>
<<<<<<< HEAD
inline
    BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
=======
inline typename Visitor::result_type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
apply_visitor(const Visitor& visitor, Visitable& visitable)
{
    return visitable.apply_visitor(visitor);
}
#endif


#if !defined(BOOST_NO_CXX14_DECLTYPE_AUTO) && !defined(BOOST_NO_CXX11_DECLTYPE_N3276)
<<<<<<< HEAD
=======
#define BOOST_VARIANT_HAS_DECLTYPE_APPLY_VISITOR_RETURN_TYPE
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// C++14
namespace detail { namespace variant {

// This class serves only metaprogramming purposes. none of its methods must be called at runtime!
template <class Visitor, class Variant>
struct result_multideduce1 {
<<<<<<< HEAD
    typedef typename Variant::types                 types;
=======
    typedef typename remove_reference<Variant>::type::types types;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    typedef typename boost::mpl::begin<types>::type begin_it;
    typedef typename boost::mpl::advance<
        begin_it, boost::mpl::int_<boost::mpl::size<types>::type::value - 1>
    >::type                                         last_it;

<<<<<<< HEAD
    // For metaprogramming purposes ONLY! Do not use this method (and class) at runtime!
    static Visitor& vis() BOOST_NOEXCEPT {
        // Functions that work with lambdas must be defined in same translation unit.
        // Because of that, we can not use `boost::decval<Visitor&>()` here.
        Visitor&(*f)() = 0; // pointer to function
        return f();
    }

    static decltype(auto) deduce_impl(last_it, unsigned /*helper*/) {
        typedef typename boost::mpl::deref<last_it>::type value_t;
        return vis()( boost::declval< value_t& >() );
    }

    template <class It>
    static decltype(auto) deduce_impl(It, unsigned helper) {
        typedef typename boost::mpl::next<It>::type next_t;
        typedef typename boost::mpl::deref<It>::type value_t;
        if (helper == boost::mpl::distance<begin_it, It>::type::value) {
            return deduce_impl(next_t(), ++helper);
        }

        return vis()( boost::declval< value_t& >() );
    }

    static decltype(auto) deduce() {
        return deduce_impl(begin_it(), 0);
    }
=======
    template <class It, class Dummy = void> // avoid explicit specialization in class scope
    struct deduce_impl {
        typedef typename boost::mpl::next<It>::type next_t;
        typedef typename boost::mpl::deref<It>::type value_t;
        typedef decltype(true ? boost::declval< Visitor& >()( boost::declval< copy_cv_ref_t< value_t, Variant > >() )
                              : boost::declval< typename deduce_impl<next_t>::type >()) type;
    };

    template <class Dummy>
    struct deduce_impl<last_it, Dummy> {
        typedef typename boost::mpl::deref<last_it>::type value_t;
        typedef decltype(boost::declval< Visitor& >()( boost::declval< copy_cv_ref_t< value_t, Variant > >() )) type;
    };

    typedef typename deduce_impl<begin_it>::type type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

template <class Visitor, class Variant>
struct result_wrapper1
{
<<<<<<< HEAD
    typedef decltype(result_multideduce1<Visitor, Variant>::deduce()) result_type;

    Visitor& visitor_;
    explicit result_wrapper1(Visitor& visitor) BOOST_NOEXCEPT
        : visitor_(visitor)
=======
    typedef typename result_multideduce1<Visitor, Variant>::type result_type;

    Visitor&& visitor_;
    explicit result_wrapper1(Visitor&& visitor) BOOST_NOEXCEPT
        : visitor_(::boost::forward<Visitor>(visitor))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    {}

    template <class T>
    result_type operator()(T&& val) const {
        return visitor_(::boost::forward<T>(val));
    }
};

}} // namespace detail::variant

template <typename Visitor, typename Visitable>
<<<<<<< HEAD
inline decltype(auto) apply_visitor(Visitor& visitor, Visitable&& visitable,
    typename boost::disable_if<
        boost::detail::variant::has_result_type<Visitor>
    >::type* = 0)
{
    boost::detail::variant::result_wrapper1<Visitor, typename remove_reference<Visitable>::type> cpp14_vis(visitor);
    return ::boost::forward<Visitable>(visitable).apply_visitor(cpp14_vis);
}

template <typename Visitor, typename Visitable>
inline decltype(auto) apply_visitor(const Visitor& visitor, Visitable&& visitable,
=======
inline decltype(auto) apply_visitor(Visitor&& visitor, Visitable&& visitable,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    typename boost::disable_if<
        boost::detail::variant::has_result_type<Visitor>
    >::type* = 0)
{
<<<<<<< HEAD
    boost::detail::variant::result_wrapper1<const Visitor, typename remove_reference<Visitable>::type> cpp14_vis(visitor);
    return ::boost::forward<Visitable>(visitable).apply_visitor(cpp14_vis);
}


=======
    boost::detail::variant::result_wrapper1<Visitor, Visitable> cpp14_vis(::boost::forward<Visitor>(visitor));
    return ::boost::forward<Visitable>(visitable).apply_visitor(cpp14_vis);
}

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif // !defined(BOOST_NO_CXX14_DECLTYPE_AUTO) && !defined(BOOST_NO_CXX11_DECLTYPE_N3276)

} // namespace boost

#endif // BOOST_VARIANT_DETAIL_APPLY_VISITOR_UNARY_HPP
