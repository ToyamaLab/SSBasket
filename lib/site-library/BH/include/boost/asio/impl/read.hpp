//
// impl/read.hpp
// ~~~~~~~~~~~~~
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

#ifndef BOOST_ASIO_IMPL_READ_HPP
#define BOOST_ASIO_IMPL_READ_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <algorithm>
#include <boost/asio/associated_allocator.hpp>
#include <boost/asio/associated_executor.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/completion_condition.hpp>
#include <boost/asio/detail/array_fwd.hpp>
#include <boost/asio/detail/base_from_completion_cond.hpp>
#include <boost/asio/detail/bind_handler.hpp>
#include <boost/asio/detail/consuming_buffers.hpp>
#include <boost/asio/detail/dependent_type.hpp>
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

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {

namespace detail
{
  template <typename SyncReadStream, typename MutableBufferSequence,
      typename MutableBufferIterator, typename CompletionCondition>
  std::size_t read_buffer_sequence(SyncReadStream& s,
      const MutableBufferSequence& buffers, const MutableBufferIterator&,
      CompletionCondition completion_condition, boost::system::error_code& ec)
  {
    ec = boost::system::error_code();
    boost::asio::detail::consuming_buffers<mutable_buffer,
        MutableBufferSequence, MutableBufferIterator> tmp(buffers);
    while (!tmp.empty())
    {
      if (std::size_t max_size = detail::adapt_completion_condition_result(
            completion_condition(ec, tmp.total_consumed())))
        tmp.consume(s.read_some(tmp.prepare(max_size), ec));
      else
        break;
    }
    return tmp.total_consumed();;
  }
} // namespace detail

template <typename SyncReadStream, typename MutableBufferSequence,
    typename CompletionCondition>
std::size_t read(SyncReadStream& s, const MutableBufferSequence& buffers,
    CompletionCondition completion_condition, boost::system::error_code& ec,
    typename enable_if<
      is_mutable_buffer_sequence<MutableBufferSequence>::value
    >::type*)
{
  return detail::read_buffer_sequence(s, buffers,
<<<<<<< HEAD
      boost::asio::buffer_sequence_begin(buffers), completion_condition, ec);
=======
      boost::asio::buffer_sequence_begin(buffers),
      BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

template <typename SyncReadStream, typename MutableBufferSequence>
inline std::size_t read(SyncReadStream& s, const MutableBufferSequence& buffers,
    typename enable_if<
      is_mutable_buffer_sequence<MutableBufferSequence>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read(s, buffers, transfer_all(), ec);
  boost::asio::detail::throw_error(ec, "read");
  return bytes_transferred;
}

template <typename SyncReadStream, typename MutableBufferSequence>
inline std::size_t read(SyncReadStream& s, const MutableBufferSequence& buffers,
    boost::system::error_code& ec,
    typename enable_if<
      is_mutable_buffer_sequence<MutableBufferSequence>::value
    >::type*)
{
  return read(s, buffers, transfer_all(), ec);
}

template <typename SyncReadStream, typename MutableBufferSequence,
    typename CompletionCondition>
inline std::size_t read(SyncReadStream& s, const MutableBufferSequence& buffers,
    CompletionCondition completion_condition,
    typename enable_if<
      is_mutable_buffer_sequence<MutableBufferSequence>::value
    >::type*)
{
  boost::system::error_code ec;
<<<<<<< HEAD
  std::size_t bytes_transferred = read(s, buffers, completion_condition, ec);
=======
  std::size_t bytes_transferred = read(s, buffers,
      BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  boost::asio::detail::throw_error(ec, "read");
  return bytes_transferred;
}

<<<<<<< HEAD
template <typename SyncReadStream, typename DynamicBuffer,
    typename CompletionCondition>
std::size_t read(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    CompletionCondition completion_condition, boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer<DynamicBuffer>::value
    >::type*)
{
  typename decay<DynamicBuffer>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers));
=======
#if !defined(BOOST_ASIO_NO_DYNAMIC_BUFFER_V1)

template <typename SyncReadStream, typename DynamicBuffer_v1,
    typename CompletionCondition>
std::size_t read(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    CompletionCondition completion_condition, boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  typename decay<DynamicBuffer_v1>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

  ec = boost::system::error_code();
  std::size_t total_transferred = 0;
  std::size_t max_size = detail::adapt_completion_condition_result(
        completion_condition(ec, total_transferred));
  std::size_t bytes_available = std::min<std::size_t>(
        std::max<std::size_t>(512, b.capacity() - b.size()),
        std::min<std::size_t>(max_size, b.max_size() - b.size()));
  while (bytes_available > 0)
  {
    std::size_t bytes_transferred = s.read_some(b.prepare(bytes_available), ec);
    b.commit(bytes_transferred);
    total_transferred += bytes_transferred;
    max_size = detail::adapt_completion_condition_result(
          completion_condition(ec, total_transferred));
    bytes_available = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(max_size, b.max_size() - b.size()));
  }
  return total_transferred;
}

<<<<<<< HEAD
template <typename SyncReadStream, typename DynamicBuffer>
inline std::size_t read(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    typename enable_if<
      is_dynamic_buffer<DynamicBuffer>::value
=======
template <typename SyncReadStream, typename DynamicBuffer_v1>
inline std::size_t read(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read(s,
<<<<<<< HEAD
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers), transfer_all(), ec);
=======
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers), transfer_all(), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  boost::asio::detail::throw_error(ec, "read");
  return bytes_transferred;
}

