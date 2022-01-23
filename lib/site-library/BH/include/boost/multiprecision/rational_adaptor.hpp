///////////////////////////////////////////////////////////////
//  Copyright 2011 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
<<<<<<< HEAD
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_
=======
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#ifndef BOOST_MATH_RATIONAL_ADAPTER_HPP
#define BOOST_MATH_RATIONAL_ADAPTER_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <boost/cstdint.hpp>
#include <boost/functional/hash_fwd.hpp>
#include <boost/multiprecision/number.hpp>
#ifdef BOOST_MSVC
<<<<<<< HEAD
#  pragma warning(push)
#  pragma warning(disable:4512 4127)
#endif
#include <boost/rational.hpp>
#ifdef BOOST_MSVC
#  pragma warning(pop)
#endif

namespace boost{
namespace multiprecision{
namespace backends{
=======
#pragma warning(push)
#pragma warning(disable : 4512 4127)
#endif
#include <boost/rational.hpp>
#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

namespace boost {
namespace multiprecision {
namespace backends {
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

template <class IntBackend>
struct rational_adaptor
{
<<<<<<< HEAD
   typedef number<IntBackend>                integer_type;
   typedef boost::rational<integer_type>        rational_type;

   typedef typename IntBackend::signed_types    signed_types;
   typedef typename IntBackend::unsigned_types  unsigned_types;
   typedef typename IntBackend::float_types     float_types;
=======
   typedef number<IntBackend>            integer_type;
   typedef boost::rational<integer_type> rational_type;

   typedef typename IntBackend::signed_types   signed_types;
   typedef typename IntBackend::unsigned_types unsigned_types;
   typedef typename IntBackend::float_types    float_types;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

   rational_adaptor() BOOST_MP_NOEXCEPT_IF(noexcept(rational_type())) {}
   rational_adaptor(const rational_adaptor& o) BOOST_MP_NOEXCEPT_IF(noexcept(std::declval<rational_type&>() = std::declval<const rational_type&>()))
   {
      m_value = o.m_value;
   }
   rational_adaptor(const IntBackend& o) BOOST_MP_NOEXCEPT_IF(noexcept(rational_type(std::declval<const IntBackend&>()))) : m_value(o) {}

