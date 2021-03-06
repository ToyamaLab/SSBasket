// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef BOOST_RANGE_DETAIL_BEGIN_HPP
#define BOOST_RANGE_DETAIL_BEGIN_HPP

#include <boost/config.hpp> // BOOST_MSVC
#include <boost/detail/workaround.hpp>
#include <boost/range/iterator.hpp>
#include <boost/range/detail/common.hpp>

namespace boost
{

    namespace range_detail
    {
        template< typename T >
        struct range_begin;

        //////////////////////////////////////////////////////////////////////
        // default
        //////////////////////////////////////////////////////////////////////

        template<>
        struct range_begin<std_container_>
        {
            template< typename C >
<<<<<<< HEAD
            static BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type fun( C& c )
=======
            BOOST_CONSTEXPR static BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type fun( C& c )
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            {
                return c.begin();
            };
        };

        //////////////////////////////////////////////////////////////////////
        // pair
        //////////////////////////////////////////////////////////////////////

        template<>
        struct range_begin<std_pair_>
        {
            template< typename P >
<<<<<<< HEAD
            static BOOST_RANGE_DEDUCED_TYPENAME range_iterator<P>::type fun( const P& p )
=======
            BOOST_CONSTEXPR static BOOST_RANGE_DEDUCED_TYPENAME range_iterator<P>::type fun( const P& p )
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            {
                return p.first;
            }
        };

        //////////////////////////////////////////////////////////////////////
        // array
        //////////////////////////////////////////////////////////////////////

        template<>
        struct range_begin<array_>
        {
            template<typename T>
<<<<<<< HEAD
            static BOOST_RANGE_DEDUCED_TYPENAME range_value<T>::type* fun(T& t)
=======
            BOOST_CONSTEXPR static BOOST_RANGE_DEDUCED_TYPENAME range_value<T>::type* fun(T& t)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            {
                return t;
            }
        };

    } // namespace 'range_detail'

    namespace range_adl_barrier
    {
        template< typename C >
<<<<<<< HEAD
        inline BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type
=======
        BOOST_CONSTEXPR inline BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        begin( C& c )
        {
            return range_detail::range_begin< BOOST_RANGE_DEDUCED_TYPENAME range_detail::range<C>::type >::fun( c );
        }
    }
} // namespace 'boost'


#endif