<<<<<<< HEAD
template <typename SyncReadStream, typename DynamicBuffer>
inline std::size_t read(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer<DynamicBuffer>::value
    >::type*)
{
  return read(s, BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers),
      transfer_all(), ec);
}

template <typename SyncReadStream, typename DynamicBuffer,
    typename CompletionCondition>
inline std::size_t read(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    CompletionCondition completion_condition,
    typename enable_if<
      is_dynamic_buffer<DynamicBuffer>::value
=======
template <typename SyncReadStream, typename DynamicBuffer_v1>
inline std::size_t read(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  return read(s, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
      transfer_all(), ec);
}

template <typename SyncReadStream, typename DynamicBuffer_v1,
    typename CompletionCondition>
inline std::size_t read(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    CompletionCondition completion_condition,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read(s,
<<<<<<< HEAD
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers),
      completion_condition, ec);
=======
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
      BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  boost::asio::detail::throw_error(ec, "read");
  return bytes_transferred;
}

#if !defined(BOOST_ASIO_NO_EXTENSIONS)
#if !defined(BOOST_ASIO_NO_IOSTREAM)

template <typename SyncReadStream, typename Allocator,
    typename CompletionCondition>
inline std::size_t read(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    CompletionCondition completion_condition, boost::system::error_code& ec)
{
<<<<<<< HEAD
  return read(s, basic_streambuf_ref<Allocator>(b), completion_condition, ec);
=======
  return read(s, basic_streambuf_ref<Allocator>(b),
      BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b)
{
  return read(s, basic_streambuf_ref<Allocator>(b));
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    boost::system::error_code& ec)
{
  return read(s, basic_streambuf_ref<Allocator>(b), ec);
}

template <typename SyncReadStream, typename Allocator,
    typename CompletionCondition>
inline std::size_t read(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    CompletionCondition completion_condition)
{
<<<<<<< HEAD
  return read(s, basic_streambuf_ref<Allocator>(b), completion_condition);
=======
  return read(s, basic_streambuf_ref<Allocator>(b),
      BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

#endif // !defined(BOOST_ASIO_NO_IOSTREAM)
#endif // !defined(BOOST_ASIO_NO_EXTENSIONS)
<<<<<<< HEAD
=======
#endif // !defined(BOOST_ASIO_NO_DYNAMIC_BUFFER_V1)

template <typename SyncReadStream, typename DynamicBuffer_v2,
    typename CompletionCondition>
std::size_t read(SyncReadStream& s, DynamicBuffer_v2 buffers,
    CompletionCondition completion_condition, boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  DynamicBuffer_v2& b = buffers;

  ec = boost::system::error_code();
  std::size_t total_transferred = 0;
  std::size_t max_size = detail::adapt_completion_condition_result(
        completion_condition(ec, total_transferred));
  std::size_t bytes_available = std::min<std::size_t>(
        std::max<std::size_t>(512, b.capacity() - b.size()),
        std::min<std::size_t>(max_size, b.max_size() - b.size()));
  while (bytes_available > 0)
  {
    std::size_t pos = b.size();
    b.grow(bytes_available);
    std::size_t bytes_transferred = s.read_some(
        b.data(pos, bytes_available), ec);
    b.shrink(bytes_available - bytes_transferred);
    total_transferred += bytes_transferred;
    max_size = detail::adapt_completion_condition_result(
          completion_condition(ec, total_transferred));
    bytes_available = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(max_size, b.max_size() - b.size()));
  }
  return total_transferred;
}

template <typename SyncReadStream, typename DynamicBuffer_v2>
inline std::size_t read(SyncReadStream& s, DynamicBuffer_v2 buffers,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers), transfer_all(), ec);
  boost::asio::detail::throw_error(ec, "read");
  return bytes_transferred;
}

