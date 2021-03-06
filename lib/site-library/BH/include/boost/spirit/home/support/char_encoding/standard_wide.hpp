/*=============================================================================
    Copyright (c) 2001-2011 Hartmut Kaiser
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(BOOST_SPIRIT_STANDARD_WIDE_NOVEMBER_10_2006_0913AM)
#define BOOST_SPIRIT_STANDARD_WIDE_NOVEMBER_10_2006_0913AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <cwctype>
#include <string>

<<<<<<< HEAD
=======
#include <boost/assert.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/cstdint.hpp>
#include <boost/spirit/home/support/assert_msg.hpp>

namespace boost { namespace spirit { namespace traits
{
    template <std::size_t N>
    struct wchar_t_size
    {
        BOOST_SPIRIT_ASSERT_MSG(N == 1 || N == 2 || N == 4,
            not_supported_size_of_wchar_t, ());
    };

    template <> struct wchar_t_size<1> { enum { mask = 0xff }; };
    template <> struct wchar_t_size<2> { enum { mask = 0xffff }; };
    template <> struct wchar_t_size<4> { enum { mask = 0xffffffff }; };

}}}

namespace boost { namespace spirit { namespace char_encoding
{
    ///////////////////////////////////////////////////////////////////////////
    //  Test characters for specified conditions (using std wchar_t functions)
    ///////////////////////////////////////////////////////////////////////////

    struct standard_wide
    {
        typedef wchar_t char_type;
<<<<<<< HEAD
=======
        typedef wchar_t classify_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

        template <typename Char>
        static typename std::char_traits<Char>::int_type
        to_int_type(Char ch)
        {
            return std::char_traits<Char>::to_int_type(ch);
        }

        template <typename Char>
        static Char
        to_char_type(typename std::char_traits<Char>::int_type ch)
        {
            return std::char_traits<Char>::to_char_type(ch);
        }

        static bool
        ischar(int ch)
        {
<<<<<<< HEAD
            // we have to watch out for sign extensions (casting is there to 
            // silence certain compilers complaining about signed/unsigned
            // mismatch)
            return (
                std::size_t(0) == 
                    std::size_t(ch & ~traits::wchar_t_size<sizeof(wchar_t)>::mask) || 
                std::size_t(~0) == 
                    std::size_t(ch | traits::wchar_t_size<sizeof(wchar_t)>::mask)
            ) ? true : false;     // any wchar_t, but no other bits set
=======
            // we have to watch out for sign extensions (casting is there to
            // silence certain compilers complaining about signed/unsigned
            // mismatch)
            return (
                std::size_t(0) ==
                    std::size_t(ch & ~traits::wchar_t_size<sizeof(wchar_t)>::mask) ||
                std::size_t(~0) ==
                    std::size_t(ch | traits::wchar_t_size<sizeof(wchar_t)>::mask)
            ) != 0;     // any wchar_t, but no other bits set
        }

        // *** Note on assertions: The precondition is that the calls to
        // these functions do not violate the required range of ch (type int)
        // which is that strict_ischar(ch) should be true. It is the
        // responsibility of the caller to make sure this precondition is not
        // violated.

        static bool
        strict_ischar(int ch)
        {
            // ch should be representable as a wchar_t
            return ch >= WCHAR_MIN && ch <= WCHAR_MAX;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        isalnum(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswalnum(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswalnum(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        isalpha(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswalpha(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswalpha(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        iscntrl(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswcntrl(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswcntrl(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        isdigit(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswdigit(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswdigit(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        isgraph(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswgraph(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswgraph(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        islower(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswlower(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswlower(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        isprint(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswprint(to_int_type(ch)) ? true : false;
=======
            return iswprint(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        ispunct(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswpunct(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswpunct(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        isspace(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswspace(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswspace(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        isupper(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswupper(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswupper(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        isxdigit(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
            return iswxdigit(to_int_type(ch)) ? true : false;
=======
            BOOST_ASSERT(strict_ischar(ch));
            return iswxdigit(to_int_type(ch)) != 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        static bool
        isblank BOOST_PREVENT_MACRO_SUBSTITUTION (wchar_t ch)
        {
<<<<<<< HEAD
=======
            BOOST_ASSERT(strict_ischar(ch));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            return (ch == L' ' || ch == L'\t');
        }

        ///////////////////////////////////////////////////////////////////////
        //  Simple character conversions
        ///////////////////////////////////////////////////////////////////////

        static wchar_t
        tolower(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
=======
            BOOST_ASSERT(strict_ischar(ch));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            return isupper(ch) ?
                to_char_type<wchar_t>(towlower(to_int_type(ch))) : ch;
        }

        static wchar_t
        toupper(wchar_t ch)
        {
            using namespace std;
<<<<<<< HEAD
=======
            BOOST_ASSERT(strict_ischar(ch));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            return islower(ch) ?
                to_char_type<wchar_t>(towupper(to_int_type(ch))) : ch;
        }

        static ::boost::uint32_t
        toucs4(int ch)
        {
<<<<<<< HEAD
=======
            BOOST_ASSERT(strict_ischar(ch));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            return ch;
        }
    };
}}}

#endif
<<<<<<< HEAD

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
