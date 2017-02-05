/*
 * packaged_task.cpp
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

double comp2(vector<double>& v)
{
	using Task_type = double(double*, double*, double);

	packaged_task<Task_type> pt0 {accum};
	packaged_task<Task_type> pt1 {accum};

	future<double> f0 {pt0.get_future()};
	future<double> f1 {pt1.get_future()};

	double* first = &v[0];
	thread t1 {move(pt0), first, first + v.size()/2, 0};
	thread t2 {move(pt1), first + v.size()/2, first + v.size(), 0};

	// 2016.04.05 add
	//t1.join(); t2.join();

	double res = f0.get() + f1.get();
	t1.join(); t2.join();
	return res;
}

int main()
{
	vector<double> v;
	for (int i = 0; i < 10000; ++i) {
		v.push_back(i);
	}

	double sum = comp2(v);
	cout << "comp2(v) returns " << sum << '\n';
}
