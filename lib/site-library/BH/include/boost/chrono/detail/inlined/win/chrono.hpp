//  win/chrono.cpp  --------------------------------------------------------------//

//  Copyright Beman Dawes 2008
//  Copyright 2009-2010 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//----------------------------------------------------------------------------//
//                                Windows                                     //
//----------------------------------------------------------------------------//
#ifndef BOOST_CHRONO_DETAIL_INLINED_WIN_CHRONO_HPP
#define BOOST_CHRONO_DETAIL_INLINED_WIN_CHRONO_HPP

<<<<<<< HEAD
#include <boost/detail/winapi/time.hpp>
#include <boost/detail/winapi/timers.hpp>
#include <boost/detail/winapi/get_last_error.hpp>
=======
#include <boost/winapi/time.hpp>
#include <boost/winapi/timers.hpp>
#include <boost/winapi/get_last_error.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/assert.hpp>

namespace boost
{
namespace chrono
{
namespace chrono_detail
{

  BOOST_CHRONO_INLINE double get_nanosecs_per_tic() BOOST_NOEXCEPT
  {
<<<<<<< HEAD
      boost::detail::winapi::LARGE_INTEGER_ freq;
      if ( !boost::detail::winapi::QueryPerformanceFrequency( &freq ) )
=======
      boost::winapi::LARGE_INTEGER_ freq;
      if ( !boost::winapi::QueryPerformanceFrequency( &freq ) )
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
          return 0.0L;
      return double(1000000000.0L / freq.QuadPart);
  }

}

  steady_clock::time_point steady_clock::now() BOOST_NOEXCEPT
  {
    double nanosecs_per_tic = chrono_detail::get_nanosecs_per_tic();

<<<<<<< HEAD
    boost::detail::winapi::LARGE_INTEGER_ pcount;
=======
    boost::winapi::LARGE_INTEGER_ pcount;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    if ( nanosecs_per_tic <= 0.0L )
    {
      BOOST_ASSERT(0 && "Boost::Chrono - get_nanosecs_per_tic Internal Error");
      return steady_clock::time_point();
    }
    unsigned times=0;
<<<<<<< HEAD
    while ( ! boost::detail::winapi::QueryPerformanceCounter( &pcount ) )
=======
    while ( ! boost::winapi::QueryPerformanceCounter( &pcount ) )
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    {
      if ( ++times > 3 )
      {
        BOOST_ASSERT(0 && "Boost::Chrono - QueryPerformanceCounter Internal Error");
        return steady_clock::time_point();
      }
    }

    return steady_clock::time_point(steady_clock::duration(
      static_cast<steady_clock::rep>((nanosecs_per_tic) * pcount.QuadPart)));
  }


#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
  steady_clock::time_point steady_clock::now( system::error_code & ec )
  {
    double nanosecs_per_tic = chrono_detail::get_nanosecs_per_tic();

<<<<<<< HEAD
    boost::detail::winapi::LARGE_INTEGER_ pcount;
    if ( (nanosecs_per_tic <= 0.0L)
            || (!boost::detail::winapi::QueryPerformanceCounter( &pcount )) )
    {
        boost::detail::winapi::DWORD_ cause =
            ((nanosecs_per_tic <= 0.0L)
                    ? ERROR_NOT_SUPPORTED
                    : boost::detail::winapi::GetLastError());
        if (BOOST_CHRONO_IS_THROWS(ec)) {
            boost::throw_exception(
                    system::system_error(
                            cause,
                            BOOST_CHRONO_SYSTEM_CATEGORY,
=======
    boost::winapi::LARGE_INTEGER_ pcount;
    if ( (nanosecs_per_tic <= 0.0L)
            || (!boost::winapi::QueryPerformanceCounter( &pcount )) )
    {
        boost::winapi::DWORD_ cause =
            ((nanosecs_per_tic <= 0.0L)
                    ? ERROR_NOT_SUPPORTED
                    : boost::winapi::GetLastError());
        if (::boost::chrono::is_throws(ec)) {
            boost::throw_exception(
                    system::system_error(
                            cause,
                            ::boost::system::system_category(),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                            "chrono::steady_clock" ));
        }
        else
        {
<<<<<<< HEAD
            ec.assign( cause, BOOST_CHRONO_SYSTEM_CATEGORY );
=======
            ec.assign( cause, ::boost::system::system_category() );
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            return steady_clock::time_point(duration(0));
        }
    }

<<<<<<< HEAD
    if (!BOOST_CHRONO_IS_THROWS(ec))
=======
    if (!::boost::chrono::is_throws(ec))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    {
        ec.clear();
    }
    return time_point(duration(
      static_cast<steady_clock::rep>(nanosecs_per_tic * pcount.QuadPart)));
  }
#endif

  BOOST_CHRONO_INLINE
  system_clock::time_point system_clock::now() BOOST_NOEXCEPT
  {
<<<<<<< HEAD
    boost::detail::winapi::FILETIME_ ft;
    boost::detail::winapi::GetSystemTimeAsFileTime( &ft );  // never fails
=======
    boost::winapi::FILETIME_ ft;
    boost::winapi::GetSystemTimeAsFileTime( &ft );  // never fails
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    return system_clock::time_point(
      system_clock::duration(
        ((static_cast<__int64>( ft.dwHighDateTime ) << 32) | ft.dwLowDateTime)
       - 116444736000000000LL
       //- (134775LL*864000000000LL)
      )
    );
  }

#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
  BOOST_CHRONO_INLINE
  system_clock::time_point system_clock::now( system::error_code & ec )
  {
<<<<<<< HEAD
    boost::detail::winapi::FILETIME_ ft;
    boost::detail::winapi::GetSystemTimeAsFileTime( &ft );  // never fails
    if (!BOOST_CHRONO_IS_THROWS(ec))
=======
    boost::winapi::FILETIME_ ft;
    boost::winapi::GetSystemTimeAsFileTime( &ft );  // never fails
    if (!::boost::chrono::is_throws(ec))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    {
        ec.clear();
    }
    return system_clock::time_point(
      system_clock::duration(
       ((static_cast<__int64>( ft.dwHighDateTime ) << 32) | ft.dwLowDateTime)
       - 116444736000000000LL
       //- (134775LL*864000000000LL)
       ));
  }
#endif

  BOOST_CHRONO_INLINE
  std::time_t system_clock::to_time_t(const system_clock::time_point& t) BOOST_NOEXCEPT
  {
      __int64 temp = t.time_since_epoch().count();
      temp /= 10000000;
      return static_cast<std::time_t>( temp );
  }

  BOOST_CHRONO_INLINE
  system_clock::time_point system_clock::from_time_t(std::time_t t) BOOST_NOEXCEPT
  {
      __int64 temp = t;
      temp *= 10000000;
      return time_point(duration(temp));
  }

}  // namespace chrono
}  // namespace boost

#endif
