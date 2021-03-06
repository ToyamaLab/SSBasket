//
// windows/basic_object_handle.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
<<<<<<< HEAD
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
=======
// Copyright (c) 2003-2019 Christopher M. Kohlhoff (chris at kohlhoff dot com)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
// Copyright (c) 2011 Boris Schaeling (boris@highscore.de)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_WINDOWS_BASIC_OBJECT_HANDLE_HPP
#define BOOST_ASIO_WINDOWS_BASIC_OBJECT_HANDLE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

<<<<<<< HEAD
#if defined(BOOST_ASIO_ENABLE_OLD_SERVICES)

#if defined(BOOST_ASIO_HAS_WINDOWS_OBJECT_HANDLE) \
  || defined(GENERATING_DOCUMENTATION)

#include <boost/asio/detail/throw_error.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/windows/basic_handle.hpp>
#include <boost/asio/windows/object_handle_service.hpp>
=======
#if defined(BOOST_ASIO_HAS_WINDOWS_OBJECT_HANDLE) \
  || defined(GENERATING_DOCUMENTATION)

#include <boost/asio/async_result.hpp>
#include <boost/asio/detail/io_object_impl.hpp>
#include <boost/asio/detail/throw_error.hpp>
#include <boost/asio/detail/win_object_handle_service.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/execution_context.hpp>
#include <boost/asio/executor.hpp>

#if defined(BOOST_ASIO_HAS_MOVE)
# include <utility>
#endif // defined(BOOST_ASIO_HAS_MOVE)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace windows {

/// Provides object-oriented handle functionality.
/**
<<<<<<< HEAD
 * The windows::basic_object_handle class template provides asynchronous and
 * blocking object-oriented handle functionality.
=======
 * The windows::basic_object_handle class provides asynchronous and blocking
 * object-oriented handle functionality.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
 *
 * @par Thread Safety
 * @e Distinct @e objects: Safe.@n
 * @e Shared @e objects: Unsafe.
 */
