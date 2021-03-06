/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 * Copyright 2016 Jorge Lodos
 * Copyright 2017 James E. King, III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_FILE_MAPPING_HPP_INCLUDED_
#define BOOST_WINAPI_FILE_MAPPING_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

/*
 * UWP:
 * API                SDK 8     SDK 10
 * CreateFileMapping  DESKTOP - DESKTOP | SYSTEM
 * FlushViewOfFile    APP     - APP     | SYSTEM
 * MapViewOfFile      DESKTOP - DESKTOP | SYSTEM
 * MapViewOfFileEx    DESKTOP - DESKTOP | SYSTEM
 * OpenFileMapping    DESKTOP - DESKTOP | SYSTEM
 * UnmapViewOfFile    APP     - APP     | SYSTEM
 */

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

#if BOOST_WINAPI_PARTITION_DESKTOP
#if !defined( BOOST_NO_ANSI_APIS )
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
CreateFileMappingA(
    boost::winapi::HANDLE_ hFile,
    ::_SECURITY_ATTRIBUTES* lpFileMappingAttributes,
    boost::winapi::DWORD_ flProtect,
    boost::winapi::DWORD_ dwMaximumSizeHigh,
    boost::winapi::DWORD_ dwMaximumSizeLow,
    boost::winapi::LPCSTR_ lpName);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
OpenFileMappingA(
    boost::winapi::DWORD_ dwDesiredAccess,
    boost::winapi::BOOL_ bInheritHandle,
    boost::winapi::LPCSTR_ lpName);
#endif // !defined( BOOST_NO_ANSI_APIS )
#endif // BOOST_WINAPI_PARTITION_DESKTOP

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
CreateFileMappingW(
    boost::winapi::HANDLE_ hFile,
    ::_SECURITY_ATTRIBUTES* lpFileMappingAttributes,
    boost::winapi::DWORD_ flProtect,
    boost::winapi::DWORD_ dwMaximumSizeHigh,
    boost::winapi::DWORD_ dwMaximumSizeLow,
    boost::winapi::LPCWSTR_ lpName);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::LPVOID_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::LPVOID_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
MapViewOfFile(
    boost::winapi::HANDLE_ hFileMappingObject,
    boost::winapi::DWORD_ dwDesiredAccess,
    boost::winapi::DWORD_ dwFileOffsetHigh,
    boost::winapi::DWORD_ dwFileOffsetLow,
    boost::winapi::SIZE_T_ dwNumberOfBytesToMap);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::LPVOID_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::LPVOID_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
MapViewOfFileEx(
    boost::winapi::HANDLE_ hFileMappingObject,
    boost::winapi::DWORD_ dwDesiredAccess,
    boost::winapi::DWORD_ dwFileOffsetHigh,
    boost::winapi::DWORD_ dwFileOffsetLow,
    boost::winapi::SIZE_T_ dwNumberOfBytesToMap,
    boost::winapi::LPVOID_ lpBaseAddress);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
OpenFileMappingW(
    boost::winapi::DWORD_ dwDesiredAccess,
    boost::winapi::BOOL_ bInheritHandle,
    boost::winapi::LPCWSTR_ lpName);
#endif // BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

#if BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
FlushViewOfFile(
    boost::winapi::LPCVOID_ lpBaseAddress,
    boost::winapi::SIZE_T_ dwNumberOfBytesToFlush);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
UnmapViewOfFile(boost::winapi::LPCVOID_ lpBaseAddress);
#endif // BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM

} // extern "C"
#endif // !defined( BOOST_USE_WINDOWS_H )

