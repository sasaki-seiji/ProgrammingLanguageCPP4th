/*
 * return_result.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <vector>
#include <thread>
#include <iostream>
using namespace std;

void f(const vector<double>& v, double* res);

class F {
public:
	F(const vector<double>& vv, double* p) :v{vv}, res{p} { }
	void operator()();
private:
	const vector<double>& v;
	double*	res;
};

// 2016.04.03 add body of function f and F::operator()
void f(const vector<double>& v, double* res)
{
	double sum = 0;
	for (double x : v)
		sum += x;
	*res = sum;
}

void F::operator()()
{
	double sum = 0;
	for (double x : v)
		sum += x;
	*res = sum;
}

int main()
{
	vector<double> some_vec {1,2,3,4,5,6,7,8,9};
	vector<double> vec2 {10,11,12,13,14};

	double res1;
	double res2;

//	thread t1 {f, ctrf(some_vec), &res1};
	thread t1 {f, cref(some_vec), &res1};
	thread t2 {F{vec2, &res2}};

	t1.join();
	t2.join();

	cout << res1 << ' ' << res2 << '\n';
}




