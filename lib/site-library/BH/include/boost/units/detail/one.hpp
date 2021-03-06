// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DETAIL_ONE_HPP
#define BOOST_UNITS_DETAIL_ONE_HPP

#include <boost/units/operators.hpp>

namespace boost {

namespace units {

<<<<<<< HEAD
struct one { one() {} };

// workaround for pathscale.
inline one make_one() {
    one result;
    return(result);
=======
struct one { BOOST_CONSTEXPR one() {} };

// workaround for pathscale.
inline BOOST_CONSTEXPR one make_one() {
    return(one());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

template<class T>
struct multiply_typeof_helper<one, T>
{
    typedef T type;
};

template<class T>
struct multiply_typeof_helper<T, one>
{
    typedef T type;
};

template<>
struct multiply_typeof_helper<one, one>
{
    typedef one type;
};

template<class T>
<<<<<<< HEAD
inline T operator*(const one&, const T& t)
=======
inline BOOST_CONSTEXPR T operator*(const one&, const T& t)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    return(t);
}

template<class T>
<<<<<<< HEAD
inline T operator*(const T& t, const one&)
=======
inline BOOST_CONSTEXPR T operator*(const T& t, const one&)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    return(t);
}

<<<<<<< HEAD
inline one operator*(const one&, const one&)
{
    one result;
    return(result);
=======
inline BOOST_CONSTEXPR one operator*(const one&, const one&)
{
    return(one());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

template<class T>
struct divide_typeof_helper<T, one>
{
    typedef T type;
};

template<class T>
struct divide_typeof_helper<one, T>
{
    typedef T type;
};

template<>
struct divide_typeof_helper<one, one>
{
    typedef one type;
};

template<class T>
<<<<<<< HEAD
inline T operator/(const T& t, const one&)
=======
inline BOOST_CONSTEXPR T operator/(const T& t, const one&)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    return(t);
}

template<class T>
<<<<<<< HEAD
inline T operator/(const one&, const T& t)
=======
inline BOOST_CONSTEXPR T operator/(const one&, const T& t)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    return(1/t);
}

<<<<<<< HEAD
inline one operator/(const one&, const one&)
{
    one result;
    return(result);
}

template<class T>
inline bool operator>(const boost::units::one&, const T& t) {
=======
inline BOOST_CONSTEXPR one operator/(const one&, const one&)
{
    return(one());
}

template<class T>
inline BOOST_CONSTEXPR bool operator>(const boost::units::one&, const T& t) {
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    return(1 > t);
}

template<class T>
<<<<<<< HEAD
T one_to_double(const T& t) { return t; }

inline double one_to_double(const one&) { return 1.0; }
=======
BOOST_CONSTEXPR T one_to_double(const T& t) { return t; }

inline BOOST_CONSTEXPR double one_to_double(const one&) { return 1.0; }
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

template<class T>
struct one_to_double_type { typedef T type; };

template<>
struct one_to_double_type<one> { typedef double type; };

} // namespace units

} // namespace boost

#endif
