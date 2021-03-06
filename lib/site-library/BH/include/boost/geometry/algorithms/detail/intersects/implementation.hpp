// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2014 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2014 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2014 Mateusz Loskot, London, UK.

// This file was modified by Oracle on 2013-2017.
// Modifications copyright (c) 2013-2017, Oracle and/or its affiliates.

// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Parts of Boost.Geometry are redesigned from Geodan's Geographic Library
// (geolib/GGL), copyright (c) 1995-2010 Geodan, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_INTERSECTS_IMPLEMENTATION_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_INTERSECTS_IMPLEMENTATION_HPP


#include <deque>

#include <boost/geometry/algorithms/detail/intersects/interface.hpp>
#include <boost/geometry/algorithms/detail/disjoint/implementation.hpp>

#include <boost/geometry/algorithms/detail/overlay/self_turn_points.hpp>
#include <boost/geometry/policies/disjoint_interrupt_policy.hpp>
#include <boost/geometry/policies/robustness/no_rescale_policy.hpp>
<<<<<<< HEAD
#include <boost/geometry/policies/robustness/segment_ratio_type.hpp>
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#include <boost/geometry/strategies/relate.hpp>


namespace boost { namespace geometry
{

#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace intersects
{

template <typename Geometry>
struct self_intersects
{
    static bool apply(Geometry const& geometry)
    {
        concepts::check<Geometry const>();

        typedef typename geometry::point_type<Geometry>::type point_type;
        typedef typename strategy::relate::services::default_strategy
                <
                    Geometry, Geometry
                >::type strategy_type;
<<<<<<< HEAD
        typedef detail::no_rescale_policy rescale_policy_type;

        typedef detail::overlay::turn_info
            <
                point_type,
                typename segment_ratio_type<point_type, rescale_policy_type>::type
            > turn_info;
=======

        typedef detail::overlay::turn_info<point_type> turn_info;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

        std::deque<turn_info> turns;

        typedef detail::overlay::get_turn_info
            <
                detail::overlay::assign_null_policy
            > turn_policy;

        strategy_type strategy;
<<<<<<< HEAD
        rescale_policy_type robust_policy;
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

        detail::disjoint::disjoint_interrupt_policy policy;
    // TODO: skip_adjacent should be set to false
        detail::self_get_turn_points::get_turns
            <
                false, turn_policy
<<<<<<< HEAD
            >::apply(geometry, strategy, robust_policy, turns, policy, 0, true);
=======
            >::apply(geometry, strategy, detail::no_rescale_policy(), turns, policy, 0, true);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        return policy.has_intersections;
    }
};

}} // namespace detail::intersects
#endif // DOXYGEN_NO_DETAIL

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_INTERSECTS_IMPLEMENTATION_HPP
