/*
 * codecvt_utf8.cpp
 *
 *  Created on: 2017/01/10
 *      Author: sasaki
 */


// codecvt_utf8: writing UTF-32 string as UTF-8
#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include <fstream>

int main()
{
  std::u32string str ( U"\U00004f60\U0000597d" );  // ni hao (你好)

  std::locale loc (std::locale(), new std::codecvt_utf8<char32_t>);
  std::basic_ofstream<char32_t> ofs ("test.txt");
  ofs.imbue(loc);

  std::cout << "Writing to file (UTF-8)... ";
  ofs << str;
  std::cout << "done!\n";

  return 0;
}

