/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2009 Helge Bahmann
 * Copyright (c) 2013 Tim Blechmann
 * Copyright (c) 2014 Andrey Semashev
 */
/*!
 * \file   atomic/detail/ops_gcc_ppc_common.hpp
 *
 * This header contains basic utilities for gcc PowerPC backend.
 */

#ifndef BOOST_ATOMIC_DETAIL_OPS_GCC_PPC_COMMON_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_OPS_GCC_PPC_COMMON_HPP_INCLUDED_

#include <boost/memory_order.hpp>
#include <boost/atomic/detail/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace atomics {
namespace detail {

// The implementation below uses information from this document:
// http://www.rdrop.com/users/paulmck/scalability/paper/N2745r.2010.02.19a.html

// A note about memory_order_consume. Technically, this architecture allows to avoid
// unnecessary memory barrier after consume load since it supports data dependency ordering.
// However, some compiler optimizations may break a seemingly valid code relying on data
// dependency tracking by injecting bogus branches to aid out of order execution.
// This may happen not only in Boost.Atomic code but also in user's code, which we have no
// control of. See this thread: http://lists.boost.org/Archives/boost/2014/06/213890.php.
// For this reason we promote memory_order_consume to memory_order_acquire.

struct gcc_ppc_operations_base
{
<<<<<<< HEAD
=======
    static BOOST_CONSTEXPR_OR_CONST bool full_cas_based = false;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    static BOOST_CONSTEXPR_OR_CONST bool is_always_lock_free = true;

    static BOOST_FORCEINLINE void fence_before(memory_order order) BOOST_NOEXCEPT
    {
#if defined(__powerpc64__) || defined(__PPC64__)
        if (order == memory_order_seq_cst)
            __asm__ __volatile__ ("sync" ::: "memory");
<<<<<<< HEAD
        else if ((order & memory_order_release) != 0)
            __asm__ __volatile__ ("lwsync" ::: "memory");
#else
        if ((order & memory_order_release) != 0)
=======
        else if ((static_cast< unsigned int >(order) & static_cast< unsigned int >(memory_order_release)) != 0u)
            __asm__ __volatile__ ("lwsync" ::: "memory");
#else
        if ((static_cast< unsigned int >(order) & static_cast< unsigned int >(memory_order_release)) != 0u)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            __asm__ __volatile__ ("sync" ::: "memory");
#endif
    }

    static BOOST_FORCEINLINE void fence_after(memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        if ((order & (memory_order_consume | memory_order_acquire)) != 0)
=======
        if ((static_cast< unsigned int >(order) & (static_cast< unsigned int >(memory_order_consume) | static_cast< unsigned int >(memory_order_acquire))) != 0u)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            __asm__ __volatile__ ("isync" ::: "memory");
    }
};

} // namespace detail
} // namespace atomics
} // namespace boost

#endif // BOOST_ATOMIC_DETAIL_OPS_GCC_PPC_COMMON_HPP_INCLUDED_
