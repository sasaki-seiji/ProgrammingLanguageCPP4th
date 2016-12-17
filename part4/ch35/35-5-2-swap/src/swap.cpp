/*
 * swap.cpp
 *
 *  Created on: 2016/12/17
 *      Author: sasaki
 */


#include <utility>
#include <vector>
#include <iostream>
using namespace std;

#include "concept.h"
using namespace Estd;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto& x : v)
		os << x << ", ";
	return os;
}

template<typename T>
void my_swap(T& a, T& b)
	noexcept(Is_nothrow_move_constructible<T>() && Is_nothrow_move_assignable<T>())
{
	T tmp {move(a)};
	a = move(b);
	b = move(tmp);
}

int main()
{
	vector<int> v {1,2,3,4};
	//swap(v,vector<int>{});
		// error: no matching function for call to 'swap(std::vector<int>&, std::vector<int>)'
	v.clear();

	vector<int> v1{1,2,3,4}, v2{5,6,7,8};
	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

	swap(v1,v2);
	cout << "after swap():" << endl;
	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

	my_swap(v1,v2);
	cout << "after my_swap():" << endl;
	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

}
