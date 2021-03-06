/*=============================================================================
    Copyright (c) 2001-2014 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
<<<<<<< HEAD
#if !defined(SPIRIT_NOT_PREDICATE_MARCH_23_2007_0618PM)
#define SPIRIT_NOT_PREDICATE_MARCH_23_2007_0618PM
=======
#if !defined(BOOST_SPIRIT_X3_NOT_PREDICATE_MARCH_23_2007_0618PM)
#define BOOST_SPIRIT_X3_NOT_PREDICATE_MARCH_23_2007_0618PM
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#include <boost/spirit/home/x3/core/parser.hpp>

namespace boost { namespace spirit { namespace x3
{
    template <typename Subject>
    struct not_predicate : unary_parser<Subject, not_predicate<Subject>>
    {
        typedef unary_parser<Subject, not_predicate<Subject>> base_type;

        typedef unused_type attribute_type;
        static bool const has_attribute = false;

        not_predicate(Subject const& subject)
          : base_type(subject) {}

        template <typename Iterator, typename Context
          , typename RContext, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context const& context, RContext& rcontext, Attribute& /*attr*/) const
        {
            Iterator i = first;
            return !this->subject.parse(i, last, context, rcontext, unused);
        }
    };

    template <typename Subject>
    inline not_predicate<typename extension::as_parser<Subject>::value_type>
    operator!(Subject const& subject)
    {
        return { as_parser(subject) };
    }
}}}

#endif
