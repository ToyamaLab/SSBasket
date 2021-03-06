//
// impl/read_until.hpp
// ~~~~~~~~~~~~~~~~~~~
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

#ifndef BOOST_ASIO_IMPL_READ_UNTIL_HPP
#define BOOST_ASIO_IMPL_READ_UNTIL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <boost/asio/associated_allocator.hpp>
#include <boost/asio/associated_executor.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/buffers_iterator.hpp>
#include <boost/asio/detail/bind_handler.hpp>
#include <boost/asio/detail/handler_alloc_helpers.hpp>
#include <boost/asio/detail/handler_cont_helpers.hpp>
#include <boost/asio/detail/handler_invoke_helpers.hpp>
#include <boost/asio/detail/handler_type_requirements.hpp>
#include <boost/asio/detail/limits.hpp>
<<<<<<< HEAD
=======
#include <boost/asio/detail/non_const_lvalue.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/asio/detail/throw_error.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {

<<<<<<< HEAD
template <typename SyncReadStream, typename DynamicBuffer>
inline std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers, char delim)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers), delim, ec);
=======
namespace detail
{
  // Algorithm that finds a subsequence of equal values in a sequence. Returns
  // (iterator,true) if a full match was found, in which case the iterator
  // points to the beginning of the match. Returns (iterator,false) if a
  // partial match was found at the end of the first sequence, in which case
  // the iterator points to the beginning of the partial match. Returns
  // (last1,false) if no full or partial match was found.
  template <typename Iterator1, typename Iterator2>
  std::pair<Iterator1, bool> partial_search(
      Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2)
  {
    for (Iterator1 iter1 = first1; iter1 != last1; ++iter1)
    {
      Iterator1 test_iter1 = iter1;
      Iterator2 test_iter2 = first2;
      for (;; ++test_iter1, ++test_iter2)
      {
        if (test_iter2 == last2)
          return std::make_pair(iter1, true);
        if (test_iter1 == last1)
        {
          if (test_iter2 != first2)
            return std::make_pair(iter1, false);
          else
            break;
        }
        if (*test_iter1 != *test_iter2)
          break;
      }
    }
    return std::make_pair(last1, false);
  }
} // namespace detail

#if !defined(BOOST_ASIO_NO_DYNAMIC_BUFFER_V1)

template <typename SyncReadStream, typename DynamicBuffer_v1>
inline std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers, char delim,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers), delim, ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  boost::asio::detail::throw_error(ec, "read_until");
  return bytes_transferred;
}

<<<<<<< HEAD
template <typename SyncReadStream, typename DynamicBuffer>
std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    char delim, boost::system::error_code& ec)
{
  typename decay<DynamicBuffer>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers));
=======
template <typename SyncReadStream, typename DynamicBuffer_v1>
std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    char delim, boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  typename decay<DynamicBuffer_v1>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

  std::size_t search_position = 0;
  for (;;)
  {
    // Determine the range of the data to be searched.
<<<<<<< HEAD
    typedef typename DynamicBuffer::const_buffers_type buffers_type;
=======
    typedef typename DynamicBuffer_v1::const_buffers_type buffers_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    typedef buffers_iterator<buffers_type> iterator;
    buffers_type data_buffers = b.data();
    iterator begin = iterator::begin(data_buffers);
    iterator start_pos = begin + search_position;
    iterator end = iterator::end(data_buffers);

    // Look for a match.
    iterator iter = std::find(start_pos, end, delim);
    if (iter != end)
    {
      // Found a match. We're done.
      ec = boost::system::error_code();
      return iter - begin + 1;
    }
    else
    {
      // No match. Next search can start with the new data.
      search_position = end - begin;
    }

    // Check if buffer is full.
    if (b.size() == b.max_size())
    {
      ec = error::not_found;
      return 0;
    }

    // Need more data.
    std::size_t bytes_to_read = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(65536, b.max_size() - b.size()));
    b.commit(s.read_some(b.prepare(bytes_to_read), ec));
    if (ec)
      return 0;
  }
}

<<<<<<< HEAD
template <typename SyncReadStream, typename DynamicBuffer>
inline std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    BOOST_ASIO_STRING_VIEW_PARAM delim)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers), delim, ec);
=======
template <typename SyncReadStream, typename DynamicBuffer_v1>
inline std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    BOOST_ASIO_STRING_VIEW_PARAM delim,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers), delim, ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  boost::asio::detail::throw_error(ec, "read_until");
  return bytes_transferred;
}

<<<<<<< HEAD
namespace detail
{
  // Algorithm that finds a subsequence of equal values in a sequence. Returns
  // (iterator,true) if a full match was found, in which case the iterator
  // points to the beginning of the match. Returns (iterator,false) if a
  // partial match was found at the end of the first sequence, in which case
  // the iterator points to the beginning of the partial match. Returns
  // (last1,false) if no full or partial match was found.
  template <typename Iterator1, typename Iterator2>
  std::pair<Iterator1, bool> partial_search(
      Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2)
  {
    for (Iterator1 iter1 = first1; iter1 != last1; ++iter1)
    {
      Iterator1 test_iter1 = iter1;
      Iterator2 test_iter2 = first2;
      for (;; ++test_iter1, ++test_iter2)
      {
        if (test_iter2 == last2)
          return std::make_pair(iter1, true);
        if (test_iter1 == last1)
        {
          if (test_iter2 != first2)
            return std::make_pair(iter1, false);
          else
            break;
        }
        if (*test_iter1 != *test_iter2)
          break;
      }
    }
    return std::make_pair(last1, false);
  }
} // namespace detail

template <typename SyncReadStream, typename DynamicBuffer>
std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    BOOST_ASIO_STRING_VIEW_PARAM delim, boost::system::error_code& ec)
{
  typename decay<DynamicBuffer>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers));
=======
template <typename SyncReadStream, typename DynamicBuffer_v1>
std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    BOOST_ASIO_STRING_VIEW_PARAM delim, boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  typename decay<DynamicBuffer_v1>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

  std::size_t search_position = 0;
  for (;;)
  {
    // Determine the range of the data to be searched.
<<<<<<< HEAD
    typedef typename DynamicBuffer::const_buffers_type buffers_type;
=======
    typedef typename DynamicBuffer_v1::const_buffers_type buffers_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    typedef buffers_iterator<buffers_type> iterator;
    buffers_type data_buffers = b.data();
    iterator begin = iterator::begin(data_buffers);
    iterator start_pos = begin + search_position;
    iterator end = iterator::end(data_buffers);

    // Look for a match.
    std::pair<iterator, bool> result = detail::partial_search(
        start_pos, end, delim.begin(), delim.end());
    if (result.first != end)
    {
      if (result.second)
      {
        // Full match. We're done.
        ec = boost::system::error_code();
        return result.first - begin + delim.length();
      }
      else
      {
        // Partial match. Next search needs to start from beginning of match.
        search_position = result.first - begin;
      }
    }
    else
    {
      // No match. Next search can start with the new data.
      search_position = end - begin;
    }

    // Check if buffer is full.
    if (b.size() == b.max_size())
    {
      ec = error::not_found;
      return 0;
    }

    // Need more data.
    std::size_t bytes_to_read = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(65536, b.max_size() - b.size()));
    b.commit(s.read_some(b.prepare(bytes_to_read), ec));
    if (ec)
      return 0;
  }
}

#if !defined(BOOST_ASIO_NO_EXTENSIONS)
#if defined(BOOST_ASIO_HAS_BOOST_REGEX)

<<<<<<< HEAD
template <typename SyncReadStream, typename DynamicBuffer>
inline std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    const boost::regex& expr)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers), expr, ec);
=======
template <typename SyncReadStream, typename DynamicBuffer_v1>
inline std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    const boost::regex& expr,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers), expr, ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  boost::asio::detail::throw_error(ec, "read_until");
  return bytes_transferred;
}

<<<<<<< HEAD
template <typename SyncReadStream, typename DynamicBuffer>
std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    const boost::regex& expr, boost::system::error_code& ec)
{
  typename decay<DynamicBuffer>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers));
=======
template <typename SyncReadStream, typename DynamicBuffer_v1>
std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    const boost::regex& expr, boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  typename decay<DynamicBuffer_v1>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

  std::size_t search_position = 0;
  for (;;)
  {
    // Determine the range of the data to be searched.
<<<<<<< HEAD
    typedef typename DynamicBuffer::const_buffers_type buffers_type;
=======
    typedef typename DynamicBuffer_v1::const_buffers_type buffers_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    typedef buffers_iterator<buffers_type> iterator;
    buffers_type data_buffers = b.data();
    iterator begin = iterator::begin(data_buffers);
    iterator start_pos = begin + search_position;
    iterator end = iterator::end(data_buffers);

    // Look for a match.
    boost::match_results<iterator,
      typename std::vector<boost::sub_match<iterator> >::allocator_type>
        match_results;
    if (regex_search(start_pos, end, match_results, expr,
          boost::match_default | boost::match_partial))
    {
      if (match_results[0].matched)
      {
        // Full match. We're done.
        ec = boost::system::error_code();
        return match_results[0].second - begin;
      }
      else
      {
        // Partial match. Next search needs to start from beginning of match.
        search_position = match_results[0].first - begin;
      }
    }
    else
    {
      // No match. Next search can start with the new data.
      search_position = end - begin;
    }

    // Check if buffer is full.
    if (b.size() == b.max_size())
    {
      ec = error::not_found;
      return 0;
    }

    // Need more data.
<<<<<<< HEAD
    std::size_t bytes_to_read = read_size_helper(b, 65536);
=======
    std::size_t bytes_to_read = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(65536, b.max_size() - b.size()));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    b.commit(s.read_some(b.prepare(bytes_to_read), ec));
    if (ec)
      return 0;
  }
}

#endif // defined(BOOST_ASIO_HAS_BOOST_REGEX)

template <typename SyncReadStream,
<<<<<<< HEAD
    typename DynamicBuffer, typename MatchCondition>
inline std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    MatchCondition match_condition,
    typename enable_if<is_match_condition<MatchCondition>::value>::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers),
