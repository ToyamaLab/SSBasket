#ifndef BOOST_CORE_LIGHTWEIGHT_TEST_HPP
#define BOOST_CORE_LIGHTWEIGHT_TEST_HPP

// MS compatible compilers support #pragma once

#if defined(_MSC_VER)
# pragma once
#endif

//
//  boost/core/lightweight_test.hpp - lightweight test library
//
//  Copyright (c) 2002, 2009, 2014 Peter Dimov
//  Copyright (2) Beman Dawes 2010, 2011
//  Copyright (3) Ion Gaztanaga 2013
//
<<<<<<< HEAD
=======
//  Copyright 2018 Glen Joseph Fernandes
//  (glenjofe@gmail.com)
//
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

<<<<<<< HEAD
#include <boost/core/no_exceptions_support.hpp>
#include <boost/assert.hpp>
#include <boost/current_function.hpp>
#include <iostream>
#include <iterator>
=======
#include <boost/current_function.hpp>
#include <boost/config.hpp>
#include <iostream>
#include <iterator>
#include <cstdlib>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <cstring>
#include <cstddef>

//  IDE's like Visual Studio perform better if output goes to std::cout or
//  some other stream, so allow user to configure output stream:
#ifndef BOOST_LIGHTWEIGHT_TEST_OSTREAM
# define BOOST_LIGHTWEIGHT_TEST_OSTREAM std::cerr
#endif

namespace boost
{

namespace detail
{

<<<<<<< HEAD
struct report_errors_reminder
{
    bool called_report_errors_function;

    report_errors_reminder() : called_report_errors_function(false) {}

