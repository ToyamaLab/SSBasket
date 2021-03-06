/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2009 Helge Bahmann
 * Copyright (c) 2012 Tim Blechmann
<<<<<<< HEAD
 * Copyright (c) 2013 - 2014 Andrey Semashev
=======
 * Copyright (c) 2013 - 2018 Andrey Semashev
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
 */
/*!
 * \file   atomic/detail/bitwise_cast.hpp
 *
 * This header defines \c bitwise_cast used to convert between storage and value types
 */

#ifndef BOOST_ATOMIC_DETAIL_BITWISE_CAST_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_BITWISE_CAST_HPP_INCLUDED_

<<<<<<< HEAD
#include <boost/atomic/detail/config.hpp>
#if !defined(BOOST_ATOMIC_DETAIL_HAS_BUILTIN_MEMCPY)
#include <cstring>
#endif
=======
#include <cstddef>
#include <boost/atomic/detail/config.hpp>
#include <boost/atomic/detail/addressof.hpp>
#include <boost/atomic/detail/string_ops.hpp>
#include <boost/atomic/detail/type_traits/integral_constant.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

<<<<<<< HEAD
#if defined(BOOST_GCC) && (BOOST_GCC+0) >= 40600
#pragma GCC diagnostic push
// missing initializer for member var
//#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
namespace boost {
namespace atomics {
namespace detail {

<<<<<<< HEAD
template< typename T >
BOOST_FORCEINLINE T* addressof(T& value) BOOST_NOEXCEPT
{
    // Note: The point of using a local struct as the intermediate type instead of char is to avoid gcc warnings
    // if T is a const volatile char*:
    // warning: casting 'const volatile char* const' to 'const volatile char&' does not dereference pointer
    // The local struct makes sure T is not related to the cast target type.
    struct opaque_type;
    return reinterpret_cast< T* >(&const_cast< opaque_type& >(reinterpret_cast< const volatile opaque_type& >(value)));
}

template< typename To, typename From >
BOOST_FORCEINLINE To bitwise_cast(From const& from) BOOST_NOEXCEPT
{
    struct
    {
        To to;
    }
    value = {};
    BOOST_ATOMIC_DETAIL_MEMCPY
    (
        atomics::detail::addressof(value.to),
        atomics::detail::addressof(from),
        (sizeof(From) < sizeof(To) ? sizeof(From) : sizeof(To))
    );
    return value.to;
=======
template< std::size_t FromSize, typename To >
BOOST_FORCEINLINE void clear_padding(To& to, atomics::detail::true_type) BOOST_NOEXCEPT
{
    BOOST_ATOMIC_DETAIL_MEMSET(reinterpret_cast< unsigned char* >(atomics::detail::addressof(to)) + FromSize, 0, sizeof(To) - FromSize);
}

template< std::size_t FromSize, typename To >
BOOST_FORCEINLINE void clear_padding(To&, atomics::detail::false_type) BOOST_NOEXCEPT
{
}

template< typename To, std::size_t FromSize, typename From >
BOOST_FORCEINLINE To bitwise_cast(From const& from) BOOST_NOEXCEPT
{
    To to;
    BOOST_ATOMIC_DETAIL_MEMCPY
    (
        atomics::detail::addressof(to),
        atomics::detail::addressof(from),
        (FromSize < sizeof(To) ? FromSize : sizeof(To))
    );
    atomics::detail::clear_padding< FromSize >(to, atomics::detail::integral_constant< bool, FromSize < sizeof(To) >());
    return to;
}

template< typename To, typename From >
BOOST_FORCEINLINE To bitwise_cast(From const& from) BOOST_NOEXCEPT
{
    return atomics::detail::bitwise_cast< To, sizeof(From) >(from);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

} // namespace detail
} // namespace atomics
} // namespace boost

<<<<<<< HEAD
#if defined(BOOST_GCC) && (BOOST_GCC+0) >= 40600
#pragma GCC diagnostic pop
#endif

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif // BOOST_ATOMIC_DETAIL_BITWISE_CAST_HPP_INCLUDED_
