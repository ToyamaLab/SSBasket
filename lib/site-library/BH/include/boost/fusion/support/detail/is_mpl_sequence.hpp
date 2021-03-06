/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_DETAIL_IS_MPL_SEQUENCE_29122006_1105)
#define FUSION_DETAIL_IS_MPL_SEQUENCE_29122006_1105

#include <boost/fusion/support/config.hpp>
<<<<<<< HEAD
#include <boost/fusion/support/sequence_base.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_convertible.hpp>
=======
#include <boost/fusion/support/detail/is_native_fusion_sequence.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

namespace boost { namespace fusion { namespace detail
{
    template <typename T>
    struct is_mpl_sequence
        : mpl::and_<
<<<<<<< HEAD
            mpl::not_<is_convertible<T, from_sequence_convertible_type> >
=======
            mpl::not_<is_native_fusion_sequence<T> >
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
          , mpl::is_sequence<T> >
    {};
}}}

#endif
