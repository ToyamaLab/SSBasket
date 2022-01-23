<<<<<<< HEAD
// Copyright Daniel Wallin, David Abrahams 2010. Use, modification and
// distribution is subject to the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
=======
// Copyright Daniel Wallin, David Abrahams 2010.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_IS_MAYBE_050329_HPP
#define BOOST_PARAMETER_IS_MAYBE_050329_HPP

<<<<<<< HEAD
#include <boost/type_traits/is_base_and_derived.hpp>

namespace boost {
namespace parameter {
namespace aux {

struct maybe_base {};

template <class T>
struct is_maybe
  : is_base_and_derived<maybe_base, T>
{};

} // namespace aux
} // namespace parameter
} // namespace boost

#endif // BOOST_PARAMETER_IS_MAYBE_050329_HPP
=======
namespace boost { namespace parameter { namespace aux {

    struct maybe_base
    {
    };
}}} // namespace boost::parameter::aux

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <type_traits>

namespace boost { namespace parameter { namespace aux {

    template <typename T>
    using is_maybe = ::std::is_base_of<
        ::boost::parameter::aux::maybe_base
      , typename ::std::remove_const<T>::type
    >;
}}} // namespace boost::parameter::aux

#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/remove_const.hpp>

namespace boost { namespace parameter { namespace aux {

    template <typename T>
    struct is_maybe
      : ::boost::mpl::if_<
            ::boost::is_base_of<
                ::boost::parameter::aux::maybe_base
              , typename ::boost::remove_const<T>::type
            >
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
    {
    };
}}} // namespace boost::parameter::aux

#endif  // BOOST_PARAMETER_CAN_USE_MP11
#endif  // include guard

>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
