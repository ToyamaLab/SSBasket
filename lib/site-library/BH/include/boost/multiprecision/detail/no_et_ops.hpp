///////////////////////////////////////////////////////////////////////////////
//  Copyright 2012 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MP_NO_ET_OPS_HPP
#define BOOST_MP_NO_ET_OPS_HPP

#ifdef BOOST_MSVC
#pragma warning(push)
<<<<<<< HEAD
#pragma warning(disable: 4714)
#endif

namespace boost{
namespace multiprecision{
=======
#pragma warning(disable : 4714)
#endif

namespace boost {
namespace multiprecision {
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

//
// Operators for non-expression template enabled number.
// NOTE: this is not a complete header - really just a suffix to default_ops.hpp.
// NOTE: these operators have to be defined after the methods in default_ops.hpp.
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator - (const number<B, et_off>& v)
{
   BOOST_STATIC_ASSERT_MSG(is_signed_number<B>::value, "Negating an unsigned type results in ill-defined behavior.");
   number<B, et_off> result(v);
   result.backend().negate();
   return BOOST_MP_MOVE(result);
}
template <class B>
BOOST_MP_FORCEINLINE number<B, et_off> operator ~ (const number<B, et_off>& v)
{
   number<B, et_off> result;
   eval_complement(result.backend(), v.backend());
   return BOOST_MP_MOVE(result);
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator-(const number<B, et_off>& v)
{
   BOOST_STATIC_ASSERT_MSG(is_signed_number<B>::value, "Negating an unsigned type results in ill-defined behavior.");
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(v);
   number<B, et_off>                                                    result(v);
   result.backend().negate();
   return result;
}
template <class B>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator~(const number<B, et_off>& v)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(v);
   number<B, et_off>                                                    result;
   eval_complement(result.backend(), v.backend());
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
//
// Addition:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator + (const number<B, et_off>& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_add;
   eval_add(result.backend(), a.backend(), b.backend());
   return BOOST_MP_MOVE(result);
}
template <class B, class V>
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator + (const number<B, et_off>& a, const V& b)
{
   number<B, et_off> result;
   using default_ops::eval_add;
   eval_add(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return BOOST_MP_MOVE(result);
}
template <class V, class B>
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator + (const V& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_add;
   eval_add(result.backend(), b.backend(), number<B, et_off>::canonical_value(a));
   return BOOST_MP_MOVE(result);
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator+(const number<B, et_off>& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
   number<B, et_off>                                                    result;
   using default_ops::eval_add;
   eval_add(result.backend(), a.backend(), b.backend());
   return result;
}
template <class B, class V>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator+(const number<B, et_off>& a, const V& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a);
   number<B, et_off>                                                    result;
   using default_ops::eval_add;
   eval_add(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return result;
}
template <class V, class B>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator+(const V& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(b);
   number<B, et_off>                                                    result;
   using default_ops::eval_add;
   eval_add(result.backend(), b.backend(), number<B, et_off>::canonical_value(a));
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
//
// Subtraction:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator - (const number<B, et_off>& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_subtract;
   eval_subtract(result.backend(), a.backend(), b.backend());
   return BOOST_MP_MOVE(result);
}
template <class B, class V>
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator - (const number<B, et_off>& a, const V& b)
{
   number<B, et_off> result;
   using default_ops::eval_subtract;
   eval_subtract(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return BOOST_MP_MOVE(result);
}
template <class V, class B>
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator - (const V& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_subtract;
   eval_subtract(result.backend(), number<B, et_off>::canonical_value(a), b.backend());
   return BOOST_MP_MOVE(result);
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator-(const number<B, et_off>& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
   number<B, et_off>                                                    result;
   using default_ops::eval_subtract;
   eval_subtract(result.backend(), a.backend(), b.backend());
   return result;
}
template <class B, class V>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator-(const number<B, et_off>& a, const V& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a);
   number<B, et_off>                                                    result;
   using default_ops::eval_subtract;
   eval_subtract(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return result;
}
template <class V, class B>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator-(const V& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(b);
   number<B, et_off>                                                    result;
   using default_ops::eval_subtract;
   eval_subtract(result.backend(), number<B, et_off>::canonical_value(a), b.backend());
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
//
// Multiply:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator * (const number<B, et_off>& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_multiply;
   eval_multiply(result.backend(), a.backend(), b.backend());
   return BOOST_MP_MOVE(result);
}
template <class B, class V>
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator * (const number<B, et_off>& a, const V& b)
{
   number<B, et_off> result;
   using default_ops::eval_multiply;
   eval_multiply(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return BOOST_MP_MOVE(result);
}
template <class V, class B>
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator * (const V& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_multiply;
   eval_multiply(result.backend(), b.backend(), number<B, et_off>::canonical_value(a));
   return BOOST_MP_MOVE(result);
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator*(const number<B, et_off>& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
   number<B, et_off>                                                    result;
   using default_ops::eval_multiply;
   eval_multiply(result.backend(), a.backend(), b.backend());
   return result;
}
template <class B, class V>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator*(const number<B, et_off>& a, const V& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a);
   number<B, et_off>                                                    result;
   using default_ops::eval_multiply;
   eval_multiply(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return result;
}
template <class V, class B>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator*(const V& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(b);
   number<B, et_off>                                                    result;
   using default_ops::eval_multiply;
   eval_multiply(result.backend(), b.backend(), number<B, et_off>::canonical_value(a));
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
//
// divide:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator / (const number<B, et_off>& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_divide;
   eval_divide(result.backend(), a.backend(), b.backend());
   return BOOST_MP_MOVE(result);
}
template <class B, class V>
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator / (const number<B, et_off>& a, const V& b)
{
   number<B, et_off> result;
   using default_ops::eval_divide;
   eval_divide(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return BOOST_MP_MOVE(result);
}
template <class V, class B>
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator / (const V& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_divide;
   eval_divide(result.backend(), number<B, et_off>::canonical_value(a), b.backend());
   return BOOST_MP_MOVE(result);
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator/(const number<B, et_off>& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
   number<B, et_off>                                                    result;
   using default_ops::eval_divide;
   eval_divide(result.backend(), a.backend(), b.backend());
   return result;
}
template <class B, class V>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator/(const number<B, et_off>& a, const V& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a);
   number<B, et_off>                                                    result;
   using default_ops::eval_divide;
   eval_divide(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return result;
}
template <class V, class B>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator/(const V& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(b);
   number<B, et_off>                                                    result;
   using default_ops::eval_divide;
   eval_divide(result.backend(), number<B, et_off>::canonical_value(a), b.backend());
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
//
// modulus:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator % (const number<B, et_off>& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_modulus;
   eval_modulus(result.backend(), a.backend(), b.backend());
   return BOOST_MP_MOVE(result);
}
template <class B, class V>
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator % (const number<B, et_off>& a, const V& b)
{
   number<B, et_off> result;
   using default_ops::eval_modulus;
   eval_modulus(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return BOOST_MP_MOVE(result);
}
template <class V, class B>
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator % (const V& a, const number<B, et_off>& b)
{
   number<B, et_off> result;
   using default_ops::eval_modulus;
   eval_modulus(result.backend(), number<B, et_off>::canonical_value(a), b.backend());
   return BOOST_MP_MOVE(result);
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator%(const number<B, et_off>& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
   number<B, et_off>                                                    result;
   using default_ops::eval_modulus;
   eval_modulus(result.backend(), a.backend(), b.backend());
   return result;
}
template <class B, class V>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator%(const number<B, et_off>& a, const V& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a);
   number<B, et_off>                                                    result;
   using default_ops::eval_modulus;
   eval_modulus(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
   return result;
}
template <class V, class B>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator%(const V& a, const number<B, et_off>& b)
{
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(b);
   number<B, et_off>                                                    result;
   using default_ops::eval_modulus;
   eval_modulus(result.backend(), number<B, et_off>::canonical_value(a), b.backend());
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
//
// Bitwise or:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator | (const number<B, et_off>& a, const number<B, et_off>& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator|(const number<B, et_off>& a, const number<B, et_off>& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   number<B, et_off> result;
   using default_ops::eval_bitwise_or;
   eval_bitwise_or(result.backend(), a.backend(), b.backend());
<<<<<<< HEAD
   return BOOST_MP_MOVE(result);
}
template <class B, class V>
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator | (const number<B, et_off>& a, const V& b)
=======
   return result;
}
template <class B, class V>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator|(const number<B, et_off>& a, const V& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   number<B, et_off> result;
   using default_ops::eval_bitwise_or;
   eval_bitwise_or(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
<<<<<<< HEAD
   return BOOST_MP_MOVE(result);
}
template <class V, class B>
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator | (const V& a, const number<B, et_off>& b)
=======
   return result;
}
template <class V, class B>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator|(const V& a, const number<B, et_off>& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   number<B, et_off> result;
   using default_ops::eval_bitwise_or;
   eval_bitwise_or(result.backend(), b.backend(), number<B, et_off>::canonical_value(a));
<<<<<<< HEAD
   return BOOST_MP_MOVE(result);
=======
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
//
// Bitwise xor:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator ^ (const number<B, et_off>& a, const number<B, et_off>& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator^(const number<B, et_off>& a, const number<B, et_off>& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   number<B, et_off> result;
   using default_ops::eval_bitwise_xor;
   eval_bitwise_xor(result.backend(), a.backend(), b.backend());
<<<<<<< HEAD
   return BOOST_MP_MOVE(result);
}
template <class B, class V>
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator ^ (const number<B, et_off>& a, const V& b)
=======
   return result;
}
template <class B, class V>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator^(const number<B, et_off>& a, const V& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   number<B, et_off> result;
   using default_ops::eval_bitwise_xor;
   eval_bitwise_xor(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
<<<<<<< HEAD
   return BOOST_MP_MOVE(result);
}
template <class V, class B>
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator ^ (const V& a, const number<B, et_off>& b)
=======
   return result;
}
template <class V, class B>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator^(const V& a, const number<B, et_off>& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   number<B, et_off> result;
   using default_ops::eval_bitwise_xor;
   eval_bitwise_xor(result.backend(), b.backend(), number<B, et_off>::canonical_value(a));
<<<<<<< HEAD
   return BOOST_MP_MOVE(result);
=======
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
//
// Bitwise and:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator & (const number<B, et_off>& a, const number<B, et_off>& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator&(const number<B, et_off>& a, const number<B, et_off>& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   number<B, et_off> result;
   using default_ops::eval_bitwise_and;
   eval_bitwise_and(result.backend(), a.backend(), b.backend());
<<<<<<< HEAD
   return BOOST_MP_MOVE(result);
}
template <class B, class V>
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator & (const number<B, et_off>& a, const V& b)
=======
   return result;
}
template <class B, class V>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator&(const number<B, et_off>& a, const V& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   number<B, et_off> result;
   using default_ops::eval_bitwise_and;
   eval_bitwise_and(result.backend(), a.backend(), number<B, et_off>::canonical_value(b));
<<<<<<< HEAD
   return BOOST_MP_MOVE(result);
}
template <class V, class B>
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator & (const V& a, const number<B, et_off>& b)
=======
   return result;
}
template <class V, class B>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator&(const V& a, const number<B, et_off>& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   number<B, et_off> result;
   using default_ops::eval_bitwise_and;
   eval_bitwise_and(result.backend(), b.backend(), number<B, et_off>::canonical_value(a));
<<<<<<< HEAD
   return BOOST_MP_MOVE(result);
=======
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
//
// shifts:
//
template <class B, class I>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_integral<I>::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator << (const number<B, et_off>& a, const I& b)
{
   number<B, et_off> result(a);
   using default_ops::eval_left_shift;
   detail::check_shift_range(b, mpl::bool_<(sizeof(I) > sizeof(std::size_t))>(), is_signed<I>());
   eval_left_shift(result.backend(), b);
   return BOOST_MP_MOVE(result);
}
template <class B, class I>
BOOST_MP_FORCEINLINE typename enable_if_c<is_integral<I>::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator >> (const number<B, et_off>& a, const I& b)
{
   number<B, et_off> result(a);
   using default_ops::eval_right_shift;
   detail::check_shift_range(b, mpl::bool_<(sizeof(I) > sizeof(std::size_t))>(), is_signed<I>());
   eval_right_shift(result.backend(), b);
   return BOOST_MP_MOVE(result);
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_integral<I>::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator<<(const number<B, et_off>& a, const I& b)
{
   number<B, et_off> result(a);
   using default_ops::eval_left_shift;
   detail::check_shift_range(b, mpl::bool_<(sizeof(I) > sizeof(std::size_t))>(), mpl::bool_<is_signed<I>::value>());
   eval_left_shift(result.backend(), b);
   return result;
}
template <class B, class I>
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_integral<I>::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator>>(const number<B, et_off>& a, const I& b)
{
   number<B, et_off> result(a);
   using default_ops::eval_right_shift;
   detail::check_shift_range(b, mpl::bool_<(sizeof(I) > sizeof(std::size_t))>(), mpl::bool_<is_signed<I>::value>());
   eval_right_shift(result.backend(), b);
   return result;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && !(defined(__GNUC__) && ((__GNUC__ == 4) && (__GNUC_MINOR__ < 5)))
//
// If we have rvalue references go all over again with rvalue ref overloads and move semantics.
// Note that while it would be tempting to implement these so they return an rvalue reference
// (and indeed this would be optimally efficient), this is unsafe due to users propensity to
// write:
//
// const T& t = a * b;
//
// which would lead to a dangling reference if we didn't return by value.  Of course move
// semantics help a great deal in return by value, so performance is still pretty good...
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator - (number<B, et_off>&& v)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator-(number<B, et_off>&& v)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   BOOST_STATIC_ASSERT_MSG(is_signed_number<B>::value, "Negating an unsigned type results in ill-defined behavior.");
   v.backend().negate();
   return static_cast<number<B, et_off>&&>(v);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator ~ (number<B, et_off>&& v)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator~(number<B, et_off>&& v)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   eval_complement(v.backend(), v.backend());
   return static_cast<number<B, et_off>&&>(v);
}
//
// Addition:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator + (number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_add;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator+(number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_add;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_add(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator + (const number<B, et_off>& a, number<B, et_off>&& b)
{
   using default_ops::eval_add;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator+(const number<B, et_off>& a, number<B, et_off>&& b)
{
   using default_ops::eval_add;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_add(b.backend(), a.backend());
   return static_cast<number<B, et_off>&&>(b);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator + (number<B, et_off>&& a, number<B, et_off>&& b)
{
   using default_ops::eval_add;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator+(number<B, et_off>&& a, number<B, et_off>&& b)
{
   using default_ops::eval_add;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_add(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B, class V>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator + (number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_add;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator+(number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_add;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_add(a.backend(), number<B, et_off>::canonical_value(b));
   return static_cast<number<B, et_off>&&>(a);
}
template <class V, class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator + (const V& a, number<B, et_off>&& b)
{
   using default_ops::eval_add;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator+(const V& a, number<B, et_off>&& b)
{
   using default_ops::eval_add;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_add(b.backend(), number<B, et_off>::canonical_value(a));
   return static_cast<number<B, et_off>&&>(b);
}
//
// Subtraction:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator - (number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_subtract;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator-(number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_subtract;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_subtract(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if<is_signed_number<B>, number<B, et_off> >::type operator - (const number<B, et_off>& a, number<B, et_off>&& b)
{
   using default_ops::eval_subtract;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_signed_number<B>, number<B, et_off> >::type operator-(const number<B, et_off>& a, number<B, et_off>&& b)
{
   using default_ops::eval_subtract;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_subtract(b.backend(), a.backend());
   b.backend().negate();
   return static_cast<number<B, et_off>&&>(b);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator - (number<B, et_off>&& a, number<B, et_off>&& b)
{
   using default_ops::eval_subtract;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator-(number<B, et_off>&& a, number<B, et_off>&& b)
{
   using default_ops::eval_subtract;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_subtract(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B, class V>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator - (number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_subtract;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator-(number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_subtract;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_subtract(a.backend(), number<B, et_off>::canonical_value(b));
   return static_cast<number<B, et_off>&&>(a);
}
template <class V, class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<(is_compatible_arithmetic_type<V, number<B, et_off> >::value && is_signed_number<B>::value), number<B, et_off> >::type
   operator - (const V& a, number<B, et_off>&& b)
{
   using default_ops::eval_subtract;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<(is_compatible_arithmetic_type<V, number<B, et_off> >::value && is_signed_number<B>::value), number<B, et_off> >::type
operator-(const V& a, number<B, et_off>&& b)
{
   using default_ops::eval_subtract;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_subtract(b.backend(), number<B, et_off>::canonical_value(a));
   b.backend().negate();
   return static_cast<number<B, et_off>&&>(b);
}
//
// Multiply:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator * (number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_multiply;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator*(number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_multiply;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_multiply(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator * (const number<B, et_off>& a, number<B, et_off>&& b)
{
   using default_ops::eval_multiply;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator*(const number<B, et_off>& a, number<B, et_off>&& b)
{
   using default_ops::eval_multiply;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_multiply(b.backend(), a.backend());
   return static_cast<number<B, et_off>&&>(b);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator * (number<B, et_off>&& a, number<B, et_off>&& b)
{
   using default_ops::eval_multiply;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator*(number<B, et_off>&& a, number<B, et_off>&& b)
{
   using default_ops::eval_multiply;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_multiply(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B, class V>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator * (number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_multiply;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator*(number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_multiply;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_multiply(a.backend(), number<B, et_off>::canonical_value(b));
   return static_cast<number<B, et_off>&&>(a);
}
template <class V, class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator * (const V& a, number<B, et_off>&& b)
{
   using default_ops::eval_multiply;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator*(const V& a, number<B, et_off>&& b)
{
   using default_ops::eval_multiply;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_multiply(b.backend(), number<B, et_off>::canonical_value(a));
   return static_cast<number<B, et_off>&&>(b);
}
//
// divide:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE number<B, et_off> operator / (number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_divide;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR number<B, et_off> operator/(number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_divide;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_divide(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B, class V>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
   operator / (number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_divide;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if<is_compatible_arithmetic_type<V, number<B, et_off> >, number<B, et_off> >::type
operator/(number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_divide;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_divide(a.backend(), number<B, et_off>::canonical_value(b));
   return static_cast<number<B, et_off>&&>(a);
}
//
// modulus:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator % (number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_modulus;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator%(number<B, et_off>&& a, const number<B, et_off>& b)
{
   using default_ops::eval_modulus;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_modulus(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B, class V>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator % (number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_modulus;
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator%(number<B, et_off>&& a, const V& b)
{
   using default_ops::eval_modulus;
   detail::scoped_default_precision<multiprecision::number<B, et_off> > precision_guard(a, b);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   eval_modulus(a.backend(), number<B, et_off>::canonical_value(b));
   return static_cast<number<B, et_off>&&>(a);
}
//
// Bitwise or:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator | (number<B, et_off>&& a, const number<B, et_off>& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator|(number<B, et_off>&& a, const number<B, et_off>& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_or;
   eval_bitwise_or(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator | (const number<B, et_off>& a, number<B, et_off>&& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator|(const number<B, et_off>& a, number<B, et_off>&& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_or;
   eval_bitwise_or(b.backend(), a.backend());
   return static_cast<number<B, et_off>&&>(b);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator | (number<B, et_off>&& a, number<B, et_off>&& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator|(number<B, et_off>&& a, number<B, et_off>&& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_or;
   eval_bitwise_or(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B, class V>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator | (number<B, et_off>&& a, const V& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator|(number<B, et_off>&& a, const V& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_or;
   eval_bitwise_or(a.backend(), number<B, et_off>::canonical_value(b));
   return static_cast<number<B, et_off>&&>(a);
}
template <class V, class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator | (const V& a, number<B, et_off>&& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator|(const V& a, number<B, et_off>&& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_or;
   eval_bitwise_or(b.backend(), number<B, et_off>::canonical_value(a));
   return static_cast<number<B, et_off>&&>(b);
}
//
// Bitwise xor:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator ^ (number<B, et_off>&& a, const number<B, et_off>& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator^(number<B, et_off>&& a, const number<B, et_off>& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_xor;
   eval_bitwise_xor(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator ^ (const number<B, et_off>& a, number<B, et_off>&& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator^(const number<B, et_off>& a, number<B, et_off>&& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_xor;
   eval_bitwise_xor(b.backend(), a.backend());
   return static_cast<number<B, et_off>&&>(b);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator ^ (number<B, et_off>&& a, number<B, et_off>&& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator^(number<B, et_off>&& a, number<B, et_off>&& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_xor;
   eval_bitwise_xor(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B, class V>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator ^ (number<B, et_off>&& a, const V& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator^(number<B, et_off>&& a, const V& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_xor;
   eval_bitwise_xor(a.backend(), number<B, et_off>::canonical_value(b));
   return static_cast<number<B, et_off>&&>(a);
}
template <class V, class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator ^ (const V& a, number<B, et_off>&& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator^(const V& a, number<B, et_off>&& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_xor;
   eval_bitwise_xor(b.backend(), number<B, et_off>::canonical_value(a));
   return static_cast<number<B, et_off>&&>(b);
}
//
// Bitwise and:
//
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator & (number<B, et_off>&& a, const number<B, et_off>& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator&(number<B, et_off>&& a, const number<B, et_off>& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_and;
   eval_bitwise_and(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator & (const number<B, et_off>& a, number<B, et_off>&& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator&(const number<B, et_off>& a, number<B, et_off>&& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_and;
   eval_bitwise_and(b.backend(), a.backend());
   return static_cast<number<B, et_off>&&>(b);
}
template <class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator & (number<B, et_off>&& a, number<B, et_off>&& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<number_category<B>::value == number_kind_integer, number<B, et_off> >::type operator&(number<B, et_off>&& a, number<B, et_off>&& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_and;
   eval_bitwise_and(a.backend(), b.backend());
   return static_cast<number<B, et_off>&&>(a);
}
template <class B, class V>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator & (number<B, et_off>&& a, const V& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator&(number<B, et_off>&& a, const V& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_and;
   eval_bitwise_and(a.backend(), number<B, et_off>::canonical_value(b));
   return static_cast<number<B, et_off>&&>(a);
}
template <class V, class B>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator & (const V& a, number<B, et_off>&& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_compatible_arithmetic_type<V, number<B, et_off> >::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator&(const V& a, number<B, et_off>&& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_bitwise_and;
   eval_bitwise_and(b.backend(), number<B, et_off>::canonical_value(a));
   return static_cast<number<B, et_off>&&>(b);
}
//
// shifts:
//
template <class B, class I>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_integral<I>::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator << (number<B, et_off>&& a, const I& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_integral<I>::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator<<(number<B, et_off>&& a, const I& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_left_shift;
   eval_left_shift(a.backend(), b);
   return static_cast<number<B, et_off>&&>(a);
}
template <class B, class I>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_integral<I>::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
   operator >> (number<B, et_off>&& a, const I& b)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_integral<I>::value && (number_category<B>::value == number_kind_integer), number<B, et_off> >::type
operator>>(number<B, et_off>&& a, const I& b)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_right_shift;
   eval_right_shift(a.backend(), b);
   return static_cast<number<B, et_off>&&>(a);
}

#endif

<<<<<<< HEAD
}} // namespaces
=======
}} // namespace boost::multiprecision
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

#endif // BOOST_MP_NO_ET_OPS_HPP
