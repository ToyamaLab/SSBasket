// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2015 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2015 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2015 Mateusz Loskot, London, UK.
// Copyright (c) 2014-2015 Samuel Debionne, Grenoble, France.

<<<<<<< HEAD
// This file was modified by Oracle on 2015, 2016, 2017.
// Modifications copyright (c) 2015-2017, Oracle and/or its affiliates.
=======
// This file was modified by Oracle on 2015, 2016, 2017, 2018.
// Modifications copyright (c) 2015-2018, Oracle and/or its affiliates.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// Contributed and/or modified by Vissarion Fysikopoulos, on behalf of Oracle
// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_EXPAND_BOX_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_EXPAND_BOX_HPP

<<<<<<< HEAD
#include <cstddef>
#include <algorithm>

#include <boost/mpl/assert.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/core/tags.hpp>

#include <boost/geometry/algorithms/detail/envelope/box.hpp>
#include <boost/geometry/algorithms/detail/envelope/range_of_boxes.hpp>

#include <boost/geometry/algorithms/detail/expand/indexed.hpp>

#include <boost/geometry/algorithms/dispatch/expand.hpp>
=======

#include <boost/geometry/algorithms/dispatch/expand.hpp>

#include <boost/geometry/core/tags.hpp>

// For backward compatibility
#include <boost/geometry/strategies/cartesian/expand_box.hpp>
#include <boost/geometry/strategies/spherical/expand_box.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce


namespace boost { namespace geometry
{

<<<<<<< HEAD
#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace expand
{


struct box_on_spheroid
{
    template <typename BoxOut, typename BoxIn, typename Strategy>
    static inline void apply(BoxOut& box_out,
                             BoxIn const& box_in,
                             Strategy const& strategy)
    {
        // normalize both boxes and convert box-in to be of type of box-out
        BoxOut mbrs[2];
        detail::envelope::envelope_box_on_spheroid::apply(box_in, mbrs[0], strategy);
        detail::envelope::envelope_box_on_spheroid::apply(box_out, mbrs[1], strategy);

        // compute the envelope of the two boxes
        detail::envelope::envelope_range_of_boxes::apply(mbrs, box_out, strategy);
    }
};


}} // namespace detail::expand
#endif // DOXYGEN_NO_DETAIL

=======
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
#ifndef DOXYGEN_NO_DISPATCH
namespace dispatch
{


// Box + box -> new box containing two input boxes
template
<
<<<<<<< HEAD
    typename BoxOut, typename BoxIn,
    typename CSTagOut, typename CSTag
=======
    typename BoxOut, typename BoxIn
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
>
struct expand
    <
        BoxOut, BoxIn,
<<<<<<< HEAD
        box_tag, box_tag,
        CSTagOut, CSTag
    >
{
    BOOST_MPL_ASSERT_MSG((false),
                         NOT_IMPLEMENTED_FOR_THESE_COORDINATE_SYSTEMS,
                         (types<CSTagOut, CSTag>()));
};

template <typename BoxOut, typename BoxIn>
struct expand
    <
        BoxOut, BoxIn,
        box_tag, box_tag,
        cartesian_tag, cartesian_tag
    > : detail::expand::expand_indexed
        <
            0, dimension<BoxIn>::value
        >
{};

template <typename BoxOut, typename BoxIn>
struct expand
    <
        BoxOut, BoxIn,
        box_tag, box_tag,
        spherical_equatorial_tag, spherical_equatorial_tag
    > : detail::expand::box_on_spheroid
{};

template <typename BoxOut, typename BoxIn>
struct expand
    <
        BoxOut, BoxIn,
        box_tag, box_tag,
        spherical_polar_tag, spherical_polar_tag
    > : detail::expand::box_on_spheroid
{};

template <typename BoxOut, typename BoxIn>
struct expand
    <
        BoxOut, BoxIn,
        box_tag, box_tag,
        geographic_tag, geographic_tag
    > : detail::expand::box_on_spheroid
{};
=======
        box_tag, box_tag
    >
{
    template <typename Strategy>
    static inline void apply(BoxOut& box_out,
                             BoxIn const& box_in,
                             Strategy const& )
    {
        Strategy::apply(box_out, box_in);
    }
};

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce


} // namespace dispatch
#endif // DOXYGEN_NO_DISPATCH

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_EXPAND_INDEXED_HPP
