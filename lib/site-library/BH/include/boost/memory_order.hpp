<<<<<<< HEAD
#ifndef BOOST_MEMORY_ORDER_HPP_INCLUDED
#define BOOST_MEMORY_ORDER_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
//  boost/memory_order.hpp
//
//  Defines enum boost::memory_order per the C++0x working draft
//
//  Copyright (c) 2008, 2009 Peter Dimov
<<<<<<< HEAD
=======
//  Copyright (c) 2018 Andrey Semashev
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

<<<<<<< HEAD
=======
#ifndef BOOST_MEMORY_ORDER_HPP_INCLUDED
#define BOOST_MEMORY_ORDER_HPP_INCLUDED

#include <boost/config.hpp>

#if defined(BOOST_HAS_PRAGMA_ONCE)
# pragma once
#endif
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace boost
{

//
// Enum values are chosen so that code that needs to insert
// a trailing fence for acquire semantics can use a single
// test such as:
//
// if( mo & memory_order_acquire ) { ...fence... }
//
// For leading fences one can use:
//
// if( mo & memory_order_release ) { ...fence... }
//
// Architectures such as Alpha that need a fence on consume
// can use:
//
// if( mo & ( memory_order_acquire | memory_order_consume ) ) { ...fence... }
//
// The values are also in the order of increasing "strength"
// of the fences so that success/failure orders can be checked
// efficiently in compare_exchange methods.
//

<<<<<<< HEAD
=======
#if !defined(BOOST_NO_CXX11_SCOPED_ENUMS)

enum class memory_order : unsigned int
{
    relaxed = 0,
    consume = 1,
    acquire = 2,
    release = 4,
    acq_rel = 6, // acquire | release
    seq_cst = 14 // acq_rel | 8
};

#if !defined(BOOST_NO_CXX17_INLINE_VARIABLES)
#define BOOST_MEMORY_ORDER_INLINE_VARIABLE inline
#else
#define BOOST_MEMORY_ORDER_INLINE_VARIABLE
#endif

BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_relaxed = memory_order::relaxed;
BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_consume = memory_order::consume;
BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_acquire = memory_order::acquire;
BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_release = memory_order::release;
BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_acq_rel = memory_order::acq_rel;
BOOST_MEMORY_ORDER_INLINE_VARIABLE BOOST_CONSTEXPR_OR_CONST memory_order memory_order_seq_cst = memory_order::seq_cst;

#undef BOOST_MEMORY_ORDER_INLINE_VARIABLE

#else // !defined(BOOST_NO_CXX11_SCOPED_ENUMS)

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
enum memory_order
{
    memory_order_relaxed = 0,
    memory_order_consume = 1,
    memory_order_acquire = 2,
    memory_order_release = 4,
    memory_order_acq_rel = 6, // acquire | release
    memory_order_seq_cst = 14 // acq_rel | 8
};

<<<<<<< HEAD
=======
#endif // !defined(BOOST_NO_CXX11_SCOPED_ENUMS)

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
} // namespace boost

#endif // #ifndef BOOST_MEMORY_ORDER_HPP_INCLUDED
