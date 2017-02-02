/*
 * alias.cpp
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */


#include <list>
#include <complex>
#include <iostream>
#include "Vector.h"
using namespace std;

template<typename C>
using Value_type = typename C::value_type;

template<typename Container>
void algo(Container& c)
{
//	Vector<Value_type<Container>> vec;
	Vector<Value_type<Container>> vec(c.size());

	// 2016.04.02 add
	int i = 0;
	for (auto it = c.begin(); it != c.end(); ++it)
		vec[i++] = *it;

	Value_type<Container> sum {};
	for (i = 0 ; i != vec.size(); ++i)
		sum += vec[i];

	cout << "sum of container: " << sum << '\n';
}

template<typename Key, typename Value>
class Map {
public:
	Map() { std::cout << "Map::Map() called\n"; }
};

template<typename Value>
using string_map = Map<string, Value>;

string_map<int> m;

int main()
{
	list<int>	ls { 1, 2, 3, 4 };
	algo(ls);

	list<complex<double>> lsc { {1,1},{1.1,2.2},{1.2,3.3}};
	algo(lsc);
}
