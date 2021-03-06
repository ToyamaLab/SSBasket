// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2015 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2015 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2015 Mateusz Loskot, London, UK.
// Copyright (c) 2014-2015 Samuel Debionne, Grenoble, France.

<<<<<<< HEAD
// This file was modified by Oracle on 2015, 2016, 2017.
// Modifications copyright (c) 2015-2017, Oracle and/or its affiliates.
=======
// This file was modified by Oracle on 2015-2018.
// Modifications copyright (c) 2015-2018, Oracle and/or its affiliates.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// Contributed and/or modified by Vissarion Fysikopoulos, on behalf of Oracle
// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Parts of Boost.Geometry are redesigned from Geodan's Geographic Library
// (geolib/GGL), copyright (c) 1995-2010 Geodan, Amsterdam, the Netherlands.

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_EXPAND_POINT_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_EXPAND_POINT_HPP

<<<<<<< HEAD
#include <cstddef>
#include <algorithm>
#include <functional>

#include <boost/mpl/assert.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/geometry/core/access.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/core/coordinate_system.hpp>
#include <boost/geometry/core/coordinate_type.hpp>
#include <boost/geometry/core/tags.hpp>

#include <boost/geometry/util/math.hpp>
#include <boost/geometry/util/select_coordinate_type.hpp>

#include <boost/geometry/algorithms/detail/normalize.hpp>
#include <boost/geometry/algorithms/detail/envelope/transform_units.hpp>

#include <boost/geometry/algorithms/dispatch/expand.hpp>
=======

#include <boost/geometry/algorithms/dispatch/expand.hpp>

#include <boost/geometry/core/tags.hpp>

// For backward compatibility
#include <boost/geometry/strategies/cartesian/expand_point.hpp>
#include <boost/geometry/strategies/spherical/expand_point.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce


