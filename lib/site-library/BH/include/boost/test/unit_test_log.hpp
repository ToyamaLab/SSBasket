//  (C) Copyright Gennadiy Rozental 2001.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
/// @file
/// @brief defines singleton class unit_test_log and all manipulators.
/// unit_test_log has output stream like interface. It's implementation is
/// completely hidden with pimple idiom
// ***************************************************************************

#ifndef BOOST_TEST_UNIT_TEST_LOG_HPP_071894GER
#define BOOST_TEST_UNIT_TEST_LOG_HPP_071894GER

// Boost.Test
#include <boost/test/tree/observer.hpp>

#include <boost/test/detail/global_typedef.hpp>
#include <boost/test/detail/log_level.hpp>
#include <boost/test/detail/fwd_decl.hpp>

#include <boost/test/utils/wrap_stringstream.hpp>
<<<<<<< HEAD
#include <boost/test/utils/trivial_singleton.hpp>
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/test/utils/lazy_ostream.hpp>

// Boost

// STL
#include <iosfwd>   // for std::ostream&

#include <boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace boost {
namespace unit_test {

// ************************************************************************** //
// **************                log manipulators              ************** //
// ************************************************************************** //

namespace log {

struct BOOST_TEST_DECL begin {
    begin( const_string fn, std::size_t ln )
    : m_file_name( fn )
    , m_line_num( ln )
    {}

    const_string m_file_name;
    std::size_t m_line_num;
};

struct end {};

} // namespace log

// ************************************************************************** //
// **************             entry_value_collector            ************** //
// ************************************************************************** //

namespace ut_detail {

class BOOST_TEST_DECL entry_value_collector {
public:
    // Constructors
    entry_value_collector() : m_last( true ) {}
    entry_value_collector( entry_value_collector const& rhs ) : m_last( true ) { rhs.m_last = false; }
    ~entry_value_collector();

    // collection interface
    entry_value_collector const& operator<<( lazy_ostream const& ) const;
    entry_value_collector const& operator<<( const_string ) const;

private:
    // Data members
    mutable bool    m_last;
};

} // namespace ut_detail

// ************************************************************************** //
// **************                 unit_test_log                ************** //
// ************************************************************************** //

/// @brief Manages the sets of loggers, their streams and log levels
///
/// The Boost.Test framework allows for having several formatters/loggers at the same time, each of which
/// having their own log level and output stream.
///
/// This class serves the purpose of
/// - exposing an interface to the test framework (as a boost::unit_test::test_observer)
/// - exposing an interface to the testing tools
/// - managing several loggers
///
/// @note Accesses to the functions exposed by this class are made through the singleton
///   @c boost::unit_test::unit_test_log.
///
/// Users/developers willing to implement their own formatter need to:
/// - implement a boost::unit_test::unit_test_log_formatter that will output the desired format
/// - register the formatter during a eg. global fixture using the method @c set_formatter (though the framework singleton).
///
/// @warning this observer has a higher priority than the @ref boost::unit_test::results_collector_t. This means
/// that the various @ref boost::unit_test::test_results associated to each test unit may not be available at the time
/// the @c test_unit_start, @c test_unit_finish ... are called.
///
/// @see
/// - boost::unit_test::test_observer
/// - boost::unit_test::unit_test_log_formatter
<<<<<<< HEAD
class BOOST_TEST_DECL unit_test_log_t : public test_observer, public singleton<unit_test_log_t> {
=======
class BOOST_TEST_DECL unit_test_log_t : public test_observer {
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
public:
    // test_observer interface implementation
    virtual void        test_start( counter_t test_cases_amount );
    virtual void        test_finish();
    virtual void        test_aborted();

    virtual void        test_unit_start( test_unit const& );
    virtual void        test_unit_finish( test_unit const&, unsigned long elapsed );
    virtual void        test_unit_skipped( test_unit const&, const_string );
    virtual void        test_unit_aborted( test_unit const& );
<<<<<<< HEAD
=======
    virtual void        test_unit_timed_out( test_unit const& );
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    virtual void        exception_caught( execution_exception const& ex );

    virtual int         priority() { return 2; }

    // log configuration methods
    //! Sets the stream for all loggers
    //!
    //! This will override the log sink/stream of all loggers, whether enabled or not.
    void                set_stream( std::ostream& );

    //! Sets the stream for specific logger
    //!
    //! @note Has no effect if the specified format is not found
    //! @par Since Boost 1.62
    void                set_stream( output_format, std::ostream& );

<<<<<<< HEAD
=======
    //! Returns a pointer to the stream associated to specific logger
    //!
    //! @note Returns a null pointer if the format is not found
    //! @par Since Boost 1.67
    std::ostream*       get_stream( output_format ) const;


>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    //! Sets the threshold level for all loggers/formatters.
    //!
    //! This will override the log level of all loggers, whether enabled or not.
    void                set_threshold_level( log_level );

    //! Sets the threshold/log level of a specific format
    //!
    //! @note Has no effect if the specified format is not found
    //! @par Since Boost 1.62
    void                set_threshold_level( output_format, log_level );

