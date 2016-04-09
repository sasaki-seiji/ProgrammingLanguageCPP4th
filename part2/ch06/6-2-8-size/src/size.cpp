/*
 * size.cpp
 *
 *  Created on: 2016/04/09
 *      Author: sasaki
 */

#include <limits>
#include <iostream>
using namespace std;

#include <cstdint>

int main()
{
	cout << "size of long " << sizeof(1L) << '\n';
	cout << "size of long long " << sizeof(1LL) << '\n';

	cout << "largest float " << std::numeric_limits<float>::max() << '\n';
	cout << "char is signed " << std::numeric_limits<char>::is_signed << '\n';

	//int16_t x {0xaabb};
	int16_t x = 0xaabb;
		// narrowing conversion of '43707' from 'int' to 'int16_t {aka short int}' inside { } [-Wnarrowing]
	//int64_t xxxx {0xaaaabbbbccccdddd};
	int64_t xxxx = 0xaaaabbbbccccdddd;
		// narrowing conversion of '12297848147757817309ull' from 'long long unsigned int' to 'int64_t {aka long long int}' inside { } [-Wnarrowing]
	int_least16_t y;
	int_least32_t yy;
	int_fast32_t z;

	cout << "size of int16_t " << sizeof(x) << '\n';
	cout << "size of int64_t " << sizeof(xxxx) << '\n';
	cout << "size of int_least16_t " << sizeof(y) << '\n';
	cout << "size of int_least32_t " << sizeof(yy) << '\n';
	cout << "size of int_fast32_t " << sizeof(z) << '\n';
}