namespace boost {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

<<<<<<< HEAD
const DWORD_ SEC_FILE_ = SEC_FILE;
const DWORD_ SEC_IMAGE_ = SEC_IMAGE;
const DWORD_ SEC_RESERVE_ = SEC_RESERVE;
const DWORD_ SEC_COMMIT_ = SEC_COMMIT;
const DWORD_ SEC_NOCACHE_ = SEC_NOCACHE;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_FILE_ = SEC_FILE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_IMAGE_ = SEC_IMAGE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_RESERVE_ = SEC_RESERVE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_COMMIT_ = SEC_COMMIT;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_NOCACHE_ = SEC_NOCACHE;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// These permission flags are undocumented and some of them are equivalent to the FILE_MAP_* flags.
// SECTION_QUERY enables NtQuerySection.
// http://undocumented.ntinternals.net/index.html?page=UserMode%2FUndocumented%20Functions%2FNT%20Objects%2FSection%2FNtQuerySection.html
<<<<<<< HEAD
const DWORD_ SECTION_QUERY_ = SECTION_QUERY;
const DWORD_ SECTION_MAP_WRITE_ = SECTION_MAP_WRITE;
const DWORD_ SECTION_MAP_READ_ = SECTION_MAP_READ;
const DWORD_ SECTION_MAP_EXECUTE_ = SECTION_MAP_EXECUTE;
const DWORD_ SECTION_EXTEND_SIZE_ = SECTION_EXTEND_SIZE;
const DWORD_ SECTION_ALL_ACCESS_ = SECTION_ALL_ACCESS;

const DWORD_ FILE_MAP_COPY_ = FILE_MAP_COPY;
const DWORD_ FILE_MAP_WRITE_ = FILE_MAP_WRITE;
const DWORD_ FILE_MAP_READ_ = FILE_MAP_READ;
const DWORD_ FILE_MAP_ALL_ACCESS_ = FILE_MAP_ALL_ACCESS;

#else // defined( BOOST_USE_WINDOWS_H )

const DWORD_ SEC_FILE_ = 0x800000;
const DWORD_ SEC_IMAGE_ = 0x1000000;
const DWORD_ SEC_RESERVE_ = 0x4000000;
const DWORD_ SEC_COMMIT_ = 0x8000000;
const DWORD_ SEC_NOCACHE_ = 0x10000000;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_QUERY_ = SECTION_QUERY;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_MAP_WRITE_ = SECTION_MAP_WRITE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_MAP_READ_ = SECTION_MAP_READ;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_MAP_EXECUTE_ = SECTION_MAP_EXECUTE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_EXTEND_SIZE_ = SECTION_EXTEND_SIZE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_ALL_ACCESS_ = SECTION_ALL_ACCESS;

BOOST_CONSTEXPR_OR_CONST DWORD_ FILE_MAP_COPY_ = FILE_MAP_COPY;
BOOST_CONSTEXPR_OR_CONST DWORD_ FILE_MAP_WRITE_ = FILE_MAP_WRITE;
BOOST_CONSTEXPR_OR_CONST DWORD_ FILE_MAP_READ_ = FILE_MAP_READ;
BOOST_CONSTEXPR_OR_CONST DWORD_ FILE_MAP_ALL_ACCESS_ = FILE_MAP_ALL_ACCESS;

#else // defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_FILE_ = 0x800000;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_IMAGE_ = 0x1000000;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_RESERVE_ = 0x4000000;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_COMMIT_ = 0x8000000;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_NOCACHE_ = 0x10000000;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// These permission flags are undocumented and some of them are equivalent to the FILE_MAP_* flags.
// SECTION_QUERY enables NtQuerySection.
// http://undocumented.ntinternals.net/index.html?page=UserMode%2FUndocumented%20Functions%2FNT%20Objects%2FSection%2FNtQuerySection.html
<<<<<<< HEAD
const DWORD_ SECTION_QUERY_ = 0x00000001;
const DWORD_ SECTION_MAP_WRITE_ = 0x00000002;
const DWORD_ SECTION_MAP_READ_ = 0x00000004;
const DWORD_ SECTION_MAP_EXECUTE_ = 0x00000008;
const DWORD_ SECTION_EXTEND_SIZE_ = 0x00000010;
const DWORD_ SECTION_ALL_ACCESS_ = 0x000F001F; // STANDARD_RIGHTS_REQUIRED | SECTION_*

const DWORD_ FILE_MAP_COPY_ = SECTION_QUERY_;
const DWORD_ FILE_MAP_WRITE_ = SECTION_MAP_WRITE_;
const DWORD_ FILE_MAP_READ_ = SECTION_MAP_READ_;
const DWORD_ FILE_MAP_ALL_ACCESS_ = SECTION_ALL_ACCESS_;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_QUERY_ = 0x00000001;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_MAP_WRITE_ = 0x00000002;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_MAP_READ_ = 0x00000004;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_MAP_EXECUTE_ = 0x00000008;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_EXTEND_SIZE_ = 0x00000010;
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_ALL_ACCESS_ = 0x000F001F; // STANDARD_RIGHTS_REQUIRED | SECTION_*

BOOST_CONSTEXPR_OR_CONST DWORD_ FILE_MAP_COPY_ = SECTION_QUERY_;
BOOST_CONSTEXPR_OR_CONST DWORD_ FILE_MAP_WRITE_ = SECTION_MAP_WRITE_;
BOOST_CONSTEXPR_OR_CONST DWORD_ FILE_MAP_READ_ = SECTION_MAP_READ_;
BOOST_CONSTEXPR_OR_CONST DWORD_ FILE_MAP_ALL_ACCESS_ = SECTION_ALL_ACCESS_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#endif // defined( BOOST_USE_WINDOWS_H )

// These constants are not defined in Windows SDK up until the one shipped with MSVC 8 and MinGW (as of 2016-02-14)
<<<<<<< HEAD
const DWORD_ SECTION_MAP_EXECUTE_EXPLICIT_ = 0x00000020; // not included in SECTION_ALL_ACCESS
const DWORD_ FILE_MAP_EXECUTE_ = SECTION_MAP_EXECUTE_EXPLICIT_; // not included in FILE_MAP_ALL_ACCESS

// These constants are not defined in Windows SDK up until 6.0A and MinGW (as of 2016-02-14)
const DWORD_ SEC_PROTECTED_IMAGE_ = 0x2000000;
const DWORD_ SEC_WRITECOMBINE_ = 0x40000000;
const DWORD_ SEC_LARGE_PAGES_ = 0x80000000;
const DWORD_ SEC_IMAGE_NO_EXECUTE_ = (SEC_IMAGE_ | SEC_NOCACHE_);
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ SECTION_MAP_EXECUTE_EXPLICIT_ = 0x00000020; // not included in SECTION_ALL_ACCESS
BOOST_CONSTEXPR_OR_CONST DWORD_ FILE_MAP_EXECUTE_ = SECTION_MAP_EXECUTE_EXPLICIT_; // not included in FILE_MAP_ALL_ACCESS

// These constants are not defined in Windows SDK up until 6.0A and MinGW (as of 2016-02-14)
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_PROTECTED_IMAGE_ = 0x2000000;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_WRITECOMBINE_ = 0x40000000;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_LARGE_PAGES_ = 0x80000000;
BOOST_CONSTEXPR_OR_CONST DWORD_ SEC_IMAGE_NO_EXECUTE_ = (SEC_IMAGE_ | SEC_NOCACHE_);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#if BOOST_WINAPI_PARTITION_DESKTOP
#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ CreateFileMappingA(
    HANDLE_ hFile,
    SECURITY_ATTRIBUTES_* lpFileMappingAttributes,
    DWORD_ flProtect,
    DWORD_ dwMaximumSizeHigh,
    DWORD_ dwMaximumSizeLow,
    LPCSTR_ lpName)
{
    return ::CreateFileMappingA(
        hFile,
        reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpFileMappingAttributes),
        flProtect,
        dwMaximumSizeHigh,
        dwMaximumSizeLow,
        lpName);
}

