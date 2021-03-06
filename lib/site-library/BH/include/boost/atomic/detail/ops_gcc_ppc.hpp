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
 * \file   atomic/detail/ops_gcc_ppc.hpp
 *
 * This header contains implementation of the \c operations template.
 */

#ifndef BOOST_ATOMIC_DETAIL_OPS_GCC_PPC_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_OPS_GCC_PPC_HPP_INCLUDED_

#include <cstddef>
#include <boost/memory_order.hpp>
#include <boost/atomic/detail/config.hpp>
#include <boost/atomic/detail/storage_type.hpp>
#include <boost/atomic/detail/operations_fwd.hpp>
#include <boost/atomic/detail/ops_gcc_ppc_common.hpp>
#include <boost/atomic/capabilities.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace atomics {
namespace detail {

// The implementation below uses information from this document:
// http://www.rdrop.com/users/paulmck/scalability/paper/N2745r.2010.02.19a.html

/*
    Refer to: Motorola: "Programming Environments Manual for 32-Bit
    Implementations of the PowerPC Architecture", Appendix E:
    "Synchronization Programming Examples" for an explanation of what is
    going on here (can be found on the web at various places by the
    name "MPCFPE32B.pdf", Google is your friend...)

    Most of the atomic operations map to instructions in a relatively
    straight-forward fashion, but "load"s may at first glance appear
    a bit strange as they map to:

            lwz %rX, addr
            cmpw %rX, %rX
            bne- 1f
        1:

    That is, the CPU is forced to perform a branch that "formally" depends
    on the value retrieved from memory. This scheme has an overhead of
    about 1-2 clock cycles per load, but it allows to map "acquire" to
    the "isync" instruction instead of "sync" uniformly and for all type
    of atomic operations. Since "isync" has a cost of about 15 clock
    cycles, while "sync" hast a cost of about 50 clock cycles, the small
    penalty to atomic loads more than compensates for this.

    Byte- and halfword-sized atomic values are implemented in two ways.
    When 8 and 16-bit instructions are available (in Power8 and later),
    they are used. Otherwise operations are realized by encoding the
    value to be represented into a word, performing sign/zero extension
    as appropriate. This means that after add/sub operations the value
    needs fixing up to accurately preserve the wrap-around semantic of
    the smaller type. (Nothing special needs to be done for the bit-wise
    and the "exchange type" operators as the compiler already sees to
    it that values carried in registers are extended appropriately and
    everything falls into place naturally).

    The register constraint "b"  instructs gcc to use any register
    except r0; this is sometimes required because the encoding for
    r0 is used to signify "constant zero" in a number of instructions,
    making r0 unusable in this place. For simplicity this constraint
    is used everywhere since I am to lazy to look this up on a
    per-instruction basis, and ppc has enough registers for this not
    to pose a problem.
*/

template< bool Signed >
struct operations< 4u, Signed > :
    public gcc_ppc_operations_base
{
<<<<<<< HEAD
    typedef typename make_storage_type< 4u, Signed >::type storage_type;
    typedef typename make_storage_type< 4u, Signed >::aligned aligned_storage_type;
=======
    typedef typename make_storage_type< 4u >::type storage_type;
    typedef typename make_storage_type< 4u >::aligned aligned_storage_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    static BOOST_CONSTEXPR_OR_CONST std::size_t storage_size = 4u;
    static BOOST_CONSTEXPR_OR_CONST bool is_signed = Signed;

    static BOOST_FORCEINLINE void store(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
        fence_before(order);
        __asm__ __volatile__
        (
            "stw %1, %0\n\t"
            : "+m" (storage)
            : "r" (v)
        );
    }

    static BOOST_FORCEINLINE storage_type load(storage_type const volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        storage_type v;
        if (order == memory_order_seq_cst)
            __asm__ __volatile__ ("sync" ::: "memory");
<<<<<<< HEAD
        if ((order & (memory_order_consume | memory_order_acquire)) != 0)
=======
        if ((static_cast< unsigned int >(order) & (static_cast< unsigned int >(memory_order_consume) | static_cast< unsigned int >(memory_order_acquire))) != 0u)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            __asm__ __volatile__
            (
                "lwz %0, %1\n\t"
                "cmpw %0, %0\n\t"
                "bne- 1f\n\t"
                "1:\n\t"
                "isync\n\t"
                : "=&r" (v)
                : "m" (storage)
                : "cr0", "memory"
            );
        }
        else
        {
            __asm__ __volatile__
            (
                "lwz %0, %1\n\t"
                : "=&r" (v)
                : "m" (storage)
            );
        }
        return v;
    }

