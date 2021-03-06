/*
 * Copyright 2016 Klemens D. Morgenstern
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_JOBS_HPP_INCLUDED_
#define BOOST_WINAPI_JOBS_HPP_INCLUDED_

#include <boost/winapi/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN2K

#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/access_rights.hpp>

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if !defined( BOOST_NO_ANSI_APIS )
#if BOOST_WINAPI_PARTITION_DESKTOP
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ WINAPI CreateJobObjectA(
=======
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC CreateJobObjectA(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    ::_SECURITY_ATTRIBUTES* lpJobAttributes,
    boost::winapi::LPCSTR_ lpName);
#endif
#endif

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ WINAPI CreateJobObjectW(
    ::_SECURITY_ATTRIBUTES* lpJobAttributes,
    boost::winapi::LPCWSTR_ lpName);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI AssignProcessToJobObject(
=======
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC CreateJobObjectW(
    ::_SECURITY_ATTRIBUTES* lpJobAttributes,
    boost::winapi::LPCWSTR_ lpName);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC AssignProcessToJobObject(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::winapi::HANDLE_ hJob,
    boost::winapi::HANDLE_ hProcess);

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WINXP
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI IsProcessInJob(
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC IsProcessInJob(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::winapi::HANDLE_ ProcessHandle,
    boost::winapi::HANDLE_ JobHandle,
    boost::winapi::PBOOL_ Result);
#endif

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI TerminateJobObject(
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC TerminateJobObject(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::winapi::HANDLE_ hJob,
    boost::winapi::UINT_ uExitCode);
#endif // BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
} // extern "C"
#endif // !defined( BOOST_USE_WINDOWS_H )

// MinGW does not declare OpenJobObjectA/W in headers but exports them from libraries
#if !defined( BOOST_USE_WINDOWS_H ) || defined( BOOST_WINAPI_IS_MINGW )
extern "C" {
#if !defined( BOOST_NO_ANSI_APIS )
#if BOOST_WINAPI_PARTITION_DESKTOP
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ WINAPI OpenJobObjectA(
=======
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC OpenJobObjectA(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::winapi::DWORD_ dwDesiredAccess,
    boost::winapi::BOOL_ bInheritHandles,
    boost::winapi::LPCSTR_ lpName);
#endif
#endif

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ WINAPI OpenJobObjectW(
=======
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC OpenJobObjectW(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::winapi::DWORD_ dwDesiredAccess,
    boost::winapi::BOOL_ bInheritHandles,
    boost::winapi::LPCWSTR_ lpName);
#endif
} // extern "C"
#endif // !defined( BOOST_USE_WINDOWS_H ) || defined( BOOST_WINAPI_IS_MINGW )

namespace boost {
namespace winapi {

// MinGW does not define job constants
#if defined( BOOST_USE_WINDOWS_H ) && !defined( BOOST_WINAPI_IS_MINGW )
<<<<<<< HEAD
const DWORD_ JOB_OBJECT_ASSIGN_PROCESS_ = JOB_OBJECT_ASSIGN_PROCESS;
const DWORD_ JOB_OBJECT_SET_ATTRIBUTES_ = JOB_OBJECT_SET_ATTRIBUTES;
const DWORD_ JOB_OBJECT_QUERY_ = JOB_OBJECT_QUERY;
const DWORD_ JOB_OBJECT_TERMINATE_ = JOB_OBJECT_TERMINATE;
const DWORD_ JOB_OBJECT_SET_SECURITY_ATTRIBUTES_ = JOB_OBJECT_SET_SECURITY_ATTRIBUTES;
const DWORD_ JOB_OBJECT_ALL_ACCESS_ = JOB_OBJECT_ALL_ACCESS;
#else
const DWORD_ JOB_OBJECT_ASSIGN_PROCESS_ = 0x0001;
const DWORD_ JOB_OBJECT_SET_ATTRIBUTES_ = 0x0002;
const DWORD_ JOB_OBJECT_QUERY_ = 0x0004;
const DWORD_ JOB_OBJECT_TERMINATE_ = 0x0008;
const DWORD_ JOB_OBJECT_SET_SECURITY_ATTRIBUTES_ = 0x0010;
const DWORD_ JOB_OBJECT_ALL_ACCESS_ = (STANDARD_RIGHTS_REQUIRED_ | SYNCHRONIZE_ | 0x1F);
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_ASSIGN_PROCESS_ = JOB_OBJECT_ASSIGN_PROCESS;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_SET_ATTRIBUTES_ = JOB_OBJECT_SET_ATTRIBUTES;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_QUERY_ = JOB_OBJECT_QUERY;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_TERMINATE_ = JOB_OBJECT_TERMINATE;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_SET_SECURITY_ATTRIBUTES_ = JOB_OBJECT_SET_SECURITY_ATTRIBUTES;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_ALL_ACCESS_ = JOB_OBJECT_ALL_ACCESS;
#else
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_ASSIGN_PROCESS_ = 0x0001;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_SET_ATTRIBUTES_ = 0x0002;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_QUERY_ = 0x0004;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_TERMINATE_ = 0x0008;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_SET_SECURITY_ATTRIBUTES_ = 0x0010;
BOOST_CONSTEXPR_OR_CONST DWORD_ JOB_OBJECT_ALL_ACCESS_ = (STANDARD_RIGHTS_REQUIRED_ | SYNCHRONIZE_ | 0x1F);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif

#if BOOST_WINAPI_PARTITION_DESKTOP
#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ CreateJobObjectA(LPSECURITY_ATTRIBUTES_ lpJobAttributes, LPCSTR_ lpName)
{
    return ::CreateJobObjectA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpJobAttributes), lpName);
}

BOOST_FORCEINLINE HANDLE_ create_job_object(LPSECURITY_ATTRIBUTES_ lpJobAttributes, LPCSTR_ lpName)
{
    return ::CreateJobObjectA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpJobAttributes), lpName);
}

using ::OpenJobObjectA;

BOOST_FORCEINLINE HANDLE_ open_job_object(DWORD_ dwDesiredAccess, BOOL_ bInheritHandles, LPCSTR_ lpName)
{
    return ::OpenJobObjectA(dwDesiredAccess, bInheritHandles, lpName);
}
#endif // !defined( BOOST_NO_ANSI_APIS )
#endif // BOOST_WINAPI_PARTITION_DESKTOP

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
using ::AssignProcessToJobObject;
BOOST_FORCEINLINE HANDLE_ CreateJobObjectW(LPSECURITY_ATTRIBUTES_ lpJobAttributes, LPCWSTR_ lpName)
{
    return ::CreateJobObjectW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpJobAttributes), lpName);
}

BOOST_FORCEINLINE HANDLE_ create_job_object(LPSECURITY_ATTRIBUTES_ lpJobAttributes, LPCWSTR_ lpName)
{
    return ::CreateJobObjectW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpJobAttributes), lpName);
}

BOOST_FORCEINLINE HANDLE_ open_job_object(DWORD_ dwDesiredAccess, BOOL_ bInheritHandles, LPCWSTR_ lpName)
{
    return ::OpenJobObjectW(dwDesiredAccess, bInheritHandles, lpName);
}

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WINXP
using ::IsProcessInJob;
#endif

using ::OpenJobObjectW;
using ::TerminateJobObject;
#endif // BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

} // namespace winapi
} // namespace boost

#endif // BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN2K
#endif // BOOST_WINAPI_JOBS_HPP_INCLUDED_
