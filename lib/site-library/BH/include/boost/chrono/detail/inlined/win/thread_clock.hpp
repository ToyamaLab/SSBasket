//  boost thread_clock.cpp  -----------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  See http://www.boost.org/libs/chrono for documentation.

//--------------------------------------------------------------------------------------//
#ifndef BOOST_CHRONO_DETAIL_INLINED_WIN_THREAD_CLOCK_HPP
#define BOOST_CHRONO_DETAIL_INLINED_WIN_THREAD_CLOCK_HPP

#include <boost/chrono/config.hpp>
#include <boost/chrono/thread_clock.hpp>
#include <cassert>
#include <boost/assert.hpp>

#include <boost/detail/winapi/get_last_error.hpp>
#include <boost/detail/winapi/get_current_thread.hpp>
#include <boost/detail/winapi/get_thread_times.hpp>

namespace boost
{
namespace chrono
{

#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
thread_clock::time_point thread_clock::now( system::error_code & ec )
{
    //  note that Windows uses 100 nanosecond ticks for FILETIME
    boost::detail::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( boost::detail::winapi::GetThreadTimes(
            boost::detail::winapi::GetCurrentThread (), &creation, &exit,
            &system_time, &user_time ) )
    {
        duration user = duration(
                ((static_cast<duration::rep>(user_time.dwHighDateTime) << 32)
                        | user_time.dwLowDateTime) * 100 );

        duration system = duration(
                ((static_cast<duration::rep>(system_time.dwHighDateTime) << 32)
                        | system_time.dwLowDateTime) * 100 );

<<<<<<< HEAD
        if (!BOOST_CHRONO_IS_THROWS(ec))
=======
        if (!::boost::chrono::is_throws(ec))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            ec.clear();
        }
        return time_point(system+user);

    }
    else
    {
<<<<<<< HEAD
        if (BOOST_CHRONO_IS_THROWS(ec))
=======
        if (::boost::chrono::is_throws(ec))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            boost::throw_exception(
                    system::system_error(
                            boost::detail::winapi::GetLastError(),
<<<<<<< HEAD
                            BOOST_CHRONO_SYSTEM_CATEGORY,
=======
                            ::boost::system::system_category(),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                            "chrono::thread_clock" ));
        }
        else
        {
<<<<<<< HEAD
            ec.assign( boost::detail::winapi::GetLastError(), BOOST_CHRONO_SYSTEM_CATEGORY );
=======
            ec.assign( boost::detail::winapi::GetLastError(), ::boost::system::system_category() );
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            return thread_clock::time_point(duration(0));
        }
    }
}
#endif

thread_clock::time_point thread_clock::now() BOOST_NOEXCEPT
{

    //  note that Windows uses 100 nanosecond ticks for FILETIME
    boost::detail::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( boost::detail::winapi::GetThreadTimes(
            boost::detail::winapi::GetCurrentThread (), &creation, &exit,
            &system_time, &user_time ) )
    {
        duration user   = duration(
                ((static_cast<duration::rep>(user_time.dwHighDateTime) << 32)
                        | user_time.dwLowDateTime) * 100 );

        duration system = duration(
                ((static_cast<duration::rep>(system_time.dwHighDateTime) << 32)
                        | system_time.dwLowDateTime) * 100 );

        return time_point(system+user);
    }
    else
    {
      BOOST_ASSERT(0 && "Boost::Chrono - Internal Error");
      return time_point();
    }

}

} // namespace chrono
} // namespace boost

#endif
