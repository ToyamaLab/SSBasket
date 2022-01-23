// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2017-2017 Barend Gehrels, Amsterdam, the Netherlands.
<<<<<<< HEAD
=======
// Copyright (c) 2017 Adam Wulkiewicz, Lodz, Poland.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_OVERLAY_IS_SELF_TURN_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_OVERLAY_IS_SELF_TURN_HPP

#include <boost/geometry/algorithms/detail/overlay/overlay_type.hpp>

namespace boost { namespace geometry
{


#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace overlay
{

template <overlay_type OverlayType>
struct is_self_turn_check
{
    template <typename Turn>
    static inline bool apply(Turn const& turn)
    {
        return turn.operations[0].seg_id.source_index
                == turn.operations[1].seg_id.source_index;
    }
};

template <>
struct is_self_turn_check<overlay_buffer>
{
    template <typename Turn>
<<<<<<< HEAD
    static inline bool apply(Turn const& turn)
=======
    static inline bool apply(Turn const& /*turn*/)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    {
        return false;
    }
};

template <>
<<<<<<< HEAD
struct is_self_turn_check<overlay_dissolve_union>
{
    template <typename Turn>
    static inline bool apply(Turn const& turn)
    {
        return false;
    }
};

template <>
struct is_self_turn_check<overlay_dissolve_intersection>
{
    template <typename Turn>
    static inline bool apply(Turn const& turn)
=======
struct is_self_turn_check<overlay_dissolve>
{
    template <typename Turn>
    static inline bool apply(Turn const& /*turn*/)
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
    {
        return false;
    }
};

template <overlay_type OverlayType, typename Turn>
bool is_self_turn(Turn const& turn)
{
    return is_self_turn_check<OverlayType>::apply(turn);
}


}} // namespace detail::overlay
#endif // DOXYGEN_NO_DETAIL


}} // namespace boost::geometry


#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_OVERLAY_IS_SELF_TURN_HPP
