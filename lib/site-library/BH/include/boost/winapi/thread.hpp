/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_THREAD_HPP_INCLUDED_
#define BOOST_WINAPI_THREAD_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/get_current_thread.hpp>
#include <boost/winapi/get_current_thread_id.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::DWORD_ WINAPI
SleepEx(
    boost::winapi::DWORD_ dwMilliseconds,
    boost::winapi::BOOL_ bAlertable);
BOOST_SYMBOL_IMPORT boost::winapi::VOID_ WINAPI Sleep(boost::winapi::DWORD_ dwMilliseconds);
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI SwitchToThread(BOOST_WINAPI_DETAIL_VOID);
=======
BOOST_SYMBOL_IMPORT boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
SleepEx(
    boost::winapi::DWORD_ dwMilliseconds,
    boost::winapi::BOOL_ bAlertable);
BOOST_SYMBOL_IMPORT boost::winapi::VOID_ BOOST_WINAPI_WINAPI_CC Sleep(boost::winapi::DWORD_ dwMilliseconds);
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC SwitchToThread(BOOST_WINAPI_DETAIL_VOID);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
} // extern "C"
#endif

namespace boost {
namespace winapi {
using ::SleepEx;
using ::Sleep;
using ::SwitchToThread;
}
}

#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_WINAPI_THREAD_HPP_INCLUDED_