   template <class U>
<<<<<<< HEAD
   rational_adaptor(const U& u, typename enable_if_c<is_convertible<U, IntBackend>::value>::type* = 0) 
      : m_value(static_cast<integer_type>(u)){}
   template <class U>
   explicit rational_adaptor(const U& u, 
      typename enable_if_c<
         boost::multiprecision::detail::is_explicitly_convertible<U, IntBackend>::value && !is_convertible<U, IntBackend>::value
      >::type* = 0) 
      : m_value(IntBackend(u)){}
   template <class U>
   typename enable_if_c<(boost::multiprecision::detail::is_explicitly_convertible<U, IntBackend>::value && !is_arithmetic<U>::value), rational_adaptor&>::type operator = (const U& u) 
=======
   rational_adaptor(const U& u, typename enable_if_c<is_convertible<U, IntBackend>::value>::type* = 0)
       : m_value(static_cast<integer_type>(u)) {}
   template <class U>
   explicit rational_adaptor(const U& u,
                             typename enable_if_c<
                                 boost::multiprecision::detail::is_explicitly_convertible<U, IntBackend>::value && !is_convertible<U, IntBackend>::value>::type* = 0)
       : m_value(IntBackend(u)) {}
   template <class U>
   typename enable_if_c<(boost::multiprecision::detail::is_explicitly_convertible<U, IntBackend>::value && !is_arithmetic<U>::value), rational_adaptor&>::type operator=(const U& u)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      m_value = IntBackend(u);
      return *this;
   }

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
<<<<<<< HEAD
   rational_adaptor(rational_adaptor&& o) BOOST_MP_NOEXCEPT_IF(noexcept(rational_type(std::declval<rational_type>()))) : m_value(static_cast<rational_type&&>(o.m_value)) {}
   rational_adaptor(IntBackend&& o) BOOST_MP_NOEXCEPT_IF(noexcept(rational_type(std::declval<IntBackend>()))) : m_value(static_cast<IntBackend&&>(o)) {}
   rational_adaptor& operator = (rational_adaptor&& o) BOOST_MP_NOEXCEPT_IF(noexcept(std::declval<rational_type&>() = std::declval<rational_type>()))
=======
   rational_adaptor(rational_adaptor&& o) BOOST_MP_NOEXCEPT_IF(noexcept(rational_type(std::declval<rational_type>()))) : m_value(static_cast<rational_type&&>(o.m_value))
   {}
   rational_adaptor(IntBackend&& o) BOOST_MP_NOEXCEPT_IF(noexcept(rational_type(std::declval<IntBackend>()))) : m_value(static_cast<IntBackend&&>(o)) {}
   rational_adaptor& operator=(rational_adaptor&& o) BOOST_MP_NOEXCEPT_IF(noexcept(std::declval<rational_type&>() = std::declval<rational_type>()))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      m_value = static_cast<rational_type&&>(o.m_value);
      return *this;
   }
#endif
<<<<<<< HEAD
   rational_adaptor& operator = (const rational_adaptor& o)
=======
   rational_adaptor& operator=(const rational_adaptor& o)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      m_value = o.m_value;
      return *this;
   }
<<<<<<< HEAD
   rational_adaptor& operator = (const IntBackend& o)
=======
   rational_adaptor& operator=(const IntBackend& o)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      m_value = o;
      return *this;
   }
   template <class Int>
<<<<<<< HEAD
   typename enable_if<is_integral<Int>, rational_adaptor&>::type operator = (Int i)
=======
   typename enable_if<is_integral<Int>, rational_adaptor&>::type operator=(Int i)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      m_value = i;
      return *this;
   }
   template <class Float>
<<<<<<< HEAD
   typename enable_if<is_floating_point<Float>, rational_adaptor&>::type operator = (Float i)
   {
      int e;
      Float f = std::frexp(i, &e);
      f = std::ldexp(f, std::numeric_limits<Float>::digits);
      e -= std::numeric_limits<Float>::digits;
      integer_type num(f);
      integer_type denom(1u);
      if(e > 0)
      {
         num <<= e;
      }
      else if(e < 0)
=======
   typename enable_if<is_floating_point<Float>, rational_adaptor&>::type operator=(Float i)
   {
      int   e;
      Float f = std::frexp(i, &e);
      f       = std::ldexp(f, std::numeric_limits<Float>::digits);
      e -= std::numeric_limits<Float>::digits;
      integer_type num(f);
      integer_type denom(1u);
      if (e > 0)
      {
         num <<= e;
      }
      else if (e < 0)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      {
         denom <<= -e;
      }
      m_value.assign(num, denom);
      return *this;
   }
<<<<<<< HEAD
   rational_adaptor& operator = (const char* s)
   {
      std::string s1;
      multiprecision::number<IntBackend> v1, v2;
      char c;
      bool have_hex = false;
      const char* p = s; // saved for later

      while((0 != (c = *s)) && (c == 'x' || c == 'X' || c == '-' || c == '+' || (c >= '0' && c <= '9') || (have_hex && (c >= 'a' && c <= 'f')) || (have_hex && (c >= 'A' && c <= 'F'))))
      {
         if(c == 'x' || c == 'X')
=======
   rational_adaptor& operator=(const char* s)
   {
      std::string                        s1;
      multiprecision::number<IntBackend> v1, v2;
      char                               c;
      bool                               have_hex = false;
      const char*                        p        = s; // saved for later

      while ((0 != (c = *s)) && (c == 'x' || c == 'X' || c == '-' || c == '+' || (c >= '0' && c <= '9') || (have_hex && (c >= 'a' && c <= 'f')) || (have_hex && (c >= 'A' && c <= 'F'))))
      {
         if (c == 'x' || c == 'X')
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            have_hex = true;
         s1.append(1, c);
         ++s;
      }
      v1.assign(s1);
      s1.erase();
<<<<<<< HEAD
      if(c == '/')
      {
         ++s;
         while((0 != (c = *s)) && (c == 'x' || c == 'X' || c == '-' || c == '+' || (c >= '0' && c <= '9') || (have_hex && (c >= 'a' && c <= 'f')) || (have_hex && (c >= 'A' && c <= 'F'))))
         {
            if(c == 'x' || c == 'X')
=======
      if (c == '/')
      {
         ++s;
         while ((0 != (c = *s)) && (c == 'x' || c == 'X' || c == '-' || c == '+' || (c >= '0' && c <= '9') || (have_hex && (c >= 'a' && c <= 'f')) || (have_hex && (c >= 'A' && c <= 'F'))))
         {
            if (c == 'x' || c == 'X')
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
               have_hex = true;
            s1.append(1, c);
            ++s;
         }
         v2.assign(s1);
      }
      else
         v2 = 1;
<<<<<<< HEAD
      if(*s)
=======
      if (*s)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      {
         BOOST_THROW_EXCEPTION(std::runtime_error(std::string("Could not parse the string \"") + p + std::string("\" as a valid rational number.")));
      }
      data().assign(v1, v2);
      return *this;
   }
   void swap(rational_adaptor& o)
   {
      std::swap(m_value, o.m_value);
   }
<<<<<<< HEAD
   std::string str(std::streamsize digits, std::ios_base::fmtflags f)const
=======
   std::string str(std::streamsize digits, std::ios_base::fmtflags f) const
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      //
      // We format the string ourselves so we can match what GMP's mpq type does:
      //
      std::string result = data().numerator().str(digits, f);
<<<<<<< HEAD
      if(data().denominator() != 1)
=======
      if (data().denominator() != 1)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      {
         result.append(1, '/');
         result.append(data().denominator().str(digits, f));
      }
      return result;
   }
   void negate()
   {
      m_value = -m_value;
   }
<<<<<<< HEAD
   int compare(const rational_adaptor& o)const
=======
   int compare(const rational_adaptor& o) const
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      return m_value > o.m_value ? 1 : (m_value < o.m_value ? -1 : 0);
   }
   template <class Arithmatic>
<<<<<<< HEAD
   typename enable_if_c<is_arithmetic<Arithmatic>::value && !is_floating_point<Arithmatic>::value, int>::type compare(Arithmatic i)const
=======
   typename enable_if_c<is_arithmetic<Arithmatic>::value && !is_floating_point<Arithmatic>::value, int>::type compare(Arithmatic i) const
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      return m_value > i ? 1 : (m_value < i ? -1 : 0);
   }
   template <class Arithmatic>
<<<<<<< HEAD
   typename enable_if_c<is_floating_point<Arithmatic>::value, int>::type compare(Arithmatic i)const
=======
   typename enable_if_c<is_floating_point<Arithmatic>::value, int>::type compare(Arithmatic i) const
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      rational_adaptor r;
      r = i;
      return this->compare(r);
   }
<<<<<<< HEAD
   rational_type& data() { return m_value; }
   const rational_type& data()const { return m_value; }
=======
   rational_type&       data() { return m_value; }
   const rational_type& data() const { return m_value; }
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

   template <class Archive>
   void serialize(Archive& ar, const mpl::true_&)
   {
      // Saving
      integer_type n(m_value.numerator()), d(m_value.denominator());
<<<<<<< HEAD
      ar & n;
      ar & d;
=======
      ar&          boost::make_nvp("numerator", n);
      ar&          boost::make_nvp("denominator", d);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   }
   template <class Archive>
   void serialize(Archive& ar, const mpl::false_&)
   {
      // Loading
      integer_type n, d;
<<<<<<< HEAD
      ar & n;
      ar & d;
=======
      ar&          boost::make_nvp("numerator", n);
      ar&          boost::make_nvp("denominator", d);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      m_value.assign(n, d);
   }
   template <class Archive>
   void serialize(Archive& ar, const unsigned int /*version*/)
   {
      typedef typename Archive::is_saving tag;
      serialize(ar, tag());
   }
<<<<<<< HEAD
private:
=======

 private:
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   rational_type m_value;
};

template <class IntBackend>
inline void eval_add(rational_adaptor<IntBackend>& result, const rational_adaptor<IntBackend>& o)
{
   result.data() += o.data();
}
template <class IntBackend>
inline void eval_subtract(rational_adaptor<IntBackend>& result, const rational_adaptor<IntBackend>& o)
{
   result.data() -= o.data();
}
template <class IntBackend>
inline void eval_multiply(rational_adaptor<IntBackend>& result, const rational_adaptor<IntBackend>& o)
{
   result.data() *= o.data();
}
template <class IntBackend>
inline void eval_divide(rational_adaptor<IntBackend>& result, const rational_adaptor<IntBackend>& o)
{
   using default_ops::eval_is_zero;
<<<<<<< HEAD
   if(eval_is_zero(o))
=======
   if (eval_is_zero(o))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   {
      BOOST_THROW_EXCEPTION(std::overflow_error("Divide by zero."));
   }
   result.data() /= o.data();
}

template <class R, class IntBackend>
inline typename enable_if_c<number_category<R>::value == number_kind_floating_point>::type eval_convert_to(R* result, const rational_adaptor<IntBackend>& backend)
{
   //
   // The generic conversion is as good as anything we can write here:
   //
   ::boost::multiprecision::detail::generic_convert_rational_to_float(*result, backend);
}

template <class R, class IntBackend>
inline typename enable_if_c<(number_category<R>::value != number_kind_integer) && (number_category<R>::value != number_kind_floating_point)>::type eval_convert_to(R* result, const rational_adaptor<IntBackend>& backend)
{
   typedef typename component_type<number<rational_adaptor<IntBackend> > >::type comp_t;
<<<<<<< HEAD
   comp_t num(backend.data().numerator());
   comp_t denom(backend.data().denominator());
=======
   comp_t                                                                        num(backend.data().numerator());
   comp_t                                                                        denom(backend.data().denominator());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   *result = num.template convert_to<R>();
   *result /= denom.template convert_to<R>();
}

template <class R, class IntBackend>
inline typename enable_if_c<number_category<R>::value == number_kind_integer>::type eval_convert_to(R* result, const rational_adaptor<IntBackend>& backend)
{
   typedef typename component_type<number<rational_adaptor<IntBackend> > >::type comp_t;
<<<<<<< HEAD
   comp_t t = backend.data().numerator();
=======
   comp_t                                                                        t = backend.data().numerator();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   t /= backend.data().denominator();
   *result = t.template convert_to<R>();
}

template <class IntBackend>
inline bool eval_is_zero(const rational_adaptor<IntBackend>& val)
{
<<<<<<< HEAD
=======
   using default_ops::eval_is_zero;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   return eval_is_zero(val.data().numerator().backend());
}
template <class IntBackend>
inline int eval_get_sign(const rational_adaptor<IntBackend>& val)
{
<<<<<<< HEAD
   return eval_get_sign(val.data().numerator().backend());
}

template<class IntBackend, class V>
=======
   using default_ops::eval_get_sign;
   return eval_get_sign(val.data().numerator().backend());
}

template <class IntBackend, class V>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
inline void assign_components(rational_adaptor<IntBackend>& result, const V& v1, const V& v2)
{
   result.data().assign(v1, v2);
}

template <class IntBackend>
inline std::size_t hash_value(const rational_adaptor<IntBackend>& val)
{
   std::size_t result = hash_value(val.data().numerator());
   boost::hash_combine(result, val.data().denominator());
   return result;
}

<<<<<<< HEAD

} // namespace backends

