//---------------------------------------------------------------------------//
// Copyright (c) 2013 Kyle Lutz <kyle.r.lutz@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://boostorg.github.com/compute for more information.
//---------------------------------------------------------------------------//

#ifndef BOOST_COMPUTE_ALGORITHM_DETAIL_COPY_TO_DEVICE_HPP
#define BOOST_COMPUTE_ALGORITHM_DETAIL_COPY_TO_DEVICE_HPP

#include <iterator>

#include <boost/utility/addressof.hpp>

#include <boost/compute/command_queue.hpp>
#include <boost/compute/async/future.hpp>
#include <boost/compute/iterator/buffer_iterator.hpp>
#include <boost/compute/memory/svm_ptr.hpp>

namespace boost {
namespace compute {
namespace detail {

template<class HostIterator, class DeviceIterator>
inline DeviceIterator copy_to_device(HostIterator first,
                                     HostIterator last,
                                     DeviceIterator result,
<<<<<<< HEAD
                                     command_queue &queue)
=======
                                     command_queue &queue,
                                     const wait_list &events)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef typename
        std::iterator_traits<DeviceIterator>::value_type
        value_type;
    typedef typename
        std::iterator_traits<DeviceIterator>::difference_type
        difference_type;

    size_t count = iterator_range_size(first, last);
    if(count == 0){
        return result;
    }

    size_t offset = result.get_index();

    queue.enqueue_write_buffer(result.get_buffer(),
                               offset * sizeof(value_type),
                               count * sizeof(value_type),
<<<<<<< HEAD
                               ::boost::addressof(*first));
=======
                               ::boost::addressof(*first),
                               events);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    return result + static_cast<difference_type>(count);
}

template<class HostIterator, class DeviceIterator>
inline DeviceIterator copy_to_device_map(HostIterator first,
                                         HostIterator last,
                                         DeviceIterator result,
<<<<<<< HEAD
                                         command_queue &queue)
=======
                                         command_queue &queue,
                                         const wait_list &events)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef typename
        std::iterator_traits<DeviceIterator>::value_type
        value_type;
    typedef typename
        std::iterator_traits<DeviceIterator>::difference_type
        difference_type;

    size_t count = iterator_range_size(first, last);
    if(count == 0){
        return result;
    }

    size_t offset = result.get_index();

    // map result buffer to host
    value_type *pointer = static_cast<value_type*>(
        queue.enqueue_map_buffer(
            result.get_buffer(),
            CL_MAP_WRITE,
            offset * sizeof(value_type),
<<<<<<< HEAD
            count * sizeof(value_type)
=======
            count * sizeof(value_type),
            events
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        )
    );

    // copy [first; last) to result buffer
    std::copy(first, last, pointer);

    // unmap result buffer
    boost::compute::event unmap_event = queue.enqueue_unmap_buffer(
        result.get_buffer(),
        static_cast<void*>(pointer)
    );
    unmap_event.wait();

    return result + static_cast<difference_type>(count);
}

template<class HostIterator, class DeviceIterator>
inline future<DeviceIterator> copy_to_device_async(HostIterator first,
                                                   HostIterator last,
                                                   DeviceIterator result,
<<<<<<< HEAD
                                                   command_queue &queue)
=======
                                                   command_queue &queue,
                                                   const wait_list &events)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef typename
        std::iterator_traits<DeviceIterator>::value_type
        value_type;
    typedef typename
        std::iterator_traits<DeviceIterator>::difference_type
        difference_type;

    size_t count = iterator_range_size(first, last);
    if(count == 0){
        return future<DeviceIterator>();
    }

    size_t offset = result.get_index();

    event event_ =
        queue.enqueue_write_buffer_async(result.get_buffer(),
                                         offset * sizeof(value_type),
                                         count * sizeof(value_type),
<<<<<<< HEAD
                                         ::boost::addressof(*first));
=======
                                         ::boost::addressof(*first),
                                         events);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    return make_future(result + static_cast<difference_type>(count), event_);
}

#ifdef BOOST_COMPUTE_CL_VERSION_2_0
// copy_to_device() specialization for svm_ptr
template<class HostIterator, class T>
inline svm_ptr<T> copy_to_device(HostIterator first,
                                 HostIterator last,
                                 svm_ptr<T> result,
<<<<<<< HEAD
                                 command_queue &queue)
=======
                                 command_queue &queue,
                                 const wait_list &events)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    size_t count = iterator_range_size(first, last);
    if(count == 0){
        return result;
    }

    queue.enqueue_svm_memcpy(
<<<<<<< HEAD
        result.get(), ::boost::addressof(*first), count * sizeof(T)
=======
        result.get(), ::boost::addressof(*first), count * sizeof(T), events
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    );

    return result + count;
}

template<class HostIterator, class T>
inline future<svm_ptr<T> > copy_to_device_async(HostIterator first,
                                                HostIterator last,
                                                svm_ptr<T> result,
<<<<<<< HEAD
                                                command_queue &queue)
=======
                                                command_queue &queue,
                                                const wait_list &events)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    size_t count = iterator_range_size(first, last);
    if(count == 0){
        return future<svm_ptr<T> >();
    }

    event event_ = queue.enqueue_svm_memcpy_async(
<<<<<<< HEAD
        result.get(), ::boost::addressof(*first), count * sizeof(T)
=======
        result.get(), ::boost::addressof(*first), count * sizeof(T), events
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    );

    return make_future(result + count, event_);
}

template<class HostIterator, class T>
inline svm_ptr<T> copy_to_device_map(HostIterator first,
                                              HostIterator last,
                                              svm_ptr<T> result,
<<<<<<< HEAD
                                              command_queue &queue)
=======
                                              command_queue &queue,
                                              const wait_list &events)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    size_t count = iterator_range_size(first, last);
    if(count == 0){
        return result;
    }

    // map
<<<<<<< HEAD
    queue.enqueue_svm_map(result.get(), count * sizeof(T), CL_MAP_WRITE);
=======
    queue.enqueue_svm_map(
        result.get(), count * sizeof(T), CL_MAP_WRITE, events
    );
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    // copy [first; last) to result buffer
    std::copy(first, last, static_cast<T*>(result.get()));

    // unmap result
    queue.enqueue_svm_unmap(result.get()).wait();

    return result + count;
}
#endif // BOOST_COMPUTE_CL_VERSION_2_0

} // end detail namespace
} // end compute namespace
} // end boost namespace

#endif // BOOST_COMPUTE_ALGORITHM_DETAIL_COPY_TO_DEVICE_HPP
