/*=============================================================================
    Copyright (c) 2001-2003 Hartmut Kaiser
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(SPIRIT_CLASSIC_VERSION_HPP)
#define SPIRIT_CLASSIC_VERSION_HPP

///////////////////////////////////////////////////////////////////////////////
//
<<<<<<< HEAD
//  This checks, whether the used Boost library is at least V1.32.0
//
///////////////////////////////////////////////////////////////////////////////
#include <boost/version.hpp>

#if BOOST_VERSION < 103200
#error "Spirit v1.8.x needs at least Boost V1.32.0 to compile successfully."
#endif

///////////////////////////////////////////////////////////////////////////////
//
//  This is the version of the current Spirit distribution
//
///////////////////////////////////////////////////////////////////////////////
#define SPIRIT_VERSION 0x1806
=======
//  This is the version of the current Spirit distribution
//
///////////////////////////////////////////////////////////////////////////////
#define SPIRIT_VERSION 0x1811
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#define SPIRIT_PIZZA_VERSION SPIRIT_MEGA_VEGGI  // :-)

#endif // defined(SPIRIT_VERSION_HPP)
