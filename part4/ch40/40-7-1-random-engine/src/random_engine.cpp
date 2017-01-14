/*
 * random_engine.cpp
 *
 *  Created on: 2017/01/15
 *      Author: sasaki
 */

#include <random>
#include <map>
#include <iostream>
using namespace std;

void test_linear_congruential_engine17()
{
	cout << "linear_congruential_engine<unsigned int, 17, 5, 0>:\n";
	map<int,int> m;
	linear_congruential_engine<unsigned int, 17, 5, 0> linc_eng;
	for (int i=0; i<1000000; ++i)
		if (1 < ++m[linc_eng()]) cout << i << '\n';
}

void test_linear_congruential_engine16()
{
	cout << "linear_congruential_engine<unsigned int, 16, 5, 0>:\n";
	map<int,int> m;
	linear_congruential_engine<unsigned int, 16, 5, 0> linc_eng;
	for (int i=0; i<100; ++i)
		if (1 < ++m[linc_eng()]) cout << i << '\n';
}

void test_independent_bits_engine()
{
	cout << "independent_bits_engine<default_random_engine,4,unsigned int>:\n";
	independent_bits_engine<default_random_engine,4,unsigned int> ibe;
	for (int i=0; i<100; ++i)
		cout << '0'+ibe() << ' ';
}

int main()
{
	test_linear_congruential_engine17();
	test_linear_congruential_engine16();
	test_independent_bits_engine();
}
