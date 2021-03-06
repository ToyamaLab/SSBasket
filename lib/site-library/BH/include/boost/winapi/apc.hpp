/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_APC_HPP_INCLUDED_
#define BOOST_WINAPI_APC_HPP_INCLUDED_

#include <boost/winapi/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
#include <boost/winapi/basic_types.hpp>

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
<<<<<<< HEAD
typedef boost::winapi::VOID_ (NTAPI *PAPCFUNC)(boost::winapi::ULONG_PTR_ Parameter);

BOOST_SYMBOL_IMPORT boost::winapi::DWORD_ WINAPI
=======
typedef boost::winapi::VOID_ (BOOST_WINAPI_NTAPI_CC *PAPCFUNC)(boost::winapi::ULONG_PTR_ Parameter);

BOOST_SYMBOL_IMPORT boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
QueueUserAPC(
    PAPCFUNC pfnAPC,
    boost::winapi::HANDLE_ hThread,
    boost::winapi::ULONG_PTR_ dwData);
}
#endif

namespace boost {
namespace winapi {
typedef ::PAPCFUNC PAPCFUNC_;
using ::QueueUserAPC;
}
}

#endif // BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_WINAPI_APC_HPP_INCLUDED_
