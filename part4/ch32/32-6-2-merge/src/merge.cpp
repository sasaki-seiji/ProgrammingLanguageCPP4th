/*
 * merge.cpp
 *
 *  Created on: 2016/12/02
 *      Author: sasaki
 */


#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	vector<int> v{3,1,4,2};
	list<double> lst {0.5, 1.5, 2, 2.5};

	sort(v.begin(), v.end());

	vector<double> v2;

	merge(v.begin(), v.end(), lst.begin(), lst.end(), back_inserter(v2));
	for (double x : v2)
		cout << x << ", ";
	cout << '\n';
}
