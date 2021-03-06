/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
<<<<<<< HEAD
=======
    Copyright (c) 2018 Kohei Takahashi
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_NEXT_IMPL_06052005_0900)
#define FUSION_NEXT_IMPL_06052005_0900

#include <boost/fusion/support/config.hpp>
<<<<<<< HEAD
#include <boost/fusion/algorithm/query/detail/find_if.hpp>
#include <boost/fusion/iterator/value_of.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/bind.hpp>
#include <boost/mpl/placeholders.hpp>
=======
#include <boost/fusion/iterator/next.hpp>
#include <boost/fusion/iterator/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace boost { namespace fusion
{
    struct filter_view_iterator_tag;

    template <typename Category,  typename First, typename Last, typename Pred>
    struct filter_iterator;

    namespace extension
    {
        template <typename Tag>
        struct next_impl;

        template <>
        struct next_impl<filter_view_iterator_tag>
        {
            template <typename Iterator>
            struct apply
            {
                typedef typename Iterator::first_type first_type;
                typedef typename Iterator::last_type last_type;
                typedef typename Iterator::pred_type pred_type;
                typedef typename Iterator::category category;

                typedef typename
                    mpl::eval_if<
                        result_of::equal_to<first_type, last_type>
                      , mpl::identity<last_type>
                      , result_of::next<first_type>
                    >::type
                next_type;

<<<<<<< HEAD
                typedef typename
                    detail::static_find_if<
                        next_type
                      , last_type
                      , mpl::bind1<
                            typename mpl::lambda<pred_type>::type
                          , mpl::bind1<mpl::quote1<result_of::value_of>,mpl::_1>
                        >
                    >
                filter;

                typedef filter_iterator<
                    category, typename filter::type, last_type, pred_type>
                type;
=======
                typedef filter_iterator<category, next_type, last_type, pred_type> type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

                BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
                static type
                call(Iterator const& i)
                {
<<<<<<< HEAD
                    return type(filter::iter_call(i.first));
=======
                    return type(fusion::next(i.first));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                }
            };
        };
    }
}}

#endif