namespace boost { namespace geometry
{

<<<<<<< HEAD
#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace expand
{


template <std::size_t Dimension, std::size_t DimensionCount>
struct point_loop
{
    template <typename Box, typename Point, typename Strategy>
    static inline void apply(Box& box, Point const& source, Strategy const& strategy)
    {
        typedef typename select_coordinate_type
            <
                Point, Box
            >::type coordinate_type;

        std::less<coordinate_type> less;
        std::greater<coordinate_type> greater;

        coordinate_type const coord = get<Dimension>(source);

        if (less(coord, get<min_corner, Dimension>(box)))
        {
            set<min_corner, Dimension>(box, coord);
        }

        if (greater(coord, get<max_corner, Dimension>(box)))
        {
            set<max_corner, Dimension>(box, coord);
        }

        point_loop<Dimension + 1, DimensionCount>::apply(box, source, strategy);
    }
};


template <std::size_t DimensionCount>
struct point_loop<DimensionCount, DimensionCount>
{
    template <typename Box, typename Point, typename Strategy>
    static inline void apply(Box&, Point const&, Strategy const&) {}
};


// implementation for the spherical and geographic coordinate systems
template <std::size_t DimensionCount, bool IsEquatorial = true>
struct point_loop_on_spheroid
{
    template <typename Box, typename Point, typename Strategy>
    static inline void apply(Box& box,
                             Point const& point,
                             Strategy const& strategy)
    {
        typedef typename point_type<Box>::type box_point_type;
        typedef typename coordinate_type<Box>::type box_coordinate_type;
        typedef typename coordinate_system<Box>::type::units units_type;

        typedef math::detail::constants_on_spheroid
            <
                box_coordinate_type,
                units_type
            > constants;

        // normalize input point and input box
        Point p_normalized = detail::return_normalized<Point>(point);
        detail::normalize(box, box);

        // transform input point to be of the same type as the box point
        box_point_type box_point;
        detail::envelope::transform_units(p_normalized, box_point);

        box_coordinate_type p_lon = geometry::get<0>(box_point);
        box_coordinate_type p_lat = geometry::get<1>(box_point);

        typename coordinate_type<Box>::type
            b_lon_min = geometry::get<min_corner, 0>(box),
            b_lat_min = geometry::get<min_corner, 1>(box),
            b_lon_max = geometry::get<max_corner, 0>(box),
            b_lat_max = geometry::get<max_corner, 1>(box);

        if (math::is_latitude_pole<units_type, IsEquatorial>(p_lat))
        {
            // the point of expansion is the either the north or the
            // south pole; the only important coordinate here is the
            // pole's latitude, as the longitude can be anything;
            // we, thus, take into account the point's latitude only and return
            geometry::set<min_corner, 1>(box, (std::min)(p_lat, b_lat_min));
            geometry::set<max_corner, 1>(box, (std::max)(p_lat, b_lat_max));
            return;
        }

        if (math::equals(b_lat_min, b_lat_max)
            && math::is_latitude_pole<units_type, IsEquatorial>(b_lat_min))
        {
            // the box degenerates to either the north or the south pole;
            // the only important coordinate here is the pole's latitude, 
            // as the longitude can be anything;
            // we thus take into account the box's latitude only and return
            geometry::set<min_corner, 0>(box, p_lon);
            geometry::set<min_corner, 1>(box, (std::min)(p_lat, b_lat_min));
            geometry::set<max_corner, 0>(box, p_lon);
            geometry::set<max_corner, 1>(box, (std::max)(p_lat, b_lat_max));
            return;
        }

        // update latitudes
        b_lat_min = (std::min)(b_lat_min, p_lat);
        b_lat_max = (std::max)(b_lat_max, p_lat);

        // update longitudes
        if (math::smaller(p_lon, b_lon_min))
        {
            box_coordinate_type p_lon_shifted = p_lon + constants::period();

            if (math::larger(p_lon_shifted, b_lon_max))
            {
                // here we could check using: ! math::larger(.., ..)
                if (math::smaller(b_lon_min - p_lon, p_lon_shifted - b_lon_max))
                {
                    b_lon_min = p_lon;
                }
                else
                {
                    b_lon_max = p_lon_shifted;
                }
            }
        }
        else if (math::larger(p_lon, b_lon_max))
        {
            // in this case, and since p_lon is normalized in the range
            // (-180, 180], we must have that b_lon_max <= 180
            if (b_lon_min < 0
                && math::larger(p_lon - b_lon_max,
                                constants::period() - p_lon + b_lon_min))
            {
                b_lon_min = p_lon;
                b_lon_max += constants::period();
            }
            else
            {
                b_lon_max = p_lon;
            }
        }

        geometry::set<min_corner, 0>(box, b_lon_min);
        geometry::set<min_corner, 1>(box, b_lat_min);
        geometry::set<max_corner, 0>(box, b_lon_max);
        geometry::set<max_corner, 1>(box, b_lat_max);

        point_loop
            <
                2, DimensionCount
            >::apply(box, point, strategy);
    }
};


}} // namespace detail::expand
#endif // DOXYGEN_NO_DETAIL

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#ifndef DOXYGEN_NO_DISPATCH
namespace dispatch
{


// Box + point -> new box containing also point
template
<
<<<<<<< HEAD
    typename BoxOut, typename Point,
    typename CSTagOut, typename CSTag
=======
    typename BoxOut, typename Point
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
>
struct expand
    <
        BoxOut, Point,
<<<<<<< HEAD
        box_tag, point_tag,
        CSTagOut, CSTag
    >
{
    BOOST_MPL_ASSERT_MSG((false),
                         NOT_IMPLEMENTED_FOR_THESE_COORDINATE_SYSTEMS,
                         (types<CSTagOut, CSTag>()));
};


template <typename BoxOut, typename Point>
struct expand
    <
        BoxOut, Point,
        box_tag, point_tag,
        cartesian_tag, cartesian_tag
    > : detail::expand::point_loop
        <
            0, dimension<Point>::value
        >
{};

template <typename BoxOut, typename Point>
struct expand
    <
        BoxOut, Point,
        box_tag, point_tag,
        spherical_equatorial_tag, spherical_equatorial_tag
    > : detail::expand::point_loop_on_spheroid
        <
            dimension<Point>::value
        >
{};

template <typename BoxOut, typename Point>
struct expand
    <
        BoxOut, Point,
        box_tag, point_tag,
        spherical_polar_tag, spherical_polar_tag
    > : detail::expand::point_loop_on_spheroid
        <
            dimension<Point>::value,
            false
        >
{};

template
<
    typename BoxOut, typename Point
>
struct expand
    <
        BoxOut, Point,
        box_tag, point_tag,
        geographic_tag, geographic_tag
    > : detail::expand::point_loop_on_spheroid
        <
            dimension<Point>::value
        >
{};

=======
        box_tag, point_tag
    >
{
    template <typename Strategy>
    static inline void apply(BoxOut& box,
                             Point const& point,
                             Strategy const& )
    {
        Strategy::apply(box, point);
    }
};


>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

} // namespace dispatch
#endif // DOXYGEN_NO_DISPATCH

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_EXPAND_POINT_HPP