template <typename SyncReadStream, typename DynamicBuffer_v2>
inline std::size_t read(SyncReadStream& s, DynamicBuffer_v2 buffers,
    boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  return read(s, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
      transfer_all(), ec);
}

template <typename SyncReadStream, typename DynamicBuffer_v2,
    typename CompletionCondition>
inline std::size_t read(SyncReadStream& s, DynamicBuffer_v2 buffers,
    CompletionCondition completion_condition,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
      BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition), ec);
  boost::asio::detail::throw_error(ec, "read");
  return bytes_transferred;
}
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace detail
{
  template <typename AsyncReadStream, typename MutableBufferSequence,
      typename MutableBufferIterator, typename CompletionCondition,
      typename ReadHandler>
  class read_op
    : detail::base_from_completion_cond<CompletionCondition>
  {
  public:
    read_op(AsyncReadStream& stream, const MutableBufferSequence& buffers,
<<<<<<< HEAD
        CompletionCondition completion_condition, ReadHandler& handler)
=======
        CompletionCondition& completion_condition, ReadHandler& handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      : detail::base_from_completion_cond<
          CompletionCondition>(completion_condition),
        stream_(stream),
        buffers_(buffers),
        start_(0),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
    read_op(const read_op& other)
      : detail::base_from_completion_cond<CompletionCondition>(other),
        stream_(other.stream_),
        buffers_(other.buffers_),
        start_(other.start_),
        handler_(other.handler_)
    {
    }

    read_op(read_op&& other)
<<<<<<< HEAD
      : detail::base_from_completion_cond<CompletionCondition>(other),
        stream_(other.stream_),
        buffers_(other.buffers_),
=======
      : detail::base_from_completion_cond<CompletionCondition>(
          BOOST_ASIO_MOVE_CAST(detail::base_from_completion_cond<
            CompletionCondition>)(other)),
        stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(buffers_type)(other.buffers_)),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        start_(other.start_),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      std::size_t max_size;
      switch (start_ = start)
      {
        case 1:
        max_size = this->check_for_completion(ec, buffers_.total_consumed());
        do
        {
          stream_.async_read_some(buffers_.prepare(max_size),
              BOOST_ASIO_MOVE_CAST(read_op)(*this));
          return; default:
          buffers_.consume(bytes_transferred);
          if ((!ec && bytes_transferred == 0) || buffers_.empty())
            break;
          max_size = this->check_for_completion(ec, buffers_.total_consumed());
        } while (max_size > 0);

        handler_(ec, buffers_.total_consumed());
      }
    }

  //private:
<<<<<<< HEAD
    AsyncReadStream& stream_;
    boost::asio::detail::consuming_buffers<mutable_buffer,
        MutableBufferSequence, MutableBufferIterator> buffers_;
=======
    typedef boost::asio::detail::consuming_buffers<mutable_buffer,
        MutableBufferSequence, MutableBufferIterator> buffers_type;

    AsyncReadStream& stream_;
    buffers_type buffers_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    int start_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream, typename MutableBufferSequence,
      typename MutableBufferIterator, typename CompletionCondition,
      typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_op<AsyncReadStream, MutableBufferSequence, MutableBufferIterator,
        CompletionCondition, ReadHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

  template <typename AsyncReadStream, typename MutableBufferSequence,
      typename MutableBufferIterator, typename CompletionCondition,
      typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_op<AsyncReadStream, MutableBufferSequence, MutableBufferIterator,
        CompletionCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

  template <typename AsyncReadStream, typename MutableBufferSequence,
      typename MutableBufferIterator, typename CompletionCondition,
      typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_op<AsyncReadStream, MutableBufferSequence, MutableBufferIterator,
        CompletionCondition, ReadHandler>* this_handler)
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename MutableBufferSequence, typename MutableBufferIterator,
      typename CompletionCondition, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_op<AsyncReadStream, MutableBufferSequence, MutableBufferIterator,
        CompletionCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename MutableBufferSequence, typename MutableBufferIterator,
      typename CompletionCondition, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_op<AsyncReadStream, MutableBufferSequence, MutableBufferIterator,
        CompletionCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename AsyncReadStream, typename MutableBufferSequence,
      typename MutableBufferIterator, typename CompletionCondition,
      typename ReadHandler>
  inline void start_read_buffer_sequence_op(AsyncReadStream& stream,
      const MutableBufferSequence& buffers, const MutableBufferIterator&,
<<<<<<< HEAD
      CompletionCondition completion_condition, ReadHandler& handler)
=======
      CompletionCondition& completion_condition, ReadHandler& handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    detail::read_op<AsyncReadStream, MutableBufferSequence,
      MutableBufferIterator, CompletionCondition, ReadHandler>(
        stream, buffers, completion_condition, handler)(
          boost::system::error_code(), 0, 1);
  }
<<<<<<< HEAD
=======

  template <typename AsyncReadStream>
  class initiate_async_read_buffer_sequence
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_buffer_sequence(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler, typename MutableBufferSequence,
        typename CompletionCondition>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        const MutableBufferSequence& buffers,
        BOOST_ASIO_MOVE_ARG(CompletionCondition) completion_cond) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      non_const_lvalue<CompletionCondition> completion_cond2(completion_cond);
      start_read_buffer_sequence_op(stream_, buffers,
          boost::asio::buffer_sequence_begin(buffers),
          completion_cond2.value, handler2.value);
    }

  private:
    AsyncReadStream& stream_;
  };
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename MutableBufferSequence,
    typename MutableBufferIterator, typename CompletionCondition,
    typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_op<AsyncReadStream, MutableBufferSequence,
      MutableBufferIterator, CompletionCondition, ReadHandler>,
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
      const detail::read_op<AsyncReadStream, MutableBufferSequence,
        MutableBufferIterator, CompletionCondition, ReadHandler>& h,
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

template <typename AsyncReadStream, typename MutableBufferSequence,
    typename MutableBufferIterator, typename CompletionCondition,
    typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_op<AsyncReadStream, MutableBufferSequence,
      MutableBufferIterator, CompletionCondition, ReadHandler>,
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
      const detail::read_op<AsyncReadStream, MutableBufferSequence,
        MutableBufferIterator, CompletionCondition, ReadHandler>& h,
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<ReadHandler, Executor>::get(h.handler_, ex);
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename AsyncReadStream, typename MutableBufferSequence,
    typename CompletionCondition, typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
