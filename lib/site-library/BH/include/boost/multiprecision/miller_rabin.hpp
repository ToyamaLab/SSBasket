///////////////////////////////////////////////////////////////
//  Copyright 2012 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
<<<<<<< HEAD
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_
=======
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#ifndef BOOST_MP_MR_HPP
#define BOOST_MP_MR_HPP

#include <boost/random.hpp>
#include <boost/multiprecision/integer.hpp>

<<<<<<< HEAD
namespace boost{
namespace multiprecision{
namespace detail{
=======
namespace boost {
namespace multiprecision {
namespace detail {
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

template <class I>
bool check_small_factors(const I& n)
{
   static const boost::uint32_t small_factors1[] = {
<<<<<<< HEAD
      3u, 5u, 7u, 11u, 13u, 17u, 19u, 23u };
=======
       3u, 5u, 7u, 11u, 13u, 17u, 19u, 23u};
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   static const boost::uint32_t pp1 = 223092870u;

   boost::uint32_t m1 = integer_modulus(n, pp1);

<<<<<<< HEAD
   for(unsigned i = 0; i < sizeof(small_factors1) / sizeof(small_factors1[0]); ++i)
   {
      BOOST_ASSERT(pp1 % small_factors1[i] == 0);
      if(m1 % small_factors1[i] == 0)
=======
   for (unsigned i = 0; i < sizeof(small_factors1) / sizeof(small_factors1[0]); ++i)
   {
      BOOST_ASSERT(pp1 % small_factors1[i] == 0);
      if (m1 % small_factors1[i] == 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
         return false;
   }

   static const boost::uint32_t small_factors2[] = {
<<<<<<< HEAD
      29u, 31u, 37u, 41u, 43u, 47u };
=======
       29u, 31u, 37u, 41u, 43u, 47u};
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   static const boost::uint32_t pp2 = 2756205443u;

   m1 = integer_modulus(n, pp2);

<<<<<<< HEAD
   for(unsigned i = 0; i < sizeof(small_factors2) / sizeof(small_factors2[0]); ++i)
   {
      BOOST_ASSERT(pp2 % small_factors2[i] == 0);
      if(m1 % small_factors2[i] == 0)
=======
   for (unsigned i = 0; i < sizeof(small_factors2) / sizeof(small_factors2[0]); ++i)
   {
      BOOST_ASSERT(pp2 % small_factors2[i] == 0);
      if (m1 % small_factors2[i] == 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
         return false;
   }

   static const boost::uint32_t small_factors3[] = {
<<<<<<< HEAD
      53u, 59u, 61u, 67u, 71u };
=======
       53u, 59u, 61u, 67u, 71u};
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   static const boost::uint32_t pp3 = 907383479u;

   m1 = integer_modulus(n, pp3);

<<<<<<< HEAD
   for(unsigned i = 0; i < sizeof(small_factors3) / sizeof(small_factors3[0]); ++i)
   {
      BOOST_ASSERT(pp3 % small_factors3[i] == 0);
      if(m1 % small_factors3[i] == 0)
=======
   for (unsigned i = 0; i < sizeof(small_factors3) / sizeof(small_factors3[0]); ++i)
   {
      BOOST_ASSERT(pp3 % small_factors3[i] == 0);
      if (m1 % small_factors3[i] == 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
         return false;
   }

   static const boost::uint32_t small_factors4[] = {
<<<<<<< HEAD
      73u, 79u, 83u, 89u, 97u };
=======
       73u, 79u, 83u, 89u, 97u};
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   static const boost::uint32_t pp4 = 4132280413u;

   m1 = integer_modulus(n, pp4);

<<<<<<< HEAD
   for(unsigned i = 0; i < sizeof(small_factors4) / sizeof(small_factors4[0]); ++i)
   {
      BOOST_ASSERT(pp4 % small_factors4[i] == 0);
      if(m1 % small_factors4[i] == 0)
=======
   for (unsigned i = 0; i < sizeof(small_factors4) / sizeof(small_factors4[0]); ++i)
   {
      BOOST_ASSERT(pp4 % small_factors4[i] == 0);
      if (m1 % small_factors4[i] == 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
         return false;
   }

   static const boost::uint32_t small_factors5[6][4] = {
<<<<<<< HEAD
      { 101u, 103u, 107u, 109u },
      { 113u, 127u, 131u, 137u },
      { 139u, 149u, 151u, 157u },
      { 163u, 167u, 173u, 179u },
      { 181u, 191u, 193u, 197u },
      { 199u, 211u, 223u, 227u }
   };
   static const boost::uint32_t pp5[6] = 
   { 
      121330189u, 
      113u * 127u * 131u * 137u, 
      139u * 149u * 151u * 157u,
      163u * 167u * 173u * 179u,
      181u * 191u * 193u * 197u,
      199u * 211u * 223u * 227u
   };

   for(unsigned k = 0; k < sizeof(pp5) / sizeof(*pp5); ++k)
   {
      m1 = integer_modulus(n, pp5[k]);

      for(unsigned i = 0; i < 4; ++i)
      {
         BOOST_ASSERT(pp5[k] % small_factors5[k][i] == 0);
         if(m1 % small_factors5[k][i] == 0)
=======
       {101u, 103u, 107u, 109u},
       {113u, 127u, 131u, 137u},
       {139u, 149u, 151u, 157u},
       {163u, 167u, 173u, 179u},
       {181u, 191u, 193u, 197u},
       {199u, 211u, 223u, 227u}};
   static const boost::uint32_t pp5[6] =
       {
           121330189u,
           113u * 127u * 131u * 137u,
           139u * 149u * 151u * 157u,
           163u * 167u * 173u * 179u,
           181u * 191u * 193u * 197u,
           199u * 211u * 223u * 227u};

   for (unsigned k = 0; k < sizeof(pp5) / sizeof(*pp5); ++k)
   {
      m1 = integer_modulus(n, pp5[k]);

      for (unsigned i = 0; i < 4; ++i)
      {
         BOOST_ASSERT(pp5[k] % small_factors5[k][i] == 0);
         if (m1 % small_factors5[k][i] == 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            return false;
      }
   }
   return true;
}

inline bool is_small_prime(unsigned n)
{
<<<<<<< HEAD
   static const unsigned char p[] = 
   {
      3u, 5u, 7u, 11u, 13u, 17u, 19u, 23u, 29u, 31u, 
      37u, 41u, 43u, 47u, 53u, 59u, 61u, 67u, 71u, 73u, 
      79u, 83u, 89u, 97u, 101u, 103u, 107u, 109u, 113u, 
      127u, 131u, 137u, 139u, 149u, 151u, 157u, 163u, 
      167u, 173u, 179u, 181u, 191u, 193u, 197u, 199u, 
      211u, 223u, 227u
   };
   for(unsigned i = 0; i < sizeof(p) / sizeof(*p); ++i)
   {
      if(n == p[i])
=======
   static const unsigned char p[] =
       {
           3u, 5u, 7u, 11u, 13u, 17u, 19u, 23u, 29u, 31u,
           37u, 41u, 43u, 47u, 53u, 59u, 61u, 67u, 71u, 73u,
           79u, 83u, 89u, 97u, 101u, 103u, 107u, 109u, 113u,
           127u, 131u, 137u, 139u, 149u, 151u, 157u, 163u,
           167u, 173u, 179u, 181u, 191u, 193u, 197u, 199u,
           211u, 223u, 227u};
   for (unsigned i = 0; i < sizeof(p) / sizeof(*p); ++i)
   {
      if (n == p[i])
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
         return true;
   }
   return false;
}

template <class I>
typename enable_if_c<is_convertible<I, unsigned>::value, unsigned>::type
<<<<<<< HEAD
   cast_to_unsigned(const I& val)
=======
cast_to_unsigned(const I& val)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   return static_cast<unsigned>(val);
}
template <class I>
typename disable_if_c<is_convertible<I, unsigned>::value, unsigned>::type
<<<<<<< HEAD
   cast_to_unsigned(const I& val)
=======
cast_to_unsigned(const I& val)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   return val.template convert_to<unsigned>();
}

} // namespace detail

template <class I, class Engine>
<<<<<<< HEAD
typename enable_if_c<number_category<I>::value == number_kind_integer, bool>::type 
   miller_rabin_test(const I& n, unsigned trials, Engine& gen)
{
#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable:4127)
=======
typename enable_if_c<number_category<I>::value == number_kind_integer, bool>::type
miller_rabin_test(const I& n, unsigned trials, Engine& gen)
{
#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable : 4127)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif
   typedef I number_type;

   if (n == 2)
<<<<<<< HEAD
      return true;  // Trivial special case.
   if(bit_test(n, 0) == 0)
      return false;  // n is even
   if(n <= 227)
      return detail::is_small_prime(detail::cast_to_unsigned(n));

   if(!detail::check_small_factors(n))
=======
      return true; // Trivial special case.
   if (bit_test(n, 0) == 0)
      return false; // n is even
   if (n <= 227)
      return detail::is_small_prime(detail::cast_to_unsigned(n));

   if (!detail::check_small_factors(n))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      return false;

   number_type nm1 = n - 1;
   //
   // Begin with a single Fermat test - it excludes a lot of candidates:
   //
   number_type q(228), x, y; // We know n is greater than this, as we've excluded small factors
   x = powm(q, nm1, n);
<<<<<<< HEAD
   if(x != 1u)
      return false;

   q = n - 1;
=======
   if (x != 1u)
      return false;

   q          = n - 1;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   unsigned k = lsb(q);
   q >>= k;

   // Declare our random number generator:
   boost::random::uniform_int_distribution<number_type> dist(2, n - 2);
   //
   // Execute the trials:
   //
<<<<<<< HEAD
   for(unsigned i = 0; i < trials; ++i)
   {
      x = dist(gen);
      y = powm(x, q, n);
      unsigned j = 0;
      while(true)
      {
         if(y == nm1)
            break;
         if(y == 1)
         {
            if(j == 0)
               break;
            return false; // test failed
         }
         if(++j == k)
=======
   for (unsigned i = 0; i < trials; ++i)
   {
      x          = dist(gen);
      y          = powm(x, q, n);
      unsigned j = 0;
      while (true)
      {
         if (y == nm1)
            break;
         if (y == 1)
         {
            if (j == 0)
               break;
            return false; // test failed
         }
         if (++j == k)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            return false; // failed
         y = powm(y, 2, n);
      }
   }
<<<<<<< HEAD
   return true;  // Yeheh! probably prime.
=======
   return true; // Yeheh! probably prime.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#ifdef BOOST_MSVC
#pragma warning(pop)
#endif
}

template <class I>
<<<<<<< HEAD
typename enable_if_c<number_category<I>::value == number_kind_integer, bool>::type 
   miller_rabin_test(const I& x, unsigned trials)
=======
typename enable_if_c<number_category<I>::value == number_kind_integer, bool>::type
miller_rabin_test(const I& x, unsigned trials)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   static mt19937 gen;
   return miller_rabin_test(x, trials, gen);
}

template <class tag, class Arg1, class Arg2, class Arg3, class Arg4, class Engine>
<<<<<<< HEAD
bool miller_rabin_test(const detail::expression<tag, Arg1, Arg2, Arg3, Arg4> & n, unsigned trials, Engine& gen)
=======
bool miller_rabin_test(const detail::expression<tag, Arg1, Arg2, Arg3, Arg4>& n, unsigned trials, Engine& gen)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   typedef typename detail::expression<tag, Arg1, Arg2, Arg3, Arg4>::result_type number_type;
   return miller_rabin_test(number_type(n), trials, gen);
}

template <class tag, class Arg1, class Arg2, class Arg3, class Arg4>
<<<<<<< HEAD
bool miller_rabin_test(const detail::expression<tag, Arg1, Arg2, Arg3, Arg4> & n, unsigned trials)
=======
bool miller_rabin_test(const detail::expression<tag, Arg1, Arg2, Arg3, Arg4>& n, unsigned trials)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
   typedef typename detail::expression<tag, Arg1, Arg2, Arg3, Arg4>::result_type number_type;
   return miller_rabin_test(number_type(n), trials);
}

<<<<<<< HEAD
}} // namespaces

#endif

=======
}} // namespace boost::multiprecision

#endif
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