=======
    typename DynamicBuffer_v1, typename MatchCondition>
inline std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    MatchCondition match_condition,
    typename enable_if<
      is_match_condition<MatchCondition>::value
        && is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      match_condition, ec);
  boost::asio::detail::throw_error(ec, "read_until");
  return bytes_transferred;
}

template <typename SyncReadStream,
<<<<<<< HEAD
    typename DynamicBuffer, typename MatchCondition>
std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    MatchCondition match_condition, boost::system::error_code& ec,
    typename enable_if<is_match_condition<MatchCondition>::value>::type*)
{
  typename decay<DynamicBuffer>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers));
=======
    typename DynamicBuffer_v1, typename MatchCondition>
std::size_t read_until(SyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    MatchCondition match_condition, boost::system::error_code& ec,
    typename enable_if<
      is_match_condition<MatchCondition>::value
        && is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  typename decay<DynamicBuffer_v1>::type b(
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

  std::size_t search_position = 0;
  for (;;)
  {
    // Determine the range of the data to be searched.
<<<<<<< HEAD
    typedef typename DynamicBuffer::const_buffers_type buffers_type;
=======
    typedef typename DynamicBuffer_v1::const_buffers_type buffers_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    typedef buffers_iterator<buffers_type> iterator;
    buffers_type data_buffers = b.data();
    iterator begin = iterator::begin(data_buffers);
    iterator start_pos = begin + search_position;
    iterator end = iterator::end(data_buffers);

    // Look for a match.
    std::pair<iterator, bool> result = match_condition(start_pos, end);
    if (result.second)
    {
      // Full match. We're done.
      ec = boost::system::error_code();
      return result.first - begin;
    }
    else if (result.first != end)
    {
      // Partial match. Next search needs to start from beginning of match.
      search_position = result.first - begin;
    }
    else
    {
      // No match. Next search can start with the new data.
      search_position = end - begin;
    }

<<<<<<< HEAD
    // Check if buffer is full.
    if (b.size() == b.max_size())
    {
      ec = error::not_found;
      return 0;
    }

    // Need more data.
    std::size_t bytes_to_read = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(65536, b.max_size() - b.size()));
    b.commit(s.read_some(b.prepare(bytes_to_read), ec));
    if (ec)
      return 0;
  }
}

#if !defined(BOOST_ASIO_NO_IOSTREAM)

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, char delim)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), delim);
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, char delim,
    boost::system::error_code& ec)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), delim, ec);
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    BOOST_ASIO_STRING_VIEW_PARAM delim)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), delim);
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    BOOST_ASIO_STRING_VIEW_PARAM delim, boost::system::error_code& ec)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), delim, ec);
=======
    // Check if buffer is full.
    if (b.size() == b.max_size())
    {
      ec = error::not_found;
      return 0;
    }

    // Need more data.
    std::size_t bytes_to_read = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(65536, b.max_size() - b.size()));
    b.commit(s.read_some(b.prepare(bytes_to_read), ec));
    if (ec)
      return 0;
  }
}

#if !defined(BOOST_ASIO_NO_IOSTREAM)

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, char delim)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), delim);
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, char delim,
    boost::system::error_code& ec)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), delim, ec);
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    BOOST_ASIO_STRING_VIEW_PARAM delim)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), delim);
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    BOOST_ASIO_STRING_VIEW_PARAM delim, boost::system::error_code& ec)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), delim, ec);
}

#if defined(BOOST_ASIO_HAS_BOOST_REGEX)

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, const boost::regex& expr)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), expr);
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, const boost::regex& expr,
    boost::system::error_code& ec)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), expr, ec);
}

#endif // defined(BOOST_ASIO_HAS_BOOST_REGEX)

template <typename SyncReadStream, typename Allocator, typename MatchCondition>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, MatchCondition match_condition,
    typename enable_if<is_match_condition<MatchCondition>::value>::type*)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), match_condition);
}

template <typename SyncReadStream, typename Allocator, typename MatchCondition>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    MatchCondition match_condition, boost::system::error_code& ec,
    typename enable_if<is_match_condition<MatchCondition>::value>::type*)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), match_condition, ec);
}

#endif // !defined(BOOST_ASIO_NO_IOSTREAM)
#endif // !defined(BOOST_ASIO_NO_EXTENSIONS)
#endif // !defined(BOOST_ASIO_NO_DYNAMIC_BUFFER_V1)

template <typename SyncReadStream, typename DynamicBuffer_v2>
inline std::size_t read_until(SyncReadStream& s,
    DynamicBuffer_v2 buffers, char delim,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers), delim, ec);
  boost::asio::detail::throw_error(ec, "read_until");
  return bytes_transferred;
}

template <typename SyncReadStream, typename DynamicBuffer_v2>
std::size_t read_until(SyncReadStream& s, DynamicBuffer_v2 buffers,
    char delim, boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  DynamicBuffer_v2& b = buffers;

  std::size_t search_position = 0;
  for (;;)
  {
    // Determine the range of the data to be searched.
    typedef typename DynamicBuffer_v2::const_buffers_type buffers_type;
    typedef buffers_iterator<buffers_type> iterator;
    buffers_type data_buffers =
      const_cast<const DynamicBuffer_v2&>(b).data(0, b.size());
    iterator begin = iterator::begin(data_buffers);
    iterator start_pos = begin + search_position;
    iterator end = iterator::end(data_buffers);

    // Look for a match.
    iterator iter = std::find(start_pos, end, delim);
    if (iter != end)
    {
      // Found a match. We're done.
      ec = boost::system::error_code();
      return iter - begin + 1;
    }
    else
    {
      // No match. Next search can start with the new data.
      search_position = end - begin;
    }

    // Check if buffer is full.
    if (b.size() == b.max_size())
    {
      ec = error::not_found;
      return 0;
    }

    // Need more data.
    std::size_t bytes_to_read = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(65536, b.max_size() - b.size()));
    std::size_t pos = b.size();
    b.grow(bytes_to_read);
    std::size_t bytes_transferred = s.read_some(b.data(pos, bytes_to_read), ec);
    b.shrink(bytes_to_read - bytes_transferred);
    if (ec)
      return 0;
  }
}

template <typename SyncReadStream, typename DynamicBuffer_v2>
inline std::size_t read_until(SyncReadStream& s,
    DynamicBuffer_v2 buffers, BOOST_ASIO_STRING_VIEW_PARAM delim,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers), delim, ec);
  boost::asio::detail::throw_error(ec, "read_until");
  return bytes_transferred;
}

template <typename SyncReadStream, typename DynamicBuffer_v2>
std::size_t read_until(SyncReadStream& s, DynamicBuffer_v2 buffers,
    BOOST_ASIO_STRING_VIEW_PARAM delim, boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  DynamicBuffer_v2& b = buffers;

  std::size_t search_position = 0;
  for (;;)
  {
    // Determine the range of the data to be searched.
    typedef typename DynamicBuffer_v2::const_buffers_type buffers_type;
    typedef buffers_iterator<buffers_type> iterator;
    buffers_type data_buffers =
      const_cast<const DynamicBuffer_v2&>(b).data(0, b.size());
    iterator begin = iterator::begin(data_buffers);
    iterator start_pos = begin + search_position;
    iterator end = iterator::end(data_buffers);

    // Look for a match.
    std::pair<iterator, bool> result = detail::partial_search(
        start_pos, end, delim.begin(), delim.end());
    if (result.first != end)
    {
      if (result.second)
      {
        // Full match. We're done.
        ec = boost::system::error_code();
        return result.first - begin + delim.length();
      }
      else
      {
        // Partial match. Next search needs to start from beginning of match.
        search_position = result.first - begin;
      }
    }
    else
    {
      // No match. Next search can start with the new data.
      search_position = end - begin;
    }

    // Check if buffer is full.
    if (b.size() == b.max_size())
    {
      ec = error::not_found;
      return 0;
    }

    // Need more data.
    std::size_t bytes_to_read = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(65536, b.max_size() - b.size()));
    std::size_t pos = b.size();
    b.grow(bytes_to_read);
    std::size_t bytes_transferred = s.read_some(b.data(pos, bytes_to_read), ec);
    b.shrink(bytes_to_read - bytes_transferred);
    if (ec)
      return 0;
  }
}

#if !defined(BOOST_ASIO_NO_EXTENSIONS)
#if defined(BOOST_ASIO_HAS_BOOST_REGEX)

template <typename SyncReadStream, typename DynamicBuffer_v2>
inline std::size_t read_until(SyncReadStream& s,
    DynamicBuffer_v2 buffers, const boost::regex& expr,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers), expr, ec);
  boost::asio::detail::throw_error(ec, "read_until");
  return bytes_transferred;
}

template <typename SyncReadStream, typename DynamicBuffer_v2>
std::size_t read_until(SyncReadStream& s, DynamicBuffer_v2 buffers,
    const boost::regex& expr, boost::system::error_code& ec,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  DynamicBuffer_v2& b = buffers;

  std::size_t search_position = 0;
  for (;;)
  {
    // Determine the range of the data to be searched.
    typedef typename DynamicBuffer_v2::const_buffers_type buffers_type;
    typedef buffers_iterator<buffers_type> iterator;
    buffers_type data_buffers =
      const_cast<const DynamicBuffer_v2&>(b).data(0, b.size());
    iterator begin = iterator::begin(data_buffers);
    iterator start_pos = begin + search_position;
    iterator end = iterator::end(data_buffers);

    // Look for a match.
    boost::match_results<iterator,
      typename std::vector<boost::sub_match<iterator> >::allocator_type>
        match_results;
    if (regex_search(start_pos, end, match_results, expr,
          boost::match_default | boost::match_partial))
    {
      if (match_results[0].matched)
      {
        // Full match. We're done.
        ec = boost::system::error_code();
        return match_results[0].second - begin;
      }
      else
      {
        // Partial match. Next search needs to start from beginning of match.
        search_position = match_results[0].first - begin;
      }
    }
    else
    {
      // No match. Next search can start with the new data.
      search_position = end - begin;
    }

    // Check if buffer is full.
    if (b.size() == b.max_size())
    {
      ec = error::not_found;
      return 0;
    }

    // Need more data.
    std::size_t bytes_to_read = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(65536, b.max_size() - b.size()));
    std::size_t pos = b.size();
    b.grow(bytes_to_read);
    std::size_t bytes_transferred = s.read_some(b.data(pos, bytes_to_read), ec);
    b.shrink(bytes_to_read - bytes_transferred);
    if (ec)
      return 0;
  }
}

