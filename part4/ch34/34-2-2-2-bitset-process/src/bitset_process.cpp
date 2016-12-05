/*
 * bitset_process.cpp
 *
 *  Created on: 2016/12/05
 *      Author: sasaki
 */


#include <bitset>
#include <iostream>
using namespace std;

void shift()
{
	bitset<9> bs {"110001111"};
	cout << bs << '\n';

	auto bs2 = bs<<3;
	cout << bs2 << '\n';

	cin >> bs;
	bs2 = bs>>3;
	cout << bs2 << '\n';
}

void binary(int i)
{
	bitset<8*sizeof(int)> b = i;

	cout << b.to_string<char,char_traits<char>,allocator<char>>()
			<< '\n';
	cout << b.to_string<char>() << '\n';
	//cout << b.to_string<>() << '\n';
		// error: no matching function for call to 'std::bitset<32ull>::to_string()'
	cout << b.to_string() << '\n';
}

void binary2(int i)
{
	bitset<8*sizeof(int)> b = i;
	cout << b << '\n';
}

int main()
{
	shift();
	binary(123);
	binary2(123);
}
