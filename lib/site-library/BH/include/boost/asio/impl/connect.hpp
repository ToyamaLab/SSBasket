//
// impl/connect.hpp
// ~~~~~~~~~~~~~~~~
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

#ifndef BOOST_ASIO_IMPL_CONNECT_HPP
#define BOOST_ASIO_IMPL_CONNECT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <algorithm>
#include <boost/asio/associated_allocator.hpp>
#include <boost/asio/associated_executor.hpp>
#include <boost/asio/detail/bind_handler.hpp>
#include <boost/asio/detail/handler_alloc_helpers.hpp>
#include <boost/asio/detail/handler_cont_helpers.hpp>
#include <boost/asio/detail/handler_invoke_helpers.hpp>
#include <boost/asio/detail/handler_type_requirements.hpp>
<<<<<<< HEAD
=======
#include <boost/asio/detail/non_const_lvalue.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/asio/detail/throw_error.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/post.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {

namespace detail
{
  struct default_connect_condition
  {
    template <typename Endpoint>
    bool operator()(const boost::system::error_code&, const Endpoint&)
    {
      return true;
    }
  };

  template <typename Protocol, typename Iterator>
  inline typename Protocol::endpoint deref_connect_result(
      Iterator iter, boost::system::error_code& ec)
  {
    return ec ? typename Protocol::endpoint() : *iter;
  }

  template <typename T, typename Iterator>
  struct legacy_connect_condition_helper : T
  {
    typedef char (*fallback_func_type)(...);
    operator fallback_func_type() const;
  };

  template <typename R, typename Arg1, typename Arg2, typename Iterator>
  struct legacy_connect_condition_helper<R (*)(Arg1, Arg2), Iterator>
  {
    R operator()(Arg1, Arg2) const;
    char operator()(...) const;
  };

  template <typename T, typename Iterator>
  struct is_legacy_connect_condition
  {
    static char asio_connect_condition_check(char);
    static char (&asio_connect_condition_check(Iterator))[2];

    static const bool value =
      sizeof(asio_connect_condition_check(
        (*static_cast<legacy_connect_condition_helper<T, Iterator>*>(0))(
          *static_cast<const boost::system::error_code*>(0),
          *static_cast<const Iterator*>(0)))) != 1;
  };

  template <typename ConnectCondition, typename Iterator>
  inline Iterator call_connect_condition(ConnectCondition& connect_condition,
      const boost::system::error_code& ec, Iterator next, Iterator end,
      typename enable_if<is_legacy_connect_condition<
        ConnectCondition, Iterator>::value>::type* = 0)
  {
    if (next != end)
      return connect_condition(ec, next);
    return end;
  }

  template <typename ConnectCondition, typename Iterator>
  inline Iterator call_connect_condition(ConnectCondition& connect_condition,
      const boost::system::error_code& ec, Iterator next, Iterator end,
      typename enable_if<!is_legacy_connect_condition<
        ConnectCondition, Iterator>::value>::type* = 0)
  {
    for (;next != end; ++next)
      if (connect_condition(ec, *next))
        return next;
    return end;
  }
}

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename EndpointSequence>
typename Protocol::endpoint connect(
    basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor, typename EndpointSequence>
typename Protocol::endpoint connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    const EndpointSequence& endpoints,
    typename enable_if<is_endpoint_sequence<
        EndpointSequence>::value>::type*)
{
  boost::system::error_code ec;
  typename Protocol::endpoint result = connect(s, endpoints, ec);
  boost::asio::detail::throw_error(ec, "connect");
  return result;
}

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename EndpointSequence>
typename Protocol::endpoint connect(
    basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor, typename EndpointSequence>
typename Protocol::endpoint connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    const EndpointSequence& endpoints, boost::system::error_code& ec,
    typename enable_if<is_endpoint_sequence<
        EndpointSequence>::value>::type*)
{
  return detail::deref_connect_result<Protocol>(
      connect(s, endpoints.begin(), endpoints.end(),
        detail::default_connect_condition(), ec), ec);
}

