//-----------------------------------------------------------------------------
// boost blank.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_BLANK_HPP
#define BOOST_BLANK_HPP

#include "boost/blank_fwd.hpp"

#if !defined(BOOST_NO_IOSTREAM)
#include <iosfwd> // for std::basic_ostream forward declare
#include "boost/detail/templated_streams.hpp"
#endif // BOOST_NO_IOSTREAM

<<<<<<< HEAD
#include "boost/mpl/bool.hpp"
=======
#include "boost/type_traits/integral_constant.hpp"
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include "boost/type_traits/is_empty.hpp"
#include "boost/type_traits/is_pod.hpp"
#include "boost/type_traits/is_stateless.hpp"

namespace boost {

struct blank
{
};

// type traits specializations
//

template <>
struct is_pod< blank >
<<<<<<< HEAD
    : mpl::true_
=======
    : boost::true_type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
};

template <>
struct is_empty< blank >
<<<<<<< HEAD
    : mpl::true_
=======
    : boost::true_type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
};

template <>
struct is_stateless< blank >
<<<<<<< HEAD
    : mpl::true_
=======
    : boost::true_type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
};

// relational operators
//

inline bool operator==(const blank&, const blank&)
{
    return true;
}

inline bool operator<=(const blank&, const blank&)
{
    return true;
}

inline bool operator>=(const blank&, const blank&)
{
    return true;
}

inline bool operator!=(const blank&, const blank&)
{
    return false;
}

inline bool operator<(const blank&, const blank&)
{
    return false;
}

inline bool operator>(const blank&, const blank&)
{
    return false;
}

// streaming support
//
#if !defined(BOOST_NO_IOSTREAM)

BOOST_TEMPLATED_STREAM_TEMPLATE(E,T)
inline BOOST_TEMPLATED_STREAM(ostream, E,T)& operator<<(
      BOOST_TEMPLATED_STREAM(ostream, E,T)& out
    , const blank&
    )
{
    // (output nothing)
    return out;
}

#endif // BOOST_NO_IOSTREAM

} // namespace boost

#endif // BOOST_BLANK_HPP
