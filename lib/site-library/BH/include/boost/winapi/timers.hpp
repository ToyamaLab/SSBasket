/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_TIMERS_HPP_INCLUDED_
#define BOOST_WINAPI_TIMERS_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
QueryPerformanceCounter(::_LARGE_INTEGER* lpPerformanceCount);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
QueryPerformanceCounter(::_LARGE_INTEGER* lpPerformanceCount);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
QueryPerformanceFrequency(::_LARGE_INTEGER* lpFrequency);
} // extern "C"
#endif


namespace boost {
namespace winapi {

BOOST_FORCEINLINE BOOL_ QueryPerformanceCounter(LARGE_INTEGER_* lpPerformanceCount)
{
    return ::QueryPerformanceCounter(reinterpret_cast< ::_LARGE_INTEGER* >(lpPerformanceCount));
}

BOOST_FORCEINLINE BOOL_ QueryPerformanceFrequency(LARGE_INTEGER_* lpFrequency)
{
    return ::QueryPerformanceFrequency(reinterpret_cast< ::_LARGE_INTEGER* >(lpFrequency));
}

}
}

#endif // BOOST_WINAPI_TIMERS_HPP_INCLUDED_