#endif // defined(BOOST_ASIO_HAS_BOOST_REGEX)

template <typename SyncReadStream,
    typename DynamicBuffer_v2, typename MatchCondition>
inline std::size_t read_until(SyncReadStream& s,
    DynamicBuffer_v2 buffers, MatchCondition match_condition,
    typename enable_if<
      is_match_condition<MatchCondition>::value
        && is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  boost::system::error_code ec;
  std::size_t bytes_transferred = read_until(s,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
      match_condition, ec);
  boost::asio::detail::throw_error(ec, "read_until");
  return bytes_transferred;
}

template <typename SyncReadStream,
    typename DynamicBuffer_v2, typename MatchCondition>
std::size_t read_until(SyncReadStream& s, DynamicBuffer_v2 buffers,
    MatchCondition match_condition, boost::system::error_code& ec,
    typename enable_if<
      is_match_condition<MatchCondition>::value
        && is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  DynamicBuffer_v2& b = buffers;

  std::size_t search_position = 0;
  for (;;)
  {
    // Determine the range of the data to be searched.
    typedef typename DynamicBuffer_v2::const_buffers_type buffers_type;
    typedef buffers_iterator<buffers_type> iterator;
    buffers_type data_buffers =
      const_cast<const DynamicBuffer_v2&>(b).data(0, b.size());
    iterator begin = iterator::begin(data_buffers);
    iterator start_pos = begin + search_position;
    iterator end = iterator::end(data_buffers);

    // Look for a match.
    std::pair<iterator, bool> result = match_condition(start_pos, end);
    if (result.second)
    {
      // Full match. We're done.
      ec = boost::system::error_code();
      return result.first - begin;
    }
    else if (result.first != end)
    {
      // Partial match. Next search needs to start from beginning of match.
      search_position = result.first - begin;
    }
    else
    {
      // No match. Next search can start with the new data.
      search_position = end - begin;
    }

    // Check if buffer is full.
    if (b.size() == b.max_size())
    {
      ec = error::not_found;
      return 0;
    }

    // Need more data.
    std::size_t bytes_to_read = std::min<std::size_t>(
          std::max<std::size_t>(512, b.capacity() - b.size()),
          std::min<std::size_t>(65536, b.max_size() - b.size()));
    std::size_t pos = b.size();
    b.grow(bytes_to_read);
    std::size_t bytes_transferred = s.read_some(b.data(pos, bytes_to_read), ec);
    b.shrink(bytes_to_read - bytes_transferred);
    if (ec)
      return 0;
  }
}

#endif // !defined(BOOST_ASIO_NO_EXTENSIONS)

#if !defined(BOOST_ASIO_NO_DYNAMIC_BUFFER_V1)

namespace detail
{
  template <typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  class read_until_delim_op_v1
  {
  public:
    template <typename BufferSequence>
    read_until_delim_op_v1(AsyncReadStream& stream,
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        char delim, ReadHandler& handler)
      : stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        delim_(delim),
        start_(0),
        search_position_(0),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
    read_until_delim_op_v1(const read_until_delim_op_v1& other)
      : stream_(other.stream_),
        buffers_(other.buffers_),
        delim_(other.delim_),
        start_(other.start_),
        search_position_(other.search_position_),
        handler_(other.handler_)
    {
    }

    read_until_delim_op_v1(read_until_delim_op_v1&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(other.buffers_)),
        delim_(other.delim_),
        start_(other.start_),
        search_position_(other.search_position_),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      const std::size_t not_found = (std::numeric_limits<std::size_t>::max)();
      std::size_t bytes_to_read;
      switch (start_ = start)
      {
      case 1:
        for (;;)
        {
          {
            // Determine the range of the data to be searched.
            typedef typename DynamicBuffer_v1::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers = buffers_.data();
            iterator begin = iterator::begin(data_buffers);
            iterator start_pos = begin + search_position_;
            iterator end = iterator::end(data_buffers);

            // Look for a match.
            iterator iter = std::find(start_pos, end, delim_);
            if (iter != end)
            {
              // Found a match. We're done.
              search_position_ = iter - begin + 1;
              bytes_to_read = 0;
            }

            // No match yet. Check if buffer is full.
            else if (buffers_.size() == buffers_.max_size())
            {
              search_position_ = not_found;
              bytes_to_read = 0;
            }

            // Need to read some more data.
            else
            {
              // Next search can start with the new data.
              search_position_ = end - begin;
              bytes_to_read = std::min<std::size_t>(
                    std::max<std::size_t>(512,
                      buffers_.capacity() - buffers_.size()),
                    std::min<std::size_t>(65536,
                      buffers_.max_size() - buffers_.size()));
            }
          }

          // Check if we're done.
          if (!start && bytes_to_read == 0)
            break;

          // Start a new asynchronous read op_v1eration to obtain more data.
          stream_.async_read_some(buffers_.prepare(bytes_to_read),
              BOOST_ASIO_MOVE_CAST(read_until_delim_op_v1)(*this));
          return; default:
          buffers_.commit(bytes_transferred);
          if (ec || bytes_transferred == 0)
            break;
        }

        const boost::system::error_code result_ec =
          (search_position_ == not_found)
          ? error::not_found : ec;

        const std::size_t result_n =
          (ec || search_position_ == not_found)
          ? 0 : search_position_;

        handler_(result_ec, result_n);
      }
    }

  //private:
    AsyncReadStream& stream_;
    DynamicBuffer_v1 buffers_;
    char delim_;
    int start_;
    std::size_t search_position_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_delim_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

  template <typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_delim_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

  template <typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_delim_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_delim_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_delim_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename AsyncReadStream>
  class initiate_async_read_until_delim_v1
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_until_delim_v1(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler, typename DynamicBuffer_v1>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
        char delim) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      read_until_delim_op_v1<AsyncReadStream,
        typename decay<DynamicBuffer_v1>::type,
          typename decay<ReadHandler>::type>(
            stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
            delim, handler2.value)(boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_delim_op_v1<AsyncReadStream,
      DynamicBuffer_v1, ReadHandler>,
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
      const detail::read_until_delim_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>& h,
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_delim_op_v1<AsyncReadStream,
      DynamicBuffer_v1, ReadHandler>,
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
      const detail::read_until_delim_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>& h,
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<ReadHandler, Executor>::get(h.handler_, ex);
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    char delim, BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_until_delim_v1<AsyncReadStream>(s),
      handler, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers), delim);
}

namespace detail
{
  template <typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  class read_until_delim_string_op_v1
  {
  public:
    template <typename BufferSequence>
    read_until_delim_string_op_v1(AsyncReadStream& stream,
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        const std::string& delim, ReadHandler& handler)
      : stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        delim_(delim),
        start_(0),
        search_position_(0),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
    read_until_delim_string_op_v1(const read_until_delim_string_op_v1& other)
      : stream_(other.stream_),
        buffers_(other.buffers_),
        delim_(other.delim_),
        start_(other.start_),
        search_position_(other.search_position_),
        handler_(other.handler_)
    {
    }

    read_until_delim_string_op_v1(read_until_delim_string_op_v1&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(other.buffers_)),
        delim_(BOOST_ASIO_MOVE_CAST(std::string)(other.delim_)),
        start_(other.start_),
        search_position_(other.search_position_),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      const std::size_t not_found = (std::numeric_limits<std::size_t>::max)();
      std::size_t bytes_to_read;
      switch (start_ = start)
      {
      case 1:
        for (;;)
        {
          {
            // Determine the range of the data to be searched.
            typedef typename DynamicBuffer_v1::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers = buffers_.data();
            iterator begin = iterator::begin(data_buffers);
            iterator start_pos = begin + search_position_;
            iterator end = iterator::end(data_buffers);

            // Look for a match.
            std::pair<iterator, bool> result = detail::partial_search(
                start_pos, end, delim_.begin(), delim_.end());
            if (result.first != end && result.second)
            {
              // Full match. We're done.
              search_position_ = result.first - begin + delim_.length();
              bytes_to_read = 0;
            }

            // No match yet. Check if buffer is full.
            else if (buffers_.size() == buffers_.max_size())
            {
              search_position_ = not_found;
              bytes_to_read = 0;
            }

            // Need to read some more data.
            else
            {
              if (result.first != end)
              {
                // Partial match. Next search needs to start from beginning of
                // match.
                search_position_ = result.first - begin;
              }
              else
              {
                // Next search can start with the new data.
                search_position_ = end - begin;
              }

              bytes_to_read = std::min<std::size_t>(
                    std::max<std::size_t>(512,
                      buffers_.capacity() - buffers_.size()),
                    std::min<std::size_t>(65536,
                      buffers_.max_size() - buffers_.size()));
            }
          }

          // Check if we're done.
          if (!start && bytes_to_read == 0)
            break;

          // Start a new asynchronous read op_v1eration to obtain more data.
          stream_.async_read_some(buffers_.prepare(bytes_to_read),
              BOOST_ASIO_MOVE_CAST(read_until_delim_string_op_v1)(*this));
          return; default:
          buffers_.commit(bytes_transferred);
          if (ec || bytes_transferred == 0)
            break;
        }

        const boost::system::error_code result_ec =
          (search_position_ == not_found)
          ? error::not_found : ec;

        const std::size_t result_n =
          (ec || search_position_ == not_found)
          ? 0 : search_position_;

        handler_(result_ec, result_n);
      }
    }

  //private:
    AsyncReadStream& stream_;
    DynamicBuffer_v1 buffers_;
    std::string delim_;
    int start_;
    std::size_t search_position_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_delim_string_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

  template <typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_delim_string_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

