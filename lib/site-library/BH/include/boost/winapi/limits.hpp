/*
 * Copyright 2016 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_LIMITS_HPP_INCLUDED_
#define BOOST_WINAPI_LIMITS_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

<<<<<<< HEAD
const DWORD_ MAX_PATH_ = MAX_PATH;

#else

const DWORD_ MAX_PATH_ = 260;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ MAX_PATH_ = MAX_PATH;

#else

BOOST_CONSTEXPR_OR_CONST DWORD_ MAX_PATH_ = 260;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#endif

#if defined( BOOST_USE_WINDOWS_H ) && !defined( BOOST_WINAPI_IS_MINGW )

<<<<<<< HEAD
const DWORD_ UNICODE_STRING_MAX_BYTES_ = UNICODE_STRING_MAX_BYTES;
const DWORD_ UNICODE_STRING_MAX_CHARS_ = UNICODE_STRING_MAX_CHARS;

#else

const DWORD_ UNICODE_STRING_MAX_BYTES_ = 65534;
const DWORD_ UNICODE_STRING_MAX_CHARS_ = 32767;

#endif

const DWORD_ max_path = MAX_PATH_;
const DWORD_ unicode_string_max_bytes = UNICODE_STRING_MAX_BYTES_;
const DWORD_ unicode_string_max_chars = UNICODE_STRING_MAX_CHARS_;
=======
BOOST_CONSTEXPR_OR_CONST DWORD_ UNICODE_STRING_MAX_BYTES_ = UNICODE_STRING_MAX_BYTES;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNICODE_STRING_MAX_CHARS_ = UNICODE_STRING_MAX_CHARS;

#else

BOOST_CONSTEXPR_OR_CONST DWORD_ UNICODE_STRING_MAX_BYTES_ = 65534;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNICODE_STRING_MAX_CHARS_ = 32767;

#endif

BOOST_CONSTEXPR_OR_CONST DWORD_ max_path = MAX_PATH_;
BOOST_CONSTEXPR_OR_CONST DWORD_ unicode_string_max_bytes = UNICODE_STRING_MAX_BYTES_;
BOOST_CONSTEXPR_OR_CONST DWORD_ unicode_string_max_chars = UNICODE_STRING_MAX_CHARS_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

}
}

#endif // BOOST_WINAPI_LIMITS_HPP_INCLUDED_
