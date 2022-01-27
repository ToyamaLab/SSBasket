<<<<<<< HEAD
// Copyright Daniel Wallin, David Abrahams 2005. Use, modification and
// distribution is subject to the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
=======
// Copyright Daniel Wallin, David Abrahams 2005.
// Copyright Cromwell D. Enage 2017.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef UNWRAP_CV_REFERENCE_050328_HPP
#define UNWRAP_CV_REFERENCE_050328_HPP

<<<<<<< HEAD
#include <boost/parameter/aux_/yesno.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { template<class T> class reference_wrapper; }

namespace boost { namespace parameter { namespace aux {

//
// reference_wrapper support -- because of the forwarding problem,
// when passing arguments positionally by non-const reference, we
// ask users of named parameter interfaces to use ref(x) to wrap
// them.
//

// is_cv_reference_wrapper returns mpl::true_ if T is of type
// reference_wrapper<U> cv
template <class U>
yes_tag is_cv_reference_wrapper_check(reference_wrapper<U> const volatile*);
no_tag is_cv_reference_wrapper_check(...);

template <class T>
struct is_cv_reference_wrapper
{
    BOOST_STATIC_CONSTANT(
        bool, value = (
            sizeof(is_cv_reference_wrapper_check((T*)0)) == sizeof(yes_tag)
        )
    );

    typedef mpl::bool_<
#if BOOST_WORKAROUND(__BORLANDC__, BOOST_TESTED_AT(0x564))
        is_cv_reference_wrapper::
#endif 
    value> type;
};

// Needed for unwrap_cv_reference below. T might be const, so
// eval_if might fail because of deriving from T const on EDG.
template <class T>
struct get_type
{
    typedef typename T::type type;
};

#if BOOST_WORKAROUND(__BORLANDC__, BOOST_TESTED_AT(0x564))
template <class T, class is_reference_wrapper = typename is_cv_reference_wrapper<T>::type>
struct unwrap_cv_reference
{
    typedef T type;
};

template <class T>
struct unwrap_cv_reference<T const, mpl::false_>
{
    typedef T const type;
};

template <class T>
struct unwrap_cv_reference<T, mpl::true_>
  : T
{};

#else 
// Produces the unwrapped type to hold a reference to in named<>
// Can't use boost::unwrap_reference<> here because it
// doesn't handle the case where T = reference_wrapper<U> cv
template <class T>
struct unwrap_cv_reference
{
    typedef typename mpl::eval_if<
        is_cv_reference_wrapper<T>
      , get_type<T>
      , mpl::identity<T>
    >::type type;
};
#endif

}}} // namespace boost::parameter::aux

#endif // UNWRAP_CV_REFERENCE_050328_HPP
=======
namespace boost {

    template <typename T>
    class reference_wrapper;
} // namespace boost

#include <boost/parameter/aux_/yesno.hpp>

namespace boost { namespace parameter { namespace aux {

    //
    // reference_wrapper support -- if perfect forwarding is unsupported,
    // then when passing arguments positionally by non-const reference,
    // we ask users of named parameter interfaces to use ref(x) to wrap them.
    //

    template <typename U>
    ::boost::parameter::aux::yes_tag
        is_cv_reference_wrapper_check(
            ::boost::reference_wrapper<U> const volatile*
        );

    ::boost::parameter::aux::no_tag is_cv_reference_wrapper_check(...);
}}} // namespace boost::parameter::aux

#include <boost/parameter/config.hpp>

#if !defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
#include <functional>

namespace boost { namespace parameter { namespace aux {

    // Support for std::ref(x) -- Cromwell D. Enage
    template <typename U>
    ::boost::parameter::aux::yes_tag
        is_cv_reference_wrapper_check(
            ::std::reference_wrapper<U> const volatile*
        );
}}} // namespace boost::parameter::aux
#endif

#include <boost/parameter/aux_/preprocessor/nullptr.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11) && !( \
        BOOST_WORKAROUND(BOOST_MSVC, >= 1900) && \
        BOOST_WORKAROUND(BOOST_MSVC, < 1910) \
    )
#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#include <type_traits>
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11) || MSVC-14.0
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/remove_reference.hpp>
#if !BOOST_WORKAROUND(__BORLANDC__, BOOST_TESTED_AT(0x564)) && \
    !BOOST_WORKAROUND(BOOST_GCC, < 40000)
