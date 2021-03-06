//  filesystem/string_file.hpp  --------------------------------------------------------//

//  Copyright Beman Dawes 2015

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  Library home page: http://www.boost.org/libs/filesystem

#ifndef BOOST_FILESYSTEM_STRING_FILE_HPP
#define BOOST_FILESYSTEM_STRING_FILE_HPP

#include <string>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>

namespace boost
{
namespace filesystem
{
inline
void save_string_file(const path& p, const std::string& str)
{
<<<<<<< HEAD
  ofstream file;
=======
  filesystem::ofstream file;
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  file.open(p, std::ios_base::binary);
  file.write(str.c_str(), str.size());
}

inline
void load_string_file(const path& p, std::string& str)
{
<<<<<<< HEAD
  ifstream file;
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  file.open(p, std::ios_base::binary);
  std::size_t sz = static_cast<std::size_t>(file_size(p));
=======
  filesystem::ifstream file;
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  file.open(p, std::ios_base::binary);
  std::size_t sz = static_cast<std::size_t>(filesystem::file_size(p));
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
  str.resize(sz, '\0');
  file.read(&str[0], sz);
}
}  // namespace filesystem
}  // namespace boost

#endif  // include guard