=======
template <typename AsyncReadStream,
    typename MutableBufferSequence, typename CompletionCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s, const MutableBufferSequence& buffers,
    CompletionCondition completion_condition,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_mutable_buffer_sequence<MutableBufferSequence>::value
    >::type*)
{
<<<<<<< HEAD
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a ReadHandler.
  BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

  async_completion<ReadHandler,
    void (boost::system::error_code, std::size_t)> init(handler);

  detail::start_read_buffer_sequence_op(s, buffers,
      boost::asio::buffer_sequence_begin(buffers), completion_condition,
      init.completion_handler);

  return init.result.get();
}

template <typename AsyncReadStream, typename MutableBufferSequence,
    typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
=======
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_buffer_sequence<AsyncReadStream>(s), handler,
      buffers, BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition));
}

template <typename AsyncReadStream, typename MutableBufferSequence,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s, const MutableBufferSequence& buffers,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_mutable_buffer_sequence<MutableBufferSequence>::value
    >::type*)
{
<<<<<<< HEAD
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a ReadHandler.
  BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

  async_completion<ReadHandler,
    void (boost::system::error_code, std::size_t)> init(handler);

  detail::start_read_buffer_sequence_op(s, buffers,
      boost::asio::buffer_sequence_begin(buffers), transfer_all(),
      init.completion_handler);

  return init.result.get();
}

namespace detail
{
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename CompletionCondition, typename ReadHandler>
  class read_dynbuf_op
=======
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_buffer_sequence<AsyncReadStream>(s),
      handler, buffers, transfer_all());
}

#if !defined(BOOST_ASIO_NO_DYNAMIC_BUFFER_V1)

namespace detail
{
  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename CompletionCondition, typename ReadHandler>
  class read_dynbuf_v1_op
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    : detail::base_from_completion_cond<CompletionCondition>
  {
  public:
    template <typename BufferSequence>
<<<<<<< HEAD
    read_dynbuf_op(AsyncReadStream& stream,
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        CompletionCondition completion_condition, ReadHandler& handler)
=======
    read_dynbuf_v1_op(AsyncReadStream& stream,
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        CompletionCondition& completion_condition, ReadHandler& handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      : detail::base_from_completion_cond<
          CompletionCondition>(completion_condition),
        stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        start_(0),
        total_transferred_(0),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
<<<<<<< HEAD
    read_dynbuf_op(const read_dynbuf_op& other)
=======
    read_dynbuf_v1_op(const read_dynbuf_v1_op& other)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      : detail::base_from_completion_cond<CompletionCondition>(other),
        stream_(other.stream_),
        buffers_(other.buffers_),
        start_(other.start_),
        total_transferred_(other.total_transferred_),
        handler_(other.handler_)
    {
    }

<<<<<<< HEAD
    read_dynbuf_op(read_dynbuf_op&& other)
      : detail::base_from_completion_cond<CompletionCondition>(other),
        stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer)(other.buffers_)),
=======
    read_dynbuf_v1_op(read_dynbuf_v1_op&& other)
      : detail::base_from_completion_cond<CompletionCondition>(
          BOOST_ASIO_MOVE_CAST(detail::base_from_completion_cond<
            CompletionCondition>)(other)),
        stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(other.buffers_)),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        start_(other.start_),
        total_transferred_(other.total_transferred_),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      std::size_t max_size, bytes_available;
      switch (start_ = start)
      {
        case 1:
        max_size = this->check_for_completion(ec, total_transferred_);
        bytes_available = std::min<std::size_t>(
              std::max<std::size_t>(512,
                buffers_.capacity() - buffers_.size()),
              std::min<std::size_t>(max_size,
                buffers_.max_size() - buffers_.size()));
        for (;;)
        {
          stream_.async_read_some(buffers_.prepare(bytes_available),
<<<<<<< HEAD
              BOOST_ASIO_MOVE_CAST(read_dynbuf_op)(*this));
=======
              BOOST_ASIO_MOVE_CAST(read_dynbuf_v1_op)(*this));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
          return; default:
          total_transferred_ += bytes_transferred;
          buffers_.commit(bytes_transferred);
          max_size = this->check_for_completion(ec, total_transferred_);
          bytes_available = std::min<std::size_t>(
                std::max<std::size_t>(512,
                  buffers_.capacity() - buffers_.size()),
                std::min<std::size_t>(max_size,
                  buffers_.max_size() - buffers_.size()));
          if ((!ec && bytes_transferred == 0) || bytes_available == 0)
            break;
        }

        handler_(ec, static_cast<const std::size_t&>(total_transferred_));
      }
    }

  //private:
    AsyncReadStream& stream_;
