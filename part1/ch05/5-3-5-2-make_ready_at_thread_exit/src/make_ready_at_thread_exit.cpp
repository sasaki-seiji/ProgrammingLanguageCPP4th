/*
 * make_ready_at_thread_exit.cpp
 *
 *  Created on: 2017/02/08
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

void calc(packaged_task<double(double*,double*,double)>& task, double* beg, double* end, double init)
{
	task.make_ready_at_thread_exit(beg, end, init);
}

double comp2(vector<double>& v)
{
	using Task_type = double(double*, double*, double);

	packaged_task<Task_type> pt0 {accum};
	packaged_task<Task_type> pt1 {accum};

	future<double> f0 {pt0.get_future()};
	future<double> f1 {pt1.get_future()};

	double* first = &v[0];
	thread t1 {calc, ref(pt0), first, first + v.size()/2, 0};
	thread t2 {calc, ref(pt1), first + v.size()/2, first + v.size(), 0};

	t1.detach();
	t2.detach();

	return f0.get() + f1.get();
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


