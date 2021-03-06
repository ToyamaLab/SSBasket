/*=============================================================================
    Copyright (c) 2001-2014 Joel de Guzman
    Copyright (c) 2001-2011 Hartmut Kaiser
    http://spirit.sourceforge.net/

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
<<<<<<< HEAD
#if !defined(SPIRIT_EXTRACT_REAL_APRIL_18_2006_0901AM)
#define SPIRIT_EXTRACT_REAL_APRIL_18_2006_0901AM
=======
#if !defined(BOOST_SPIRIT_X3_EXTRACT_REAL_APRIL_18_2006_0901AM)
#define BOOST_SPIRIT_X3_EXTRACT_REAL_APRIL_18_2006_0901AM
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#include <cmath>
#include <boost/limits.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/spirit/home/x3/support/unused.hpp>
#include <boost/spirit/home/x3/support/numeric_utils/pow10.hpp>
#include <boost/spirit/home/x3/support/numeric_utils/sign.hpp>
#include <boost/spirit/home/x3/support/traits/move_to.hpp>
#include <boost/assert.hpp>

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400)
# pragma warning(push)
# pragma warning(disable: 4100)   // 'p': unreferenced formal parameter
# pragma warning(disable: 4127)   // conditional expression is constant
#endif

namespace boost { namespace spirit { namespace x3 { namespace extension
{
    using x3::traits::pow10;

    template <typename T>
<<<<<<< HEAD
    inline void
    scale(int exp, T& n)
    {
        if (exp >= 0)
        {
            // $$$ Why is this failing for boost.math.concepts ? $$$
            //~ int nn = std::numeric_limits<T>::max_exponent10;
            //~ BOOST_ASSERT(exp <= std::numeric_limits<T>::max_exponent10);
=======
    inline bool
    scale(int exp, T& n)
    {
        constexpr auto max_exp = std::numeric_limits<T>::max_exponent10;
        constexpr auto min_exp = std::numeric_limits<T>::min_exponent10;

        if (exp >= 0)
        {
            // return false if exp exceeds the max_exp
            // do this check only for primitive types!
            if (is_floating_point<T>() && exp > max_exp)
                return false;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            n *= pow10<T>(exp);
        }
        else
        {
<<<<<<< HEAD
            if (exp < std::numeric_limits<T>::min_exponent10)
            {
                n /= pow10<T>(-std::numeric_limits<T>::min_exponent10);
                n /= pow10<T>(-exp + std::numeric_limits<T>::min_exponent10);
=======
            if (exp < min_exp)
            {
                n /= pow10<T>(-min_exp);

                // return false if exp still exceeds the min_exp
                // do this check only for primitive types!
                exp += -min_exp;
                if (is_floating_point<T>() && exp < min_exp)
                    return false;

                n /= pow10<T>(-exp);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }
            else
            {
                n /= pow10<T>(-exp);
            }
        }
<<<<<<< HEAD
    }

    inline void
    scale(int /*exp*/, unused_type /*n*/)
    {
        // no-op for unused_type
    }

    template <typename T>
    inline void
    scale(int exp, int frac, T& n)
    {
        scale(exp - frac, n);
    }

    inline void
    scale(int /*exp*/, int /*frac*/, unused_type /*n*/)
    {
        // no-op for unused_type
=======
        return true;
    }

    inline bool
    scale(int /*exp*/, unused_type /*n*/)
    {
        // no-op for unused_type
        return true;
    }

    template <typename T>
    inline bool
    scale(int exp, int frac, T& n)
    {
        return scale(exp - frac, n);
    }

    inline bool
    scale(int /*exp*/, int /*frac*/, unused_type /*n*/)
    {
        // no-op for unused_type
        return true;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }

    inline float
    negate(bool neg, float n)
    {
        return neg ? x3::changesign(n) : n;
    }

    inline double
    negate(bool neg, double n)
    {
        return neg ? x3::changesign(n) : n;
    }

    inline long double
    negate(bool neg, long double n)
    {
        return neg ? x3::changesign(n) : n;
    }

    template <typename T>
    inline T
    negate(bool neg, T const& n)
    {
        return neg ? -n : n;
    }

    inline unused_type
    negate(bool /*neg*/, unused_type n)
    {
        // no-op for unused_type
        return n;
    }
<<<<<<< HEAD

    template <typename T>
    inline bool
    is_equal_to_one(T const& value)
    {
        return value == 1.0;
    }

    inline bool
    is_equal_to_one(unused_type)
    {
        // no-op for unused_type
        return false;
    }
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}}}}

