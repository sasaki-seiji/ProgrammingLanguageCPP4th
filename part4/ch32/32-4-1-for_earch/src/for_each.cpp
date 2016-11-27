/*
 * for_each.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void increment_all(vector<int>& v)
{
	for_each(v.begin(),v.end(), [](int& x) {++x;});
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ", ";
	return os;
}

int main()
{
	vector<int> v {0,1,2,3,4,5,6,7,8,9};
	cout << "v: " << v << endl;
	increment_all(v);
	cout << "v: " << v << endl;
}