<<<<<<< HEAD
template <typename ObjectHandleService = object_handle_service>
class basic_object_handle
  : public basic_handle<ObjectHandleService>
{
public:
  /// The native representation of a handle.
  typedef typename ObjectHandleService::native_handle_type native_handle_type;

  /// Construct a basic_object_handle without opening it.
  /**
   * This constructor creates an object handle without opening it.
   *
   * @param io_context The io_context object that the object handle will use to
   * dispatch handlers for any asynchronous operations performed on the handle.
   */
  explicit basic_object_handle(boost::asio::io_context& io_context)
    : basic_handle<ObjectHandleService>(io_context)
  {
  }

  /// Construct a basic_object_handle on an existing native handle.
=======
template <typename Executor = executor>
class basic_object_handle
{
public:
  /// The type of the executor associated with the object.
  typedef Executor executor_type;

  /// Rebinds the handle type to another executor.
  template <typename Executor1>
  struct rebind_executor
  {
    /// The handle type when rebound to the specified executor.
    typedef basic_object_handle<Executor1> other;
  };

  /// The native representation of a handle.
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined native_handle_type;
#else
  typedef boost::asio::detail::win_object_handle_service::native_handle_type
    native_handle_type;
#endif

  /// An object handle is always the lowest layer.
  typedef basic_object_handle lowest_layer_type;

  /// Construct an object handle without opening it.
  /**
   * This constructor creates an object handle without opening it.
   *
   * @param ex The I/O executor that the object handle will use, by default, to
   * dispatch handlers for any asynchronous operations performed on the
   * object handle.
   */
  explicit basic_object_handle(const executor_type& ex)
    : impl_(ex)
  {
  }

  /// Construct an object handle without opening it.
  /**
   * This constructor creates an object handle without opening it.
   *
   * @param context An execution context which provides the I/O executor that
   * the object handle will use, by default, to dispatch handlers for any
   * asynchronous operations performed on the object handle.
   */
  template <typename ExecutionContext>
  explicit basic_object_handle(ExecutionContext& context,
      typename enable_if<
        is_convertible<ExecutionContext&, execution_context&>::value,
        basic_object_handle
      >::type* = 0)
    : impl_(context)
  {
  }

  /// Construct an object handle on an existing native handle.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  /**
   * This constructor creates an object handle object to hold an existing native
   * handle.
   *
<<<<<<< HEAD
   * @param io_context The io_context object that the object handle will use to
   * dispatch handlers for any asynchronous operations performed on the handle.
=======
   * @param ex The I/O executor that the object handle will use, by default, to
   * dispatch handlers for any asynchronous operations performed on the
   * object handle.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
   *
   * @param native_handle The new underlying handle implementation.
   *
   * @throws boost::system::system_error Thrown on failure.
   */
<<<<<<< HEAD
  basic_object_handle(boost::asio::io_context& io_context,
      const native_handle_type& native_handle)
    : basic_handle<ObjectHandleService>(io_context, native_handle)
  {
  }

#if defined(BOOST_ASIO_HAS_MOVE) || defined(GENERATING_DOCUMENTATION)
  /// Move-construct a basic_object_handle from another.
  /**
   * This constructor moves an object handle from one object to another.
   *
   * @param other The other basic_object_handle object from which the move will
   * occur.
   *
   * @note Following the move, the moved-from object is in the same state as if
   * constructed using the @c basic_object_handle(io_context&) constructor.
   */
  basic_object_handle(basic_object_handle&& other)
    : basic_handle<ObjectHandleService>(
        BOOST_ASIO_MOVE_CAST(basic_object_handle)(other))
  {
  }

  /// Move-assign a basic_object_handle from another.
  /**
   * This assignment operator moves an object handle from one object to another.
   *
   * @param other The other basic_object_handle object from which the move will
   * occur.
   *
   * @note Following the move, the moved-from object is in the same state as if
   * constructed using the @c basic_object_handle(io_context&) constructor.
   */
  basic_object_handle& operator=(basic_object_handle&& other)
  {
    basic_handle<ObjectHandleService>::operator=(
        BOOST_ASIO_MOVE_CAST(basic_object_handle)(other));
=======
  basic_object_handle(const executor_type& ex,
      const native_handle_type& native_handle)
    : impl_(ex)
  {
    boost::system::error_code ec;
    impl_.get_service().assign(impl_.get_implementation(), native_handle, ec);
    boost::asio::detail::throw_error(ec, "assign");
  }

  /// Construct an object handle on an existing native handle.
  /**
   * This constructor creates an object handle object to hold an existing native
   * handle.
   *
   * @param context An execution context which provides the I/O executor that
   * the object handle will use, by default, to dispatch handlers for any
   * asynchronous operations performed on the object handle.
   *
   * @param native_handle The new underlying handle implementation.
   *
   * @throws boost::system::system_error Thrown on failure.
   */
  template <typename ExecutionContext>
  basic_object_handle(ExecutionContext& context,
      const native_handle_type& native_handle,
      typename enable_if<
        is_convertible<ExecutionContext&, execution_context&>::value
      >::type* = 0)
    : impl_(context)
  {
    boost::system::error_code ec;
    impl_.get_service().assign(impl_.get_implementation(), native_handle, ec);
    boost::asio::detail::throw_error(ec, "assign");
  }

#if defined(BOOST_ASIO_HAS_MOVE) || defined(GENERATING_DOCUMENTATION)
  /// Move-construct an object handle from another.
  /**
   * This constructor moves an object handle from one object to another.
   *
   * @param other The other object handle object from which the move will
   * occur.
   *
   * @note Following the move, the moved-from object is in the same state as if
   * constructed using the @c basic_object_handle(const executor_type&)
   * constructor.
   */
  basic_object_handle(basic_object_handle&& other)
    : impl_(std::move(other.impl_))
  {
  }

  /// Move-assign an object handle from another.
  /**
   * This assignment operator moves an object handle from one object to another.
   *
   * @param other The other object handle object from which the move will
   * occur.
   *
   * @note Following the move, the moved-from object is in the same state as if
   * constructed using the @c basic_object_handle(const executor_type&)
   * constructor.
   */
  basic_object_handle& operator=(basic_object_handle&& other)
  {
    impl_ = std::move(other.impl_);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    return *this;
  }
#endif // defined(BOOST_ASIO_HAS_MOVE) || defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
=======
  /// Get the executor associated with the object.
  executor_type get_executor() BOOST_ASIO_NOEXCEPT
  {
    return impl_.get_executor();
  }

  /// Get a reference to the lowest layer.
  /**
   * This function returns a reference to the lowest layer in a stack of
   * layers. Since an object handle cannot contain any further layers, it simply
   * returns a reference to itself.
   *
   * @return A reference to the lowest layer in the stack of layers. Ownership
   * is not transferred to the caller.
   */
  lowest_layer_type& lowest_layer()
  {
    return *this;
  }

  /// Get a const reference to the lowest layer.
  /**
   * This function returns a const reference to the lowest layer in a stack of
   * layers. Since an object handle cannot contain any further layers, it simply
   * returns a reference to itself.
   *
   * @return A const reference to the lowest layer in the stack of layers.
   * Ownership is not transferred to the caller.
   */
  const lowest_layer_type& lowest_layer() const
  {
    return *this;
  }

  /// Assign an existing native handle to the handle.
  /*
   * This function opens the handle to hold an existing native handle.
   *
   * @param handle A native handle.
   *
   * @throws boost::system::system_error Thrown on failure.
   */
  void assign(const native_handle_type& handle)
  {
    boost::system::error_code ec;
    impl_.get_service().assign(impl_.get_implementation(), handle, ec);
    boost::asio::detail::throw_error(ec, "assign");
  }

  /// Assign an existing native handle to the handle.
  /*
   * This function opens the handle to hold an existing native handle.
   *
   * @param handle A native handle.
   *
   * @param ec Set to indicate what error occurred, if any.
   */
  BOOST_ASIO_SYNC_OP_VOID assign(const native_handle_type& handle,
      boost::system::error_code& ec)
  {
    impl_.get_service().assign(impl_.get_implementation(), handle, ec);
    BOOST_ASIO_SYNC_OP_VOID_RETURN(ec);
  }

  /// Determine whether the handle is open.
  bool is_open() const
  {
    return impl_.get_service().is_open(impl_.get_implementation());
  }

  /// Close the handle.
  /**
   * This function is used to close the handle. Any asynchronous read or write
   * operations will be cancelled immediately, and will complete with the
   * boost::asio::error::operation_aborted error.
   *
   * @throws boost::system::system_error Thrown on failure.
   */
  void close()
  {
    boost::system::error_code ec;
    impl_.get_service().close(impl_.get_implementation(), ec);
    boost::asio::detail::throw_error(ec, "close");
  }

  /// Close the handle.
  /**
   * This function is used to close the handle. Any asynchronous read or write
   * operations will be cancelled immediately, and will complete with the
   * boost::asio::error::operation_aborted error.
   *
   * @param ec Set to indicate what error occurred, if any.
   */
  BOOST_ASIO_SYNC_OP_VOID close(boost::system::error_code& ec)
  {
    impl_.get_service().close(impl_.get_implementation(), ec);
    BOOST_ASIO_SYNC_OP_VOID_RETURN(ec);
  }

  /// Get the native handle representation.
  /**
   * This function may be used to obtain the underlying representation of the
   * handle. This is intended to allow access to native handle functionality
   * that is not otherwise provided.
   */
  native_handle_type native_handle()
  {
    return impl_.get_service().native_handle(impl_.get_implementation());
  }

  /// Cancel all asynchronous operations associated with the handle.
  /**
   * This function causes all outstanding asynchronous read or write operations
   * to finish immediately, and the handlers for cancelled operations will be
   * passed the boost::asio::error::operation_aborted error.
   *
   * @throws boost::system::system_error Thrown on failure.
   */
  void cancel()
  {
    boost::system::error_code ec;
    impl_.get_service().cancel(impl_.get_implementation(), ec);
    boost::asio::detail::throw_error(ec, "cancel");
  }

  /// Cancel all asynchronous operations associated with the handle.
  /**
   * This function causes all outstanding asynchronous read or write operations
   * to finish immediately, and the handlers for cancelled operations will be
   * passed the boost::asio::error::operation_aborted error.
   *
   * @param ec Set to indicate what error occurred, if any.
   */
  BOOST_ASIO_SYNC_OP_VOID cancel(boost::system::error_code& ec)
  {
    impl_.get_service().cancel(impl_.get_implementation(), ec);
    BOOST_ASIO_SYNC_OP_VOID_RETURN(ec);
  }

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  /// Perform a blocking wait on the object handle.
  /**
   * This function is used to wait for the object handle to be set to the
   * signalled state. This function blocks and does not return until the object
   * handle has been set to the signalled state.
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

  /// Perform a blocking wait on the object handle.
  /**
   * This function is used to wait for the object handle to be set to the
   * signalled state. This function blocks and does not return until the object
   * handle has been set to the signalled state.
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

  /// Start an asynchronous wait on the object handle.
  /**
   * This function is be used to initiate an asynchronous wait against the
   * object handle. It always returns immediately.
   *
   * @param handler The handler to be called when the object handle is set to
   * the signalled state. Copies will be made of the handler as required. The
   * function signature of the handler must be:
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
    return this->get_service().async_wait(this->get_implementation(),
        BOOST_ASIO_MOVE_CAST(WaitHandler)(handler));
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
  basic_object_handle(const basic_object_handle&) BOOST_ASIO_DELETED;
  basic_object_handle& operator=(const basic_object_handle&) BOOST_ASIO_DELETED;

  class initiate_async_wait
  {
  public:
    typedef Executor executor_type;

    explicit initiate_async_wait(basic_object_handle* self)
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
    basic_object_handle* self_;
  };

  boost::asio::detail::io_object_impl<
    boost::asio::detail::win_object_handle_service, Executor> impl_;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

} // namespace windows
} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

#endif // defined(BOOST_ASIO_HAS_WINDOWS_OBJECT_HANDLE)
       //   || defined(GENERATING_DOCUMENTATION)

<<<<<<< HEAD
#endif // defined(BOOST_ASIO_ENABLE_OLD_SERVICES)

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif // BOOST_ASIO_WINDOWS_BASIC_OBJECT_HANDLE_HPP
