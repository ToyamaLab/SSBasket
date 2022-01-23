//
// basic_deadline_timer.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~
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

#ifndef BOOST_ASIO_BASIC_DEADLINE_TIMER_HPP
#define BOOST_ASIO_BASIC_DEADLINE_TIMER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HAS_BOOST_DATE_TIME) \
  || defined(GENERATING_DOCUMENTATION)

#include <cstddef>
<<<<<<< HEAD
#include <boost/asio/basic_io_object.hpp>
#include <boost/asio/detail/handler_type_requirements.hpp>
#include <boost/asio/detail/throw_error.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/time_traits.hpp>

#if defined(BOOST_ASIO_ENABLE_OLD_SERVICES)
# include <boost/asio/deadline_timer_service.hpp>
#else // defined(BOOST_ASIO_ENABLE_OLD_SERVICES)
# include <boost/asio/detail/deadline_timer_service.hpp>
# define BOOST_ASIO_SVC_T detail::deadline_timer_service<TimeTraits>
#endif // defined(BOOST_ASIO_ENABLE_OLD_SERVICES)

=======
#include <boost/asio/detail/deadline_timer_service.hpp>
#include <boost/asio/detail/handler_type_requirements.hpp>
#include <boost/asio/detail/io_object_impl.hpp>
#include <boost/asio/detail/non_const_lvalue.hpp>
#include <boost/asio/detail/throw_error.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/execution_context.hpp>
#include <boost/asio/executor.hpp>
#include <boost/asio/time_traits.hpp>

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {

/// Provides waitable timer functionality.
/**
 * The basic_deadline_timer class template provides the ability to perform a
 * blocking or asynchronous wait for a timer to expire.
 *
 * A deadline timer is always in one of two states: "expired" or "not expired".
 * If the wait() or async_wait() function is called on an expired timer, the
 * wait operation will complete immediately.
 *
 * Most applications will use the boost::asio::deadline_timer typedef.
 *
 * @par Thread Safety
 * @e Distinct @e objects: Safe.@n
 * @e Shared @e objects: Unsafe.
 *
 * @par Examples
 * Performing a blocking wait:
 * @code
 * // Construct a timer without setting an expiry time.
<<<<<<< HEAD
 * boost::asio::deadline_timer timer(io_context);
=======
 * boost::asio::deadline_timer timer(my_context);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
 *
 * // Set an expiry time relative to now.
 * timer.expires_from_now(boost::posix_time::seconds(5));
 *
 * // Wait for the timer to expire.
 * timer.wait();
 * @endcode
 *
 * @par 
 * Performing an asynchronous wait:
 * @code
 * void handler(const boost::system::error_code& error)
 * {
 *   if (!error)
 *   {
 *     // Timer expired.
 *   }
 * }
 *
 * ...
 *
 * // Construct a timer with an absolute expiry time.
<<<<<<< HEAD
 * boost::asio::deadline_timer timer(io_context,
=======
 * boost::asio::deadline_timer timer(my_context,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
 *     boost::posix_time::time_from_string("2005-12-07 23:59:59.000"));
 *
 * // Start an asynchronous wait.
 * timer.async_wait(handler);
 * @endcode
 *
 * @par Changing an active deadline_timer's expiry time
 *
 * Changing the expiry time of a timer while there are pending asynchronous
 * waits causes those wait operations to be cancelled. To ensure that the action
 * associated with the timer is performed only once, use something like this:
 * used:
 *
 * @code
 * void on_some_event()
 * {
 *   if (my_timer.expires_from_now(seconds(5)) > 0)
 *   {
 *     // We managed to cancel the timer. Start new asynchronous wait.
 *     my_timer.async_wait(on_timeout);
 *   }
 *   else
 *   {
 *     // Too late, timer has already expired!
 *   }
 * }
 *
 * void on_timeout(const boost::system::error_code& e)
 * {
 *   if (e != boost::asio::error::operation_aborted)
 *   {
 *     // Timer was not cancelled, take necessary action.
 *   }
 * }
 * @endcode
 *
 * @li The boost::asio::basic_deadline_timer::expires_from_now() function
 * cancels any pending asynchronous waits, and returns the number of
 * asynchronous waits that were cancelled. If it returns 0 then you were too
 * late and the wait handler has already been executed, or will soon be
 * executed. If it returns 1 then the wait handler was successfully cancelled.
 *
 * @li If a wait handler is cancelled, the boost::system::error_code passed to
 * it contains the value boost::asio::error::operation_aborted.
 */
template <typename Time,
<<<<<<< HEAD
    typename TimeTraits = boost::asio::time_traits<Time>
    BOOST_ASIO_SVC_TPARAM_DEF2(= deadline_timer_service<Time, TimeTraits>)>
class basic_deadline_timer
  : BOOST_ASIO_SVC_ACCESS basic_io_object<BOOST_ASIO_SVC_T>
{
public:
  /// The type of the executor associated with the object.
  typedef io_context::executor_type executor_type;
=======
    typename TimeTraits = boost::asio::time_traits<Time>,
    typename Executor = executor>
class basic_deadline_timer
{
public:
  /// The type of the executor associated with the object.
  typedef Executor executor_type;

  /// Rebinds the timer type to another executor.
  template <typename Executor1>
  struct rebind_executor
  {
    /// The timer type when rebound to the specified executor.
    typedef basic_deadline_timer<Time, TimeTraits, Executor1> other;
  };
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

  /// The time traits type.
  typedef TimeTraits traits_type;

  /// The time type.
  typedef typename traits_type::time_type time_type;

  /// The duration type.
  typedef typename traits_type::duration_type duration_type;

  /// Constructor.
  /**
   * This constructor creates a timer without setting an expiry time. The
   * expires_at() or expires_from_now() functions must be called to set an
   * expiry time before the timer can be waited on.
   *
<<<<<<< HEAD
   * @param io_context The io_context object that the timer will use to dispatch
   * handlers for any asynchronous operations performed on the timer.
   */
  explicit basic_deadline_timer(boost::asio::io_context& io_context)
    : basic_io_object<BOOST_ASIO_SVC_T>(io_context)
  {
=======
   * @param ex The I/O executor that the timer will use, by default, to
   * dispatch handlers for any asynchronous operations performed on the timer.
   */
  explicit basic_deadline_timer(const executor_type& ex)
    : impl_(ex)
  {
  }

  /// Constructor.
  /**
   * This constructor creates a timer without setting an expiry time. The
   * expires_at() or expires_from_now() functions must be called to set an
   * expiry time before the timer can be waited on.
   *
   * @param context An execution context which provides the I/O executor that
   * the timer will use, by default, to dispatch handlers for any asynchronous
   * operations performed on the timer.
   */
  template <typename ExecutionContext>
  explicit basic_deadline_timer(ExecutionContext& context,
      typename enable_if<
        is_convertible<ExecutionContext&, execution_context&>::value
      >::type* = 0)
    : impl_(context)
  {
  }

  /// Constructor to set a particular expiry time as an absolute time.
  /**
   * This constructor creates a timer and sets the expiry time.
   *
   * @param ex The I/O executor that the timer will use, by default, to
   * dispatch handlers for any asynchronous operations performed on the timer.
   *
   * @param expiry_time The expiry time to be used for the timer, expressed
   * as an absolute time.
   */
  basic_deadline_timer(const executor_type& ex, const time_type& expiry_time)
    : impl_(ex)
  {
    boost::system::error_code ec;
    impl_.get_service().expires_at(impl_.get_implementation(), expiry_time, ec);
    boost::asio::detail::throw_error(ec, "expires_at");
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  /// Constructor to set a particular expiry time as an absolute time.
  /**
   * This constructor creates a timer and sets the expiry time.
   *
<<<<<<< HEAD
   * @param io_context The io_context object that the timer will use to dispatch
   * handlers for any asynchronous operations performed on the timer.
=======
   * @param context An execution context which provides the I/O executor that
   * the timer will use, by default, to dispatch handlers for any asynchronous
   * operations performed on the timer.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   *
   * @param expiry_time The expiry time to be used for the timer, expressed
   * as an absolute time.
   */
<<<<<<< HEAD
  basic_deadline_timer(boost::asio::io_context& io_context,
      const time_type& expiry_time)
    : basic_io_object<BOOST_ASIO_SVC_T>(io_context)
  {
    boost::system::error_code ec;
    this->get_service().expires_at(this->get_implementation(), expiry_time, ec);
=======
  template <typename ExecutionContext>
  basic_deadline_timer(ExecutionContext& context, const time_type& expiry_time,
      typename enable_if<
        is_convertible<ExecutionContext&, execution_context&>::value
      >::type* = 0)
    : impl_(context)
  {
    boost::system::error_code ec;
    impl_.get_service().expires_at(impl_.get_implementation(), expiry_time, ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::asio::detail::throw_error(ec, "expires_at");
  }

  /// Constructor to set a particular expiry time relative to now.
  /**
   * This constructor creates a timer and sets the expiry time.
   *
<<<<<<< HEAD
   * @param io_context The io_context object that the timer will use to dispatch
   * handlers for any asynchronous operations performed on the timer.
=======
   * @param ex The I/O executor that the timer will use, by default, to
   * dispatch handlers for any asynchronous operations performed on the timer.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   *
   * @param expiry_time The expiry time to be used for the timer, relative to
   * now.
   */
<<<<<<< HEAD
  basic_deadline_timer(boost::asio::io_context& io_context,
      const duration_type& expiry_time)
    : basic_io_object<BOOST_ASIO_SVC_T>(io_context)
  {
    boost::system::error_code ec;
    this->get_service().expires_from_now(
        this->get_implementation(), expiry_time, ec);
=======
  basic_deadline_timer(const executor_type& ex,
      const duration_type& expiry_time)
    : impl_(ex)
  {
    boost::system::error_code ec;
    impl_.get_service().expires_from_now(
        impl_.get_implementation(), expiry_time, ec);
    boost::asio::detail::throw_error(ec, "expires_from_now");
  }

  /// Constructor to set a particular expiry time relative to now.
  /**
   * This constructor creates a timer and sets the expiry time.
   *
   * @param context An execution context which provides the I/O executor that
   * the timer will use, by default, to dispatch handlers for any asynchronous
   * operations performed on the timer.
   *
   * @param expiry_time The expiry time to be used for the timer, relative to
   * now.
   */
  template <typename ExecutionContext>
  basic_deadline_timer(ExecutionContext& context,
      const duration_type& expiry_time,
      typename enable_if<
        is_convertible<ExecutionContext&, execution_context&>::value
      >::type* = 0)
    : impl_(context)
  {
    boost::system::error_code ec;
    impl_.get_service().expires_from_now(
        impl_.get_implementation(), expiry_time, ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::asio::detail::throw_error(ec, "expires_from_now");
  }

#if defined(BOOST_ASIO_HAS_MOVE) || defined(GENERATING_DOCUMENTATION)
  /// Move-construct a basic_deadline_timer from another.
  /**
   * This constructor moves a timer from one object to another.
   *
   * @param other The other basic_deadline_timer object from which the move will
   * occur.
   *
   * @note Following the move, the moved-from object is in the same state as if
<<<<<<< HEAD
   * constructed using the @c basic_deadline_timer(io_context&) constructor.
   */
  basic_deadline_timer(basic_deadline_timer&& other)
    : basic_io_object<BOOST_ASIO_SVC_T>(std::move(other))
=======
   * constructed using the @c basic_deadline_timer(const executor_type&)
   * constructor.
   */
  basic_deadline_timer(basic_deadline_timer&& other)
    : impl_(std::move(other.impl_))
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  {
  }

  /// Move-assign a basic_deadline_timer from another.
  /**
   * This assignment operator moves a timer from one object to another. Cancels
   * any outstanding asynchronous operations associated with the target object.
   *
   * @param other The other basic_deadline_timer object from which the move will
   * occur.
   *
   * @note Following the move, the moved-from object is in the same state as if
<<<<<<< HEAD
   * constructed using the @c basic_deadline_timer(io_context&) constructor.
   */
  basic_deadline_timer& operator=(basic_deadline_timer&& other)
  {
    basic_io_object<BOOST_ASIO_SVC_T>::operator=(std::move(other));
=======
   * constructed using the @c basic_deadline_timer(const executor_type&)
   * constructor.
   */
  basic_deadline_timer& operator=(basic_deadline_timer&& other)
  {
    impl_ = std::move(other.impl_);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    return *this;
  }
#endif // defined(BOOST_ASIO_HAS_MOVE) || defined(GENERATING_DOCUMENTATION)

  /// Destroys the timer.
  /**
   * This function destroys the timer, cancelling any outstanding asynchronous
   * wait operations associated with the timer as if by calling @c cancel.
   */
  ~basic_deadline_timer()
  {
  }

<<<<<<< HEAD
#if defined(BOOST_ASIO_ENABLE_OLD_SERVICES)
  // These functions are provided by basic_io_object<>.
#else // defined(BOOST_ASIO_ENABLE_OLD_SERVICES)
#if !defined(BOOST_ASIO_NO_DEPRECATED)
  /// (Deprecated: Use get_executor().) Get the io_context associated with the
  /// object.
  /**
   * This function may be used to obtain the io_context object that the I/O
   * object uses to dispatch handlers for asynchronous operations.
   *
   * @return A reference to the io_context object that the I/O object will use
   * to dispatch handlers. Ownership is not transferred to the caller.
   */
  boost::asio::io_context& get_io_context()
  {
    return basic_io_object<BOOST_ASIO_SVC_T>::get_io_context();
  }

  /// (Deprecated: Use get_executor().) Get the io_context associated with the
  /// object.
  /**
   * This function may be used to obtain the io_context object that the I/O
   * object uses to dispatch handlers for asynchronous operations.
   *
   * @return A reference to the io_context object that the I/O object will use
   * to dispatch handlers. Ownership is not transferred to the caller.
   */
  boost::asio::io_context& get_io_service()
  {
    return basic_io_object<BOOST_ASIO_SVC_T>::get_io_service();
  }
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

  /// Get the executor associated with the object.
  executor_type get_executor() BOOST_ASIO_NOEXCEPT
  {
    return basic_io_object<BOOST_ASIO_SVC_T>::get_executor();
  }
#endif // defined(BOOST_ASIO_ENABLE_OLD_SERVICES)
=======
  /// Get the executor associated with the object.
  executor_type get_executor() BOOST_ASIO_NOEXCEPT
  {
    return impl_.get_executor();
  }
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

  /// Cancel any asynchronous operations that are waiting on the timer.
  /**
   * This function forces the completion of any pending asynchronous wait
   * operations against the timer. The handler for each cancelled operation will
   * be invoked with the boost::asio::error::operation_aborted error code.
   *
   * Cancelling the timer does not change the expiry time.
   *
   * @return The number of asynchronous operations that were cancelled.
   *
   * @throws boost::system::system_error Thrown on failure.
   *
   * @note If the timer has already expired when cancel() is called, then the
   * handlers for asynchronous wait operations will:
   *
   * @li have already been invoked; or
   *
   * @li have been queued for invocation in the near future.
   *
   * These handlers can no longer be cancelled, and therefore are passed an
   * error code that indicates the successful completion of the wait operation.
   */
  std::size_t cancel()
  {
    boost::system::error_code ec;
<<<<<<< HEAD
    std::size_t s = this->get_service().cancel(this->get_implementation(), ec);
=======
    std::size_t s = impl_.get_service().cancel(impl_.get_implementation(), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::asio::detail::throw_error(ec, "cancel");
    return s;
  }

  /// Cancel any asynchronous operations that are waiting on the timer.
  /**
   * This function forces the completion of any pending asynchronous wait
   * operations against the timer. The handler for each cancelled operation will
   * be invoked with the boost::asio::error::operation_aborted error code.
   *
   * Cancelling the timer does not change the expiry time.
   *
   * @param ec Set to indicate what error occurred, if any.
   *
   * @return The number of asynchronous operations that were cancelled.
   *
   * @note If the timer has already expired when cancel() is called, then the
   * handlers for asynchronous wait operations will:
   *
   * @li have already been invoked; or
   *
   * @li have been queued for invocation in the near future.
   *
   * These handlers can no longer be cancelled, and therefore are passed an
   * error code that indicates the successful completion of the wait operation.
   */
  std::size_t cancel(boost::system::error_code& ec)
  {
<<<<<<< HEAD
    return this->get_service().cancel(this->get_implementation(), ec);
=======
    return impl_.get_service().cancel(impl_.get_implementation(), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  /// Cancels one asynchronous operation that is waiting on the timer.
  /**
   * This function forces the completion of one pending asynchronous wait
   * operation against the timer. Handlers are cancelled in FIFO order. The
   * handler for the cancelled operation will be invoked with the
   * boost::asio::error::operation_aborted error code.
   *
   * Cancelling the timer does not change the expiry time.
   *
   * @return The number of asynchronous operations that were cancelled. That is,
   * either 0 or 1.
   *
   * @throws boost::system::system_error Thrown on failure.
   *
   * @note If the timer has already expired when cancel_one() is called, then
   * the handlers for asynchronous wait operations will:
   *
   * @li have already been invoked; or
   *
   * @li have been queued for invocation in the near future.
   *
   * These handlers can no longer be cancelled, and therefore are passed an
   * error code that indicates the successful completion of the wait operation.
   */
  std::size_t cancel_one()
  {
    boost::system::error_code ec;
<<<<<<< HEAD
    std::size_t s = this->get_service().cancel_one(
        this->get_implementation(), ec);
=======
    std::size_t s = impl_.get_service().cancel_one(
        impl_.get_implementation(), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::asio::detail::throw_error(ec, "cancel_one");
    return s;
  }

  /// Cancels one asynchronous operation that is waiting on the timer.
  /**
   * This function forces the completion of one pending asynchronous wait
   * operation against the timer. Handlers are cancelled in FIFO order. The
   * handler for the cancelled operation will be invoked with the
   * boost::asio::error::operation_aborted error code.
   *
   * Cancelling the timer does not change the expiry time.
   *
   * @param ec Set to indicate what error occurred, if any.
   *
   * @return The number of asynchronous operations that were cancelled. That is,
   * either 0 or 1.
   *
   * @note If the timer has already expired when cancel_one() is called, then
   * the handlers for asynchronous wait operations will:
   *
   * @li have already been invoked; or
   *
   * @li have been queued for invocation in the near future.
   *
   * These handlers can no longer be cancelled, and therefore are passed an
   * error code that indicates the successful completion of the wait operation.
   */
  std::size_t cancel_one(boost::system::error_code& ec)
  {
<<<<<<< HEAD
    return this->get_service().cancel_one(this->get_implementation(), ec);
=======
    return impl_.get_service().cancel_one(impl_.get_implementation(), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  /// Get the timer's expiry time as an absolute time.
  /**
   * This function may be used to obtain the timer's current expiry time.
   * Whether the timer has expired or not does not affect this value.
   */
  time_type expires_at() const
  {
<<<<<<< HEAD
    return this->get_service().expires_at(this->get_implementation());
=======
    return impl_.get_service().expires_at(impl_.get_implementation());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  /// Set the timer's expiry time as an absolute time.
  /**
   * This function sets the expiry time. Any pending asynchronous wait
   * operations will be cancelled. The handler for each cancelled operation will
   * be invoked with the boost::asio::error::operation_aborted error code.
   *
   * @param expiry_time The expiry time to be used for the timer.
   *
   * @return The number of asynchronous operations that were cancelled.
   *
   * @throws boost::system::system_error Thrown on failure.
   *
   * @note If the timer has already expired when expires_at() is called, then
   * the handlers for asynchronous wait operations will:
   *
   * @li have already been invoked; or
   *
   * @li have been queued for invocation in the near future.
   *
   * These handlers can no longer be cancelled, and therefore are passed an
   * error code that indicates the successful completion of the wait operation.
   */
  std::size_t expires_at(const time_type& expiry_time)
  {
    boost::system::error_code ec;
<<<<<<< HEAD
    std::size_t s = this->get_service().expires_at(
        this->get_implementation(), expiry_time, ec);
=======
    std::size_t s = impl_.get_service().expires_at(
        impl_.get_implementation(), expiry_time, ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::asio::detail::throw_error(ec, "expires_at");
    return s;
  }

  /// Set the timer's expiry time as an absolute time.
  /**
   * This function sets the expiry time. Any pending asynchronous wait
   * operations will be cancelled. The handler for each cancelled operation will
   * be invoked with the boost::asio::error::operation_aborted error code.
   *
   * @param expiry_time The expiry time to be used for the timer.
   *
   * @param ec Set to indicate what error occurred, if any.
   *
   * @return The number of asynchronous operations that were cancelled.
   *
   * @note If the timer has already expired when expires_at() is called, then
   * the handlers for asynchronous wait operations will:
   *
   * @li have already been invoked; or
   *
   * @li have been queued for invocation in the near future.
   *
   * These handlers can no longer be cancelled, and therefore are passed an
   * error code that indicates the successful completion of the wait operation.
   */
  std::size_t expires_at(const time_type& expiry_time,
      boost::system::error_code& ec)
  {
<<<<<<< HEAD
    return this->get_service().expires_at(
        this->get_implementation(), expiry_time, ec);
=======
    return impl_.get_service().expires_at(
        impl_.get_implementation(), expiry_time, ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  /// Get the timer's expiry time relative to now.
  /**
   * This function may be used to obtain the timer's current expiry time.
   * Whether the timer has expired or not does not affect this value.
   */
  duration_type expires_from_now() const
  {
<<<<<<< HEAD
    return this->get_service().expires_from_now(this->get_implementation());
=======
    return impl_.get_service().expires_from_now(impl_.get_implementation());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  /// Set the timer's expiry time relative to now.
  /**
   * This function sets the expiry time. Any pending asynchronous wait
   * operations will be cancelled. The handler for each cancelled operation will
   * be invoked with the boost::asio::error::operation_aborted error code.
   *
   * @param expiry_time The expiry time to be used for the timer.
   *
   * @return The number of asynchronous operations that were cancelled.
   *
   * @throws boost::system::system_error Thrown on failure.
   *
   * @note If the timer has already expired when expires_from_now() is called,
   * then the handlers for asynchronous wait operations will:
   *
   * @li have already been invoked; or
   *
   * @li have been queued for invocation in the near future.
   *
   * These handlers can no longer be cancelled, and therefore are passed an
   * error code that indicates the successful completion of the wait operation.
   */
  std::size_t expires_from_now(const duration_type& expiry_time)
  {
    boost::system::error_code ec;
<<<<<<< HEAD
    std::size_t s = this->get_service().expires_from_now(
        this->get_implementation(), expiry_time, ec);
=======
    std::size_t s = impl_.get_service().expires_from_now(
        impl_.get_implementation(), expiry_time, ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::asio::detail::throw_error(ec, "expires_from_now");
    return s;
  }

  /// Set the timer's expiry time relative to now.
  /**
   * This function sets the expiry time. Any pending asynchronous wait
   * operations will be cancelled. The handler for each cancelled operation will
   * be invoked with the boost::asio::error::operation_aborted error code.
   *
   * @param expiry_time The expiry time to be used for the timer.
   *
   * @param ec Set to indicate what error occurred, if any.
   *
   * @return The number of asynchronous operations that were cancelled.
   *
   * @note If the timer has already expired when expires_from_now() is called,
   * then the handlers for asynchronous wait operations will:
   *
   * @li have already been invoked; or
   *
   * @li have been queued for invocation in the near future.
   *
   * These handlers can no longer be cancelled, and therefore are passed an
   * error code that indicates the successful completion of the wait operation.
   */
  std::size_t expires_from_now(const duration_type& expiry_time,
      boost::system::error_code& ec)
  {
<<<<<<< HEAD
    return this->get_service().expires_from_now(
        this->get_implementation(), expiry_time, ec);
=======
    return impl_.get_service().expires_from_now(
        impl_.get_implementation(), expiry_time, ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  /// Perform a blocking wait on the timer.
  /**
   * This function is used to wait for the timer to expire. This function
   * blocks and does not return until the timer has expired.
   *
   * @throws boost::system::system_error Thrown on failure.
   */
  void wait()
  {
    boost::system::error_code ec;
<<<<<<< HEAD
    this->get_service().wait(this->get_implementation(), ec);
=======
    impl_.get_service().wait(impl_.get_implementation(), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    boost::asio::detail::throw_error(ec, "wait");
  }

  /// Perform a blocking wait on the timer.
  /**
   * This function is used to wait for the timer to expire. This function
   * blocks and does not return until the timer has expired.
   *
   * @param ec Set to indicate what error occurred, if any.
   */
  void wait(boost::system::error_code& ec)
  {
<<<<<<< HEAD
    this->get_service().wait(this->get_implementation(), ec);
=======
    impl_.get_service().wait(impl_.get_implementation(), ec);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  }

  /// Start an asynchronous wait on the timer.
  /**
   * This function may be used to initiate an asynchronous wait against the
   * timer. It always returns immediately.
   *
   * For each call to async_wait(), the supplied handler will be called exactly
   * once. The handler will be called when:
   *
   * @li The timer has expired.
   *
   * @li The timer was cancelled, in which case the handler is passed the error
   * code boost::asio::error::operation_aborted.
   *
   * @param handler The handler to be called when the timer expires. Copies
   * will be made of the handler as required. The function signature of the
   * handler must be:
   * @code void handler(
   *   const boost::system::error_code& error // Result of operation.
   * ); @endcode
   * Regardless of whether the asynchronous operation completes immediately or
<<<<<<< HEAD
   * not, the handler will not be invoked from within this function. Invocation
   * of the handler will be performed in a manner equivalent to using
   * boost::asio::io_context::post().
   */
  template <typename WaitHandler>
  BOOST_ASIO_INITFN_RESULT_TYPE(WaitHandler,
      void (boost::system::error_code))
  async_wait(BOOST_ASIO_MOVE_ARG(WaitHandler) handler)
  {
    // If you get an error on the following line it means that your handler does
    // not meet the documented type requirements for a WaitHandler.
    BOOST_ASIO_WAIT_HANDLER_CHECK(WaitHandler, handler) type_check;

#if defined(BOOST_ASIO_ENABLE_OLD_SERVICES)
    return this->get_service().async_wait(this->get_implementation(),
        BOOST_ASIO_MOVE_CAST(WaitHandler)(handler));
#else // defined(BOOST_ASIO_ENABLE_OLD_SERVICES)
    async_completion<WaitHandler,
      void (boost::system::error_code)> init(handler);

    this->get_service().async_wait(this->get_implementation(),
        init.completion_handler);

    return init.result.get();
#endif // defined(BOOST_ASIO_ENABLE_OLD_SERVICES)
  }
=======
   * not, the handler will not be invoked from within this function. On
   * immediate completion, invocation of the handler will be performed in a
   * manner equivalent to using boost::asio::post().
   */
  template <
      BOOST_ASIO_COMPLETION_TOKEN_FOR(void (boost::system::error_code))
        WaitHandler BOOST_ASIO_DEFAULT_COMPLETION_TOKEN_TYPE(executor_type)>
  BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(WaitHandler,
      void (boost::system::error_code))
  async_wait(
      BOOST_ASIO_MOVE_ARG(WaitHandler) handler
        BOOST_ASIO_DEFAULT_COMPLETION_TOKEN(executor_type))
  {
    return async_initiate<WaitHandler, void (boost::system::error_code)>(
        initiate_async_wait(this), handler);
  }

private:
  // Disallow copying and assignment.
  basic_deadline_timer(const basic_deadline_timer&) BOOST_ASIO_DELETED;
  basic_deadline_timer& operator=(
      const basic_deadline_timer&) BOOST_ASIO_DELETED;

  class initiate_async_wait
  {
  public:
    typedef Executor executor_type;

    explicit initiate_async_wait(basic_deadline_timer* self)
      : self_(self)
    {
    }

    executor_type get_executor() const BOOST_ASIO_NOEXCEPT
    {
      return self_->get_executor();
    }

    template <typename WaitHandler>
    void operator()(BOOST_ASIO_MOVE_ARG(WaitHandler) handler) const
    {
      // If you get an error on the following line it means that your handler
      // does not meet the documented type requirements for a WaitHandler.
      BOOST_ASIO_WAIT_HANDLER_CHECK(WaitHandler, handler) type_check;

      detail::non_const_lvalue<WaitHandler> handler2(handler);
      self_->impl_.get_service().async_wait(
          self_->impl_.get_implementation(), handler2.value,
          self_->impl_.get_implementation_executor());
    }

  private:
    basic_deadline_timer* self_;
  };

  detail::io_object_impl<
    detail::deadline_timer_service<TimeTraits>, Executor> impl_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

<<<<<<< HEAD
#if !defined(BOOST_ASIO_ENABLE_OLD_SERVICES)
# undef BOOST_ASIO_SVC_T
#endif // !defined(BOOST_ASIO_ENABLE_OLD_SERVICES)

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif // defined(BOOST_ASIO_HAS_BOOST_DATE_TIME)
       // || defined(GENERATING_DOCUMENTATION)

#endif // BOOST_ASIO_BASIC_DEADLINE_TIMER_HPP
