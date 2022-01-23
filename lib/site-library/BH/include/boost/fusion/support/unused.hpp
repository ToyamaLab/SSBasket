/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
<<<<<<< HEAD
=======
    Copyright (c) 2018 Kohei Takahashi
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(BOOST_FUSION_SUPPORT_UNUSED_20070305_1038)
#define BOOST_FUSION_SUPPORT_UNUSED_20070305_1038

#include <boost/fusion/support/config.hpp>
#include <iosfwd>

<<<<<<< HEAD
#include <boost/config.hpp>
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#if defined(BOOST_MSVC)
# pragma warning(push)
# pragma warning(disable: 4522) // multiple assignment operators specified warning
#endif

#define BOOST_FUSION_UNUSED_HAS_IO

namespace boost { namespace fusion
{
    struct unused_type
    {
        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
<<<<<<< HEAD
        unused_type() BOOST_NOEXCEPT
        {
        }

        template <typename T>
        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        unused_type(T const&) BOOST_NOEXCEPT
        {
        }

        template <typename T>
        BOOST_FUSION_CONSTEXPR_THIS BOOST_FUSION_GPU_ENABLED
        unused_type const&
        operator=(T const&) const BOOST_NOEXCEPT
        {
            return *this;
        }

        template <typename T>
        BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        unused_type&
        operator=(T const&) BOOST_NOEXCEPT
        {
            return *this;
=======
        BOOST_DEFAULTED_FUNCTION(
        unused_type() BOOST_FUSION_NOEXCEPT_ON_DEFAULTED,
        {
        })

        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        BOOST_DEFAULTED_FUNCTION(
        unused_type(unused_type const&) BOOST_FUSION_NOEXCEPT_ON_DEFAULTED,
        {
        })

        template <typename T>
        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        unused_type(T const&) BOOST_NOEXCEPT
        {
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        BOOST_FUSION_CONSTEXPR_THIS BOOST_FUSION_GPU_ENABLED
        unused_type const&
        operator=(unused_type const&) const BOOST_NOEXCEPT
        {
            return *this;
        }
<<<<<<< HEAD

        BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        unused_type&
        operator=(unused_type const&) BOOST_NOEXCEPT
        {
            return *this;
        }
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    };

    BOOST_CONSTEXPR_OR_CONST unused_type unused = unused_type();

    namespace detail
    {
        struct unused_only
        {
            BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
            unused_only(unused_type const&) BOOST_NOEXCEPT {}
        };
    }

    BOOST_CONSTEXPR
    inline std::ostream& operator<<(std::ostream& out, detail::unused_only const&) BOOST_NOEXCEPT
    {
        return out;
    }

    BOOST_CONSTEXPR
    inline std::istream& operator>>(std::istream& in, unused_type&) BOOST_NOEXCEPT
    {
        return in;
    }
}}

#if defined(BOOST_MSVC)
# pragma warning(pop)
#endif

#endif
