/*
 * function_object.cpp
 *
 *  Created on: 2016/12/04
 *      Author: sasaki
 */


#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto& x : v)
		os << x << ", ";
	return os;
}

int main()
{
	vector<int> v {1,5,2,7,9,2};

	cout << "before sort, v: " << v << endl;
	sort(v.begin(), v.end(), greater<int>{});
	cout << "after sort, v: " << v << endl;

	vector<int> v2 {4,2,7,1,9,8,3,2};

	cout << "before sort, v2: " << v2 << endl;
	sort(v2.begin(), v2.end(), [](int a, int b){ return a > b; });
	cout << "after sort, v2: " << v2 << endl;
}
