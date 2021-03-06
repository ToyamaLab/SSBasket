//
// detail/handler_work.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~
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

#ifndef BOOST_ASIO_DETAIL_HANDLER_WORK_HPP
#define BOOST_ASIO_DETAIL_HANDLER_WORK_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>
#include <boost/asio/associated_executor.hpp>
#include <boost/asio/detail/handler_invoke_helpers.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace detail {

// A helper class template to allow completion handlers to be dispatched
// through either the new executors framework or the old invocaton hook. The
// primary template uses the new executors framework.
<<<<<<< HEAD
template <typename Handler, typename Executor
    = typename associated_executor<Handler>::type>
=======
template <typename Handler,
    typename IoExecutor = system_executor, typename HandlerExecutor
      = typename associated_executor<Handler, IoExecutor>::type>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
class handler_work
{
public:
  explicit handler_work(Handler& handler) BOOST_ASIO_NOEXCEPT
<<<<<<< HEAD
    : executor_(associated_executor<Handler>::get(handler))
=======
    : io_executor_(),
      executor_(boost::asio::get_associated_executor(handler, io_executor_))
  {
  }

  handler_work(Handler& handler, const IoExecutor& io_ex) BOOST_ASIO_NOEXCEPT
    : io_executor_(io_ex),
      executor_(boost::asio::get_associated_executor(handler, io_executor_))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
  }

  static void start(Handler& handler) BOOST_ASIO_NOEXCEPT
  {
<<<<<<< HEAD
    Executor ex(associated_executor<Handler>::get(handler));
    ex.on_work_started();
=======
    HandlerExecutor ex(boost::asio::get_associated_executor(handler));
    ex.on_work_started();
  }

  static void start(Handler& handler,
      const IoExecutor& io_ex) BOOST_ASIO_NOEXCEPT
  {
    HandlerExecutor ex(boost::asio::get_associated_executor(handler, io_ex));
    ex.on_work_started();
    io_ex.on_work_started();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  ~handler_work()
  {
<<<<<<< HEAD
=======
    io_executor_.on_work_finished();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    executor_.on_work_finished();
  }

  template <typename Function>
  void complete(Function& function, Handler& handler)
  {
    executor_.dispatch(BOOST_ASIO_MOVE_CAST(Function)(function),
<<<<<<< HEAD
        associated_allocator<Handler>::get(handler));
=======
        boost::asio::get_associated_allocator(handler));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

private:
  // Disallow copying and assignment.
  handler_work(const handler_work&);
  handler_work& operator=(const handler_work&);

<<<<<<< HEAD
  typename associated_executor<Handler>::type executor_;
=======
  IoExecutor io_executor_;
  HandlerExecutor executor_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

// This specialisation dispatches a handler through the old invocation hook.
// The specialisation is not strictly required for correctness, as the
// system_executor will dispatch through the hook anyway. However, by doing
// this we avoid an extra copy of the handler.
template <typename Handler>
<<<<<<< HEAD
class handler_work<Handler, system_executor>
=======
class handler_work<Handler, system_executor, system_executor>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
public:
  explicit handler_work(Handler&) BOOST_ASIO_NOEXCEPT {}
  static void start(Handler&) BOOST_ASIO_NOEXCEPT {}
  ~handler_work() {}

  template <typename Function>
  void complete(Function& function, Handler& handler)
  {
    boost_asio_handler_invoke_helpers::invoke(function, handler);
  }

private:
  // Disallow copying and assignment.
  handler_work(const handler_work&);
  handler_work& operator=(const handler_work&);
};

} // namespace detail
} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_DETAIL_HANDLER_WORK_HPP
