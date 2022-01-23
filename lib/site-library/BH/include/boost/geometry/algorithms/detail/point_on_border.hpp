// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2012 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2012 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2012 Mateusz Loskot, London, UK.

<<<<<<< HEAD
// This file was modified by Oracle on 2017.
// Modifications copyright (c) 2017 Oracle and/or its affiliates.
=======
// This file was modified by Oracle on 2017, 2018.
// Modifications copyright (c) 2017-2018 Oracle and/or its affiliates.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Parts of Boost.Geometry are redesigned from Geodan's Geographic Library
// (geolib/GGL), copyright (c) 1995-2010 Geodan, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.Dimension. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_POINT_ON_BORDER_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_POINT_ON_BORDER_HPP


#include <cstddef>

#include <boost/range.hpp>
#include <boost/static_assert.hpp>

#include <boost/geometry/core/tags.hpp>
#include <boost/geometry/core/point_type.hpp>
#include <boost/geometry/core/ring_type.hpp>

#include <boost/geometry/geometries/concepts/check.hpp>

#include <boost/geometry/algorithms/assign.hpp>
#include <boost/geometry/algorithms/detail/convert_point_to_point.hpp>
#include <boost/geometry/algorithms/detail/equals/point_point.hpp>

#include <boost/geometry/util/condition.hpp>