  template <typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_delim_string_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_delim_string_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v1, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_delim_string_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename AsyncReadStream>
  class initiate_async_read_until_delim_string_v1
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_until_delim_string_v1(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler, typename DynamicBuffer_v1>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
        const std::string& delim) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      read_until_delim_string_op_v1<AsyncReadStream,
        typename decay<DynamicBuffer_v1>::type,
          typename decay<ReadHandler>::type>(
            stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
            delim, handler2.value)(boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_delim_string_op_v1<AsyncReadStream,
      DynamicBuffer_v1, ReadHandler>,
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
      const detail::read_until_delim_string_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>& h,
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_delim_string_op_v1<AsyncReadStream,
      DynamicBuffer_v1, ReadHandler>,
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
      const detail::read_until_delim_string_op_v1<AsyncReadStream,
        DynamicBuffer_v1, ReadHandler>& h,
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<ReadHandler, Executor>::get(h.handler_, ex);
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    BOOST_ASIO_STRING_VIEW_PARAM delim,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_until_delim_string_v1<AsyncReadStream>(s),
      handler, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
      static_cast<std::string>(delim));
}

#if !defined(BOOST_ASIO_NO_EXTENSIONS)
#if defined(BOOST_ASIO_HAS_BOOST_REGEX)

namespace detail
{
  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename RegEx, typename ReadHandler>
  class read_until_expr_op_v1
  {
  public:
    template <typename BufferSequence>
    read_until_expr_op_v1(AsyncReadStream& stream,
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        const boost::regex& expr, ReadHandler& handler)
      : stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        expr_(expr),
        start_(0),
        search_position_(0),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
    read_until_expr_op_v1(const read_until_expr_op_v1& other)
      : stream_(other.stream_),
        buffers_(other.buffers_),
        expr_(other.expr_),
        start_(other.start_),
        search_position_(other.search_position_),
        handler_(other.handler_)
    {
    }

    read_until_expr_op_v1(read_until_expr_op_v1&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(other.buffers_)),
        expr_(other.expr_),
        start_(other.start_),
        search_position_(other.search_position_),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      const std::size_t not_found = (std::numeric_limits<std::size_t>::max)();
      std::size_t bytes_to_read;
      switch (start_ = start)
      {
      case 1:
        for (;;)
        {
          {
            // Determine the range of the data to be searched.
            typedef typename DynamicBuffer_v1::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers = buffers_.data();
            iterator begin = iterator::begin(data_buffers);
            iterator start_pos = begin + search_position_;
            iterator end = iterator::end(data_buffers);

            // Look for a match.
            boost::match_results<iterator,
              typename std::vector<boost::sub_match<iterator> >::allocator_type>
                match_results;
            bool match = regex_search(start_pos, end, match_results, expr_,
                boost::match_default | boost::match_partial);
            if (match && match_results[0].matched)
            {
              // Full match. We're done.
              search_position_ = match_results[0].second - begin;
              bytes_to_read = 0;
            }

            // No match yet. Check if buffer is full.
            else if (buffers_.size() == buffers_.max_size())
            {
              search_position_ = not_found;
              bytes_to_read = 0;
            }

            // Need to read some more data.
            else
            {
              if (match)
              {
                // Partial match. Next search needs to start from beginning of
                // match.
                search_position_ = match_results[0].first - begin;
              }
              else
              {
                // Next search can start with the new data.
                search_position_ = end - begin;
              }

              bytes_to_read = std::min<std::size_t>(
                    std::max<std::size_t>(512,
                      buffers_.capacity() - buffers_.size()),
                    std::min<std::size_t>(65536,
                      buffers_.max_size() - buffers_.size()));
            }
          }

          // Check if we're done.
          if (!start && bytes_to_read == 0)
            break;

          // Start a new asynchronous read op_v1eration to obtain more data.
          stream_.async_read_some(buffers_.prepare(bytes_to_read),
              BOOST_ASIO_MOVE_CAST(read_until_expr_op_v1)(*this));
          return; default:
          buffers_.commit(bytes_transferred);
          if (ec || bytes_transferred == 0)
            break;
        }

        const boost::system::error_code result_ec =
          (search_position_ == not_found)
          ? error::not_found : ec;

        const std::size_t result_n =
          (ec || search_position_ == not_found)
          ? 0 : search_position_;

        handler_(result_ec, result_n);
      }
    }

  //private:
    AsyncReadStream& stream_;
    DynamicBuffer_v1 buffers_;
    RegEx expr_;
    int start_;
    std::size_t search_position_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename RegEx, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_expr_op_v1<AsyncReadStream,
        DynamicBuffer_v1, RegEx, ReadHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename RegEx, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_expr_op_v1<AsyncReadStream,
        DynamicBuffer_v1, RegEx, ReadHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename RegEx, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_expr_op_v1<AsyncReadStream,
        DynamicBuffer_v1, RegEx, ReadHandler>* this_handler)
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v1, typename RegEx, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_expr_op_v1<AsyncReadStream,
        DynamicBuffer_v1, RegEx, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v1, typename RegEx, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_expr_op_v1<AsyncReadStream,
        DynamicBuffer_v1, RegEx, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename AsyncReadStream>
  class initiate_async_read_until_expr_v1
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_until_expr_v1(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler, typename DynamicBuffer_v1, typename RegEx>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers, const RegEx& expr) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      read_until_expr_op_v1<AsyncReadStream,
        typename decay<DynamicBuffer_v1>::type,
          RegEx, typename decay<ReadHandler>::type>(
            stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
            expr, handler2.value)(boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename RegEx, typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_expr_op_v1<AsyncReadStream,
      DynamicBuffer_v1, RegEx, ReadHandler>,
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
      const detail::read_until_expr_op_v1<AsyncReadStream,
        DynamicBuffer_v1, RegEx, ReadHandler>& h,
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename RegEx, typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_expr_op_v1<AsyncReadStream,
      DynamicBuffer_v1, RegEx, ReadHandler>,
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
      const detail::read_until_expr_op_v1<AsyncReadStream,
        DynamicBuffer_v1, RegEx, ReadHandler>& h,
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<ReadHandler, Executor>::get(h.handler_, ex);
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    const boost::regex& expr,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_until_expr_v1<AsyncReadStream>(s),
      handler, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers), expr);
}

#endif // defined(BOOST_ASIO_HAS_BOOST_REGEX)

namespace detail
{
  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename MatchCondition, typename ReadHandler>
  class read_until_match_op_v1
  {
  public:
    template <typename BufferSequence>
    read_until_match_op_v1(AsyncReadStream& stream,
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        MatchCondition match_condition, ReadHandler& handler)
      : stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        match_condition_(match_condition),
        start_(0),
        search_position_(0),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
    read_until_match_op_v1(const read_until_match_op_v1& other)
      : stream_(other.stream_),
        buffers_(other.buffers_),
        match_condition_(other.match_condition_),
        start_(other.start_),
        search_position_(other.search_position_),
        handler_(other.handler_)
    {
    }

    read_until_match_op_v1(read_until_match_op_v1&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(other.buffers_)),
        match_condition_(other.match_condition_),
        start_(other.start_),
        search_position_(other.search_position_),
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      const std::size_t not_found = (std::numeric_limits<std::size_t>::max)();
      std::size_t bytes_to_read;
      switch (start_ = start)
      {
      case 1:
        for (;;)
        {
          {
            // Determine the range of the data to be searched.
            typedef typename DynamicBuffer_v1::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers = buffers_.data();
            iterator begin = iterator::begin(data_buffers);
            iterator start_pos = begin + search_position_;
            iterator end = iterator::end(data_buffers);

            // Look for a match.
            std::pair<iterator, bool> result = match_condition_(start_pos, end);
            if (result.second)
            {
              // Full match. We're done.
              search_position_ = result.first - begin;
              bytes_to_read = 0;
            }

            // No match yet. Check if buffer is full.
            else if (buffers_.size() == buffers_.max_size())
            {
              search_position_ = not_found;
              bytes_to_read = 0;
            }

            // Need to read some more data.
            else
            {
              if (result.first != end)
              {
                // Partial match. Next search needs to start from beginning of
                // match.
                search_position_ = result.first - begin;
              }
              else
              {
                // Next search can start with the new data.
                search_position_ = end - begin;
              }

              bytes_to_read = std::min<std::size_t>(
                    std::max<std::size_t>(512,
                      buffers_.capacity() - buffers_.size()),
                    std::min<std::size_t>(65536,
                      buffers_.max_size() - buffers_.size()));
            }
          }

          // Check if we're done.
          if (!start && bytes_to_read == 0)
            break;

          // Start a new asynchronous read op_v1eration to obtain more data.
          stream_.async_read_some(buffers_.prepare(bytes_to_read),
              BOOST_ASIO_MOVE_CAST(read_until_match_op_v1)(*this));
          return; default:
          buffers_.commit(bytes_transferred);
          if (ec || bytes_transferred == 0)
            break;
        }

        const boost::system::error_code result_ec =
          (search_position_ == not_found)
          ? error::not_found : ec;

        const std::size_t result_n =
          (ec || search_position_ == not_found)
          ? 0 : search_position_;

        handler_(result_ec, result_n);
      }
    }

  //private:
    AsyncReadStream& stream_;
    DynamicBuffer_v1 buffers_;
    MatchCondition match_condition_;
    int start_;
    std::size_t search_position_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename MatchCondition, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_match_op_v1<AsyncReadStream, DynamicBuffer_v1,
        MatchCondition, ReadHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename MatchCondition, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_match_op_v1<AsyncReadStream, DynamicBuffer_v1,
        MatchCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