BOOST_FORCEINLINE HANDLE_ create_file_mapping(
    HANDLE_ hFile,
    SECURITY_ATTRIBUTES_* lpFileMappingAttributes,
    DWORD_ flProtect,
    DWORD_ dwMaximumSizeHigh,
    DWORD_ dwMaximumSizeLow,
    LPCSTR_ lpName)
{
    return ::CreateFileMappingA(
        hFile,
        reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpFileMappingAttributes),
        flProtect,
        dwMaximumSizeHigh,
        dwMaximumSizeLow,
        lpName);
}

using ::OpenFileMappingA;

BOOST_FORCEINLINE HANDLE_ open_file_mapping(DWORD_ dwDesiredAccess, BOOL_ bInheritHandle, LPCSTR_ lpName)
{
    return ::OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName);
}
#endif
#endif // BOOST_WINAPI_PARTITION_DESKTOP

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
BOOST_FORCEINLINE HANDLE_ CreateFileMappingW(
    HANDLE_ hFile,
    SECURITY_ATTRIBUTES_* lpFileMappingAttributes,
    DWORD_ flProtect,
    DWORD_ dwMaximumSizeHigh,
    DWORD_ dwMaximumSizeLow,
    LPCWSTR_ lpName)
{
    return ::CreateFileMappingW(
        hFile,
        reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpFileMappingAttributes),
        flProtect,
        dwMaximumSizeHigh,
        dwMaximumSizeLow,
        lpName);
}

BOOST_FORCEINLINE HANDLE_ create_file_mapping(
    HANDLE_ hFile,
    SECURITY_ATTRIBUTES_* lpFileMappingAttributes,
    DWORD_ flProtect,
    DWORD_ dwMaximumSizeHigh,
    DWORD_ dwMaximumSizeLow,
    LPCWSTR_ lpName)
{
    return ::CreateFileMappingW(
        hFile,
        reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpFileMappingAttributes),
        flProtect,
        dwMaximumSizeHigh,
        dwMaximumSizeLow,
        lpName);
}

using ::MapViewOfFile;
using ::MapViewOfFileEx;
using ::OpenFileMappingW;

BOOST_FORCEINLINE HANDLE_ open_file_mapping(DWORD_ dwDesiredAccess, BOOL_ bInheritHandle, LPCWSTR_ lpName)
{
    return ::OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName);
}
#endif // BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

#if BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM
using ::FlushViewOfFile;
using ::UnmapViewOfFile;
#endif // BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM

}
}

#endif // BOOST_WINAPI_FILE_MAPPING_HPP_INCLUDED_
