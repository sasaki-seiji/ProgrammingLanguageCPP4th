/*
 * swap.cpp
 *
 *  Created on: 2016/11/30
 *      Author: sasaki
 */


#include <utility>
#include <vector>
#include <iostream>
using namespace std;


void use(vector<int>& v, int* p)
{
	swap_ranges(v.begin(), v.end(), p);
}

void print(const vector<int>& v, const int* a)
{
	cout << "v: ";
	for (auto x : v)
		cout << x << ',';
	cout << endl;

	cout << "a[]: ";
	for (size_t i=0; i!=v.size(); ++i)
		cout << a[i] << ',';
	cout << endl;
}

int main()
{
	vector<int> v {1, 2, 3, 4 ,5};
	int a[] = {11,12,13,14,15};
	print(v,a);

	use(v, a);
	print(v,a);
}