#if !defined(BOOST_ASIO_NO_DEPRECATED)
<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator>
Iterator connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s, Iterator begin,
=======
template <typename Protocol, typename Executor, typename Iterator>
Iterator connect(basic_socket<Protocol, Executor>& s, Iterator begin,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    typename enable_if<!is_endpoint_sequence<Iterator>::value>::type*)
{
  boost::system::error_code ec;
  Iterator result = connect(s, begin, ec);
  boost::asio::detail::throw_error(ec, "connect");
  return result;
}

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator>
inline Iterator connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor, typename Iterator>
inline Iterator connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Iterator begin, boost::system::error_code& ec,
    typename enable_if<!is_endpoint_sequence<Iterator>::value>::type*)
{
  return connect(s, begin, Iterator(), detail::default_connect_condition(), ec);
}
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator>
Iterator connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor, typename Iterator>
Iterator connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Iterator begin, Iterator end)
{
  boost::system::error_code ec;
  Iterator result = connect(s, begin, end, ec);
  boost::asio::detail::throw_error(ec, "connect");
  return result;
}

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator>
inline Iterator connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor, typename Iterator>
inline Iterator connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Iterator begin, Iterator end, boost::system::error_code& ec)
{
  return connect(s, begin, end, detail::default_connect_condition(), ec);
}

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename EndpointSequence, typename ConnectCondition>
typename Protocol::endpoint connect(
    basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor,
    typename EndpointSequence, typename ConnectCondition>
typename Protocol::endpoint connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    const EndpointSequence& endpoints, ConnectCondition connect_condition,
    typename enable_if<is_endpoint_sequence<
        EndpointSequence>::value>::type*)
{
  boost::system::error_code ec;
  typename Protocol::endpoint result = connect(
      s, endpoints, connect_condition, ec);
  boost::asio::detail::throw_error(ec, "connect");
  return result;
}

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename EndpointSequence, typename ConnectCondition>
typename Protocol::endpoint connect(
    basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor,
    typename EndpointSequence, typename ConnectCondition>
typename Protocol::endpoint connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    const EndpointSequence& endpoints, ConnectCondition connect_condition,
    boost::system::error_code& ec,
    typename enable_if<is_endpoint_sequence<
        EndpointSequence>::value>::type*)
{
  return detail::deref_connect_result<Protocol>(
      connect(s, endpoints.begin(), endpoints.end(),
        connect_condition, ec), ec);
}

#if !defined(BOOST_ASIO_NO_DEPRECATED)
<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename Iterator, typename ConnectCondition>
Iterator connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor,
    typename Iterator, typename ConnectCondition>
Iterator connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Iterator begin, ConnectCondition connect_condition,
    typename enable_if<!is_endpoint_sequence<Iterator>::value>::type*)
{
  boost::system::error_code ec;
  Iterator result = connect(s, begin, connect_condition, ec);
  boost::asio::detail::throw_error(ec, "connect");
  return result;
}

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename Iterator, typename ConnectCondition>
inline Iterator connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor,
    typename Iterator, typename ConnectCondition>
inline Iterator connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Iterator begin, ConnectCondition connect_condition,
    boost::system::error_code& ec,
    typename enable_if<!is_endpoint_sequence<Iterator>::value>::type*)
{
  return connect(s, begin, Iterator(), connect_condition, ec);
}
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename Iterator, typename ConnectCondition>
Iterator connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
    Iterator begin, Iterator end, ConnectCondition connect_condition)
=======
template <typename Protocol, typename Executor,
    typename Iterator, typename ConnectCondition>
Iterator connect(basic_socket<Protocol, Executor>& s, Iterator begin,
    Iterator end, ConnectCondition connect_condition)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
  boost::system::error_code ec;
  Iterator result = connect(s, begin, end, connect_condition, ec);
  boost::asio::detail::throw_error(ec, "connect");
  return result;
}

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename Iterator, typename ConnectCondition>
Iterator connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
    Iterator begin, Iterator end, ConnectCondition connect_condition,
=======
template <typename Protocol, typename Executor,
    typename Iterator, typename ConnectCondition>
Iterator connect(basic_socket<Protocol, Executor>& s, Iterator begin,
    Iterator end, ConnectCondition connect_condition,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::system::error_code& ec)
{
  ec = boost::system::error_code();

  for (Iterator iter = begin; iter != end; ++iter)
  {
    iter = (detail::call_connect_condition(connect_condition, ec, iter, end));
    if (iter != end)
    {
      s.close(ec);
      s.connect(*iter, ec);
      if (!ec)
        return iter;
    }
    else
      break;
  }

  if (!ec)
    ec = boost::asio::error::not_found;

  return end;
}

namespace detail
{
  // Enable the empty base class optimisation for the connect condition.
  template <typename ConnectCondition>
  class base_from_connect_condition
  {
  protected:
    explicit base_from_connect_condition(
        const ConnectCondition& connect_condition)
      : connect_condition_(connect_condition)
    {
    }

    template <typename Iterator>
    void check_condition(const boost::system::error_code& ec,
        Iterator& iter, Iterator& end)
    {
      iter = detail::call_connect_condition(connect_condition_, ec, iter, end);
    }

  private:
    ConnectCondition connect_condition_;
  };

  // The default_connect_condition implementation is essentially a no-op. This
  // template specialisation lets us eliminate all costs associated with it.
  template <>
  class base_from_connect_condition<default_connect_condition>
  {
  protected:
    explicit base_from_connect_condition(const default_connect_condition&)
    {
    }