namespace boost { namespace geometry
{


#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace point_on_border
{


struct get_point
{
    template <typename Point>
    static inline bool apply(Point& destination, Point const& source)
    {
        destination = source;
        return true;
    }
};

<<<<<<< HEAD
template<typename Point, std::size_t Dimension, std::size_t DimensionCount>
struct midpoint_helper
{
    template <typename InputPoint>
    static inline bool apply(Point& p, InputPoint const& p1, InputPoint const& p2)
    {
        typename coordinate_type<Point>::type const two = 2;
        set<Dimension>(p,
                    (get<Dimension>(p1) + get<Dimension>(p2)) / two);
        return midpoint_helper<Point, Dimension + 1, DimensionCount>::apply(p, p1, p2);
    }
};


template <typename Point, std::size_t DimensionCount>
struct midpoint_helper<Point, DimensionCount, DimensionCount>
{
    template <typename InputPoint>
    static inline bool apply(Point& , InputPoint const& , InputPoint const& )
    {
        return true;
    }
};


template <bool Midpoint>
=======

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
struct point_on_range
{
    // Version with iterator
    template<typename Point, typename Iterator>
    static inline bool apply(Point& point, Iterator begin, Iterator end)
    {
<<<<<<< HEAD
        Iterator it = begin;
        if (it == end)
=======
        if (begin == end)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            return false;
        }

<<<<<<< HEAD
        if (! Midpoint)
        {
            geometry::detail::conversion::convert_point_to_point(*it, point);
            return true;
        }

        Iterator prev = it++;

        // Go to next non-duplicate point
        while (it != end
            && detail::equals::equals_point_point(*it, *prev))
        {
            prev = it++;
        }
        if (it != end)
        {
            return midpoint_helper
                <
                    Point,
                    0, dimension<Point>::value
                >::apply(point, *prev, *it);
        }
        return false;
=======
        geometry::detail::conversion::convert_point_to_point(*begin, point);
        return true;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }

    // Version with range
    template<typename Point, typename Range>
    static inline bool apply(Point& point, Range const& range)
    {
<<<<<<< HEAD
        typedef typename geometry::cs_tag<Point>::type cs_tag;
        BOOST_STATIC_ASSERT((! Midpoint || boost::is_same<cs_tag, cartesian_tag>::value));

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        return apply(point, boost::begin(range), boost::end(range));
    }
};


<<<<<<< HEAD
template <bool Midpoint>
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
struct point_on_polygon
{
    template<typename Point, typename Polygon>
    static inline bool apply(Point& point, Polygon const& polygon)
    {
<<<<<<< HEAD
        return point_on_range
            <
                Midpoint
            >::apply(point, exterior_ring(polygon));
=======
        return point_on_range::apply(point, exterior_ring(polygon));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
};


<<<<<<< HEAD
template <bool Midpoint>
=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
struct point_on_box
{
    template<typename Point, typename Box>
    static inline bool apply(Point& point, Box const& box)
    {
<<<<<<< HEAD
        if (BOOST_GEOMETRY_CONDITION(Midpoint))
        {
            Point p1, p2;
            detail::assign::assign_box_2d_corner<min_corner, min_corner>(box, p1);
            detail::assign::assign_box_2d_corner<max_corner, min_corner>(box, p2);
            midpoint_helper
                <
                    Point,
                    0, dimension<Point>::value
                >::apply(point, p1, p2);
        }
        else
        {
            detail::assign::assign_box_2d_corner<min_corner, min_corner>(box, point);
        }

=======
        detail::assign::assign_box_2d_corner<min_corner, min_corner>(box, point);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        return true;
    }
};


template <typename Policy>
struct point_on_multi
{
    template<typename Point, typename MultiGeometry>
    static inline bool apply(Point& point, MultiGeometry const& multi)
    {
        // Take a point on the first multi-geometry
        // (i.e. the first that is not empty)
        for (typename boost::range_iterator
                <
                    MultiGeometry const
                >::type it = boost::begin(multi);
            it != boost::end(multi);
            ++it)
        {
            if (Policy::apply(point, *it))
            {
                return true;
            }
        }
        return false;
    }
};


}} // namespace detail::point_on_border
#endif // DOXYGEN_NO_DETAIL


#ifndef DOXYGEN_NO_DISPATCH
namespace dispatch
{


<<<<<<< HEAD
template
<
    typename GeometryTag,
    bool Midpoint

>
struct point_on_border
{};


template <bool Midpoint>
struct point_on_border<point_tag, Midpoint>
    : detail::point_on_border::get_point
{};


template <bool Midpoint>
struct point_on_border<linestring_tag, Midpoint>
    : detail::point_on_border::point_on_range<Midpoint>
{};


template <bool Midpoint>
struct point_on_border<ring_tag, Midpoint>
    : detail::point_on_border::point_on_range<Midpoint>
{};


template <bool Midpoint>
struct point_on_border<polygon_tag, Midpoint>
    : detail::point_on_border::point_on_polygon<Midpoint>
{};


template <bool Midpoint>
struct point_on_border<box_tag, Midpoint>
    : detail::point_on_border::point_on_box<Midpoint>
{};


template <bool Midpoint>
struct point_on_border<multi_polygon_tag, Midpoint>
    : detail::point_on_border::point_on_multi
        <
            detail::point_on_border::point_on_polygon<Midpoint>
=======
template <typename GeometryTag>
struct point_on_border
{};

template <>
struct point_on_border<point_tag>
    : detail::point_on_border::get_point
{};

template <>
struct point_on_border<linestring_tag>
    : detail::point_on_border::point_on_range
{};

template <>
struct point_on_border<ring_tag>
    : detail::point_on_border::point_on_range
{};

template <>
struct point_on_border<polygon_tag>
    : detail::point_on_border::point_on_polygon
{};

template <>
struct point_on_border<box_tag>
    : detail::point_on_border::point_on_box
{};


template <>
struct point_on_border<multi_polygon_tag>
    : detail::point_on_border::point_on_multi
        <
            detail::point_on_border::point_on_polygon
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        >
{};


<<<<<<< HEAD
template <bool Midpoint>
struct point_on_border<multi_linestring_tag, Midpoint>
    : detail::point_on_border::point_on_multi
        <
            detail::point_on_border::point_on_range<Midpoint>
=======
template <>
struct point_on_border<multi_linestring_tag>
    : detail::point_on_border::point_on_multi
        <
            detail::point_on_border::point_on_range
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        >
{};


} // namespace dispatch
#endif // DOXYGEN_NO_DISPATCH


/*!
\brief Take point on a border
\ingroup overlay
\tparam Geometry geometry type. This also defines the type of the output point
\param point to assign
\param geometry geometry to take point from
\return TRUE if successful, else false.
    It is only false if polygon/line have no points
\note for a polygon, it is always a point on the exterior ring
 */
template <typename Point, typename Geometry>
inline bool point_on_border(Point& point, Geometry const& geometry)
{
    concepts::check<Point>();
    concepts::check<Geometry const>();

    return dispatch::point_on_border
            <
<<<<<<< HEAD
                typename tag<Geometry>::type,
                false
=======
                typename tag<Geometry>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::apply(point, geometry);
}


<<<<<<< HEAD
/*!
\tparam Midpoint boolean flag, true if the point should not be a vertex, but some point
    in between of two vertices
\note for Midpoint, it is not taken from two consecutive duplicate vertices,
    (unless there are no other).
 */
/*
template <bool Midpoint, typename Point, typename Geometry>
inline bool point_on_border(Point& point, Geometry const& geometry)
{
    concepts::check<Point>();
    concepts::check<Geometry const>();

    return dispatch::point_on_border
            <
                typename tag<Geometry>::type,
                Midpoint
            >::apply(point, geometry);
}
*/

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}} // namespace boost::geometry


#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_POINT_ON_BORDER_HPP