    ~report_errors_reminder()
    {
        BOOST_ASSERT(called_report_errors_function);  // verify report_errors() was called  
    }
};

inline report_errors_reminder& report_errors_remind()
{
    static report_errors_reminder r;
    return r;
}

inline int & test_errors()
{
    static int x = 0;
    report_errors_remind();
    return x;
=======
class test_result {
public:
    test_result()
        : report_(false)
        , errors_(0) {
#if defined(_MSC_VER) && (_MSC_VER > 1310)
        ::_set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
#endif
    }

    ~test_result() {
        if (!report_) {
            BOOST_LIGHTWEIGHT_TEST_OSTREAM << "main() should return report_errors()" << std::endl;
            std::abort();
        }
    }

    int& errors() {
        return errors_;
    }

    void done() {
        report_ = true;
    }

private:
    bool report_;
    int errors_;
};

inline test_result& test_results()
{
    static test_result instance;
    return instance;
}

inline int& test_errors()
{
    return test_results().errors();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

inline void test_failed_impl(char const * expr, char const * file, int line, char const * function)
{
    BOOST_LIGHTWEIGHT_TEST_OSTREAM
      << file << "(" << line << "): test '" << expr << "' failed in function '"
      << function << "'" << std::endl;
<<<<<<< HEAD
    ++test_errors();
=======
    ++test_results().errors();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

inline void error_impl(char const * msg, char const * file, int line, char const * function)
{
    BOOST_LIGHTWEIGHT_TEST_OSTREAM
      << file << "(" << line << "): " << msg << " in function '"
      << function << "'" << std::endl;
<<<<<<< HEAD
    ++test_errors();
=======
    ++test_results().errors();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

inline void throw_failed_impl(char const * excep, char const * file, int line, char const * function)
{
   BOOST_LIGHTWEIGHT_TEST_OSTREAM
    << file << "(" << line << "): Exception '" << excep << "' not thrown in function '"
    << function << "'" << std::endl;
<<<<<<< HEAD
   ++test_errors();
=======
   ++test_results().errors();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

// In the comparisons below, it is possible that T and U are signed and unsigned integer types, which generates warnings in some compilers.
// A cleaner fix would require common_type trait or some meta-programming, which would introduce a dependency on Boost.TypeTraits. To avoid
// the dependency we just disable the warnings.
<<<<<<< HEAD
#if defined(_MSC_VER)
# pragma warning(push)
# pragma warning(disable: 4389)
#elif defined(__clang__) && defined(__has_warning)
=======
#if defined(__clang__) && defined(__has_warning)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
# if __has_warning("-Wsign-compare")
#  pragma clang diagnostic push
  //#  pragma clang diagnostic ignored "-Wsign-compare"
# endif
<<<<<<< HEAD
=======
#elif defined(_MSC_VER)
# pragma warning(push)
# pragma warning(disable: 4389)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#elif defined(__GNUC__) && !(defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)) && (__GNUC__ * 100 + __GNUC_MINOR__) >= 406
# pragma GCC diagnostic push
  //# pragma GCC diagnostic ignored "-Wsign-compare"
#endif

// specialize test output for char pointers to avoid printing as cstring
template <class T> inline const T& test_output_impl(const T& v) { return v; }
inline const void* test_output_impl(const char* v) { return v; }
inline const void* test_output_impl(const unsigned char* v) { return v; }
inline const void* test_output_impl(const signed char* v) { return v; }
inline const void* test_output_impl(char* v) { return v; }
inline const void* test_output_impl(unsigned char* v) { return v; }
inline const void* test_output_impl(signed char* v) { return v; }
template<class T> inline const void* test_output_impl(T volatile* v) { return const_cast<T*>(v); }

#if !defined( BOOST_NO_CXX11_NULLPTR )
inline const void* test_output_impl(std::nullptr_t) { return nullptr; }
#endif

<<<<<<< HEAD
template<class T, class U> inline void test_eq_impl( char const * expr1, char const * expr2,
  char const * file, int line, char const * function, T const & t, U const & u )
{
    if( t == u )
    {
        report_errors_remind();
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
            << file << "(" << line << "): test '" << expr1 << " == " << expr2
            << "' failed in function '" << function << "': "
            << "'" << test_output_impl(t) << "' != '" << test_output_impl(u) << "'" << std::endl;
        ++test_errors();
    }
}

template<class T, class U> inline void test_ne_impl( char const * expr1, char const * expr2,
  char const * file, int line, char const * function, T const & t, U const & u )
{
    if( t != u )
    {
        report_errors_remind();
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
            << file << "(" << line << "): test '" << expr1 << " != " << expr2
            << "' failed in function '" << function << "': "
            << "'" << test_output_impl(t) << "' == '" << test_output_impl(u) << "'" << std::endl;
        ++test_errors();
    }
}

template<class T, class U> inline void test_lt_impl( char const * expr1, char const * expr2,
  char const * file, int line, char const * function, T const & t, U const & u )
{
    if( t < u )
    {
        report_errors_remind();
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
            << file << "(" << line << "): test '" << expr1 << " < " << expr2
            << "' failed in function '" << function << "': "
            << "'" << test_output_impl(t) << "' >= '" << test_output_impl(u) << "'" << std::endl;
        ++test_errors();
    }
}

template<class T, class U> inline void test_le_impl( char const * expr1, char const * expr2,
  char const * file, int line, char const * function, T const & t, U const & u )
{
    if( t <= u )
    {
        report_errors_remind();
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
            << file << "(" << line << "): test '" << expr1 << " <= " << expr2
            << "' failed in function '" << function << "': "
            << "'" << test_output_impl(t) << "' > '" << test_output_impl(u) << "'" << std::endl;
        ++test_errors();
    }
}

template<class T, class U> inline void test_gt_impl( char const * expr1, char const * expr2,
  char const * file, int line, char const * function, T const & t, U const & u )
{
    if( t > u )
    {
        report_errors_remind();
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
            << file << "(" << line << "): test '" << expr1 << " > " << expr2
            << "' failed in function '" << function << "': "
            << "'" << test_output_impl(t) << "' <= '" << test_output_impl(u) << "'" << std::endl;
        ++test_errors();
    }
}

template<class T, class U> inline void test_ge_impl( char const * expr1, char const * expr2,
  char const * file, int line, char const * function, T const & t, U const & u )
{
    if( t >= u )
    {
        report_errors_remind();
=======
struct lw_test_eq {
    template <typename T, typename U>
    bool operator()(const T& t, const U& u) const { return t == u; }
    static const char* op() { return "=="; }
};

struct lw_test_ne {
    template <typename T, typename U>
    bool operator()(const T& t, const U& u) const { return t != u; }
    static const char* op() { return "!="; }
};

struct lw_test_lt {
    template <typename T, typename U>
    bool operator()(const T& t, const U& u) const { return t < u; }
    static const char* op() { return "<"; }
};

struct lw_test_le {
    template <typename T, typename U>
    bool operator()(const T& t, const U& u) const { return t <= u; }
    static const char* op() { return "<="; }
};

struct lw_test_gt {
    template <typename T, typename U>
    bool operator()(const T& t, const U& u) const { return t > u; }
    static const char* op() { return ">"; }
};

struct lw_test_ge {
    template <typename T, typename U>
    bool operator()(const T& t, const U& u) const { return t >= u; }
    static const char* op() { return ">="; }
};

template<class BinaryPredicate, class T, class U>
inline void test_with_impl(BinaryPredicate pred, char const * expr1, char const * expr2,
                           char const * file, int line, char const * function,
                           T const & t, U const & u)
{
    if( pred(t, u) )
    {
        test_results();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
<<<<<<< HEAD
            << file << "(" << line << "): test '" << expr1 << " >= " << expr2
            << "' failed in function '" << function << "': "
            << "'" << test_output_impl(t) << "' < '" << test_output_impl(u) << "'" << std::endl;
        ++test_errors();
=======
            << file << "(" << line << "): test '" << expr1 << " " << pred.op() << " " << expr2
            << "' ('" << test_output_impl(t) << "' " << pred.op() << " '" << test_output_impl(u)
            << "') failed in function '" << function << "'" << std::endl;
        ++test_results().errors();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
}

inline void test_cstr_eq_impl( char const * expr1, char const * expr2,
  char const * file, int line, char const * function, char const * const t, char const * const u )
{
    if( std::strcmp(t, u) == 0 )
    {
<<<<<<< HEAD
        report_errors_remind();
=======
        test_results();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
<<<<<<< HEAD
            << file << "(" << line << "): test '" << expr1 << " == " << expr2
            << "' failed in function '" << function << "': "
            << "'" << t << "' != '" << u << "'" << std::endl;
        ++test_errors();
=======
            << file << "(" << line << "): test '" << expr1 << " == " << expr2 << "' ('" << t
            << "' == '" << u << "') failed in function '" << function << "'" << std::endl;
        ++test_results().errors();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
}

inline void test_cstr_ne_impl( char const * expr1, char const * expr2,
  char const * file, int line, char const * function, char const * const t, char const * const u )
{
    if( std::strcmp(t, u) != 0 )
    {
<<<<<<< HEAD
        report_errors_remind();
=======
        test_results();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
<<<<<<< HEAD
            << file << "(" << line << "): test '" << expr1 << " == " << expr2
            << "' failed in function '" << function << "': "
            << "'" << t << "' == '" << u << "'" << std::endl;
        ++test_errors();
=======
            << file << "(" << line << "): test '" << expr1 << " != " << expr2 << "' ('" << t
            << "' != '" << u << "') failed in function '" << function << "'" << std::endl;
        ++test_results().errors();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
}

template<class FormattedOutputFunction, class InputIterator1, class InputIterator2>
void test_all_eq_impl(FormattedOutputFunction& output,
                      char const * file, int line, char const * function,
                      InputIterator1 first_begin, InputIterator1 first_end,
                      InputIterator2 second_begin, InputIterator2 second_end)
{
    InputIterator1 first_it = first_begin;
    InputIterator2 second_it = second_begin;
    typename std::iterator_traits<InputIterator1>::difference_type first_index = 0;
    typename std::iterator_traits<InputIterator2>::difference_type second_index = 0;
    std::size_t error_count = 0;
    const std::size_t max_count = 8;
    do
    {
        while ((first_it != first_end) && (second_it != second_end) && (*first_it == *second_it))
        {
            ++first_it;
            ++second_it;
            ++first_index;
            ++second_index;
        }
        if ((first_it == first_end) || (second_it == second_end))
        {
            break; // do-while
        }
        if (error_count == 0)
        {
            output << file << "(" << line << "): Container contents differ in function '" << function << "':";
        }
        else if (error_count >= max_count)
        {
            output << " ...";
            break;
        }
        output << " [" << first_index << "] '" << test_output_impl(*first_it) << "' != '" << test_output_impl(*second_it) << "'";
        ++first_it;
        ++second_it;
        ++first_index;
        ++second_index;
        ++error_count;
    } while (first_it != first_end);

    first_index += std::distance(first_it, first_end);
    second_index += std::distance(second_it, second_end);
    if (first_index != second_index)
    {
        if (error_count == 0)
        {
            output << file << "(" << line << "): Container sizes differ in function '" << function << "': size(" << first_index << ") != size(" << second_index << ")";
        }
        else
        {
            output << " [*] size(" << first_index << ") != size(" << second_index << ")";
        }
        ++error_count;
    }

    if (error_count == 0)
    {
<<<<<<< HEAD
        boost::detail::report_errors_remind();
=======
        test_results();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
    else
    {
        output << std::endl;
<<<<<<< HEAD
        ++boost::detail::test_errors();
=======
        ++test_results().errors();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
}

template<class FormattedOutputFunction, class InputIterator1, class InputIterator2, typename BinaryPredicate>
void test_all_with_impl(FormattedOutputFunction& output,
                        char const * file, int line, char const * function,
                        InputIterator1 first_begin, InputIterator1 first_end,
                        InputIterator2 second_begin, InputIterator2 second_end,
                        BinaryPredicate predicate)
{
    InputIterator1 first_it = first_begin;
    InputIterator2 second_it = second_begin;
    typename std::iterator_traits<InputIterator1>::difference_type first_index = 0;
    typename std::iterator_traits<InputIterator2>::difference_type second_index = 0;
    std::size_t error_count = 0;
    const std::size_t max_count = 8;
    do
    {
        while ((first_it != first_end) && (second_it != second_end) && predicate(*first_it, *second_it))
        {
            ++first_it;
            ++second_it;
            ++first_index;
            ++second_index;
        }
        if ((first_it == first_end) || (second_it == second_end))
        {
            break; // do-while
        }
        if (error_count == 0)
        {
            output << file << "(" << line << "): Container contents differ in function '" << function << "':";
        }
        else if (error_count >= max_count)
        {
            output << " ...";
            break;
        }
        output << " [" << first_index << "]";
        ++first_it;
        ++second_it;
        ++first_index;
        ++second_index;
        ++error_count;
    } while (first_it != first_end);

    first_index += std::distance(first_it, first_end);
    second_index += std::distance(second_it, second_end);
    if (first_index != second_index)
    {
        if (error_count == 0)
        {
            output << file << "(" << line << "): Container sizes differ in function '" << function << "': size(" << first_index << ") != size(" << second_index << ")";
        }
        else
        {
            output << " [*] size(" << first_index << ") != size(" << second_index << ")";
        }
        ++error_count;
    }

    if (error_count == 0)
    {
<<<<<<< HEAD
        report_errors_remind();
=======
        test_results();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
    else
    {
        output << std::endl;
<<<<<<< HEAD
        ++test_errors();
    }
}

#if defined(_MSC_VER)
# pragma warning(pop)
#elif defined(__clang__) && defined(__has_warning)
# if __has_warning("-Wsign-compare")
#  pragma clang diagnostic pop
# endif
=======
        ++test_results().errors();
    }
}

#if defined(__clang__) && defined(__has_warning)
# if __has_warning("-Wsign-compare")
#  pragma clang diagnostic pop
# endif
#elif defined(_MSC_VER)
# pragma warning(pop)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#elif defined(__GNUC__) && !(defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)) && (__GNUC__ * 100 + __GNUC_MINOR__) >= 406
# pragma GCC diagnostic pop
#endif

} // namespace detail

inline int report_errors()
{
<<<<<<< HEAD
    boost::detail::report_errors_remind().called_report_errors_function = true;

    int errors = boost::detail::test_errors();
=======
    boost::detail::test_result& result = boost::detail::test_results();
    result.done();

    int errors = result.errors();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    if( errors == 0 )
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
          << "No errors detected." << std::endl;
<<<<<<< HEAD
        return 0;
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
          << errors << " error" << (errors == 1? "": "s") << " detected." << std::endl;
<<<<<<< HEAD
        return 1;
    }
=======
    }

    // `return report_errors();` from main only supports 8 bit exit codes
    return errors < 256? errors: 255;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

} // namespace boost

<<<<<<< HEAD
#define BOOST_TEST(expr) ((expr)? (void)0: ::boost::detail::test_failed_impl(#expr, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION))
=======
#define BOOST_TEST(expr) ((expr)? (void)::boost::detail::test_results(): ::boost::detail::test_failed_impl(#expr, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#define BOOST_TEST_NOT(expr) BOOST_TEST(!(expr))

#define BOOST_ERROR(msg) ( ::boost::detail::error_impl(msg, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION) )

<<<<<<< HEAD
#define BOOST_TEST_EQ(expr1,expr2) ( ::boost::detail::test_eq_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_NE(expr1,expr2) ( ::boost::detail::test_ne_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )

#define BOOST_TEST_LT(expr1,expr2) ( ::boost::detail::test_lt_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_LE(expr1,expr2) ( ::boost::detail::test_le_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_GT(expr1,expr2) ( ::boost::detail::test_gt_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_GE(expr1,expr2) ( ::boost::detail::test_ge_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
=======
#define BOOST_TEST_EQ(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_eq(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_NE(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_ne(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )

#define BOOST_TEST_LT(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_lt(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_LE(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_le(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_GT(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_gt(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_GE(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_ge(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#define BOOST_TEST_CSTR_EQ(expr1,expr2) ( ::boost::detail::test_cstr_eq_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_CSTR_NE(expr1,expr2) ( ::boost::detail::test_cstr_ne_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )

#define BOOST_TEST_ALL_EQ(begin1, end1, begin2, end2) ( ::boost::detail::test_all_eq_impl(BOOST_LIGHTWEIGHT_TEST_OSTREAM, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, begin1, end1, begin2, end2) )
#define BOOST_TEST_ALL_WITH(begin1, end1, begin2, end2, predicate) ( ::boost::detail::test_all_with_impl(BOOST_LIGHTWEIGHT_TEST_OSTREAM, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, begin1, end1, begin2, end2, predicate) )

#ifndef BOOST_NO_EXCEPTIONS
   #define BOOST_TEST_THROWS( EXPR, EXCEP )                    \
      try {                                                    \
         EXPR;                                                 \
         ::boost::detail::throw_failed_impl                    \
         (#EXCEP, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION); \
      }                                                        \
      catch(EXCEP const&) {                                    \
<<<<<<< HEAD
=======
         ::boost::detail::test_results();                      \
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      }                                                        \
      catch(...) {                                             \
         ::boost::detail::throw_failed_impl                    \
         (#EXCEP, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION); \
      }                                                        \
   //
#else
   #define BOOST_TEST_THROWS( EXPR, EXCEP )
#endif

#endif // #ifndef BOOST_CORE_LIGHTWEIGHT_TEST_HPP