  template <typename AsyncReadStream, typename DynamicBuffer_v1,
      typename MatchCondition, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_match_op_v1<AsyncReadStream, DynamicBuffer_v1,
        MatchCondition, ReadHandler>* this_handler)
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v1, typename MatchCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_match_op_v1<AsyncReadStream, DynamicBuffer_v1,
        MatchCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
      typename DynamicBuffer_v1, typename MatchCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_match_op_v1<AsyncReadStream, DynamicBuffer_v1,
      MatchCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename AsyncReadStream>
  class initiate_async_read_until_match_v1
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_until_match_v1(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler,
        typename DynamicBuffer_v1, typename MatchCondition>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
        MatchCondition match_condition) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      read_until_match_op_v1<AsyncReadStream,
        typename decay<DynamicBuffer_v1>::type,
          MatchCondition, typename decay<ReadHandler>::type>(
            stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers),
            match_condition, handler2.value)(boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename MatchCondition, typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_match_op_v1<AsyncReadStream,
      DynamicBuffer_v1, MatchCondition, ReadHandler>,
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
      const detail::read_until_match_op_v1<AsyncReadStream,
        DynamicBuffer_v1, MatchCondition, ReadHandler>& h,
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

template <typename AsyncReadStream, typename DynamicBuffer_v1,
    typename MatchCondition, typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_match_op_v1<AsyncReadStream,
      DynamicBuffer_v1, MatchCondition, ReadHandler>,
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
      const detail::read_until_match_op_v1<AsyncReadStream,
        DynamicBuffer_v1, MatchCondition, ReadHandler>& h,
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<ReadHandler, Executor>::get(h.handler_, ex);
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream,
    typename DynamicBuffer_v1, typename MatchCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer_v1) buffers,
    MatchCondition match_condition, BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_match_condition<MatchCondition>::value
        && is_dynamic_buffer_v1<typename decay<DynamicBuffer_v1>::type>::value
        && !is_dynamic_buffer_v2<typename decay<DynamicBuffer_v1>::type>::value
    >::type*)
{
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_until_match_v1<AsyncReadStream>(s), handler,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v1)(buffers), match_condition);
}

#if !defined(BOOST_ASIO_NO_IOSTREAM)

template <typename AsyncReadStream, typename Allocator,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    char delim, BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  return async_read_until(s, basic_streambuf_ref<Allocator>(b),
      delim, BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
}

template <typename AsyncReadStream, typename Allocator,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    BOOST_ASIO_STRING_VIEW_PARAM delim,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  return async_read_until(s, basic_streambuf_ref<Allocator>(b),
      delim, BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

#if defined(BOOST_ASIO_HAS_BOOST_REGEX)

<<<<<<< HEAD
template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, const boost::regex& expr)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), expr);
}

template <typename SyncReadStream, typename Allocator>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, const boost::regex& expr,
    boost::system::error_code& ec)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), expr, ec);
=======
template <typename AsyncReadStream, typename Allocator,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, const boost::regex& expr,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  return async_read_until(s, basic_streambuf_ref<Allocator>(b),
      expr, BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

#endif // defined(BOOST_ASIO_HAS_BOOST_REGEX)

<<<<<<< HEAD
template <typename SyncReadStream, typename Allocator, typename MatchCondition>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, MatchCondition match_condition,
    typename enable_if<is_match_condition<MatchCondition>::value>::type*)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), match_condition);
}

template <typename SyncReadStream, typename Allocator, typename MatchCondition>
inline std::size_t read_until(SyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    MatchCondition match_condition, boost::system::error_code& ec,
    typename enable_if<is_match_condition<MatchCondition>::value>::type*)
{
  return read_until(s, basic_streambuf_ref<Allocator>(b), match_condition, ec);
=======
template <typename AsyncReadStream, typename Allocator, typename MatchCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
inline BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    MatchCondition match_condition, BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<is_match_condition<MatchCondition>::value>::type*)
{
  return async_read_until(s, basic_streambuf_ref<Allocator>(b),
      match_condition, BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

#endif // !defined(BOOST_ASIO_NO_IOSTREAM)
#endif // !defined(BOOST_ASIO_NO_EXTENSIONS)
<<<<<<< HEAD
=======
#endif // !defined(BOOST_ASIO_NO_DYNAMIC_BUFFER_V1)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace detail
{
  template <typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  class read_until_delim_op
  {
  public:
    template <typename BufferSequence>
    read_until_delim_op(AsyncReadStream& stream,
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  class read_until_delim_op_v2
  {
  public:
    template <typename BufferSequence>
    read_until_delim_op_v2(AsyncReadStream& stream,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        char delim, ReadHandler& handler)
      : stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        delim_(delim),
        start_(0),
        search_position_(0),
<<<<<<< HEAD
=======
        bytes_to_read_(0),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
<<<<<<< HEAD
    read_until_delim_op(const read_until_delim_op& other)
=======
    read_until_delim_op_v2(const read_until_delim_op_v2& other)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      : stream_(other.stream_),
        buffers_(other.buffers_),
        delim_(other.delim_),
        start_(other.start_),
        search_position_(other.search_position_),
<<<<<<< HEAD
=======
        bytes_to_read_(other.bytes_to_read_),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(other.handler_)
    {
    }

<<<<<<< HEAD
    read_until_delim_op(read_until_delim_op&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer)(other.buffers_)),
        delim_(other.delim_),
        start_(other.start_),
        search_position_(other.search_position_),
=======
    read_until_delim_op_v2(read_until_delim_op_v2&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(other.buffers_)),
        delim_(other.delim_),
        start_(other.start_),
        search_position_(other.search_position_),
        bytes_to_read_(other.bytes_to_read_),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      const std::size_t not_found = (std::numeric_limits<std::size_t>::max)();
<<<<<<< HEAD
      std::size_t bytes_to_read;
=======
      std::size_t pos;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      switch (start_ = start)
      {
      case 1:
        for (;;)
        {
          {
            // Determine the range of the data to be searched.
<<<<<<< HEAD
            typedef typename DynamicBuffer::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers = buffers_.data();
=======
            typedef typename DynamicBuffer_v2::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers =
              const_cast<const DynamicBuffer_v2&>(buffers_).data(
                  0, buffers_.size());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            iterator begin = iterator::begin(data_buffers);
            iterator start_pos = begin + search_position_;
            iterator end = iterator::end(data_buffers);

            // Look for a match.
            iterator iter = std::find(start_pos, end, delim_);
            if (iter != end)
            {
              // Found a match. We're done.
              search_position_ = iter - begin + 1;
<<<<<<< HEAD
              bytes_to_read = 0;
=======
              bytes_to_read_ = 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }

            // No match yet. Check if buffer is full.
            else if (buffers_.size() == buffers_.max_size())
            {
              search_position_ = not_found;
<<<<<<< HEAD
              bytes_to_read = 0;
=======
              bytes_to_read_ = 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }

            // Need to read some more data.
            else
            {
              // Next search can start with the new data.
              search_position_ = end - begin;
<<<<<<< HEAD
              bytes_to_read = std::min<std::size_t>(
=======
              bytes_to_read_ = std::min<std::size_t>(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                    std::max<std::size_t>(512,
                      buffers_.capacity() - buffers_.size()),
                    std::min<std::size_t>(65536,
                      buffers_.max_size() - buffers_.size()));
            }
          }

          // Check if we're done.
<<<<<<< HEAD
          if (!start && bytes_to_read == 0)
            break;

          // Start a new asynchronous read operation to obtain more data.
          stream_.async_read_some(buffers_.prepare(bytes_to_read),
              BOOST_ASIO_MOVE_CAST(read_until_delim_op)(*this));
          return; default:
          buffers_.commit(bytes_transferred);
=======
          if (!start && bytes_to_read_ == 0)
            break;

          // Start a new asynchronous read op_v2eration to obtain more data.
          pos = buffers_.size();
          buffers_.grow(bytes_to_read_);
          stream_.async_read_some(buffers_.data(pos, bytes_to_read_),
              BOOST_ASIO_MOVE_CAST(read_until_delim_op_v2)(*this));
          return; default:
          buffers_.shrink(bytes_to_read_ - bytes_transferred);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
          if (ec || bytes_transferred == 0)
            break;
        }

        const boost::system::error_code result_ec =
          (search_position_ == not_found)
          ? error::not_found : ec;

        const std::size_t result_n =
          (ec || search_position_ == not_found)
          ? 0 : search_position_;

        handler_(result_ec, result_n);
      }
    }

  //private:
    AsyncReadStream& stream_;
<<<<<<< HEAD
    DynamicBuffer buffers_;
    char delim_;
    int start_;
    std::size_t search_position_;
=======
    DynamicBuffer_v2 buffers_;
    char delim_;
    int start_;
    std::size_t search_position_;
    std::size_t bytes_to_read_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    ReadHandler handler_;
  };

  template <typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_delim_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_delim_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

  template <typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_delim_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_delim_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

  template <typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_delim_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_delim_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_delim_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_delim_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_delim_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_delim_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }
<<<<<<< HEAD
=======

  template <typename AsyncReadStream>
  class initiate_async_read_until_delim_v2
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_until_delim_v2(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler, typename DynamicBuffer_v2>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v2) buffers, char delim) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      read_until_delim_op_v2<AsyncReadStream,
        typename decay<DynamicBuffer_v2>::type,
          typename decay<ReadHandler>::type>(
            stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
            delim, handler2.value)(boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_delim_op<AsyncReadStream,
      DynamicBuffer, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_delim_op_v2<AsyncReadStream,
      DynamicBuffer_v2, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_until_delim_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>& h,
=======
      const detail::read_until_delim_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>& h,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_delim_op<AsyncReadStream,
      DynamicBuffer, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_delim_op_v2<AsyncReadStream,
      DynamicBuffer_v2, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_until_delim_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>& h,
=======
      const detail::read_until_delim_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>& h,
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
BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    char delim, BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a ReadHandler.
  BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

  async_completion<ReadHandler,
    void (boost::system::error_code, std::size_t)> init(handler);

  detail::read_until_delim_op<AsyncReadStream,
    typename decay<DynamicBuffer>::type,
      BOOST_ASIO_HANDLER_TYPE(ReadHandler,
        void (boost::system::error_code, std::size_t))>(
          s, BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers),
            delim, init.completion_handler)(boost::system::error_code(), 0, 1);

  return init.result.get();
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s, DynamicBuffer_v2 buffers,
    char delim, BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_until_delim_v2<AsyncReadStream>(s),
      handler, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers), delim);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

