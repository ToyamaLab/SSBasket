// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2012 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2012 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2012 Mateusz Loskot, London, UK.
<<<<<<< HEAD

// This file was modified by Oracle on 2017.
// Modifications copyright (c) 2017 Oracle and/or its affiliates.
=======
// Copyright (c) 2017 Adam Wulkiewicz, Lodz, Poland.

// This file was modified by Oracle on 2017, 2018.
// Modifications copyright (c) 2017-2018 Oracle and/or its affiliates.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Parts of Boost.Geometry are redesigned from Geodan's Geographic Library
// (geolib/GGL), copyright (c) 1995-2010 Geodan, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ALGORITHMS_AREA_HPP
#define BOOST_GEOMETRY_ALGORITHMS_AREA_HPP

#include <boost/concept_check.hpp>
<<<<<<< HEAD
#include <boost/mpl/if.hpp>
=======
#include <boost/core/ignore_unused.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#include <boost/range/functions.hpp>
#include <boost/range/metafunctions.hpp>

#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/static_visitor.hpp>
#include <boost/variant/variant_fwd.hpp>

#include <boost/geometry/core/closure.hpp>
#include <boost/geometry/core/exterior_ring.hpp>
#include <boost/geometry/core/interior_rings.hpp>
#include <boost/geometry/core/point_order.hpp>
#include <boost/geometry/core/point_type.hpp>
#include <boost/geometry/core/ring_type.hpp>
#include <boost/geometry/core/tags.hpp>

#include <boost/geometry/geometries/concepts/check.hpp>

#include <boost/geometry/algorithms/detail/calculate_null.hpp>
#include <boost/geometry/algorithms/detail/calculate_sum.hpp>
// #include <boost/geometry/algorithms/detail/throw_on_empty_input.hpp>
#include <boost/geometry/algorithms/detail/multi_sum.hpp>

#include <boost/geometry/strategies/area.hpp>
<<<<<<< HEAD
#include <boost/geometry/strategies/default_area_result.hpp>
=======
#include <boost/geometry/strategies/area_result.hpp>
#include <boost/geometry/strategies/default_area_result.hpp>
#include <boost/geometry/strategies/default_strategy.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#include <boost/geometry/strategies/concepts/area_concept.hpp>

#include <boost/geometry/util/math.hpp>
#include <boost/geometry/util/order_as_direction.hpp>
#include <boost/geometry/views/closeable_view.hpp>
#include <boost/geometry/views/reversible_view.hpp>


