//
// detail/signal_init.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
<<<<<<< HEAD
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
=======
// Copyright (c) 2003-2019 Christopher M. Kohlhoff (chris at kohlhoff dot com)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_DETAIL_SIGNAL_INIT_HPP
#define BOOST_ASIO_DETAIL_SIGNAL_INIT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

#if !defined(BOOST_ASIO_WINDOWS) && !defined(__CYGWIN__)

#include <csignal>

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace detail {

template <int Signal = SIGPIPE>
class signal_init
{
public:
  // Constructor.
  signal_init()
  {
    std::signal(Signal, SIG_IGN);
  }
};

} // namespace detail
} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

#endif // !defined(BOOST_ASIO_WINDOWS) && !defined(__CYGWIN__)

#endif // BOOST_ASIO_DETAIL_SIGNAL_INIT_HPP
