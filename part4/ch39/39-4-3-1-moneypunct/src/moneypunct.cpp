/*
 * moneypunct.cpp
 *
 *  Created on: 2017/01/09
 *      Author: sasaki
 */


// moneypunct example
#include <iostream>       // std::cout
#include <locale>         // std::locale, std::moneypunct, std::use_facet

// overload inserter to print patterns:
std::ostream& operator<< (std::ostream& os, std::moneypunct<char>::pattern p)
{
  for (int i=0; i<4; i++)
    switch (p.field[i]) {
      case std::moneypunct<char>::none: std::cout << "none "; break;
      case std::moneypunct<char>::space: std::cout << "space "; break;
      case std::moneypunct<char>::symbol: std::cout << "symbol "; break;
      case std::moneypunct<char>::sign: std::cout << "sign "; break;
      case std::moneypunct<char>::value: std::cout << "value "; break;
    }
  return os;
}

void output_moneypunct (const std::locale &mylocale)
{
  const std::moneypunct<char>& mp = std::use_facet<std::moneypunct<char> >(mylocale);

  std::cout << "moneypunct in locale \"" << mylocale.name() << "\":\n";

  std::cout << "decimal_point: " << mp.decimal_point() << '\n';
  std::cout << "thousands_sep: " << mp.thousands_sep() << '\n';
  std::cout << "grouping: " << mp.grouping() << '\n';
  std::cout << "curr_symbol: " << mp.curr_symbol() << '\n';
  std::cout << "positive_sign: " << mp.positive_sign() << '\n';
  std::cout << "negative_sign: " << mp.negative_sign() << '\n';
  std::cout << "frac_digits: " << mp.frac_digits() << '\n';
  std::cout << "pos_format: " << mp.pos_format() << '\n';
  std::cout << "neg_format: " << mp.neg_format() << '\n';
}

int main()
{
	std::cout << "--- default locale ---\n";
	output_moneypunct(std::locale());

	std::cout << "--- preferred locale ---\n";
	output_moneypunct(std::locale(""));

	std::cout << "--- ja_JP.UTF-8 ---\n";
	output_moneypunct(std::locale("ja_JP.UTF-8"));

	std::cout << "--- en_US.UTF-8 ---\n";
	output_moneypunct(std::locale("en_US.UTF-8"));

	std::cout << "--- fr_FR.UTF-8 ---\n";
	output_moneypunct(std::locale("fr_FR.UTF-8"));

	std::cout << "--- da_DK.UTF-8 ---\n";
	output_moneypunct(std::locale("da_DK.UTF-8"));
}