namespace boost { namespace spirit { namespace x3
{
    template <typename T, typename RealPolicies>
    struct extract_real
    {
        template <typename Iterator, typename Attribute>
        static bool
        parse(Iterator& first, Iterator const& last, Attribute& attr,
            RealPolicies const& p)
        {
            if (first == last)
                return false;
            Iterator save = first;

            // Start by parsing the sign. neg will be true if
            // we got a "-" sign, false otherwise.
            bool neg = p.parse_sign(first, last);

            // Now attempt to parse an integer
            T n = 0;
            bool got_a_number = p.parse_n(first, last, n);

            // If we did not get a number it might be a NaN, Inf or a leading
            // dot.
            if (!got_a_number)
            {
                // Check whether the number to parse is a NaN or Inf
                if (p.parse_nan(first, last, n) ||
                    p.parse_inf(first, last, n))
                {
                    // If we got a negative sign, negate the number
                    traits::move_to(extension::negate(neg, n), attr);
                    return true;    // got a NaN or Inf, return early
                }

                // If we did not get a number and our policies do not
                // allow a leading dot, fail and return early (no-match)
                if (!p.allow_leading_dot)
                {
                    first = save;
                    return false;
                }
            }

            bool e_hit = false;
<<<<<<< HEAD
=======
            Iterator e_pos;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            int frac_digits = 0;

            // Try to parse the dot ('.' decimal point)
            if (p.parse_dot(first, last))
            {
                // We got the decimal point. Now we will try to parse
                // the fraction if it is there. If not, it defaults
                // to zero (0) only if we already got a number.
                Iterator savef = first;
                if (p.parse_frac_n(first, last, n))
                {
                    // Optimization note: don't compute frac_digits if T is
                    // an unused_type. This should be optimized away by the compiler.
                    if (!is_same<T, unused_type>::value)
                        frac_digits =
                            static_cast<int>(std::distance(savef, first));
<<<<<<< HEAD
=======
                    BOOST_ASSERT(frac_digits >= 0);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                }
                else if (!got_a_number || !p.allow_trailing_dot)
                {
                    // We did not get a fraction. If we still haven't got a
                    // number and our policies do not allow a trailing dot,
                    // return no-match.
                    first = save;
                    return false;
                }

                // Now, let's see if we can parse the exponent prefix
<<<<<<< HEAD
=======
                e_pos = first;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                e_hit = p.parse_exp(first, last);
            }
            else
            {
                // No dot and no number! Return no-match.
                if (!got_a_number)
                {
                    first = save;
                    return false;
                }

                // If we must expect a dot and we didn't see an exponent
                // prefix, return no-match.
<<<<<<< HEAD
=======
                e_pos = first;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                e_hit = p.parse_exp(first, last);
                if (p.expect_dot && !e_hit)
                {
                    first = save;
                    return false;
                }
            }

            if (e_hit)
            {
                // We got the exponent prefix. Now we will try to parse the
                // actual exponent. It is an error if it is not there.
                int exp = 0;
                if (p.parse_exp_n(first, last, exp))
                {
                    // Got the exponent value. Scale the number by
                    // exp-frac_digits.
<<<<<<< HEAD
                    extension::scale(exp, frac_digits, n);
                }
                else
                {
                    // Oops, no exponent, return no-match.
                    first = save;
                    return false;
=======
                    if (!extension::scale(exp, frac_digits, n))
                        return false;
                }
                else
                {
                    // If there is no number, disregard the exponent altogether.
                    // by resetting 'first' prior to the exponent prefix (e|E)
                    first = e_pos;

                    // Scale the number by -frac_digits.
                    if (!extension::scale(-frac_digits, n))
                        return false;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                }
            }
            else if (frac_digits)
            {
                // No exponent found. Scale the number by -frac_digits.
<<<<<<< HEAD
                extension::scale(-frac_digits, n);
            }
            else if (extension::is_equal_to_one(n))
            {
                // There is a chance of having to parse one of the 1.0#...
                // styles some implementations use for representing NaN or Inf.

                // Check whether the number to parse is a NaN or Inf
                if (p.parse_nan(first, last, n) ||
                    p.parse_inf(first, last, n))
                {
                    // If we got a negative sign, negate the number
                    traits::move_to(extension::negate(neg, n), attr);
                    return true;    // got a NaN or Inf, return immediately
                }
=======
                if (!extension::scale(-frac_digits, n))
                    return false;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }

            // If we got a negative sign, negate the number
            traits::move_to(extension::negate(neg, n), attr);

            // Success!!!
            return true;
        }
    };

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400)
# pragma warning(pop)
#endif

}}}

#endif