#include <boost/mpl/eval_if.hpp>
#endif
#endif  // BOOST_PARAMETER_CAN_USE_MP11 && not MSVC-14.0

namespace boost { namespace parameter { namespace aux {

#if defined(BOOST_PARAMETER_CAN_USE_MP11) && !( \
        BOOST_WORKAROUND(BOOST_MSVC, >= 1900) && \
        BOOST_WORKAROUND(BOOST_MSVC, < 1910) \
    )
    // This metafunction returns mp11::mp_true if T is of type
    // reference_wrapper<U> cv.
    template <typename T>
    using is_cv_reference_wrapper = ::boost::mp11::mp_bool<
        sizeof(
            ::boost::parameter::aux::is_cv_reference_wrapper_check(
                static_cast<
                    typename ::std::remove_reference<T>::type*
                >(BOOST_PARAMETER_AUX_PP_NULLPTR)
            )
        ) == sizeof(::boost::parameter::aux::yes_tag)
    >;

    // Needed for unwrap_cv_reference below. T might be const, so
    // mp_eval_if<> might fail because of deriving from T const on EDG.
    template <typename T>
    using unwrap_cv_reference_impl = typename ::std::remove_reference<T>::type;

    // Produces the unwrapped type to hold a reference to in
    // tagged_argument<>.  Can't use boost::unwrap_reference<> here
    // because it doesn't handle the case where T = reference_wrapper<U> cv.
    template <typename T>
    using unwrap_cv_reference = ::boost::mp11::mp_eval_if<
        ::boost::parameter::aux::is_cv_reference_wrapper<T>
      , ::boost::parameter::aux::unwrap_cv_reference_impl<T>
      , ::std::remove_reference
      , T
    >;
#else  // !defined(BOOST_PARAMETER_CAN_USE_MP11) || MSVC-14.0
    // This metafunction returns mpl::true_ if T is of type
    // reference_wrapper<U> cv.
    template <typename T>
    struct is_cv_reference_wrapper
    {
        BOOST_STATIC_CONSTANT(
            bool, value = (
                sizeof(
                    ::boost::parameter::aux::is_cv_reference_wrapper_check(
                        static_cast<
                            typename ::boost::remove_reference<T>::type*
                        >(BOOST_PARAMETER_AUX_PP_NULLPTR)
                    )
                ) == sizeof(::boost::parameter::aux::yes_tag)
            )
        );

        typedef boost::mpl::bool_<
#if BOOST_WORKAROUND(__BORLANDC__, BOOST_TESTED_AT(0x564))
            is_cv_reference_wrapper::
#endif 
        value> type;
    };

#if BOOST_WORKAROUND(__BORLANDC__, BOOST_TESTED_AT(0x564)) || \
    BOOST_WORKAROUND(BOOST_GCC, < 40000)
    template <
        typename T
      , typename = typename ::boost::parameter::aux
        ::is_cv_reference_wrapper<T>::type
    >
    struct unwrap_cv_reference : ::boost::remove_reference<T>
    {
    };

    template <typename T>
    struct unwrap_cv_reference<T const,::boost::mpl::false_>
    {
        typedef T const type;
    };

    template <typename T>
    struct unwrap_cv_reference<T,::boost::mpl::true_> : T
    {
    };
#else   // no Borland or GCC 3- workarounds needed
    // Needed for unwrap_cv_reference below. T might be const, so
    // eval_if<> might fail because of deriving from T const on EDG.
    template <typename T>
    struct unwrap_cv_reference_impl : ::boost::remove_reference<T>::type
    {
    };

    // Produces the unwrapped type to hold a reference to in
    // tagged_argument<>.  Can't use boost::unwrap_reference<> here
    // because it doesn't handle the case where T = reference_wrapper<U> cv.
    template <typename T>
    struct unwrap_cv_reference
      : ::boost::mpl::eval_if<
            ::boost::parameter::aux::is_cv_reference_wrapper<T>
          , ::boost::parameter::aux::unwrap_cv_reference_impl<T>
          , ::boost::remove_reference<T>
        >
    {
    };
#endif  // Borland or GCC 3- workarounds needed
#endif  // BOOST_PARAMETER_CAN_USE_MP11 && not MSVC-14.0
}}} // namespace boost::parameter::aux

#endif  // include guard
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