<<<<<<< HEAD
    DynamicBuffer buffers_;
=======
    DynamicBuffer_v1 buffers_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    int start_;
    std::size_t total_transferred_;
    ReadHandler handler_;
  };

<<<<<<< HEAD
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename CompletionCondition, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_dynbuf_op<AsyncReadStream, DynamicBuffer,
=======
  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename CompletionCondition, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_dynbuf_v1_op<AsyncReadStream, DynamicBuffer_v1,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        CompletionCondition, ReadHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename CompletionCondition, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_dynbuf_op<AsyncReadStream, DynamicBuffer,
=======
  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename CompletionCondition, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_dynbuf_v1_op<AsyncReadStream, DynamicBuffer_v1,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        CompletionCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename CompletionCondition, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_dynbuf_op<AsyncReadStream, DynamicBuffer,
=======
  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename CompletionCondition, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_dynbuf_v1_op<AsyncReadStream, DynamicBuffer_v1,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        CompletionCondition, ReadHandler>* this_handler)
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename CompletionCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_dynbuf_op<AsyncReadStream, DynamicBuffer,
=======
      typename DynamicBuffer_v1, typename CompletionCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_dynbuf_v1_op<AsyncReadStream, DynamicBuffer_v1,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        CompletionCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename CompletionCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_dynbuf_op<AsyncReadStream, DynamicBuffer,
=======
      typename DynamicBuffer_v1, typename CompletionCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_dynbuf_v1_op<AsyncReadStream, DynamicBuffer_v1,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        CompletionCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }
<<<<<<< HEAD
=======

  template <typename AsyncReadStream>
  class initiate_async_read_dynbuf_v1
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_dynbuf_v1(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler, typename DynamicBuffer_v1,
        typename CompletionCondition>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
        BOOST_ASIO_MOVE_ARG(CompletionCondition) completion_cond) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      non_const_lvalue<CompletionCondition> completion_cond2(completion_cond);
      read_dynbuf_v1_op<AsyncReadStream, typename decay<DynamicBuffer_v1>::type,
        CompletionCondition, typename decay<ReadHandler>::type>(
          stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
            completion_cond2.value, handler2.value)(
              boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename CompletionCondition, typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_dynbuf_op<AsyncReadStream,
      DynamicBuffer, CompletionCondition, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename CompletionCondition, typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_dynbuf_v1_op<AsyncReadStream,
      DynamicBuffer_v1, CompletionCondition, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_dynbuf_op<AsyncReadStream,
        DynamicBuffer, CompletionCondition, ReadHandler>& h,
=======
      const detail::read_dynbuf_v1_op<AsyncReadStream,
        DynamicBuffer_v1, CompletionCondition, ReadHandler>& h,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename CompletionCondition, typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_dynbuf_op<AsyncReadStream,
      DynamicBuffer, CompletionCondition, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename CompletionCondition, typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_dynbuf_v1_op<AsyncReadStream,
      DynamicBuffer_v1, CompletionCondition, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_dynbuf_op<AsyncReadStream,
        DynamicBuffer, CompletionCondition, ReadHandler>& h,
=======
      const detail::read_dynbuf_v1_op<AsyncReadStream,
        DynamicBuffer_v1, CompletionCondition, ReadHandler>& h,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<ReadHandler, Executor>::get(h.handler_, ex);
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename AsyncReadStream,
    typename DynamicBuffer, typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer<DynamicBuffer>::value
    >::type*)
{
  return async_read(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers),
      transfer_all(), BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
}