template<class IntBackend>
struct expression_template_default<backends::rational_adaptor<IntBackend> > : public expression_template_default<IntBackend> {};
   
template<class IntBackend>
struct number_category<backends::rational_adaptor<IntBackend> > : public mpl::int_<number_kind_rational>{};

using boost::multiprecision::backends::rational_adaptor;

template <class T>
struct component_type<rational_adaptor<T> >
{
   typedef number<T> type;
=======
} // namespace backends

template <class IntBackend>
struct expression_template_default<backends::rational_adaptor<IntBackend> > : public expression_template_default<IntBackend>
{};

template <class IntBackend>
struct number_category<backends::rational_adaptor<IntBackend> > : public mpl::int_<number_kind_rational>
{};

using boost::multiprecision::backends::rational_adaptor;

template <class Backend, expression_template_option ExpressionTemplates>
struct component_type<number<backends::rational_adaptor<Backend>, ExpressionTemplates> >
{
   typedef number<Backend, ExpressionTemplates> type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

template <class IntBackend, expression_template_option ET>
inline number<IntBackend, ET> numerator(const number<rational_adaptor<IntBackend>, ET>& val)
{
   return val.backend().data().numerator();
}
template <class IntBackend, expression_template_option ET>
inline number<IntBackend, ET> denominator(const number<rational_adaptor<IntBackend>, ET>& val)
{
   return val.backend().data().denominator();
}

#ifdef BOOST_NO_SFINAE_EXPR

<<<<<<< HEAD
namespace detail{

template<class U, class IntBackend>
struct is_explicitly_convertible<U, rational_adaptor<IntBackend> > : public is_explicitly_convertible<U, IntBackend> {};

}

#endif

}} // namespaces


