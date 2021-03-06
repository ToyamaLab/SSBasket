// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2015 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2015 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2015 Mateusz Loskot, London, UK.
// Copyright (c) 2013-2015 Adam Wulkiewicz, Lodz, Poland.

<<<<<<< HEAD
// This file was modified by Oracle on 2015, 2016, 2017.
// Modifications copyright (c) 2016-2017, Oracle and/or its affiliates.
=======
// This file was modified by Oracle on 2015, 2016, 2017, 2019.
// Modifications copyright (c) 2016-2019, Oracle and/or its affiliates.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Parts of Boost.Geometry are redesigned from Geodan's Geographic Library
// (geolib/GGL), copyright (c) 1995-2010 Geodan, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_STRATEGIES_CARTESIAN_BOX_IN_BOX_HPP
#define BOOST_GEOMETRY_STRATEGIES_CARTESIAN_BOX_IN_BOX_HPP


#include <boost/geometry/core/access.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/strategies/covered_by.hpp>
#include <boost/geometry/strategies/within.hpp>
#include <boost/geometry/util/normalize_spheroidal_coordinates.hpp>


namespace boost { namespace geometry { namespace strategy
{


namespace within
{


<<<<<<< HEAD
=======
#ifndef DOXYGEN_NO_DETAIL
namespace detail
{


>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
struct box_within_coord
{
    template <typename BoxContainedValue, typename BoxContainingValue>
    static inline bool apply(BoxContainedValue const& bed_min,
                             BoxContainedValue const& bed_max,
                             BoxContainingValue const& bing_min,
                             BoxContainingValue const& bing_max)
    {
        return bing_min <= bed_min && bed_max <= bing_max // contained in containing
            && bed_min < bed_max;                         // interiors overlap
    }
};


struct box_covered_by_coord
{
    template <typename BoxContainedValue, typename BoxContainingValue>
    static inline bool apply(BoxContainedValue const& bed_min,
                             BoxContainedValue const& bed_max,
                             BoxContainingValue const& bing_min,
                             BoxContainingValue const& bing_max)
    {
        return bed_min >= bing_min && bed_max <= bing_max;
    }
};


<<<<<<< HEAD
template <typename Geometry, std::size_t Dimension, typename CSTag>
struct box_within_range
    : box_within_coord
{};


template <typename Geometry, std::size_t Dimension, typename CSTag>
struct box_covered_by_range
    : box_covered_by_coord
{};


=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
struct box_within_longitude_diff
{
    template <typename CalcT>
    static inline bool apply(CalcT const& diff_ed)
    {
        return diff_ed > CalcT(0);
    }
};

struct box_covered_by_longitude_diff
{
    template <typename CalcT>
    static inline bool apply(CalcT const&)
    {
        return true;
    }
};

template <typename Geometry,
          typename CoordCheck,
          typename InteriorCheck>
struct box_longitude_range
{
    template <typename BoxContainedValue, typename BoxContainingValue>
    static inline bool apply(BoxContainedValue const& bed_min,
                             BoxContainedValue const& bed_max,
                             BoxContainingValue const& bing_min,
                             BoxContainingValue const& bing_max)
    {
        typedef typename select_most_precise
            <
                BoxContainedValue,
                BoxContainingValue
            >::type calc_t;
<<<<<<< HEAD
        typedef typename coordinate_system<Geometry>::type::units units_t;
=======
        typedef typename geometry::detail::cs_angular_units<Geometry>::type units_t;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        typedef math::detail::constants_on_spheroid<calc_t, units_t> constants;

        if (CoordCheck::apply(bed_min, bed_max, bing_min, bing_max))
        {
            return true;
        }

        // min <= max <=> diff >= 0
        calc_t const diff_ed = bed_max - bed_min;
        calc_t const diff_ing = bing_max - bing_min;
        
        // if containing covers the whole globe it contains all
        if (diff_ing >= constants::period())
        {
            return true;
        }

        // if containing is smaller it cannot contain
        // and check interior (within vs covered_by)
        if (diff_ing < diff_ed || ! InteriorCheck::apply(diff_ed))
        {
            return false;
        }

        // calculate positive longitude translation with bing_min as origin
        calc_t const diff_min = math::longitude_distance_unsigned<units_t>(bing_min, bed_min);

        // max of contained translated into the containing origin must be lesser than max of containing
        return bing_min + diff_min + diff_ed <= bing_max
            /*|| bing_max - diff_min - diff_ed >= bing_min*/;
    }
};


<<<<<<< HEAD
// spherical_equatorial_tag, spherical_polar_tag and geographic_cat are casted to spherical_tag
template <typename Geometry>
struct box_within_range<Geometry, 0, spherical_tag>
    : box_longitude_range<Geometry, box_within_coord, box_within_longitude_diff>
{};


template <typename Geometry>
struct box_covered_by_range<Geometry, 0, spherical_tag>
    : box_longitude_range<Geometry, box_covered_by_coord, box_covered_by_longitude_diff>
{};


template
<
    template <typename, std::size_t, typename> class SubStrategy,
    typename Box1,
    typename Box2,
=======
template
<
    template <typename, std::size_t, typename> class SubStrategy,
    typename CSTag,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    std::size_t Dimension,
    std::size_t DimensionCount
>
struct relate_box_box_loop
{
<<<<<<< HEAD
    static inline bool apply(Box1 const& b_contained, Box2 const& b_containing)
    {
        assert_dimension_equal<Box1, Box2>();
        typedef typename tag_cast<typename cs_tag<Box1>::type, spherical_tag>::type cs_tag_t;

        if (! SubStrategy<Box1, Dimension, cs_tag_t>::apply(
=======
    template <typename Box1, typename Box2>
    static inline bool apply(Box1 const& b_contained, Box2 const& b_containing)
    {
        assert_dimension_equal<Box1, Box2>();
        
        if (! SubStrategy<Box1, Dimension, CSTag>::apply(
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                    get<min_corner, Dimension>(b_contained),
                    get<max_corner, Dimension>(b_contained),
                    get<min_corner, Dimension>(b_containing),
                    get<max_corner, Dimension>(b_containing)
                )
            )
        {
            return false;
        }

<<<<<<< HEAD
        return relate_box_box_loop
            <
                SubStrategy,
                Box1, Box2,
=======
        return within::detail::relate_box_box_loop
            <
                SubStrategy, CSTag,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
                Dimension + 1, DimensionCount
            >::apply(b_contained, b_containing);
    }
};

template
<
    template <typename, std::size_t, typename> class SubStrategy,
<<<<<<< HEAD
    typename Box1,
    typename Box2,
    std::size_t DimensionCount
>
struct relate_box_box_loop<SubStrategy, Box1, Box2, DimensionCount, DimensionCount>
{
=======
    typename CSTag,
    std::size_t DimensionCount
>
struct relate_box_box_loop<SubStrategy, CSTag, DimensionCount, DimensionCount>
{
    template <typename Box1, typename Box2>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    static inline bool apply(Box1 const& , Box2 const& )
    {
        return true;
    }
};

<<<<<<< HEAD
template
<
    typename Box1,
    typename Box2,
=======

} // namespace detail
#endif // DOXYGEN_NO_DETAIL


// for backward compatibility
template <typename Geometry, std::size_t Dimension, typename CSTag>
struct box_within_range
    : within::detail::box_within_coord
{};


template <typename Geometry, std::size_t Dimension, typename CSTag>
struct box_covered_by_range
    : within::detail::box_covered_by_coord
{};


// spherical_equatorial_tag, spherical_polar_tag and geographic_cat are casted to spherical_tag
template <typename Geometry>
struct box_within_range<Geometry, 0, spherical_tag>
    : within::detail::box_longitude_range
        <
            Geometry,
            within::detail::box_within_coord,
            within::detail::box_within_longitude_diff
        >
{};


template <typename Geometry>
struct box_covered_by_range<Geometry, 0, spherical_tag>
    : within::detail::box_longitude_range
        <
            Geometry,
            within::detail::box_covered_by_coord,
            within::detail::box_covered_by_longitude_diff
        >
{};


// for backward compatibility
template
<
    typename B1,
    typename B2,
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    template <typename, std::size_t, typename> class SubStrategy = box_within_range
>
struct box_in_box
{
<<<<<<< HEAD
    static inline bool apply(Box1 const& box1, Box2 const& box2)
    {
        return relate_box_box_loop
            <
                SubStrategy,
                Box1, Box2, 0, dimension<Box1>::type::value
=======
    template <typename Box1, typename Box2>
    static inline bool apply(Box1 const& box1, Box2 const& box2)
    {
        typedef typename tag_cast
            <
                typename geometry::cs_tag<Box1>::type,
                spherical_tag
            >::type cs_tag;

        return within::detail::relate_box_box_loop
            <
                SubStrategy, cs_tag,
                0, dimension<Box1>::type::value
            >::apply(box1, box2);
    }
};


struct cartesian_box_box
{
    template <typename Box1, typename Box2>
    static inline bool apply(Box1 const& box1, Box2 const& box2)
    {
        return within::detail::relate_box_box_loop
            <
                box_within_range,
                cartesian_tag,
                0, dimension<Box1>::type::value
            >::apply(box1, box2);
    }
};

struct spherical_box_box
{
    template <typename Box1, typename Box2>
    static inline bool apply(Box1 const& box1, Box2 const& box2)
    {
        return within::detail::relate_box_box_loop
            <
                box_within_range,
                spherical_tag,
                0, dimension<Box1>::type::value
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
            >::apply(box1, box2);
    }
};


} // namespace within


<<<<<<< HEAD
=======
namespace covered_by
{


struct cartesian_box_box
{
    template <typename Box1, typename Box2>
    static inline bool apply(Box1 const& box1, Box2 const& box2)
    {
        return within::detail::relate_box_box_loop
            <
                strategy::within::box_covered_by_range,
                cartesian_tag,
                0, dimension<Box1>::type::value
            >::apply(box1, box2);
    }
};

struct spherical_box_box
{
    template <typename Box1, typename Box2>
    static inline bool apply(Box1 const& box1, Box2 const& box2)
    {
        return within::detail::relate_box_box_loop
            <
                strategy::within::box_covered_by_range,
                spherical_tag,
                0, dimension<Box1>::type::value
            >::apply(box1, box2);
    }
};


}


>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#ifndef DOXYGEN_NO_STRATEGY_SPECIALIZATIONS


namespace within { namespace services
{

template <typename BoxContained, typename BoxContaining>
struct default_strategy
    <
        BoxContained, BoxContaining,
        box_tag, box_tag,
        areal_tag, areal_tag,
        cartesian_tag, cartesian_tag
    >
{
<<<<<<< HEAD
    typedef within::box_in_box<BoxContained, BoxContaining> type;
=======
    typedef cartesian_box_box type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

// spherical_equatorial_tag, spherical_polar_tag and geographic_cat are casted to spherical_tag
template <typename BoxContained, typename BoxContaining>
struct default_strategy
    <
        BoxContained, BoxContaining,
        box_tag, box_tag,
        areal_tag, areal_tag,
        spherical_tag, spherical_tag
    >
{
<<<<<<< HEAD
    typedef within::box_in_box<BoxContained, BoxContaining> type;
=======
    typedef spherical_box_box type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};


}} // namespace within::services

namespace covered_by { namespace services
{

template <typename BoxContained, typename BoxContaining>
struct default_strategy
    <
        BoxContained, BoxContaining,
        box_tag, box_tag,
        areal_tag, areal_tag,
        cartesian_tag, cartesian_tag
    >
{
<<<<<<< HEAD
    typedef within::box_in_box
                <
                    BoxContained, BoxContaining,
                    within::box_covered_by_range
                > type;
=======
    typedef cartesian_box_box type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

// spherical_equatorial_tag, spherical_polar_tag and geographic_cat are casted to spherical_tag
template <typename BoxContained, typename BoxContaining>
struct default_strategy
    <
        BoxContained, BoxContaining,
        box_tag, box_tag,
        areal_tag, areal_tag,
        spherical_tag, spherical_tag
    >
{
<<<<<<< HEAD
    typedef within::box_in_box
                <
                    BoxContained, BoxContaining,
                    within::box_covered_by_range
                > type;
=======
    typedef spherical_box_box type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};


}} // namespace covered_by::services


#endif // DOXYGEN_NO_STRATEGY_SPECIALIZATIONS


}}} // namespace boost::geometry::strategy

#endif // BOOST_GEOMETRY_STRATEGIES_CARTESIAN_BOX_IN_BOX_HPP
