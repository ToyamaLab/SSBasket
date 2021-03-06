/*=============================================================================
    Copyright (c) 2014 Thomas Bernard

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
<<<<<<< HEAD
#if !defined(SPIRIT_NO_CASE_SEPT_16_2014_0912PM)
#define SPIRIT_NO_CASE_SEPT_16_2014_0912PM
=======
#if !defined(BOOST_SPIRIT_X3_NO_CASE_SEPT_16_2014_0912PM)
#define BOOST_SPIRIT_X3_NO_CASE_SEPT_16_2014_0912PM
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#include <boost/spirit/home/x3/support/context.hpp>
#include <boost/spirit/home/x3/support/unused.hpp>
#include <boost/spirit/home/x3/support/no_case.hpp>
#include <boost/spirit/home/x3/core/parser.hpp>

namespace boost { namespace spirit { namespace x3
{
    // propagate no_case information through the context
    template <typename Subject>
    struct no_case_directive : unary_parser<Subject, no_case_directive<Subject>>
    {
        typedef unary_parser<Subject, no_case_directive<Subject> > base_type;
        static bool const is_pass_through_unary = true;
        static bool const handles_container = Subject::handles_container;

        no_case_directive(Subject const& subject)
          : base_type(subject) {}

        template <typename Iterator, typename Context
          , typename RContext, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context const& context, RContext& rcontext, Attribute& attr) const
        {
            return this->subject.parse(
                first, last
              , make_context<no_case_tag>(no_case_compare_, context)
              , rcontext
              , attr);
        }
    };

    struct no_case_gen
    {
        template <typename Subject>
        no_case_directive<typename extension::as_parser<Subject>::value_type>
        operator[](Subject const& subject) const
        {
            return { as_parser(subject) };
        }
    };

    auto const no_case = no_case_gen{};
}}}

#endif
