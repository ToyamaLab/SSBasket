/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_INIT_ONCE_HPP_INCLUDED_
#define BOOST_WINAPI_INIT_ONCE_HPP_INCLUDED_

#include <boost/winapi/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6

#include <boost/winapi/basic_types.hpp>

<<<<<<< HEAD
#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if defined( BOOST_WINAPI_IS_MINGW_W64 )
=======
#if !defined(BOOST_USE_WINDOWS_H)
extern "C" {
#if defined(BOOST_WINAPI_IS_CYGWIN) || defined(BOOST_WINAPI_IS_MINGW_W64)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
struct _RTL_RUN_ONCE;
#else
union _RTL_RUN_ONCE;
#endif

typedef boost::winapi::BOOL_
<<<<<<< HEAD
(WINAPI *PINIT_ONCE_FN) (
=======
(BOOST_WINAPI_WINAPI_CC *PINIT_ONCE_FN) (
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    ::_RTL_RUN_ONCE* InitOnce,
    boost::winapi::PVOID_ Parameter,
    boost::winapi::PVOID_ *Context);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::VOID_ WINAPI
InitOnceInitialize(::_RTL_RUN_ONCE* InitOnce);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::VOID_ BOOST_WINAPI_WINAPI_CC
InitOnceInitialize(::_RTL_RUN_ONCE* InitOnce);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
InitOnceExecuteOnce(
    ::_RTL_RUN_ONCE* InitOnce,
    ::PINIT_ONCE_FN InitFn,
    boost::winapi::PVOID_ Parameter,
    boost::winapi::LPVOID_ *Context);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
InitOnceBeginInitialize(
    ::_RTL_RUN_ONCE* lpInitOnce,
    boost::winapi::DWORD_ dwFlags,
    boost::winapi::PBOOL_ fPending,
    boost::winapi::LPVOID_ *lpContext);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
InitOnceComplete(
    ::_RTL_RUN_ONCE* lpInitOnce,
    boost::winapi::DWORD_ dwFlags,
    boost::winapi::LPVOID_ lpContext);
}
#endif

namespace boost {
namespace winapi {

typedef union BOOST_MAY_ALIAS _RTL_RUN_ONCE {
    PVOID_ Ptr;
} INIT_ONCE_, *PINIT_ONCE_, *LPINIT_ONCE_;

extern "C" {
<<<<<<< HEAD
typedef BOOL_ (WINAPI *PINIT_ONCE_FN_) (PINIT_ONCE_ lpInitOnce, PVOID_ Parameter, PVOID_ *Context);
=======
typedef BOOL_ (BOOST_WINAPI_WINAPI_CC *PINIT_ONCE_FN_) (PINIT_ONCE_ lpInitOnce, PVOID_ Parameter, PVOID_ *Context);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

BOOST_FORCEINLINE VOID_ InitOnceInitialize(PINIT_ONCE_ lpInitOnce)
{
    ::InitOnceInitialize(reinterpret_cast< ::_RTL_RUN_ONCE* >(lpInitOnce));
}

BOOST_FORCEINLINE BOOL_ InitOnceExecuteOnce(PINIT_ONCE_ lpInitOnce, PINIT_ONCE_FN_ InitFn, PVOID_ Parameter, LPVOID_ *Context)
{
    return ::InitOnceExecuteOnce(reinterpret_cast< ::_RTL_RUN_ONCE* >(lpInitOnce), reinterpret_cast< ::PINIT_ONCE_FN >(InitFn), Parameter, Context);
}

BOOST_FORCEINLINE BOOL_ InitOnceBeginInitialize(PINIT_ONCE_ lpInitOnce, DWORD_ dwFlags, PBOOL_ fPending, LPVOID_ *lpContext)
{
    return ::InitOnceBeginInitialize(reinterpret_cast< ::_RTL_RUN_ONCE* >(lpInitOnce), dwFlags, fPending, lpContext);
}

BOOST_FORCEINLINE BOOL_ InitOnceComplete(PINIT_ONCE_ lpInitOnce, DWORD_ dwFlags, LPVOID_ lpContext)
{
    return ::InitOnceComplete(reinterpret_cast< ::_RTL_RUN_ONCE* >(lpInitOnce), dwFlags, lpContext);
}

#if defined( BOOST_USE_WINDOWS_H )

#define BOOST_WINAPI_INIT_ONCE_STATIC_INIT INIT_ONCE_STATIC_INIT
<<<<<<< HEAD
const DWORD_ INIT_ONCE_ASYNC_ = INIT_ONCE_ASYNC;
const DWORD_ INIT_ONCE_CHECK_ONLY_ = INIT_ONCE_CHECK_ONLY;
const DWORD_ INIT_ONCE_INIT_FAILED_ = INIT_ONCE_INIT_FAILED;
const DWORD_ INIT_ONCE_CTX_RESERVED_BITS_ = INIT_ONCE_CTX_RESERVED_BITS;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ INIT_ONCE_ASYNC_ = INIT_ONCE_ASYNC;
BOOST_CONSTEXPR_OR_CONST DWORD_ INIT_ONCE_CHECK_ONLY_ = INIT_ONCE_CHECK_ONLY;
BOOST_CONSTEXPR_OR_CONST DWORD_ INIT_ONCE_INIT_FAILED_ = INIT_ONCE_INIT_FAILED;
BOOST_CONSTEXPR_OR_CONST DWORD_ INIT_ONCE_CTX_RESERVED_BITS_ = INIT_ONCE_CTX_RESERVED_BITS;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#else // defined( BOOST_USE_WINDOWS_H )

#define BOOST_WINAPI_INIT_ONCE_STATIC_INIT {0}
<<<<<<< HEAD
const DWORD_ INIT_ONCE_ASYNC_ = 0x00000002UL;
const DWORD_ INIT_ONCE_CHECK_ONLY_ = 0x00000001UL;
const DWORD_ INIT_ONCE_INIT_FAILED_ = 0x00000004UL;
const DWORD_ INIT_ONCE_CTX_RESERVED_BITS_ = 2;

#endif // defined( BOOST_USE_WINDOWS_H )

const DWORD_ init_once_async = INIT_ONCE_ASYNC_;
const DWORD_ init_once_check_only = INIT_ONCE_CHECK_ONLY_;
const DWORD_ init_once_init_failed = INIT_ONCE_INIT_FAILED_;
const DWORD_ init_once_ctx_reserved_bits = INIT_ONCE_CTX_RESERVED_BITS_;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ INIT_ONCE_ASYNC_ = 0x00000002UL;
BOOST_CONSTEXPR_OR_CONST DWORD_ INIT_ONCE_CHECK_ONLY_ = 0x00000001UL;
BOOST_CONSTEXPR_OR_CONST DWORD_ INIT_ONCE_INIT_FAILED_ = 0x00000004UL;
BOOST_CONSTEXPR_OR_CONST DWORD_ INIT_ONCE_CTX_RESERVED_BITS_ = 2;

#endif // defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ init_once_async = INIT_ONCE_ASYNC_;
BOOST_CONSTEXPR_OR_CONST DWORD_ init_once_check_only = INIT_ONCE_CHECK_ONLY_;
BOOST_CONSTEXPR_OR_CONST DWORD_ init_once_init_failed = INIT_ONCE_INIT_FAILED_;
BOOST_CONSTEXPR_OR_CONST DWORD_ init_once_ctx_reserved_bits = INIT_ONCE_CTX_RESERVED_BITS_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

}
}

#endif // BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6

#endif // BOOST_WINAPI_INIT_ONCE_HPP_INCLUDED_