namespace detail
{
  template <typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  class read_until_delim_string_op
  {
  public:
    template <typename BufferSequence>
    read_until_delim_string_op(AsyncReadStream& stream,
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  class read_until_delim_string_op_v2
  {
  public:
    template <typename BufferSequence>
    read_until_delim_string_op_v2(AsyncReadStream& stream,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        const std::string& delim, ReadHandler& handler)
      : stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        delim_(delim),
        start_(0),
        search_position_(0),
<<<<<<< HEAD
=======
        bytes_to_read_(0),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
<<<<<<< HEAD
    read_until_delim_string_op(const read_until_delim_string_op& other)
=======
    read_until_delim_string_op_v2(const read_until_delim_string_op_v2& other)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      : stream_(other.stream_),
        buffers_(other.buffers_),
        delim_(other.delim_),
        start_(other.start_),
        search_position_(other.search_position_),
<<<<<<< HEAD
=======
        bytes_to_read_(other.bytes_to_read_),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(other.handler_)
    {
    }

<<<<<<< HEAD
    read_until_delim_string_op(read_until_delim_string_op&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer)(other.buffers_)),
        delim_(BOOST_ASIO_MOVE_CAST(std::string)(other.delim_)),
        start_(other.start_),
        search_position_(other.search_position_),
=======
    read_until_delim_string_op_v2(read_until_delim_string_op_v2&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(other.buffers_)),
        delim_(BOOST_ASIO_MOVE_CAST(std::string)(other.delim_)),
        start_(other.start_),
        search_position_(other.search_position_),
        bytes_to_read_(other.bytes_to_read_),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      const std::size_t not_found = (std::numeric_limits<std::size_t>::max)();
<<<<<<< HEAD
      std::size_t bytes_to_read;
=======
      std::size_t pos;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      switch (start_ = start)
      {
      case 1:
        for (;;)
        {
          {
            // Determine the range of the data to be searched.
<<<<<<< HEAD
            typedef typename DynamicBuffer::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers = buffers_.data();
=======
            typedef typename DynamicBuffer_v2::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers =
              const_cast<const DynamicBuffer_v2&>(buffers_).data(
                  0, buffers_.size());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            iterator begin = iterator::begin(data_buffers);
            iterator start_pos = begin + search_position_;
            iterator end = iterator::end(data_buffers);

            // Look for a match.
            std::pair<iterator, bool> result = detail::partial_search(
                start_pos, end, delim_.begin(), delim_.end());
            if (result.first != end && result.second)
            {
              // Full match. We're done.
              search_position_ = result.first - begin + delim_.length();
<<<<<<< HEAD
              bytes_to_read = 0;
=======
              bytes_to_read_ = 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }

            // No match yet. Check if buffer is full.
            else if (buffers_.size() == buffers_.max_size())
            {
              search_position_ = not_found;
<<<<<<< HEAD
              bytes_to_read = 0;
=======
              bytes_to_read_ = 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }

            // Need to read some more data.
            else
            {
              if (result.first != end)
              {
                // Partial match. Next search needs to start from beginning of
                // match.
                search_position_ = result.first - begin;
              }
              else
              {
                // Next search can start with the new data.
                search_position_ = end - begin;
              }

<<<<<<< HEAD
              bytes_to_read = std::min<std::size_t>(
=======
              bytes_to_read_ = std::min<std::size_t>(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                    std::max<std::size_t>(512,
                      buffers_.capacity() - buffers_.size()),
                    std::min<std::size_t>(65536,
                      buffers_.max_size() - buffers_.size()));
            }
          }

          // Check if we're done.
<<<<<<< HEAD
          if (!start && bytes_to_read == 0)
            break;

          // Start a new asynchronous read operation to obtain more data.
          stream_.async_read_some(buffers_.prepare(bytes_to_read),
              BOOST_ASIO_MOVE_CAST(read_until_delim_string_op)(*this));
          return; default:
          buffers_.commit(bytes_transferred);
=======
          if (!start && bytes_to_read_ == 0)
            break;

          // Start a new asynchronous read op_v2eration to obtain more data.
          pos = buffers_.size();
          buffers_.grow(bytes_to_read_);
          stream_.async_read_some(buffers_.data(pos, bytes_to_read_),
              BOOST_ASIO_MOVE_CAST(read_until_delim_string_op_v2)(*this));
          return; default:
          buffers_.shrink(bytes_to_read_ - bytes_transferred);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
          if (ec || bytes_transferred == 0)
            break;
        }

        const boost::system::error_code result_ec =
          (search_position_ == not_found)
          ? error::not_found : ec;

        const std::size_t result_n =
          (ec || search_position_ == not_found)
          ? 0 : search_position_;

        handler_(result_ec, result_n);
      }
    }

  //private:
    AsyncReadStream& stream_;
<<<<<<< HEAD
    DynamicBuffer buffers_;
    std::string delim_;
    int start_;
    std::size_t search_position_;
=======
    DynamicBuffer_v2 buffers_;
    std::string delim_;
    int start_;
    std::size_t search_position_;
    std::size_t bytes_to_read_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    ReadHandler handler_;
  };

  template <typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_delim_string_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_delim_string_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

  template <typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_delim_string_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_delim_string_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

  template <typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_delim_string_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_delim_string_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_delim_string_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_delim_string_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_delim_string_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_delim_string_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }
<<<<<<< HEAD
=======

  template <typename AsyncReadStream>
  class initiate_async_read_until_delim_string_v2
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_until_delim_string_v2(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler, typename DynamicBuffer_v2>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v2) buffers,
        const std::string& delim) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      read_until_delim_string_op_v2<AsyncReadStream,
        typename decay<DynamicBuffer_v2>::type,
          typename decay<ReadHandler>::type>(
            stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
            delim, handler2.value)(boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_delim_string_op<AsyncReadStream,
      DynamicBuffer, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_delim_string_op_v2<AsyncReadStream,
      DynamicBuffer_v2, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_until_delim_string_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>& h,
=======
      const detail::read_until_delim_string_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>& h,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_delim_string_op<AsyncReadStream,
      DynamicBuffer, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_delim_string_op_v2<AsyncReadStream,
      DynamicBuffer_v2, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_until_delim_string_op<AsyncReadStream,
        DynamicBuffer, ReadHandler>& h,
=======
      const detail::read_until_delim_string_op_v2<AsyncReadStream,
        DynamicBuffer_v2, ReadHandler>& h,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<ReadHandler, Executor>::get(h.handler_, ex);
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

template <typename AsyncReadStream,
<<<<<<< HEAD
    typename DynamicBuffer, typename ReadHandler>
BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    BOOST_ASIO_STRING_VIEW_PARAM delim,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a ReadHandler.
  BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

  async_completion<ReadHandler,
    void (boost::system::error_code, std::size_t)> init(handler);

  detail::read_until_delim_string_op<AsyncReadStream,
    typename decay<DynamicBuffer>::type,
      BOOST_ASIO_HANDLER_TYPE(ReadHandler,
        void (boost::system::error_code, std::size_t))>(
          s, BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers),
            static_cast<std::string>(delim),
              init.completion_handler)(boost::system::error_code(), 0, 1);

  return init.result.get();
=======
    typename DynamicBuffer_v2,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    DynamicBuffer_v2 buffers, BOOST_ASIO_STRING_VIEW_PARAM delim,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_until_delim_string_v2<AsyncReadStream>(s),
      handler, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
      static_cast<std::string>(delim));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

#if !defined(BOOST_ASIO_NO_EXTENSIONS)
#if defined(BOOST_ASIO_HAS_BOOST_REGEX)

