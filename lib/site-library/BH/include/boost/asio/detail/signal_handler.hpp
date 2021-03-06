//
// detail/signal_handler.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~
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

#ifndef BOOST_ASIO_DETAIL_SIGNAL_HANDLER_HPP
#define BOOST_ASIO_DETAIL_SIGNAL_HANDLER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>
#include <boost/asio/detail/bind_handler.hpp>
#include <boost/asio/detail/fenced_block.hpp>
#include <boost/asio/detail/handler_alloc_helpers.hpp>
#include <boost/asio/detail/handler_invoke_helpers.hpp>
#include <boost/asio/detail/handler_work.hpp>
#include <boost/asio/detail/memory.hpp>
#include <boost/asio/detail/signal_op.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace detail {

<<<<<<< HEAD
template <typename Handler>
=======
template <typename Handler, typename IoExecutor>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
class signal_handler : public signal_op
{
public:
  BOOST_ASIO_DEFINE_HANDLER_PTR(signal_handler);

<<<<<<< HEAD
  signal_handler(Handler& h)
    : signal_op(&signal_handler::do_complete),
      handler_(BOOST_ASIO_MOVE_CAST(Handler)(h))
  {
    handler_work<Handler>::start(handler_);
=======
  signal_handler(Handler& h, const IoExecutor& io_ex)
    : signal_op(&signal_handler::do_complete),
      handler_(BOOST_ASIO_MOVE_CAST(Handler)(h)),
      io_executor_(io_ex)
  {
    handler_work<Handler, IoExecutor>::start(handler_, io_executor_);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  static void do_complete(void* owner, operation* base,
      const boost::system::error_code& /*ec*/,
      std::size_t /*bytes_transferred*/)
  {
    // Take ownership of the handler object.
    signal_handler* h(static_cast<signal_handler*>(base));
    ptr p = { boost::asio::detail::addressof(h->handler_), h, h };
<<<<<<< HEAD
    handler_work<Handler> w(h->handler_);
=======
    handler_work<Handler, IoExecutor> w(h->handler_, h->io_executor_);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    BOOST_ASIO_HANDLER_COMPLETION((*h));

    // Make a copy of the handler so that the memory can be deallocated before
    // the upcall is made. Even if we're not about to make an upcall, a
    // sub-object of the handler may be the true owner of the memory associated
    // with the handler. Consequently, a local copy of the handler is required
    // to ensure that any owning sub-object remains valid until after we have
    // deallocated the memory here.
    detail::binder2<Handler, boost::system::error_code, int>
      handler(h->handler_, h->ec_, h->signal_number_);
    p.h = boost::asio::detail::addressof(handler.handler_);
    p.reset();

    // Make the upcall if required.
    if (owner)
    {
      fenced_block b(fenced_block::half);
      BOOST_ASIO_HANDLER_INVOCATION_BEGIN((handler.arg1_, handler.arg2_));
      w.complete(handler, handler.handler_);
      BOOST_ASIO_HANDLER_INVOCATION_END;
    }
  }

private:
  Handler handler_;
<<<<<<< HEAD
=======
  IoExecutor io_executor_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

} // namespace detail
} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_DETAIL_SIGNAL_HANDLER_HPP
