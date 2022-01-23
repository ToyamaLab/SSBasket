/*
 * Copyright 2014 Antony Polukhin
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_CRYPT_HPP_INCLUDED_
#define BOOST_WINAPI_CRYPT_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>
<<<<<<< HEAD
#include <boost/winapi/detail/cast_ptr.hpp>
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#if defined( BOOST_USE_WINDOWS_H )
// This header is not always included as part of windows.h
#include <wincrypt.h>
#endif

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
namespace boost { namespace winapi {
typedef ULONG_PTR_ HCRYPTPROV_;
}}

<<<<<<< HEAD
// Some versions of MinGW contain buggy declarations of CryptEnumProvidersA and CryptEnumProvidersW.
// We cannot detect those broken versions, and we can't include the system header because it's incomplete.
// So below we duplicate the broken declarations here and work around the problem with cast_ptr. These declarations
// will have to be removed when MinGW is fixed.
//
// @@@ Looks like mingw 5.0-dev has this fixed and possibly in a 3.2x late release as well
//     See: https://sourceforge.net/p/mingw/bugs/2263/

extern "C" {
#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
#if !defined( BOOST_NO_ANSI_APIS )
#if !defined( BOOST_WINAPI_IS_MINGW ) || !defined( UNICODE )
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
extern "C" {
#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
CryptEnumProvidersA(
    boost::winapi::DWORD_ dwIndex,
    boost::winapi::DWORD_ *pdwReserved,
    boost::winapi::DWORD_ dwFlags,
    boost::winapi::DWORD_ *pdwProvType,
    boost::winapi::LPSTR_ szProvName,
    boost::winapi::DWORD_ *pcbProvName);
<<<<<<< HEAD
#else
// Broken declaration in MinGW
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
CryptEnumProvidersA(
    boost::winapi::DWORD_ dwIndex,
    boost::winapi::DWORD_ *pdwReserved,
    boost::winapi::DWORD_ dwFlags,
    boost::winapi::DWORD_ *pdwProvType,
    boost::winapi::LPWSTR_ szProvName,
    boost::winapi::DWORD_ *pcbProvName);
#endif

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
CryptAcquireContextA(
    boost::winapi::HCRYPTPROV_ *phProv,
    boost::winapi::LPCSTR_ pszContainer,
    boost::winapi::LPCSTR_ pszProvider,
    boost::winapi::DWORD_ dwProvType,
    boost::winapi::DWORD_ dwFlags);
#endif // !defined( BOOST_NO_ANSI_APIS )

<<<<<<< HEAD
#if !defined( BOOST_WINAPI_IS_MINGW ) || defined( UNICODE )
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
CryptEnumProvidersW(
    boost::winapi::DWORD_ dwIndex,
    boost::winapi::DWORD_ *pdwReserved,
    boost::winapi::DWORD_ dwFlags,
    boost::winapi::DWORD_ *pdwProvType,
    boost::winapi::LPWSTR_ szProvName,
    boost::winapi::DWORD_ *pcbProvName);
<<<<<<< HEAD
#else
// Broken declaration in MinGW
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
CryptEnumProvidersW(
    boost::winapi::DWORD_ dwIndex,
    boost::winapi::DWORD_ *pdwReserved,
    boost::winapi::DWORD_ dwFlags,
    boost::winapi::DWORD_ *pdwProvType,
    boost::winapi::LPSTR_ szProvName,
    boost::winapi::DWORD_ *pcbProvName);
#endif

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
CryptAcquireContextW(
    boost::winapi::HCRYPTPROV_ *phProv,
    boost::winapi::LPCWSTR_ szContainer,
    boost::winapi::LPCWSTR_ szProvider,
    boost::winapi::DWORD_ dwProvType,
    boost::winapi::DWORD_ dwFlags);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
CryptGenRandom(
    boost::winapi::HCRYPTPROV_ hProv,
    boost::winapi::DWORD_ dwLen,
    boost::winapi::BYTE_ *pbBuffer);
#endif // BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
#if defined(_MSC_VER) && (_MSC_VER+0) >= 1500 && (_MSC_VER+0) < 1900 && BOOST_USE_NTDDI_VERSION < BOOST_WINAPI_NTDDI_WINXP
// Standalone MS Windows SDK 6.0A and later until 10.0 provide a different declaration of CryptReleaseContext for Windows 2000 and older.
// This is not the case for (a) MinGW and MinGW-w64, (b) MSVC 7.1 and 8, which are shipped with their own Windows SDK,
// and (c) MSVC 14.0 and later, which are used with Windows SDK 10.
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
CryptReleaseContext(
    boost::winapi::HCRYPTPROV_ hProv,
    boost::winapi::ULONG_PTR_ dwFlags);
#else
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
CryptReleaseContext(
    boost::winapi::HCRYPTPROV_ hProv,
    boost::winapi::DWORD_ dwFlags);
#endif
#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
}
#endif // !defined( BOOST_USE_WINDOWS_H )

namespace boost {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

typedef ::HCRYPTPROV HCRYPTPROV_;

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
<<<<<<< HEAD
const DWORD_ PROV_RSA_FULL_         = PROV_RSA_FULL;

const DWORD_ CRYPT_VERIFYCONTEXT_   = CRYPT_VERIFYCONTEXT;
const DWORD_ CRYPT_NEWKEYSET_       = CRYPT_NEWKEYSET;
const DWORD_ CRYPT_DELETEKEYSET_    = CRYPT_DELETEKEYSET;
const DWORD_ CRYPT_MACHINE_KEYSET_  = CRYPT_MACHINE_KEYSET;
const DWORD_ CRYPT_SILENT_          = CRYPT_SILENT;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ PROV_RSA_FULL_         = PROV_RSA_FULL;

BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_VERIFYCONTEXT_   = CRYPT_VERIFYCONTEXT;
BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_NEWKEYSET_       = CRYPT_NEWKEYSET;
BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_DELETEKEYSET_    = CRYPT_DELETEKEYSET;
BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_MACHINE_KEYSET_  = CRYPT_MACHINE_KEYSET;
BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_SILENT_          = CRYPT_SILENT;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif

#else

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
<<<<<<< HEAD
const DWORD_ PROV_RSA_FULL_         = 1;

const DWORD_ CRYPT_VERIFYCONTEXT_   = 0xF0000000;
const DWORD_ CRYPT_NEWKEYSET_       = 8;
const DWORD_ CRYPT_DELETEKEYSET_    = 16;
const DWORD_ CRYPT_MACHINE_KEYSET_  = 32;
const DWORD_ CRYPT_SILENT_          = 64;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ PROV_RSA_FULL_         = 1;

BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_VERIFYCONTEXT_   = 0xF0000000;
BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_NEWKEYSET_       = 8;
BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_DELETEKEYSET_    = 16;
BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_MACHINE_KEYSET_  = 32;
BOOST_CONSTEXPR_OR_CONST DWORD_ CRYPT_SILENT_          = 64;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif

#endif

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

#if !defined( BOOST_NO_ANSI_APIS )
<<<<<<< HEAD
using ::CryptAcquireContextA;
#endif
=======
using ::CryptEnumProvidersA;
using ::CryptAcquireContextA;
#endif
using ::CryptEnumProvidersW;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
using ::CryptAcquireContextW;
using ::CryptGenRandom;

#if !defined( BOOST_NO_ANSI_APIS )
<<<<<<< HEAD
BOOST_FORCEINLINE BOOL_ CryptEnumProvidersA(
    DWORD_ dwIndex,
    DWORD_ *pdwReserved,
    DWORD_ dwFlags,
    DWORD_ *pdwProvType,
    LPSTR_ szProvName,
    DWORD_ *pcbProvName)
{
    return ::CryptEnumProvidersA(dwIndex, pdwReserved, dwFlags, pdwProvType, winapi::detail::cast_ptr(szProvName), pcbProvName);
}

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
BOOST_FORCEINLINE BOOL_ crypt_enum_providers(
    DWORD_ dwIndex,
    DWORD_ *pdwReserved,
    DWORD_ dwFlags,
    DWORD_ *pdwProvType,
    LPSTR_ szProvName,
    DWORD_ *pcbProvName)
{
<<<<<<< HEAD
    return ::CryptEnumProvidersA(dwIndex, pdwReserved, dwFlags, pdwProvType, winapi::detail::cast_ptr(szProvName), pcbProvName);
=======
    return ::CryptEnumProvidersA(dwIndex, pdwReserved, dwFlags, pdwProvType, szProvName, pcbProvName);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

BOOST_FORCEINLINE BOOL_ crypt_acquire_context(
    HCRYPTPROV_ *phProv,
    LPCSTR_ pszContainer,
    LPCSTR_ pszProvider,
    DWORD_ dwProvType,
    DWORD_ dwFlags)
{
    return ::CryptAcquireContextA(phProv, pszContainer, pszProvider, dwProvType, dwFlags);
}
#endif

<<<<<<< HEAD
BOOST_FORCEINLINE BOOL_ CryptEnumProvidersW(
    DWORD_ dwIndex,
    DWORD_ *pdwReserved,
    DWORD_ dwFlags,
    DWORD_ *pdwProvType,
    LPWSTR_ szProvName,
    DWORD_ *pcbProvName)
{
    return ::CryptEnumProvidersW(dwIndex, pdwReserved, dwFlags, pdwProvType, winapi::detail::cast_ptr(szProvName), pcbProvName);
}

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
BOOST_FORCEINLINE BOOL_ crypt_enum_providers(
    DWORD_ dwIndex,
    DWORD_ *pdwReserved,
    DWORD_ dwFlags,
    DWORD_ *pdwProvType,
    LPWSTR_ szProvName,
    DWORD_ *pcbProvName)
{
<<<<<<< HEAD
    return ::CryptEnumProvidersW(dwIndex, pdwReserved, dwFlags, pdwProvType, winapi::detail::cast_ptr(szProvName), pcbProvName);
=======
    return ::CryptEnumProvidersW(dwIndex, pdwReserved, dwFlags, pdwProvType, szProvName, pcbProvName);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

BOOST_FORCEINLINE BOOL_ crypt_acquire_context(
    HCRYPTPROV_ *phProv,
    LPCWSTR_ szContainer,
    LPCWSTR_ szProvider,
    DWORD_ dwProvType,
    DWORD_ dwFlags)
{
    return ::CryptAcquireContextW(phProv, szContainer, szProvider, dwProvType, dwFlags);
}

#endif // BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
BOOST_FORCEINLINE BOOL_ CryptReleaseContext(HCRYPTPROV_ hProv, DWORD_ dwFlags)
{
    return ::CryptReleaseContext(hProv, dwFlags);
}
#endif

}
}

#endif // BOOST_WINAPI_CRYPT_HPP_INCLUDED_
