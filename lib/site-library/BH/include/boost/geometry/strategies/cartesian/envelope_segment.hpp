// Boost.Geometry (aka GGL, Generic Geometry Library)

<<<<<<< HEAD
// Copyright (c) 2017 Oracle and/or its affiliates.
=======
// Copyright (c) 2017-2018 Oracle and/or its affiliates.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
// Contributed and/or modified by Vissarion Fisikopoulos, on behalf of Oracle
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_STRATEGIES_CARTESIAN_ENVELOPE_SEGMENT_HPP
#define BOOST_GEOMETRY_STRATEGIES_CARTESIAN_ENVELOPE_SEGMENT_HPP

<<<<<<< HEAD

#include <boost/geometry/algorithms/detail/envelope/segment.hpp>
#include <boost/geometry/core/tags.hpp>
#include <boost/geometry/strategies/envelope.hpp>
#include <boost/geometry/util/select_calculation_type.hpp>


namespace boost { namespace geometry
{

namespace strategy { namespace envelope
{
=======
#include <cstddef>

#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/core/tags.hpp>

#include <boost/geometry/strategies/cartesian/envelope_point.hpp>
#include <boost/geometry/strategies/cartesian/expand_point.hpp>
#include <boost/geometry/strategies/envelope.hpp>

namespace boost { namespace geometry { namespace strategy { namespace envelope
{

#ifndef DOXYGEN_NO_DETAIL
namespace detail
{

template <std::size_t Dimension, std::size_t DimensionCount>
struct envelope_one_segment
{
    template<typename Point, typename Box>
    static inline void apply(Point const& p1,
                             Point const& p2,
                             Box& mbr)
    {
        geometry::detail::envelope::envelope_one_point
            <
                Dimension, DimensionCount
            >::apply(p1, mbr);

        strategy::expand::detail::point_loop
            <
                Dimension, DimensionCount
            >::apply(mbr, p2);
    }
};

} // namespace detail
#endif // DOXYGEN_NO_DETAIL

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

template
<
    typename CalculationType = void
>
class cartesian_segment
{
<<<<<<< HEAD
public :

    template <typename Point1, typename Point2, typename Box>
    inline void
    apply(Point1 const& point1, Point2 const& point2, Box& box) const
    {
        geometry::detail::envelope::envelope_one_segment
                <
                    0,
                    dimension<Point1>::value
                >
                ::apply(point1,
                        point2,
                        box,
                        strategy::envelope::cartesian_segment<CalculationType>());
=======
public:
    template <typename Point, typename Box>
    static inline void apply(Point const& point1, Point const& point2, Box& box)
    {
        strategy::envelope::detail::envelope_one_segment
            <
                0,
                dimension<Point>::value
            >::apply(point1, point2, box);        
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }

};

#ifndef DOXYGEN_NO_STRATEGY_SPECIALIZATIONS

namespace services
{

template <typename CalculationType>
<<<<<<< HEAD
struct default_strategy<cartesian_tag, CalculationType>
=======
struct default_strategy<segment_tag, cartesian_tag, CalculationType>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    typedef strategy::envelope::cartesian_segment<CalculationType> type;
};

}

#endif // DOXYGEN_NO_STRATEGY_SPECIALIZATIONS


}} // namespace strategy::envelope

}} //namepsace boost::geometry

#endif // BOOST_GEOMETRY_STRATEGIES_CARTESIAN_ENVELOPE_SEGMENT_HPP
