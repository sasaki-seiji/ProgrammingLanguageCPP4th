/*
 * dependent_typename.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

template<typename Container>
void fct(Container& c)
{
	cout << "-- fct(Container&) --\n";

	//Container::value_type v1 = c[7];
		// error: need 'typename' before 'Container:: value_type' because 'Container' is a dependent scope
	typename Container::value_type v2 = c[9];
	auto v3 = c[11];

	cout << "v2: " << v2 << '\n';
	cout << "v3: " << v3 << '\n';
}


template<typename T>
using Value_type = typename T::value_type;

template<typename Container>
void fct2(Container& c)
{
	cout << "-- fct2(Container&) --\n";

	Value_type<Container> v1 = c[7];
	auto v3 = c[11];

	cout << "v1: " << v1 << '\n';
	cout << "v3: " << v3 << '\n';
}


// add main

int main()
{
	vector<int> vi {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	fct(vi);
	fct2(vi);
}
