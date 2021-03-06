///////////////////////////////////////////////////////////////
//  Copyright 2012 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
<<<<<<< HEAD
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_
=======
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
//
// Comparison operators for cpp_int_backend:
//
#ifndef BOOST_MP_CPP_INT_MISC_HPP
#define BOOST_MP_CPP_INT_MISC_HPP

<<<<<<< HEAD
#include <boost/multiprecision/detail/bitscan.hpp> // lsb etc
#include <boost/integer/common_factor_rt.hpp> // gcd/lcm
=======
#include <boost/multiprecision/detail/constexpr.hpp>
#include <boost/multiprecision/detail/bitscan.hpp> // lsb etc
#include <boost/integer/common_factor_rt.hpp>      // gcd/lcm
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/functional/hash_fwd.hpp>

#ifdef BOOST_MSVC
#pragma warning(push)
<<<<<<< HEAD
#pragma warning(disable:4702)
#pragma warning(disable:4127) // conditional expression is constant
#pragma warning(disable:4146) // unary minus operator applied to unsigned type, result still unsigned
#endif


namespace boost{ namespace multiprecision{ namespace backends{

template <class R, class CppInt>
void check_in_range(const CppInt& val, const mpl::int_<checked>&)
{
   typedef typename boost::multiprecision::detail::canonical<R, CppInt>::type cast_type;
   if(val.sign())
   {
      if(val.compare(static_cast<cast_type>((std::numeric_limits<R>::min)())) < 0)
=======
#pragma warning(disable : 4702)
#pragma warning(disable : 4127) // conditional expression is constant
#pragma warning(disable : 4146) // unary minus operator applied to unsigned type, result still unsigned
#endif

namespace boost { namespace multiprecision { namespace backends {

template <class R, class CppInt>
BOOST_MP_CXX14_CONSTEXPR void check_in_range(const CppInt& val, const mpl::int_<checked>&)
{
   typedef typename boost::multiprecision::detail::canonical<R, CppInt>::type cast_type;
   if (val.sign())
   {
      if (boost::is_signed<R>::value == false)
         BOOST_THROW_EXCEPTION(std::range_error("Attempt to assign a negative value to an unsigned type."));
      if (val.compare(static_cast<cast_type>((std::numeric_limits<R>::min)())) < 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
         BOOST_THROW_EXCEPTION(std::overflow_error("Could not convert to the target type - -value is out of range."));
   }
   else
   {
<<<<<<< HEAD
      if(val.compare(static_cast<cast_type>((std::numeric_limits<R>::max)())) > 0)
=======
      if (val.compare(static_cast<cast_type>((std::numeric_limits<R>::max)())) > 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
         BOOST_THROW_EXCEPTION(std::overflow_error("Could not convert to the target type - -value is out of range."));
   }
}
template <class R, class CppInt>
<<<<<<< HEAD
inline void check_in_range(const CppInt& /*val*/, const mpl::int_<unchecked>&) BOOST_NOEXCEPT {}

inline void check_is_negative(const mpl::true_&) BOOST_NOEXCEPT {}
=======
inline BOOST_MP_CXX14_CONSTEXPR void check_in_range(const CppInt& /*val*/, const mpl::int_<unchecked>&) BOOST_NOEXCEPT {}

inline BOOST_MP_CXX14_CONSTEXPR void check_is_negative(const mpl::true_&) BOOST_NOEXCEPT {}
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
inline void check_is_negative(const mpl::false_&)
{
   BOOST_THROW_EXCEPTION(std::range_error("Attempt to assign a negative value to an unsigned type."));
}

template <class Integer>
<<<<<<< HEAD
inline Integer negate_integer(Integer i, const mpl::true_&) BOOST_NOEXCEPT
=======
inline BOOST_MP_CXX14_CONSTEXPR Integer negate_integer(Integer i, const mpl::true_&) BOOST_NOEXCEPT
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   return -i;
}
template <class Integer>
<<<<<<< HEAD
inline Integer negate_integer(Integer i, const mpl::false_&) BOOST_NOEXCEPT
{
   return ~(i-1);
}

template <class R, unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
inline typename enable_if_c<is_integral<R>::value && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, void>::type
   eval_convert_to(R* result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& backend) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
=======
inline BOOST_MP_CXX14_CONSTEXPR Integer negate_integer(Integer i, const mpl::false_&) BOOST_NOEXCEPT
{
   return ~(i - 1);
}

template <class R, unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_integral<R>::value && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, void>::type
eval_convert_to(R* result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& backend)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   typedef mpl::int_<Checked1> checked_type;
   check_in_range<R>(backend, checked_type());

<<<<<<< HEAD
   *result = static_cast<R>(backend.limbs()[0]);
   unsigned shift = cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   for(unsigned i = 1; (i < backend.size()) && (shift < static_cast<unsigned>(std::numeric_limits<R>::digits)); ++i)
   {
      *result += static_cast<R>(backend.limbs()[i]) << shift;
      shift += cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   }
   if(backend.sign())
   {
      check_is_negative(boost::is_signed<R>());
      *result = negate_integer(*result, boost::is_signed<R>());
=======
   if (std::numeric_limits<R>::digits < cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits)
   {
      if ((backend.sign() && boost::is_signed<R>::value) && (1 + static_cast<boost::multiprecision::limb_type>((std::numeric_limits<R>::max)()) <= backend.limbs()[0]))
      {
         *result = (std::numeric_limits<R>::min)();
         return;
      }
      else if (boost::is_signed<R>::value && !backend.sign() && static_cast<boost::multiprecision::limb_type>((std::numeric_limits<R>::max)()) <= backend.limbs()[0])
      {
         *result = (std::numeric_limits<R>::max)();
         return;
      }
      else
         *result = static_cast<R>(backend.limbs()[0]);
   }
   else
      *result = static_cast<R>(backend.limbs()[0]);
   unsigned shift = cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   unsigned i     = 1;
   if (std::numeric_limits<R>::digits > cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits)
   {
      while ((i < backend.size()) && (shift < static_cast<unsigned>(std::numeric_limits<R>::digits - cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits)))
      {
         *result += static_cast<R>(backend.limbs()[i]) << shift;
         shift += cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
         ++i;
      }
      //
      // We have one more limb to extract, but may not need all the bits, so treat this as a special case:
      //
      if (i < backend.size())
      {
         const limb_type mask = std::numeric_limits<R>::digits - shift == cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits ? ~static_cast<limb_type>(0) : (static_cast<limb_type>(1u) << (std::numeric_limits<R>::digits - shift)) - 1;
         *result += (static_cast<R>(backend.limbs()[i]) & mask) << shift;
         if ((static_cast<R>(backend.limbs()[i]) & static_cast<limb_type>(~mask)) || (i + 1 < backend.size()))
         {
            // Overflow:
            if (backend.sign())
            {
               check_is_negative(boost::is_signed<R>());
               *result = (std::numeric_limits<R>::min)();
            }
            else if (boost::is_signed<R>::value)
               *result = (std::numeric_limits<R>::max)();
            return;
         }
      }
   }
   else if (backend.size() > 1)
   {
      // Overflow:
      if (backend.sign())
      {
         check_is_negative(boost::is_signed<R>());
         *result = (std::numeric_limits<R>::min)();
      }
      else if (boost::is_signed<R>::value)
         *result = (std::numeric_limits<R>::max)();
      return;
   }
   if (backend.sign())
   {
      check_is_negative(mpl::bool_<boost::is_signed<R>::value>());
      *result = negate_integer(*result, mpl::bool_<boost::is_signed<R>::value>());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   }
}

template <class R, unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<is_floating_point<R>::value && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, void>::type
   eval_convert_to(R* result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& backend) BOOST_MP_NOEXCEPT_IF(is_arithmetic<R>::value)
{
   typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::const_limb_pointer p = backend.limbs();
   unsigned shift = cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   *result = static_cast<R>(*p);
   for(unsigned i = 1; i < backend.size(); ++i)
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_floating_point<R>::value && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, void>::type
eval_convert_to(R* result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& backend) BOOST_MP_NOEXCEPT_IF(is_arithmetic<R>::value)
{
   typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::const_limb_pointer p     = backend.limbs();
   unsigned                                                                                          shift = cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   *result                                                                                                 = static_cast<R>(*p);
   for (unsigned i = 1; i < backend.size(); ++i)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      *result += static_cast<R>(std::ldexp(static_cast<long double>(p[i]), shift));
      shift += cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   }
<<<<<<< HEAD
   if(backend.sign())
=======
   if (backend.sign())
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      *result = -*result;
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, bool>::type
   eval_is_zero(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val) BOOST_NOEXCEPT
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, bool>::type
eval_is_zero(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val) BOOST_NOEXCEPT
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   return (val.size() == 1) && (val.limbs()[0] == 0);
}
template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, int>::type
   eval_get_sign(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val) BOOST_NOEXCEPT
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, int>::type
eval_get_sign(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val) BOOST_NOEXCEPT
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   return eval_is_zero(val) ? 0 : val.sign() ? -1 : 1;
}
template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_abs(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_abs(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   result = val;
   result.sign(false);
}

//
// Get the location of the least-significant-bit:
//
template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
   eval_lsb(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   using default_ops::eval_get_sign;
   if(eval_get_sign(a) == 0)
   {
      BOOST_THROW_EXCEPTION(std::range_error("No bits were set in the operand."));
   }
   if(a.sign())
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
eval_lsb(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   using default_ops::eval_get_sign;
   if (eval_get_sign(a) == 0)
   {
      BOOST_THROW_EXCEPTION(std::range_error("No bits were set in the operand."));
   }
   if (a.sign())
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      BOOST_THROW_EXCEPTION(std::range_error("Testing individual bits in negative values is not supported - results are undefined."));
   }

   //
   // Find the index of the least significant limb that is non-zero:
   //
   unsigned index = 0;
<<<<<<< HEAD
   while(!a.limbs()[index] && (index < a.size()))
=======
   while (!a.limbs()[index] && (index < a.size()))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      ++index;
   //
   // Find the index of the least significant bit within that limb:
   //
   unsigned result = boost::multiprecision::detail::find_lsb(a.limbs()[index]);

   return result + index * cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
}

//
// Get the location of the most-significant-bit:
//
template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
eval_msb_imp(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   //
   // Find the index of the most significant bit that is non-zero:
   //
   return (a.size() - 1) * cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits + boost::multiprecision::detail::find_msb(a.limbs()[a.size() - 1]);
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
   eval_msb(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   using default_ops::eval_get_sign;
   if(eval_get_sign(a) == 0)
   {
      BOOST_THROW_EXCEPTION(std::range_error("No bits were set in the operand."));
   }
   if(a.sign())
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
eval_msb(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   using default_ops::eval_get_sign;
   if (eval_get_sign(a) == 0)
   {
      BOOST_THROW_EXCEPTION(std::range_error("No bits were set in the operand."));
   }
   if (a.sign())
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      BOOST_THROW_EXCEPTION(std::range_error("Testing individual bits in negative values is not supported - results are undefined."));
   }
   return eval_msb_imp(a);
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, bool>::type
   eval_bit_test(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val, unsigned index) BOOST_NOEXCEPT
{
   unsigned offset = index / cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   unsigned shift = index % cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   limb_type mask = shift ? limb_type(1u) << shift : limb_type(1u);
   if(offset >= val.size())
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, bool>::type
eval_bit_test(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val, unsigned index) BOOST_NOEXCEPT
{
   unsigned  offset = index / cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   unsigned  shift  = index % cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   limb_type mask   = shift ? limb_type(1u) << shift : limb_type(1u);
   if (offset >= val.size())
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      return false;
   return val.limbs()[offset] & mask ? true : false;
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_bit_set(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val, unsigned index)
{
   unsigned offset = index / cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   unsigned shift = index % cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   limb_type mask = shift ? limb_type(1u) << shift : limb_type(1u);
   if(offset >= val.size())
   {
      unsigned os = val.size();
      val.resize(offset + 1, offset + 1);
      if(offset >= val.size())
         return;  // fixed precision overflow
      for(unsigned i = os; i <= offset; ++i)
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_bit_set(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val, unsigned index)
{
   unsigned  offset = index / cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   unsigned  shift  = index % cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   limb_type mask   = shift ? limb_type(1u) << shift : limb_type(1u);
   if (offset >= val.size())
   {
      unsigned os = val.size();
      val.resize(offset + 1, offset + 1);
      if (offset >= val.size())
         return; // fixed precision overflow
      for (unsigned i = os; i <= offset; ++i)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
         val.limbs()[i] = 0;
   }
   val.limbs()[offset] |= mask;
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_bit_unset(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val, unsigned index) BOOST_NOEXCEPT
{
   unsigned offset = index / cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   unsigned shift = index % cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   limb_type mask = shift ? limb_type(1u) << shift : limb_type(1u);
   if(offset >= val.size())
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_bit_unset(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val, unsigned index) BOOST_NOEXCEPT
{
   unsigned  offset = index / cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   unsigned  shift  = index % cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   limb_type mask   = shift ? limb_type(1u) << shift : limb_type(1u);
   if (offset >= val.size())
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      return;
   val.limbs()[offset] &= ~mask;
   val.normalize();
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_bit_flip(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val, unsigned index)
{
   unsigned offset = index / cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   unsigned shift = index % cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   limb_type mask = shift ? limb_type(1u) << shift : limb_type(1u);
   if(offset >= val.size())
   {
      unsigned os = val.size();
      val.resize(offset + 1, offset + 1);
      if(offset >= val.size())
         return;  // fixed precision overflow
      for(unsigned i = os; i <= offset; ++i)
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_bit_flip(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val, unsigned index)
{
   unsigned  offset = index / cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   unsigned  shift  = index % cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::limb_bits;
   limb_type mask   = shift ? limb_type(1u) << shift : limb_type(1u);
   if (offset >= val.size())
   {
      unsigned os = val.size();
      val.resize(offset + 1, offset + 1);
      if (offset >= val.size())
         return; // fixed precision overflow
      for (unsigned i = os; i <= offset; ++i)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
         val.limbs()[i] = 0;
   }
   val.limbs()[offset] ^= mask;
   val.normalize();
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_qr(
      const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x,
      const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& y,
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& q,
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& r) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_qr(
    const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x,
    const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& y,
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       q,
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       r) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   divide_unsigned_helper(&q, x, y, r);
   q.sign(x.sign() != y.sign());
   r.sign(x.sign());
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_qr(
      const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x,
      limb_type y,
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& q,
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& r) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_qr(
    const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x,
    limb_type                                                                   y,
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       q,
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       r) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   divide_unsigned_helper(&q, x, y, r);
   q.sign(x.sign());
   r.sign(x.sign());
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1, class U>
<<<<<<< HEAD
inline typename enable_if_c<is_integral<U>::value>::type eval_qr(
      const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x,
      U y,
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& q,
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& r) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_integral<U>::value>::type eval_qr(
    const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x,
    U                                                                           y,
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       q,
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       r) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   using default_ops::eval_qr;
   cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> t;
   t = y;
   eval_qr(x, t, q, r);
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1, class Integer>
<<<<<<< HEAD
inline typename enable_if_c<is_unsigned<Integer>::value && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, Integer>::type
   eval_integer_modulus(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x, Integer val)
{
   if((sizeof(Integer) <= sizeof(limb_type)) || (val <= (std::numeric_limits<limb_type>::max)()))
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_unsigned<Integer>::value && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, Integer>::type
eval_integer_modulus(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x, Integer val)
{
   if ((sizeof(Integer) <= sizeof(limb_type)) || (val <= (std::numeric_limits<limb_type>::max)()))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> d;
      divide_unsigned_helper(static_cast<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>*>(0), x, static_cast<limb_type>(val), d);
      return d.limbs()[0];
   }
   else
   {
      return default_ops::eval_integer_modulus(x, val);
   }
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1, class Integer>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_signed<Integer>::value && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, Integer>::type
   eval_integer_modulus(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x, Integer val)
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_signed<Integer>::value && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, Integer>::type
eval_integer_modulus(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& x, Integer val)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   return eval_integer_modulus(x, boost::multiprecision::detail::unsigned_abs(val));
}

<<<<<<< HEAD
inline limb_type integer_gcd_reduce(limb_type u, limb_type v)
{
   do
   {
      if(u > v)
         std::swap(u, v);
      if(u == v)
         break;
      v -= u;
      v >>= boost::multiprecision::detail::find_lsb(v);
   } while(true);
   return u;
}

inline double_limb_type integer_gcd_reduce(double_limb_type u, double_limb_type v)
{
   do
   {
      if(u > v)
         std::swap(u, v);
      if(u == v)
         break;
      if(v <= ~static_cast<limb_type>(0))
=======
inline BOOST_MP_CXX14_CONSTEXPR limb_type integer_gcd_reduce(limb_type u, limb_type v)
{
   do
   {
      if (u > v)
         std_constexpr::swap(u, v);
      if (u == v)
         break;
      v -= u;
      v >>= boost::multiprecision::detail::find_lsb(v);
   } while (true);
   return u;
}

inline BOOST_MP_CXX14_CONSTEXPR double_limb_type integer_gcd_reduce(double_limb_type u, double_limb_type v)
{
   do
   {
      if (u > v)
         std_constexpr::swap(u, v);
      if (u == v)
         break;
      if (v <= ~static_cast<limb_type>(0))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      {
         u = integer_gcd_reduce(static_cast<limb_type>(v), static_cast<limb_type>(u));
         break;
      }
      v -= u;
#ifdef __MSVC_RUNTIME_CHECKS
<<<<<<< HEAD
      while((v & 1u) == 0)
#else
      while((static_cast<unsigned>(v) & 1u) == 0)
#endif
         v >>= 1;
   } while(true);
=======
      while ((v & 1u) == 0)
#else
      while ((static_cast<unsigned>(v) & 1u) == 0)
#endif
         v >>= 1;
   } while (true);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   return u;
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_gcd(
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, 
      const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a, 
      limb_type v)
{
   using default_ops::eval_lsb;
   using default_ops::eval_is_zero;
   using default_ops::eval_get_sign;

   int shift;
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_gcd(
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       result,
    const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a,
    limb_type                                                                   v)
{
   using default_ops::eval_get_sign;
   using default_ops::eval_is_zero;
   using default_ops::eval_lsb;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

   cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> u(a);

   int s = eval_get_sign(u);

   /* GCD(0,x) := x */
<<<<<<< HEAD
   if(s < 0)
   {
      u.negate();
   }
   else if(s == 0)
=======
   if (s < 0)
   {
      u.negate();
   }
   else if (s == 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      result = v;
      return;
   }
<<<<<<< HEAD
   if(v == 0)
=======
   if (v == 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      result = u;
      return;
   }

   /* Let shift := lg K, where K is the greatest power of 2
   dividing both u and v. */

   unsigned us = eval_lsb(u);
   unsigned vs = boost::multiprecision::detail::find_lsb(v);
<<<<<<< HEAD
   shift = (std::min)(us, vs);
   eval_right_shift(u, us);
   if(vs)
      v >>= vs;

   do 
   {
      /* Now u and v are both odd, so diff(u, v) is even.
      Let u = min(u, v), v = diff(u, v)/2. */
      if(u.size() <= 2)
      {
         if(u.size() == 1)
            v = integer_gcd_reduce(*u.limbs(), v);
         else
         {
            double_limb_type i;
            i = u.limbs()[0] | (static_cast<double_limb_type>(u.limbs()[1]) << sizeof(limb_type) * CHAR_BIT);
=======
   int shift   = (std::min)(us, vs);
   eval_right_shift(u, us);
   if (vs)
      v >>= vs;

   do
   {
      /* Now u and v are both odd, so diff(u, v) is even.
      Let u = min(u, v), v = diff(u, v)/2. */
      if (u.size() <= 2)
      {
         if (u.size() == 1)
            v = integer_gcd_reduce(*u.limbs(), v);
         else
         {
            double_limb_type i = u.limbs()[0] | (static_cast<double_limb_type>(u.limbs()[1]) << sizeof(limb_type) * CHAR_BIT);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            v = static_cast<limb_type>(integer_gcd_reduce(i, static_cast<double_limb_type>(v)));
         }
         break;
      }
      eval_subtract(u, v);
      us = eval_lsb(u);
      eval_right_shift(u, us);
<<<<<<< HEAD
   } 
   while(true);
=======
   } while (true);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

   result = v;
   eval_left_shift(result, shift);
}
template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1, class Integer>
<<<<<<< HEAD
inline typename enable_if_c<is_unsigned<Integer>::value && (sizeof(Integer) <= sizeof(limb_type)) && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_gcd(
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, 
      const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a, 
      const Integer& v)
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_unsigned<Integer>::value && (sizeof(Integer) <= sizeof(limb_type)) && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_gcd(
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       result,
    const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a,
    const Integer&                                                              v)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   eval_gcd(result, a, static_cast<limb_type>(v));
}
template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1, class Integer>
<<<<<<< HEAD
inline typename enable_if_c<is_signed<Integer>::value && (sizeof(Integer) <= sizeof(limb_type)) && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_gcd(
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, 
      const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a, 
      const Integer& v)
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_signed<Integer>::value && (sizeof(Integer) <= sizeof(limb_type)) && !is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_gcd(
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       result,
    const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a,
    const Integer&                                                              v)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   eval_gcd(result, a, static_cast<limb_type>(v < 0 ? -v : v));
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_gcd(
      cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, 
      const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a, 
      const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& b)
{
   using default_ops::eval_lsb;
   using default_ops::eval_is_zero;
   using default_ops::eval_get_sign;

   if(a.size() == 1)
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<!is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_gcd(
    cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>&       result,
    const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a,
    const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& b)
{
   using default_ops::eval_get_sign;
   using default_ops::eval_is_zero;
   using default_ops::eval_lsb;

   if (a.size() == 1)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      eval_gcd(result, b, *a.limbs());
      return;
   }
<<<<<<< HEAD
   if(b.size() == 1)
=======
   if (b.size() == 1)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      eval_gcd(result, a, *b.limbs());
      return;
   }

<<<<<<< HEAD
   int shift;

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> u(a), v(b);

   int s = eval_get_sign(u);

   /* GCD(0,x) := x */
<<<<<<< HEAD
   if(s < 0)
   {
      u.negate();
   }
   else if(s == 0)
=======
   if (s < 0)
   {
      u.negate();
   }
   else if (s == 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      result = v;
      return;
   }
   s = eval_get_sign(v);
<<<<<<< HEAD
   if(s < 0)
   {
      v.negate();
   }
   else if(s == 0)
=======
   if (s < 0)
   {
      v.negate();
   }
   else if (s == 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      result = u;
      return;
   }

   /* Let shift := lg K, where K is the greatest power of 2
   dividing both u and v. */

   unsigned us = eval_lsb(u);
   unsigned vs = eval_lsb(v);
<<<<<<< HEAD
   shift = (std::min)(us, vs);
   eval_right_shift(u, us);
   eval_right_shift(v, vs);

   do 
=======
   int shift   = (std::min)(us, vs);
   eval_right_shift(u, us);
   eval_right_shift(v, vs);

   do
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      /* Now u and v are both odd, so diff(u, v) is even.
      Let u = min(u, v), v = diff(u, v)/2. */
      s = u.compare(v);
<<<<<<< HEAD
      if(s > 0)
         u.swap(v);
      if(s == 0)
         break;
      if(v.size() <= 2)
      {
         if(v.size() == 1)
            u = integer_gcd_reduce(*v.limbs(), *u.limbs());
         else
         {
            double_limb_type i, j;
            i = v.limbs()[0] | (static_cast<double_limb_type>(v.limbs()[1]) << sizeof(limb_type) * CHAR_BIT);
            j = (u.size() == 1) ? *u.limbs() : u.limbs()[0] | (static_cast<double_limb_type>(u.limbs()[1]) << sizeof(limb_type) * CHAR_BIT);
=======
      if (s > 0)
         u.swap(v);
      if (s == 0)
         break;
      if (v.size() <= 2)
      {
         if (v.size() == 1)
            u = integer_gcd_reduce(*v.limbs(), *u.limbs());
         else
         {
            double_limb_type i = v.limbs()[0] | (static_cast<double_limb_type>(v.limbs()[1]) << sizeof(limb_type) * CHAR_BIT);
            double_limb_type j = (u.size() == 1) ? *u.limbs() : u.limbs()[0] | (static_cast<double_limb_type>(u.limbs()[1]) << sizeof(limb_type) * CHAR_BIT);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            u = integer_gcd_reduce(i, j);
         }
         break;
      }
      eval_subtract(v, u);
      vs = eval_lsb(v);
      eval_right_shift(v, vs);
<<<<<<< HEAD
   } 
   while(true);
=======
   } while (true);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

   result = u;
   eval_left_shift(result, shift);
}
//
// Now again for trivial backends:
//
template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
   eval_gcd(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& b) BOOST_NOEXCEPT
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value>::type
eval_gcd(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& b) BOOST_NOEXCEPT
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   *result.limbs() = boost::integer::gcd(*a.limbs(), *b.limbs());
}
// This one is only enabled for unchecked cpp_int's, for checked int's we need the checking in the default version:
template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
BOOST_MP_FORCEINLINE typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value && (Checked1 == unchecked)>::type
   eval_lcm(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& b) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
=======
BOOST_MP_FORCEINLINE BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value && (Checked1 == unchecked)>::type
eval_lcm(cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& b) BOOST_MP_NOEXCEPT_IF((is_non_throwing_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   *result.limbs() = boost::integer::lcm(*a.limbs(), *b.limbs());
   result.normalize(); // result may overflow the specified number of bits
}

inline void conversion_overflow(const mpl::int_<checked>&)
{
   BOOST_THROW_EXCEPTION(std::overflow_error("Overflow in conversion to narrower type"));
}
<<<<<<< HEAD
inline void conversion_overflow(const mpl::int_<unchecked>&){}

template <class R, unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
inline typename enable_if_c<
            is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value
            && is_signed_number<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value
            && boost::is_convertible<typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::local_limb_type, R>::value
         >::type
   eval_convert_to(R* result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val)
{
   typedef typename common_type<R, typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::local_limb_type>::type common_type;
   if(std::numeric_limits<R>::is_specialized && (static_cast<common_type>(*val.limbs()) > static_cast<common_type>((std::numeric_limits<R>::max)())))
   {
      if(val.isneg())
      {
         if(static_cast<common_type>(*val.limbs()) > -static_cast<common_type>((std::numeric_limits<R>::min)()))
=======
inline BOOST_MP_CXX14_CONSTEXPR void conversion_overflow(const mpl::int_<unchecked>&) {}

template <class R, unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<
    is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value && is_signed_number<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value && boost::is_convertible<typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::local_limb_type, R>::value>::type
eval_convert_to(R* result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val)
{
   typedef typename common_type<R, typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::local_limb_type>::type common_type;
   if (std::numeric_limits<R>::is_specialized && (static_cast<common_type>(*val.limbs()) > static_cast<common_type>((std::numeric_limits<R>::max)())))
   {
      if (val.isneg())
      {
         check_is_negative(mpl::bool_ < boost::is_signed<R>::value || (number_category<R>::value == number_kind_floating_point) > ());
         if (static_cast<common_type>(*val.limbs()) > -static_cast<common_type>((std::numeric_limits<R>::min)()))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            conversion_overflow(typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::checked_type());
         *result = (std::numeric_limits<R>::min)();
      }
      else
      {
         conversion_overflow(typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::checked_type());
<<<<<<< HEAD
         *result = (std::numeric_limits<R>::max)();
=======
         *result = boost::is_signed<R>::value ? (std::numeric_limits<R>::max)() : static_cast<R>(*val.limbs());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      }
   }
   else
   {
      *result = static_cast<R>(*val.limbs());
<<<<<<< HEAD
      if(val.isneg())
      {
         check_is_negative(mpl::bool_<is_signed_number<R>::value || (number_category<R>::value == number_kind_floating_point)>());
         *result = negate_integer(*result, mpl::bool_<is_signed_number<R>::value || (number_category<R>::value == number_kind_floating_point)>());
=======
      if (val.isneg())
      {
         check_is_negative(mpl::bool_ < boost::is_signed<R>::value || (number_category<R>::value == number_kind_floating_point) > ());
         *result = negate_integer(*result, mpl::bool_ < is_signed_number<R>::value || (number_category<R>::value == number_kind_floating_point) > ());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      }
   }
}

template <class R, unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<
            is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value
            && is_unsigned_number<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value
            && boost::is_convertible<typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::local_limb_type, R>::value
         >::type
   eval_convert_to(R* result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val)
{
   typedef typename common_type<R, typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::local_limb_type>::type common_type;
   if(std::numeric_limits<R>::is_specialized && (static_cast<common_type>(*val.limbs()) > static_cast<common_type>((std::numeric_limits<R>::max)())))
   {
      conversion_overflow(typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::checked_type());
      *result = (std::numeric_limits<R>::max)();
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<
    is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value && is_unsigned_number<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value && boost::is_convertible<typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::local_limb_type, R>::value>::type
eval_convert_to(R* result, const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val)
{
   typedef typename common_type<R, typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::local_limb_type>::type common_type;
   if (std::numeric_limits<R>::is_specialized && (static_cast<common_type>(*val.limbs()) > static_cast<common_type>((std::numeric_limits<R>::max)())))
   {
      conversion_overflow(typename cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>::checked_type());
      *result = boost::is_signed<R>::value ? (std::numeric_limits<R>::max)() : static_cast<R>(*val.limbs());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   }
   else
      *result = static_cast<R>(*val.limbs());
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
   eval_lsb(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   using default_ops::eval_get_sign;
   if(eval_get_sign(a) == 0)
   {
      BOOST_THROW_EXCEPTION(std::range_error("No bits were set in the operand."));
   }
   if(a.sign())
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
eval_lsb(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   using default_ops::eval_get_sign;
   if (eval_get_sign(a) == 0)
   {
      BOOST_THROW_EXCEPTION(std::range_error("No bits were set in the operand."));
   }
   if (a.sign())
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      BOOST_THROW_EXCEPTION(std::range_error("Testing individual bits in negative values is not supported - results are undefined."));
   }
   //
   // Find the index of the least significant bit within that limb:
   //
   return boost::multiprecision::detail::find_lsb(*a.limbs());
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
eval_msb_imp(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   //
   // Find the index of the least significant bit within that limb:
   //
   return boost::multiprecision::detail::find_msb(*a.limbs());
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
   eval_msb(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   using default_ops::eval_get_sign;
   if(eval_get_sign(a) == 0)
   {
      BOOST_THROW_EXCEPTION(std::range_error("No bits were set in the operand."));
   }
   if(a.sign())
=======
inline BOOST_MP_CXX14_CONSTEXPR typename enable_if_c<is_trivial_cpp_int<cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1> >::value, unsigned>::type
eval_msb(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& a)
{
   using default_ops::eval_get_sign;
   if (eval_get_sign(a) == 0)
   {
      BOOST_THROW_EXCEPTION(std::range_error("No bits were set in the operand."));
   }
   if (a.sign())
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      BOOST_THROW_EXCEPTION(std::range_error("Testing individual bits in negative values is not supported - results are undefined."));
   }
   return eval_msb_imp(a);
}

template <unsigned MinBits1, unsigned MaxBits1, cpp_integer_type SignType1, cpp_int_check_type Checked1, class Allocator1>
<<<<<<< HEAD
inline std::size_t hash_value(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val) BOOST_NOEXCEPT
{
   std::size_t result = 0;
   for(unsigned i = 0; i < val.size(); ++i)
=======
inline BOOST_MP_CXX14_CONSTEXPR std::size_t hash_value(const cpp_int_backend<MinBits1, MaxBits1, SignType1, Checked1, Allocator1>& val) BOOST_NOEXCEPT
{
   std::size_t result = 0;
   for (unsigned i = 0; i < val.size(); ++i)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      boost::hash_combine(result, val.limbs()[i]);
   }
   boost::hash_combine(result, val.sign());
   return result;
}

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

<<<<<<< HEAD
}}} // namespaces
=======
}}} // namespace boost::multiprecision::backends
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#endif
