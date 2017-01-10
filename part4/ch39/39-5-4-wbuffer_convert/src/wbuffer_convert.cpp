/*
 * wbuffer_convert.cpp
 *
 *  Created on: 2017/01/11
 *      Author: sasaki
 */


// wbuffer_convert example
#include <iostream>       // std::cout, std::ios, std::wostream
#include <locale>         // std::wbuffer_convert
#include <codecvt>        // std::codecvt_utf8
#include <fstream>        // std::filebuf

int main()
{
  // file buffer (narrow buffer):
  std::filebuf myfile;
  myfile.open("test.txt",std::ios::out);

  // conversor (wide buffer -> narrow buffer, using UTF-8):
  std::wbuffer_convert<std::codecvt_utf8<wchar_t>> bufconv (&myfile);

  // stream (wide buffer):
  std::wostream mystream (&bufconv);

  mystream << L"Testテスト";  // writes wide string to file (UTF-8)

  // 2017.01.10 add
  mystream << std::flush;

  return 0;
}

