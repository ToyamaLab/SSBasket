// Boost.Geometry Index
//
// Copyright (c) 2011-2013 Adam Wulkiewicz, Lodz, Poland.
//
<<<<<<< HEAD
=======
// This file was modified by Oracle on 2019.
// Modifications copyright (c) 2019 Oracle and/or its affiliates.
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle
//
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_INDEX_DETAIL_TRANSLATOR_HPP
#define BOOST_GEOMETRY_INDEX_DETAIL_TRANSLATOR_HPP

namespace boost { namespace geometry { namespace index {

namespace detail {

<<<<<<< HEAD
=======
template <typename Strategy>
struct translator_equals
{
    template <typename EqualTo, typename Value>
    static inline bool apply(EqualTo const& equal_to,
                             Value const& v1, Value const& v2,
                             Strategy const& strategy)
    {
        return equal_to(v1, v2, strategy);
    }
};

template <>
struct translator_equals<default_strategy>
{
    template <typename EqualTo, typename Value>
    static inline bool apply(EqualTo const& equal_to,
                             Value const& v1, Value const& v2,
                             default_strategy const&)
    {
        return equal_to(v1, v2);
    }
};

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
template <typename IndexableGetter, typename EqualTo>
struct translator
    : public IndexableGetter
    , public EqualTo
{
    typedef typename IndexableGetter::result_type result_type;

    translator(IndexableGetter const& i, EqualTo const& e)
        : IndexableGetter(i), EqualTo(e)
    {}

    template <typename Value>
    result_type operator()(Value const& value) const
    {
        return IndexableGetter::operator()(value);
    }

<<<<<<< HEAD
    template <typename Value>
    bool equals(Value const& v1, Value const& v2) const
    {
        return EqualTo::operator()(v1, v2);
    }
=======
	template <typename Value, typename Strategy>
	bool equals(Value const& v1, Value const& v2, Strategy const& strategy) const
	{
		return translator_equals
                <
                    Strategy
                >::apply(static_cast<EqualTo const&>(*this), v1, v2, strategy);
	}
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
};

template <typename IndexableGetter>
struct result_type
{
    typedef typename IndexableGetter::result_type type;
};

template <typename IndexableGetter>
struct indexable_type
{
    typedef typename boost::remove_const<
        typename boost::remove_reference<
            typename result_type<IndexableGetter>::type
        >::type
    >::type type;
};

} // namespace detail

}}} // namespace boost::geometry::index

#endif // BOOST_GEOMETRY_INDEX_DETAIL_TRANSLATOR_HPP
