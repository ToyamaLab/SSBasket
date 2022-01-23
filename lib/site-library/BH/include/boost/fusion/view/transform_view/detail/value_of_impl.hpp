/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
<<<<<<< HEAD
=======
    Copyright (c) 2018 Kohei Takahashi
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_VALUE_OF_IMPL_07162005_1030)
#define FUSION_VALUE_OF_IMPL_07162005_1030

#include <boost/fusion/support/config.hpp>
<<<<<<< HEAD
#include <boost/mpl/apply.hpp>
#include <boost/fusion/iterator/value_of.hpp>
#include <boost/fusion/view/transform_view/detail/apply_transform_result.hpp>
=======
#include <boost/fusion/iterator/value_of.hpp>
#include <boost/utility/result_of.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace boost { namespace fusion
{
    struct transform_view_iterator_tag;
    struct transform_view_iterator2_tag;

    namespace extension
    {
        template <typename Tag>
        struct value_of_impl;

        // Unary Version
        template <>
        struct value_of_impl<transform_view_iterator_tag>
        {
            template <typename Iterator>
            struct apply
            {
                typedef typename
                    result_of::value_of<typename Iterator::first_type>::type
                value_type;

<<<<<<< HEAD
                typedef detail::apply_transform_result<typename Iterator::transform_type> transform_type;
                typedef typename mpl::apply<transform_type, value_type>::type type;
=======
                typedef typename Iterator::transform_type F;
                typedef typename boost::result_of<F(value_type)>::type type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            };
        };

        // Binary Version
        template <>
        struct value_of_impl<transform_view_iterator2_tag>
        {
            template <typename Iterator>
            struct apply
            {
                typedef typename
                    result_of::value_of<typename Iterator::first1_type>::type
                value1_type;
                typedef typename
                    result_of::value_of<typename Iterator::first2_type>::type
                value2_type;

<<<<<<< HEAD
                typedef detail::apply_transform_result<typename Iterator::transform_type> transform_type;
                typedef typename mpl::apply<transform_type, value1_type, value2_type>::type type;
=======
                typedef typename Iterator::transform_type F;
                typedef typename boost::result_of<F(value1_type, value2_type)>::type type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            };
        };
    }
}}

#endif


