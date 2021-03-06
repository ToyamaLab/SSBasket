// Boost.Geometry (aka GGL, Generic Geometry Library)

<<<<<<< HEAD
// Copyright (c) 2016-2017 Oracle and/or its affiliates.
=======
// Copyright (c) 2016-2018 Oracle and/or its affiliates.
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
// Contributed and/or modified by Vissarion Fisikopoulos, on behalf of Oracle
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_STRATEGIES_CARTESIAN_AZIMUTH_HPP
#define BOOST_GEOMETRY_STRATEGIES_CARTESIAN_AZIMUTH_HPP

#include <boost/geometry/core/tags.hpp>

<<<<<<< HEAD
=======
#include <boost/geometry/strategies/azimuth.hpp>

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
namespace boost { namespace geometry
{

namespace strategy { namespace azimuth
{

template
<
    typename CalculationType = void
>
class cartesian
{};

#ifndef DOXYGEN_NO_STRATEGY_SPECIALIZATIONS

namespace services
{

template <typename CalculationType>
struct default_strategy<cartesian_tag, CalculationType>
{
    typedef strategy::azimuth::cartesian<CalculationType> type;
};

}

#endif // DOXYGEN_NO_STRATEGY_SPECIALIZATIONS

}} // namespace strategy::azimuth


}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_STRATEGIES_CARTESIAN_AZIMUTH_HPP
