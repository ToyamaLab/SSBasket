//---------------------------------------------------------------------------//
// Copyright (c) 2013 Kyle Lutz <kyle.r.lutz@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://boostorg.github.com/compute for more information.
//---------------------------------------------------------------------------//

#ifndef BOOST_COMPUTE_ALGORITHM_IOTA_HPP
#define BOOST_COMPUTE_ALGORITHM_IOTA_HPP

<<<<<<< HEAD
=======
#include <boost/static_assert.hpp>

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/compute/system.hpp>
#include <boost/compute/command_queue.hpp>
#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/iterator/counting_iterator.hpp>
<<<<<<< HEAD
=======
#include <boost/compute/type_traits/is_device_iterator.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace boost {
namespace compute {

/// Fills the range [\p first, \p last) with sequential values starting at
/// \p value.
///
/// For example, the following code:
/// \snippet test/test_iota.cpp iota
///
/// Will fill \c vec with the values (\c 0, \c 1, \c 2, \c ...).
///
/// Space complexity: \Omega(1)
template<class BufferIterator, class T>
inline void iota(BufferIterator first,
                 BufferIterator last,
                 const T &value,
                 command_queue &queue = system::default_queue())
{
<<<<<<< HEAD
=======
    BOOST_STATIC_ASSERT(is_device_iterator<BufferIterator>::value);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    T count = static_cast<T>(detail::iterator_range_size(first, last));

    copy(
        ::boost::compute::make_counting_iterator(value),
        ::boost::compute::make_counting_iterator(value + count),
        first,
        queue
    );
}

} // end compute namespace
} // end boost namespace

#endif // BOOST_COMPUTE_ALGORITHM_IOTA_HPP
