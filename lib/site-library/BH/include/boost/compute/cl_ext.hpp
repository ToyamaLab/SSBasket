//---------------------------------------------------------------------------//
// Copyright (c) 2013 Kyle Lutz <kyle.r.lutz@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://boostorg.github.com/compute for more information.
//---------------------------------------------------------------------------//

#ifndef BOOST_COMPUTE_CL_EXT_HPP
#define BOOST_COMPUTE_CL_EXT_HPP

<<<<<<< HEAD
#if defined(BOOST_COMPUTE_MAX_CL_VERSION)
#  if !defined(CL_USE_DEPRECATED_OPENCL_2_1_APIS) && BOOST_COMPUTE_MAX_CL_VERSION < 202
#    define CL_USE_DEPRECATED_OPENCL_2_1_APIS
#  endif
#  if !defined(CL_USE_DEPRECATED_OPENCL_2_0_APIS) && BOOST_COMPUTE_MAX_CL_VERSION < 201
#    define CL_USE_DEPRECATED_OPENCL_2_0_APIS
#  endif
#  if !defined(CL_USE_DEPRECATED_OPENCL_1_2_APIS) && BOOST_COMPUTE_MAX_CL_VERSION < 200
#    define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#  endif
#  if !defined(CL_USE_DEPRECATED_OPENCL_1_1_APIS) && BOOST_COMPUTE_MAX_CL_VERSION < 102
#    define CL_USE_DEPRECATED_OPENCL_1_1_APIS
#  endif
#  if !defined(CL_USE_DEPRECATED_OPENCL_1_0_APIS) && BOOST_COMPUTE_MAX_CL_VERSION < 101
#    define CL_USE_DEPRECATED_OPENCL_1_0_APIS
#  endif
#endif
=======
#include "detail/cl_versions.hpp"
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce

#if defined(__APPLE__)
#include <OpenCL/cl_ext.h>
#else
#include <CL/cl_ext.h>
#endif

#endif // BOOST_COMPUTE_CL_EXT_HPP
