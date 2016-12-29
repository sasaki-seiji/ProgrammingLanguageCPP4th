/*
 * ostreambuf_iterator.cpp
 *
 *  Created on: 2016/12/29
 *      Author: sasaki
 */


// ostreambuf_iterator example
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::ostreambuf_iterator
#include <string>       // std::string
#include <algorithm>    // std::copy

int main () {
  std::string mystring ("Some text here...\n");
  std::ostreambuf_iterator<char> out_it (std::cout); // stdout iterator

  std::copy ( mystring.begin(), mystring.end(), out_it);

  return 0;
}

