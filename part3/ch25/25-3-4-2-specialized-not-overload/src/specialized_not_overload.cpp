/*
 * specialized_not_overload.cpp
 *
 *  Created on: 2016/09/22
 *      Author: sasaki
 */

#include <climits>
#include <iostream>
#include <vector>

template<typename T> T max_value();

template<> constexpr int max_value<int>() { return INT_MAX; }
template<> constexpr char max_value<char>() { return CHAR_MAX; }

template<typename T>
using Value_type = typename T::value_type;

template<typename Iter>
Iter my_alogo(Iter p)
{
	auto x = max_value<Value_type<Iter>>();
	std::cout << "my_alogo - x :" << (long)x << '\n';
	return p;
}

int max2(int) { return INT_MAX; }
int max2(char) { return CHAR_MAX; }

template<typename Iter>
Iter my_alogo2(Iter p)
{
	auto x = max2(Value_type<Iter>{});
	std::cout << "my_alogo2 - x :" << (long)x << '\n';
	return p;
}

// add main

int main()
{
	std::vector<int> vi(10);
	my_alogo(vi.begin());

	std::vector<char> vc(10);
	my_alogo(vc.begin());

	std::vector<long> vl(10);
	//my_alogo(vl.begin());
		// undefined reference to `long max_value<long>()'

	my_alogo2(vi.begin());
	my_alogo2(vc.begin());
}
