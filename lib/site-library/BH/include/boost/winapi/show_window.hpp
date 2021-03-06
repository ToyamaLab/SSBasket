/*
 * Copyright 2016 Klemens D. Morgenstern
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_SHOW_WINDOW_HPP_INCLUDED_
#define BOOST_WINAPI_SHOW_WINDOW_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_DESKTOP

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
BOOST_WINAPI_DETAIL_DECLARE_HANDLE(HWND);

<<<<<<< HEAD
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI ShowWindow(
    HWND hWnd,
    int nCmdShow);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI ShowWindowAsync(
=======
BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC ShowWindow(
    HWND hWnd,
    int nCmdShow);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC ShowWindowAsync(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    HWND hWnd,
    int nCmdShow);
} // extern "C"
#endif // BOOST_USE_WINDOWS_H

namespace boost {
namespace winapi {

typedef ::HWND HWND_;
using ::ShowWindow;
using ::ShowWindowAsync;

#if defined( BOOST_USE_WINDOWS_H ) && !defined( NOSHOWWINDOW )

<<<<<<< HEAD
const DWORD_ SW_HIDE_             = SW_HIDE;
const DWORD_ SW_SHOWNORMAL_       = SW_SHOWNORMAL;
const DWORD_ SW_NORMAL_           = SW_NORMAL;
const DWORD_ SW_SHOWMINIMIZED_    = SW_SHOWMINIMIZED;
const DWORD_ SW_SHOWMAXIMIZED_    = SW_SHOWMAXIMIZED;
const DWORD_ SW_MAXIMIZE_         = SW_MAXIMIZE;
const DWORD_ SW_SHOWNOACTIVATE_   = SW_SHOWNOACTIVATE;
const DWORD_ SW_SHOW_             = SW_SHOW;
const DWORD_ SW_MINIMIZE_         = SW_MINIMIZE;
const DWORD_ SW_SHOWMINNOACTIVE_  = SW_SHOWMINNOACTIVE;
const DWORD_ SW_SHOWNA_           = SW_SHOWNA;
const DWORD_ SW_RESTORE_          = SW_RESTORE;
const DWORD_ SW_SHOWDEFAULT_      = SW_SHOWDEFAULT;
const DWORD_ SW_FORCEMINIMIZE_    = SW_FORCEMINIMIZE;
const DWORD_ SW_MAX_              = SW_MAX;
const DWORD_ HIDE_WINDOW_         = HIDE_WINDOW;
const DWORD_ SHOW_OPENWINDOW_     = SHOW_OPENWINDOW;
const DWORD_ SHOW_ICONWINDOW_     = SHOW_ICONWINDOW;
const DWORD_ SHOW_FULLSCREEN_     = SHOW_FULLSCREEN;
const DWORD_ SHOW_OPENNOACTIVATE_ = SHOW_OPENNOACTIVATE;
const DWORD_ SW_PARENTCLOSING_    = SW_PARENTCLOSING;
const DWORD_ SW_OTHERZOOM_        = SW_OTHERZOOM;
const DWORD_ SW_PARENTOPENING_    = SW_PARENTOPENING;
const DWORD_ SW_OTHERUNZOOM_      = SW_OTHERUNZOOM;

#else

const DWORD_ SW_HIDE_             = 0;
const DWORD_ SW_SHOWNORMAL_       = 1;
const DWORD_ SW_NORMAL_           = 1;
const DWORD_ SW_SHOWMINIMIZED_    = 2;
const DWORD_ SW_SHOWMAXIMIZED_    = 3;
const DWORD_ SW_MAXIMIZE_         = 3;
const DWORD_ SW_SHOWNOACTIVATE_   = 4;
const DWORD_ SW_SHOW_             = 5;
const DWORD_ SW_MINIMIZE_         = 6;
const DWORD_ SW_SHOWMINNOACTIVE_  = 7;
const DWORD_ SW_SHOWNA_           = 8;
const DWORD_ SW_RESTORE_          = 9;
const DWORD_ SW_SHOWDEFAULT_      = 10;
const DWORD_ SW_FORCEMINIMIZE_    = 11;
const DWORD_ SW_MAX_              = 11;
const DWORD_ HIDE_WINDOW_         = 0;
const DWORD_ SHOW_OPENWINDOW_     = 1;
const DWORD_ SHOW_ICONWINDOW_     = 2;
const DWORD_ SHOW_FULLSCREEN_     = 3;
const DWORD_ SHOW_OPENNOACTIVATE_ = 4;
const DWORD_ SW_PARENTCLOSING_    = 1;
const DWORD_ SW_OTHERZOOM_        = 2;
const DWORD_ SW_PARENTOPENING_    = 3;
const DWORD_ SW_OTHERUNZOOM_      = 4;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_HIDE_             = SW_HIDE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWNORMAL_       = SW_SHOWNORMAL;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_NORMAL_           = SW_NORMAL;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWMINIMIZED_    = SW_SHOWMINIMIZED;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWMAXIMIZED_    = SW_SHOWMAXIMIZED;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_MAXIMIZE_         = SW_MAXIMIZE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWNOACTIVATE_   = SW_SHOWNOACTIVATE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOW_             = SW_SHOW;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_MINIMIZE_         = SW_MINIMIZE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWMINNOACTIVE_  = SW_SHOWMINNOACTIVE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWNA_           = SW_SHOWNA;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_RESTORE_          = SW_RESTORE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWDEFAULT_      = SW_SHOWDEFAULT;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_FORCEMINIMIZE_    = SW_FORCEMINIMIZE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_MAX_              = SW_MAX;
BOOST_CONSTEXPR_OR_CONST DWORD_ HIDE_WINDOW_         = HIDE_WINDOW;
BOOST_CONSTEXPR_OR_CONST DWORD_ SHOW_OPENWINDOW_     = SHOW_OPENWINDOW;
BOOST_CONSTEXPR_OR_CONST DWORD_ SHOW_ICONWINDOW_     = SHOW_ICONWINDOW;
BOOST_CONSTEXPR_OR_CONST DWORD_ SHOW_FULLSCREEN_     = SHOW_FULLSCREEN;
BOOST_CONSTEXPR_OR_CONST DWORD_ SHOW_OPENNOACTIVATE_ = SHOW_OPENNOACTIVATE;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_PARENTCLOSING_    = SW_PARENTCLOSING;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_OTHERZOOM_        = SW_OTHERZOOM;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_PARENTOPENING_    = SW_PARENTOPENING;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_OTHERUNZOOM_      = SW_OTHERUNZOOM;

#else

BOOST_CONSTEXPR_OR_CONST DWORD_ SW_HIDE_             = 0;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWNORMAL_       = 1;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_NORMAL_           = 1;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWMINIMIZED_    = 2;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWMAXIMIZED_    = 3;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_MAXIMIZE_         = 3;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWNOACTIVATE_   = 4;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOW_             = 5;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_MINIMIZE_         = 6;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWMINNOACTIVE_  = 7;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWNA_           = 8;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_RESTORE_          = 9;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_SHOWDEFAULT_      = 10;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_FORCEMINIMIZE_    = 11;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_MAX_              = 11;
BOOST_CONSTEXPR_OR_CONST DWORD_ HIDE_WINDOW_         = 0;
BOOST_CONSTEXPR_OR_CONST DWORD_ SHOW_OPENWINDOW_     = 1;
BOOST_CONSTEXPR_OR_CONST DWORD_ SHOW_ICONWINDOW_     = 2;
BOOST_CONSTEXPR_OR_CONST DWORD_ SHOW_FULLSCREEN_     = 3;
BOOST_CONSTEXPR_OR_CONST DWORD_ SHOW_OPENNOACTIVATE_ = 4;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_PARENTCLOSING_    = 1;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_OTHERZOOM_        = 2;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_PARENTOPENING_    = 3;
BOOST_CONSTEXPR_OR_CONST DWORD_ SW_OTHERUNZOOM_      = 4;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#endif

}
}

#endif // BOOST_WINAPI_PARTITION_DESKTOP

#endif // BOOST_WINAPI_SHOW_WINDOW_HPP_INCLUDED_
