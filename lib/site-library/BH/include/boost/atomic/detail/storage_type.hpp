/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2009 Helge Bahmann
 * Copyright (c) 2012 Tim Blechmann
 * Copyright (c) 2013 - 2014 Andrey Semashev
 */
/*!
 * \file   atomic/detail/storage_type.hpp
 *
 * This header defines underlying types used as storage
 */

#ifndef BOOST_ATOMIC_DETAIL_STORAGE_TYPE_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_STORAGE_TYPE_HPP_INCLUDED_

#include <cstddef>
#include <boost/cstdint.hpp>
#include <boost/atomic/detail/config.hpp>
<<<<<<< HEAD
#if !defined(BOOST_ATOMIC_DETAIL_HAS_BUILTIN_MEMCMP) || !defined(BOOST_ATOMIC_DETAIL_HAS_BUILTIN_MEMCPY)
#include <cstring>
#endif
=======
#include <boost/atomic/detail/string_ops.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace atomics {
namespace detail {

template< typename T >
BOOST_FORCEINLINE void non_atomic_load(T const volatile& from, T& to) BOOST_NOEXCEPT
{
    to = from;
}

template< std::size_t Size >
struct BOOST_ATOMIC_DETAIL_MAY_ALIAS buffer_storage
{
    BOOST_ALIGNMENT(16) unsigned char data[Size];

    BOOST_FORCEINLINE bool operator! () const BOOST_NOEXCEPT
    {
        return (data[0] == 0u && BOOST_ATOMIC_DETAIL_MEMCMP(data, data + 1, Size - 1) == 0);
    }

    BOOST_FORCEINLINE bool operator== (buffer_storage const& that) const BOOST_NOEXCEPT
    {
        return BOOST_ATOMIC_DETAIL_MEMCMP(data, that.data, Size) == 0;
    }

    BOOST_FORCEINLINE bool operator!= (buffer_storage const& that) const BOOST_NOEXCEPT
    {
        return BOOST_ATOMIC_DETAIL_MEMCMP(data, that.data, Size) != 0;
    }
};

template< std::size_t Size >
BOOST_FORCEINLINE void non_atomic_load(buffer_storage< Size > const volatile& from, buffer_storage< Size >& to) BOOST_NOEXCEPT
{
    BOOST_ATOMIC_DETAIL_MEMCPY(to.data, const_cast< unsigned char const* >(from.data), Size);
}

<<<<<<< HEAD
template< std::size_t Size, bool Signed >
=======
template< std::size_t Size >
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
struct make_storage_type
{
    typedef buffer_storage< Size > type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type const& v) BOOST_NOEXCEPT : value(v) {}
    };
};

template< >
<<<<<<< HEAD
struct make_storage_type< 1u, false >
=======
struct make_storage_type< 1u >
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef boost::uint8_t BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

template< >
<<<<<<< HEAD
struct make_storage_type< 1u, true >
{
    typedef boost::int8_t BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

template< >
struct make_storage_type< 2u, false >
=======
struct make_storage_type< 2u >
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef boost::uint16_t BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        BOOST_ALIGNMENT(2) type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

template< >
<<<<<<< HEAD
struct make_storage_type< 2u, true >
{
    typedef boost::int16_t BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        BOOST_ALIGNMENT(2) type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

template< >
struct make_storage_type< 4u, false >
=======
struct make_storage_type< 4u >
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef boost::uint32_t BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        BOOST_ALIGNMENT(4) type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

template< >
<<<<<<< HEAD
struct make_storage_type< 4u, true >
{
    typedef boost::int32_t BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        BOOST_ALIGNMENT(4) type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

template< >
struct make_storage_type< 8u, false >
=======
struct make_storage_type< 8u >
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef boost::uint64_t BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        BOOST_ALIGNMENT(8) type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

<<<<<<< HEAD
template< >
struct make_storage_type< 8u, true >
{
    typedef boost::int64_t BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        BOOST_ALIGNMENT(8) type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

#if defined(BOOST_HAS_INT128)

template< >
struct make_storage_type< 16u, false >
=======
#if defined(BOOST_HAS_INT128)

template< >
struct make_storage_type< 16u >
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef boost::uint128_type BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        BOOST_ALIGNMENT(16) type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

<<<<<<< HEAD
template< >
struct make_storage_type< 16u, true >
{
    typedef boost::int128_type BOOST_ATOMIC_DETAIL_MAY_ALIAS type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        BOOST_ALIGNMENT(16) type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type v) BOOST_NOEXCEPT : value(v) {}
    };
};

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#elif !defined(BOOST_NO_ALIGNMENT)

struct BOOST_ATOMIC_DETAIL_MAY_ALIAS storage128_t
{
    typedef boost::uint64_t BOOST_ATOMIC_DETAIL_MAY_ALIAS element_type;

    element_type data[2];

    BOOST_FORCEINLINE bool operator! () const BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        return data[0] == 0 && data[1] == 0;
=======
        return (data[0] | data[1]) == 0u;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
};

BOOST_FORCEINLINE bool operator== (storage128_t const& left, storage128_t const& right) BOOST_NOEXCEPT
{
<<<<<<< HEAD
    return left.data[0] == right.data[0] && left.data[1] == right.data[1];
=======
    return ((left.data[0] ^ right.data[0]) | (left.data[1] ^ right.data[1])) == 0u;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
BOOST_FORCEINLINE bool operator!= (storage128_t const& left, storage128_t const& right) BOOST_NOEXCEPT
{
    return !(left == right);
}

BOOST_FORCEINLINE void non_atomic_load(storage128_t const volatile& from, storage128_t& to) BOOST_NOEXCEPT
{
    to.data[0] = from.data[0];
    to.data[1] = from.data[1];
}

<<<<<<< HEAD
template< bool Signed >
struct make_storage_type< 16u, Signed >
=======
template< >
struct make_storage_type< 16u >
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef storage128_t type;

    struct BOOST_ATOMIC_DETAIL_MAY_ALIAS aligned
    {
        BOOST_ALIGNMENT(16) type value;

        BOOST_DEFAULTED_FUNCTION(aligned(), {})
        BOOST_FORCEINLINE BOOST_CONSTEXPR explicit aligned(type const& v) BOOST_NOEXCEPT : value(v) {}
    };
};

#endif

template< typename T >
struct storage_size_of
{
<<<<<<< HEAD
    enum _
    {
        size = sizeof(T),
        value = (size == 3 ? 4 : (size >= 5 && size <= 7 ? 8 : (size >= 9 && size <= 15 ? 16 : size)))
    };
=======
    static BOOST_CONSTEXPR_OR_CONST std::size_t size = sizeof(T);
    static BOOST_CONSTEXPR_OR_CONST std::size_t value = (size == 3u ? 4u : (size >= 5u && size <= 7u ? 8u : (size >= 9u && size <= 15u ? 16u : size)));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

} // namespace detail
} // namespace atomics
} // namespace boost

#endif // BOOST_ATOMIC_DETAIL_STORAGE_TYPE_HPP_INCLUDED_
