//  (C) Copyright Gennadiy Rozental 2001.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
/// @file
/// @brief defines specific version of execution monitor used to managed run unit of test cases
///
/// Translates execution exception into error level
// ***************************************************************************

#ifndef BOOST_TEST_UNIT_TEST_MONITOR_HPP_020905GER
#define BOOST_TEST_UNIT_TEST_MONITOR_HPP_020905GER

// Boost.Test
#include <boost/test/execution_monitor.hpp>
#include <boost/test/detail/fwd_decl.hpp>
<<<<<<< HEAD
#include <boost/test/utils/trivial_singleton.hpp>
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#include <boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace boost {
namespace unit_test {

// ************************************************************************** //
// **************               unit_test_monitor              ************** //
// ************************************************************************** //

<<<<<<< HEAD
class BOOST_TEST_DECL unit_test_monitor_t : public singleton<unit_test_monitor_t>, public execution_monitor {
public:
    enum error_level {
        test_ok                 =  0,
        precondition_failure    = -1,
=======
class BOOST_TEST_DECL unit_test_monitor_t :public execution_monitor {
public:
    enum error_level {
        test_ok                 =  0,
        /// Indicates a failure to prepare the unit test (eg. fixture). Does not
        /// account for tests skipped because of parent tests failed/skipped.
        test_setup_failure    = -1,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        unexpected_exception    = -2,
        os_exception            = -3,
        os_timeout              = -4,
        fatal_error             = -5  // includes both system and user
    };

    static bool is_critical_error( error_level e ) { return e <= fatal_error; }

    // monitor method
<<<<<<< HEAD
    error_level execute_and_translate( boost::function<void ()> const& func, unsigned timeout = 0 );

private:
=======
    // timeout is expressed in seconds
    error_level execute_and_translate( boost::function<void ()> const& func, unsigned long int timeout_microseconds = 0 );

    // singleton pattern
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    BOOST_TEST_SINGLETON_CONS( unit_test_monitor_t )
};

BOOST_TEST_SINGLETON_INST( unit_test_monitor )

} // namespace unit_test
} // namespace boost

#include <boost/test/detail/enable_warnings.hpp>

#endif // BOOST_TEST_UNIT_TEST_MONITOR_HPP_020905GER