template <typename AsyncReadStream, typename DynamicBuffer,
    typename CompletionCondition, typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    CompletionCondition completion_condition,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer<DynamicBuffer>::value
=======
template <typename AsyncReadStream, typename DynamicBuffer_v1,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  return async_read(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
      transfer_all(), BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
}

template <typename AsyncReadStream,
    typename DynamicBuffer_v1, typename CompletionCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    CompletionCondition completion_condition,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    >::type*)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a ReadHandler.
  BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

<<<<<<< HEAD
  async_completion<ReadHandler,
    void (boost::system::error_code, std::size_t)> init(handler);

  detail::read_dynbuf_op<AsyncReadStream,
    typename decay<DynamicBuffer>::type,
      CompletionCondition, BOOST_ASIO_HANDLER_TYPE(
        ReadHandler, void (boost::system::error_code, std::size_t))>(
          s, BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers),
            completion_condition, init.completion_handler)(
              boost::system::error_code(), 0, 1);

  return init.result.get();
=======
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_dynbuf_v1<AsyncReadStream>(s),
      handler, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
      BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

#if !defined(BOOST_ASIO_NO_EXTENSIONS)
#if !defined(BOOST_ASIO_NO_IOSTREAM)

<<<<<<< HEAD
template <typename AsyncReadStream, typename Allocator, typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
=======
template <typename AsyncReadStream, typename Allocator,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s, basic_streambuf<Allocator>& b,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  return async_read(s, basic_streambuf_ref<Allocator>(b),
      BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
}

<<<<<<< HEAD
template <typename AsyncReadStream, typename Allocator,
    typename CompletionCondition, typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
=======
template <typename AsyncReadStream,
    typename Allocator, typename CompletionCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s, basic_streambuf<Allocator>& b,
    CompletionCondition completion_condition,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  return async_read(s, basic_streambuf_ref<Allocator>(b),
<<<<<<< HEAD
      completion_condition, BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
=======
      BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition),
      BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

#endif // !defined(BOOST_ASIO_NO_IOSTREAM)
#endif // !defined(BOOST_ASIO_NO_EXTENSIONS)
<<<<<<< HEAD
=======
#endif // !defined(BOOST_ASIO_NO_DYNAMIC_BUFFER_V1)