namespace detail
{
<<<<<<< HEAD
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename RegEx, typename ReadHandler>
  class read_until_expr_op
  {
  public:
    template <typename BufferSequence>
    read_until_expr_op(AsyncReadStream& stream,
=======
  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename RegEx, typename ReadHandler>
  class read_until_expr_op_v2
  {
  public:
    template <typename BufferSequence>
    read_until_expr_op_v2(AsyncReadStream& stream,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        const boost::regex& expr, ReadHandler& handler)
      : stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        expr_(expr),
        start_(0),
        search_position_(0),
<<<<<<< HEAD
=======
        bytes_to_read_(0),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
<<<<<<< HEAD
    read_until_expr_op(const read_until_expr_op& other)
=======
    read_until_expr_op_v2(const read_until_expr_op_v2& other)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      : stream_(other.stream_),
        buffers_(other.buffers_),
        expr_(other.expr_),
        start_(other.start_),
        search_position_(other.search_position_),
<<<<<<< HEAD
=======
        bytes_to_read_(other.bytes_to_read_),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(other.handler_)
    {
    }

<<<<<<< HEAD
    read_until_expr_op(read_until_expr_op&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer)(other.buffers_)),
        expr_(other.expr_),
        start_(other.start_),
        search_position_(other.search_position_),
=======
    read_until_expr_op_v2(read_until_expr_op_v2&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(other.buffers_)),
        expr_(other.expr_),
        start_(other.start_),
        search_position_(other.search_position_),
        bytes_to_read_(other.bytes_to_read_),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      const std::size_t not_found = (std::numeric_limits<std::size_t>::max)();
<<<<<<< HEAD
      std::size_t bytes_to_read;
=======
      std::size_t pos;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      switch (start_ = start)
      {
      case 1:
        for (;;)
        {
          {
            // Determine the range of the data to be searched.
<<<<<<< HEAD
            typedef typename DynamicBuffer::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers = buffers_.data();
=======
            typedef typename DynamicBuffer_v2::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers =
              const_cast<const DynamicBuffer_v2&>(buffers_).data(
                  0, buffers_.size());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            iterator begin = iterator::begin(data_buffers);
            iterator start_pos = begin + search_position_;
            iterator end = iterator::end(data_buffers);

            // Look for a match.
            boost::match_results<iterator,
              typename std::vector<boost::sub_match<iterator> >::allocator_type>
                match_results;
            bool match = regex_search(start_pos, end, match_results, expr_,
                boost::match_default | boost::match_partial);
            if (match && match_results[0].matched)
            {
              // Full match. We're done.
              search_position_ = match_results[0].second - begin;
<<<<<<< HEAD
              bytes_to_read = 0;
=======
              bytes_to_read_ = 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }

            // No match yet. Check if buffer is full.
            else if (buffers_.size() == buffers_.max_size())
            {
              search_position_ = not_found;
<<<<<<< HEAD
              bytes_to_read = 0;
=======
              bytes_to_read_ = 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }

            // Need to read some more data.
            else
            {
              if (match)
              {
                // Partial match. Next search needs to start from beginning of
                // match.
                search_position_ = match_results[0].first - begin;
              }
              else
              {
                // Next search can start with the new data.
                search_position_ = end - begin;
              }

<<<<<<< HEAD
              bytes_to_read = std::min<std::size_t>(
=======
              bytes_to_read_ = std::min<std::size_t>(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                    std::max<std::size_t>(512,
                      buffers_.capacity() - buffers_.size()),
                    std::min<std::size_t>(65536,
                      buffers_.max_size() - buffers_.size()));
            }
          }

          // Check if we're done.
<<<<<<< HEAD
          if (!start && bytes_to_read == 0)
            break;

          // Start a new asynchronous read operation to obtain more data.
          stream_.async_read_some(buffers_.prepare(bytes_to_read),
              BOOST_ASIO_MOVE_CAST(read_until_expr_op)(*this));
          return; default:
          buffers_.commit(bytes_transferred);
=======
          if (!start && bytes_to_read_ == 0)
            break;

          // Start a new asynchronous read op_v2eration to obtain more data.
          pos = buffers_.size();
          buffers_.grow(bytes_to_read_);
          stream_.async_read_some(buffers_.data(pos, bytes_to_read_),
              BOOST_ASIO_MOVE_CAST(read_until_expr_op_v2)(*this));
          return; default:
          buffers_.shrink(bytes_to_read_ - bytes_transferred);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
          if (ec || bytes_transferred == 0)
            break;
        }

        const boost::system::error_code result_ec =
          (search_position_ == not_found)
          ? error::not_found : ec;

        const std::size_t result_n =
          (ec || search_position_ == not_found)
          ? 0 : search_position_;

        handler_(result_ec, result_n);
      }
    }

  //private:
    AsyncReadStream& stream_;
<<<<<<< HEAD
    DynamicBuffer buffers_;
    RegEx expr_;
    int start_;
    std::size_t search_position_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream, typename DynamicBuffer,
      typename RegEx, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_expr_op<AsyncReadStream,
        DynamicBuffer, RegEx, ReadHandler>* this_handler)
=======
    DynamicBuffer_v2 buffers_;
    RegEx expr_;
    int start_;
    std::size_t search_position_;
    std::size_t bytes_to_read_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename RegEx, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_expr_op_v2<AsyncReadStream,
        DynamicBuffer_v2, RegEx, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename RegEx, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_expr_op<AsyncReadStream,
        DynamicBuffer, RegEx, ReadHandler>* this_handler)
=======
  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename RegEx, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_expr_op_v2<AsyncReadStream,
        DynamicBuffer_v2, RegEx, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename RegEx, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_expr_op<AsyncReadStream,
        DynamicBuffer, RegEx, ReadHandler>* this_handler)
=======
  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename RegEx, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_expr_op_v2<AsyncReadStream,
        DynamicBuffer_v2, RegEx, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename RegEx, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_expr_op<AsyncReadStream,
        DynamicBuffer, RegEx, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename RegEx, typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_expr_op_v2<AsyncReadStream,
        DynamicBuffer_v2, RegEx, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename RegEx, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_expr_op<AsyncReadStream,
        DynamicBuffer, RegEx, ReadHandler>* this_handler)
=======
      typename DynamicBuffer_v2, typename RegEx, typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_expr_op_v2<AsyncReadStream,
        DynamicBuffer_v2, RegEx, ReadHandler>* this_handler)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }
<<<<<<< HEAD
=======

  template <typename AsyncReadStream>
  class initiate_async_read_until_expr_v2
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_until_expr_v2(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler, typename DynamicBuffer_v2, typename RegEx>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v2) buffers,
        const RegEx& expr) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      read_until_expr_op_v2<AsyncReadStream,
        typename decay<DynamicBuffer_v2>::type,
          RegEx, typename decay<ReadHandler>::type>(
            stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
            expr, handler2.value)(boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename RegEx, typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_expr_op<AsyncReadStream,
      DynamicBuffer, RegEx, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename RegEx, typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_expr_op_v2<AsyncReadStream,
      DynamicBuffer_v2, RegEx, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_until_expr_op<AsyncReadStream,
        DynamicBuffer, RegEx, ReadHandler>& h,
=======
      const detail::read_until_expr_op_v2<AsyncReadStream,
        DynamicBuffer_v2, RegEx, ReadHandler>& h,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename RegEx, typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_expr_op<AsyncReadStream,
      DynamicBuffer, RegEx, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename RegEx, typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_expr_op_v2<AsyncReadStream,
      DynamicBuffer_v2, RegEx, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_until_expr_op<AsyncReadStream,
        DynamicBuffer, RegEx, ReadHandler>& h,
=======
      const detail::read_until_expr_op_v2<AsyncReadStream,
        DynamicBuffer_v2, RegEx, ReadHandler>& h,
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
BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    const boost::regex& expr,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a ReadHandler.
  BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

  async_completion<ReadHandler,
    void (boost::system::error_code, std::size_t)> init(handler);

  detail::read_until_expr_op<AsyncReadStream,
    typename decay<DynamicBuffer>::type,
      boost::regex, BOOST_ASIO_HANDLER_TYPE(ReadHandler,
        void (boost::system::error_code, std::size_t))>(
          s, BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers),
            expr, init.completion_handler)(boost::system::error_code(), 0, 1);

  return init.result.get();
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s, DynamicBuffer_v2 buffers,
    const boost::regex& expr, BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_until_expr_v2<AsyncReadStream>(s),
      handler, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers), expr);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

#endif // defined(BOOST_ASIO_HAS_BOOST_REGEX)

namespace detail
{
<<<<<<< HEAD
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename MatchCondition, typename ReadHandler>
  class read_until_match_op
  {
  public:
    template <typename BufferSequence>
    read_until_match_op(AsyncReadStream& stream,
=======
  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename MatchCondition, typename ReadHandler>
  class read_until_match_op_v2
  {
  public:
    template <typename BufferSequence>
    read_until_match_op_v2(AsyncReadStream& stream,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        BOOST_ASIO_MOVE_ARG(BufferSequence) buffers,
        MatchCondition match_condition, ReadHandler& handler)
      : stream_(stream),
        buffers_(BOOST_ASIO_MOVE_CAST(BufferSequence)(buffers)),
        match_condition_(match_condition),
        start_(0),
        search_position_(0),
<<<<<<< HEAD
=======
        bytes_to_read_(0),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(handler))
    {
    }

#if defined(BOOST_ASIO_HAS_MOVE)
<<<<<<< HEAD
    read_until_match_op(const read_until_match_op& other)
=======
    read_until_match_op_v2(const read_until_match_op_v2& other)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      : stream_(other.stream_),
        buffers_(other.buffers_),
        match_condition_(other.match_condition_),
        start_(other.start_),
        search_position_(other.search_position_),
<<<<<<< HEAD
=======
        bytes_to_read_(other.bytes_to_read_),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(other.handler_)
    {
    }

<<<<<<< HEAD
    read_until_match_op(read_until_match_op&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer)(other.buffers_)),
        match_condition_(other.match_condition_),
        start_(other.start_),
        search_position_(other.search_position_),
=======
    read_until_match_op_v2(read_until_match_op_v2&& other)
      : stream_(other.stream_),
        buffers_(BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(other.buffers_)),
        match_condition_(other.match_condition_),
        start_(other.start_),
        search_position_(other.search_position_),
        bytes_to_read_(other.bytes_to_read_),
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        handler_(BOOST_ASIO_MOVE_CAST(ReadHandler)(other.handler_))
    {
    }
#endif // defined(BOOST_ASIO_HAS_MOVE)

