// Boost.Geometry (aka GGL, Generic Geometry Library)

<<<<<<< HEAD
// Copyright (c) 2014, Oracle and/or its affiliates.

// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle
=======
// Copyright (c) 2014, 2019, Oracle and/or its affiliates.

// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// Licensed under the Boost Software License version 1.0.
// http://www.boost.org/users/license.html

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_DISTANCE_LINEAR_OR_AREAL_TO_AREAL_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_DISTANCE_LINEAR_OR_AREAL_TO_AREAL_HPP

#include <boost/geometry/core/point_type.hpp>

#include <boost/geometry/strategies/distance.hpp>

#include <boost/geometry/algorithms/intersects.hpp>

#include <boost/geometry/algorithms/detail/distance/linear_to_linear.hpp>

<<<<<<< HEAD

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
namespace boost { namespace geometry
{

#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace distance
{


template <typename Linear, typename Areal, typename Strategy>
struct linear_to_areal
{
    typedef typename strategy::distance::services::return_type
        <
            Strategy,
            typename point_type<Linear>::type,
            typename point_type<Areal>::type
        >::type return_type;

    static inline return_type apply(Linear const& linear,
                                    Areal const& areal,
                                    Strategy const& strategy)
    {
<<<<<<< HEAD
        if ( geometry::intersects(linear, areal) )
=======
        if ( geometry::intersects(linear, areal,
                                  strategy.get_relate_segment_segment_strategy()) )
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            return 0;
        }

        return linear_to_linear
            <
                Linear, Areal, Strategy
            >::apply(linear, areal, strategy, false);
    }


    static inline return_type apply(Areal const& areal,
                                    Linear const& linear,
                                    Strategy const& strategy)
    {
        return apply(linear, areal, strategy);
    }
};

<<<<<<< HEAD

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
template <typename Areal1, typename Areal2, typename Strategy>
struct areal_to_areal
{
    typedef typename strategy::distance::services::return_type
        <
            Strategy,
            typename point_type<Areal1>::type,
            typename point_type<Areal2>::type
        >::type return_type;

    static inline return_type apply(Areal1 const& areal1,
                                    Areal2 const& areal2,
                                    Strategy const& strategy)
    {
<<<<<<< HEAD
        if ( geometry::intersects(areal1, areal2) )
=======
        if ( geometry::intersects(areal1, areal2,
                                  strategy.get_relate_segment_segment_strategy()) )
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            return 0;
        }

        return linear_to_linear
            <
                Areal1, Areal2, Strategy
            >::apply(areal1, areal2, strategy, false);
    }
};


}} // namespace detail::distance
#endif // DOXYGEN_NO_DETAIL


#ifndef DOXYGEN_NO_DISPATCH
namespace dispatch
{

template <typename Linear, typename Areal, typename Strategy>
struct distance
    <
        Linear, Areal, Strategy,
        linear_tag, areal_tag, 
        strategy_tag_distance_point_segment, false
    >
    : detail::distance::linear_to_areal
        <
            Linear, Areal, Strategy
        >
{};

<<<<<<< HEAD

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
template <typename Areal, typename Linear, typename Strategy>
struct distance
    <
        Areal, Linear, Strategy,
        areal_tag, linear_tag, 
        strategy_tag_distance_point_segment, false
    >
    : detail::distance::linear_to_areal
        <
            Linear, Areal, Strategy
        >
{};


template <typename Areal1, typename Areal2, typename Strategy>
struct distance
    <
        Areal1, Areal2, Strategy,
        areal_tag, areal_tag, 
        strategy_tag_distance_point_segment, false
    >
    : detail::distance::areal_to_areal
        <
            Areal1, Areal2, Strategy
        >
{};


} // namespace dispatch
#endif // DOXYGEN_NO_DISPATCH

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_DISTANCE_LINEAR_OR_AREAL_TO_AREAL_HPP