    static BOOST_FORCEINLINE storage_type exchange(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
        storage_type original;
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y1\n\t"
            "stwcx. %2,%y1\n\t"
            "bne- 1b\n\t"
            : "=&b" (original), "+Z" (storage)
            : "b" (v)
            : "cr0"
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE bool compare_exchange_weak(
        storage_type volatile& storage, storage_type& expected, storage_type desired, memory_order success_order, memory_order failure_order) BOOST_NOEXCEPT
    {
        int success;
        fence_before(success_order);
        __asm__ __volatile__
        (
            "li %1, 0\n\t"
            "lwarx %0,%y2\n\t"
            "cmpw %0, %3\n\t"
            "bne- 1f\n\t"
            "stwcx. %4,%y2\n\t"
            "bne- 1f\n\t"
            "li %1, 1\n\t"
            "1:\n\t"
            : "=&b" (expected), "=&b" (success), "+Z" (storage)
            : "b" (expected), "b" (desired)
            : "cr0"
        );
        if (success)
            fence_after(success_order);
        else
            fence_after(failure_order);
        return !!success;
    }

    static BOOST_FORCEINLINE bool compare_exchange_strong(
        storage_type volatile& storage, storage_type& expected, storage_type desired, memory_order success_order, memory_order failure_order) BOOST_NOEXCEPT
    {
        int success;
        fence_before(success_order);
        __asm__ __volatile__
        (
            "li %1, 0\n\t"
            "0: lwarx %0,%y2\n\t"
            "cmpw %0, %3\n\t"
            "bne- 1f\n\t"
            "stwcx. %4,%y2\n\t"
            "bne- 0b\n\t"
            "li %1, 1\n\t"
            "1:\n\t"
            : "=&b" (expected), "=&b" (success), "+Z" (storage)
            : "b" (expected), "b" (desired)
            : "cr0"
        );
        if (success)
            fence_after(success_order);
        else
            fence_after(failure_order);
        return !!success;
    }

    static BOOST_FORCEINLINE storage_type fetch_add(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "add %1,%0,%3\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_sub(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "sub %1,%0,%3\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_and(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "and %1,%0,%3\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_or(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "or %1,%0,%3\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_xor(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "xor %1,%0,%3\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE bool test_and_set(storage_type volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        return !!exchange(storage, (storage_type)1, order);
    }

    static BOOST_FORCEINLINE void clear(storage_type volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        store(storage, 0, order);
    }
};

#if defined(BOOST_ATOMIC_DETAIL_PPC_HAS_LBARX_STBCX)

template< bool Signed >
struct operations< 1u, Signed > :
    public gcc_ppc_operations_base
{
<<<<<<< HEAD
    typedef typename make_storage_type< 1u, Signed >::type storage_type;
    typedef typename make_storage_type< 1u, Signed >::aligned aligned_storage_type;
    typedef typename make_storage_type< 1u, false >::type unsigned_storage_type;
=======
    typedef typename make_storage_type< 1u >::type storage_type;
    typedef typename make_storage_type< 1u >::aligned aligned_storage_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    static BOOST_CONSTEXPR_OR_CONST std::size_t storage_size = 1u;
    static BOOST_CONSTEXPR_OR_CONST bool is_signed = Signed;

    static BOOST_FORCEINLINE void store(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
        fence_before(order);
        __asm__ __volatile__
        (
            "stb %1, %0\n\t"
            : "+m" (storage)
            : "r" (v)
        );
    }

    static BOOST_FORCEINLINE storage_type load(storage_type const volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        storage_type v;
        if (order == memory_order_seq_cst)
            __asm__ __volatile__ ("sync" ::: "memory");
<<<<<<< HEAD
        if ((order & (memory_order_consume | memory_order_acquire)) != 0)
=======
        if ((static_cast< unsigned int >(order) & (static_cast< unsigned int >(memory_order_consume) | static_cast< unsigned int >(memory_order_acquire))) != 0u)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            __asm__ __volatile__
            (
                "lbz %0, %1\n\t"
                "cmpw %0, %0\n\t"
                "bne- 1f\n\t"
                "1:\n\t"
                "isync\n\t"
                : "=&r" (v)
                : "m" (storage)
                : "cr0", "memory"
            );
        }
        else
        {
            __asm__ __volatile__
            (
                "lbz %0, %1\n\t"
                : "=&r" (v)
                : "m" (storage)
            );
        }
        return v;
    }

    static BOOST_FORCEINLINE storage_type exchange(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
        storage_type original;
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lbarx %0,%y1\n\t"
            "stbcx. %2,%y1\n\t"
            "bne- 1b\n\t"
            : "=&b" (original), "+Z" (storage)
            : "b" (v)
            : "cr0"
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE bool compare_exchange_weak(
        storage_type volatile& storage, storage_type& expected, storage_type desired, memory_order success_order, memory_order failure_order) BOOST_NOEXCEPT
    {
        int success;
        fence_before(success_order);
        __asm__ __volatile__
        (
            "li %1, 0\n\t"
            "lbarx %0,%y2\n\t"
            "cmpw %0, %3\n\t"
            "bne- 1f\n\t"
            "stbcx. %4,%y2\n\t"
            "bne- 1f\n\t"
            "li %1, 1\n\t"
            "1:\n\t"
            : "=&b" (expected), "=&b" (success), "+Z" (storage)
<<<<<<< HEAD
            : "b" ((unsigned_storage_type)expected), "b" (desired)
=======
            : "b" (expected), "b" (desired)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "cr0"
        );
        if (success)
            fence_after(success_order);
        else
            fence_after(failure_order);
        return !!success;
    }

    static BOOST_FORCEINLINE bool compare_exchange_strong(
        storage_type volatile& storage, storage_type& expected, storage_type desired, memory_order success_order, memory_order failure_order) BOOST_NOEXCEPT
    {
        int success;
        fence_before(success_order);
        __asm__ __volatile__
        (
            "li %1, 0\n\t"
            "0: lbarx %0,%y2\n\t"
            "cmpw %0, %3\n\t"
            "bne- 1f\n\t"
            "stbcx. %4,%y2\n\t"
            "bne- 0b\n\t"
            "li %1, 1\n\t"
            "1:\n\t"
            : "=&b" (expected), "=&b" (success), "+Z" (storage)
<<<<<<< HEAD
            : "b" ((unsigned_storage_type)expected), "b" (desired)
=======
            : "b" (expected), "b" (desired)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "cr0"
        );
        if (success)
            fence_after(success_order);
        else
            fence_after(failure_order);
        return !!success;
    }

    static BOOST_FORCEINLINE storage_type fetch_add(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lbarx %0,%y2\n\t"
            "add %1,%0,%3\n\t"
            "stbcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_sub(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lbarx %0,%y2\n\t"
            "sub %1,%0,%3\n\t"
            "stbcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_and(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lbarx %0,%y2\n\t"
            "and %1,%0,%3\n\t"
            "stbcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_or(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lbarx %0,%y2\n\t"
            "or %1,%0,%3\n\t"
            "stbcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_xor(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lbarx %0,%y2\n\t"
            "xor %1,%0,%3\n\t"
            "stbcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE bool test_and_set(storage_type volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        return !!exchange(storage, (storage_type)1, order);
    }

    static BOOST_FORCEINLINE void clear(storage_type volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        store(storage, 0, order);
    }
};

#else // defined(BOOST_ATOMIC_DETAIL_PPC_HAS_LBARX_STBCX)

template< >
struct operations< 1u, false > :
    public operations< 4u, false >
{
    typedef operations< 4u, false > base_type;
    typedef base_type::storage_type storage_type;

    static BOOST_FORCEINLINE storage_type fetch_add(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "add %1,%0,%3\n\t"
            "rlwinm %1, %1, 0, 0xff\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_sub(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "sub %1,%0,%3\n\t"
            "rlwinm %1, %1, 0, 0xff\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }
};

template< >
struct operations< 1u, true > :
    public operations< 4u, true >
{
    typedef operations< 4u, true > base_type;
    typedef base_type::storage_type storage_type;

    static BOOST_FORCEINLINE storage_type fetch_add(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "add %1,%0,%3\n\t"
            "extsb %1, %1\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_sub(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "sub %1,%0,%3\n\t"
            "extsb %1, %1\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }
};

#endif // defined(BOOST_ATOMIC_DETAIL_PPC_HAS_LBARX_STBCX)

#if defined(BOOST_ATOMIC_DETAIL_PPC_HAS_LHARX_STHCX)

template< bool Signed >
struct operations< 2u, Signed > :
    public gcc_ppc_operations_base
{
<<<<<<< HEAD
    typedef typename make_storage_type< 2u, Signed >::type storage_type;
    typedef typename make_storage_type< 2u, Signed >::aligned aligned_storage_type;
    typedef typename make_storage_type< 2u, false >::type unsigned_storage_type;
=======
    typedef typename make_storage_type< 2u >::type storage_type;
    typedef typename make_storage_type< 2u >::aligned aligned_storage_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    static BOOST_CONSTEXPR_OR_CONST std::size_t storage_size = 2u;
    static BOOST_CONSTEXPR_OR_CONST bool is_signed = Signed;

    static BOOST_FORCEINLINE void store(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
        fence_before(order);
        __asm__ __volatile__
        (
            "sth %1, %0\n\t"
            : "+m" (storage)
            : "r" (v)
        );
    }

    static BOOST_FORCEINLINE storage_type load(storage_type const volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        storage_type v;
        if (order == memory_order_seq_cst)
            __asm__ __volatile__ ("sync" ::: "memory");
<<<<<<< HEAD
        if ((order & (memory_order_consume | memory_order_acquire)) != 0)
=======
        if ((static_cast< unsigned int >(order) & (static_cast< unsigned int >(memory_order_consume) | static_cast< unsigned int >(memory_order_acquire))) != 0u)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            __asm__ __volatile__
            (
                "lhz %0, %1\n\t"
                "cmpw %0, %0\n\t"
                "bne- 1f\n\t"
                "1:\n\t"
                "isync\n\t"
                : "=&r" (v)
                : "m" (storage)
                : "cr0", "memory"
            );
        }
        else
        {
            __asm__ __volatile__
            (
                "lhz %0, %1\n\t"
                : "=&r" (v)
                : "m" (storage)
            );
        }
        return v;
    }

    static BOOST_FORCEINLINE storage_type exchange(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
        storage_type original;
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lharx %0,%y1\n\t"
            "sthcx. %2,%y1\n\t"
            "bne- 1b\n\t"
            : "=&b" (original), "+Z" (storage)
            : "b" (v)
            : "cr0"
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE bool compare_exchange_weak(
        storage_type volatile& storage, storage_type& expected, storage_type desired, memory_order success_order, memory_order failure_order) BOOST_NOEXCEPT
    {
        int success;
        fence_before(success_order);
        __asm__ __volatile__
        (
            "li %1, 0\n\t"
            "lharx %0,%y2\n\t"
            "cmpw %0, %3\n\t"
            "bne- 1f\n\t"
            "sthcx. %4,%y2\n\t"
            "bne- 1f\n\t"
            "li %1, 1\n\t"
            "1:\n\t"
            : "=&b" (expected), "=&b" (success), "+Z" (storage)
<<<<<<< HEAD
            : "b" ((unsigned_storage_type)expected), "b" (desired)
=======
            : "b" (expected), "b" (desired)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "cr0"
        );
        if (success)
            fence_after(success_order);
        else
            fence_after(failure_order);
        return !!success;
    }

    static BOOST_FORCEINLINE bool compare_exchange_strong(
        storage_type volatile& storage, storage_type& expected, storage_type desired, memory_order success_order, memory_order failure_order) BOOST_NOEXCEPT
    {
        int success;
        fence_before(success_order);
        __asm__ __volatile__
        (
            "li %1, 0\n\t"
            "0: lharx %0,%y2\n\t"
            "cmpw %0, %3\n\t"
            "bne- 1f\n\t"
            "sthcx. %4,%y2\n\t"
            "bne- 0b\n\t"
            "li %1, 1\n\t"
            "1:\n\t"
            : "=&b" (expected), "=&b" (success), "+Z" (storage)
<<<<<<< HEAD
            : "b" ((unsigned_storage_type)expected), "b" (desired)
=======
            : "b" (expected), "b" (desired)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "cr0"
        );
        if (success)
            fence_after(success_order);
        else
            fence_after(failure_order);
        return !!success;
    }

    static BOOST_FORCEINLINE storage_type fetch_add(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lharx %0,%y2\n\t"
            "add %1,%0,%3\n\t"
            "sthcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_sub(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lharx %0,%y2\n\t"
            "sub %1,%0,%3\n\t"
            "sthcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_and(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lharx %0,%y2\n\t"
            "and %1,%0,%3\n\t"
            "sthcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_or(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lharx %0,%y2\n\t"
            "or %1,%0,%3\n\t"
            "sthcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_xor(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lharx %0,%y2\n\t"
            "xor %1,%0,%3\n\t"
            "sthcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE bool test_and_set(storage_type volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        return !!exchange(storage, (storage_type)1, order);
    }

    static BOOST_FORCEINLINE void clear(storage_type volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        store(storage, 0, order);
    }
};

#else // defined(BOOST_ATOMIC_DETAIL_PPC_HAS_LHARX_STHCX)

template< >
struct operations< 2u, false > :
    public operations< 4u, false >
{
    typedef operations< 4u, false > base_type;
    typedef base_type::storage_type storage_type;

    static BOOST_FORCEINLINE storage_type fetch_add(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "add %1,%0,%3\n\t"
            "rlwinm %1, %1, 0, 0xffff\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_sub(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "sub %1,%0,%3\n\t"
            "rlwinm %1, %1, 0, 0xffff\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }
};

template< >
struct operations< 2u, true > :
    public operations< 4u, true >
{
    typedef operations< 4u, true > base_type;
    typedef base_type::storage_type storage_type;

    static BOOST_FORCEINLINE storage_type fetch_add(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "add %1,%0,%3\n\t"
            "extsh %1, %1\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_sub(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "lwarx %0,%y2\n\t"
            "sub %1,%0,%3\n\t"
            "extsh %1, %1\n\t"
            "stwcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }
};

#endif // defined(BOOST_ATOMIC_DETAIL_PPC_HAS_LHARX_STHCX)

#if defined(BOOST_ATOMIC_DETAIL_PPC_HAS_LDARX_STDCX)

template< bool Signed >
struct operations< 8u, Signed > :
    public gcc_ppc_operations_base
{
<<<<<<< HEAD
    typedef typename make_storage_type< 8u, Signed >::type storage_type;
    typedef typename make_storage_type< 8u, Signed >::aligned aligned_storage_type;
=======
    typedef typename make_storage_type< 8u >::type storage_type;
    typedef typename make_storage_type< 8u >::aligned aligned_storage_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    static BOOST_CONSTEXPR_OR_CONST std::size_t storage_size = 8u;
    static BOOST_CONSTEXPR_OR_CONST bool is_signed = Signed;

    static BOOST_FORCEINLINE void store(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
        fence_before(order);
        __asm__ __volatile__
        (
            "std %1, %0\n\t"
            : "+m" (storage)
            : "r" (v)
        );
    }

    static BOOST_FORCEINLINE storage_type load(storage_type const volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        storage_type v;
        if (order == memory_order_seq_cst)
            __asm__ __volatile__ ("sync" ::: "memory");
<<<<<<< HEAD
        if ((order & (memory_order_consume | memory_order_acquire)) != 0)
=======
        if ((static_cast< unsigned int >(order) & (static_cast< unsigned int >(memory_order_consume) | static_cast< unsigned int >(memory_order_acquire))) != 0u)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            __asm__ __volatile__
            (
                "ld %0, %1\n\t"
                "cmpd %0, %0\n\t"
                "bne- 1f\n\t"
                "1:\n\t"
                "isync\n\t"
                : "=&b" (v)
                : "m" (storage)
                : "cr0", "memory"
            );
        }
        else
        {
            __asm__ __volatile__
            (
                "ld %0, %1\n\t"
                : "=&b" (v)
                : "m" (storage)
            );
        }
        return v;
    }

    static BOOST_FORCEINLINE storage_type exchange(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
        storage_type original;
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "ldarx %0,%y1\n\t"
            "stdcx. %2,%y1\n\t"
            "bne- 1b\n\t"
            : "=&b" (original), "+Z" (storage)
            : "b" (v)
            : "cr0"
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE bool compare_exchange_weak(
        storage_type volatile& storage, storage_type& expected, storage_type desired, memory_order success_order, memory_order failure_order) BOOST_NOEXCEPT
    {
        int success;
        fence_before(success_order);
        __asm__ __volatile__
        (
            "li %1, 0\n\t"
            "ldarx %0,%y2\n\t"
            "cmpd %0, %3\n\t"
            "bne- 1f\n\t"
            "stdcx. %4,%y2\n\t"
            "bne- 1f\n\t"
            "li %1, 1\n\t"
            "1:"
            : "=&b" (expected), "=&b" (success), "+Z" (storage)
            : "b" (expected), "b" (desired)
            : "cr0"
        );
        if (success)
            fence_after(success_order);
        else
            fence_after(failure_order);
        return !!success;
    }

    static BOOST_FORCEINLINE bool compare_exchange_strong(
        storage_type volatile& storage, storage_type& expected, storage_type desired, memory_order success_order, memory_order failure_order) BOOST_NOEXCEPT
    {
        int success;
        fence_before(success_order);
        __asm__ __volatile__
        (
            "li %1, 0\n\t"
            "0: ldarx %0,%y2\n\t"
            "cmpd %0, %3\n\t"
            "bne- 1f\n\t"
            "stdcx. %4,%y2\n\t"
            "bne- 0b\n\t"
            "li %1, 1\n\t"
            "1:\n\t"
            : "=&b" (expected), "=&b" (success), "+Z" (storage)
            : "b" (expected), "b" (desired)
            : "cr0"
        );
        if (success)
            fence_after(success_order);
        else
            fence_after(failure_order);
        return !!success;
    }

    static BOOST_FORCEINLINE storage_type fetch_add(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "ldarx %0,%y2\n\t"
            "add %1,%0,%3\n\t"
            "stdcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_sub(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "ldarx %0,%y2\n\t"
            "sub %1,%0,%3\n\t"
            "stdcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_and(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "ldarx %0,%y2\n\t"
            "and %1,%0,%3\n\t"
            "stdcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_or(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "ldarx %0,%y2\n\t"
            "or %1,%0,%3\n\t"
            "stdcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE storage_type fetch_xor(storage_type volatile& storage, storage_type v, memory_order order) BOOST_NOEXCEPT
    {
<<<<<<< HEAD
        storage_type original, tmp;
=======
        storage_type original, result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        fence_before(order);
        __asm__ __volatile__
        (
            "1:\n\t"
            "ldarx %0,%y2\n\t"
            "xor %1,%0,%3\n\t"
            "stdcx. %1,%y2\n\t"
            "bne- 1b\n\t"
<<<<<<< HEAD
            : "=&b" (original), "=&b" (tmp), "+Z" (storage)
=======
            : "=&b" (original), "=&b" (result), "+Z" (storage)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            : "b" (v)
            : BOOST_ATOMIC_DETAIL_ASM_CLOBBER_CC
        );
        fence_after(order);
        return original;
    }

    static BOOST_FORCEINLINE bool test_and_set(storage_type volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        return !!exchange(storage, (storage_type)1, order);
    }

    static BOOST_FORCEINLINE void clear(storage_type volatile& storage, memory_order order) BOOST_NOEXCEPT
    {
        store(storage, 0, order);
    }
};

#endif // defined(BOOST_ATOMIC_DETAIL_PPC_HAS_LDARX_STDCX)


BOOST_FORCEINLINE void thread_fence(memory_order order) BOOST_NOEXCEPT
{
<<<<<<< HEAD
    switch (order)
    {
    case memory_order_consume:
    case memory_order_acquire:
    case memory_order_release:
    case memory_order_acq_rel:
#if defined(__powerpc64__) || defined(__PPC64__)
        __asm__ __volatile__ ("lwsync" ::: "memory");
        break;
#endif
    case memory_order_seq_cst:
        __asm__ __volatile__ ("sync" ::: "memory");
        break;
    default:;
=======
    if (order != memory_order_relaxed)
    {
#if defined(__powerpc64__) || defined(__PPC64__)
        if (order != memory_order_seq_cst)
            __asm__ __volatile__ ("lwsync" ::: "memory");
        else
            __asm__ __volatile__ ("sync" ::: "memory");
#else
        __asm__ __volatile__ ("sync" ::: "memory");
#endif
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
}

BOOST_FORCEINLINE void signal_fence(memory_order order) BOOST_NOEXCEPT
{
    if (order != memory_order_relaxed)
#if defined(__ibmxl__) || defined(__IBMCPP__)
        __fence();
#else
        __asm__ __volatile__ ("" ::: "memory");
#endif
}

} // namespace detail
} // namespace atomics
} // namespace boost

#endif // BOOST_ATOMIC_DETAIL_OPS_GCC_PPC_HPP_INCLUDED_
