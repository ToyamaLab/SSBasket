//
// Boost.Pointer Container
//
//  Copyright Thorsten Ottosen 2003-2005. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/ptr_container/
//

#ifndef BOOST_PTR_CONTAINER_PTR_VECTOR_HPP
#define BOOST_PTR_CONTAINER_PTR_VECTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <vector>
#include <boost/ptr_container/ptr_sequence_adapter.hpp>
<<<<<<< HEAD
=======
#include <boost/ptr_container/detail/ptr_container_disable_deprecated.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/if.hpp>

#if defined(BOOST_PTR_CONTAINER_DISABLE_DEPRECATED)
#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace boost
{

    template
    < 
        class T, 
        class CloneAllocator = heap_clone_allocator,
<<<<<<< HEAD
        class Allocator      = std::allocator<typename ptr_container_detail::void_ptr<T>::type>
    >
    class ptr_vector : public 
        ptr_sequence_adapter< T, std::vector<
            typename ptr_container_detail::void_ptr<T>::type,Allocator>, 
                              CloneAllocator >
    {  
        typedef ptr_sequence_adapter< T, std::vector<
            typename ptr_container_detail::void_ptr<T>::type,Allocator>, 
                                      CloneAllocator > 
=======
        class Allocator      = void
    >
    class ptr_vector : public 
        ptr_sequence_adapter< T,
            std::vector<
                typename ptr_container_detail::void_ptr<T>::type,
                typename boost::mpl::if_<boost::is_same<Allocator, void>,
                    std::allocator<typename ptr_container_detail::void_ptr<T>::type>, Allocator>::type
            >,
            CloneAllocator >
    {  
        typedef

            ptr_sequence_adapter< T,
                std::vector<
                    typename ptr_container_detail::void_ptr<T>::type,
                    typename boost::mpl::if_<boost::is_same<Allocator, void>,
                        std::allocator<typename ptr_container_detail::void_ptr<T>::type>, Allocator>::type
                >,
                CloneAllocator >

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            base_class;

        typedef ptr_vector<T,CloneAllocator,Allocator> this_type;
        
    public:

        BOOST_PTR_CONTAINER_DEFINE_SEQEUENCE_MEMBERS( ptr_vector, 
                                                      base_class,
                                                      this_type )
        
        explicit ptr_vector( size_type n,
                             const allocator_type& alloc = allocator_type() )
          : base_class(alloc)
        {
            this->base().reserve( n );
        }        
    };

    //////////////////////////////////////////////////////////////////////////////
    // clonability

    template< typename T, typename CA, typename A >
    inline ptr_vector<T,CA,A>* new_clone( const ptr_vector<T,CA,A>& r )
    {
        return r.clone().release();
    }

    /////////////////////////////////////////////////////////////////////////
    // swap

    template< typename T, typename CA, typename A >
    inline void swap( ptr_vector<T,CA,A>& l, ptr_vector<T,CA,A>& r )
    {
        l.swap(r);
    }
    
}

<<<<<<< HEAD
=======
#if defined(BOOST_PTR_CONTAINER_DISABLE_DEPRECATED)
#pragma GCC diagnostic pop
#endif

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#endif