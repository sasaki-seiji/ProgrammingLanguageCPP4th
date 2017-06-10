/*
 * specialized_not_overload.cpp
 *
 *  Created on: 2016/09/22
 *      Author: sasaki
 */

#include "iterator_traits.h"
using namespace Estd;

#include <climits>
#include <iostream>
#include <vector>
#include <iterator>

template<typename T> T max_value();

template<> constexpr int max_value<int>() { return INT_MAX; }
template<> constexpr char max_value<char>() { return CHAR_MAX; }


template<typename Iter>
Iter my_algo(Iter p)
{
	auto x = max_value<Value_type<Iter>>();
	std::cout << "my_alogo - x :" << (long)x << '\n';
	return p;
}

int max2(int) { return INT_MAX; }
int max2(char) { return CHAR_MAX; }

template<typename Iter>
Iter my_algo2(Iter p)
{
	auto x = max2(Value_type<Iter>{});
	std::cout << "my_alogo2 - x :" << (long)x << '\n';
	return p;
}

// add main

int main()
{
	std::vector<int> vi(10);
	my_algo(vi.begin());

	std::vector<char> vc(10);
	my_algo(vc.begin());

	std::vector<long> vl(10);
	//my_alogo(vl.begin());
		// `long max_value<long>()' に対する定義されていない参照です

	int ai[] = {1,2,3,4};
	my_algo(std::begin(ai));

	my_algo2(vi.begin());
	my_algo2(vc.begin());
}
