
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  (C) Copyright Eric Friedman 2002-2003.
//  (C) Copyright Antony Polukhin 2013.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_IS_NOTHROW_MOVE_ASSIGNABLE_HPP_INCLUDED
#define BOOST_TT_IS_NOTHROW_MOVE_ASSIGNABLE_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/type_traits/has_trivial_move_assign.hpp>
#include <boost/type_traits/has_nothrow_assign.hpp>
#include <boost/type_traits/is_array.hpp>
#include <boost/type_traits/is_reference.hpp>
<<<<<<< HEAD
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/declval.hpp>
=======
#include <boost/type_traits/enable_if.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/is_complete.hpp>
#include <boost/static_assert.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace boost {

#ifdef BOOST_IS_NOTHROW_MOVE_ASSIGN

template <class T>
<<<<<<< HEAD
struct is_nothrow_move_assignable : public integral_constant<bool, BOOST_IS_NOTHROW_MOVE_ASSIGN(T)>{};
=======
struct is_nothrow_move_assignable : public integral_constant<bool, BOOST_IS_NOTHROW_MOVE_ASSIGN(T)>
{
   BOOST_STATIC_ASSERT_MSG(boost::is_complete<T>::value, "Arguments to is_nothrow_move_assignable must be complete types");
};
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
template <class T> struct is_nothrow_move_assignable<T const> : public false_type{};
template <class T> struct is_nothrow_move_assignable<T volatile> : public false_type{};
template <class T> struct is_nothrow_move_assignable<T const volatile> : public false_type{};
template <class T> struct is_nothrow_move_assignable<T&> : public false_type{};
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) 
template <class T> struct is_nothrow_move_assignable<T&&> : public false_type{};
#endif

#elif !defined(BOOST_NO_CXX11_NOEXCEPT) && !defined(BOOST_NO_SFINAE_EXPR) && !BOOST_WORKAROUND(BOOST_GCC_VERSION, < 40700)

namespace detail{

template <class T, class Enable = void>
struct false_or_cpp11_noexcept_move_assignable: public ::boost::false_type {};

template <class T>
struct false_or_cpp11_noexcept_move_assignable <
        T,
<<<<<<< HEAD
        typename ::boost::enable_if_c<sizeof(T) && BOOST_NOEXCEPT_EXPR(::boost::declval<T&>() = ::boost::declval<T>())>::type
=======
        typename ::boost::enable_if_<sizeof(T) && BOOST_NOEXCEPT_EXPR(::boost::declval<T&>() = ::boost::declval<T>())>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    > : public ::boost::integral_constant<bool, BOOST_NOEXCEPT_EXPR(::boost::declval<T&>() = ::boost::declval<T>())>
{};

}

template <class T>
<<<<<<< HEAD
struct is_nothrow_move_assignable : public integral_constant<bool, ::boost::detail::false_or_cpp11_noexcept_move_assignable<T>::value>{};
=======
struct is_nothrow_move_assignable : public integral_constant<bool, ::boost::detail::false_or_cpp11_noexcept_move_assignable<T>::value>
{
   BOOST_STATIC_ASSERT_MSG(boost::is_complete<T>::value, "Arguments to is_nothrow_move_assignable must be complete types");
};
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

template <class T> struct is_nothrow_move_assignable<T const> : public ::boost::false_type {};
template <class T> struct is_nothrow_move_assignable<T const volatile> : public ::boost::false_type{};
template <class T> struct is_nothrow_move_assignable<T volatile> : public ::boost::false_type{};
template <class T> struct is_nothrow_move_assignable<T&> : public ::boost::false_type{};
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
template <class T> struct is_nothrow_move_assignable<T&&> : public ::boost::false_type{};
#endif

#else

template <class T>
struct is_nothrow_move_assignable : public integral_constant<bool,
<<<<<<< HEAD
   (::boost::has_trivial_move_assign<T>::value || ::boost::has_nothrow_assign<T>::value) &&  ! ::boost::is_array<T>::value>{};
=======
   (::boost::has_trivial_move_assign<T>::value || ::boost::has_nothrow_assign<T>::value) &&  ! ::boost::is_array<T>::value>
{
   BOOST_STATIC_ASSERT_MSG(boost::is_complete<T>::value, "Arguments to is_nothrow_move_assignable must be complete types");
};
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#endif


template <> struct is_nothrow_move_assignable<void> : public false_type{};
#ifndef BOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct is_nothrow_move_assignable<void const> : public false_type{};
template <> struct is_nothrow_move_assignable<void const volatile> : public false_type{};
template <> struct is_nothrow_move_assignable<void volatile> : public false_type{};
#endif

} // namespace boost

#endif // BOOST_TT_IS_NOTHROW_MOVE_ASSIGNABLE_HPP_INCLUDED
