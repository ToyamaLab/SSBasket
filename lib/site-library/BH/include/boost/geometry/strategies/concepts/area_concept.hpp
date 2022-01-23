// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2012 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2012 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2012 Mateusz Loskot, London, UK.
<<<<<<< HEAD
=======
// Copyright (c) 2017 Adam Wulkiewicz, Lodz, Poland.

// This file was modified by Oracle on 2018.
// Modifications copyright (c) 2018 Oracle and/or its affiliates.
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

// Parts of Boost.Geometry are redesigned from Geodan's Geographic Library
// (geolib/GGL), copyright (c) 1995-2010 Geodan, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_STRATEGIES_CONCEPTS_AREA_CONCEPT_HPP
#define BOOST_GEOMETRY_STRATEGIES_CONCEPTS_AREA_CONCEPT_HPP


#include <boost/concept_check.hpp>
<<<<<<< HEAD
=======
#include <boost/core/ignore_unused.hpp>

#include <boost/geometry/geometries/point.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce


namespace boost { namespace geometry { namespace concepts
{


/*!
    \brief Checks strategy for area
    \ingroup area
*/
<<<<<<< HEAD
template <typename Strategy>
=======
template <typename Geometry, typename Strategy>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
class AreaStrategy
{
#ifndef DOXYGEN_NO_CONCEPT_MEMBERS

<<<<<<< HEAD
    // 1) must define state_type,
    typedef typename Strategy::state_type state_type;

    // 2) must define return_type,
    typedef typename Strategy::return_type return_type;

    // 3) must define point_type, of polygon (segments)
    typedef typename Strategy::segment_point_type spoint_type;
=======
    // 1) must define state template,
    typedef typename Strategy::template state<Geometry> state_type;

    // 2) must define result_type template,
    typedef typename Strategy::template result_type<Geometry>::type return_type;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

    struct check_methods
    {
        static void apply()
        {
            Strategy const* str = 0;
            state_type *st = 0;

<<<<<<< HEAD
            // 4) must implement a method apply with the following signature
            spoint_type const* sp = 0;
            str->apply(*sp, *sp, *st);

            // 5) must implement a static method result with the following signature
            return_type r = str->result(*st);

            boost::ignore_unused_variable_warning(r);
            boost::ignore_unused_variable_warning(str);
=======
            // 3) must implement a method apply with the following signature
            typename geometry::point_type<Geometry>::type const* sp = 0;
            str->apply(*sp, *sp, *st);

            // 4) must implement a static method result with the following signature
            return_type r = str->result(*st);

            boost::ignore_unused(r, str);
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
        }
    };

public :
    BOOST_CONCEPT_USAGE(AreaStrategy)
    {
        check_methods::apply();
    }

#endif
};


}}} // namespace boost::geometry::concepts


#endif // BOOST_GEOMETRY_STRATEGIES_CONCEPTS_AREA_CONCEPT_HPP
