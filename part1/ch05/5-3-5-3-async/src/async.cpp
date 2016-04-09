/*
 * async.cpp
 *
 *  Created on: 2016/04/05
 *      Author: sasaki
 */

#include <numeric>
#include <future>
#include <vector>
#include <iostream>
using namespace std;

double accum(double* beg, double* end, double init)
{
	return accumulate(beg, end, init);
}

double comp4(vector<double>& v)
{
	// 2016.04.05 change
	//if (v.size() < 10000) return accum(v.begin(), v.end(), 0.0);
	if (v.size() < 10000) return accum(&v[0], &v[0]+v.size(), 0.0);

	auto v0 = &v[0];
	auto sz = v.size();

	auto f0 = async(accum, v0, v0+sz/4, 0.0);
	auto f1 = async(accum, v0+sz/4, v0+sz/2, 0.0);
	auto f2 = async(accum, v0+sz/2, v0+sz*3/4, 0.0);
	auto f3 = async(accum, v0+sz*3/4, v0+sz, 0.0);

	return f0.get() + f1.get() + f2.get() + f3.get();
}

int main()
{
	vector<double> v;
	for (int i = 0; i < 100000; ++i) {
		v.push_back(i);
	}

	double sum = comp4(v);
	cout << "comp4(v) returns " << sum << '\n';
}


