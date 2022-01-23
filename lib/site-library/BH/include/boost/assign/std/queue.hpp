// Boost.Assign library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/assign/
//


#ifndef BOOST_ASSIGN_STD_QUEUE_HPP
#define BOOST_ASSIGN_STD_QUEUE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <boost/assign/list_inserter.hpp>
#include <boost/config.hpp>
<<<<<<< HEAD
=======
#include <boost/move/utility.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <queue>

namespace boost
{
namespace assign
{
<<<<<<< HEAD
=======
#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    template< class V, class C, class V2 >
    inline list_inserter< assign_detail::call_push< std::queue<V,C> >, V >
    operator+=( std::queue<V,C>& c, V2 v )
    {
        return push( c )( v );
    }
    
    template< class V, class C, class V2 >
    inline list_inserter< assign_detail::call_push< std::priority_queue<V,C> >, V >
    operator+=( std::priority_queue<V,C>& c, V2 v )
    {
        return push( c )( v );
    }

<<<<<<< HEAD
=======
#else

    template< class V, class C, class V2 >
    inline list_inserter< assign_detail::call_push< std::queue<V, C> >, V >
    operator+=(std::queue<V, C>& c, V2&& v)
    {
        return push(c)(boost::forward<V2>(v));
    }

    template< class V, class C, class V2 >
    inline list_inserter< assign_detail::call_push< std::priority_queue<V, C> >, V >
    operator+=(std::priority_queue<V, C>& c, V2&& v)
    {
        return push(c)(boost::forward<V2>(v));
    }

#endif
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}
}

#endif