namespace detail
{
  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename CompletionCondition, typename ReadHandler>
  class read_dynbuf_v2_op
    : detail::base_from_completion_cond<CompletionCondition>
  {
  public:
    template <typename BufferSequence>
    read_dynbuf_v2_op(AsyncReadStream& stream,
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        CompletionCondition& completion_condition, ReadHandler& handler)
      : detail::base_from_completion_cond<
          CompletionCondition>(completion_condition),
        stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        start_(0),
        total_transferred_(0),
        bytes_available_(0),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
    read_dynbuf_v2_op(const read_dynbuf_v2_op& other)
      : detail::base_from_completion_cond<CompletionCondition>(other),
        stream_(other.stream_),
        buffers_(other.buffers_),
        start_(other.start_),
        total_transferred_(other.total_transferred_),
        bytes_available_(other.bytes_available_),
        handler_(other.handler_)
    {
    }

    read_dynbuf_v2_op(read_dynbuf_v2_op&& other)
      : detail::base_from_completion_cond<CompletionCondition>(
          BOOST_ASIO_MOVE_CAST(detail::base_from_completion_cond<
            CompletionCondition>)(other)),
        stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(other.buffers_)),
        start_(other.start_),
        total_transferred_(other.total_transferred_),
        bytes_available_(other.bytes_available_),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      std::size_t max_size, pos;
      switch (start_ = start)
      {
        case 1:
        max_size = this->check_for_completion(ec, total_transferred_);
        bytes_available_ = std::min<std::size_t>(
              std::max<std::size_t>(512,
                buffers_.capacity() - buffers_.size()),
              std::min<std::size_t>(max_size,
                buffers_.max_size() - buffers_.size()));
        for (;;)
        {
          pos = buffers_.size();
          buffers_.grow(bytes_available_);
          stream_.async_read_some(buffers_.data(pos, bytes_available_),
              BOOST_ASIO_MOVE_CAST(read_dynbuf_v2_op)(*this));
          return; default:
          total_transferred_ += bytes_transferred;
          buffers_.shrink(bytes_available_ - bytes_transferred);
          max_size = this->check_for_completion(ec, total_transferred_);
          bytes_available_ = std::min<std::size_t>(
                std::max<std::size_t>(512,
                  buffers_.capacity() - buffers_.size()),
                std::min<std::size_t>(max_size,
                  buffers_.max_size() - buffers_.size()));
          if ((!ec && bytes_transferred == 0) || bytes_available_ == 0)
            break;
        }

        handler_(ec, static_cast<const std::size_t&>(total_transferred_));
      }
    }

  //private:
    AsyncReadStream& stream_;
    DynamicBuffer_v2 buffers_;
    int start_;
    std::size_t total_transferred_;
    std::size_t bytes_available_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename CompletionCondition, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_dynbuf_v2_op<AsyncReadStream, DynamicBuffer_v2,
        CompletionCondition, ReadHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename CompletionCondition, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_dynbuf_v2_op<AsyncReadStream, DynamicBuffer_v2,
        CompletionCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename CompletionCondition, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_dynbuf_v2_op<AsyncReadStream, DynamicBuffer_v2,
        CompletionCondition, ReadHandler>* this_handler)
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v2, typename CompletionCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_dynbuf_v2_op<AsyncReadStream, DynamicBuffer_v2,
        CompletionCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v2, typename CompletionCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_dynbuf_v2_op<AsyncReadStream, DynamicBuffer_v2,
        CompletionCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename AsyncReadStream>
  class initiate_async_read_dynbuf_v2
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_dynbuf_v2(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler, typename DynamicBuffer_v2,
        typename CompletionCondition>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v2) buffers,
        BOOST_ASIO_MOVE_ARG(CompletionCondition) completion_cond) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      non_const_lvalue<CompletionCondition> completion_cond2(completion_cond);
      read_dynbuf_v2_op<AsyncReadStream, typename decay<DynamicBuffer_v2>::type,
        CompletionCondition, typename decay<ReadHandler>::type>(
          stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
            completion_cond2.value, handler2.value)(
              boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename CompletionCondition, typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_dynbuf_v2_op<AsyncReadStream,
      DynamicBuffer_v2, CompletionCondition, ReadHandler>,
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
      const detail::read_dynbuf_v2_op<AsyncReadStream,
        DynamicBuffer_v2, CompletionCondition, ReadHandler>& h,
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename CompletionCondition, typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_dynbuf_v2_op<AsyncReadStream,
      DynamicBuffer_v2, CompletionCondition, ReadHandler>,
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
      const detail::read_dynbuf_v2_op<AsyncReadStream,
        DynamicBuffer_v2, CompletionCondition, ReadHandler>& h,
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<ReadHandler, Executor>::get(h.handler_, ex);
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename DynamicBuffer_v2,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s, DynamicBuffer_v2 buffers,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  return async_read(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
      transfer_all(), BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
}

template <typename AsyncReadStream,
    typename DynamicBuffer_v2, typename CompletionCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read(AsyncReadStream& s, DynamicBuffer_v2 buffers,
    CompletionCondition completion_condition,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a ReadHandler.
  BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_dynbuf_v2<AsyncReadStream>(s),
      handler, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
      BOOST_ASIO_MOVE_CAST(CompletionCondition)(completion_condition));
}
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_IMPL_READ_HPP