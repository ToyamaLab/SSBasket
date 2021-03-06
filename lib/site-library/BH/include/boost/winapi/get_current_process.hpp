/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_GET_CURRENT_PROCESS_HPP_INCLUDED_
#define BOOST_WINAPI_GET_CURRENT_PROCESS_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

// Windows CE define GetCurrentProcess as an inline function in kfuncs.h
#if !defined( BOOST_USE_WINDOWS_H ) && !defined( UNDER_CE )
extern "C" {
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ WINAPI GetCurrentProcess(BOOST_WINAPI_DETAIL_VOID);
=======
BOOST_SYMBOL_IMPORT boost::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC GetCurrentProcess(BOOST_WINAPI_DETAIL_VOID);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
#endif

namespace boost {
namespace winapi {
using ::GetCurrentProcess;
}
}

#endif // BOOST_WINAPI_GET_CURRENT_PROCESS_HPP_INCLUDED_
