///////////////////////////////////////////////////////////////////////////////
//  Copyright 2012 John Maddock.
//  Copyright Christopher Kormanyos 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_MP_DETAIL_REBIND_HPP
<<<<<<< HEAD
  #define BOOST_MP_DETAIL_REBIND_HPP

  namespace boost { namespace multiprecision { namespace backends { namespace detail
  {
    template <class value_type, class my_allocator>
    struct rebind
    {
       typedef typename my_allocator::template rebind<value_type>::other type;
    };
  } } } } // namespace boost::multiprecision::backends::detail
=======
#define BOOST_MP_DETAIL_REBIND_HPP

namespace boost { namespace multiprecision { namespace backends { namespace detail {
template <class value_type, class my_allocator>
struct rebind
{
#ifndef BOOST_NO_CXX11_ALLOCATOR
   typedef typename std::allocator_traits<my_allocator>::template rebind_alloc<value_type> type;
#else
   typedef typename my_allocator::template rebind<value_type>::other type;
#endif
};
}}}} // namespace boost::multiprecision::backends::detail
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#endif // BOOST_MP_DETAIL_REBIND_HPP
