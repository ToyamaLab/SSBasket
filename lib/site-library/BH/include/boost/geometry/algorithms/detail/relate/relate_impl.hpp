// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2012 Barend Gehrels, Amsterdam, the Netherlands.

<<<<<<< HEAD
// This file was modified by Oracle on 2013, 2014, 2015.
// Modifications copyright (c) 2013-2015 Oracle and/or its affiliates.
=======
// This file was modified by Oracle on 2013, 2014, 2015, 2019.
// Modifications copyright (c) 2013-2019 Oracle and/or its affiliates.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_RELATE_RELATE_IMPL_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_RELATE_RELATE_IMPL_HPP

#include <boost/mpl/if.hpp>
#include <boost/mpl/or.hpp>
#include <boost/type_traits/is_base_of.hpp>

#include <boost/geometry/algorithms/detail/relate/interface.hpp>
#include <boost/geometry/algorithms/not_implemented.hpp>
#include <boost/geometry/core/tag.hpp>

namespace boost { namespace geometry {


#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace relate {

struct implemented_tag {};

<<<<<<< HEAD
template <template <typename, typename> class StaticMaskTrait,
          typename Geometry1,
          typename Geometry2>
struct relate_impl
    : boost::mpl::if_
        <
            boost::mpl::or_
                <
                    boost::is_base_of
                        <
                            nyi::not_implemented_tag,
                            StaticMaskTrait<Geometry1, Geometry2>
                        >,
                    boost::is_base_of
                        <
                            nyi::not_implemented_tag,
                            dispatch::relate<Geometry1, Geometry2>
                        >
                >,
=======
template
<
    typename Geometry1,
    typename Geometry2
>
struct relate_impl_base
    : boost::mpl::if_c
        <
            boost::is_base_of
                <
                    nyi::not_implemented_tag,
                    dispatch::relate<Geometry1, Geometry2>
                >::value,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            not_implemented
                <
                    typename geometry::tag<Geometry1>::type,
                    typename geometry::tag<Geometry2>::type
                >,
            implemented_tag
        >::type
<<<<<<< HEAD
=======
{};

template
<
    typename Geometry1,
    typename Geometry2,
    typename StaticMask
>
struct relate_impl_dispatch
    : relate_impl_base<Geometry1, Geometry2>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    template <typename Strategy>
    static inline bool apply(Geometry1 const& g1, Geometry2 const& g2, Strategy const& strategy)
    {
        typename detail::relate::result_handler_type
            <
                Geometry1,
                Geometry2,
<<<<<<< HEAD
                typename StaticMaskTrait<Geometry1, Geometry2>::type
=======
                StaticMask
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::type handler;

        dispatch::relate<Geometry1, Geometry2>::apply(g1, g2, handler, strategy);

        return handler.result();
    }
};

<<<<<<< HEAD
=======
template <typename Geometry1, typename Geometry2>
struct relate_impl_dispatch<Geometry1, Geometry2, detail::relate::false_mask>
    : relate_impl_base<Geometry1, Geometry2>
{
    template <typename Strategy>
    static inline bool apply(Geometry1 const& , Geometry2 const& , Strategy const& )
    {
        return false;
    }
};

template
<
    template <typename, typename> class StaticMaskTrait,
    typename Geometry1,
    typename Geometry2
>
struct relate_impl
    : relate_impl_dispatch
        <
            Geometry1,
            Geometry2,
            typename StaticMaskTrait<Geometry1, Geometry2>::type
        >
{};

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}} // namespace detail::relate
#endif // DOXYGEN_NO_DETAIL

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_RELATE_RELATE_IMPL_HPP