namespace std{
=======
namespace detail {

template <class U, class IntBackend>
struct is_explicitly_convertible<U, rational_adaptor<IntBackend> > : public is_explicitly_convertible<U, IntBackend>
{};

} // namespace detail

#endif

}} // namespace boost::multiprecision

namespace std {
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

template <class IntBackend, boost::multiprecision::expression_template_option ExpressionTemplates>
class numeric_limits<boost::multiprecision::number<boost::multiprecision::rational_adaptor<IntBackend>, ExpressionTemplates> > : public std::numeric_limits<boost::multiprecision::number<IntBackend, ExpressionTemplates> >
{
<<<<<<< HEAD
   typedef std::numeric_limits<boost::multiprecision::number<IntBackend> > base_type;
   typedef boost::multiprecision::number<boost::multiprecision::rational_adaptor<IntBackend> > number_type;
public:
   BOOST_STATIC_CONSTEXPR bool is_integer = false;
   BOOST_STATIC_CONSTEXPR bool is_exact = true;
   BOOST_STATIC_CONSTEXPR number_type (min)() { return (base_type::min)(); }
   BOOST_STATIC_CONSTEXPR number_type (max)() { return (base_type::max)(); }
=======
   typedef std::numeric_limits<boost::multiprecision::number<IntBackend> >                     base_type;
   typedef boost::multiprecision::number<boost::multiprecision::rational_adaptor<IntBackend> > number_type;