    template <typename Iterator>
    void check_condition(const boost::system::error_code&, Iterator&, Iterator&)
    {
    }
  };

<<<<<<< HEAD
  template <typename Protocol BOOST_ASIO_SVC_TPARAM,
      typename EndpointSequence, typename ConnectCondition,
      typename RangeConnectHandler>
  class range_connect_op : base_from_connect_condition<ConnectCondition>
  {
  public:
    range_connect_op(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& sock,
=======
  template <typename Protocol, typename Executor, typename EndpointSequence,
      typename ConnectCondition, typename RangeConnectHandler>
  class range_connect_op : base_from_connect_condition<ConnectCondition>
  {
  public:
    range_connect_op(basic_socket<Protocol, Executor>& sock,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        const EndpointSequence& endpoints,
        const ConnectCondition& connect_condition,
        RangeConnectHandler& handler)
      : base_from_connect_condition<ConnectCondition>(connect_condition),
        socket_(sock),
        endpoints_(endpoints),
        index_(0),
        start_(0),
        handler_(BOOST_ASIO_MOVE_CAST(RangeConnectHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
    range_connect_op(const range_connect_op& other)
      : base_from_connect_condition<ConnectCondition>(other),
        socket_(other.socket_),
        endpoints_(other.endpoints_),
        index_(other.index_),
        start_(other.start_),
        handler_(other.handler_)
    {
    }

    range_connect_op(range_connect_op&& other)
      : base_from_connect_condition<ConnectCondition>(other),
        socket_(other.socket_),
        endpoints_(other.endpoints_),
        index_(other.index_),
        start_(other.start_),
        handler_(BOOST_ASIO_MOVE_CAST(RangeConnectHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(boost::system::error_code ec, int start = 0)
    {
<<<<<<< HEAD
      typename EndpointSequence::const_iterator begin = endpoints_.begin();
      typename EndpointSequence::const_iterator iter = begin;
      std::advance(iter, index_);
      typename EndpointSequence::const_iterator end = endpoints_.end();
=======
      this->process(ec, start,
          const_cast<const EndpointSequence&>(endpoints_).begin(),
          const_cast<const EndpointSequence&>(endpoints_).end());
    }

  //private:
    template <typename Iterator>
    void process(boost::system::error_code ec,
        int start, Iterator begin, Iterator end)
    {
      Iterator iter = begin;
      std::advance(iter, index_);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

      switch (start_ = start)
      {
        case 1:
        for (;;)
        {
          this->check_condition(ec, iter, end);
          index_ = std::distance(begin, iter);

          if (iter != end)
          {
            socket_.close(ec);
            socket_.async_connect(*iter,
                BOOST_ASIO_MOVE_CAST(range_connect_op)(*this));
            return;
          }

          if (start)
          {
            ec = boost::asio::error::not_found;
            boost::asio::post(socket_.get_executor(),
                detail::bind_handler(
                  BOOST_ASIO_MOVE_CAST(range_connect_op)(*this), ec));
            return;
          }

<<<<<<< HEAD
          default:
=======
          /* fall-through */ default:
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

          if (iter == end)
            break;

          if (!socket_.is_open())
          {
            ec = boost::asio::error::operation_aborted;
            break;
          }

          if (!ec)
            break;

          ++iter;
          ++index_;
        }

        handler_(static_cast<const boost::system::error_code&>(ec),
            static_cast<const typename Protocol::endpoint&>(
              ec || iter == end ? typename Protocol::endpoint() : *iter));
      }
    }

<<<<<<< HEAD
  //private:
    basic_socket<Protocol BOOST_ASIO_SVC_TARG>& socket_;
=======
    basic_socket<Protocol, Executor>& socket_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    EndpointSequence endpoints_;
    std::size_t index_;
    int start_;
    RangeConnectHandler handler_;
  };

<<<<<<< HEAD
  template <typename Protocol BOOST_ASIO_SVC_TPARAM,
      typename EndpointSequence, typename ConnectCondition,
      typename RangeConnectHandler>
  inline void* asio_handler_allocate(std::size_t size,
      range_connect_op<Protocol BOOST_ASIO_SVC_TARG, EndpointSequence,
=======
  template <typename Protocol, typename Executor, typename EndpointSequence,
      typename ConnectCondition, typename RangeConnectHandler>
  inline void* asio_handler_allocate(std::size_t size,
      range_connect_op<Protocol, Executor, EndpointSequence,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, RangeConnectHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename Protocol BOOST_ASIO_SVC_TPARAM,
      typename EndpointSequence, typename ConnectCondition,
      typename RangeConnectHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      range_connect_op<Protocol BOOST_ASIO_SVC_TARG, EndpointSequence,
=======
  template <typename Protocol, typename Executor, typename EndpointSequence,
      typename ConnectCondition, typename RangeConnectHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      range_connect_op<Protocol, Executor, EndpointSequence,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, RangeConnectHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename Protocol BOOST_ASIO_SVC_TPARAM,
      typename EndpointSequence, typename ConnectCondition,
      typename RangeConnectHandler>
  inline bool asio_handler_is_continuation(
      range_connect_op<Protocol BOOST_ASIO_SVC_TARG, EndpointSequence,
=======
  template <typename Protocol, typename Executor, typename EndpointSequence,
      typename ConnectCondition, typename RangeConnectHandler>
  inline bool asio_handler_is_continuation(
      range_connect_op<Protocol, Executor, EndpointSequence,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, RangeConnectHandler>* this_handler)
  {
    return boost_asio_handler_cont_helpers::is_continuation(
        this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename Function, typename Protocol
      BOOST_ASIO_SVC_TPARAM, typename EndpointSequence,
      typename ConnectCondition, typename RangeConnectHandler>
  inline void asio_handler_invoke(Function& function,
      range_connect_op<Protocol BOOST_ASIO_SVC_TARG, EndpointSequence,
=======
  template <typename Function, typename Executor, typename Protocol,
      typename EndpointSequence, typename ConnectCondition,
      typename RangeConnectHandler>
  inline void asio_handler_invoke(Function& function,
      range_connect_op<Protocol, Executor, EndpointSequence,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, RangeConnectHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename Function, typename Protocol
      BOOST_ASIO_SVC_TPARAM, typename EndpointSequence,
      typename ConnectCondition, typename RangeConnectHandler>
  inline void asio_handler_invoke(const Function& function,
      range_connect_op<Protocol BOOST_ASIO_SVC_TARG, EndpointSequence,
=======
  template <typename Function, typename Executor, typename Protocol,
      typename EndpointSequence, typename ConnectCondition,
      typename RangeConnectHandler>
  inline void asio_handler_invoke(const Function& function,
      range_connect_op<Protocol, Executor, EndpointSequence,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, RangeConnectHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator,
=======
  template <typename Protocol, typename Executor>
  class initiate_async_range_connect
  {
  public:
    typedef Executor executor_type;

    explicit initiate_async_range_connect(basic_socket<Protocol, Executor>& s)
      : socket_(s)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return socket_.get_executor();
    }

    template <typename RangeConnectHandler,
        typename EndpointSequence, typename ConnectCondition>
    void operator()(BOOST_ASIO_MOVE_ARG(RangeConnectHandler) handler,
        const EndpointSequence& endpoints,
        const ConnectCondition& connect_condition) const
    {
      // If you get an error on the following line it means that your
      // handler does not meet the documented type requirements for an
      // RangeConnectHandler.
      BOOST_ASIO_RANGE_CONNECT_HANDLER_CHECK(RangeConnectHandler,
          handler, typename Protocol::endpoint) type_check;

      non_const_lvalue<RangeConnectHandler> handler2(handler);
      range_connect_op<Protocol, Executor, EndpointSequence, ConnectCondition,
        typename decay<RangeConnectHandler>::type>(socket_, endpoints,
          connect_condition, handler2.value)(boost::system::error_code(), 1);
    }

  private:
    basic_socket<Protocol, Executor>& socket_;
  };

  template <typename Protocol, typename Executor, typename Iterator,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      typename ConnectCondition, typename IteratorConnectHandler>
  class iterator_connect_op : base_from_connect_condition<ConnectCondition>
  {
  public:
<<<<<<< HEAD
    iterator_connect_op(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& sock,
=======
    iterator_connect_op(basic_socket<Protocol, Executor>& sock,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        const Iterator& begin, const Iterator& end,
        const ConnectCondition& connect_condition,
        IteratorConnectHandler& handler)
      : base_from_connect_condition<ConnectCondition>(connect_condition),
        socket_(sock),
        iter_(begin),
        end_(end),
        start_(0),
        handler_(BOOST_ASIO_MOVE_CAST(IteratorConnectHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
    iterator_connect_op(const iterator_connect_op& other)
      : base_from_connect_condition<ConnectCondition>(other),
        socket_(other.socket_),
        iter_(other.iter_),
        end_(other.end_),
        start_(other.start_),
        handler_(other.handler_)
    {
    }

    iterator_connect_op(iterator_connect_op&& other)
      : base_from_connect_condition<ConnectCondition>(other),
        socket_(other.socket_),
        iter_(other.iter_),
        end_(other.end_),
        start_(other.start_),
        handler_(BOOST_ASIO_MOVE_CAST(IteratorConnectHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(boost::system::error_code ec, int start = 0)
    {
      switch (start_ = start)
      {
        case 1:
        for (;;)
        {
          this->check_condition(ec, iter_, end_);

          if (iter_ != end_)
          {
            socket_.close(ec);
            socket_.async_connect(*iter_,
                BOOST_ASIO_MOVE_CAST(iterator_connect_op)(*this));
            return;
          }

          if (start)
          {
            ec = boost::asio::error::not_found;
            boost::asio::post(socket_.get_executor(),
                detail::bind_handler(
                  BOOST_ASIO_MOVE_CAST(iterator_connect_op)(*this), ec));
            return;
          }

<<<<<<< HEAD
          default:
=======
          /* fall-through */ default:
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

          if (iter_ == end_)
            break;

          if (!socket_.is_open())
          {
            ec = boost::asio::error::operation_aborted;
            break;
          }

          if (!ec)
            break;

          ++iter_;
        }

        handler_(static_cast<const boost::system::error_code&>(ec),
            static_cast<const Iterator&>(iter_));
      }
    }

  //private:
<<<<<<< HEAD
    basic_socket<Protocol BOOST_ASIO_SVC_TARG>& socket_;
=======
    basic_socket<Protocol, Executor>& socket_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Iterator iter_;
    Iterator end_;
    int start_;
    IteratorConnectHandler handler_;
  };

<<<<<<< HEAD
  template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator,
      typename ConnectCondition, typename IteratorConnectHandler>
  inline void* asio_handler_allocate(std::size_t size,
      iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
=======
  template <typename Protocol, typename Executor, typename Iterator,
      typename ConnectCondition, typename IteratorConnectHandler>
  inline void* asio_handler_allocate(std::size_t size,
      iterator_connect_op<Protocol, Executor, Iterator,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, IteratorConnectHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator,
      typename ConnectCondition, typename IteratorConnectHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
=======
  template <typename Protocol, typename Executor, typename Iterator,
      typename ConnectCondition, typename IteratorConnectHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      iterator_connect_op<Protocol, Executor, Iterator,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, IteratorConnectHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator,
      typename ConnectCondition, typename IteratorConnectHandler>
  inline bool asio_handler_is_continuation(
      iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
=======
  template <typename Protocol, typename Executor, typename Iterator,
      typename ConnectCondition, typename IteratorConnectHandler>
  inline bool asio_handler_is_continuation(
      iterator_connect_op<Protocol, Executor, Iterator,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, IteratorConnectHandler>* this_handler)
  {
    return boost_asio_handler_cont_helpers::is_continuation(
        this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename Function, typename Protocol
      BOOST_ASIO_SVC_TPARAM, typename Iterator,
      typename ConnectCondition, typename IteratorConnectHandler>
  inline void asio_handler_invoke(Function& function,
      iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
=======
  template <typename Function, typename Executor, typename Protocol,
      typename Iterator, typename ConnectCondition,
      typename IteratorConnectHandler>
  inline void asio_handler_invoke(Function& function,
      iterator_connect_op<Protocol, Executor, Iterator,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, IteratorConnectHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename Function, typename Protocol
      BOOST_ASIO_SVC_TPARAM, typename Iterator,
      typename ConnectCondition, typename IteratorConnectHandler>
  inline void asio_handler_invoke(const Function& function,
      iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
=======
  template <typename Function, typename Executor, typename Protocol,
      typename Iterator, typename ConnectCondition,
      typename IteratorConnectHandler>
  inline void asio_handler_invoke(const Function& function,
      iterator_connect_op<Protocol, Executor, Iterator,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        ConnectCondition, IteratorConnectHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }
<<<<<<< HEAD
=======

  template <typename Protocol, typename Executor>
  class initiate_async_iterator_connect
  {
  public:
    typedef Executor executor_type;

    explicit initiate_async_iterator_connect(
        basic_socket<Protocol, Executor>& s)
      : socket_(s)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return socket_.get_executor();
    }

    template <typename IteratorConnectHandler,
        typename Iterator, typename ConnectCondition>
    void operator()(BOOST_ASIO_MOVE_ARG(IteratorConnectHandler) handler,
        Iterator begin, Iterator end,
        const ConnectCondition& connect_condition) const
    {
      // If you get an error on the following line it means that your
      // handler does not meet the documented type requirements for an
      // IteratorConnectHandler.
      BOOST_ASIO_ITERATOR_CONNECT_HANDLER_CHECK(
          IteratorConnectHandler, handler, Iterator) type_check;

      non_const_lvalue<IteratorConnectHandler> handler2(handler);
      iterator_connect_op<Protocol, Executor, Iterator, ConnectCondition,
        typename decay<IteratorConnectHandler>::type>(socket_, begin, end,
          connect_condition, handler2.value)(boost::system::error_code(), 1);
    }

  private:
    basic_socket<Protocol, Executor>& socket_;
  };
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename EndpointSequence, typename ConnectCondition,
    typename RangeConnectHandler, typename Allocator>
struct associated_allocator<
    detail::range_connect_op<Protocol BOOST_ASIO_SVC_TARG,
      EndpointSequence, ConnectCondition, RangeConnectHandler>,
    Allocator>
=======
template <typename Protocol, typename Executor, typename EndpointSequence,
    typename ConnectCondition, typename RangeConnectHandler, typename Allocator>
struct associated_allocator<
    detail::range_connect_op<Protocol, Executor, EndpointSequence,
      ConnectCondition, RangeConnectHandler>, Allocator>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
  typedef typename associated_allocator<
      RangeConnectHandler, Allocator>::type type;

  static type get(
<<<<<<< HEAD
      const detail::range_connect_op<Protocol BOOST_ASIO_SVC_TARG,
        EndpointSequence, ConnectCondition, RangeConnectHandler>& h,
=======
      const detail::range_connect_op<Protocol, Executor, EndpointSequence,
        ConnectCondition, RangeConnectHandler>& h,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<RangeConnectHandler,
        Allocator>::get(h.handler_, a);
  }
};

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename EndpointSequence, typename ConnectCondition,
    typename RangeConnectHandler, typename Executor>
struct associated_executor<
    detail::range_connect_op<Protocol BOOST_ASIO_SVC_TARG,
      EndpointSequence, ConnectCondition, RangeConnectHandler>,
    Executor>
{
  typedef typename associated_executor<
      RangeConnectHandler, Executor>::type type;

  static type get(
      const detail::range_connect_op<Protocol BOOST_ASIO_SVC_TARG,
        EndpointSequence, ConnectCondition, RangeConnectHandler>& h,
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<RangeConnectHandler,
        Executor>::get(h.handler_, ex);
  }
};

template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename Iterator, typename ConnectCondition,
    typename IteratorConnectHandler, typename Allocator>
struct associated_allocator<
    detail::iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
      ConnectCondition, IteratorConnectHandler>,
=======
template <typename Protocol, typename Executor, typename EndpointSequence,
    typename ConnectCondition, typename RangeConnectHandler, typename Executor1>
struct associated_executor<
    detail::range_connect_op<Protocol, Executor, EndpointSequence,
      ConnectCondition, RangeConnectHandler>, Executor1>
{
  typedef typename associated_executor<
      RangeConnectHandler, Executor1>::type type;

  static type get(
      const detail::range_connect_op<Protocol, Executor, EndpointSequence,
      ConnectCondition, RangeConnectHandler>& h,
      const Executor1& ex = Executor1()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<RangeConnectHandler,
        Executor1>::get(h.handler_, ex);
  }
};

template <typename Protocol, typename Executor, typename Iterator,
    typename ConnectCondition, typename IteratorConnectHandler,
    typename Allocator>
struct associated_allocator<
    detail::iterator_connect_op<Protocol, Executor,
      Iterator, ConnectCondition, IteratorConnectHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Allocator>
{
  typedef typename associated_allocator<
      IteratorConnectHandler, Allocator>::type type;

  static type get(
<<<<<<< HEAD
      const detail::iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG,
=======
      const detail::iterator_connect_op<Protocol, Executor,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        Iterator, ConnectCondition, IteratorConnectHandler>& h,
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<IteratorConnectHandler,
        Allocator>::get(h.handler_, a);
  }
};

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename Iterator, typename ConnectCondition,
    typename IteratorConnectHandler, typename Executor>
struct associated_executor<
    detail::iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
      ConnectCondition, IteratorConnectHandler>,
    Executor>
{
  typedef typename associated_executor<
      IteratorConnectHandler, Executor>::type type;

  static type get(
      const detail::iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG,
        Iterator, ConnectCondition, IteratorConnectHandler>& h,
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<IteratorConnectHandler,
        Executor>::get(h.handler_, ex);
=======
template <typename Protocol, typename Executor, typename Iterator,
    typename ConnectCondition, typename IteratorConnectHandler,
    typename Executor1>
struct associated_executor<
    detail::iterator_connect_op<Protocol, Executor,
      Iterator, ConnectCondition, IteratorConnectHandler>,
    Executor1>
{
  typedef typename associated_executor<
      IteratorConnectHandler, Executor1>::type type;

  static type get(
      const detail::iterator_connect_op<Protocol, Executor,
        Iterator, ConnectCondition, IteratorConnectHandler>& h,
      const Executor1& ex = Executor1()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<IteratorConnectHandler,
        Executor1>::get(h.handler_, ex);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename EndpointSequence, typename RangeConnectHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(RangeConnectHandler,
    void (boost::system::error_code, typename Protocol::endpoint))
async_connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
template <typename Protocol, typename Executor, typename EndpointSequence,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      typename Protocol::endpoint)) RangeConnectHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(RangeConnectHandler,
    void (boost::system::error_code, typename Protocol::endpoint))
async_connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    const EndpointSequence& endpoints,
    BOOST_ASIO_MOVE_ARG(RangeConnectHandler) handler,
    typename enable_if<is_endpoint_sequence<
        EndpointSequence>::value>::type*)
{
<<<<<<< HEAD
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a RangeConnectHandler.
  BOOST_ASIO_RANGE_CONNECT_HANDLER_CHECK(
      RangeConnectHandler, handler, typename Protocol::endpoint) type_check;

  async_completion<RangeConnectHandler,
    void (boost::system::error_code, typename Protocol::endpoint)>
      init(handler);

  detail::range_connect_op<Protocol BOOST_ASIO_SVC_TARG, EndpointSequence,
    detail::default_connect_condition,
      BOOST_ASIO_HANDLER_TYPE(RangeConnectHandler,
        void (boost::system::error_code, typename Protocol::endpoint))>(s,
          endpoints, detail::default_connect_condition(),
            init.completion_handler)(boost::system::error_code(), 1);

  return init.result.get();
}

#if !defined(BOOST_ASIO_NO_DEPRECATED)
template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename Iterator, typename IteratorConnectHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(IteratorConnectHandler,
    void (boost::system::error_code, Iterator))
async_connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
    Iterator begin, BOOST_ASIO_MOVE_ARG(IteratorConnectHandler) handler,
    typename enable_if<!is_endpoint_sequence<Iterator>::value>::type*)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a IteratorConnectHandler.
  BOOST_ASIO_ITERATOR_CONNECT_HANDLER_CHECK(
      IteratorConnectHandler, handler, Iterator) type_check;

  async_completion<IteratorConnectHandler,
    void (boost::system::error_code, Iterator)> init(handler);

  detail::iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
    detail::default_connect_condition, BOOST_ASIO_HANDLER_TYPE(
      IteratorConnectHandler, void (boost::system::error_code, Iterator))>(s,
        begin, Iterator(), detail::default_connect_condition(),
          init.completion_handler)(boost::system::error_code(), 1);

  return init.result.get();
}
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

template <typename Protocol BOOST_ASIO_SVC_TPARAM,
    typename Iterator, typename IteratorConnectHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(IteratorConnectHandler,
    void (boost::system::error_code, Iterator))
async_connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
    Iterator begin, Iterator end,
    BOOST_ASIO_MOVE_ARG(IteratorConnectHandler) handler)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a IteratorConnectHandler.
  BOOST_ASIO_ITERATOR_CONNECT_HANDLER_CHECK(
      IteratorConnectHandler, handler, Iterator) type_check;

  async_completion<IteratorConnectHandler,
    void (boost::system::error_code, Iterator)> init(handler);

  detail::iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
    detail::default_connect_condition, BOOST_ASIO_HANDLER_TYPE(
      IteratorConnectHandler, void (boost::system::error_code, Iterator))>(s,
        begin, end, detail::default_connect_condition(),
          init.completion_handler)(boost::system::error_code(), 1);

  return init.result.get();
}

template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename EndpointSequence,
    typename ConnectCondition, typename RangeConnectHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(RangeConnectHandler,
    void (boost::system::error_code, typename Protocol::endpoint))
async_connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
=======
  return async_initiate<RangeConnectHandler,
    void (boost::system::error_code, typename Protocol::endpoint)>(
      detail::initiate_async_range_connect<Protocol, Executor>(s),
      handler, endpoints, detail::default_connect_condition());
}

#if !defined(BOOST_ASIO_NO_DEPRECATED)
template <typename Protocol, typename Executor, typename Iterator,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      Iterator)) IteratorConnectHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(IteratorConnectHandler,
    void (boost::system::error_code, Iterator))
async_connect(basic_socket<Protocol, Executor>& s, Iterator begin,
    BOOST_ASIO_MOVE_ARG(IteratorConnectHandler) handler,
    typename enable_if<!is_endpoint_sequence<Iterator>::value>::type*)
{
  return async_initiate<IteratorConnectHandler,
    void (boost::system::error_code, Iterator)>(
      detail::initiate_async_iterator_connect<Protocol, Executor>(s),
      handler, begin, Iterator(), detail::default_connect_condition());
}
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

template <typename Protocol, typename Executor, typename Iterator,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      Iterator)) IteratorConnectHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(IteratorConnectHandler,
    void (boost::system::error_code, Iterator))
async_connect(basic_socket<Protocol, Executor>& s, Iterator begin, Iterator end,
    BOOST_ASIO_MOVE_ARG(IteratorConnectHandler) handler)
{
  return async_initiate<IteratorConnectHandler,
    void (boost::system::error_code, Iterator)>(
      detail::initiate_async_iterator_connect<Protocol, Executor>(s),
      handler, begin, end, detail::default_connect_condition());
}

template <typename Protocol, typename Executor,
    typename EndpointSequence, typename ConnectCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      typename Protocol::endpoint)) RangeConnectHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(RangeConnectHandler,
    void (boost::system::error_code, typename Protocol::endpoint))
async_connect(basic_socket<Protocol, Executor>& s,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    const EndpointSequence& endpoints, ConnectCondition connect_condition,
    BOOST_ASIO_MOVE_ARG(RangeConnectHandler) handler,
    typename enable_if<is_endpoint_sequence<
        EndpointSequence>::value>::type*)
{
<<<<<<< HEAD
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a RangeConnectHandler.
  BOOST_ASIO_RANGE_CONNECT_HANDLER_CHECK(
      RangeConnectHandler, handler, typename Protocol::endpoint) type_check;

  async_completion<RangeConnectHandler,
    void (boost::system::error_code, typename Protocol::endpoint)>
      init(handler);

  detail::range_connect_op<Protocol BOOST_ASIO_SVC_TARG, EndpointSequence,
    ConnectCondition, BOOST_ASIO_HANDLER_TYPE(RangeConnectHandler,
      void (boost::system::error_code, typename Protocol::endpoint))>(s,
        endpoints, connect_condition, init.completion_handler)(
          boost::system::error_code(), 1);

  return init.result.get();
}

#if !defined(BOOST_ASIO_NO_DEPRECATED)
template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator,
    typename ConnectCondition, typename IteratorConnectHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(IteratorConnectHandler,
    void (boost::system::error_code, Iterator))
async_connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
    Iterator begin, ConnectCondition connect_condition,
    BOOST_ASIO_MOVE_ARG(IteratorConnectHandler) handler,
    typename enable_if<!is_endpoint_sequence<Iterator>::value>::type*)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a IteratorConnectHandler.
  BOOST_ASIO_ITERATOR_CONNECT_HANDLER_CHECK(
      IteratorConnectHandler, handler, Iterator) type_check;

  async_completion<IteratorConnectHandler,
    void (boost::system::error_code, Iterator)> init(handler);

  detail::iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
    ConnectCondition, BOOST_ASIO_HANDLER_TYPE(
      IteratorConnectHandler, void (boost::system::error_code, Iterator))>(s,
        begin, Iterator(), connect_condition, init.completion_handler)(
          boost::system::error_code(), 1);

  return init.result.get();
}
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

template <typename Protocol BOOST_ASIO_SVC_TPARAM, typename Iterator,
    typename ConnectCondition, typename IteratorConnectHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(IteratorConnectHandler,
    void (boost::system::error_code, Iterator))
async_connect(basic_socket<Protocol BOOST_ASIO_SVC_TARG>& s,
    Iterator begin, Iterator end, ConnectCondition connect_condition,
    BOOST_ASIO_MOVE_ARG(IteratorConnectHandler) handler)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a IteratorConnectHandler.
  BOOST_ASIO_ITERATOR_CONNECT_HANDLER_CHECK(
      IteratorConnectHandler, handler, Iterator) type_check;

  async_completion<IteratorConnectHandler,
    void (boost::system::error_code, Iterator)> init(handler);

  detail::iterator_connect_op<Protocol BOOST_ASIO_SVC_TARG, Iterator,
    ConnectCondition, BOOST_ASIO_HANDLER_TYPE(
      IteratorConnectHandler, void (boost::system::error_code, Iterator))>(s,
        begin, end, connect_condition, init.completion_handler)(
          boost::system::error_code(), 1);

  return init.result.get();
=======
  return async_initiate<RangeConnectHandler,
    void (boost::system::error_code, typename Protocol::endpoint)>(
      detail::initiate_async_range_connect<Protocol, Executor>(s),
      handler, endpoints, connect_condition);
}

#if !defined(BOOST_ASIO_NO_DEPRECATED)
template <typename Protocol, typename Executor,
    typename Iterator, typename ConnectCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      Iterator)) IteratorConnectHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(IteratorConnectHandler,
    void (boost::system::error_code, Iterator))
async_connect(basic_socket<Protocol, Executor>& s, Iterator begin,
    ConnectCondition connect_condition,
    BOOST_ASIO_MOVE_ARG(IteratorConnectHandler) handler,
    typename enable_if<!is_endpoint_sequence<Iterator>::value>::type*)
{
  return async_initiate<IteratorConnectHandler,
    void (boost::system::error_code, Iterator)>(
      detail::initiate_async_iterator_connect<Protocol, Executor>(s),
      handler, begin, Iterator(), connect_condition);
}
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

template <typename Protocol, typename Executor,
    typename Iterator, typename ConnectCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      Iterator)) IteratorConnectHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(IteratorConnectHandler,
    void (boost::system::error_code, Iterator))
async_connect(basic_socket<Protocol, Executor>& s, Iterator begin,
    Iterator end, ConnectCondition connect_condition,
    BOOST_ASIO_MOVE_ARG(IteratorConnectHandler) handler)
{
  return async_initiate<IteratorConnectHandler,
    void (boost::system::error_code, Iterator)>(
      detail::initiate_async_iterator_connect<Protocol, Executor>(s),
      handler, begin, end, connect_condition);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_IMPL_CONNECT_HPP
