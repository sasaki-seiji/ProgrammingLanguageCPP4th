/*
 * range_for_statement.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
#include <complex>
using namespace std;


int sum(vector<int>& v)
{
	int s = 0;
	for (int x : v)
		s += x;
	return s;
}

int sum2(vector<int>& v)
{
	int s = 0;
	for (auto p = begin(v); p != end(v); ++p)
		s += *p;
	return s;
}

void incr(vector<int>& v)
{
	for (int& x : v)
		++x;
}

void print(const vector<int>& v)
{
	cout << '[';
	for (int x : v)
		cout << ' ' << x ;
	cout << " ]\n";
}

template<typename T> T accum(vector<T>& v)
{
	T sum = 0;
	for (const T& x : v)
		sum += x;
	return sum;
}

int main()
{
	vector<int> v = {1,2,3,4};
	cout << "sum(v) is " << sum(v) << '\n';
	cout << "sum2(v) is " << sum2(v) << '\n';
	incr(v);
	cout << "after incr(v), v is :"; print(v);

	vector<complex<double>> cv = {{1,0},{2,1},{3,2}};
	cout << "accum(cv) is " << accum(cv) << '\n';
}


