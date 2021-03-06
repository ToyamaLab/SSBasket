//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2017-2017. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_CONTAINER_DETAIL_IS_CONTAINER_HPP
#define BOOST_CONTAINER_DETAIL_IS_CONTAINER_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

//empty
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_FUNCNAME empty
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_BEG namespace boost { namespace container { namespace is_container_detail {
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_END   }}}
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MIN 0
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MAX 0
#include <boost/intrusive/detail/has_member_function_callable_with.hpp>

//size
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_FUNCNAME size
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_BEG namespace boost { namespace container { namespace is_container_detail {
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_END   }}}
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MIN 0
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MAX 0
#include <boost/intrusive/detail/has_member_function_callable_with.hpp>

namespace boost {
namespace container {
<<<<<<< HEAD
namespace container_detail {
=======
namespace dtl {
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

template <class Container>
struct is_container
{
   static const bool value =
      boost::container::is_container_detail::
         has_member_function_callable_with_size <const Container>::value &&
      boost::container::is_container_detail::
         has_member_function_callable_with_empty<const Container>::value;
};

<<<<<<< HEAD
}  //namespace container_detail {
=======
template <>
struct is_container<void>
{
   static const bool value = false;
};


}  //namespace dtl {
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}  //namespace container {
}  //namespace boost {

#endif   //#ifndef BOOST_CONTAINER_DETAIL_IS_CONTAINER_HPP