namespace boost { namespace geometry
{

<<<<<<< HEAD
=======

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace area
{

struct box_area
{
    template <typename Box, typename Strategy>
    static inline typename coordinate_type<Box>::type
    apply(Box const& box, Strategy const&)
    {
        // Currently only works for 2D Cartesian boxes
        assert_dimension<Box, 2>();

        return (get<max_corner, 0>(box) - get<min_corner, 0>(box))
             * (get<max_corner, 1>(box) - get<min_corner, 1>(box));
    }
};


template
<
    iterate_direction Direction,
    closure_selector Closure
>
struct ring_area
{
    template <typename Ring, typename Strategy>
<<<<<<< HEAD
    static inline typename Strategy::return_type
    apply(Ring const& ring, Strategy const& strategy)
    {
        BOOST_CONCEPT_ASSERT( (geometry::concepts::AreaStrategy<Strategy>) );
        assert_dimension<Ring, 2>();

        // Ignore warning (because using static method sometimes) on strategy
        boost::ignore_unused_variable_warning(strategy);
=======
    static inline typename area_result<Ring, Strategy>::type
    apply(Ring const& ring, Strategy const& strategy)
    {
        BOOST_CONCEPT_ASSERT( (geometry::concepts::AreaStrategy<Ring, Strategy>) );
        assert_dimension<Ring, 2>();

        // Ignore warning (because using static method sometimes) on strategy
        boost::ignore_unused(strategy);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

        // An open ring has at least three points,
        // A closed ring has at least four points,
        // if not, there is no (zero) area
        if (boost::size(ring)
                < core_detail::closure::minimum_ring_size<Closure>::value)
        {
<<<<<<< HEAD
            return typename Strategy::return_type();
=======
            return typename area_result<Ring, Strategy>::type();
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }

        typedef typename reversible_view<Ring const, Direction>::type rview_type;
        typedef typename closeable_view
            <
                rview_type const, Closure
            >::type view_type;
        typedef typename boost::range_iterator<view_type const>::type iterator_type;

        rview_type rview(ring);
        view_type view(rview);
<<<<<<< HEAD
        typename Strategy::state_type state;
=======
        typename Strategy::template state<Ring> state;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        iterator_type it = boost::begin(view);
        iterator_type end = boost::end(view);

        for (iterator_type previous = it++;
            it != end;
            ++previous, ++it)
        {
            strategy.apply(*previous, *it, state);
        }

        return strategy.result(state);
    }
};


}} // namespace detail::area


#endif // DOXYGEN_NO_DETAIL


#ifndef DOXYGEN_NO_DISPATCH
namespace dispatch
{

template
<
    typename Geometry,
    typename Tag = typename tag<Geometry>::type
>
struct area : detail::calculate_null
{
    template <typename Strategy>
<<<<<<< HEAD
    static inline typename Strategy::return_type apply(Geometry const& geometry, Strategy const& strategy)
    {
        return calculate_null::apply<typename Strategy::return_type>(geometry, strategy);
=======
    static inline typename area_result<Geometry, Strategy>::type
        apply(Geometry const& geometry, Strategy const& strategy)
    {
        return calculate_null::apply
            <
                typename area_result<Geometry, Strategy>::type
            >(geometry, strategy);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
};


template <typename Geometry>
struct area<Geometry, box_tag> : detail::area::box_area
{};


template <typename Ring>
struct area<Ring, ring_tag>
    : detail::area::ring_area
        <
            order_as_direction<geometry::point_order<Ring>::value>::value,
            geometry::closure<Ring>::value
        >
{};


template <typename Polygon>
struct area<Polygon, polygon_tag> : detail::calculate_polygon_sum
{
    template <typename Strategy>
<<<<<<< HEAD
    static inline typename Strategy::return_type apply(Polygon const& polygon, Strategy const& strategy)
    {
        return calculate_polygon_sum::apply<
            typename Strategy::return_type,
=======
    static inline typename area_result<Polygon, Strategy>::type
        apply(Polygon const& polygon, Strategy const& strategy)
    {
        return calculate_polygon_sum::apply<
            typename area_result<Polygon, Strategy>::type,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            detail::area::ring_area
                <
                    order_as_direction<geometry::point_order<Polygon>::value>::value,
                    geometry::closure<Polygon>::value
                >
            >(polygon, strategy);
    }
};


template <typename MultiGeometry>
struct area<MultiGeometry, multi_polygon_tag> : detail::multi_sum
{
    template <typename Strategy>
<<<<<<< HEAD
    static inline typename Strategy::return_type
=======
    static inline typename area_result<MultiGeometry, Strategy>::type
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    apply(MultiGeometry const& multi, Strategy const& strategy)
    {
        return multi_sum::apply
               <
<<<<<<< HEAD
                   typename Strategy::return_type,
=======
                   typename area_result<MultiGeometry, Strategy>::type,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                   area<typename boost::range_value<MultiGeometry>::type>
               >(multi, strategy);
    }
};


} // namespace dispatch
#endif // DOXYGEN_NO_DISPATCH


<<<<<<< HEAD
namespace resolve_variant {
=======
namespace resolve_strategy
{

template <typename Strategy>
struct area
{
    template <typename Geometry>
    static inline typename area_result<Geometry, Strategy>::type
    apply(Geometry const& geometry, Strategy const& strategy)
    {
        return dispatch::area<Geometry>::apply(geometry, strategy);
    }
};

template <>
struct area<default_strategy>
{
    template <typename Geometry>
    static inline typename area_result<Geometry>::type
    apply(Geometry const& geometry, default_strategy)
    {
        typedef typename strategy::area::services::default_strategy
            <
                typename cs_tag<Geometry>::type
            >::type strategy_type;

        return dispatch::area<Geometry>::apply(geometry, strategy_type());
    }
};


} // namespace resolve_strategy


namespace resolve_variant
{
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

template <typename Geometry>
struct area
{
    template <typename Strategy>
<<<<<<< HEAD
    static inline typename Strategy::return_type apply(Geometry const& geometry,
                                                       Strategy const& strategy)
    {
        return dispatch::area<Geometry>::apply(geometry, strategy);
=======
    static inline typename area_result<Geometry, Strategy>::type
        apply(Geometry const& geometry, Strategy const& strategy)
    {
        return resolve_strategy::area<Strategy>::apply(geometry, strategy);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    }
};

template <BOOST_VARIANT_ENUM_PARAMS(typename T)>
struct area<boost::variant<BOOST_VARIANT_ENUM_PARAMS(T)> >
{
<<<<<<< HEAD
    template <typename Strategy>
    struct visitor: boost::static_visitor<typename Strategy::return_type>
=======
    typedef boost::variant<BOOST_VARIANT_ENUM_PARAMS(T)> variant_type;

    template <typename Strategy>
    struct visitor
        : boost::static_visitor<typename area_result<variant_type, Strategy>::type>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    {
        Strategy const& m_strategy;

        visitor(Strategy const& strategy): m_strategy(strategy) {}

        template <typename Geometry>
<<<<<<< HEAD
        typename Strategy::return_type operator()(Geometry const& geometry) const
=======
        typename area_result<variant_type, Strategy>::type
        operator()(Geometry const& geometry) const
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        {
            return area<Geometry>::apply(geometry, m_strategy);
        }
    };

    template <typename Strategy>
<<<<<<< HEAD
    static inline typename Strategy::return_type
    apply(boost::variant<BOOST_VARIANT_ENUM_PARAMS(T)> const& geometry,
=======
    static inline typename area_result<variant_type, Strategy>::type
    apply(variant_type const& geometry,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
          Strategy const& strategy)
    {
        return boost::apply_visitor(visitor<Strategy>(strategy), geometry);
    }
};

} // namespace resolve_variant


/*!
\brief \brief_calc{area}
\ingroup area
\details \details_calc{area}. \details_default_strategy

The area algorithm calculates the surface area of all geometries having a surface, namely
box, polygon, ring, multipolygon. The units are the square of the units used for the points
defining the surface. If subject geometry is defined in meters, then area is calculated
in square meters.

The area calculation can be done in all three common coordinate systems, Cartesian, Spherical
and Geographic as well.

\tparam Geometry \tparam_geometry
\param geometry \param_geometry
\return \return_calc{area}

\qbk{[include reference/algorithms/area.qbk]}
\qbk{[heading Examples]}
\qbk{[area] [area_output]}
*/
template <typename Geometry>
<<<<<<< HEAD
inline typename default_area_result<Geometry>::type area(Geometry const& geometry)
{
    concepts::check<Geometry const>();

    // TODO put this into a resolve_strategy stage
    //      (and take the return type from resolve_variant)
    typedef typename point_type<Geometry>::type point_type;
    typedef typename strategy::area::services::default_strategy
        <
            typename cs_tag<point_type>::type,
            point_type
        >::type strategy_type;

    // detail::throw_on_empty_input(geometry);

    return resolve_variant::area<Geometry>::apply(geometry, strategy_type());
=======
inline typename area_result<Geometry>::type
area(Geometry const& geometry)
{
    concepts::check<Geometry const>();

    // detail::throw_on_empty_input(geometry);

    return resolve_variant::area<Geometry>::apply(geometry, default_strategy());
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
}

/*!
\brief \brief_calc{area} \brief_strategy
\ingroup area
\details \details_calc{area} \brief_strategy. \details_strategy_reasons
\tparam Geometry \tparam_geometry
\tparam Strategy \tparam_strategy{Area}
\param geometry \param_geometry
\param strategy \param_strategy{area}
\return \return_calc{area}

\qbk{distinguish,with strategy}

\qbk{
[include reference/algorithms/area.qbk]

<<<<<<< HEAD
[heading Example]
[area_with_strategy]
[area_with_strategy_output]

[heading Available Strategies]
\* [link geometry.reference.strategies.strategy_area_surveyor Surveyor (cartesian)]
\* [link geometry.reference.strategies.strategy_area_spherical Spherical]
[/link geometry.reference.strategies.strategy_area_geographic Geographic]
}
 */
template <typename Geometry, typename Strategy>
inline typename Strategy::return_type area(
        Geometry const& geometry, Strategy const& strategy)
=======
[heading Available Strategies]
\* [link geometry.reference.strategies.strategy_area_cartesian Cartesian]
\* [link geometry.reference.strategies.strategy_area_spherical Spherical]
\* [link geometry.reference.strategies.strategy_area_geographic Geographic]

[heading Example]
[area_with_strategy]
[area_with_strategy_output]
}
 */
template <typename Geometry, typename Strategy>
inline typename area_result<Geometry, Strategy>::type
area(Geometry const& geometry, Strategy const& strategy)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
{
    concepts::check<Geometry const>();

    // detail::throw_on_empty_input(geometry);

    return resolve_variant::area<Geometry>::apply(geometry, strategy);
}


}} // namespace boost::geometry


#endif // BOOST_GEOMETRY_ALGORITHMS_AREA_HPP
