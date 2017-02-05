/*
 * pass_argument.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <vector>
#include <thread>
#include <iostream>
using namespace std;

void f(vector<double>& v);

struct F {
	vector<double>& v;
	F(vector<double>& vv) :v{vv} { }
	void operator()();
};

// 2016.04.03 add body of function f and F::operator()
// 2017.02.05 change function body
void f(vector<double>& v)
{
	for (double& x : v)
		x += 1.5;
}

// 2017.02.05 change function body
void F::operator()()
{
	for (double& x : v)
		x *= 1.5;
}

int main()
{
	vector<double> some_vec {1,2,3,4,5,6,7,8,9};
	vector<double> vec2 {10,11,12,13,14};

	thread t1 {f, ref(some_vec)};
	thread t2 {F{vec2}};

	t1.join();
	t2.join();

	cout << "some_vec: ";
	for (auto x : some_vec)
		cout << x << ' ';
	cout << endl;

	cout << "vec2: ";
	for (auto x : vec2)
		cout << x << ' ';
	cout << endl;
}