 public:
   BOOST_STATIC_CONSTEXPR bool is_integer = false;
   BOOST_STATIC_CONSTEXPR bool is_exact   = true;
   BOOST_STATIC_CONSTEXPR      number_type(min)() { return (base_type::min)(); }
   BOOST_STATIC_CONSTEXPR      number_type(max)() { return (base_type::max)(); }
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   BOOST_STATIC_CONSTEXPR number_type lowest() { return -(max)(); }
   BOOST_STATIC_CONSTEXPR number_type epsilon() { return base_type::epsilon(); }
   BOOST_STATIC_CONSTEXPR number_type round_error() { return epsilon() / 2; }
   BOOST_STATIC_CONSTEXPR number_type infinity() { return base_type::infinity(); }
   BOOST_STATIC_CONSTEXPR number_type quiet_NaN() { return base_type::quiet_NaN(); }
   BOOST_STATIC_CONSTEXPR number_type signaling_NaN() { return base_type::signaling_NaN(); }
   BOOST_STATIC_CONSTEXPR number_type denorm_min() { return base_type::denorm_min(); }
};

#ifndef BOOST_NO_INCLASS_MEMBER_INITIALIZATION

template <class IntBackend, boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<boost::multiprecision::number<boost::multiprecision::rational_adaptor<IntBackend>, ExpressionTemplates> >::is_integer;
template <class IntBackend, boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<boost::multiprecision::number<boost::multiprecision::rational_adaptor<IntBackend>, ExpressionTemplates> >::is_exact;

#endif

<<<<<<< HEAD

}
=======
} // namespace std
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#endif