    //! Add a format to the set of loggers
    //!
    //! Adding a logger means that the specified logger is enabled. The log level is managed by the formatter itself
    //! and specifies what events are forwarded to the underlying formatter.
    //! @par Since Boost 1.62
    void                add_format( output_format );

    //! Sets the format of the logger
    //!
    //! This will become the only active format of the logs.
    void                set_format( output_format );

    //! Returns the logger instance for a specific format.
    //!
    //! @returns the logger/formatter instance, or @c (unit_test_log_formatter*)0 if the format is not found.
    //! @par Since Boost 1.62
    unit_test_log_formatter* get_formatter( output_format );

    //! Sets the logger instance
    //!
    //! The specified logger becomes the unique active one. The custom log formatter has the
    //! format @c OF_CUSTOM_LOGGER. If such a format exists already, its formatter gets replaced by the one
    //! given in argument.
    //!
    //! The log level and output stream of the new formatter are taken from the currently active logger. In case
    //! several loggers are active, the order of priority is CUSTOM, HRF, XML, and JUNIT.
    //! If (unit_test_log_formatter*)0 is given as argument, the custom logger (if any) is removed.
    //!
    //! @note The ownership of the pointer is transfered to the Boost.Test framework. This call is equivalent to
    //! - a call to @c add_formatter
    //! - a call to @c set_format(OF_CUSTOM_LOGGER)
    //! - a configuration of the newly added logger with a previously configured stream and log level.
    void                set_formatter( unit_test_log_formatter* );

    //! Adds a custom log formatter to the set of formatters
    //!
    //! The specified logger is added with the format @c OF_CUSTOM_LOGGER, such that it can
    //! be futher selected or its stream/log level can be specified.
    //! If there is already a custom logger (with @c OF_CUSTOM_LOGGER), then
    //! the existing one gets replaced by the one given in argument.
    //! The provided logger is added with an enabled state.
    //! If (unit_test_log_formatter*)0 is given as argument, the custom logger (if any) is removed and
    //! no other action is performed.
    //!
    //! @note The ownership of the pointer is transfered to the Boost.Test framework.
    //! @par Since Boost 1.62
    void                add_formatter( unit_test_log_formatter* the_formatter );

    // test progress logging
    void                set_checkpoint( const_string file, std::size_t line_num, const_string msg = const_string() );

    // entry logging
    unit_test_log_t&    operator<<( log::begin const& );        // begin entry
    unit_test_log_t&    operator<<( log::end const& );          // end entry
    unit_test_log_t&    operator<<( log_level );                // set entry level
    unit_test_log_t&    operator<<( const_string );             // log entry value
    unit_test_log_t&    operator<<( lazy_ostream const& );      // log entry value

    ut_detail::entry_value_collector operator()( log_level );   // initiate entry collection

private:
    // Implementation helpers
    bool                log_entry_start(output_format log_format);
    void                log_entry_context( log_level l );
    void                clear_entry_context();

<<<<<<< HEAD
=======
    // Singleton
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    BOOST_TEST_SINGLETON_CONS( unit_test_log_t )
}; // unit_test_log_t

BOOST_TEST_SINGLETON_INST( unit_test_log )

// helper macros
#define BOOST_TEST_LOG_ENTRY( ll )                                                  \
    (::boost::unit_test::unit_test_log                                              \
        << ::boost::unit_test::log::begin( BOOST_TEST_L(__FILE__), __LINE__ ))(ll)  \
/**/

} // namespace unit_test
} // namespace boost

// ************************************************************************** //
// **************       Unit test log interface helpers        ************** //
// ************************************************************************** //

// messages sent by the framework
#define BOOST_TEST_FRAMEWORK_MESSAGE( M )                       \
   (::boost::unit_test::unit_test_log                           \
        << ::boost::unit_test::log::begin(                      \
                "boost.test framework",                         \
<<<<<<< HEAD
                __LINE__ ))                                     \
=======
                0 ))                                     \
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
             ( ::boost::unit_test::log_messages )               \
    << BOOST_TEST_LAZY_MSG( M )                                 \
/**/


#define BOOST_TEST_MESSAGE( M )                                 \
    BOOST_TEST_LOG_ENTRY( ::boost::unit_test::log_messages )    \
    << BOOST_TEST_LAZY_MSG( M )                                 \
/**/

//____________________________________________________________________________//

#define BOOST_TEST_PASSPOINT()                                  \
    ::boost::unit_test::unit_test_log.set_checkpoint(           \
        BOOST_TEST_L(__FILE__),                                 \
        static_cast<std::size_t>(__LINE__) )                    \
/**/

//____________________________________________________________________________//

#define BOOST_TEST_CHECKPOINT( M )                              \
    ::boost::unit_test::unit_test_log.set_checkpoint(           \
        BOOST_TEST_L(__FILE__),                                 \
        static_cast<std::size_t>(__LINE__),                     \
        (::boost::wrap_stringstream().ref() << M).str() )       \
/**/

//____________________________________________________________________________//

#include <boost/test/detail/enable_warnings.hpp>

#endif // BOOST_TEST_UNIT_TEST_LOG_HPP_071894GER

