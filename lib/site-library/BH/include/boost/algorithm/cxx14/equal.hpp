/* 
   Copyright (c) Marshall Clow 2008-2012.

   Distributed under the Boost Software License, Version 1.0. (See accompanying
   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/

/// \file  equal.hpp
/// \brief Test ranges to if they are equal
/// \author Marshall Clow

#ifndef BOOST_ALGORITHM_EQUAL_HPP
#define BOOST_ALGORITHM_EQUAL_HPP

<<<<<<< HEAD
#include <algorithm>    // for std::equal
#include <iterator>

=======
#include <iterator>

#include <boost/config.hpp>

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
namespace boost { namespace algorithm {

namespace detail {

    template <class T1, class T2>
    struct eq {
<<<<<<< HEAD
        bool operator () ( const T1& v1, const T2& v2 ) const { return v1 == v2 ;}
        };
    
    template <class RandomAccessIterator1, class RandomAccessIterator2, class BinaryPredicate>
=======
        BOOST_CONSTEXPR bool operator () ( const T1& v1, const T2& v2 ) const { return v1 == v2 ;}
        };
    
    template <class RandomAccessIterator1, class RandomAccessIterator2, class BinaryPredicate>
    BOOST_CXX14_CONSTEXPR
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    bool equal ( RandomAccessIterator1 first1, RandomAccessIterator1 last1, 
                 RandomAccessIterator2 first2, RandomAccessIterator2 last2, BinaryPredicate pred,
                 std::random_access_iterator_tag, std::random_access_iterator_tag )
    {
    //  Random-access iterators let is check the sizes in constant time
        if ( std::distance ( first1, last1 ) != std::distance ( first2, last2 ))
            return false;
<<<<<<< HEAD
    // If we know that the sequences are the same size, the original version is fine
        return std::equal ( first1, last1, first2, pred );
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
=======

    //  std::equal
        for (; first1 != last1; ++first1, ++first2)
            if (!pred(*first1, *first2))
                return false;
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    BOOST_CXX14_CONSTEXPR
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    bool equal ( InputIterator1 first1, InputIterator1 last1, 
                 InputIterator2 first2, InputIterator2 last2, BinaryPredicate pred,
                 std::input_iterator_tag, std::input_iterator_tag )
    {
    for (; first1 != last1 && first2 != last2; ++first1, ++first2 )
        if ( !pred(*first1, *first2 ))
            return false;

    return first1 == last1 && first2 == last2;
    }
}

/// \fn equal ( InputIterator1 first1, InputIterator1 last1, 
///             InputIterator2 first2, InputIterator2 last2,
///             BinaryPredicate pred )
/// \return true if all elements in the two ranges are equal
/// 
/// \param first1    The start of the first range.
/// \param last1     One past the end of the first range.
/// \param first2    The start of the second range.
/// \param last2     One past the end of the second range.
/// \param pred      A predicate for comparing the elements of the ranges
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
<<<<<<< HEAD
=======
BOOST_CXX14_CONSTEXPR
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
bool equal ( InputIterator1 first1, InputIterator1 last1, 
             InputIterator2 first2, InputIterator2 last2, BinaryPredicate pred )
{
    return boost::algorithm::detail::equal ( 
        first1, last1, first2, last2, pred,
        typename std::iterator_traits<InputIterator1>::iterator_category (),
        typename std::iterator_traits<InputIterator2>::iterator_category ());
}

/// \fn equal ( InputIterator1 first1, InputIterator1 last1, 
///             InputIterator2 first2, InputIterator2 last2 )
/// \return true if all elements in the two ranges are equal
/// 
/// \param first1    The start of the first range.
/// \param last1     One past the end of the first range.
/// \param first2    The start of the second range.
/// \param last2     One past the end of the second range.
template <class InputIterator1, class InputIterator2>
<<<<<<< HEAD
=======
BOOST_CXX14_CONSTEXPR
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
bool equal ( InputIterator1 first1, InputIterator1 last1, 
             InputIterator2 first2, InputIterator2 last2 )
{
    return boost::algorithm::detail::equal (
        first1, last1, first2, last2,
        boost::algorithm::detail::eq<
            typename std::iterator_traits<InputIterator1>::value_type,
            typename std::iterator_traits<InputIterator2>::value_type> (),
        typename std::iterator_traits<InputIterator1>::iterator_category (),
        typename std::iterator_traits<InputIterator2>::iterator_category ());
}

//  There are already range-based versions of these.

}} // namespace boost and algorithm

#endif // BOOST_ALGORITHM_EQUAL_HPP
