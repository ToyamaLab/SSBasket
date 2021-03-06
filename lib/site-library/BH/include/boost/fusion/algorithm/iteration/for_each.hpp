/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2007 Dan Marsden
<<<<<<< HEAD
=======
    Copyright (c) 2018 Kohei Takahashi
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(BOOST_FUSION_FOR_EACH_20070527_0943)
#define BOOST_FUSION_FOR_EACH_20070527_0943

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/algorithm/iteration/detail/for_each.hpp>
#include <boost/fusion/algorithm/iteration/detail/segmented_for_each.hpp>
#include <boost/fusion/support/is_segmented.hpp>
#include <boost/fusion/support/is_sequence.hpp>
<<<<<<< HEAD
#include <boost/utility/enable_if.hpp>
=======
#include <boost/core/enable_if.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace boost { namespace fusion
{
    namespace result_of
    {
        template <typename Sequence, typename F>
        struct for_each
        {
            typedef void type;
        };
    }

    template <typename Sequence, typename F>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
<<<<<<< HEAD
    inline typename
        enable_if<
            traits::is_sequence<Sequence>
          , void
        >::type
    for_each(Sequence& seq, F const& f)
=======
    inline typename enable_if<traits::is_sequence<Sequence> >::type
    for_each(Sequence& seq, F f)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    {
        detail::for_each(seq, f, typename traits::is_segmented<Sequence>::type());
    }

    template <typename Sequence, typename F>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
<<<<<<< HEAD
    inline typename
        enable_if<
            traits::is_sequence<Sequence>
          , void
        >::type
    for_each(Sequence const& seq, F const& f)
=======
    inline typename enable_if<traits::is_sequence<Sequence> >::type
    for_each(Sequence const& seq, F f)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    {
        detail::for_each(seq, f, typename traits::is_segmented<Sequence>::type());
    }
}}

#endif