    void operator()(const boost::system::error_code& ec,
        std::size_t bytes_transferred, int start = 0)
    {
      const std::size_t not_found = (std::numeric_limits<std::size_t>::max)();
<<<<<<< HEAD
      std::size_t bytes_to_read;
=======
      std::size_t pos;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      switch (start_ = start)
      {
      case 1:
        for (;;)
        {
          {
            // Determine the range of the data to be searched.
<<<<<<< HEAD
            typedef typename DynamicBuffer::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers = buffers_.data();
=======
            typedef typename DynamicBuffer_v2::const_buffers_type
              buffers_type;
            typedef buffers_iterator<buffers_type> iterator;
            buffers_type data_buffers =
              const_cast<const DynamicBuffer_v2&>(buffers_).data(
                  0, buffers_.size());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            iterator begin = iterator::begin(data_buffers);
            iterator start_pos = begin + search_position_;
            iterator end = iterator::end(data_buffers);

            // Look for a match.
            std::pair<iterator, bool> result = match_condition_(start_pos, end);
            if (result.second)
            {
              // Full match. We're done.
              search_position_ = result.first - begin;
<<<<<<< HEAD
              bytes_to_read = 0;
=======
              bytes_to_read_ = 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }

            // No match yet. Check if buffer is full.
            else if (buffers_.size() == buffers_.max_size())
            {
              search_position_ = not_found;
<<<<<<< HEAD
              bytes_to_read = 0;
=======
              bytes_to_read_ = 0;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            }

            // Need to read some more data.
            else
            {
              if (result.first != end)
              {
                // Partial match. Next search needs to start from beginning of
                // match.
                search_position_ = result.first - begin;
              }
              else
              {
                // Next search can start with the new data.
                search_position_ = end - begin;
              }

<<<<<<< HEAD
              bytes_to_read = std::min<std::size_t>(
=======
              bytes_to_read_ = std::min<std::size_t>(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                    std::max<std::size_t>(512,
                      buffers_.capacity() - buffers_.size()),
                    std::min<std::size_t>(65536,
                      buffers_.max_size() - buffers_.size()));
            }
          }

          // Check if we're done.
<<<<<<< HEAD
          if (!start && bytes_to_read == 0)
            break;

          // Start a new asynchronous read operation to obtain more data.
          stream_.async_read_some(buffers_.prepare(bytes_to_read),
              BOOST_ASIO_MOVE_CAST(read_until_match_op)(*this));
          return; default:
          buffers_.commit(bytes_transferred);
=======
          if (!start && bytes_to_read_ == 0)
            break;

          // Start a new asynchronous read op_v2eration to obtain more data.
          pos = buffers_.size();
          buffers_.grow(bytes_to_read_);
          stream_.async_read_some(buffers_.data(pos, bytes_to_read_),
              BOOST_ASIO_MOVE_CAST(read_until_match_op_v2)(*this));
          return; default:
          buffers_.shrink(bytes_to_read_ - bytes_transferred);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
          if (ec || bytes_transferred == 0)
            break;
        }

        const boost::system::error_code result_ec =
          (search_position_ == not_found)
          ? error::not_found : ec;

        const std::size_t result_n =
          (ec || search_position_ == not_found)
          ? 0 : search_position_;

        handler_(result_ec, result_n);
      }
    }

  //private:
    AsyncReadStream& stream_;
<<<<<<< HEAD
    DynamicBuffer buffers_;
    MatchCondition match_condition_;
    int start_;
    std::size_t search_position_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream, typename DynamicBuffer,
      typename MatchCondition, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_match_op<AsyncReadStream, DynamicBuffer,
=======
    DynamicBuffer_v2 buffers_;
    MatchCondition match_condition_;
    int start_;
    std::size_t search_position_;
    std::size_t bytes_to_read_;
    ReadHandler handler_;
  };

  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename MatchCondition, typename ReadHandler>
  inline void* asio_handler_allocate(std::size_t size,
      read_until_match_op_v2<AsyncReadStream, DynamicBuffer_v2,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        MatchCondition, ReadHandler>* this_handler)
  {
    return boost_asio_handler_alloc_helpers::allocate(
        size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename MatchCondition, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_match_op<AsyncReadStream, DynamicBuffer,
=======
  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename MatchCondition, typename ReadHandler>
  inline void asio_handler_deallocate(void* pointer, std::size_t size,
      read_until_match_op_v2<AsyncReadStream, DynamicBuffer_v2,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        MatchCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_alloc_helpers::deallocate(
        pointer, size, this_handler->handler_);
  }

<<<<<<< HEAD
  template <typename AsyncReadStream, typename DynamicBuffer,
      typename MatchCondition, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_match_op<AsyncReadStream, DynamicBuffer,
=======
  template <typename AsyncReadStream, typename DynamicBuffer_v2,
      typename MatchCondition, typename ReadHandler>
  inline bool asio_handler_is_continuation(
      read_until_match_op_v2<AsyncReadStream, DynamicBuffer_v2,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        MatchCondition, ReadHandler>* this_handler)
  {
    return this_handler->start_ == 0 ? true
      : boost_asio_handler_cont_helpers::is_continuation(
          this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename MatchCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_match_op<AsyncReadStream, DynamicBuffer,
=======
      typename DynamicBuffer_v2, typename MatchCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(Function& function,
      read_until_match_op_v2<AsyncReadStream, DynamicBuffer_v2,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        MatchCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }

  template <typename Function, typename AsyncReadStream,
<<<<<<< HEAD
      typename DynamicBuffer, typename MatchCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_match_op<AsyncReadStream, DynamicBuffer,
=======
      typename DynamicBuffer_v2, typename MatchCondition,
      typename ReadHandler>
  inline void asio_handler_invoke(const Function& function,
      read_until_match_op_v2<AsyncReadStream, DynamicBuffer_v2,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      MatchCondition, ReadHandler>* this_handler)
  {
    boost_asio_handler_invoke_helpers::invoke(
        function, this_handler->handler_);
  }
<<<<<<< HEAD
=======

  template <typename AsyncReadStream>
  class initiate_async_read_until_match_v2
  {
  public:
    typedef typename AsyncReadStream::executor_type executor_type;

    explicit initiate_async_read_until_match_v2(AsyncReadStream& stream)
      : stream_(stream)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return stream_.get_executor();
    }

    template <typename ReadHandler,
        typename DynamicBuffer_v2, typename MatchCondition>
    void operator()(BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
        BOOST_ASIO_MOVE_ARG(DynamicBuffer_v2) buffers,
        MatchCondition match_condition) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

      non_const_lvalue<ReadHandler> handler2(handler);
      read_until_match_op_v2<AsyncReadStream,
        typename decay<DynamicBuffer_v2>::type,
          MatchCondition, typename decay<ReadHandler>::type>(
            stream_, BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers),
            match_condition, handler2.value)(boost::system::error_code(), 0, 1);
    }

  private:
    AsyncReadStream& stream_;
  };
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
} // namespace detail

#if !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename MatchCondition, typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_match_op<AsyncReadStream,
      DynamicBuffer, MatchCondition, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename MatchCondition, typename ReadHandler, typename Allocator>
struct associated_allocator<
    detail::read_until_match_op_v2<AsyncReadStream,
      DynamicBuffer_v2, MatchCondition, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Allocator>
{
  typedef typename associated_allocator<ReadHandler, Allocator>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_until_match_op<AsyncReadStream,
        DynamicBuffer, MatchCondition, ReadHandler>& h,
=======
      const detail::read_until_match_op_v2<AsyncReadStream,
        DynamicBuffer_v2, MatchCondition, ReadHandler>& h,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      const Allocator& a = Allocator()) BOOST_ASIO_NOEXCEPT
  {
    return associated_allocator<ReadHandler, Allocator>::get(h.handler_, a);
  }
};

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename MatchCondition, typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_match_op<AsyncReadStream,
      DynamicBuffer, MatchCondition, ReadHandler>,
=======
template <typename AsyncReadStream, typename DynamicBuffer_v2,
    typename MatchCondition, typename ReadHandler, typename Executor>
struct associated_executor<
    detail::read_until_match_op_v2<AsyncReadStream,
      DynamicBuffer_v2, MatchCondition, ReadHandler>,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    Executor>
{
  typedef typename associated_executor<ReadHandler, Executor>::type type;

  static type get(
<<<<<<< HEAD
      const detail::read_until_match_op<AsyncReadStream,
        DynamicBuffer, MatchCondition, ReadHandler>& h,
=======
      const detail::read_until_match_op_v2<AsyncReadStream,
        DynamicBuffer_v2, MatchCondition, ReadHandler>& h,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
      const Executor& ex = Executor()) BOOST_ASIO_NOEXCEPT
  {
    return associated_executor<ReadHandler, Executor>::get(h.handler_, ex);
  }
};

#endif // !defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
template <typename AsyncReadStream, typename DynamicBuffer,
    typename MatchCondition, typename ReadHandler>
BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    BOOST_ASIO_MOVE_ARG(DynamicBuffer) buffers,
    MatchCondition match_condition, BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<is_match_condition<MatchCondition>::value>::type*)
{
  // If you get an error on the following line it means that your handler does
  // not meet the documented type requirements for a ReadHandler.
  BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

  async_completion<ReadHandler,
    void (boost::system::error_code, std::size_t)> init(handler);

  detail::read_until_match_op<AsyncReadStream,
    typename decay<DynamicBuffer>::type,
      MatchCondition, BOOST_ASIO_HANDLER_TYPE(ReadHandler,
        void (boost::system::error_code, std::size_t))>(
          s, BOOST_ASIO_MOVE_CAST(DynamicBuffer)(buffers),
            match_condition, init.completion_handler)(
              boost::system::error_code(), 0, 1);

  return init.result.get();
}

#if !defined(BOOST_ASIO_NO_IOSTREAM)

template <typename AsyncReadStream, typename Allocator, typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    char delim, BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  return async_read_until(s, basic_streambuf_ref<Allocator>(b),
      delim, BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
}

template <typename AsyncReadStream, typename Allocator, typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    BOOST_ASIO_STRING_VIEW_PARAM delim,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  return async_read_until(s, basic_streambuf_ref<Allocator>(b),
      delim, BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
}

#if defined(BOOST_ASIO_HAS_BOOST_REGEX)

template <typename AsyncReadStream, typename Allocator, typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b, const boost::regex& expr,
    BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
{
  return async_read_until(s, basic_streambuf_ref<Allocator>(b),
      expr, BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
}

#endif // defined(BOOST_ASIO_HAS_BOOST_REGEX)

template <typename AsyncReadStream, typename Allocator,
    typename MatchCondition, typename ReadHandler>
inline BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s,
    boost::asio::basic_streambuf<Allocator>& b,
    MatchCondition match_condition, BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<is_match_condition<MatchCondition>::value>::type*)
{
  return async_read_until(s, basic_streambuf_ref<Allocator>(b),
      match_condition, BOOST_ASIO_MOVE_CAST(ReadHandler)(handler));
}

#endif // !defined(BOOST_ASIO_NO_IOSTREAM)
=======
template <typename AsyncReadStream,
    typename DynamicBuffer_v2, typename MatchCondition,
    BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code,
      std::size_t)) ReadHandler>
BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ReadHandler,
    void (boost::system::error_code, std::size_t))
async_read_until(AsyncReadStream& s, DynamicBuffer_v2 buffers,
    MatchCondition match_condition, BOOST_ASIO_MOVE_ARG(ReadHandler) handler,
    typename enable_if<
      is_match_condition<MatchCondition>::value
        && is_dynamic_buffer_v2<DynamicBuffer_v2>::value
    >::type*)
{
  return async_initiate<ReadHandler,
    void (boost::system::error_code, std::size_t)>(
      detail::initiate_async_read_until_match_v2<AsyncReadStream>(s), handler,
      BOOST_ASIO_MOVE_CAST(DynamicBuffer_v2)(buffers), match_condition);
}

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif // !defined(BOOST_ASIO_NO_EXTENSIONS)

} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_IMPL_READ_UNTIL_HPP
